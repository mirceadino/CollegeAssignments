#include "Teacher.h"
#include "Utils.h"
#include <cstdio>
#include <string>

Teacher::Teacher(std::string name, std::vector<int> groups) :
    name_(name), groups_(groups) {
}

const std::vector<int>& Teacher::getGroups() const {
  return groups_;
}

void Teacher::setGroups(const std::vector<int>& groups) {
  groups_ = groups;
}

const std::string& Teacher::getName() const {
  return name_;
}

void Teacher::setName(const std::string& name) {
  name_ = name;
}
#include <iostream>

std::istream& operator >>(std::istream& in, Teacher& teach) {
  std::string buffer = "";
  char separator = '|';

  if (!(getline(in, buffer))) return in;

  std::vector<std::string> tokens = tokenize(buffer, separator);
  if (tokens.size() <= 1) return in;

  std::string name = tokens[0];
  std::vector<int> groups;

  for (int i = 1; i < (int) tokens.size(); i++)
    if (!tokens[i].empty()) groups.push_back(str_to_int(tokens[i]));

  teach = Teacher(name, groups);

  return in;
}

std::ostream& operator <<(std::ostream& out, Teacher& teach) {
  char separator = '|';

  out << teach.getName() << separator;

  for (auto group : teach.getGroups())
    out << group << separator;

  return out;
}
