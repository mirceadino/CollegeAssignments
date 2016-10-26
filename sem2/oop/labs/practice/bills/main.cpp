#include <QtGui/QApplication>
#include "App.h"

using namespace std;

int main(int argc, char** argv) {
	ifstream fin("bills.txt");
	Repository repo(fin);
	Controller ctrl(&repo);

	QApplication a(argc, argv);

	App app(&ctrl);
	app.show();

	return a.exec();
}
