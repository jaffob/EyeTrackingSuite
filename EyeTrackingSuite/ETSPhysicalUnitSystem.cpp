#include "ETSPhysicalUnitSystem.h"
#include "EyeTrackingSuite.h"
#include <QScreen>
#include <QApplication>

const double ETSPhysicalUnitSystem::EYE_MICRONS_PER_DEGREE = 300.;

ETSPhysicalUnitSystem::ETSPhysicalUnitSystem(int physViewDist, QObject * parent)
	: QObject(parent)
	, viewDistIn(physViewDist)
	, updateETS(nullptr)
{
	setDPIFromSystem();
}

ETSPhysicalUnitSystem::~ETSPhysicalUnitSystem()
{
}

void ETSPhysicalUnitSystem::setViewDist(int viewDistInches)
{
	viewDistIn = viewDistInches;
	notifyUpdate();
}

int ETSPhysicalUnitSystem::getViewDist()
{
	return viewDistIn;
}

void ETSPhysicalUnitSystem::setDPIFromSystem()
{
	QScreen * screen = QGuiApplication::primaryScreen();
	dpi = screen->logicalDotsPerInch();
	notifyUpdate();
}

void ETSPhysicalUnitSystem::setDPI(double dpi)
{
	this->dpi = dpi;
	notifyUpdate();
}

double ETSPhysicalUnitSystem::getDPI()
{
	return dpi;
}

void ETSPhysicalUnitSystem::calibrateDPI(int calibMillimeters)
{
	QScreen * screen = QGuiApplication::primaryScreen();
	dpi = screen->logicalDotsPerInch();
	dpi = dpi * (25.4 / calibMillimeters);
	notifyUpdate();
}

void ETSPhysicalUnitSystem::registerForUpdates(EyeTrackingSuite * ets)
{
	updateETS = ets;
}

double ETSPhysicalUnitSystem::calcDegreesToScreenInches(double degrees)
{
	return tan((degrees / 2.) * (3.141592 / 180.)) * viewDistIn * 2.;
}

double ETSPhysicalUnitSystem::calcDegreesToPixels(double degrees)
{
	return calcDegreesToScreenInches(degrees) * dpi;
}

double ETSPhysicalUnitSystem::calcEyeMicronsToPixels(double microns)
{
	return calcDegreesToPixels(microns / EYE_MICRONS_PER_DEGREE);
}

void ETSPhysicalUnitSystem::notifyUpdate()
{
	if (updateETS)
		updateETS->onPhysicalUnitSystemUpdate();
}
