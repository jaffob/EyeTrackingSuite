#include "ETSScotoma.h"
#include <QtMath>

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
	img = QImage(options->radius * 2, options->radius * 2, QImage::Format::Format_ARGB32_Premultiplied);

	// Do some pre-calculations.
	QPoint center = QPoint(img.width() / 2, img.height() / 2);
	int radiusSq = options->radius * options->radius;
	int prosthesisEdge = options->radius * (options->prosthesisSizePercent / 100.f);
	int prosthesisEdgeSq = prosthesisEdge * prosthesisEdge;
	int gradInside = options->radius * (qMax(options->gradientInside, options->gradientOutside) / 100.f);
	int gradOutside = options->radius * (options->gradientOutside / 100.f);
	int gradInsideSq = gradInside * gradInside;
	int gradOutsideSq = gradOutside * gradOutside;
	
	// Iterate over all pixels.
	for (int i = 0; i < img.width(); i++)
	{
		for (int j = 0; j < img.height(); j++)
		{
			float alpha = 1.f;													// Alpha of this pixel, 0 to 1.
			int distSq = qPow(center.x() - i, 2) + qPow(center.y() - j, 2);		// Squared distance of this point from the center.

			// If this pixel is outside the total radius, it's transparent.
			if (distSq > radiusSq)
			{
				alpha = 0.f;
			}

			// Prostheis.
			else if (options->prosthesisEnabled && distSq < prosthesisEdgeSq)
			{
				alpha = 0.f;
			}

			// Outside fade.
			else if (options->gradientEnabled && distSq > gradOutsideSq)
			{
				if (options->gradientSquaredFalloff)
					alpha = 1.f - (float)(distSq - gradOutsideSq) / (radiusSq - gradOutsideSq);
				else
					alpha = 1.f - (float)(qSqrt(distSq) - gradOutside) / (options->radius - gradOutside);
			}

			img.setPixelColor(i, j, QColor(110.f, 110.f, 110.f, 255.f * alpha));
		}
	}
}

QImage & ETSScotoma::getImage()
{
	return img;
}
