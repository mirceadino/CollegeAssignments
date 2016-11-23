#ifndef ADMIN_H_
#define ADMIN_H_

#include "Observer.h"
#include <string>

class Admin: public Subject {
  public:
    Admin();
    void addUser(std::string username);
    void removeUser(Observer* user);
    void addMessage(std::string message);
    std::vector<std::string> getUsers();
    std::vector<std::string> getMessages(int number = 100000, std::string username = "");
    bool isValidUsername(std::string username);

  protected:
    std::vector<std::string> messages_;
};

#endif /* ADMIN_H_ */
