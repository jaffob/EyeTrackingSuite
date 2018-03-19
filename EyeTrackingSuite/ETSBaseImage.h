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

	/**
	 * Special version of getImage() for making the prosthesis.
	 */
	virtual QImage getProsthesisBase() const;

	/**
	 * Hook for adding last minute modifications to a prosthesis image.
	 */
	virtual void prosthesisPostEdit(QImage& prosthesisImg);

};