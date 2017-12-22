#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EyeTrackingSuite.h"

class EyeTrackingSuite : public QMainWindow
{
    Q_OBJECT

public:
    EyeTrackingSuite(QWidget *parent = Q_NULLPTR);

private:
    Ui::EyeTrackingSuiteClass ui;
};
