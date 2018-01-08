#include "EyeTrackingSuite.h"
#include "ETSDrawArea.h"
#include <QtDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QPoint>

EyeTrackingSuite::EyeTrackingSuite(QWidget *parent)
	: QMainWindow(parent)
	, optCalibrationHoriz(0)
	, optCalibrationVert(0)
	, optScotomaEnabled(true)
	, optScotomaRadius(50)
	, optProsthesisEnabled(false)
	, optProsthesisSizePercent(25)
	, optProsthesisGrayLevel(0)
{
	ui.setupUi(this);
	drawArea = (ETSDrawArea *)ui.mainDrawArea;

	// Initialize the Tobii bridge.
	tobii = new ETSTobii();
	tobii->init();
	reconnectToTobii();

	// Load the base image for the draw area.
	drawArea->loadBaseImage(QString("input.jpg"));
	drawArea->repaintDrawArea(this);

	// Start the main loop.
	timerId = startTimer(1000/60);
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
		drawArea->setGazeLocalPosition(QPoint(drawArea->width() / 2, drawArea->height() / 2));
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

void EyeTrackingSuite::onScotomaEnabled(int enabled)
{
	optScotomaEnabled = enabled;
}

void EyeTrackingSuite::onScotomaRadiusChanged(int newValue)
{
	optScotomaRadius = newValue;
}

void EyeTrackingSuite::onProsthesisEnabled(int enabled)
{
	optProsthesisEnabled = enabled;
}

void EyeTrackingSuite::onProsthesisSizeChanged(int newValue)
{
	optProsthesisSizePercent = newValue;
}

void EyeTrackingSuite::onProsthesisGrayLevelChanged(int newValue)
{
	optProsthesisGrayLevel = newValue;
}