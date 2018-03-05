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

void ETSProsthesis::drawOverImage(QPainter& painter, QPointF& prosthesisCenter, int prosthesisRadius)
{
	// Create a rectangle for the final part of the image that will receive the prosthesis.
	QRect prosthesisRect = QRect(prosthesisCenter.x() - prosthesisRadius, prosthesisCenter.y() - prosthesisRadius, prosthesisRadius * 2, prosthesisRadius * 2);
	
	// Set the painter to confine drawing operations to just the prosthesis circle (so we don't get square edges).
	QPainterPath oldClipPath = painter.clipPath();
	QPainterPath newClipPath = QPainterPath();
	newClipPath.addEllipse(prosthesisRect);
	painter.setClipPath(newClipPath);

	// Draw from the prosthesis image into the regular image.
	painter.drawImage(prosthesisRect, img, prosthesisRect);

	// Turn clipping off after completing this draw.
	painter.setClipPath(oldClipPath, Qt::ClipOperation::NoClip);
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
