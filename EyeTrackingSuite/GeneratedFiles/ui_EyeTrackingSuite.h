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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "etsdrawarea.h"

QT_BEGIN_NAMESPACE

class Ui_EyeTrackingSuiteClass
{
public:
    QAction *actionSwitch_Application;
    QAction *actionAbout;
    QAction *actionFull_Screen;
    QAction *actionShow_Controls;
    QAction *actionAdd_Space_At_Bottom;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    ETSDrawArea *mainDrawArea;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *groupBox_6;
    QComboBox *imageComboBox;
    QGroupBox *groupBox_9;
    QLabel *label_9;
    QSpinBox *physViewDist;
    QSpinBox *physDPICalib;
    QLabel *label_13;
    QPushButton *physDPICalibHelp;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QSlider *calibrationHoriz;
    QSlider *calibrationVert;
    QLabel *label_5;
    QGroupBox *groupBox;
    QPushButton *tobiiReconnect;
    QLabel *tobiiLabel;
    QGroupBox *groupBox_8;
    QLabel *label;
    QComboBox *visFont;
    QLabel *label_6;
    QSpinBox *visTextNumber;
    QCheckBox *visTextDifferent;
    QCheckBox *visTextCapital;
    QPushButton *visFontBold;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QGroupBox *groupBox_7;
    QCheckBox *gradientEnabled;
    QSlider *gradientOutside;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QCheckBox *scotomaEnabled;
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
    QWidget *spaceAtBottom;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuWindow;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EyeTrackingSuiteClass)
    {
        if (EyeTrackingSuiteClass->objectName().isEmpty())
            EyeTrackingSuiteClass->setObjectName(QStringLiteral("EyeTrackingSuiteClass"));
        EyeTrackingSuiteClass->resize(1156, 850);
        actionSwitch_Application = new QAction(EyeTrackingSuiteClass);
        actionSwitch_Application->setObjectName(QStringLiteral("actionSwitch_Application"));
        actionAbout = new QAction(EyeTrackingSuiteClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionFull_Screen = new QAction(EyeTrackingSuiteClass);
        actionFull_Screen->setObjectName(QStringLiteral("actionFull_Screen"));
        actionFull_Screen->setCheckable(true);
        actionShow_Controls = new QAction(EyeTrackingSuiteClass);
        actionShow_Controls->setObjectName(QStringLiteral("actionShow_Controls"));
        actionShow_Controls->setCheckable(true);
        actionShow_Controls->setChecked(true);
        actionAdd_Space_At_Bottom = new QAction(EyeTrackingSuiteClass);
        actionAdd_Space_At_Bottom->setObjectName(QStringLiteral("actionAdd_Space_At_Bottom"));
        actionAdd_Space_At_Bottom->setCheckable(true);
        centralWidget = new QWidget(EyeTrackingSuiteClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainDrawArea = new ETSDrawArea(centralWidget);
        mainDrawArea->setObjectName(QStringLiteral("mainDrawArea"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainDrawArea->sizePolicy().hasHeightForWidth());
        mainDrawArea->setSizePolicy(sizePolicy);
        mainDrawArea->setAutoFillBackground(false);
        mainDrawArea->setScaledContents(false);
        mainDrawArea->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mainDrawArea);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(260, 0));
        tabWidget->setMaximumSize(QSize(260, 16777215));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QStringLiteral("background-color:none"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 259, 750));
        groupBox_6 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 420, 211, 71));
        imageComboBox = new QComboBox(groupBox_6);
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->setObjectName(QStringLiteral("imageComboBox"));
        imageComboBox->setGeometry(QRect(20, 30, 171, 22));
        groupBox_9 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 300, 211, 101));
        label_9 = new QLabel(groupBox_9);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(13, 30, 151, 21));
        physViewDist = new QSpinBox(groupBox_9);
        physViewDist->setObjectName(QStringLiteral("physViewDist"));
        physViewDist->setGeometry(QRect(157, 30, 42, 22));
        physViewDist->setMinimum(10);
        physViewDist->setMaximum(60);
        physViewDist->setValue(24);
        physDPICalib = new QSpinBox(groupBox_9);
        physDPICalib->setObjectName(QStringLiteral("physDPICalib"));
        physDPICalib->setGeometry(QRect(123, 60, 42, 22));
        physDPICalib->setMinimum(10);
        physDPICalib->setMaximum(99);
        physDPICalib->setValue(25);
        label_13 = new QLabel(groupBox_9);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(13, 60, 111, 21));
        physDPICalibHelp = new QPushButton(groupBox_9);
        physDPICalibHelp->setObjectName(QStringLiteral("physDPICalibHelp"));
        physDPICalibHelp->setGeometry(QRect(170, 60, 31, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        physDPICalibHelp->setFont(font);
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 120, 211, 161));
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
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 211, 81));
        tobiiReconnect = new QPushButton(groupBox);
        tobiiReconnect->setObjectName(QStringLiteral("tobiiReconnect"));
        tobiiReconnect->setGeometry(QRect(120, 30, 81, 31));
        tobiiLabel = new QLabel(groupBox);
        tobiiLabel->setObjectName(QStringLiteral("tobiiLabel"));
        tobiiLabel->setGeometry(QRect(10, 30, 101, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        tobiiLabel->setFont(font1);
        tobiiLabel->setAlignment(Qt::AlignCenter);
        tobiiLabel->raise();
        tobiiReconnect->raise();
        groupBox_8 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 510, 211, 201));
        label = new QLabel(groupBox_8);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 31, 21));
        visFont = new QComboBox(groupBox_8);
        visFont->addItem(QString());
        visFont->addItem(QString());
        visFont->addItem(QString());
        visFont->addItem(QString());
        visFont->addItem(QString());
        visFont->setObjectName(QStringLiteral("visFont"));
        visFont->setGeometry(QRect(20, 60, 151, 22));
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 100, 111, 21));
        visTextNumber = new QSpinBox(groupBox_8);
        visTextNumber->setObjectName(QStringLiteral("visTextNumber"));
        visTextNumber->setGeometry(QRect(140, 100, 42, 22));
        visTextNumber->setMinimum(1);
        visTextNumber->setMaximum(10);
        visTextNumber->setValue(1);
        visTextDifferent = new QCheckBox(groupBox_8);
        visTextDifferent->setObjectName(QStringLiteral("visTextDifferent"));
        visTextDifferent->setGeometry(QRect(20, 134, 171, 17));
        visTextDifferent->setChecked(false);
        visTextCapital = new QCheckBox(groupBox_8);
        visTextCapital->setObjectName(QStringLiteral("visTextCapital"));
        visTextCapital->setGeometry(QRect(20, 160, 171, 17));
        visTextCapital->setChecked(true);
        visFontBold = new QPushButton(groupBox_8);
        visFontBold->setObjectName(QStringLiteral("visFontBold"));
        visFontBold->setGeometry(QRect(174, 60, 21, 21));
        visFontBold->setFont(font);
        visFontBold->setCheckable(true);
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout = new QVBoxLayout(tab_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(tab_4);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        sizePolicy2.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy2);
        scrollArea_2->setStyleSheet(QStringLiteral("background-color:none"));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(false);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 242, 639));
        groupBox_7 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 390, 211, 101));
        gradientEnabled = new QCheckBox(groupBox_7);
        gradientEnabled->setObjectName(QStringLiteral("gradientEnabled"));
        gradientEnabled->setGeometry(QRect(20, 30, 181, 17));
        gradientOutside = new QSlider(groupBox_7);
        gradientOutside->setObjectName(QStringLiteral("gradientOutside"));
        gradientOutside->setGeometry(QRect(60, 60, 131, 22));
        gradientOutside->setMinimum(0);
        gradientOutside->setMaximum(95);
        gradientOutside->setValue(60);
        gradientOutside->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 60, 31, 21));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 211, 101));
        scotomaEnabled = new QCheckBox(groupBox_2);
        scotomaEnabled->setObjectName(QStringLiteral("scotomaEnabled"));
        scotomaEnabled->setGeometry(QRect(20, 30, 171, 17));
        scotomaEnabled->setChecked(false);
        scotomaSizeDegrees = new QSpinBox(groupBox_2);
        scotomaSizeDegrees->setObjectName(QStringLiteral("scotomaSizeDegrees"));
        scotomaSizeDegrees->setGeometry(QRect(120, 60, 42, 22));
        scotomaSizeDegrees->setMinimum(1);
        scotomaSizeDegrees->setMaximum(20);
        scotomaSizeDegrees->setValue(10);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 60, 111, 21));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 140, 211, 231));
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
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(scrollArea_2);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout_3->addLayout(horizontalLayout);

        spaceAtBottom = new QWidget(centralWidget);
        spaceAtBottom->setObjectName(QStringLiteral("spaceAtBottom"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spaceAtBottom->sizePolicy().hasHeightForWidth());
        spaceAtBottom->setSizePolicy(sizePolicy3);
        spaceAtBottom->setMinimumSize(QSize(0, 64));

        verticalLayout_3->addWidget(spaceAtBottom);

        EyeTrackingSuiteClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EyeTrackingSuiteClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1156, 21));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        EyeTrackingSuiteClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(EyeTrackingSuiteClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EyeTrackingSuiteClass->setStatusBar(statusBar);

        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);
        menuWindow->addAction(actionFull_Screen);
        menuWindow->addSeparator();
        menuWindow->addAction(actionShow_Controls);
        menuWindow->addAction(actionAdd_Space_At_Bottom);

        retranslateUi(EyeTrackingSuiteClass);
        QObject::connect(actionAbout, SIGNAL(triggered()), EyeTrackingSuiteClass, SLOT(onActionAbout()));
        QObject::connect(actionFull_Screen, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onActionFullscreen(bool)));
        QObject::connect(actionShow_Controls, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onActionShowControls(bool)));
        QObject::connect(actionAdd_Space_At_Bottom, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onActionSpaceBottom(bool)));
        QObject::connect(prosthesisEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onProsthesisEnabled(bool)));
        QObject::connect(tobiiReconnect, SIGNAL(clicked()), EyeTrackingSuiteClass, SLOT(onTobiiReconnectClicked()));
        QObject::connect(scotomaEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onScotomaEnabled(bool)));
        QObject::connect(gradientEnabled, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onGradientEnabled(bool)));
        QObject::connect(gradientOutside, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onGradientOutsideChanged(int)));
        QObject::connect(prosthesisSize, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisSizeChanged(int)));
        QObject::connect(imageComboBox, SIGNAL(currentIndexChanged(QString)), EyeTrackingSuiteClass, SLOT(onImageComboBoxChanged(QString)));
        QObject::connect(physViewDist, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onPhysViewDistChanged(int)));
        QObject::connect(calibrationHoriz, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationHorizChanged(int)));
        QObject::connect(scotomaSizeDegrees, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onScotomaSizeDegreesChanged(int)));
        QObject::connect(prosthesisPixelSize, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisPixelSizeChanged(int)));
        QObject::connect(prosthesisGrayLevel, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onProsthesisGrayLevelChanged(int)));
        QObject::connect(calibrationVert, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onCalibrationVertChanged(int)));
        QObject::connect(visTextCapital, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onVisTextCapitalChanged(bool)));
        QObject::connect(visFont, SIGNAL(currentIndexChanged(int)), EyeTrackingSuiteClass, SLOT(onVisFontChanged(int)));
        QObject::connect(physDPICalib, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onPhysDPICalibChanged(int)));
        QObject::connect(visTextNumber, SIGNAL(valueChanged(int)), EyeTrackingSuiteClass, SLOT(onVisTextNumberChanged(int)));
        QObject::connect(physDPICalibHelp, SIGNAL(clicked()), EyeTrackingSuiteClass, SLOT(onPhysDPICalibHelp()));
        QObject::connect(visTextDifferent, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onVisTextDifferentChanged(bool)));
        QObject::connect(prosthesisFullWhite, SIGNAL(sliderReleased()), EyeTrackingSuiteClass, SLOT(onProsthesisFullWhiteChanged()));
        QObject::connect(visFontBold, SIGNAL(toggled(bool)), EyeTrackingSuiteClass, SLOT(onVisFontBoldChanged(bool)));
        QObject::connect(prosthesisFullBlack, SIGNAL(sliderReleased()), EyeTrackingSuiteClass, SLOT(onProsthesisFullBlackChanged()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EyeTrackingSuiteClass);
    } // setupUi

    void retranslateUi(QMainWindow *EyeTrackingSuiteClass)
    {
        EyeTrackingSuiteClass->setWindowTitle(QApplication::translate("EyeTrackingSuiteClass", "Eye Tracking Suite", nullptr));
        actionSwitch_Application->setText(QApplication::translate("EyeTrackingSuiteClass", "Switch Application", nullptr));
        actionAbout->setText(QApplication::translate("EyeTrackingSuiteClass", "About", nullptr));
        actionFull_Screen->setText(QApplication::translate("EyeTrackingSuiteClass", "Full Screen", nullptr));
        actionShow_Controls->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Controls", nullptr));
        actionAdd_Space_At_Bottom->setText(QApplication::translate("EyeTrackingSuiteClass", "Add Space At Bottom", nullptr));
        mainDrawArea->setText(QApplication::translate("EyeTrackingSuiteClass", "TextLabel", nullptr));
        groupBox_6->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Image", nullptr));
        imageComboBox->setItemText(0, QApplication::translate("EyeTrackingSuiteClass", "Vision Chart", nullptr));
        imageComboBox->setItemText(1, QApplication::translate("EyeTrackingSuiteClass", "One Square Inch", nullptr));

        groupBox_9->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Physical Setup", nullptr));
        label_9->setText(QApplication::translate("EyeTrackingSuiteClass", "Eye-To-Screen Distance (in):", nullptr));
        label_13->setText(QApplication::translate("EyeTrackingSuiteClass", "Size Calibration (mm):", nullptr));
        physDPICalibHelp->setText(QApplication::translate("EyeTrackingSuiteClass", "?", nullptr));
        groupBox_4->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Calibration", nullptr));
        label_4->setText(QApplication::translate("EyeTrackingSuiteClass", "Horizontal Offset:", nullptr));
        label_5->setText(QApplication::translate("EyeTrackingSuiteClass", "Vertical Offset:", nullptr));
        groupBox->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Tobii", nullptr));
        tobiiReconnect->setText(QApplication::translate("EyeTrackingSuiteClass", "Reconnect", nullptr));
        tobiiLabel->setText(QApplication::translate("EyeTrackingSuiteClass", "Disconnected", nullptr));
        groupBox_8->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Vision Chart", nullptr));
        label->setText(QApplication::translate("EyeTrackingSuiteClass", "Font:", nullptr));
        visFont->setItemText(0, QApplication::translate("EyeTrackingSuiteClass", "Courier New", nullptr));
        visFont->setItemText(1, QApplication::translate("EyeTrackingSuiteClass", "Arial Black", nullptr));
        visFont->setItemText(2, QApplication::translate("EyeTrackingSuiteClass", "Times New Roman", nullptr));
        visFont->setItemText(3, QApplication::translate("EyeTrackingSuiteClass", "Lucida Sans Unicode", nullptr));
        visFont->setItemText(4, QApplication::translate("EyeTrackingSuiteClass", "Verdana", nullptr));

        label_6->setText(QApplication::translate("EyeTrackingSuiteClass", "Sample Text Number:", nullptr));
        visTextDifferent->setText(QApplication::translate("EyeTrackingSuiteClass", "Different Text For Each Line", nullptr));
        visTextCapital->setText(QApplication::translate("EyeTrackingSuiteClass", "Always Use Capital Letters", nullptr));
        visFontBold->setText(QApplication::translate("EyeTrackingSuiteClass", "B", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("EyeTrackingSuiteClass", "General", nullptr));
        groupBox_7->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Gradient", nullptr));
        gradientEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Fade Scotoma at Edges", nullptr));
        label_7->setText(QApplication::translate("EyeTrackingSuiteClass", "Fade:", nullptr));
        groupBox_2->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Scotoma", nullptr));
        scotomaEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Scotoma", nullptr));
        label_10->setText(QApplication::translate("EyeTrackingSuiteClass", "Size in Degrees:", nullptr));
        groupBox_3->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Prosthesis", nullptr));
        prosthesisEnabled->setText(QApplication::translate("EyeTrackingSuiteClass", "Show Prosthesis", nullptr));
        label_2->setText(QApplication::translate("EyeTrackingSuiteClass", "Size (%):", nullptr));
        label_3->setText(QApplication::translate("EyeTrackingSuiteClass", "Gray Levels:", nullptr));
        label_8->setText(QApplication::translate("EyeTrackingSuiteClass", "Pixel Size (\316\274m):", nullptr));
        label_11->setText(QApplication::translate("EyeTrackingSuiteClass", "Full Black:", nullptr));
        label_12->setText(QApplication::translate("EyeTrackingSuiteClass", "Full White:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("EyeTrackingSuiteClass", "Central Vision", nullptr));
        menuHelp->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Help", nullptr));
        menuWindow->setTitle(QApplication::translate("EyeTrackingSuiteClass", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EyeTrackingSuiteClass: public Ui_EyeTrackingSuiteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYETRACKINGSUITE_H
