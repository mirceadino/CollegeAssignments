#include <QtGui/QApplication>
#include "Controller.h"
#include "ProgrammerWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  TaskRepository taskRepo("tasks.txt");
  Controller ctrl(taskRepo);

  Programmer P;
  ifstream fin("programmers.txt");
  while (fin >> P) {
    ProgrammerWindow* pw = new ProgrammerWindow(ctrl, P);
    ctrl.addObserver(pw);
    pw->show();
  }

  return a.exec();
}

