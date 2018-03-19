#pragma once
#include "ETSBaseImage.h"

class ETSBaseImage_VisionChart : public ETSBaseImage
{

public:

	static const double degrees2020;	// Degrees of visual height occupied by text at 20/20.

private:

	QImage img;				// Chart generated for the right size
	QSize drawAreaSize;
	class ETSPhysicalUnitSystem * phys;

	// List of acuities to display. These are 20/x numbers.
	unsigned int acuities[32];
	unsigned int nAcuities;

public:

	ETSBaseImage_VisionChart(class ETSPhysicalUnitSystem * physUnits);
	~ETSBaseImage_VisionChart();

	virtual bool regenerateForSize(QSize drawAreaSize) override;
	virtual QImage getImage() const override;
	virtual bool isValid() const override;

	virtual void setAcuities(unsigned int * acuities, unsigned int count);
	virtual unsigned int * getAcuities() const;
	virtual unsigned int getAcuitiesCount() const;

protected:

	/**
	 * Using the given font, make a sample text string that fits in width.
	 */
	virtual QString makeTruncatedSampleString(QFont& font, int width) const;
};