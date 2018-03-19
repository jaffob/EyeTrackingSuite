#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EyeTrackingSuite.h"
#include "ETSTobii.h"
#include "ETSScotoma.h"
#include "ETSProsthesis.h"
#include "ETSPhysicalUnitSystem.h"

class EyeTrackingSuite : public QMainWindow
{
    Q_OBJECT

private:
	Ui::EyeTrackingSuiteClass ui;

private:

	ETSTobii * tobii;
	ETSDrawArea * drawArea;
	int timerId;
	ETSPhysicalUnitSystem * physUnits;

public:

	// Options.
	int optCalibrationHoriz;
	int optCalibrationVert;
	bool optScotomaEnabled;
	bool optScotomaUseDegrees;
	ETSScotomaDrawOptions optScotoma;
	ETSProsthesisDrawOptions optProsthesis;
	int optHalfField;

	// Base image.
	class ETSBaseImage * baseImage;

public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);
	~EyeTrackingSuite();

	void onPhysicalUnitSystemUpdate();

protected:

	void loadNewBaseImage();

	virtual void timerEvent(QTimerEvent *event) override;

	static void onGazePointReceived(float alpha, float beta, void * context);

	void reconnectToTobii();

	void autoResizeScotoma();
	void autoResizeProsthesisPixels();

public slots:

	// General.
	void onTobiiReconnectClicked();
	void onCalibrationHorizChanged(int newValue);
	void onCalibrationVertChanged(int newValue);
	void onPhysViewDistChanged(int newValue);
	void onImageComboBoxChanged(QString newText);

	// Central vision.
	void onScotomaEnabled(bool enabled);
	void onScotomaUseDegrees(bool enabled);
	void onScotomaRadiusChanged(int newValue);
	void onScotomaSizeDegreesChanged(int newValue);
	void onProsthesisEnabled(bool enabled);
	void onProsthesisSizeChanged(int newValue);
	void onProsthesisGrayLevelChanged(int newValue);
	void onProsthesisPixelSizeChanged(int newValue);
	void onProsthesisFullBlackChanged();
	void onProsthesisFullWhiteChanged();
	void onGradientEnabled(bool enabled);
	void onGradientInsideChanged(int newValue);
	void onGradientOutsideChanged(int newValue);

	// Visual field.
	void onHalfFieldBlockNone(bool enabled);
	void onHalfFieldBlockLeft(bool enabled);
	void onHalfFieldBlockRight(bool enabled);

	// Menu actions.
	void onActionFullscreen(bool newValue);
	void onActionShowControls(bool newValue);
	void onActionAbout();
};
