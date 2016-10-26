#ifndef USER_H_
#define USER_H_

#include <QtGui/QMainWindow>
#include "Admin.h"
#include "Observer.h"
#include "ui_user.h"
#include <string>

class User: public QMainWindow, public Observer {
  Q_OBJECT

  public:
    User(Admin& admin, std::string username);
    ~User();
    std::string getName() override;
    void update() override;
    void populateList();
    void setConnections();

  protected:
    Admin& admin_;
    std::string username_;
    Ui::UserWindow ui_;

  private slots:
    void addMessage();
};

#endif /* USER_H_ */
