#include "EyeTrackingSuite.h"
#include "ETSDrawArea.h"
#include <QtDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QPoint>
#include <QScreen>
#include <QMessageBox>
#include "ETSBaseImage_File.h"
#include "ETSBaseImage_OneInch.h"
#include <cstdio>
#include <QCloseEvent>
#include <QDirIterator>

const unsigned int EyeTrackingSuite::optionsFileVersion = 6;

EyeTrackingSuite::EyeTrackingSuite(QWidget *parent)
	: QMainWindow(parent)
	, optCalibrationHoriz(0)
	, optCalibrationVert(0)
	, optScotomaEnabled(false)
	, optScotomaUseDegrees(true)
	, optHalfField(0)
	, optPhysDPICalib(0)
	, baseImage(nullptr)
	, visTexts("Vision Chart Text.txt")
	, visChartShowing(false)
{
	ui.setupUi(this);
	ui.spaceAtBottom->setHidden(true);
	drawArea = (ETSDrawArea *)ui.mainDrawArea;
	drawArea->attachETS(this);

	// Initialize the Tobii bridge.
	tobii = new ETSTobii();
	tobii->init();
	reconnectToTobii();

	// Initialize the physical unit system.
	physUnits = new ETSPhysicalUnitSystem(24);

	// Initialize the scotoma draw options.
	optScotoma.radius = 50;
	optScotoma.sizeDegrees = 10;
	optScotoma.changed = true;
	optScotoma.prosthesisEnabled = false;
	optScotoma.prosthesisSizePercent = 50;
	optScotoma.gradientEnabled = false;
	optScotoma.gradientSquaredFalloff = true;
	optScotoma.gradientInside = 40;
	optScotoma.gradientOutside = 60;

	// Initialize prosthesis options.
	optProsthesis.changed = true;
	optProsthesis.pixelSize = 30;
	optProsthesis.pixelSizeMicrons = 30;
	optProsthesis.grayLevels = 8;
	optProsthesis.fullBlack = 0;
	optProsthesis.fullWhite = 255;

	// Initialize vision chart options.
	optVisionChart.fontNumber = 0;
	optVisionChart.fontBold = false;
	optVisionChart.textNumber = 1;
	optVisionChart.textDifferent = false;
	optVisionChart.textCapital = true;
	ui.visTextNumber->setMaximum(visTexts.getTextCount());

	// Load options from file.
	readOptionsFile();

	// If DPI has been calibrated, do the calibration.
	if (optPhysDPICalib > 0)
	{
		physUnits->calibrateDPI(optPhysDPICalib);
	}

	// If not, warn the user.
	else
	{
		QMessageBox::warning(this, "DPI Calibration", "The dots-per-inch (DPI) metric of this screen has not yet \
been calibrated. To do this, press the [?] button under \"Physical Setup\" and follow the instructions. Measurements \
may not be accurate until this is done.", "OK");
	}

	physUnits->registerForUpdates(this);

	// Load names of image files from the images directory.
	populateImageDropdown();

	// Set proper scotoma and prosthesis sizes.
	autoResizeScotoma();
	autoResizeProsthesisPixels();

	// Load the base image for the draw area.
	loadNewBaseImage();
	drawArea->repaintDrawArea();

	// Start the main loop.
	timerId = startTimer(12);
}

EyeTrackingSuite::~EyeTrackingSuite()
{
	tobii->disconnectDevice();
	tobii->shutdown();
	delete tobii;

	killTimer(timerId);
}

void EyeTrackingSuite::onPhysicalUnitSystemUpdate()
{
	// Regenerate the base image in case it depends on physical units.
	baseImage->regenerateForSize(drawArea->size());

	// If the scotoma is set to size in degrees, update it.
	if (optScotomaUseDegrees)
	{
		autoResizeScotoma();
	}

	autoResizeProsthesisPixels();
}

void EyeTrackingSuite::populateImageDropdown()
{
	QDirIterator dir ("Images", QStringList("*.jpg"));

	while (dir.hasNext())
	{
		QFileInfo info (dir.next());
		ui.imageComboBox->addItem(info.baseName());
	}
}

void EyeTrackingSuite::loadNewBaseImage()
{
	// Kill the old base image.
	if (baseImage)
		delete baseImage;
	visChartShowing = false;

	// Load the dynamic vision chart.
	if (ui.imageComboBox->currentIndex() == 0)
	{
		ETSBaseImage_VisionChart * bi = new ETSBaseImage_VisionChart(this, physUnits);
		unsigned int acs[9] = { 20, 30, 40, 60, 80, 100, 200, 400, 800 };
		bi->setAcuities(acs, 9);
		baseImage = bi;
		visChartShowing = true;
	}

	// Load the square inch.
	else if (ui.imageComboBox->currentIndex() == 1)
	{
		baseImage = new ETSBaseImage_OneInch(physUnits);
	}

	// Load a file.
	else
	{
		ETSBaseImage_File * bi = new ETSBaseImage_File();
		bi->loadFromFile(QString("Images/") + ui.imageComboBox->currentText() + QString(".jpg"));
		baseImage = bi;
	}

	baseImage->regenerateForSize(drawArea->size());

	// Changing the base image invalidates the old prosthesis render.
	optProsthesis.changed = true;
}

