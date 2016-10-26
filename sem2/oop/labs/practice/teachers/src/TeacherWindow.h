#ifndef TEACHERWINDOW_H_
#define TEACHERWINDOW_H_

#include <QtGui/QMainWindow>
#include "ui_observer.h"
#include "Observer.h"
#include "GradingController.h"

class TeacherWindow: public QMainWindow, public Observer {
  Q_OBJECT

  public:
    TeacherWindow(GradingController& ctrl, Teacher& teacher);
    ~TeacherWindow();
    void update();
    void populateList();
    void setConnections();

  protected:
    GradingController& ctrl_;
    Teacher& teacher_;
    OUi::MainWindow ui_;

  private slots:
    void gradeStudent();
};

#endif /* TEACHERWINDOW_H_ */
