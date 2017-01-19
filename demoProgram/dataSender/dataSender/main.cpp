#include "datasender.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	dataSender w;
	w.show();
	return a.exec();
}