void EyeTrackingSuite::timerEvent(QTimerEvent * event)
{
	// Process eye data (thereby calling our callback).
	if (tobii->isConnected())
	{
		if (!tobii->processEyeData(false))
		{
			if (tobii->mError == TOBII_ERROR_CONNECTION_FAILED)
			{
				tobii->disconnectDevice();
				ui.tobiiLabel->setText(QString("<font color='red'>Disconnected</font>"));
			}
		}
	}

	// If no Tobii is connected, call repaint here.
	else
	{
		drawArea->repaintDrawArea();
	}
}

void EyeTrackingSuite::onGazePointReceived(float alpha, float beta, void * context)
{
	EyeTrackingSuite * ets = (EyeTrackingSuite *)context;

	// Tobii gives us barycentric (0-1) coords, so we need to convert to screen coords.
	QRect screenRect = QApplication::desktop()->screenGeometry();
	QPoint screenPoint(screenRect.width() * alpha, screenRect.height() * beta);

	// Send that on to the draw area, and tell it to redraw.
	ets->drawArea->setGazeScreenPosition(screenPoint);
	ets->drawArea->repaintDrawArea();
}

void EyeTrackingSuite::reconnectToTobii()
{
	tobii->disconnectDevice();

	// Connect to a device and setup a callback.
	if (tobii->connectDevice())
	{
		tobii->registerGazePointCallback(onGazePointReceived, this);
		ui.tobiiLabel->setText(QString("<font color='green'>Connected</font>"));
	}
	else
	{
		ui.tobiiLabel->setText(QString("<font color='red'>Disconnected</font>"));
	}
}

void EyeTrackingSuite::autoResizeScotoma()
{
	optScotoma.radius = physUnits->calcDegreesToPixels(ui.scotomaSizeDegrees->value()) / 2;
	optScotoma.changed = true;
}

void EyeTrackingSuite::autoResizeProsthesisPixels()
{
	optProsthesis.pixelSize = physUnits->calcEyeMicronsToPixels(ui.prosthesisPixelSize->value());
	optProsthesis.changed = true;
}

void EyeTrackingSuite::readOptionsFile()
{
	// Open options file.
	FILE * fp = fopen("options.dat", "r");
	if (!fp) return;

	bool fullscreen = false;
	bool hidecontrols = false;
	bool spacebottom = false;
	int viewdist = 0;

	// Abort if options file version is different.
	unsigned int ver;
	fread(&ver, sizeof(unsigned int), 1, fp);
	if (ver != optionsFileVersion)
	{
		fclose(fp);
		return;
	}

	// Read options.
	fread(&optScotomaEnabled, sizeof(bool), 1, fp);
	fread(&optScotoma, sizeof(ETSScotomaDrawOptions), 1, fp);
	fread(&optProsthesis, sizeof(ETSProsthesisDrawOptions), 1, fp);
	fread(&optVisionChart, sizeof(ETSVisionChartOptions), 1, fp);
	fread(&fullscreen, sizeof(bool), 1, fp);
	fread(&hidecontrols, sizeof(bool), 1, fp);
	fread(&spacebottom, sizeof(bool), 1, fp);
	fread(&viewdist, sizeof(int), 1, fp);
	fread(&optPhysDPICalib, sizeof(int), 1, fp);

	if (optVisionChart.textNumber > visTexts.getTextCount())
	{
		optVisionChart.textNumber = 1;
	}

	// Update UI.

	ui.scotomaEnabled->setChecked(optScotomaEnabled);
	ui.scotomaSizeDegrees->setValue(optScotoma.sizeDegrees);

	ui.prosthesisEnabled->setChecked(optScotoma.prosthesisEnabled);
	ui.prosthesisSize->setValue(optScotoma.prosthesisSizePercent);
	ui.gradientEnabled->setChecked(optScotoma.gradientEnabled);
	ui.gradientOutside->setValue(optScotoma.gradientOutside);
	
	ui.prosthesisGrayLevel->setValue(optProsthesis.grayLevels);
	ui.prosthesisPixelSize->setValue(optProsthesis.pixelSizeMicrons);
	ui.prosthesisFullBlack->setValue(optProsthesis.fullBlack);
	ui.prosthesisFullWhite->setValue(optProsthesis.fullWhite);
	
	ui.visFont->setCurrentIndex(optVisionChart.fontNumber);
	ui.visFontBold->setChecked(optVisionChart.fontBold);
	ui.visTextNumber->setEnabled(!optVisionChart.textDifferent);
	ui.visTextNumber->setValue(optVisionChart.textNumber);
	ui.visTextDifferent->setChecked(optVisionChart.textDifferent);
	ui.visTextCapital->setChecked(optVisionChart.textCapital);

	if (fullscreen) showFullScreen();
	ui.actionFull_Screen->setChecked(fullscreen);
	ui.tabWidget->setHidden(hidecontrols);
	ui.actionShow_Controls->setChecked(!hidecontrols);
	ui.spaceAtBottom->setHidden(!spacebottom);
	ui.actionAdd_Space_At_Bottom->setChecked(spacebottom);

	physUnits->setViewDist(viewdist);
	ui.physViewDist->setValue(viewdist);
	ui.physDPICalib->setValue(optPhysDPICalib);

	fclose(fp);
}

