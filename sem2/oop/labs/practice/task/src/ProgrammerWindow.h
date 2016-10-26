#ifndef PROGRAMMERWINDOW_H_
#define PROGRAMMERWINDOW_H_

#include <QtGui/QMainWindow>
#include "Observer.h"
#include "ui_programmer.h"
#include "Programmer.h"
#include "Controller.h"

class ProgrammerWindow: public QMainWindow, public Observer {
  Q_OBJECT

  public:
    ProgrammerWindow(Controller& ctrl, Programmer& programmer);
    ~ProgrammerWindow();
    void update();
    void populateList();
    void setConnections();
    void displayWarning(std::string message);

  protected:
    Controller& ctrl_;
    Programmer programmer_;
    Ui::MainWindow ui_;
    std::vector<Task> tasks_;

  private slots:
    void remove();
    void add();
    void start();
    void finish();
};

#endif /* PROGRAMMERWINDOW_H_ */
