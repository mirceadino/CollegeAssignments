#ifndef GRADINGCONTROLLER_H_
#define GRADINGCONTROLLER_H_

#include "GradingRepository.h"
#include "Observer.h"

class GradingController: public Subject {
  public:
    GradingController(GradingRepository& repo);
    ~GradingController();
    Student& findStudent(int id);
    Teacher& findTeacher(std::string name);
    void addStudent(std::string name, int group);
    void removeStudent(int id);
    void gradeStudent(int id, std::string teacher, double grade);
    std::vector<Student>& getStudents();
    std::vector<Teacher>& getTeachers();
    std::vector<Student> getStudentsOfTeacher(std::string name);

  protected:
    GradingRepository& repo_;
    int idCounter_;
};

#endif /* GRADINGCONTROLLER_H_ */