void EyeTrackingSuite::writeOptionsFile()
{
	// Open options file.
	FILE * fp = fopen("options.dat", "w");
	if (!fp) return;

	bool fullscreen = isFullScreen();
	bool hidecontrols = ui.tabWidget->isHidden();
	bool spacebottom = !ui.spaceAtBottom->isHidden();
	int viewdist = physUnits->getViewDist();

	// Write file version.
	fwrite(&optionsFileVersion, sizeof(unsigned int), 1, fp);

	// Write options.
	fwrite(&optScotomaEnabled, sizeof(bool), 1, fp);
	fwrite(&optScotoma, sizeof(ETSScotomaDrawOptions), 1, fp);
	fwrite(&optProsthesis, sizeof(ETSProsthesisDrawOptions), 1, fp);
	fwrite(&optVisionChart, sizeof(ETSVisionChartOptions), 1, fp);
	fwrite(&fullscreen, sizeof(bool), 1, fp);
	fwrite(&hidecontrols, sizeof(bool), 1, fp);
	fwrite(&spacebottom, sizeof(bool), 1, fp);
	fwrite(&viewdist, sizeof(int), 1, fp);
	fwrite(&optPhysDPICalib, sizeof(int), 1, fp);

	fclose(fp);
}

void EyeTrackingSuite::closeEvent(QCloseEvent * event)
{
	writeOptionsFile();
	event->accept();
}

void EyeTrackingSuite::setCalibration(int h, int v)
{
	optCalibrationHoriz = h;
	optCalibrationVert = v;
	ui.calibrationHoriz->setValue(h);
	ui.calibrationVert->setValue(v);
}

bool EyeTrackingSuite::isTobiiConnected() const
{
	return tobii->isConnected();
}

QString EyeTrackingSuite::getCurrentVisionChartFont() const
{
	return ui.visFont->currentText();
}

void EyeTrackingSuite::onTobiiReconnectClicked()
{
	reconnectToTobii();
}

void EyeTrackingSuite::onCalibrationHorizChanged(int newValue)
{
	optCalibrationHoriz = newValue;
}

void EyeTrackingSuite::onCalibrationVertChanged(int newValue)
{
	optCalibrationVert = newValue;
}

void EyeTrackingSuite::onPhysViewDistChanged(int newValue)
{
	physUnits->setViewDist(newValue);
}

void EyeTrackingSuite::onPhysDPICalibChanged(int newValue)
{
	optPhysDPICalib = newValue;
	physUnits->calibrateDPI(optPhysDPICalib);
}

void EyeTrackingSuite::onPhysDPICalibHelp()
{
	QString text = QString("To calibrate screen DPI:\n\n");
	text += "1. Select the \"One Square Inch\" image from the image selector.\n";
	text += "2. Using a ruler, measure the width of the square in millimeters.\n";
	text += "3. Enter the measurement (in mm) into the \"DPI Calibration\" field.\n\n";
	text += "If the DPI was already calibrated when you opened the application, another option ";
	text += "is to simply perturb the calibration value until the square measures one inch.";
	QMessageBox::information(this, "DPI Calibration", text, QMessageBox::Ok);
}

void EyeTrackingSuite::onImageComboBoxChanged(QString newText)
{
	loadNewBaseImage();
}

void EyeTrackingSuite::onVisFontChanged(int newIndex)
{
	optVisionChart.fontNumber = newIndex;

	if (visChartShowing)
	{
		baseImage->regenerateForSize(drawArea->size());
		optProsthesis.changed = true;
	}
}

