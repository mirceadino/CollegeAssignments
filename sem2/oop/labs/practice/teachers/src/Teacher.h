#ifndef TEACHER_H_
#define TEACHER_H_

#include <string>
#include <vector>
#include <fstream>

class Teacher {
  public:
    Teacher(std::string name = "", std::vector<int> groups = std::vector<int>());

    const std::vector<int>& getGroups() const;
    void setGroups(const std::vector<int>& groups);

    const std::string& getName() const;
    void setName(const std::string& name);

  protected:
    std::string name_;
    std::vector<int> groups_;
};

std::istream& operator>>(std::istream& in, Teacher& teach);
std::ostream& operator<<(std::ostream& out, Teacher& teach);

#endif /* TEACHER_H_ */
