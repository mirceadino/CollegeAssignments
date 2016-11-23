#include <QtGui/QApplication>
#include "App.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  testController();

  ifstream fin("genes.txt");
  Repository repo(fin);
  Controller ctrl(repo);
  QApplication a(argc, argv);

  App app(ctrl);
  app.show();

  return a.exec();
}
