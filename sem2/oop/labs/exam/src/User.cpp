#include "User.h"
#include <sstream>

using namespace std;

User::User(std::string name, std::string type) :
    name_(name), type_(type) {
}

const std::string& User::getName() const {
  return name_;
}

void User::setName(const std::string& name) {
  name_ = name;
}

const std::string& User::getType() const {
  return type_;
}

void User::setType(const std::string& type) {
  type_ = type;
}

std::istream& operator >>(std::istream& in, User& I) {
  string line;

  if (!getline(in, line))
    return in;

  if (line.empty())
    return in;

  string name;
  string type;

  istringstream ss(line);
  getline(ss, name, '|');
  getline(ss, type, '|');

  I.setName(name);
  I.setType(type);

  return in;
}

std::ostream& operator <<(std::ostream& out, User& I) {
  ostringstream ss;

  ss << I.getName() << "|";
  ss << I.getType() << "|\n";

  out << ss.str();

  return out;
}
