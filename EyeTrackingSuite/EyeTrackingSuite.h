#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EyeTrackingSuite.h"
#include "ETSTobii.h"
#include "ETSScotoma.h"
#include "ETSProsthesis.h"

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
	ETSScotomaDrawOptions optScotoma;
	ETSProsthesisDrawOptions optProsthesis;
	int optHalfField;

public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);
	~EyeTrackingSuite();

protected:

	virtual void timerEvent(QTimerEvent *event) override;

	static void onGazePointReceived(float alpha, float beta, void * context);

	void reconnectToTobii();

public slots:

	// General.
	void onTobiiReconnectClicked();
	void onCalibrationHorizChanged(int newValue);
	void onCalibrationVertChanged(int newValue);
	void onImageComboBoxChanged(QString newText);

	// Central vision.
	void onScotomaEnabled(bool enabled);
	void onScotomaRadiusChanged(int newValue);
	void onScotomaAutoSize();
	void onProsthesisEnabled(bool enabled);
	void onProsthesisSizeChanged(int newValue);
	void onProsthesisGrayLevelChanged(int newValue);
	void onProsthesisPixelSizeChanged(int newValue);
	void onGradientEnabled(bool enabled);
	void onGradientInsideChanged(int newValue);
	void onGradientOutsideChanged(int newValue);

	// Visual field.
	void onHalfFieldBlockNone(bool enabled);
	void onHalfFieldBlockLeft(bool enabled);
	void onHalfFieldBlockRight(bool enabled);

	// Menu actions.
	void onActionAbout();
};
