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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "etsdrawarea.h"

QT_BEGIN_NAMESPACE

class Ui_EyeTrackingSuiteClass
{
public:
    QAction *actionSwitch_Application;
    QAction *actionAbout;
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
    QGroupBox *groupBox_9;
    QLabel *label_9;
    QSpinBox *physViewDist;
    QWidget *tab_4;
    QGroupBox *groupBox_2;
    QSlider *scotomaRadius;
    QCheckBox *scotomaEnabled;
    QLabel *label;
    QCheckBox *scotomaUseDegrees;
    QSpinBox *scotomaSizeDegrees;
    QLabel *label_10;
    QGroupBox *groupBox_3;
    QCheckBox *prosthesisEnabled;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *prosthesisGrayLevel;
    QSpinBox *prosthesisPixelSize;
    QLabel *label_8;
    QSpinBox *prosthesisSize;
    QLabel *label_11;
    QLabel *label_12;
    QSlider *prosthesisFullBlack;
    QSlider *prosthesisFullWhite;
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
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EyeTrackingSuiteClass)
    {
        if (EyeTrackingSuiteClass->objectName().isEmpty())
            EyeTrackingSuiteClass->setObjectName(QStringLiteral("EyeTrackingSuiteClass"));
        EyeTrackingSuiteClass->resize(914, 724);
        actionSwitch_Application = new QAction(EyeTrackingSuiteClass);
        actionSwitch_Application->setObjectName(QStringLiteral("actionSwitch_Application"));
        actionAbout = new QAction(EyeTrackingSuiteClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
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
        groupBox_6->setGeometry(QRect(20, 390, 211, 71));
        imageComboBox = new QComboBox(groupBox_6);
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->setObjectName(QStringLiteral("imageComboBox"));
        imageComboBox->setGeometry(QRect(20, 30, 171, 22));
        groupBox_9 = new QGroupBox(tab_3);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(20, 300, 211, 71));
        label_9 = new QLabel(groupBox_9);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(13, 30, 151, 21));
        physViewDist = new QSpinBox(groupBox_9);
        physViewDist->setObjectName(QStringLiteral("physViewDist"));
        physViewDist->setGeometry(QRect(157, 30, 42, 22));
        physViewDist->setMinimum(1);
        physViewDist->setMaximum(5);
        physViewDist->setValue(2);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 20, 211, 161));
        scotomaRadius = new QSlider(groupBox_2);
        scotomaRadius->setObjectName(QStringLiteral("scotomaRadius"));
        scotomaRadius->setGeometry(QRect(50, 90, 141, 22));
        scotomaRadius->setMinimum(10);
        scotomaRadius->setMaximum(300);
        scotomaRadius->setValue(50);
        scotomaRadius->setOrientation(Qt::Horizontal);
        scotomaEnabled = new QCheckBox(groupBox_2);
        scotomaEnabled->setObjectName(QStringLiteral("scotomaEnabled"));
        scotomaEnabled->setGeometry(QRect(20, 30, 171, 17));
        scotomaEnabled->setChecked(false);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 90, 31, 21));
        scotomaUseDegrees = new QCheckBox(groupBox_2);
        scotomaUseDegrees->setObjectName(QStringLiteral("scotomaUseDegrees"));
        scotomaUseDegrees->setGeometry(QRect(20, 60, 171, 17));
        scotomaUseDegrees->setChecked(false);
        scotomaSizeDegrees = new QSpinBox(groupBox_2);
        scotomaSizeDegrees->setObjectName(QStringLiteral("scotomaSizeDegrees"));
        scotomaSizeDegrees->setGeometry(QRect(120, 120, 42, 22));
        scotomaSizeDegrees->setMinimum(1);
        scotomaSizeDegrees->setMaximum(20);
        scotomaSizeDegrees->setValue(10);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 120, 111, 21));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 200, 211, 231));
        prosthesisEnabled = new QCheckBox(groupBox_3);
        prosthesisEnabled->setObjectName(QStringLiteral("prosthesisEnabled"));
        prosthesisEnabled->setGeometry(QRect(20, 30, 171, 17));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 51, 21));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 61, 21));
        prosthesisGrayLevel = new QSpinBox(groupBox_3);
        prosthesisGrayLevel->setObjectName(QStringLiteral("prosthesisGrayLevel"));
        prosthesisGrayLevel->setGeometry(QRect(100, 120, 50, 22));
        prosthesisGrayLevel->setMinimum(2);
        prosthesisGrayLevel->setMaximum(10);
        prosthesisGrayLevel->setValue(8);
        prosthesisPixelSize = new QSpinBox(groupBox_3);
        prosthesisPixelSize->setObjectName(QStringLiteral("prosthesisPixelSize"));
        prosthesisPixelSize->setGeometry(QRect(100, 90, 50, 22));
        prosthesisPixelSize->setMinimum(10);
        prosthesisPixelSize->setMaximum(999);
        prosthesisPixelSize->setValue(30);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 90, 81, 21));
        prosthesisSize = new QSpinBox(groupBox_3);
        prosthesisSize->setObjectName(QStringLiteral("prosthesisSize"));
        prosthesisSize->setGeometry(QRect(100, 60, 49, 22));
        prosthesisSize->setMinimum(5);
        prosthesisSize->setMaximum(95);
        prosthesisSize->setValue(50);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 160, 61, 21));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 190, 61, 21));
        prosthesisFullBlack = new QSlider(groupBox_3);
        prosthesisFullBlack->setObjectName(QStringLiteral("prosthesisFullBlack"));
        prosthesisFullBlack->setGeometry(QRect(80, 160, 111, 22));
        prosthesisFullBlack->setMinimum(0);
        prosthesisFullBlack->setMaximum(254);
        prosthesisFullBlack->setValue(0);
        prosthesisFullBlack->setSliderPosition(0);
        prosthesisFullBlack->setOrientation(Qt::Horizontal);
        prosthesisFullWhite = new QSlider(groupBox_3);
        prosthesisFullWhite->setObjectName(QStringLiteral("prosthesisFullWhite"));
        prosthesisFullWhite->setGeometry(QRect(80, 190, 111, 22));
        prosthesisFullWhite->setMinimum(1);
        prosthesisFullWhite->setMaximum(255);
        prosthesisFullWhite->setValue(255);
        prosthesisFullWhite->setSliderPosition(255);
        prosthesisFullWhite->setOrientation(Qt::Horizontal);
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 450, 211, 131));
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
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        EyeTrackingSuiteClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(EyeTrackingSuiteClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EyeTrackingSuiteClass->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);

        retranslateUi(EyeTrackingSuiteClass);
        QObject::connect(tobiiReconnect, SIGNAL(clicked()), EyeTrackingSuiteClass, SLOT(onTobiiReconnectClicked()));
        QObject::connect(scotomaEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onScotomaEnabled(bool)));
        QObject::connect(scotomaRadius, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onScotomaRadiusChanged(int)));
        QObject::connect(calibrationHoriz, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationHorizChanged(int)));
        QObject::connect(calibrationVert, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationVertChanged(int)));
        QObject::connect(prosthesisEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onProsthesisEnabled(bool)));
        QObject::connect(halfFieldBlockNone, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onHalfFieldBlockNone(bool)));
        QObject::connect(halfFieldBlockLeft, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onHalfFieldBlockLeft(bool)));
        QObject::connect(halfFieldBlockRight, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onHalfFieldBlockRight(bool)));
        QObject::connect(prosthesisGrayLevel, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisGrayLevelChanged(int)));
        QObject::connect(gradientEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onGradientEnabled(bool)));
        QObject::connect(gradientInside, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onGradientInsideChanged(int)));
        QObject::connect(gradientOutside, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onGradientOutsideChanged(int)));
        QObject::connect(imageComboBox, SIGNAL(currentIndexChanged(QString)), EyeTrackingSuiteClass, SLOT(onImageComboBoxChanged(QString)));
        QObject::connect(prosthesisPixelSize, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisPixelSizeChanged(int)));
        QObject::connect(prosthesisSize, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisSizeChanged(int)));
        QObject::connect(actionAbout, SIGNAL(triggered()), EyeTrackingSuiteClass, SLOT(onActionAbout()));
        QObject::connect(physViewDist, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onPhysViewDistChanged(int)));
        QObject::connect(scotomaUseDegrees, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onScotomaUseDegrees(bool)));
        QObject::connect(scotomaSizeDegrees, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onScotomaSizeDegreesChanged(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EyeTrackingSuiteClass);
    } // setupUi

    void retranslateUi(QMainWindow *EyeTrackingSuiteClass)
    {
        EyeTrackingSuiteClass->setWindowTitle(QApplication::translate("EyeTrackingSuiteClass", "Eye Tracking Suite", nullptr));
        actionSwitch_Application->setText(QApplication::translate("EyeTrackingSuiteClass", "Switch Application", nullptr));
        actionAbout->setText(QApplication::translate("EyeTrackingSuiteClass", "About", nullptr));
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

        groupBox_9->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Physical Setup", nullptr));
        label_9->setText(QApplication::translate("EyeTrackingSuiteClass", "Eye-To-Screen Distance (ft):", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("EyeTrackingSuiteClass", "General", nullptr));
        groupBox_2->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Scotoma", nullptr));
        scotomaEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Scotoma", nullptr));
        label->setText(QApplication::translate("EyeTrackingSuiteClass", "Size:", nullptr));
        scotomaUseDegrees->setText(QApplication::translate("EyeTrackingSuiteClass", "Set Scotoma Size In Degrees", nullptr));
        label_10->setText(QApplication::translate("EyeTrackingSuiteClass", "Size in Degrees:", nullptr));
        groupBox_3->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Prosthesis", nullptr));
        prosthesisEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Prosthesis", nullptr));
        label_2->setText(QApplication::translate("EyeTrackingSuiteClass", "Size (%):", nullptr));
        label_3->setText(QApplication::translate("EyeTrackingSuiteClass", "Gray Levels:", nullptr));
        label_8->setText(QApplication::translate("EyeTrackingSuiteClass", "Pixel Size (\316\274m):", nullptr));
        label_11->setText(QApplication::translate("EyeTrackingSuiteClass", "Full Black:", nullptr));
        label_12->setText(QApplication::translate("EyeTrackingSuiteClass", "Full White:", nullptr));
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
        menuHelp->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EyeTrackingSuiteClass: public Ui_EyeTrackingSuiteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYETRACKINGSUITE_H
