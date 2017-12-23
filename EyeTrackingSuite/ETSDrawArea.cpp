#include "ETSDrawArea.h"
#include <QImageReader>
#include <QImage>

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
	imgReader.setScaledSize(size());
	baseImg = imgReader.read();
	
	imgLoaded = !baseImg.isNull();
	return imgLoaded;
}

void ETSDrawArea::repaintDrawArea()
{
	if (!imgLoaded)
		return;

	img = QImage(baseImg);
	setPixmap(QPixmap::fromImage(img));
}
