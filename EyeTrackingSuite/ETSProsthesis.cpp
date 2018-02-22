#include "ETSProsthesis.h"
#include <QPainter>

ETSProsthesis::ETSProsthesis(QObject * parent)
	: QObject(parent)
	, img()
{
}

ETSProsthesis::~ETSProsthesis()
{
}

void ETSProsthesis::makeProsthesis(QImage& source, ETSProsthesisDrawOptions * options)
{
	img = source.scaled(source.size() / options->pixelSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);
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

void ETSProsthesis::makeProsthesis_Pixel(QPainter& painter, ETSProsthesisDrawOptions * options, int x, int y)
{
	/*int totalLightness = 0, totalN = 0;
	
	// Iterate over all the screen pixels in this prosthesis pixel.
	for (int i = x; i < qMin(x + options->pixelSize, img.width()); i++)
	{
		for (int j = y; j < qMin(y + options->pixelSize, img.height()); j++)
		{
			QColor pix = img.pixelColor(i, j);
			totalLightness += pix.lightness();
			totalN++;
		}
	}
	
	if (totalN > 0)
	{
		// Total lightness of this prosthesis pixel is the average of all the screen pixels.
		totalLightness /= totalN;

		// Force this value to one of the gray levels.
		int grayLevel = totalLightness / (256 / options->grayLevels);

		// Interpolate the gray level between the full black and full white value.
		//totalLightness = qMin(grayLevel * (255 / (options->grayLevels - 1)), 255);
		totalLightness = options->fullBlack + (int)((options->fullWhite - options->fullBlack) * (1. * grayLevel / (options->grayLevels - 1.)));
		totalLightness = qMax(qMin(totalLightness, 255), 0);
	}

	painter.fillRect(x, y, options->pixelSize, options->pixelSize, QColor(totalLightness, totalLightness, totalLightness));*/
}

QImage & ETSProsthesis::getImage()
{
	return img;
}
