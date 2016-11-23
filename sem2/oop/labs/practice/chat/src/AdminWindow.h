#ifndef ADMINWINDOW_H_
#define ADMINWINDOW_H_

#include <QtGui/QMainWindow>
#include "Admin.h"
#include "Observer.h"
#include "ui_admin.h"

class AdminWindow: public QMainWindow, public Observer {
  Q_OBJECT

  public:
    AdminWindow(Admin& admin);
    ~AdminWindow();
    void populateList();
    void setConnections();
    void update() override;
    std::string getName() override;

  protected:
    Admin& admin_;
    Ui::AdminMainWindow ui_;

  private slots:
    void addUser();
};

#endif /* ADMINWINDOW_H_ */
