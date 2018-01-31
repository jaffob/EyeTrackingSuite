#pragma once

#include <QLabel>
#include "ETSScotoma.h"
#include "ETSProsthesis.h"

class ETSDrawArea : public QLabel
{
	Q_OBJECT

private:

	QImage baseImg;
	bool imgLoaded;
	QPoint gazeLocalPos;
	ETSScotoma scotoma;
	ETSProsthesis prosthesis;

public:

	QImage img;

public:
	ETSDrawArea(QWidget *parent);
	~ETSDrawArea();

	bool loadBaseImage(QString filename);
	void repaintDrawArea(class EyeTrackingSuite * ets);
	void drawProsthesis(class EyeTrackingSuite * ets, QPointF& finalEyePos, QPainter& painter);

	void setGazeLocalPosition(QPoint pos);
	void setGazeScreenPosition(QPoint pos);

private:

	void drawProsthesis_Pixel(class EyeTrackingSuite * ets, QPainter& painter, int x, int y);
};
