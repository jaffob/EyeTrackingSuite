/********************************************************************************
** Form generated from reading UI file 'EyeTrackingSuite.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EYETRACKINGSUITE_H
#define UI_EYETRACKINGSUITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "etsdrawarea.h"

QT_BEGIN_NAMESPACE

class Ui_EyeTrackingSuiteClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    ETSDrawArea *mainDrawArea;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QPushButton *tobiiReconnect;
    QLabel *tobiiLabel;
    QGroupBox *groupBox_2;
    QSlider *scotomaRadius;
    QCheckBox *scotomaEnabled;
    QLabel *label;
    QGroupBox *groupBox_3;
    QCheckBox *prosthesisEnabled;
    QLabel *label_2;
    QSlider *prosthesisSize;
    QLabel *label_3;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QSlider *calibrationHoriz;
    QSlider *calibrationVert;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EyeTrackingSuiteClass)
    {
        if (EyeTrackingSuiteClass->objectName().isEmpty())
            EyeTrackingSuiteClass->setObjectName(QStringLiteral("EyeTrackingSuiteClass"));
        EyeTrackingSuiteClass->resize(914, 724);
        centralWidget = new QWidget(EyeTrackingSuiteClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mainDrawArea = new ETSDrawArea(centralWidget);
        mainDrawArea->setObjectName(QStringLiteral("mainDrawArea"));
        mainDrawArea->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(mainDrawArea);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(250, 0));
        scrollArea->setBaseSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 651));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 211, 81));
        tobiiReconnect = new QPushButton(groupBox);
        tobiiReconnect->setObjectName(QStringLiteral("tobiiReconnect"));
        tobiiReconnect->setGeometry(QRect(120, 30, 81, 31));
        tobiiLabel = new QLabel(groupBox);
        tobiiLabel->setObjectName(QStringLiteral("tobiiLabel"));
        tobiiLabel->setGeometry(QRect(10, 30, 101, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        tobiiLabel->setFont(font);
        tobiiLabel->setAlignment(Qt::AlignCenter);
        tobiiLabel->raise();
        tobiiReconnect->raise();
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 300, 211, 101));
        scotomaRadius = new QSlider(groupBox_2);
        scotomaRadius->setObjectName(QStringLiteral("scotomaRadius"));
        scotomaRadius->setGeometry(QRect(50, 60, 141, 22));
        scotomaRadius->setMinimum(10);
        scotomaRadius->setMaximum(200);
        scotomaRadius->setValue(50);
        scotomaRadius->setOrientation(Qt::Horizontal);
        scotomaEnabled = new QCheckBox(groupBox_2);
        scotomaEnabled->setObjectName(QStringLiteral("scotomaEnabled"));
        scotomaEnabled->setGeometry(QRect(20, 30, 171, 17));
        scotomaEnabled->setChecked(true);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 31, 21));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 420, 211, 131));
        prosthesisEnabled = new QCheckBox(groupBox_3);
        prosthesisEnabled->setObjectName(QStringLiteral("prosthesisEnabled"));
        prosthesisEnabled->setGeometry(QRect(20, 30, 171, 17));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 51, 21));
        prosthesisSize = new QSlider(groupBox_3);
        prosthesisSize->setObjectName(QStringLiteral("prosthesisSize"));
        prosthesisSize->setGeometry(QRect(70, 60, 121, 22));
        prosthesisSize->setMinimum(0);
        prosthesisSize->setMaximum(100);
        prosthesisSize->setValue(25);
        prosthesisSize->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 61, 21));
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 120, 211, 161));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 30, 91, 21));
        calibrationHoriz = new QSlider(groupBox_4);
        calibrationHoriz->setObjectName(QStringLiteral("calibrationHoriz"));
        calibrationHoriz->setGeometry(QRect(20, 60, 171, 22));
        calibrationHoriz->setMinimum(-200);
        calibrationHoriz->setMaximum(200);
        calibrationHoriz->setValue(0);
        calibrationHoriz->setOrientation(Qt::Horizontal);
        calibrationVert = new QSlider(groupBox_4);
        calibrationVert->setObjectName(QStringLiteral("calibrationVert"));
        calibrationVert->setGeometry(QRect(20, 120, 171, 22));
        calibrationVert->setMinimum(-200);
        calibrationVert->setMaximum(200);
        calibrationVert->setValue(0);
        calibrationVert->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 91, 21));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        EyeTrackingSuiteClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EyeTrackingSuiteClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 914, 21));
        EyeTrackingSuiteClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EyeTrackingSuiteClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EyeTrackingSuiteClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EyeTrackingSuiteClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EyeTrackingSuiteClass->setStatusBar(statusBar);

        retranslateUi(EyeTrackingSuiteClass);
        QObject::connect(tobiiReconnect, SIGNAL(clicked()), EyeTrackingSuiteClass, SLOT(onTobiiReconnectClicked()));
        QObject::connect(scotomaEnabled, SIGNAL(stateChanged(int)), EyeTrackingSuiteClass, SLOT(onScotomaEnabled(int)));
        QObject::connect(scotomaRadius, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onScotomaRadiusChanged(int)));
        QObject::connect(calibrationHoriz, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationHorizChanged(int)));
        QObject::connect(calibrationVert, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationVertChanged(int)));
        QObject::connect(prosthesisEnabled, SIGNAL(stateChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisEnabled(int)));
        QObject::connect(prosthesisSize, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisSizeChanged(int)));

        QMetaObject::connectSlotsByName(EyeTrackingSuiteClass);
    } // setupUi

    void retranslateUi(QMainWindow *EyeTrackingSuiteClass)
    {
        EyeTrackingSuiteClass->setWindowTitle(QApplication::translate("EyeTrackingSuiteClass", "Eye Tracking Suite", nullptr));
        mainDrawArea->setText(QApplication::translate("EyeTrackingSuiteClass", "TextLabel", nullptr));
        groupBox->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Tobii", nullptr));
        tobiiReconnect->setText(QApplication::translate("EyeTrackingSuiteClass", "Reconnect", nullptr));
        tobiiLabel->setText(QApplication::translate("EyeTrackingSuiteClass", "Disconnected", nullptr));
        groupBox_2->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Scotoma", nullptr));
        scotomaEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Scotoma", nullptr));
        label->setText(QApplication::translate("EyeTrackingSuiteClass", "Size:", nullptr));
        groupBox_3->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Prosthesis", nullptr));
        prosthesisEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Prosthesis", nullptr));
        label_2->setText(QApplication::translate("EyeTrackingSuiteClass", "Size (%):", nullptr));
        label_3->setText(QApplication::translate("EyeTrackingSuiteClass", "Gray Level:", nullptr));
        groupBox_4->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Calibration", nullptr));
        label_4->setText(QApplication::translate("EyeTrackingSuiteClass", "Horizontal Offset:", nullptr));
        label_5->setText(QApplication::translate("EyeTrackingSuiteClass", "Vertical Offset:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EyeTrackingSuiteClass: public Ui_EyeTrackingSuiteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYETRACKINGSUITE_H
