/********************************************************************************
** Form generated from reading UI file 'realTimeCheck.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMECHECK_H
#define UI_REALTIMECHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *data;
    QPushButton *startCheck;
    QPushButton *returnToMain;
    QPushButton *stopCheck;
    QLabel *pic;
    QLabel *restText;
    QLabel *waitText;
    QLabel *receiveDataText;
    QLabel *turnToStopText;
    QPushButton *background;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(573, 333);
        data = new QLabel(Form);
        data->setObjectName(QStringLiteral("data"));
        data->setGeometry(QRect(200, 60, 201, 241));
        QFont font;
        font.setFamily(QStringLiteral("Century Gothic"));
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        data->setFont(font);
        data->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        data->setWordWrap(true);
        startCheck = new QPushButton(Form);
        startCheck->setObjectName(QStringLiteral("startCheck"));
        startCheck->setGeometry(QRect(440, 30, 101, 91));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        startCheck->setFont(font1);
        returnToMain = new QPushButton(Form);
        returnToMain->setObjectName(QStringLiteral("returnToMain"));
        returnToMain->setGeometry(QRect(440, 270, 101, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        returnToMain->setFont(font2);
        stopCheck = new QPushButton(Form);
        stopCheck->setObjectName(QStringLiteral("stopCheck"));
        stopCheck->setGeometry(QRect(440, 150, 101, 91));
        stopCheck->setFont(font1);
        pic = new QLabel(Form);
        pic->setObjectName(QStringLiteral("pic"));
        pic->setGeometry(QRect(40, 100, 141, 141));
        restText = new QLabel(Form);
        restText->setObjectName(QStringLiteral("restText"));
        restText->setGeometry(QRect(170, 140, 161, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Century Gothic"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        restText->setFont(font3);
        waitText = new QLabel(Form);
        waitText->setObjectName(QStringLiteral("waitText"));
        waitText->setGeometry(QRect(100, 140, 301, 41));
        waitText->setFont(font3);
        receiveDataText = new QLabel(Form);
        receiveDataText->setObjectName(QStringLiteral("receiveDataText"));
        receiveDataText->setGeometry(QRect(50, 30, 301, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Century Gothic"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        receiveDataText->setFont(font4);
        turnToStopText = new QLabel(Form);
        turnToStopText->setObjectName(QStringLiteral("turnToStopText"));
        turnToStopText->setGeometry(QRect(100, 140, 321, 41));
        turnToStopText->setFont(font3);
        background = new QPushButton(Form);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(30, 30, 371, 281));
        background->setStyleSheet(QStringLiteral(""));
        background->setFlat(true);
        background->raise();
        data->raise();
        restText->raise();
        waitText->raise();
        turnToStopText->raise();
        startCheck->raise();
        returnToMain->raise();
        stopCheck->raise();
        receiveDataText->raise();
        pic->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        data->setText(QString());
        startCheck->setText(QApplication::translate("Form", "\345\274\200\345\247\213\347\233\221\346\265\213", 0));
        returnToMain->setText(QApplication::translate("Form", "\351\200\200\345\207\272", 0));
        stopCheck->setText(QApplication::translate("Form", "\345\201\234\346\255\242\346\216\245\346\224\266", 0));
        pic->setText(QString());
        restText->setText(QApplication::translate("Form", "resting...", 0));
        waitText->setText(QApplication::translate("Form", "waiting for request...", 0));
        receiveDataText->setText(QApplication::translate("Form", "receiving data...", 0));
        turnToStopText->setText(QApplication::translate("Form", "stop receiving data now!", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMECHECK_H
