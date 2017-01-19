/********************************************************************************
** Form generated from reading UI file 'driverstatuscheck.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVERSTATUSCHECK_H
#define UI_DRIVERSTATUSCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_driverStatusCheckClass
{
public:
    QWidget *centralWidget;
    QPushButton *oneClass;
    QPushButton *twoClass;
    QPushButton *titleText;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *driverStatusCheckClass)
    {
        if (driverStatusCheckClass->objectName().isEmpty())
            driverStatusCheckClass->setObjectName(QStringLiteral("driverStatusCheckClass"));
        driverStatusCheckClass->resize(448, 194);
        centralWidget = new QWidget(driverStatusCheckClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        oneClass = new QPushButton(centralWidget);
        oneClass->setObjectName(QStringLiteral("oneClass"));
        oneClass->setGeometry(QRect(50, 80, 161, 61));
        QFont font;
        font.setFamily(QStringLiteral("Century Gothic"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        oneClass->setFont(font);
        twoClass = new QPushButton(centralWidget);
        twoClass->setObjectName(QStringLiteral("twoClass"));
        twoClass->setGeometry(QRect(240, 80, 161, 61));
        twoClass->setFont(font);
        titleText = new QPushButton(centralWidget);
        titleText->setObjectName(QStringLiteral("titleText"));
        titleText->setGeometry(QRect(140, 10, 161, 41));
        titleText->setFont(font);
        titleText->setStyleSheet(QStringLiteral("background: transparent;"));
        titleText->setFlat(true);
        driverStatusCheckClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(driverStatusCheckClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 448, 23));
        driverStatusCheckClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(driverStatusCheckClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        driverStatusCheckClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(driverStatusCheckClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        driverStatusCheckClass->setStatusBar(statusBar);

        retranslateUi(driverStatusCheckClass);

        QMetaObject::connectSlotsByName(driverStatusCheckClass);
    } // setupUi

    void retranslateUi(QMainWindow *driverStatusCheckClass)
    {
        driverStatusCheckClass->setWindowTitle(QApplication::translate("driverStatusCheckClass", "driverStatusCheck", 0));
        oneClass->setText(QApplication::translate("driverStatusCheckClass", "one-class SVM", 0));
        twoClass->setText(QApplication::translate("driverStatusCheckClass", "two-class SVM", 0));
        titleText->setText(QApplication::translate("driverStatusCheckClass", "choose SVM type", 0));
    } // retranslateUi

};

namespace Ui {
    class driverStatusCheckClass: public Ui_driverStatusCheckClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVERSTATUSCHECK_H
