#include <QtGui/QApplication>
#include "AdminWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  Admin admin;

  AdminWindow aw(admin);
  admin.addObserver(&aw);
  aw.show();

  return a.exec();
}
