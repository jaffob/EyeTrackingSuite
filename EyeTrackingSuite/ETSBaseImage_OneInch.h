#pragma once
#include "ETSBaseImage.h"
#include <QImage>

class ETSBaseImage_OneInch : public ETSBaseImage
{

private:

	QImage img;
	class ETSPhysicalUnitSystem * phys;

public:

	ETSBaseImage_OneInch(class ETSPhysicalUnitSystem * physUnits);
	~ETSBaseImage_OneInch();

	virtual bool regenerateForSize(QSize drawAreaSize) override;
	virtual QImage getImage() const override;
	virtual bool isValid() const override;

};