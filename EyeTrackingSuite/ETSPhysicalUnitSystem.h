#pragma once
#include <QObject>

class ETSPhysicalUnitSystem : public QObject
{
	
public:

	static const double EYE_MICRONS_PER_DEGREE;

private:

	int viewDistIn;
	double dpi;

	class EyeTrackingSuite * updateETS;

public:

	ETSPhysicalUnitSystem(int viewDistInches, QObject *parent = Q_NULLPTR);
	~ETSPhysicalUnitSystem();

	void setViewDist(int viewDistInches);
	int getViewDist();

	void setDPIFromSystem();
	void setDPI(double dpi);
	double getDPI();

	void registerForUpdates(class EyeTrackingSuite * ets);

	/**
	 * Given degrees of vision, return inches across the screen plane.
	 */
	double calcDegreesToScreenInches(double degrees);

	/**
	 * Given degrees of vision, return number of screen pixels.
	 */
	double calcDegreesToPixels(double degrees);

	/**
	 * Calculate how many screen pixels (possibly fractional) represent
	 * the given distance (in microns) on the retina.
	 */
	double calcEyeMicronsToPixels(double microns);

private:

	void notifyUpdate();

};