#include "ProgrammerWindow.h"
#include <cstdio>
#include <QtGui/QMessageBox>

using namespace std;

ProgrammerWindow::ProgrammerWindow(Controller& ctrl, Programmer& programmer) :
    QMainWindow(0), ctrl_(ctrl), programmer_(programmer) {

  ostringstream ss;
  ss << programmer_.getName() << " (" << programmer_.getId() << ")";

  ui_.setupUi(this, ss.str());

  setConnections();
  populateList();
}

ProgrammerWindow::~ProgrammerWindow() {
}

void ProgrammerWindow::update() {
  populateList();
}

void ProgrammerWindow::populateList() {
  ui_.tasks->clear();

  tasks_ = ctrl_.getTasks();
  sort(tasks_.begin(), tasks_.end());

  for (auto task : tasks_) {
    char buffer[500];
    sprintf(buffer, "%s | %s | %d", task.getDescription().c_str(), task.getStatus().c_str(), task.getProgrammerId());
    ui_.tasks->addItem(QString(buffer));
  }
}

void ProgrammerWindow::setConnections() {
  connect(ui_.addButton, SIGNAL(clicked()), this, SLOT(add()));
  connect(ui_.removeButton, SIGNAL(clicked()), this, SLOT(remove()));
  connect(ui_.startButton, SIGNAL(clicked()), this, SLOT(start()));
  connect(ui_.finishButton, SIGNAL(clicked()), this, SLOT(finish()));
}

void ProgrammerWindow::displayWarning(string message) {
  QMessageBox msgBox;
  msgBox.setText(message.c_str());
  msgBox.exec();
}

void ProgrammerWindow::remove() {
  int index = ui_.tasks->currentRow();

  if (index < 0 || index >= ui_.tasks->count()) {
    displayWarning("Select a task to remove.");
    return;
  }

  try {
    ctrl_.removeTask(tasks_[index].getIdentifier());

  } catch (TaskException& err) {
    displayWarning(err.what());
  }
}

void ProgrammerWindow::add() {
  std::string description = ui_.description->displayText().toStdString();

  try {
    ctrl_.addTask(description);
    ui_.description->clear();

  } catch (TaskException& err) {
    displayWarning(err.what());
  }
}

void ProgrammerWindow::start() {
  int index = ui_.tasks->currentRow();

  if (index < 0 || index >= ui_.tasks->count()) {
    displayWarning("Select a task to start.");
    return;
  }

  try {
    ctrl_.startTask(tasks_[index].getIdentifier(), programmer_);

  } catch (TaskException& err) {
    displayWarning(err.what());
  }
}

void ProgrammerWindow::finish() {
  int index = ui_.tasks->currentRow();

  if (index < 0 || index >= ui_.tasks->count()) {
    displayWarning("Select a task to finish.");
    return;
  }

  try {
    ctrl_.finishTask(tasks_[index].getIdentifier(), programmer_);

  } catch (TaskException& err) {
    displayWarning(err.what());
  }
}
