#include "datasender.h"

/* initialize static member */
bool dataSender::breakLoop = FALSE;
int dataSender::subNo = 1;
string dataSender::stopSend = "Stop now!";
string dataSender::allFileReaded = "All file has been read.";
bool dataSender::stopSendData = FALSE;
Ui::dataSenderClass dataSender::ui;
currentStatus dataSender::crtSt = rest;
int dataSender::svmType = 0;
string dataSender::trainDataFile1; // for one-class-SVM & two-class-SVM
string dataSender::trainDataFile2; // for one-class-SVM & two-class-SVM
string dataSender::trainDataFile3; // for one-class-SVM & two-class-SVM
string dataSender::trainDataFile4; // for two-class only; with lable 0
string dataSender::trainLabelFile1 = "\.\\data\\trainlabel.txt"; // for one-class-SVM & two-class-SVM
string dataSender::trainLabelFile2 = "\.\\data\\trainlabel2.txt"; // for one-class-SVM & two-class-SVM
string dataSender::trainLabelFile3 = "\.\\data\\trainlabel3.txt"; // for one-class-SVM & two-class-SVM
string dataSender::trainLabelFile4 = "\.\\data\\trainlabel4.txt"; // for two-class only; lable 0
int dataSender::dimension = 25;
int dataSender::trainNum = 3500;
int dataSender::testNum = 3500;
double dataSender::nu = 0.50;
double dataSender::gamma = 1.00;
double dataSender::coef0 = 0.00;
double dataSender::degree = 3.00;
list<point> dataSender::point_list;
string dataSender::modelDir = "E:\\";

