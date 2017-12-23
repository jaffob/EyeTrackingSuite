#pragma once

#include <QLabel>

class ETSDrawArea : public QLabel
{
	Q_OBJECT

private:

	QImage baseImg;
	QImage img;
	bool imgLoaded;

public:
	ETSDrawArea(QWidget *parent);
	~ETSDrawArea();

	bool loadBaseImage(QString filename);
	void repaintDrawArea();
};
