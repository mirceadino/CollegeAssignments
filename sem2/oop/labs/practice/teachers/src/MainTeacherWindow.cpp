#include "MainTeacherWindow.h"
#include <cstdio>
#include <QtGui/QMessageBox>
#include "Utils.h"

MainTeacherWindow::MainTeacherWindow(GradingController& ctrl) :
    QMainWindow(0), ctrl_(ctrl) {

  ui_.setupUi(this);
  setConnections();
  populateList();
}

struct sortingCriteria {
    bool operator()(const Student& A, const Student& B) const {
      if (A.getGroup() == B.getGroup())
        return A.getName() < B.getName();
      return A.getGroup() < B.getGroup();
    }
};

void MainTeacherWindow::populateList() {
  if (ui_.studentsList->count())
    ui_.studentsList->clear();

  auto students = ctrl_.getStudents();
  sort(students.begin(), students.end(), sortingCriteria());

  for (auto stud : students) {
    char buffer[500];

    sprintf(buffer, "%d | %s  | Group: %d", stud.getId(), stud.getName().c_str(), stud.getGroup());

    ui_.studentsList->addItem(QString(buffer));
  }

  ui_.studentsList->setCurrentRow(0);
}

void MainTeacherWindow::setConnections() {
  connect(ui_.addStudentButton, SIGNAL(clicked()), this, SLOT(addStudent()));
  connect(ui_.removeStudentButton, SIGNAL(clicked()), this, SLOT(removeStudent()));
}

MainTeacherWindow::~MainTeacherWindow() {
}

void MainTeacherWindow::addStudent() {
  std::string bufferName = ui_.lineEditName->displayText().toStdString();
  std::string name = bufferName;

  std::string bufferGroup = ui_.lineEditGroup->displayText().toStdString();
  int group = str_to_int(bufferGroup);

  QMessageBox msgBox;
  std::string buffer = "You want to add student: \n";
  buffer += "Name: " + bufferName + "\n";
  buffer += "Group: " + bufferGroup;

  msgBox.setText(buffer.c_str());
  msgBox.setInformativeText("Are you sure?");
  msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::Yes);
  int ret = msgBox.exec();

  if (ret == QMessageBox::Yes) {
    ctrl_.addStudent(name, group);
    populateList();
  }
}

void MainTeacherWindow::removeStudent() {
  if (ui_.studentsList->currentRow() < 0 || ui_.studentsList->currentRow() >= ui_.studentsList->count()) {
    QMessageBox msgBox;
    std::string buffer = "Select a student if you want to remove one.";
    msgBox.setText(buffer.c_str());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
    return;
  }

  std::string allLine = ui_.studentsList->currentItem()->text().toStdString();
  int id;
  sscanf(allLine.c_str(), "%d", &id);

  Student stud = ctrl_.findStudent(id);

  char buff[400];
  QMessageBox msgBox;
  std::string buffer = "You want to remove student: \n";
  sprintf(buff, "%d", stud.getId());
  buffer += "Id: " + std::string(buff) + "\n";
  buffer += "Name: " + stud.getName() + "\n";
  sprintf(buff, "%d", stud.getGroup());
  buffer += "Group: " + std::string(buff) + "\n";
  sprintf(buff, "%.2f", stud.getGrade());
  buffer += "Grade: " + std::string(buff) + "\n";
  buffer += "Grader: " + stud.getGrader();

  msgBox.setText(buffer.c_str());
  msgBox.setInformativeText("Are you sure?");
  msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::Yes);
  int ret = msgBox.exec();

  if (ret == QMessageBox::Yes) {
    ctrl_.removeStudent(id);
    populateList();
  }
}
