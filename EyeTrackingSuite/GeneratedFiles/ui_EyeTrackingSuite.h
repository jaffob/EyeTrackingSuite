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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
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
    QGroupBox *groupBox_2;
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
        groupBox->setGeometry(QRect(20, 20, 211, 161));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 200, 211, 161));
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

        QMetaObject::connectSlotsByName(EyeTrackingSuiteClass);
    } // setupUi

    void retranslateUi(QMainWindow *EyeTrackingSuiteClass)
    {
        EyeTrackingSuiteClass->setWindowTitle(QApplication::translate("EyeTrackingSuiteClass", "EyeTrackingSuite", nullptr));
        mainDrawArea->setText(QApplication::translate("EyeTrackingSuiteClass", "TextLabel", nullptr));
        groupBox->setTitle(QApplication::translate("EyeTrackingSuiteClass", "GroupBox", nullptr));
        groupBox_2->setTitle(QApplication::translate("EyeTrackingSuiteClass", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EyeTrackingSuiteClass: public Ui_EyeTrackingSuiteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYETRACKINGSUITE_H
