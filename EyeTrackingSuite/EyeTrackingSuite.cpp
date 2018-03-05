#include "EyeTrackingSuite.h"
#include "ETSDrawArea.h"
#include <QtDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QPoint>
#include <QScreen>
#include <QMessageBox>

EyeTrackingSuite::EyeTrackingSuite(QWidget *parent)
	: QMainWindow(parent)
	, optCalibrationHoriz(0)
	, optCalibrationVert(0)
	, optPhysViewDistFt(2)
	, optScotomaEnabled(false)
	, optScotomaUseDegrees(true)
	, optHalfField(0)
{
	ui.setupUi(this);
	drawArea = (ETSDrawArea *)ui.mainDrawArea;

	// Initialize the Tobii bridge.
	tobii = new ETSTobii();
	tobii->init();
	reconnectToTobii();

	// Initialize the scotoma draw options.
	optScotoma.radius = 50;
	optScotoma.changed = true;
	optScotoma.prosthesisEnabled = false;
	optScotoma.prosthesisSizePercent = 50;
	optScotoma.gradientEnabled = false;
	optScotoma.gradientSquaredFalloff = true;
	optScotoma.gradientInside = 40;
	optScotoma.gradientOutside = 60;

	autoResizeScotoma();

	// Initialize prosthesis options.
	optProsthesis.changed = true;
	optProsthesis.grayLevels = 8;
	autoResizeProsthesisPixels();
	optProsthesis.fullBlack = 0;
	optProsthesis.fullWhite = 255;

	// Load the base image for the draw area.
	drawArea->setBaseImage(ui.imageComboBox->currentText() + QString(".jpg"));
	drawArea->repaintDrawArea(this);

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

	// If no Tobii is connected, draw the scotoma in the center.
	else
	{
		drawArea->setGazeLocalPosition(QPoint(drawArea->img.width() / 2, drawArea->img.height() / 2));
		drawArea->repaintDrawArea(this);
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
	ets->drawArea->repaintDrawArea(ets);
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
	// Figure out desired scotoma size.
	QScreen * screen = QGuiApplication::primaryScreen();
	double scotomaRadiusInches = tan((ui.scotomaSizeDegrees->value() / 2.) * (3.141592 / 180.)) * (optPhysViewDistFt * 12.);
	int scotomaRadiusPixels = (int)(scotomaRadiusInches * screen->logicalDotsPerInch());

	// Set the new radius.
	//ui.scotomaRadius->setValue(scotomaRadiusPixels);
	optScotoma.radius = scotomaRadiusPixels;
	optScotoma.changed = true;
}

void EyeTrackingSuite::autoResizeProsthesisPixels()
{
	// Figure out pixel size. 300 microns is one degree of vision.
	QScreen * screen = QGuiApplication::primaryScreen();
	double prosPixSizeDegrees = ui.prosthesisPixelSize->value() / 300.;
	double prosPixSizeInches = tan((prosPixSizeDegrees / 2.) * (3.141592 / 180.)) * (optPhysViewDistFt * 12.) * 2.;
	double prosPixSizePixels = prosPixSizeInches * screen->logicalDotsPerInch();

	optProsthesis.pixelSize = prosPixSizePixels;
	optProsthesis.changed = true;
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
	optPhysViewDistFt = qMax(newValue, 1);

	// If the scotoma is set to size in degrees, update it.
	if (optScotomaUseDegrees)
	{
		autoResizeScotoma();
	}

	autoResizeProsthesisPixels();
}

void EyeTrackingSuite::onImageComboBoxChanged(QString newText)
{
	drawArea->setBaseImage(newText + QString(".jpg"));
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

void EyeTrackingSuite::onActionAbout()
{
	QMessageBox::about(this, "About", "Created by Jack Boffa.");
}
