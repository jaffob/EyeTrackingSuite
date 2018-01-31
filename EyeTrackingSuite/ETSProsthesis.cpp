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
	img = QImage(source);
	QPainter painter(&img);

	// Iterate over pixels in the prosthesis area.
	for (int i = 0; i < img.width(); i += options->pixelSize)
	{
		for (int j = 0; j < img.height(); j += options->pixelSize)
		{
			makeProsthesis_Pixel(painter, options, i, j);
		}
	}
}

void ETSProsthesis::makeProsthesis_Pixel(QPainter& painter, ETSProsthesisDrawOptions * options, int x, int y)
{
	int totalLightness = 0, totalN = 0;
	
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
	
	// Total lightness of this prosthesis pixel is the average of all the screen pixels.
	totalLightness /= totalN;
	
	// Force this value to one of the gray levels.
	int grayLevel = totalLightness / (256 / options->grayLevels);
	totalLightness = qMin(grayLevel * (255 / (options->grayLevels - 1)), 255);
	
	painter.fillRect(x, y, options->pixelSize, options->pixelSize, QColor(totalLightness, totalLightness, totalLightness));
}

QImage & ETSProsthesis::getImage()
{
	return img;
}
