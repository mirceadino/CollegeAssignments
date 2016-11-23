#include "UserWindow.h"
#include <sstream>
#include <QtGui/QMessageBox>

using namespace std;

UserWindow::UserWindow(IssueController& ctrl, User user) :
    QMainWindow(0), controller_(ctrl), user_(user) {

  ui_.setupUi(this);

  ostringstream ss;
  ss << user_.getName();
  ss << " (";
  ss << user_.getType();
  ss << ")";

  this->setWindowTitle(ss.str().c_str());

  if (user_.getType() == "programmer") {
    ui_.resolveButton->setEnabled(true);
    ui_.description->setEnabled(false);
    ui_.addButton->setEnabled(false);
  } else {
    ui_.resolveButton->setEnabled(false);
    ui_.description->setEnabled(true);
    ui_.addButton->setEnabled(true);
  }

  setConnections();
  populateList();
}

void UserWindow::update() {
  populateList();
}

void UserWindow::populateList() {
  ui_.issues->clear();

  issues_ = controller_.getIssues();
  sort(issues_.begin(), issues_.end());

  for (auto i : issues_) {
    ostringstream ss;

    ss << i.getDescription() << " - ";
    ss << i.getStatus() << " - opened by ";
    ss << i.getReporter();
    if (i.getStatus() == "closed")
      ss << " - closed by " << i.getSolver();

    ui_.issues->addItem(QString(ss.str().c_str()));
  }
}

void UserWindow::setConnections() {
  connect(ui_.addButton, SIGNAL(clicked()), this, SLOT(add()));
  connect(ui_.removeButton, SIGNAL(clicked()), this, SLOT(remove()));
  connect(ui_.resolveButton, SIGNAL(clicked()), this, SLOT(resolve()));
  connect(ui_.issues, SIGNAL(itemSelectionChanged()), this, SLOT(enableResolve()));
}

void UserWindow::warningBox(std::string message) {
  QMessageBox msgBox;
  msgBox.setText(message.c_str());
  msgBox.exec();
}

void UserWindow::add() {
  std::string description = ui_.description->displayText().toStdString();

  try {
    controller_.reportIssue(description, user_);

  } catch (IssueException& err) {
    warningBox(err.what());
  }
}

void UserWindow::remove() {
  int index = ui_.issues->currentRow();

  if (index < 0 || index >= ui_.issues->count()) {
    warningBox("Choose an issue to remove.");
    return;
  }

  try {
    Issue I = issues_[index];
    controller_.removeIssue(I.getDescription(), user_);

  } catch (IssueException& err) {
    warningBox(err.what());
  }
}

void UserWindow::resolve() {
  int index = ui_.issues->currentRow();

  if (index < 0 || index >= ui_.issues->count()) {
    warningBox("Choose an issue to resolve.");
    return;
  }

  try {
    Issue I = issues_[index];
    controller_.resolveIssue(I.getDescription(), user_);

  } catch (IssueException& err) {
    warningBox(err.what());
  }
}

void UserWindow::enableResolve() {
  int index = ui_.issues->currentRow();

  ui_.resolveButton->setEnabled(false);

  if (index < 0 || index >= ui_.issues->count())
    return;

  Issue I = issues_[index];

  if (I.getStatus() == "open" && user_.getType() == "programmer")
    ui_.resolveButton->setEnabled(true);
}
