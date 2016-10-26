#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Programmer {
  public:
    Programmer(int id = 0, std::string name = "");

    int getId() const;
    void setId(int id);
    const std::string& getName() const;
    void setName(const std::string& name);

  protected:
    int id_;
    std::string name_;
};

std::istream& operator>>(std::istream& in, Programmer& P);
std::ostream& operator<<(std::ostream& out, Programmer& P);

#endif /* PROGRAMMER_H_ */
