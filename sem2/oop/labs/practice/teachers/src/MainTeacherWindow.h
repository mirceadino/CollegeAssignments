#ifndef MAINTEACHER_H_
#define MAINTEACHER_H_

#include <QtGui/QMainWindow>
#include "GradingController.h"
#include "Observer.h"
#include "ui_subject.h"

class MainTeacherWindow: public QMainWindow {
  Q_OBJECT

  public:
    MainTeacherWindow(GradingController& ctrl);
    void populateList();
    void setConnections();
    ~MainTeacherWindow();

  protected:
    GradingController& ctrl_;
    Ui::MainWindow ui_;

  private slots:
    void addStudent();
    void removeStudent();
};

#endif /* MAINTEACHER_H_ */
