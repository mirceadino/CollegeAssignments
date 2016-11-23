#include "Programmer.h"

Programmer::Programmer(int id, std::string name) :
    id_(id), name_(name) {
}

int Programmer::getId() const {
  return id_;
}

void Programmer::setId(int id) {
  id_ = id;
}

const std::string& Programmer::getName() const {
  return name_;
}

void Programmer::setName(const std::string& name) {
  name_ = name;
}

std::istream& operator >>(std::istream& in, Programmer& P) {
  std::string entry;

  if (!(getline(in, entry)))
    return in;

  std::istringstream ss(entry);
  std::string idbuffer;
  std::string namebuffer;

  getline(ss, idbuffer, '|');
  getline(ss, namebuffer, '|');

  P.setId(stoi(idbuffer));
  P.setName(namebuffer);

  return in;
}

std::ostream& operator <<(std::ostream& out, Programmer& P) {
  char buffer[500];
  sprintf(buffer, "%d|%s", P.getId(), P.getName().c_str());
  out << buffer;
  return out;
}
