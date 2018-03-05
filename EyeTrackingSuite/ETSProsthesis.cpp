#include "ETSProsthesis.h"
#include <QPainter>

ETSProsthesis::ETSProsthesis(QObject * parent)
	: QObject(parent)
	, img()
	, options(nullptr)
{
}

ETSProsthesis::~ETSProsthesis()
{
}

void ETSProsthesis::makeProsthesis(QImage& source)
{
	// If no draw options have been attached, essentially do nothing.
	if (!options)
	{
		img = QImage(source);
		return;
	}

	// Reduce image resolution by downscaling then upscaling the image.
	img = source.scaled(source.size() / options->pixelSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	img = img.scaled(source.size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);

	// Iterate over pixels in the prosthesis area.
	for (int i = 0; i < img.width(); i++)
	{
		for (int j = 0; j < img.height(); j++)
		{
			QPoint pixpoint = QPoint(i, j);

			// Total lightness of this prosthesis pixel is the average of all the screen pixels.
			int pixelLightness = img.pixelColor(pixpoint).lightness();

			// Force this value to one of the gray levels.
			int grayLevel = pixelLightness / (256 / options->grayLevels);

			// Interpolate the gray level between the full black and full white value.
			pixelLightness = options->fullBlack + (int)((options->fullWhite - options->fullBlack) * (1. * grayLevel / (options->grayLevels - 1.)));
			pixelLightness = qMax(qMin(pixelLightness, 255), 0);

			img.setPixelColor(pixpoint, QColor(pixelLightness, pixelLightness, pixelLightness));
		}
	}
}

QImage & ETSProsthesis::getImage()
{
	return img;
}

void ETSProsthesis::attachDrawOptions(ETSProsthesisDrawOptions * options)
{
	this->options = options;
}

bool ETSProsthesis::areDrawOptionsAttached() const
{
	return options != nullptr;
}
