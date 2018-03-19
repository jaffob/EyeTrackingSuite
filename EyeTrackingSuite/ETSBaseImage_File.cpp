#include "ETSBaseImage_File.h"
#include <QImage>
#include <QImageReader>
#include <QSize>

ETSBaseImage_File::ETSBaseImage_File()
	: fileImg()
	, scaledImg()
	, drawAreaSize()
	, imgLoaded(false)
{
}

ETSBaseImage_File::~ETSBaseImage_File()
{
}

bool ETSBaseImage_File::loadFromFile(QString filename)
{
	// Read the image from the filename specified.
	QImageReader imgReader(filename);
	fileImg = imgReader.read();
	imgLoaded = !fileImg.isNull();
	if (!imgLoaded)
		return false;

	// Copy this into scaledImg. If we don't yet know draw area size, copy directly.
	if (drawAreaSize.isEmpty())
		scaledImg = QImage(fileImg);
	else
		regenerateForSize(drawAreaSize);

	return true;
}

bool ETSBaseImage_File::regenerateForSize(QSize drawAreaSize)
{
	this->drawAreaSize = drawAreaSize;

	// Scale the base image to fit the size of the widget.
	scaledImg = fileImg.scaled(drawAreaSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

	return true;
}

QImage ETSBaseImage_File::getImage() const
{
	return QImage(scaledImg);
}

bool ETSBaseImage_File::isValid() const
{
	return imgLoaded;
}
