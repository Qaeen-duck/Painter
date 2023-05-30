#include "Paint.h"
#include "LayerManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Paint w;
	LayerManager layerManager;
	w.setCentralWidget(&layerManager);
	w.show();
	return a.exec();
}
