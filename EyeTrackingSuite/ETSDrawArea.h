#pragma once

#include <QLabel>
#include "ETSScotoma.h"
#include "ETSProsthesis.h"

class ETSDrawArea : public QLabel
{
	Q_OBJECT

private:

	QImage baseImg;
	QString baseImgFilename;

	bool imgLoaded;
	QPoint gazeLocalPos;
	ETSScotoma scotoma;
	ETSProsthesis prosthesis;

	int resizeTimerId;

public:

	QImage img;

public:
	ETSDrawArea(QWidget *parent);
	~ETSDrawArea();

	bool setBaseImage(QString filename);
	bool loadBaseImage();
	void repaintDrawArea(class EyeTrackingSuite * ets);

	void setGazeLocalPosition(QPoint pos);
	void setGazeScreenPosition(QPoint pos);

protected:

	virtual void resizeEvent(QResizeEvent *event) override;
	virtual void timerEvent(QTimerEvent *event) override;
	

};
