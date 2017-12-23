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

public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);
};
