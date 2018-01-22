#include "ETSDrawArea.h"

#include "EyeTrackingSuite.h"
#include "ETSScotoma.h"

#include <QImageReader>
#include <QImage>
#include <QPainter>

ETSDrawArea::ETSDrawArea(QWidget *parent)
	: QLabel(parent)
	, imgLoaded(false)
	, scotoma()
{
}

ETSDrawArea::~ETSDrawArea()
{
}

bool ETSDrawArea::loadBaseImage(QString filename)
{
	// Read the image from the filename specified.
	QImageReader imgReader(filename);
	//imgReader.setScaledSize(size());
	baseImg = imgReader.read();
	
	imgLoaded = !baseImg.isNull();
	return imgLoaded;
}

void ETSDrawArea::repaintDrawArea(EyeTrackingSuite * ets)
{
	if (!imgLoaded)
		return;

	// Determine the eye position from the local position adjusted for calibration.
	QPointF finalEyePos = QPointF(gazeLocalPos.x() + ets->optCalibrationHoriz, gazeLocalPos.y() + ets->optCalibrationVert);

	// Copy the base image into the image buffer. That is, overwrite the last
	// frame's drawing with just the base image.
	img = QImage(baseImg);

	// Initialize drawing.
	QPainter painter(&img);
	painter.setBrush(Qt::black);
	
	// Remake the scotoma if the options have changed.
	if (ets->consumeScotomaDrawChangedFlag())
	{
		scotoma.makeScotoma(&ets->optScotoma);
	}

	// Reduce image quality in the area of the prosthesis.
	if (ets->optScotoma.prosthesisEnabled)
	{
		drawProsthesis(ets, finalEyePos, painter);
	}

	// Draw the scotoma.
	if (ets->optScotomaEnabled)
	{
		painter.drawImage(finalEyePos - QPointF(ets->optScotoma.radius, ets->optScotoma.radius), scotoma.getImage());
	}

	// Block half of the visual field, if so desired.
	if (ets->optHalfField == 1)
	{
		painter.drawRect(0, 0, finalEyePos.x(), img.height());
	}
	else if (ets->optHalfField == 2)
	{
		painter.drawRect(finalEyePos.x(), 0, img.width() - finalEyePos.x(), img.height());
	}

	painter.end();

	// Dump the image buffer to the label's pixmap.
	setPixmap(QPixmap::fromImage(img));
	repaint();
}

void ETSDrawArea::drawProsthesis(EyeTrackingSuite * ets, QPointF& finalEyePos, QPainter& painter)
{
	// Radius of the prosthesis (we were given a percent).
	int prosthesisRadius = ets->optScotoma.radius * (ets->optScotoma.prosthesisSizePercent / 100.f);
	int prosthesisRadiusSq = prosthesisRadius * prosthesisRadius;

	// Buckets for resolution reduction.
	/*unsigned int bucketN = prosthesisRadius / ets->optScotoma.prosthesisPixelSize;
	if (prosthesisRadius % ets->optScotoma.prosthesisPixelSize) bucketN++;*/
	
	// Iterate over pixels in the prosthesis area.
	for (int i = qMax(0, (int)finalEyePos.x() - prosthesisRadius); i < qMin((int)finalEyePos.x() + prosthesisRadius, img.width()); i += ets->optScotoma.prosthesisPixelSize)
	{
		for (int j = qMax(0, (int)finalEyePos.y() - prosthesisRadius); j < qMin((int)finalEyePos.y() + prosthesisRadius, img.height()); j += ets->optScotoma.prosthesisPixelSize)
		{
			// Ignore pixels outside the circular radius.
			/*int pixDistSq = pow(finalEyePos.x() - i, 2) + pow(finalEyePos.y() - j, 2);
			if (pixDistSq > prosthesisRadiusSq) continue;*/

			drawProsthesis_Pixel(ets, painter, i, j);

			/*QColor pix = img.pixelColor(i, j);
			drawProsthesis_Pixel(ets, pix);
			img.setPixelColor(i, j, pix);*/
		}
	}
}

void ETSDrawArea::setGazeLocalPosition(QPoint pos)
{
	gazeLocalPos = pos;
}

void ETSDrawArea::setGazeScreenPosition(QPoint pos)
{
	// We were given a screen position of the user's gaze. Save the position
	// relative to the widget.
	gazeLocalPos = mapFromGlobal(pos);
	gazeLocalPos.setY(gazeLocalPos.y() - 100);
}

void ETSDrawArea::drawProsthesis_Pixel(EyeTrackingSuite * ets, QPainter& painter, int x, int y)
{
	int totalLightness = 0, totalN = 0;

	// Iterate over all the screen pixels in this prosthesis pixel.
	for (int i = x; i < qMin(x + ets->optScotoma.prosthesisPixelSize, img.width()); i++)
	{
		for (int j = y; j < qMin(y + ets->optScotoma.prosthesisPixelSize, img.height()); j++)
		{
			QColor pix = img.pixelColor(i, j);
			totalLightness += pix.lightness();
			totalN++;
		}
	}

	// Total lightness of this prosthesis pixel is the average of all the screen pixels.
	totalLightness /= totalN;

	// Force this value to one of the gray levels.
	int grayLevel = totalLightness / (256 / ets->optScotoma.prosthesisGrayLevels);
	totalLightness = grayLevel * (255 / (ets->optScotoma.prosthesisGrayLevels - 1));

	painter.fillRect(x, y, ets->optScotoma.prosthesisPixelSize, ets->optScotoma.prosthesisPixelSize, QColor(totalLightness, totalLightness, totalLightness));
}
