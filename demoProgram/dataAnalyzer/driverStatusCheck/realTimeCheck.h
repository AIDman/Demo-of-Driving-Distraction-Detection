#pragma once
#ifndef REALTIMECHECK_H
#define REALTIMECHECK_H

using namespace std;

#include <QtWidgets/QMainWindow>
#include "ui_realTimeCheck.h"

#include <Winsock2.h>  
#pragma comment(lib,"WS2_32.lib")  
#include "svm.h"
#include <sstream>

const int MAX_TEST = 3500; //upper limit of number of test data

struct point { //the format of data used for function svm_train()
	double *feature; // 25-dimension feature
	bool value; // driver's state corresponding to feature; 0/FALSE:focused; 1/TRUE:distracted
};

enum currentStatus
{
	rest = 0,
	waitConnection = 1,
	receiveData = 2,
	turnToRest = 3
};


class realTimeCheckWindowClass : public QWidget
{
	Q_OBJECT

public:
	realTimeCheckWindowClass(QWidget *parent = 0);
	~realTimeCheckWindowClass();

public:
	static int svmType; // 1:one-class 0:two-class

//signals:
//	void sendAData(QString);

public slots: // slot functions for clicking the buttons
	void on_startCheck_clicked(); // “开始监测” button
	void on_stopCheck_clicked(); // “停止接收” button
	void on_returnToMain_clicked(); // “返回” button

private:
	static Ui::Form ui;

private: //private data
	static list<point> point_list;
	static int dimension; // the dimension of EEG data
	static bool testLabel[MAX_TEST]; // TRUE: distracted; FALSE: focused
	static bool exitCheckLoop; // whether or not to continue the socket with data sender
	static char recvBuf[410]; // save the data sent from data sender
	static int subNo; // No. of subject （1-8）
	static currentStatus crtSt;
	static string stopSendBuf;
	static string allFileReaded;
	static string modelFileName;
	static string dir;

private: //private function
	void setBtnQss(QPushButton *btn,
		QString normalColor, QString normalTextColor,
		QString hoverColor, QString hoverTextColor,
		QString pressedColor, QString pressedTextColor); // set the style of button
	static DWORD WINAPI ThreadDetect(LPVOID lpParameter); // a thread function for the real-time detection
	static DWORD WINAPI ThreadDraw(LPVOID lpParameter); // display current status
	HANDLE hThreadDraw;

};

#endif // REALTIMECHECK_H
