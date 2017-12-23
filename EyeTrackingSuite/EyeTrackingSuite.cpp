#include "EyeTrackingSuite.h"
#include "ETSDrawArea.h"

EyeTrackingSuite::EyeTrackingSuite(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	drawArea = (ETSDrawArea *)ui.mainDrawArea;

	tobii = new ETSTobii();
	tobii->init();
	tobii->connectDevice();
}