#pragma once
#include "ETSBaseImage.h"
#include <QImage>

typedef struct
{
	int fontNumber;
	bool fontBold;
	int textNumber;
	bool textDifferent;
	bool textCapital;
} ETSVisionChartOptions;

class ETSBaseImage_VisionChart : public ETSBaseImage
{

public:

	static const int textResolvePixels;	// Minimum text height for the text to be resolvable.
	static const double degrees2020;	// Degrees of visual height occupied by text at 20/20.

private:

	class EyeTrackingSuite * ets;

	QImage img;				// Chart generated for the right size
	QSize drawAreaSize;
	class ETSPhysicalUnitSystem * phys;

	// List of acuities to display. These are 20/x numbers.
	unsigned int acuities[32];
	unsigned int nAcuities;

	int acNumberX;

public:

	ETSBaseImage_VisionChart(class EyeTrackingSuite * ets, class ETSPhysicalUnitSystem * physUnits);
	~ETSBaseImage_VisionChart();

	virtual bool regenerateForSize(QSize drawAreaSize) override;
	virtual QImage getImage() const override;
	virtual bool isValid() const override;

	virtual void prosthesisPostEdit(QImage& prosthesisImg) override;

	virtual void setAcuities(unsigned int * acuities, unsigned int count);
	virtual unsigned int * getAcuities() const;
	virtual unsigned int getAcuitiesCount() const;

protected:

	/**
	 * Using the given font, make a sample text string that fits in width.
	 */
	virtual QString makeTruncatedSampleString(QFont& font, int width) const;

	/**
	 * Use font metrics to establish a calibration factor for the font height. Using
	 * QFont::setPixelSize() gives results that are always off by a constant factor,
	 * so by measuring the resulting height of setPixelSize(), we can adjust for it.
	 */
	virtual double calcFontCalibration(QFont font) const;
};