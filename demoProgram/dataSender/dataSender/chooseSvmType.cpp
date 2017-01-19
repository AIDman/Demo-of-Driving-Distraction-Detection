#include "chooseSvmType.h"

chooseSvmTypeWindowClass::chooseSvmTypeWindowClass(QWidget *parent)
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

	hThreadDraw = CreateThread(NULL, 0, ThreadDraw, NULL, 0, NULL); // create a thread
	CloseHandle(hThreadDraw);

	QPalette pe;
	pe.setColor(QPalette::WindowText, RGB(105, 105, 105));
	ui.turnToStopText->setPalette(pe);
	ui.waitText->setPalette(pe);
	ui.restText->setPalette(pe);
	ui.receiveDataText->setPalette(pe);
}

chooseSvmTypeWindowClass::~chooseSvmTypeWindowClass()
{

}

void chooseSvmTypeWindowClass::on_oneClass_clicked()
{
}