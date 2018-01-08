#include "ETSScotoma.h"

ETSScotoma::ETSScotoma(QObject * parent)
	: QObject(parent)
	, img()
{
}

ETSScotoma::~ETSScotoma()
{
}

void ETSScotoma::makeScotoma(ETSScotomaDrawOptions * options)
{
	if (!options)
		return;

	// Create an alpha-only image that's big enough to hold the whole scotoma.
	img = QImage(options->radius * 2, options->radius * 2, QImage::Format::Format_Alpha8);
	
	// Iterate over all pixels.
	for (int i = 0; i < img.width(); i++)
	{
		for (int j = 0; j < img.height(); j++)
		{
			img.setPixelColor(i, j, QColor(0, 0, 0, 100));
		}
	}
}

QImage & ETSScotoma::getImage()
{
	return img;
}
