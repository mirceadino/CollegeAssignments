#include "AdminWindow.h"
#include <QtGui/QMessageBox>
#include <cstdio>

using namespace std;

AdminWindow::AdminWindow(Admin& admin) :
    QMainWindow(0), admin_(admin) {

  ui_.setupUi(this);
  setConnections();
  populateList();
}

void AdminWindow::populateList() {
  ui_.users->clear();

  for (auto user : admin_.getUsers())
    ui_.users->addItem(QString(user.c_str()));
}

void AdminWindow::setConnections() {
  connect(ui_.enter, SIGNAL(clicked()), this, SLOT(addUser()));
  connect(ui_.username, SIGNAL(returnPressed()), this, SLOT(addUser()));
}

void AdminWindow::update() {
  populateList();
}

std::string AdminWindow::getName() {
  return "";
}

AdminWindow::~AdminWindow() {
}

void AdminWindow::addUser() {
  string username = ui_.username->displayText().toStdString();

  try {
    admin_.addUser(username);
    ui_.username->clear();
    populateList();

  } catch (runtime_error& err) {
    QMessageBox msgBox;
    msgBox.setText(err.what());
    msgBox.exec();
  }
}
