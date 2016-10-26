#include "GradingRepository.h"
#include <stdexcept>
#include <iostream>

GradingRepository::GradingRepository() {
}

GradingRepository::GradingRepository(std::string studfile, std::string teachfile) {
  Student stud;
  Teacher teach;

  std::ifstream sin(studfile_ = "students.txt");
  std::ifstream tin(teachfile_ = "teachers.txt");

  while (sin >> stud)
    students_.push_back(stud);

  while (tin >> teach)
    teachers_.push_back(teach);

  sin.close();
  tin.close();
}

GradingRepository::~GradingRepository() {
  std::ofstream sout(studfile_);
  std::ofstream tout(teachfile_);

  for (auto stud : students_)
    sout << stud << "\n";

  for (auto teach : teachers_)
    tout << teach << "\n";

  sout.close();
  tout.close();
}

void GradingRepository::addStudent(const Student& student) {
  for (auto stud : students_)
    if (stud.getId() == student.getId())
      throw GradingException("Duplicate ID among students.");

  students_.push_back(student);
}

void GradingRepository::removeStudent(int id) {
  for (auto& stud : students_)
    if (stud.getId() == id) {
      std::swap(students_.back(), stud);
      students_.pop_back();
      return;
    }

  throw GradingException("Student with such ID doesn't exist.");
}

bool GradingRepository::isStudent(int id) {
  for (auto& stud : students_)
    if (stud.getId() == id)
      return true;
  return false;
}

bool GradingRepository::isTeacher(std::string name) {
  for (auto& teach : teachers_)
    if (teach.getName() == name)
      return true;
  return false;
}

std::vector<Student> &GradingRepository::getStudents() {
  return students_;
}

std::vector<Teacher> &GradingRepository::getTeachers() {
  return teachers_;
}
