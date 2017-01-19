/********************************************************************************
** Form generated from reading UI file 'datasender.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASENDER_H
#define UI_DATASENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataSenderClass
{
public:
    QWidget *centralWidget;
    QPushButton *sub5;
    QPushButton *sub6;
    QPushButton *sub8;
    QPushButton *sub1;
    QPushButton *sub2;
    QPushButton *sub3;
    QPushButton *sub4;
    QPushButton *sub7;
    QPushButton *startSend;
    QPushButton *stopSend;
    QPushButton *exit;
    QPushButton *titleText;
    QLabel *sendText;
    QLabel *restText;
    QPushButton *background;
    QPushButton *twoClass;
    QPushButton *oneClass;
    QPushButton *svmText;
    QPushButton *train;
    QLabel *trainText;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dataSenderClass)
    {
        if (dataSenderClass->objectName().isEmpty())
            dataSenderClass->setObjectName(QStringLiteral("dataSenderClass"));
        dataSenderClass->resize(585, 312);
        centralWidget = new QWidget(dataSenderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sub5 = new QPushButton(centralWidget);
        sub5->setObjectName(QStringLiteral("sub5"));
        sub5->setGeometry(QRect(30, 120, 41, 41));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        sub5->setFont(font);
        sub6 = new QPushButton(centralWidget);
        sub6->setObjectName(QStringLiteral("sub6"));
        sub6->setGeometry(QRect(80, 120, 41, 41));
        sub6->setFont(font);
        sub8 = new QPushButton(centralWidget);
        sub8->setObjectName(QStringLiteral("sub8"));
        sub8->setGeometry(QRect(180, 120, 41, 41));
        sub8->setFont(font);
        sub1 = new QPushButton(centralWidget);
        sub1->setObjectName(QStringLiteral("sub1"));
        sub1->setGeometry(QRect(30, 60, 41, 41));
        sub1->setFont(font);
        sub2 = new QPushButton(centralWidget);
        sub2->setObjectName(QStringLiteral("sub2"));
        sub2->setGeometry(QRect(80, 60, 41, 41));
        sub2->setFont(font);
        sub3 = new QPushButton(centralWidget);
        sub3->setObjectName(QStringLiteral("sub3"));
        sub3->setGeometry(QRect(130, 60, 41, 41));
        sub3->setFont(font);
        sub4 = new QPushButton(centralWidget);
        sub4->setObjectName(QStringLiteral("sub4"));
        sub4->setGeometry(QRect(180, 60, 41, 41));
        sub4->setFont(font);
        sub7 = new QPushButton(centralWidget);
        sub7->setObjectName(QStringLiteral("sub7"));
        sub7->setGeometry(QRect(130, 120, 41, 41));
        sub7->setFont(font);
        startSend = new QPushButton(centralWidget);
        startSend->setObjectName(QStringLiteral("startSend"));
        startSend->setGeometry(QRect(470, 20, 91, 81));
        startSend->setFont(font);
        stopSend = new QPushButton(centralWidget);
        stopSend->setObjectName(QStringLiteral("stopSend"));
        stopSend->setGeometry(QRect(470, 120, 91, 81));
        stopSend->setFont(font);
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(470, 220, 91, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        exit->setFont(font1);
        titleText = new QPushButton(centralWidget);
        titleText->setObjectName(QStringLiteral("titleText"));
        titleText->setGeometry(QRect(40, -10, 171, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Century Gothic"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        titleText->setFont(font2);
        titleText->setStyleSheet(QStringLiteral("background: transparent;"));
        titleText->setFlat(true);
        sendText = new QLabel(centralWidget);
        sendText->setObjectName(QStringLiteral("sendText"));
        sendText->setGeometry(QRect(120, 220, 131, 21));
        sendText->setFont(font2);
        restText = new QLabel(centralWidget);
        restText->setObjectName(QStringLiteral("restText"));
        restText->setGeometry(QRect(140, 220, 131, 21));
        restText->setFont(font2);
        background = new QPushButton(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(30, 190, 291, 81));
        background->setStyleSheet(QStringLiteral(""));
        background->setFlat(true);
        twoClass = new QPushButton(centralWidget);
        twoClass->setObjectName(QStringLiteral("twoClass"));
        twoClass->setGeometry(QRect(260, 120, 171, 41));
        twoClass->setFont(font2);
        oneClass = new QPushButton(centralWidget);
        oneClass->setObjectName(QStringLiteral("oneClass"));
        oneClass->setGeometry(QRect(260, 60, 171, 41));
        oneClass->setFont(font2);
        svmText = new QPushButton(centralWidget);
        svmText->setObjectName(QStringLiteral("svmText"));
        svmText->setGeometry(QRect(260, 10, 161, 41));
        svmText->setFont(font2);
        svmText->setStyleSheet(QStringLiteral("background: transparent;"));
        svmText->setFlat(true);
        train = new QPushButton(centralWidget);
        train->setObjectName(QStringLiteral("train"));
        train->setGeometry(QRect(340, 190, 91, 81));
        train->setFont(font);
        trainText = new QLabel(centralWidget);
        trainText->setObjectName(QStringLiteral("trainText"));
        trainText->setGeometry(QRect(140, 220, 131, 21));
        trainText->setFont(font2);
        dataSenderClass->setCentralWidget(centralWidget);
        background->raise();
        sub5->raise();
        sub6->raise();
        sub8->raise();
        sub1->raise();
        sub2->raise();
        sub3->raise();
        sub4->raise();
        sub7->raise();
        startSend->raise();
        stopSend->raise();
        exit->raise();
        titleText->raise();
        sendText->raise();
        restText->raise();
        twoClass->raise();
        oneClass->raise();
        svmText->raise();
        train->raise();
        trainText->raise();
        menuBar = new QMenuBar(dataSenderClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 585, 23));
        dataSenderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dataSenderClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dataSenderClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dataSenderClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dataSenderClass->setStatusBar(statusBar);

        retranslateUi(dataSenderClass);

        QMetaObject::connectSlotsByName(dataSenderClass);
    } // setupUi

    void retranslateUi(QMainWindow *dataSenderClass)
    {
        dataSenderClass->setWindowTitle(QApplication::translate("dataSenderClass", "dataSender", 0));
        sub5->setText(QApplication::translate("dataSenderClass", "5", 0));
        sub6->setText(QApplication::translate("dataSenderClass", "6", 0));
        sub8->setText(QApplication::translate("dataSenderClass", "8", 0));
        sub1->setText(QApplication::translate("dataSenderClass", "1", 0));
        sub2->setText(QApplication::translate("dataSenderClass", "2", 0));
        sub3->setText(QApplication::translate("dataSenderClass", "3", 0));
        sub4->setText(QApplication::translate("dataSenderClass", "4", 0));
        sub7->setText(QApplication::translate("dataSenderClass", "7", 0));
        startSend->setText(QApplication::translate("dataSenderClass", "\345\217\221\351\200\201\357\274\201", 0));
        stopSend->setText(QApplication::translate("dataSenderClass", "\345\201\234\346\255\242\357\274\201", 0));
        exit->setText(QApplication::translate("dataSenderClass", "\351\200\200\345\207\272", 0));
        titleText->setText(QApplication::translate("dataSenderClass", "choose subject", 0));
        sendText->setText(QApplication::translate("dataSenderClass", "Sending data...", 0));
        restText->setText(QApplication::translate("dataSenderClass", "resting...", 0));
        background->setText(QString());
        twoClass->setText(QApplication::translate("dataSenderClass", "two-class SVM", 0));
        oneClass->setText(QApplication::translate("dataSenderClass", "one-class SVM", 0));
        svmText->setText(QApplication::translate("dataSenderClass", "choose SVM type", 0));
        train->setText(QApplication::translate("dataSenderClass", "\350\256\255\347\273\203\357\274\201", 0));
        trainText->setText(QApplication::translate("dataSenderClass", "training...", 0));
    } // retranslateUi

};

namespace Ui {
    class dataSenderClass: public Ui_dataSenderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASENDER_H
