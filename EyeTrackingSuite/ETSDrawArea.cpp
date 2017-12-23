#include "ETSDrawArea.h"
#include <QImageReader>
#include <QImage>
#include <QPainter>

ETSDrawArea::ETSDrawArea(QWidget *parent)
	: QLabel(parent)
	, imgLoaded(false)
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

void ETSDrawArea::repaintDrawArea()
{
	if (!imgLoaded)
		return;

	// Copy the base image into the image buffer.
	img = QImage(baseImg);

	// Draw a basic scotoma.
	QPainter painter(&img);
	painter.setBrush(Qt::black);
	painter.drawEllipse(QPointF(gazeLocalPos), 50, 50);
	painter.end();

	// Dump the image buffer to the label's pixmap.
	setPixmap(QPixmap::fromImage(img));
	repaint();
}

void ETSDrawArea::setGazeScreenPosition(QPoint pos)
{
	// We were given a screen position of the user's gaze. Save the position
	// relative to the widget.
	gazeLocalPos = mapFromGlobal(pos);
}
