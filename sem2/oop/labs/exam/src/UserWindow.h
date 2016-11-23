#ifndef USERWINDOW_H_
#define USERWINDOW_H_

#include <QtGui/QMainWindow>
#include "ui_user.h"
#include "Observer.h"
#include "IssueController.h"

class UserWindow: public QMainWindow, public Observer {
  Q_OBJECT

  public:
    UserWindow(IssueController& ctrl, User user);
    void update() override;
    void populateList();
    void setConnections();
    void warningBox(std::string message);

  protected:
    IssueController& controller_;
    Ui::MainWindow ui_;
    User user_;
    std::vector<Issue> issues_;

  private slots:
    void add();
    void remove();
    void resolve();
    void enableResolve();
};

#endif /* USERWINDOW_H_ */