dataSender::dataSender(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setBtnQss(ui.background, "#DCDCDC", "#FFFFFF", "#DCDCDC", "#E5FEFF", "#DCDCDC", "#A0DAFB");
	setSubBtnColor();
	setBtnQss(ui.startSend, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
	setBtnQss(ui.stopSend, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");
	setBtnQss(ui.exit, "#34495E", "#FFFFFF", "#4E6D8C", "#F0F0F0", "#2D3E50", "#B8C6D1");

	QPalette p = this->palette();
	p.setColor(QPalette::Window, QColor(255, 255, 255));
	this->setPalette(p);
	
	ui.mainToolBar->hide();

	QPalette pal;
	pal.setColor(QPalette::ButtonText, QColor(0, 205, 102));
	ui.titleText->setPalette(pal);

	ui.sendText->setText("");

	QPalette pe;
	pe.setColor(QPalette::WindowText, RGB(105, 105, 105));
	ui.sendText->setPalette(pe);
	ui.restText->setPalette(pe);
	ui.trainText->setPalette(pe);

	QPalette pa;
	pa.setColor(QPalette::ButtonText, QColor(0, 197, 205));
	ui.svmText->setPalette(pa);

	setSvmBtnColor();

	setBtnQss(ui.train, "#FF3C63", "#FFFFFF", "#FF6685", "#E5FEFF", "#FF1244", "#A0DAFB");

	hThreadDraw = CreateThread(NULL, 0, ThreadDraw, NULL, 0, NULL); // create thread to show program's status on GUI
	CloseHandle(hThreadDraw);
}

dataSender::~dataSender()
{

}

void dataSender::on_startSend_clicked()
{
	crtSt = sendData;
	stopSendData = FALSE;
	breakLoop = FALSE;
	HANDLE hThread = CreateThread(NULL, 0, ThreadSend, NULL, 0, NULL); // create a thread
	CloseHandle(hThread);
}

void dataSender::setBtnQss(QPushButton *btn,
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

void dataSender::setSubBtnColor()
{
	setBtnQss(ui.sub1, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub2, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub3, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub4, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub5, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub6, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub7, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub8, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub1_clicked()
{
	subNo = 1;

	setSubBtnColor();
	setBtnQss(ui.sub1, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub2_clicked()
{
	subNo = 2;
	setSubBtnColor();
	setBtnQss(ui.sub2, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub3_clicked()
{
	subNo = 3;
	setSubBtnColor();
	setBtnQss(ui.sub3, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub4_clicked()
{
	subNo = 4;
	setSubBtnColor();
	setBtnQss(ui.sub4, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub5_clicked()
{
	subNo = 5;
	setSubBtnColor();
	setBtnQss(ui.sub5, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub6_clicked()
{
	subNo = 6;
	setSubBtnColor();
	setBtnQss(ui.sub6, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub7_clicked()
{
	subNo = 7;
	setSubBtnColor();
	setBtnQss(ui.sub7, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

void dataSender::on_sub8_clicked()
{
	subNo = 8;
	setSubBtnColor();
	setBtnQss(ui.sub8, "#00AA00", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
}

string dataSender::generateSourceFileName(int sub, int phase)
{
	string str1 = "\.\\sourceData\\s";

	char strSub[2];
	sprintf_s(strSub, "%d", sub);
	string str2 = strSub;

	string str3 = "b";

	char strPhase[2];
	sprintf_s(strPhase, "%d", phase);
	string str4 = strPhase;

	string str5 = ".txt";

	string srcFileName = str1 + str2 + str3 + str4 + str5;

	return srcFileName;
}

DWORD WINAPI dataSender::ThreadSend(LPVOID lpParameter)
{
	ifstream indata;
	ofstream outdata;

	string sourceFileName;
	string buffer_tmp; // save the data from indata(ifstream) temporarily
	string buffer; // delete the three ' ' in buffer_tmp

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return 1;
	}
	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return 1;
	}
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	::connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)); // send request to server

	char recvBuf[50];
	recv(sockClient, recvBuf, 50, 0);
	printf("receive: %s\n", recvBuf);

	//sprintf_s(buffer.c_str(), 2, "%d", subNo);
	sprintf_s((char*)buffer.c_str(), 3, "%d", subNo);
	send(sockClient, buffer.c_str(), strlen(buffer.c_str()) + 1, 0); // send subNo to data analyzer

	recv(sockClient, recvBuf, 50, 0);
	printf("receive: %s\n", recvBuf);

	//sprintf_s(buffer.c_str(), 2, "%d", subNo);
	sprintf_s((char*)buffer.c_str(), 3, "%d", svmType);
	send(sockClient, buffer.c_str(), strlen(buffer.c_str()) + 1, 0);  // send svmType to data analyzer

	char recvBuf2[50];
	recv(sockClient, recvBuf2, 50, 0);
	printf("receive: %s\n", recvBuf2);

	int j = 4;//here!!
	while (1) // enter the loop
	{
		if (stopSendData == TRUE)
		{
			string stopSendBuf = "I will stop send data.";
			send(sockClient, stopSendBuf.c_str(), strlen(stopSendBuf.c_str()) + 1, 0);
			break;
		}
		if (breakLoop == TRUE) // receive "Stop now!" from data analyzer
		{
			break;
		}
		if (j > PHASE_NUM)
		{
			break;
		}
		sourceFileName = generateSourceFileName(subNo, j);
		indata.open(sourceFileName.c_str());
		while (!indata.eof())
		{
			if (stopSendData == TRUE)
			{
				break;
			}
			getline(indata, buffer_tmp, '\n');

			if (strlen(buffer_tmp.c_str()) == 0) // add this mechanism because each txt file has a '\n' ( which we should skip ) at the end
			{
				break;
			}

			buffer = buffer_tmp.substr(3, strlen(buffer_tmp.c_str()) - 3); // delete the first three ' '

			send(sockClient, buffer.c_str(), strlen(buffer.c_str()) + 1, 0);
			printf("send: %s\n", buffer.c_str());

			char recvBuf[30];
			recv(sockClient, recvBuf, 50, 0);

			if (strcmp(recvBuf, stopSend.c_str()) == 0) // receive "Stop now!" from data analyzer
			{
				breakLoop = TRUE;
				break;
			}
			printf("%s\n", recvBuf);
			Sleep(50);
		}
		indata.close();
		if (j == 4)
		{
			j = 6;
		}
		else
		{
			send(sockClient, allFileReaded.c_str(), strlen(allFileReaded.c_str()) + 1, 0);
		}
	}
	crtSt = rest;
	//setSubBtnColor();
	closesocket(sockClient);
	WSACleanup();
}

void dataSender::on_stopSend_clicked()
{
	stopSendData = TRUE;
}

void dataSender::on_exit_clicked()
{
	this->close();
}

DWORD WINAPI dataSender::ThreadDraw(LPVOID lpParameter)
{
	while (TRUE)
	{
		if (crtSt == rest)
		{
			ui.sendText->setText("");
			ui.restText->setText("");
			ui.trainText->setText("");
			while (TRUE)
			{
				ui.restText->setText(QApplication::translate("Form", "resting.", 0));
				Sleep(250);
				if (crtSt != rest)
				{
					break;
				}
				ui.restText->setText(QApplication::translate("Form", "resting..", 0));
				Sleep(250);
				if (crtSt != rest)
				{
					break;
				}
				ui.restText->setText(QApplication::translate("Form", "resting...", 0));
				Sleep(250);
				if (crtSt != rest)
				{
					break;
				}
			}
		}
		else if (crtSt == sendData)
		{
			ui.sendText->setText("");
			ui.restText->setText("");
			ui.trainText->setText("");
			while (TRUE)
			{
				ui.sendText->setText(QApplication::translate("Form", "sending data.", 0));
				Sleep(250);
				if (crtSt != sendData)
				{
					break;
				}
				ui.sendText->setText(QApplication::translate("Form", "sending data..", 0));
				Sleep(250);
				if (crtSt != sendData)
				{
					break;
				}
				ui.sendText->setText(QApplication::translate("Form", "sending data...", 0));
				Sleep(250);
				if (crtSt != sendData)
				{
					break;
				}
			}
		}
		else if (crtSt == train)
		{
			ui.sendText->setText("");
			ui.restText->setText("");
			ui.trainText->setText("please wait for training...");
			while (TRUE)
			{
				ui.trainText->setText(QApplication::translate("Form", "training.", 0));
				Sleep(250);
				if (crtSt != train)
				{
					break;
				}
				ui.trainText->setText(QApplication::translate("Form", "training..", 0));
				Sleep(250);
				if (crtSt != train)
				{
					break;
				}
				ui.trainText->setText(QApplication::translate("Form", "training...", 0));
				Sleep(250);
				if (crtSt != train)
				{
					break;
				}
			}
		}
	}
	return 0;
}

void dataSender::setSvmBtnColor()
{
	setBtnQss(ui.oneClass, "#01CBCB", "#FFFFFF", "#01F5F5", "#E5FEFF", "#019FA0", "#A0DAFB");
	setBtnQss(ui.twoClass, "#01CBCB", "#FFFFFF", "#01F5F5", "#E5FEFF", "#019FA0", "#A0DAFB");
}

void dataSender::on_oneClass_clicked()
{
	svmType = 1;
	setSvmBtnColor();
	setBtnQss(ui.oneClass, "#0088A8", "#FFFFFF", "#0088A8", "#E5FEFF", "#0088A8", "#A0DAFB");
}

void dataSender::on_twoClass_clicked()
{
	svmType = 0;
	setSvmBtnColor();
	setBtnQss(ui.twoClass, "#0088A8", "#FFFFFF", "#0088A8", "#E5FEFF", "#0088A8", "#A0DAFB");
}

void dataSender::writeTrainLabel_twoClass()
{
	ofstream fout_label;
	fout_label.open(trainLabelFile1.c_str());
	for (int i = 0; i < trainNum; i++)
	{
		if (i != trainNum - 1)
			fout_label << '1' << '\n';
		else
		{
			fout_label << '1';
		}
	}
	fout_label << flush;
	fout_label.close();

	fout_label.open(trainLabelFile2.c_str());
	for (int i = 0; i < trainNum; i++)
	{
		if (i != trainNum - 1)
			fout_label << '1' << '\n';
		else
		{
			fout_label << '1';
		}
	}
	fout_label << flush;
	fout_label.close();

	fout_label.open(trainLabelFile3.c_str());
	for (int i = 0; i < trainNum; i++)
	{
		if (i != trainNum - 1)
			fout_label << '1' << '\n';
		else
		{
			fout_label << '1';
		}
	}
	fout_label << flush;
	fout_label.close();

	fout_label.open(trainLabelFile4.c_str());
	for (int i = 0; i < trainNum; i++)
	{
		if (i != trainNum - 1)
			fout_label << '0' << '\n';
		else
		{
			fout_label << '0';
		}
	}
	fout_label << flush;
	fout_label.close();

}

void dataSender::readTrainData_twoClass(const char file[], const char file2[], const char file3[], const char file4[],
	const char file_lable[], const char file_lable2[], const char file_lable3[], const char file_lable4[])  //read train data
{
	point_list.clear();

	/* file 1 */
	ifstream indata, indata_lable;
	indata.open(file, ios::in);               //读入特征
	indata_lable.open(file_lable, ios::in);    // 读入标签  
	while (!indata.eof())              // 如果没有读到文件结束，就继续读，知道读完整个 traindata 文件  
	{

		double *line = new double[MAX_DIMENSION];
		for (int i = 0; i < dimension; i++)
		{
			indata >> line[i];       //把特征存起来  
		}

		point p;
		indata_lable >> p.value;          //把label存起来  

		p.feature = line;
		point_list.push_back(p);

	}
	point_list.pop_back();        //如果你的 traindata.txt 文件数据的最后有一个空格的话，需要加上这句话，否则预测会有错如果没有空格，这句话就不需要了  
	indata.close();
	indata_lable.close();

	/* file 2 */
	indata.open(file2, ios::in);               //读入特征
	indata_lable.open(file_lable2, ios::in);    // 读入标签  
	while (!indata.eof())              // 如果没有读到文件结束，就继续读，知道读完整个 traindata 文件  
	{

		double *line = new double[MAX_DIMENSION];
		for (int i = 0; i < dimension; i++)
		{
			indata >> line[i];       //把特征存起来  
		}

		point p;
		indata_lable >> p.value;          //把label存起来  

		p.feature = line;

		point_list.push_back(p);

	}
	point_list.pop_back();        //如果你的 traindata.txt 文件数据的最后有一个空格的话，需要加上这句话，否则预测会有错如果没有空格，这句话就不需要了  
	indata.close();
	indata_lable.close();

	/* file 3 */
	indata.open(file3, ios::in);               //读入特征
	indata_lable.open(file_lable3, ios::in);    // 读入标签  
	while (!indata.eof())              // 如果没有读到文件结束，就继续读，知道读完整个 traindata 文件  
	{
		double *line = new double[MAX_DIMENSION];
		for (int i = 0; i < dimension; i++)
		{
			indata >> line[i];       //把特征存起来  
		}

		point p;
		indata_lable >> p.value;          //把label存起来  

		p.feature = line;

		point_list.push_back(p);

	}
	point_list.pop_back();        //如果你的 traindata.txt 文件数据的最后有一个空格的话，需要加上这句话，否则预测会有错如果没有空格，这句话就不需要了  
	indata.close();
	indata_lable.close();

	/* file 4 */
	indata.open(file4, ios::in);               //读入特征
	indata_lable.open(file_lable4, ios::in);    // 读入标签  
	while (!indata.eof())              // 如果没有读到文件结束，就继续读，知道读完整个 traindata 文件  
	{

		double *line = new double[MAX_DIMENSION];
		for (int i = 0; i < dimension; i++)
		{
			indata >> line[i];       //把特征存起来  
		}

		point p;
		indata_lable >> p.value;          //把label存起来  

		p.feature = line;

		point_list.push_back(p);

	}
	point_list.pop_back();        //如果你的 traindata.txt 文件数据的最后有一个空格的话，需要加上这句话，否则预测会有错如果没有空格，这句话就不需要了  
	indata.close();
	indata_lable.close();
}

void dataSender::run_twoClass()
{
	if (point_list.empty()) return;

	svm_parameter param;
	int i, j;

	// set parameters
	param.svm_type = NU_SVC;
	param.kernel_type = 1; // type of kernel function
	param.degree = degree;
	param.gamma = gamma;
	param.coef0 = coef0;
	param.nu = nu;
	param.cache_size = 2000;
	param.C = 1;
	param.eps = 1e-3;
	param.p = 0.1;
	param.shrinking = 1;
	param.probability = 0;
	param.nr_weight = 0;
	param.weight_label = NULL;
	param.weight = NULL;

	// build problem
	svm_problem prob;

	prob.l = point_list.size();
	prob.y = new double[prob.l];

	if (param.kernel_type == PRECOMPUTED)
	{
	}
	else if (param.svm_type == EPSILON_SVR ||
		param.svm_type == NU_SVR)
	{
		if (param.gamma == 0) param.gamma = 1;
		svm_node *x_space = new svm_node[2 * prob.l];
		prob.x = new svm_node *[prob.l];

		i = 0;
		for (list<point>::iterator q = point_list.begin(); q != point_list.end(); q++, i++)
		{
		}

		// build model & classify
		svm_model *model = svm_train(&prob, &param);

		svm_free_and_destroy_model(&model);

		delete[] x_space;
		delete[] prob.x;
		delete[] prob.y;
	}
	else
	{
		if (param.gamma == 0) param.gamma = 0.5;

		prob.x = new svm_node *[prob.l];
		int k = 0;
		for (list<point>::iterator q = point_list.begin(); q != point_list.end(); q++, k++)
		{
			svm_node *x_space = new svm_node[dimension + 1];
			for (i = 0; i < dimension; i++)
			{

				x_space[i].index = i + 1;
				x_space[i].value = q->feature[i];

			}
			x_space[dimension].index = -1;
			prob.x[k] = x_space;
			prob.y[k] = q->value;

		}

		// build model & classify
		svm_model *model = svm_train(&prob, &param);

		char tmpSub[2];
		string strSubNo;
		sprintf(tmpSub, "%d", subNo);
		strSubNo = tmpSub;

		string modelName = modelDir + "model_" + strSubNo + "_2.txt";

		// save model
		svm_save_model(modelName.c_str(), model);

		svm_free_and_destroy_model(&model);
		for (i = 0; i < int(point_list.size()); i++)
		{
			delete[] prob.x[i];
		}
		delete[] prob.x;
		delete[] prob.y;
	}
	free(param.weight_label);
	free(param.weight);
}

void dataSender::setPara_twoClass()
{
	nu = 0.30;
	gamma = 0.50;
	coef0 = 0.00;
	degree = 3.00;
}

void dataSender::generateFileName_twoClass()
{
	char tmp[2];
	string strSubNo;
	sprintf(tmp, "%d", subNo);
	strSubNo = tmp;

	trainDataFile1 = "\.\\data\\s" + strSubNo + "b1.txt"; // write label '1'
	trainDataFile2 = "\.\\data\\s" + strSubNo + "b2.txt"; // write label '1'
	trainDataFile3 = "\.\\data\\s" + strSubNo + "b3.txt"; // write label '1'
	trainDataFile4 = "\.\\data\\s" + strSubNo + "b5.txt"; // write label '0'
}

void dataSender::writeTrainLabel_oneClass()
{
	ofstream fout_label;
	fout_label.open(trainLabelFile1.c_str());
	for (int i = 0; i < trainNum; i++)
	{
		if (i != trainNum - 1)
			fout_label << '1' << '\n';
		else
		{
			fout_label << '1';
		}
	}
	fout_label << flush;
	fout_label.close();

	fout_label.open(trainLabelFile2.c_str());
	for (int i = 0; i < trainNum; i++)
	{
		if (i != trainNum - 1)
			fout_label << '1' << '\n';
		else
		{
			fout_label << '1';
		}
	}
	fout_label << flush;
	fout_label.close();

	fout_label.open(trainLabelFile3.c_str());
	for (int i = 0; i < trainNum; i++)
	{
		if (i != trainNum - 1)
			fout_label << '1' << '\n';
		else
		{
			fout_label << '1';
		}
	}
	fout_label << flush;
	fout_label.close();
}

void dataSender::readTrainData_oneClass(const char file[], const char file2[], const char file3[],
	const char file_lable[], const char file_lable2[], const char file_lable3[])
{
	point_list.clear();

	/* file 1 */
	ifstream indata, indata_lable;
	indata.open(file, ios::in); // read features
	indata_lable.open(file_lable, ios::in); // read labels
	while (!indata.eof())
	{
		double *line = new double[MAX_DIMENSION];
		for (int i = 0; i < dimension; i++)
		{
			indata >> line[i];       // save features  
		}
		point p;
		indata_lable >> p.value; // save labels  
		p.feature = line;
		point_list.push_back(p);

	}
	point_list.pop_back();
	indata.close();
	indata_lable.close();

	/* file 2 */
	indata.open(file2, ios::in); // read features
	indata_lable.open(file_lable2, ios::in); // read labels
	while (!indata.eof())
	{
		double *line = new double[MAX_DIMENSION];
		for (int i = 0; i < dimension; i++)
		{
			indata >> line[i];       // save features  
		}
		point p;
		indata_lable >> p.value; //save labels 
		p.feature = line;
		point_list.push_back(p);
	}
	point_list.pop_back();
	indata.close();
	indata_lable.close();

	/* file 3 */
	indata.open(file3, ios::in); // read features
	indata_lable.open(file_lable3, ios::in); // read labels  
	while (!indata.eof()) {

		double *line = new double[MAX_DIMENSION];
		for (int i = 0; i < dimension; i++)
		{
			indata >> line[i]; // save features  
		}
		point p;
		indata_lable >> p.value; // save labels  
		p.feature = line;
		point_list.push_back(p);
	}
	point_list.pop_back();
	indata.close();
	indata_lable.close();
}

void dataSender::run_oneClass()
{
	if (point_list.empty()) return;

	svm_parameter param;
	int i, j;

	// set parameters
	param.svm_type = ONE_CLASS;
	param.kernel_type = 1; //type of kernel function
	param.degree = degree;
	param.gamma = gamma;
	param.coef0 = coef0;
	param.nu = nu;
	param.cache_size = 100;
	param.C = 1;
	param.eps = 1e-3;
	param.p = 0.1;
	param.shrinking = 1;
	param.probability = 0;
	param.nr_weight = 0;
	param.weight_label = NULL;
	param.weight = NULL;

	// build problem
	svm_problem prob;

	prob.l = point_list.size();
	prob.y = new double[prob.l];

	if (param.kernel_type == PRECOMPUTED)
	{
	}
	else if (param.svm_type == EPSILON_SVR ||
		param.svm_type == NU_SVR)
	{
		if (param.gamma == 0) param.gamma = 1;
		svm_node *x_space = new svm_node[2 * prob.l];
		prob.x = new svm_node *[prob.l];

		i = 0;
		for (list<point>::iterator q = point_list.begin(); q != point_list.end(); q++, i++)
		{
		}

		// build model & classify
		svm_model *model = svm_train(&prob, &param);

		svm_free_and_destroy_model(&model);

		delete[] x_space;
		delete[] prob.x;
		delete[] prob.y;
	}
	else
	{
		if (param.gamma == 0) param.gamma = 0.5;

		prob.x = new svm_node *[prob.l];
		int k = 0;
		for (list<point>::iterator q = point_list.begin(); q != point_list.end(); q++, k++)
		{
			svm_node *x_space = new svm_node[dimension + 1];
			for (i = 0; i < dimension; i++)
			{

				x_space[i].index = i + 1;
				x_space[i].value = q->feature[i];

			}
			x_space[dimension].index = -1;
			prob.x[k] = x_space;
			prob.y[k] = q->value;
		}

		// build model & classify
		svm_model *model = svm_train(&prob, &param);

		char tmpSub[2];
		string strSubNo;
		sprintf(tmpSub, "%d", subNo);
		strSubNo = tmpSub;

		string modelName = "E:\\model_" + strSubNo + "_1.txt";

		// save model
		svm_save_model(modelName.c_str(), model);

		svm_free_and_destroy_model(&model);
		for (i = 0; i < int(point_list.size()); i++)
		{
			delete[] prob.x[i];
		}
		delete[] prob.x;
		delete[] prob.y;
	}
	free(param.weight_label);
	free(param.weight);
}

void dataSender::setPara_oneClass() // set parameters for one-class-SVM
{
	nu = 0.05;
	gamma = 0.50;
	coef0 = 0;
	degree = 3;
}

void dataSender::generateFileName_oneClass()
{
	char tmp[2];
	string strSubNo;
	sprintf(tmp, "%d", subNo);
	strSubNo = tmp;

	trainDataFile1 = "\.\\data\\s" + strSubNo + "b1.txt";
	trainDataFile2 = "\.\\data\\s" + strSubNo + "b2.txt";
	trainDataFile3 = "\.\\data\\s" + strSubNo + "b3.txt";
}

void dataSender::on_train_clicked()
{
	crtSt = train; // change the current state of program
	hThreadDraw = CreateThread(NULL, 0, ThreadTrain, NULL, 0, NULL); // create a thread
	CloseHandle(hThreadDraw);
}

DWORD WINAPI dataSender::ThreadTrain(LPVOID lpParameter)
{
	if (svmType == 1) // one-class-SVM
	{
		generateFileName_oneClass();
		writeTrainLabel_oneClass();
		setPara_oneClass();
		readTrainData_oneClass(trainDataFile1.c_str(), trainDataFile2.c_str(), trainDataFile3.c_str(),
			trainLabelFile1.c_str(), trainLabelFile2.c_str(), trainLabelFile3.c_str());
		run_oneClass();
	}
	else if (svmType == 0) // two-class-SVM
	{
		generateFileName_twoClass();
		writeTrainLabel_twoClass();
		setPara_twoClass();
		readTrainData_twoClass(trainDataFile1.c_str(), trainDataFile2.c_str(), trainDataFile3.c_str(), trainDataFile4.c_str(),
			trainLabelFile1.c_str(), trainLabelFile2.c_str(), trainLabelFile3.c_str(), trainLabelFile4.c_str());
		run_twoClass();
	}
	crtSt = rest;
	return 0;
}