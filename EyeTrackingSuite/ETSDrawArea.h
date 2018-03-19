#pragma once

#include <QLabel>
#include "ETSScotoma.h"
#include "ETSProsthesis.h"

class ETSDrawArea : public QLabel
{
	Q_OBJECT

private:

	QPoint gazeLocalPos;
	ETSScotoma scotoma;
	ETSProsthesis prosthesis;

	int resizeTimerId;
	bool resizeFlag;

public:

	QImage img;

public:
	ETSDrawArea(QWidget *parent);
	~ETSDrawArea();

	void repaintDrawArea(class EyeTrackingSuite * ets);

	void setGazeLocalPosition(QPoint pos);
	void setGazeScreenPosition(QPoint pos);

protected:

	virtual void resizeEvent(QResizeEvent *event) override;
	virtual void timerEvent(QTimerEvent *event) override;
	

};
