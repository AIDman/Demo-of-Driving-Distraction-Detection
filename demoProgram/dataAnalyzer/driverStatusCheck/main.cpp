#include "driverStatusCheck.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//driverStatusCheckWindowClass w;
	realTimeCheckWindowClass w;
	w.show();
	return a.exec();
}
