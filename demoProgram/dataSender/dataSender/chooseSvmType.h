#pragma once
#ifndef CHOOSESVMTYPE_H
#define CHOOSESVMTYPE_H

using namespace std;

#include <QtWidgets/QMainWindow>
#include "ui_chooseSvmType.h"

class chooseSvmTypeWindowClass : public QWidget
{
	Q_OBJECT

public:
	chooseSvmTypeWindowClass(QWidget *parent = 0);
	~chooseSvmTypeWindowClass();

public:
	static int svmType; // 1:one-class 0:two-class

signals:
	void sendAData(QString);

public slots: // slot functions for clicking the buttons
	void on_oneClass_clicked();

private:
	static Ui::Form ui;
};

#endif // CHOOSESVMTYPE_H
