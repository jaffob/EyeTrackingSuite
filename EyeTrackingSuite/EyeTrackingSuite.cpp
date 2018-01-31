#include "EyeTrackingSuite.h"
#include "ETSDrawArea.h"
#include <QtDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QPoint>
#include <QScreen>

EyeTrackingSuite::EyeTrackingSuite(QWidget *parent)
	: QMainWindow(parent)
	, optCalibrationHoriz(0)
	, optCalibrationVert(0)
	, optScotomaEnabled(false)
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
	optScotoma.prosthesisSizePercent = 25;
	optScotoma.gradientEnabled = false;
	optScotoma.gradientSquaredFalloff = true;
	optScotoma.gradientInside = 40;
	optScotoma.gradientOutside = 60;

	// Initialize prosthesis options.
	optProsthesis.changed = true;
	optProsthesis.grayLevels = 8;
	optProsthesis.pixelSize = 5;

	// Load the base image for the draw area.
	drawArea->loadBaseImage(ui.imageComboBox->currentText() + QString(".jpg"));
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

void EyeTrackingSuite::onImageComboBoxChanged(QString newText)
{
	drawArea->loadBaseImage(newText + QString(".jpg"));
	optProsthesis.changed = true;	// A new base image means we have to re-blur.
}

void EyeTrackingSuite::onScotomaEnabled(bool enabled)
{
	optScotomaEnabled = enabled;
}

void EyeTrackingSuite::onScotomaRadiusChanged(int newValue)
{
	optScotoma.radius = newValue;
	optScotoma.changed = true;
}

void EyeTrackingSuite::onScotomaAutoSize()
{
	// Figure out desired scotoma size.
	QScreen * screen = QGuiApplication::primaryScreen();
	double scotomaRadiusInches = tan((ui.scotomaAutoSizeDegrees->value() / 2.) * (3.141592 / 180.)) * ui.scotomaAutoViewDist->value();
	int scotomaRadiusPixels = (int)(scotomaRadiusInches * screen->logicalDotsPerInch());
	
	// Set the new radius.
	ui.scotomaRadius->setValue(scotomaRadiusPixels);
	optScotoma.radius = scotomaRadiusPixels;
	optScotoma.changed = true;
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
	optProsthesis.pixelSize = newValue;
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
