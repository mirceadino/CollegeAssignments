#include <QtGui/QApplication>
#include <bits/stdc++.h>
#include "UserWindow.h"
#include "IssueController.h"

using namespace std;

int main(int argc, char **argv) {
  QApplication a(argc, argv);

  test_controller();

  IssueRepository repo("issues.txt", "users.txt");
  IssueController ctrl(repo);

  vector<UserWindow*> windows;

  for (auto user : repo.allUsers())
    windows.push_back(new UserWindow(ctrl, user));

  for (auto window : windows) {
    ctrl.attachObserver(window);
    window->show();
  }

  return a.exec();
}
