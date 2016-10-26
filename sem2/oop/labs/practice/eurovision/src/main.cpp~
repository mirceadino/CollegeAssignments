#include <iostream>

#include <QtGui/QApplication>
#include "App.h"

using namespace std;

int main(int argc, char** argv) {
	ifstream fin("countries.txt");

	QApplication ceplm(argc, argv);
	Repository repo(fin);
	Controller ctrl(&repo);

	App app(&ctrl);
	app.show();

	return ceplm.exec();
}
