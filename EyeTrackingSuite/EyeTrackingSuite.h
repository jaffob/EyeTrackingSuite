#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EyeTrackingSuite.h"
#include "ETSTobii.h"
#include "ETSScotoma.h"

class EyeTrackingSuite : public QMainWindow
{
    Q_OBJECT

private:
	Ui::EyeTrackingSuiteClass ui;

private:

	ETSTobii * tobii;
	ETSDrawArea * drawArea;
	int timerId;

	bool scotomaDrawChangedFlag;
	
public:

	// Options.
	int optCalibrationHoriz;
	int optCalibrationVert;
	bool optScotomaEnabled;
	ETSScotomaDrawOptions optScotoma;
	int optHalfField;

public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);
	~EyeTrackingSuite();

protected:

	virtual void timerEvent(QTimerEvent *event) override;

	static void onGazePointReceived(float alpha, float beta, void * context);

	void reconnectToTobii();

public:

	/**
	 * Returns whether the scotoma visual options have changed, and
	 * resets the flag to false.
	 */
	bool consumeScotomaDrawChangedFlag();

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
};
