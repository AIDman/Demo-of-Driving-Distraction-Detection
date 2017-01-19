#include "driverStatusCheck.h"

driverStatusCheckWindowClass::driverStatusCheckWindowClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowTitle("Driver Status Check");

	/*setBtnQss(ui.sub1, "#019FA0", "#FFFFFF", "#BFDE96", "#E5FEFF", "#8CC540", "#A0DAFB");
	setBtnQss(ui.sub2, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub3, "#01CBCB", "#FFFFFF", "#01F5F5", "#E5FEFF", "#019FA0", "#A0DAFB");
	setBtnQss(ui.sub4, "#0CBBFE", "#FFFFFF", "#36C7FE", "#E5FEFF", "#019FDE", "#A0DAFB");
	setBtnQss(ui.sub5, "#019FA0", "#FFFFFF", "#BFDE96", "#E5FEFF", "#8CC540", "#A0DAFB");
	setBtnQss(ui.sub6, "#00CA74", "#FFFFFF", "#00F490", "#E5FEFF", "#009F5D", "#A0DAFB");
	setBtnQss(ui.sub7, "#01CBCB", "#FFFFFF", "#01F5F5", "#E5FEFF", "#019FA0", "#A0DAFB");
	setBtnQss(ui.sub8, "#0CBBFE", "#FFFFFF", "#36C7FE", "#E5FEFF", "#019FDE", "#A0DAFB");*/

	/*setBtnQss(ui.oneClass, "#FF8096", "#FFFFFF", "#FFAAB9", "#E5FEFF", "#FF5675", "#A0DAFB");
	setBtnQss(ui.twoClass, "#FF8096", "#FFFFFF", "#FFAAB9", "#E5FEFF", "#FF5675", "#A0DAFB");
*/
	setSvmBtnColor();
	
	//setBtnQss(ui.train, "#D99DE6", "#FFFFFF", "#E6BFFE", "#E5FEFF", "#CD7BBD", "#A0DAFB");

	//setBtnQss(ui.realTimeCheck, "#FAC934", "#FFFFFF", "#FBD35E", "#E5FEFF", "#F8BD0E", "#A0DAFB");

	//setBtnQss(ui.exit, "#C7C8C9", "#FFFFFF", "#DDDDDD", "#E5FEFF", "#AFB1B6", "#A0DAFB");
	//setBtnQss(ui.exit, "#01CBCB", "#FFFFFF", "#01F5F5", "#E5FEFF", "#019FA0", "#A0DAFB");
	//setBtnQss(ui.exit, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");
	
	QPalette p = this->palette();
	p.setColor(QPalette::Window, QColor(255,255,255));
	this->setPalette(p);

	QPalette pal;
	pal.setColor(QPalette::ButtonText, QColor(0, 197, 205));
	ui.titleText ->setPalette(pal);

	ui.mainToolBar->hide();
	//this->setWindowFlags(Qt::FramelessWindowHint);


}

driverStatusCheckWindowClass::~driverStatusCheckWindowClass()
{

}

void driverStatusCheckWindowClass::on_oneClass_clicked()
{
	this->hide();
	newWindow = new realTimeCheckWindowClass();
	newWindow->svmType = 1;
	newWindow->show(); // enter "Real Time Check" window
}

void driverStatusCheckWindowClass::on_twoClass_clicked()
{
	this->hide();
	newWindow = new realTimeCheckWindowClass();
	newWindow->svmType = 0;
	newWindow->show(); // enter "Real Time Check" window
}

void driverStatusCheckWindowClass::writeTrainLabel_twoClass()
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

void driverStatusCheckWindowClass::readTrainData_twoClass(const char file[], const char file2[], const char file3[], const char file4[],
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

void driverStatusCheckWindowClass::run_twoClass()
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

		// save model
		svm_save_model("model.txt", model);

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

void driverStatusCheckWindowClass::setPara_twoClass()
{
	nu = 0.30;
	gamma = 0.50;
	coef0 = 0.00;
	degree = 3.00;
}

void driverStatusCheckWindowClass::generateFileName_twoClass()
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

void driverStatusCheckWindowClass::writeTrainLabel_oneClass()
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

void driverStatusCheckWindowClass::readTrainData_oneClass(const char file[], const char file2[], const char file3[],
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
	while (!indata.eof()) 	{

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

void driverStatusCheckWindowClass::run_oneClass()
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

		// save model
		svm_save_model("model.txt", model);

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

void driverStatusCheckWindowClass::setPara_oneClass() // set parameters for one-class-SVM
{
	nu = 0.05;
	gamma = 0.50;
	coef0 = 0;
	degree = 3;
}

void driverStatusCheckWindowClass::generateFileName_oneClass()
{
	char tmp[2];
	string strSubNo;
	sprintf(tmp, "%d", subNo);
	strSubNo = tmp;

	trainDataFile1 = "\.\\data\\s" + strSubNo + "b1.txt";
	trainDataFile2 = "\.\\data\\s" + strSubNo + "b2.txt";
	trainDataFile3 = "\.\\data\\s" + strSubNo + "b3.txt";
}

void driverStatusCheckWindowClass::setSvmBtnColor()
{
	setBtnQss(ui.oneClass, "#01CBCB", "#FFFFFF", "#01F5F5", "#E5FEFF", "#019FA0", "#A0DAFB");
	setBtnQss(ui.twoClass, "#01CBCB", "#FFFFFF", "#01F5F5", "#E5FEFF", "#019FA0", "#A0DAFB");
}

void driverStatusCheckWindowClass::setBtnQss(QPushButton *btn,
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