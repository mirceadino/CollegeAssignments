#include "GradingController.h"
#include <vector>

GradingController::GradingController(GradingRepository& repo) :
    repo_(repo), idCounter_(100) {
}

GradingController::~GradingController() {
}

Student& GradingController::findStudent(int id) {
  for (auto& stud : repo_.getStudents())
    if (stud.getId() == id)
      return stud;

  throw GradingException("No student with such ID exists");
}

Teacher& GradingController::findTeacher(std::string name) {
  for (auto& teach : repo_.getTeachers())
    if (teach.getName() == name)
      return teach;

  throw GradingException("Teacher with such name doesn't exist.");
}

void GradingController::addStudent(std::string name, int group) {
  while (repo_.isStudent(idCounter_))
    idCounter_++;

  Student stud(idCounter_, name, group);
  repo_.addStudent(stud);

  notify();
}

void GradingController::removeStudent(int id) {
  repo_.removeStudent(id);

  notify();
}

void GradingController::gradeStudent(int id, std::string teacher, double grade) {
  Student& stud = findStudent(id);
  Teacher& teach = findTeacher(teacher);

  if (stud.getGrader().empty()) {
    stud.setGrade(grade);
    stud.setGrader(teach.getName());

    notify();
  } else
    throw GradingException("This student was already graded.");
}

std::vector<Student>& GradingController::getStudents() {
  return repo_.getStudents();
}

std::vector<Teacher>& GradingController::getTeachers() {
  return repo_.getTeachers();
}

std::vector<Student> GradingController::getStudentsOfTeacher(std::string name) {
  const Teacher& teacher = findTeacher(name);
  std::vector<Student> students;

  for (auto stud : getStudents())
    for (auto group : teacher.getGroups())
      if (stud.getGroup() == group)
        students.push_back(stud);

  return students;
}
