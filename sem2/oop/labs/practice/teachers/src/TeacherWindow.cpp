#include "TeacherWindow.h"
#include "Utils.h"
#include <QtGui/QMessageBox>

using namespace std;

TeacherWindow::TeacherWindow(GradingController& ctrl, Teacher& teacher) :
    QMainWindow(0), ctrl_(ctrl), teacher_(teacher) {

  ui_.setupUi(this, teacher_.getName());
  setConnections();
  update();
}

TeacherWindow::~TeacherWindow() {
}

void TeacherWindow::update() {
  populateList();
}

struct sortingCriteria {
    bool operator()(const Student& A, const Student& B) const {
      if (A.getGroup() == B.getGroup())
        return A.getName() < B.getName();
      return A.getGroup() < B.getGroup();
    }
};

void TeacherWindow::populateList() {
  if (ui_.listWidget->count())
    ui_.listWidget->clear();

  auto students = ctrl_.getStudentsOfTeacher(teacher_.getName());
  sort(students.begin(), students.end(), sortingCriteria());

  for (auto stud : students) {
    char buffer[500];

    sprintf(buffer, "%d | %s  | Group: %d | Grade: %.2f | Grader: %s", stud.getId(), stud.getName().c_str(), stud.getGroup(), stud.getGrade(), stud.getGrader().c_str());

    ui_.listWidget->addItem(QString(buffer));
  }

  ui_.listWidget->setCurrentRow(0);
}

void TeacherWindow::setConnections() {
  connect(ui_.pushButton, SIGNAL(clicked()), this, SLOT(gradeStudent()));
}

void TeacherWindow::gradeStudent() {
  if (ui_.listWidget->currentRow() < 0 || ui_.listWidget->currentRow() >= ui_.listWidget->count()) {
    QMessageBox msgBox;
    std::string buffer = "Select a student if you want to grade one.";
    msgBox.setText(buffer.c_str());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
    return;
  }

  std::string allLine = ui_.listWidget->currentItem()->text().toStdString();
  int id;
  sscanf(allLine.c_str(), "%d", &id);

  std::string bufferGrade = ui_.lineEdit->displayText().toStdString();
  double grade = str_to_double(bufferGrade);

  try {
    ctrl_.gradeStudent(id, teacher_.getName(), grade);
  } catch (GradingException& err) {
    QMessageBox msgBox;
    std::string buffer = err.what();
    msgBox.setText(buffer.c_str());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
  }
}
