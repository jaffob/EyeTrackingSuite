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

	// Options.
	int optCalibrationHoriz;
	int optCalibrationVert;
	bool optScotomaEnabled;
	int optScotomaRadius;
	bool optProsthesisEnabled;
	int optProsthesisSizePercent;
	int optProsthesisGrayLevel;

public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);
	~EyeTrackingSuite();

protected:

	virtual void timerEvent(QTimerEvent *event) override;

	static void onGazePointReceived(float alpha, float beta, void * context);

	void reconnectToTobii();

public slots:

	void onTobiiReconnectClicked();
	void onCalibrationHorizChanged(int newValue);
	void onCalibrationVertChanged(int newValue);
	void onScotomaEnabled(int enabled);
	void onScotomaRadiusChanged(int newValue);
	void onProsthesisEnabled(int enabled);
	void onProsthesisSizeChanged(int newValue);
	void onProsthesisGrayLevelChanged(int newValue);

};
