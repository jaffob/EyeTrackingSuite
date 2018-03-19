#pragma once
#include <QObject>
#include <QImage>

class ETSBaseImage : public QObject
{

public:

	/**
	 * Re-generate the underlying base image for the given draw
	 * area size. Should generate an image scaled to fit within
	 * the bounds of drawAreaSize. Returns whether the operation
	 * was successful.
	 */
	virtual bool regenerateForSize(QSize drawAreaSize) = 0;

	/**
	 * Returns a copy of the base image.
	 */
	virtual QImage getImage() const = 0;

	/**
	 * Whether getImage() is currently able to return a valid image.
	 */
	virtual bool isValid() const = 0;

};