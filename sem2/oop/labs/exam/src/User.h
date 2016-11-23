#ifndef USER_H_
#define USER_H_

#include "IssueException.h"
#include <string>
#include <iostream>
#include <fstream>

class User {
  public:
    User(std::string name = "", std::string type = "");
    const std::string& getName() const;
    void setName(const std::string& name);
    const std::string& getType() const;
    void setType(const std::string& type);

  protected:
    std::string name_;
    std::string type_;
};

std::istream& operator>>(std::istream& in, User& I);
std::ostream& operator<<(std::ostream& out, User& I);

#endif /* USER_H_ */
