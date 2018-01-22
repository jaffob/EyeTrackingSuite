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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "etsdrawarea.h"

QT_BEGIN_NAMESPACE

class Ui_EyeTrackingSuiteClass
{
public:
    QAction *actionSwitch_Application;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    ETSDrawArea *mainDrawArea;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QPushButton *tobiiReconnect;
    QLabel *tobiiLabel;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QSlider *calibrationHoriz;
    QSlider *calibrationVert;
    QLabel *label_5;
    QGroupBox *groupBox_6;
    QComboBox *imageComboBox;
    QWidget *tab_4;
    QGroupBox *groupBox_2;
    QSlider *scotomaRadius;
    QCheckBox *scotomaEnabled;
    QLabel *label;
    QGroupBox *groupBox_3;
    QCheckBox *prosthesisEnabled;
    QLabel *label_2;
    QSlider *prosthesisSize;
    QLabel *label_3;
    QSpinBox *prosthesisGrayLevel;
    QSpinBox *prosthesisPixelSize;
    QLabel *label_8;
    QGroupBox *groupBox_7;
    QCheckBox *gradientEnabled;
    QSlider *gradientInside;
    QLabel *label_6;
    QSlider *gradientOutside;
    QLabel *label_7;
    QWidget *tab;
    QGroupBox *groupBox_5;
    QRadioButton *halfFieldBlockNone;
    QRadioButton *halfFieldBlockLeft;
    QRadioButton *halfFieldBlockRight;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EyeTrackingSuiteClass)
    {
        if (EyeTrackingSuiteClass->objectName().isEmpty())
            EyeTrackingSuiteClass->setObjectName(QStringLiteral("EyeTrackingSuiteClass"));
        EyeTrackingSuiteClass->resize(914, 724);
        actionSwitch_Application = new QAction(EyeTrackingSuiteClass);
        actionSwitch_Application->setObjectName(QStringLiteral("actionSwitch_Application"));
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

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(250, 0));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
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
        groupBox_4 = new QGroupBox(tab_3);
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
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 300, 211, 71));
        imageComboBox = new QComboBox(groupBox_6);
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->setObjectName(QStringLiteral("imageComboBox"));
        imageComboBox->setGeometry(QRect(20, 30, 171, 22));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 20, 211, 101));
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
        scotomaEnabled->setChecked(false);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 31, 21));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 140, 211, 161));
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
        prosthesisGrayLevel = new QSpinBox(groupBox_3);
        prosthesisGrayLevel->setObjectName(QStringLiteral("prosthesisGrayLevel"));
        prosthesisGrayLevel->setGeometry(QRect(90, 90, 42, 22));
        prosthesisGrayLevel->setMinimum(2);
        prosthesisGrayLevel->setMaximum(10);
        prosthesisGrayLevel->setValue(8);
        prosthesisPixelSize = new QSpinBox(groupBox_3);
        prosthesisPixelSize->setObjectName(QStringLiteral("prosthesisPixelSize"));
        prosthesisPixelSize->setGeometry(QRect(90, 120, 42, 22));
        prosthesisPixelSize->setMinimum(1);
        prosthesisPixelSize->setMaximum(200);
        prosthesisPixelSize->setValue(5);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 120, 61, 21));
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 320, 211, 131));
        gradientEnabled = new QCheckBox(groupBox_7);
        gradientEnabled->setObjectName(QStringLiteral("gradientEnabled"));
        gradientEnabled->setGeometry(QRect(20, 30, 181, 17));
        gradientInside = new QSlider(groupBox_7);
        gradientInside->setObjectName(QStringLiteral("gradientInside"));
        gradientInside->setGeometry(QRect(90, 60, 101, 22));
        gradientInside->setMinimum(0);
        gradientInside->setMaximum(95);
        gradientInside->setValue(40);
        gradientInside->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 60, 71, 21));
        gradientOutside = new QSlider(groupBox_7);
        gradientOutside->setObjectName(QStringLiteral("gradientOutside"));
        gradientOutside->setGeometry(QRect(90, 90, 101, 22));
        gradientOutside->setMinimum(0);
        gradientOutside->setMaximum(95);
        gradientOutside->setValue(60);
        gradientOutside->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 90, 71, 21));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 20, 211, 131));
        halfFieldBlockNone = new QRadioButton(groupBox_5);
        halfFieldBlockNone->setObjectName(QStringLiteral("halfFieldBlockNone"));
        halfFieldBlockNone->setGeometry(QRect(20, 30, 171, 17));
        halfFieldBlockNone->setChecked(true);
        halfFieldBlockLeft = new QRadioButton(groupBox_5);
        halfFieldBlockLeft->setObjectName(QStringLiteral("halfFieldBlockLeft"));
        halfFieldBlockLeft->setGeometry(QRect(20, 60, 171, 17));
        halfFieldBlockRight = new QRadioButton(groupBox_5);
        halfFieldBlockRight->setObjectName(QStringLiteral("halfFieldBlockRight"));
        halfFieldBlockRight->setGeometry(QRect(20, 90, 171, 17));
        tabWidget->addTab(tab, QString());

        horizontalLayout_2->addWidget(tabWidget);

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
        QObject::connect(scotomaEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onScotomaEnabled(bool)));
        QObject::connect(scotomaRadius, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onScotomaRadiusChanged(int)));
        QObject::connect(calibrationHoriz, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationHorizChanged(int)));
        QObject::connect(calibrationVert, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationVertChanged(int)));
        QObject::connect(prosthesisEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onProsthesisEnabled(bool)));
        QObject::connect(prosthesisSize, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisSizeChanged(int)));
        QObject::connect(halfFieldBlockNone, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onHalfFieldBlockNone(bool)));
        QObject::connect(halfFieldBlockLeft, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onHalfFieldBlockLeft(bool)));
        QObject::connect(halfFieldBlockRight, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onHalfFieldBlockRight(bool)));
        QObject::connect(prosthesisGrayLevel, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisGrayLevelChanged(int)));
        QObject::connect(gradientEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onGradientEnabled(bool)));
        QObject::connect(gradientInside, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onGradientInsideChanged(int)));
        QObject::connect(gradientOutside, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onGradientOutsideChanged(int)));
        QObject::connect(imageComboBox, SIGNAL(currentIndexChanged(QString)), EyeTrackingSuiteClass, SLOT(onImageComboBoxChanged(QString)));
        QObject::connect(prosthesisPixelSize, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisPixelSizeChanged(int)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(EyeTrackingSuiteClass);
    } // setupUi

    void retranslateUi(QMainWindow *EyeTrackingSuiteClass)
    {
        EyeTrackingSuiteClass->setWindowTitle(QApplication::translate("EyeTrackingSuiteClass", "Eye Tracking Suite", nullptr));
        actionSwitch_Application->setText(QApplication::translate("EyeTrackingSuiteClass", "Switch Application", nullptr));
        mainDrawArea->setText(QApplication::translate("EyeTrackingSuiteClass", "TextLabel", nullptr));
        groupBox->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Tobii", nullptr));
        tobiiReconnect->setText(QApplication::translate("EyeTrackingSuiteClass", "Reconnect", nullptr));
        tobiiLabel->setText(QApplication::translate("EyeTrackingSuiteClass", "Disconnected", nullptr));
        groupBox_4->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Calibration", nullptr));
        label_4->setText(QApplication::translate("EyeTrackingSuiteClass", "Horizontal Offset:", nullptr));
        label_5->setText(QApplication::translate("EyeTrackingSuiteClass", "Vertical Offset:", nullptr));
        groupBox_6->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Image", nullptr));
        imageComboBox->setItemText(0, QApplication::translate("EyeTrackingSuiteClass", "Reading Test", nullptr));
        imageComboBox->setItemText(1, QApplication::translate("EyeTrackingSuiteClass", "Oregon Sunset", nullptr));
        imageComboBox->setItemText(2, QApplication::translate("EyeTrackingSuiteClass", "Desert Mustang", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("EyeTrackingSuiteClass", "General", nullptr));
        groupBox_2->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Scotoma", nullptr));
        scotomaEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Scotoma", nullptr));
        label->setText(QApplication::translate("EyeTrackingSuiteClass", "Size:", nullptr));
        groupBox_3->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Prosthesis", nullptr));
        prosthesisEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Prosthesis", nullptr));
        label_2->setText(QApplication::translate("EyeTrackingSuiteClass", "Size (%):", nullptr));
        label_3->setText(QApplication::translate("EyeTrackingSuiteClass", "Gray Levels:", nullptr));
        label_8->setText(QApplication::translate("EyeTrackingSuiteClass", "Pixel Size:", nullptr));
        groupBox_7->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Gradient", nullptr));
        gradientEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Fade Scotoma at Edges", nullptr));
        label_6->setText(QApplication::translate("EyeTrackingSuiteClass", "Fade Inside:", nullptr));
        label_7->setText(QApplication::translate("EyeTrackingSuiteClass", "Fade Outside:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("EyeTrackingSuiteClass", "Central Vision", nullptr));
        groupBox_5->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Homonymous Hemianopsia", nullptr));
        halfFieldBlockNone->setText(QApplication::translate("EyeTrackingSuiteClass", "Do not block visual fields", nullptr));
        halfFieldBlockLeft->setText(QApplication::translate("EyeTrackingSuiteClass", "Block left visual field", nullptr));
        halfFieldBlockRight->setText(QApplication::translate("EyeTrackingSuiteClass", "Block right visual field", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EyeTrackingSuiteClass", "Visual Field", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EyeTrackingSuiteClass: public Ui_EyeTrackingSuiteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYETRACKINGSUITE_H
