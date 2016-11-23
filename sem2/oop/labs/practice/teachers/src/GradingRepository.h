#ifndef GRADINGREPOSITORY_H_
#define GRADINGREPOSITORY_H_

#include "Student.h"
#include "Teacher.h"
#include "GradingException.h"

class GradingRepository {
  public:
    GradingRepository();
    GradingRepository(std::string studfile, std::string teachfile);
    ~GradingRepository();
    void addStudent(const Student& student);
    void removeStudent(int id);
    bool isStudent(int id);
    bool isTeacher(std::string name);
    std::vector<Student>& getStudents();
    std::vector<Teacher>& getTeachers();

  protected:
    std::vector<Student> students_;
    std::vector<Teacher> teachers_;
    std::string studfile_;
    std::string teachfile_;
};

#endif /* GRADINGREPOSITORY_H_ */
