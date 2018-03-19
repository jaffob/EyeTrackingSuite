#pragma once

#include <QLabel>
#include "ETSScotoma.h"
#include "ETSProsthesis.h"

class ETSDrawArea : public QLabel
{
	Q_OBJECT

private:

	class EyeTrackingSuite * ets;
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

	void attachETS(class EyeTrackingSuite * ets);

	void repaintDrawArea();

	void setGazeLocalPosition(QPoint pos);
	void setGazeScreenPosition(QPoint pos);

	QPoint getImageOffset() const;

protected:

	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void resizeEvent(QResizeEvent *event) override;
	virtual void timerEvent(QTimerEvent *event) override;
	

};
