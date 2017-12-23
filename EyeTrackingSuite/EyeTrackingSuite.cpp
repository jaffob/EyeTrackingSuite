#include "EyeTrackingSuite.h"
#include "ETSDrawArea.h"
#include <QtDebug>

EyeTrackingSuite::EyeTrackingSuite(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	drawArea = (ETSDrawArea *)ui.mainDrawArea;

	// Initialize the Tobii bridge.
	tobii = new ETSTobii();
	tobii->init();

	// Connect to a device and setup a callback.
	if (tobii->connectDevice())
	{
		tobii->registerGazePointCallback(onGazePointReceived, this);
	}

	// Load the base image for the draw area.
	drawArea->loadBaseImage(QString("input.jpg"));
	drawArea->repaintDrawArea();

	// Start the main loop.
	timerId = startTimer(500);
}

EyeTrackingSuite::~EyeTrackingSuite()
{
	tobii->shutdown();
	delete tobii;

	killTimer(timerId);
}

void EyeTrackingSuite::timerEvent(QTimerEvent * event)
{
	tobii->processEyeData(false);
}

void EyeTrackingSuite::onGazePointReceived(float alpha, float beta, void * context)
{
	EyeTrackingSuite * ets = (EyeTrackingSuite *)context;
	qDebug() << "eyes: " << alpha << ", " << beta;
}
