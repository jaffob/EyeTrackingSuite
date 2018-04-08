#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EyeTrackingSuite.h"
#include "ETSTobii.h"
#include "ETSScotoma.h"
#include "ETSProsthesis.h"
#include "ETSPhysicalUnitSystem.h"
#include "ETSBaseImage_VisionChart.h"
#include "ETSVisionChartText.h"

class EyeTrackingSuite : public QMainWindow
{
    Q_OBJECT

private:
	Ui::EyeTrackingSuiteClass ui;

public:

	static const unsigned int optionsFileVersion;

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
	ETSVisionChartOptions optVisionChart;
	int optPhysDPICalib;
	int optHalfField;

	// Base image.
	class ETSBaseImage * baseImage;

	// Vision chart texts.
	ETSVisionChartText visTexts;
	
public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);
	~EyeTrackingSuite();

	void onPhysicalUnitSystemUpdate();

	void setCalibration(int h, int v);
	bool isTobiiConnected() const;

protected:

	void loadNewBaseImage();

	virtual void timerEvent(QTimerEvent *event) override;

	static void onGazePointReceived(float alpha, float beta, void * context);

	void reconnectToTobii();

	void autoResizeScotoma();
	void autoResizeProsthesisPixels();

	// Settings and files.
	void readOptionsFile();
	void writeOptionsFile();

	virtual void closeEvent(QCloseEvent *event) override;

public slots:

	// General.
	void onTobiiReconnectClicked();
	void onCalibrationHorizChanged(int newValue);
	void onCalibrationVertChanged(int newValue);
	void onPhysViewDistChanged(int newValue);
	void onPhysDPICalibChanged(int newValue);
	void onPhysDPICalibHelp();
	void onImageComboBoxChanged(QString newText);
	void onVisFontChanged(int newIndex);
	void onVisFontBoldChanged(bool enabled);
	void onVisTextNumberChanged(int newValue);
	void onVisTextDifferentChanged(bool enabled);
	void onVisTextCapitalChanged(bool enabled);

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
