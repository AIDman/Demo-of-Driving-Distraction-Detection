#include "realTimeCheck.h"

/* initialize static members of realTimeCheckWindowClass */
Ui::Form realTimeCheckWindowClass::ui;
list<point> realTimeCheckWindowClass::point_list;
bool realTimeCheckWindowClass::testLabel[MAX_TEST] = { 0 };
int realTimeCheckWindowClass::dimension = 25; // set dimension = 25 automatically
bool realTimeCheckWindowClass::exitCheckLoop = FALSE;
char realTimeCheckWindowClass::recvBuf[410] = { 0 };
int realTimeCheckWindowClass::subNo = 1;
string realTimeCheckWindowClass::stopSendBuf = "I will stop send data.";
string realTimeCheckWindowClass::allFileReaded = "All file has been read.";
currentStatus realTimeCheckWindowClass::crtSt = rest;
string realTimeCheckWindowClass::modelFileName;
int realTimeCheckWindowClass::svmType; // 1:one-class 0:two-class
string realTimeCheckWindowClass::dir = "E:\\";

realTimeCheckWindowClass::realTimeCheckWindowClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	/* UI design for the "Real Time Check" window */

	this->setWindowTitle("Real Time Check");

	//setBtnQss(ui.background, "#C7C8C9", "#FFFFFF", "#C7C8C9", "#E5FEFF", "#C7C8C9", "#A0DAFB");
	//setBtnQss(ui.background, "#F5F5F5", "#FFFFFF", "#F5F5F5", "#E5FEFF", "#F5F5F5", "#A0DAFB");
	setBtnQss(ui.background, "#DCDCDC", "#FFFFFF", "#DCDCDC", "#E5FEFF", "#DCDCDC", "#A0DAFB");

	//setBtnQss(ui.returnToMain, "#C7C8C9", "#FFFFFF", "#DDDDDD", "#E5FEFF", "#AFB1B6", "#A0DAFB");
	setBtnQss(ui.returnToMain, "#34495E", "#FFFFFF", "#4E6D8C", "#F0F0F0", "#2D3E50", "#B8C6D1");
	setBtnQss(ui.startCheck, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
	setBtnQss(ui.stopCheck, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

	QPalette p = this->palette();
	p.setColor(QPalette::Window, QColor(255, 255, 255));
	this->setPalette(p);

	hThreadDraw = CreateThread(NULL, 0, ThreadDraw, NULL, 0, NULL); // create a thread to show current status of program
	CloseHandle(hThreadDraw);

	QPalette pe;
	pe.setColor(QPalette::WindowText, RGB(105, 105, 105));
	ui.turnToStopText->setPalette(pe);
	ui.waitText->setPalette(pe);
	ui.restText->setPalette(pe);
	ui.receiveDataText->setPalette(pe);
}

realTimeCheckWindowClass::~realTimeCheckWindowClass()
{

}

void realTimeCheckWindowClass::on_startCheck_clicked()
{
	crtSt = waitConnection;
	exitCheckLoop = FALSE;
	HANDLE hThread = CreateThread(NULL, 0, ThreadDetect, NULL, 0, NULL); // create a thread
	CloseHandle(hThread);
}

void realTimeCheckWindowClass::on_stopCheck_clicked()
{
	exitCheckLoop = TRUE; // break the detecting loop
}

DWORD WINAPI realTimeCheckWindowClass::ThreadDetect(LPVOID lpParameter)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0)
	{
		return 1;
	}

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return 1;
	}

	SOCKET socketSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv; // address of server
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	bind(socketSrv, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR));
	listen(socketSrv, 5);

	SOCKADDR_IN addrClient; // address of client
	int len = sizeof(SOCKADDR);

	SOCKET sockConn = accept(socketSrv, (SOCKADDR *)&addrClient, &len); // accept request from client
	crtSt = receiveData;
	string sendQuestion = "Which subject will I detect?";
	send(sockConn, sendQuestion.c_str(), strlen(sendQuestion.c_str()) + 1, 0);
	recv(sockConn, recvBuf, 410, 0); // get the No. of subject from data sender
	subNo = atoi(recvBuf);
	sendQuestion = "which type of SVM did you use?";
	send(sockConn, sendQuestion.c_str(), strlen(sendQuestion.c_str()) + 1, 0);
	recv(sockConn, recvBuf, 410, 0); // get the svm type from data sender
	svmType = atoi(recvBuf);

	char tmp[2];
	string strSubNo;
	sprintf(tmp, "%d", subNo);
	strSubNo = tmp;

	string strSvmType;
	if (svmType == 1) {
		strSvmType = "1";
	}
	else {
		strSvmType = "2";
	}

	modelFileName = dir + "model_" + strSubNo + "_" + strSvmType + ".txt";

	while (exitCheckLoop == FALSE)
	{
		string sendBuf = "OK! data analyzer is waiting...";
		send(sockConn, sendBuf.c_str(), strlen(sendBuf.c_str()) + 1, 0);
		
		recv(sockConn, recvBuf, 410, 0); // save received 25-dimension feature in recvBuf or exit info
		if ((strcmp(recvBuf, stopSendBuf.c_str()) == 0) || (strcmp(recvBuf, allFileReaded.c_str()) == 0))
		{
			break;
		}
		QString qRecvBuf1(recvBuf);
		ui.data->setText(qRecvBuf1);

		stringstream ss(recvBuf);
		string buf;
		point_list.clear();
		double *line = new double[dimension];
		int count = 0;
		while (ss >> buf)
		{
			line[count++] = atof(buf.c_str()); //read features
		}
		point p;
		p.value = 1; // set status: distracted
		p.feature = line; // save the 25-dimension feature in "line"
		point_list.push_back(p);
		svm_model *model = svm_load_model(modelFileName.c_str()); // load model
		svm_node *x_space = new svm_node[dimension + 1];
		double d;
		int i;
		int j = 0;
		list<point>::iterator q = point_list.begin();
		for (i = 0; i < dimension; i++)
		{
			x_space[i].index = i + 1;
			x_space[i].value = q->feature[i];
		}
		x_space[dimension].index = -1;

		d = svm_predict(model, x_space); // predict
		if (d == q->value) // classified as distracted
		{
			testLabel[j++] = TRUE;

			/* display picture */
			QString picName;
			picName = "distracted.tif";
			QImage* img = new QImage;
			img->load(picName);
			ui.pic->setPixmap(QPixmap::fromImage(*img));
		}
		else // classified as focused
		{
			testLabel[j++] = FALSE;

			/* display picture */
			QString picName;
			picName = "focused.tif";
			QImage* img = new QImage;
			img->load(picName);
			ui.pic->setPixmap(QPixmap::fromImage(*img));
			delete img;
		}
		QCoreApplication::processEvents();
		delete[] x_space;
	}
	crtSt = turnToRest;
	QString picName = "";
	QImage* img = new QImage;
	img->load(picName);
	ui.pic->setPixmap(QPixmap::fromImage(*img));
	ui.data->setText("");
	ui.restText->setText("");
	ui.waitText->setText("");
	ui.receiveDataText->setText("");
	ui.turnToStopText->setText(QApplication::translate("Form", "stop receiving data now!", 0));
	QCoreApplication::processEvents();
	Sleep(1000);
	crtSt = rest;
	if (strcmp(recvBuf, stopSendBuf.c_str()) == 0)
	{
		closesocket(sockConn);
		WSACleanup();
	}
	else
	{
		string sendBuf = "Stop now!"; // stop socket with data sender and make the data sender exit
		send(sockConn, sendBuf.c_str(), strlen(sendBuf.c_str()) + 1, 0);
		closesocket(sockConn);
		WSACleanup();
	}
}

