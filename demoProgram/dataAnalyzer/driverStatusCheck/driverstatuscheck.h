#pragma once

#ifndef TESTQTSOCKET_H
#define TESTQTSOCKET_H

using namespace std;
#include "realTimeCheck.h"

#include <QtWidgets/QMainWindow>
#include "ui_driverStatusCheck.h"

#include <stdio.h>
#include <string>
#include <tchar.h>
#include <fstream>

const int MAX_DIMENSION = 100; // upper limit of dimension number ( in fact, it's 25 )

class driverStatusCheckWindowClass : public QMainWindow
{
	Q_OBJECT

public:
	driverStatusCheckWindowClass(QWidget *parent = 0);
	~driverStatusCheckWindowClass();

public slots: // slot functions for pushing buttons

	/* choose SVM type */
	void on_oneClass_clicked();
	void on_twoClass_clicked();

	//void on_exit_clicked(); // exit program

private:
	Ui::driverStatusCheckClass ui;

private: //private data
	realTimeCheckWindowClass * newWindow; // "Real Time Check" window
	int subNo; // the No. of the subject, the value should between 1 and 8
	bool SVMtype; // the type of SVM ( 1/TRUE: one-class-SVM; 0/FALSE: two-class-SVM )
	int dimension = 25; // the dimension of feature
	int trainNum = 3500; // number of train data is no more than 3500
	int testNum = 3500; // number of test data is no more than 3500
	string trainDataFile1; // for one-class-SVM & two-class-SVM
	string trainDataFile2; // for one-class-SVM & two-class-SVM
	string trainDataFile3; // for one-class-SVM & two-class-SVM
	string trainDataFile4; // for two-class only; with lable 0
	string trainLabelFile1 = "\.\\data\\trainlabel.txt"; // for one-class-SVM & two-class-SVM
	string trainLabelFile2 = "\.\\data\\trainlabel2.txt"; // for one-class-SVM & two-class-SVM
	string trainLabelFile3 = "\.\\data\\trainlabel3.txt"; // for one-class-SVM & two-class-SVM
	string trainLabelFile4 = "\.\\data\\trainlabel4.txt"; // for two-class only; lable 0
	list<point> point_list;

	/* default parameters */
	double nu = 0.50;
	double gamma = 1.00;
	double coef0 = 0.00;
	double degree = 3.00;

private: //private function

	/* function for one-class-SVM train */
	void generateFileName_oneClass(); // generate trainDataFile[1 - 3]
	void writeTrainLabel_oneClass(); // write in trainLabelFile[1 - 3]
	void setPara_oneClass(); // set parameters
	void readTrainData_oneClass(const char file[], const char file2[], const char file3[],
		const char file_lable[], const char file_lable2[], const char file_lable3[]); // read train data and train labels
	void run_oneClass(); // train data and save the model as "model.txt"

	/* function for two-class-SVM train */
	void generateFileName_twoClass(); // generate trainDataFile[1-4]
	void writeTrainLabel_twoClass(); // write trainLabelFile[1-4]
	void setPara_twoClass(); // set parameters
	void readTrainData_twoClass(const char file[], const char file2[], const char file3[], const char file4[],
		const char file_lable[], const char file_lable2[], const char file_lable3[], const char file_lable4[]); // read train data and train labels
	void run_twoClass(); // train data and save the model as "model.txt"

	/* function for UI design */
	void setSvmBtnColor(); // set style of button oneClass/twoClass using setBtnQss
	void setBtnQss(QPushButton *btn,
		QString normalColor, QString normalTextColor,
		QString hoverColor, QString hoverTextColor,
		QString pressedColor, QString pressedTextColor); // set the style of button
};

#endif // TESTQTSOCKET_H
