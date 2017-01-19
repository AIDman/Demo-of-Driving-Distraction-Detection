#ifndef DATASENDER_H
#define DATASENDER_H



#include <QtWidgets/QMainWindow>
#include "ui_datasender.h"
#include <tchar.h>

using namespace std;

#include <fstream>
#include <stdio.h>
#include <Winsock2.h>  
#include <string>

#pragma comment(lib,"WS2_32.lib")  

#include "svm.h"

const int PHASE_NUM = 6;

enum currentStatus {
	rest = 0,
	sendData = 1,
	train = 2 
};

struct point { //the format of data used for function svm_train()
	double *feature; // 25-dimension feature
	bool value; // driver's state corresponding to feature; 0/FALSE:focused; 1/TRUE:distracted
};

const int MAX_DIMENSION = 100; // upper limit of dimension number ( in fact, it's 25 )

class dataSender : public QMainWindow
{
	Q_OBJECT

public:
	dataSender(QWidget *parent = 0);
	~dataSender();

public slots: // slot function

	/* choose subject */
	void on_sub1_clicked();
	void on_sub2_clicked();
	void on_sub3_clicked();
	void on_sub4_clicked();
	void on_sub5_clicked();
	void on_sub6_clicked();
	void on_sub7_clicked();
	void on_sub8_clicked();

	/* choose SVM type */
	void on_oneClass_clicked();
	void on_twoClass_clicked();

	/* train data */
	void on_train_clicked();
	
	/* start to send data to data analyzer*/
	void on_startSend_clicked();

	/* stop sending data */
	void on_stopSend_clicked();

	/* exit the program */
	void on_exit_clicked();

private:
	static Ui::dataSenderClass ui;

private: //private data
	
	static bool breakLoop; // whether or not to break the external while loop
	static int subNo; // No. of subject
	static bool stopSendData; // whether or not to stop sending data
	HANDLE hThreadDraw; // thread for the display of current state
	static list<point> point_list;
	static int dimension ; // dimension of EEG feature (25)
	static int trainNum; // upper limit of number of train data
	static int testNum; // upper limit of number of test data
	static int svmType; // 1:one-class; 0:two-class
	static string stopSend; // send this string when deciding to stop sending data
	static string allFileReaded; // send this string when all files have been read
	static string trainDataFile1; // for one-class-SVM & two-class-SVM
	static string trainDataFile2; // for one-class-SVM & two-class-SVM
	static string trainDataFile3; // for one-class-SVM & two-class-SVM
	static string trainDataFile4; // for two-class only; with lable 0
	static string trainLabelFile1 ; // for one-class-SVM & two-class-SVM
	static string trainLabelFile2 ; // for one-class-SVM & two-class-SVM
	static string trainLabelFile3 ; // for one-class-SVM & two-class-SVM
	static string trainLabelFile4 ; // for two-class only; lable 0
	static string modelDir; // directory for saving trained model
	
	/* default parameters of SVM */
	static double nu ;
	static double gamma ;
	static double coef0 ;
	static double degree ;

private: //private functions
	static void setBtnQss(QPushButton *btn,
		QString normalColor, QString normalTextColor,
		QString hoverColor, QString hoverTextColor,
		QString pressedColor, QString pressedTextColor); // set the style of button
	static void setSubBtnColor(); // set style of button (sub 1-8)
	static void setSvmBtnColor(); // set style of button (svm type)
	static string generateSourceFileName(int sub, int phase);
	static DWORD WINAPI ThreadSend(LPVOID lpParameter); // thread for the real-time sending
	static DWORD WINAPI ThreadDraw(LPVOID lpParameter); // thread for showing current status of the program on GUI
	static DWORD WINAPI ThreadTrain(LPVOID lpParameter); // thread for training data
	static currentStatus crtSt; // current state of the program
	

	/* function for one-class-SVM train */
	static void generateFileName_oneClass(); // generate trainDataFile[1 - 3]
	static void writeTrainLabel_oneClass(); // write in trainLabelFile[1 - 3]
	static void setPara_oneClass(); // set parameters
	static void readTrainData_oneClass(const char file[], const char file2[], const char file3[],
		const char file_lable[], const char file_lable2[], const char file_lable3[]); // read train data and train labels
	static void run_oneClass(); // train data and save the model as "model.txt"

	/* function for two-class-SVM train */
	static void generateFileName_twoClass(); // generate trainDataFile[1-4]
	static void writeTrainLabel_twoClass(); // write trainLabelFile[1-4]
	static void setPara_twoClass(); // set parameters
	static void readTrainData_twoClass(const char file[], const char file2[], const char file3[], const char file4[],
		const char file_lable[], const char file_lable2[], const char file_lable3[], const char file_lable4[]); // read train data and train labels
	static void run_twoClass(); // train data and save the model as "model.txt"
};

#endif // DATASENDER_H
