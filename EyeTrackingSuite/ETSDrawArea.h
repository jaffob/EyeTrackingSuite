#pragma once

#include <QLabel>
#include "ETSScotoma.h"

class ETSDrawArea : public QLabel
{
	Q_OBJECT

private:

	QImage baseImg;
	QImage img;
	bool imgLoaded;
	QPoint gazeLocalPos;
	ETSScotoma scotoma;

public:
	ETSDrawArea(QWidget *parent);
	~ETSDrawArea();

	bool loadBaseImage(QString filename);
	void repaintDrawArea(class EyeTrackingSuite * ets);

	void setGazeLocalPosition(QPoint pos);
	void setGazeScreenPosition(QPoint pos);

};