void realTimeCheckWindowClass::on_returnToMain_clicked()
{
	this->close();
}

void realTimeCheckWindowClass::setBtnQss(QPushButton *btn,
	QString normalColor, QString normalTextColor,
	QString hoverColor, QString hoverTextColor,
	QString pressedColor, QString pressedTextColor)
{
	QStringList qss;
	qss.append(QString("QPushButton{border-style:none;padding:10px;border-radius:5px;color:%1;background:%2;}").arg(normalTextColor).arg(normalColor));
	qss.append(QString("QPushButton:hover{color:%1;background:%2;}").arg(hoverTextColor).arg(hoverColor));
	qss.append(QString("QPushButton:pressed{color:%1;background:%2;}").arg(pressedTextColor).arg(pressedColor));
	btn->setStyleSheet(qss.join(""));
}

DWORD WINAPI realTimeCheckWindowClass::ThreadDraw(LPVOID lpParameter)
{
	while (TRUE)
	{
		if (crtSt == rest)
		{
			ui.restText->setText("");
			ui.waitText->setText("");
			ui.receiveDataText->setText("");
			ui.turnToStopText->setText("");
			while (TRUE)
			{
				ui.restText->setText(QApplication::translate("Form", "resting.", 0));
				Sleep(250);
				if (crtSt != rest) {
					break;
				}
				ui.restText->setText(QApplication::translate("Form", "resting..", 0));
				Sleep(250);
				if (crtSt != rest) {
					break;
				}
				ui.restText->setText(QApplication::translate("Form", "resting...", 0));
				Sleep(250);
				if (crtSt != rest) {
					break;
				}
			}		
		}
		else if (crtSt == waitConnection)
		{
			ui.restText->setText("");
			ui.waitText->setText("");
			ui.receiveDataText->setText("");
			ui.turnToStopText->setText("");
			while (TRUE)
			{
				ui.waitText->setText(QApplication::translate("Form", "waiting for request.", 0));
				Sleep(250);
				if (crtSt != waitConnection)
				{
					break;
				}
				ui.waitText->setText(QApplication::translate("Form", "waiting for request..", 0));
				Sleep(250);
				if (crtSt != waitConnection)
				{
					break;
				}
				ui.waitText->setText(QApplication::translate("Form", "waiting for request...", 0));
				Sleep(250);
				if (crtSt != waitConnection) 
				{
					break;
				}
			}
		}
		else if (crtSt == receiveData)
		{
			ui.restText->setText("");
			ui.waitText->setText("");
			ui.receiveDataText->setText("");
			ui.turnToStopText->setText("");
			while (TRUE)
			{
				ui.receiveDataText->setText(QApplication::translate("Form", "receiving data.", 0));
				Sleep(250);
				if (crtSt != receiveData)
				{
					break;
				}
				ui.receiveDataText->setText(QApplication::translate("Form", "receiving data..", 0));
				Sleep(250);
				if (crtSt != receiveData)
				{
					break;
				}
				ui.receiveDataText->setText(QApplication::translate("Form", "receiving data...", 0));
				Sleep(250);
				if (crtSt != receiveData)
				{
					break;
				}
			}
		}
	}
	
	return 0;
}