void EyeTrackingSuite::onVisFontBoldChanged(bool enabled)
{
	optVisionChart.fontBold = enabled;

	if (visChartShowing)
	{
		baseImage->regenerateForSize(drawArea->size());
		optProsthesis.changed = true;
	}
}

void EyeTrackingSuite::onVisTextNumberChanged(int newValue)
{
	optVisionChart.textNumber = newValue;

	if (visChartShowing)
	{
		baseImage->regenerateForSize(drawArea->size());
		optProsthesis.changed = true;
	}
}

void EyeTrackingSuite::onVisTextDifferentChanged(bool enabled)
{
	optVisionChart.textDifferent = enabled;
	ui.visTextNumber->setEnabled(!enabled);

	if (visChartShowing)
	{
		baseImage->regenerateForSize(drawArea->size());
		optProsthesis.changed = true;
	}
}

void EyeTrackingSuite::onVisTextCapitalChanged(bool enabled)
{
	optVisionChart.textCapital = enabled;

	if (visChartShowing)
	{
		baseImage->regenerateForSize(drawArea->size());
		optProsthesis.changed = true;
	}
}

void EyeTrackingSuite::onScotomaEnabled(bool enabled)
{
	optScotomaEnabled = enabled;
}

void EyeTrackingSuite::onScotomaUseDegrees(bool enabled)
{
	optScotomaUseDegrees = enabled;

	// Enable/disable the different size controls.
	//ui.scotomaRadius->setEnabled(!optScotomaUseDegrees);
	//ui.scotomaSizeDegrees->setEnabled(optScotomaUseDegrees);

	// If starting to use degrees, resize to the set value.
	if (optScotomaUseDegrees)
	{
		autoResizeScotoma();
	}
}

void EyeTrackingSuite::onScotomaRadiusChanged(int newValue)
{
	if (!optScotomaUseDegrees)
	{
		optScotoma.radius = newValue;
		optScotoma.changed = true;
	}
}

void EyeTrackingSuite::onScotomaSizeDegreesChanged(int newValue)
{
	optScotoma.sizeDegrees = newValue;

	if (optScotomaUseDegrees)
	{
		autoResizeScotoma();
	}
}

void EyeTrackingSuite::onProsthesisEnabled(bool enabled)
{
	optScotoma.prosthesisEnabled = enabled;
	optScotoma.changed = true;
}

void EyeTrackingSuite::onProsthesisSizeChanged(int newValue)
{
	optScotoma.prosthesisSizePercent = newValue;
	optScotoma.changed = true;
}

void EyeTrackingSuite::onProsthesisGrayLevelChanged(int newValue)
{
	optProsthesis.grayLevels = newValue;
	optProsthesis.changed = true;
}

void EyeTrackingSuite::onProsthesisPixelSizeChanged(int newValue)
{
	optProsthesis.pixelSizeMicrons = newValue;
	autoResizeProsthesisPixels();
}

void EyeTrackingSuite::onProsthesisFullBlackChanged()
{
	optProsthesis.fullBlack = ui.prosthesisFullBlack->value();
	optProsthesis.changed = true;
}

void EyeTrackingSuite::onProsthesisFullWhiteChanged()
{
	optProsthesis.fullWhite = ui.prosthesisFullWhite->value();
	optProsthesis.changed = true;
}

void EyeTrackingSuite::onGradientEnabled(bool enabled)
{
	optScotoma.gradientEnabled = enabled;
	optScotoma.changed = true;
}

void EyeTrackingSuite::onGradientInsideChanged(int newValue)
{
	optScotoma.gradientInside = newValue;
	optScotoma.changed = true;
}

void EyeTrackingSuite::onGradientOutsideChanged(int newValue)
{
	optScotoma.gradientOutside = newValue;
	optScotoma.changed = true;
}

void EyeTrackingSuite::onHalfFieldBlockNone(bool enabled)
{
	if (enabled) optHalfField = 0;
}

void EyeTrackingSuite::onHalfFieldBlockLeft(bool enabled)
{
	if (enabled) optHalfField = 1;
}

void EyeTrackingSuite::onHalfFieldBlockRight(bool enabled)
{
	if (enabled) optHalfField = 2;
}

void EyeTrackingSuite::onActionFullscreen(bool newValue)
{
	if (newValue)
		showFullScreen();
	else
		showNormal();
}

void EyeTrackingSuite::onActionShowControls(bool newValue)
{
	ui.tabWidget->setHidden(!newValue);
}

void EyeTrackingSuite::onActionSpaceBottom(bool newValue)
{
	ui.spaceAtBottom->setHidden(!newValue);
}


void EyeTrackingSuite::onActionAbout()
{
	QMessageBox::about(this, "About", "Created by Jack Boffa.");
}
