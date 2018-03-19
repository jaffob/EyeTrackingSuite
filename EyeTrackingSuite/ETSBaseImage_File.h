#pragma once
#include "ETSBaseImage.h"

class ETSBaseImage_File : public ETSBaseImage
{

private:

	QImage fileImg;		// Image as read directly from file.
	QImage scaledImg;	// fileImg scaled by regenerateForSize()
	QSize drawAreaSize;
	bool imgLoaded;

public:

	ETSBaseImage_File();
	~ETSBaseImage_File();

	/**
	 * Loads a new file to use as the base image. If regenerateForSize() has
	 * been called before, the old size is remembered and a properly scaled
	 * image will immediately be available.
	 */
	virtual bool loadFromFile(QString filename);

	virtual bool regenerateForSize(QSize drawAreaSize) override;
	virtual QImage getImage() const override;
	virtual bool isValid() const override;
};