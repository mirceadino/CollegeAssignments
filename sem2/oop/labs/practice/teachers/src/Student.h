#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <fstream>

class Student {
  public:
    Student(int id = -1, std::string name = "-", int group = -1, double grade = 1.0, std::string grader = "");

    double getGrade() const;
    void setGrade(double grade);

    const std::string& getGrader() const;
    void setGrader(const std::string& grader);

    int getGroup() const;
    void setGroup(int group);

    int getId() const;
    void setId(int id);

    const std::string& getName() const;
    void setName(const std::string& name);

  protected:
    int id_;
    std::string name_;
    int group_;
    double grade_;
    std::string grader_;
};

std::istream& operator>>(std::istream& in, Student& stud);
std::ostream& operator<<(std::ostream& out, Student& stud);

#endif /* STUDENT_H_ */
