#include "Student.h"
#include "Utils.h"
#include <iomanip>
#include <cstdio>
#include <string>

Student::Student(int id, std::string name, int group, double grade, std::string grader) :
    id_(id), name_(name), group_(group), grade_(grade), grader_(grader) {
}

double Student::getGrade() const {
  return grade_;
}

void Student::setGrade(double grade) {
  grade_ = grade;
}

const std::string& Student::getGrader() const {
  return grader_;
}

void Student::setGrader(const std::string& grader) {
  grader_ = grader;
}

int Student::getGroup() const {
  return group_;
}

void Student::setGroup(int group) {
  group_ = group;
}

int Student::getId() const {
  return id_;
}

void Student::setId(int id) {
  id_ = id;
}

const std::string& Student::getName() const {
  return name_;
}

void Student::setName(const std::string& name) {
  name_ = name;
}

std::istream& operator >>(std::istream& in, Student& stud) {
  std::string buffer = "";
  char separator = '|';

  if (!(getline(in, buffer))) return in;

  std::vector<std::string> tokens = tokenize(buffer, separator);
  if (tokens.size() != 5) return in;

  int id = str_to_int(tokens[0]);
  std::string name = tokens[1];
  int group = str_to_int(tokens[2]);
  double grade = str_to_double(tokens[3]);
  std::string grader = tokens[4];

  stud = Student(id, name, group, grade, grader);

  return in;
}

std::ostream& operator <<(std::ostream& out, Student& stud) {
  char separator = '|';

  out << stud.getId() << separator;
  out << stud.getName() << separator;
  out << stud.getGroup() << separator;
  out << std::fixed << std::setprecision(4) << stud.getGrade() << separator;
  out << stud.getGrader() << separator;

  return out;
}
