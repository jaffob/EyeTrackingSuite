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

	// Draw the scotoma.
	if (ets->optScotomaEnabled)
	{
		// Draw the scotoma at the stored local position, accounting for the user's calibration.
		QPointF scotomaDrawPos = QPointF(gazeLocalPos.x() + ets->optCalibrationHoriz, gazeLocalPos.y() + ets->optCalibrationVert);

		// Draw it.
		painter.drawEllipse(scotomaDrawPos, ets->optScotoma.radius, ets->optScotoma.radius);
		
		// For when we implement drawing the ETSScotoma.
		//painter.drawImage(scotomaDrawPos, scotoma.getImage());
	}

	painter.end();

	// Dump the image buffer to the label's pixmap.
	setPixmap(QPixmap::fromImage(img));
	repaint();
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
