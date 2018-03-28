#include "ETSBaseImage_OneInch.h"
#include "ETSPhysicalUnitSystem.h"
#include <QPainter>

ETSBaseImage_OneInch::ETSBaseImage_OneInch(ETSPhysicalUnitSystem * physUnits)
	: phys(physUnits)
{
}

ETSBaseImage_OneInch::~ETSBaseImage_OneInch()
{
}

bool ETSBaseImage_OneInch::regenerateForSize(QSize drawAreaSize)
{
	if (!phys) return false;

	// Make an image that's one square inch.
	img = QImage(qMin((int)phys->getDPI(), drawAreaSize.width()), qMin((int)phys->getDPI(), drawAreaSize.height()), QImage::Format::Format_RGB32);
	QPainter painter(&img);
	painter.setBrush(Qt::lightGray);
	painter.drawRect(0, 0, phys->getDPI() - 1, phys->getDPI() - 1);
	painter.end();

	return true;
}

QImage ETSBaseImage_OneInch::getImage() const
{
	return QImage(img);
}

bool ETSBaseImage_OneInch::isValid() const
{
	return phys && !img.isNull();
}
