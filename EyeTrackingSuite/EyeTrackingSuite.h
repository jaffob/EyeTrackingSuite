#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EyeTrackingSuite.h"
#include "ETSTobii.h"

class EyeTrackingSuite : public QMainWindow
{
    Q_OBJECT

private:
	Ui::EyeTrackingSuiteClass ui;

private:

	ETSTobii * tobii;
	ETSDrawArea * drawArea;
	int timerId;

public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);
	~EyeTrackingSuite();

protected:

	virtual void timerEvent(QTimerEvent *event) override;

	static void onGazePointReceived(float alpha, float beta, void * context);

	void reconnectToTobii();

public slots:

	void onTobiiReconnectClicked();

};
