#include <QtGui/QApplication>
#include "MainTeacherWindow.h"
#include "TeacherWindow.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  GradingRepository repo("students.txt", "teachers.txt");
  GradingController ctrl(repo);

  vector<TeacherWindow*> tws;

  for (auto& teacher : ctrl.getTeachers()) {
    TeacherWindow* tw = new TeacherWindow(ctrl, teacher);
    ctrl.addObserver(tw);
    tws.push_back(tw);
  }

  for (auto tw : tws)
    tw->show();

  MainTeacherWindow mtw(ctrl);
  mtw.show();

  a.exec();
}
