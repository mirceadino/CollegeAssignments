#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Task {
  public:
    Task(std::string description, std::string status = "open", int id = 0);

    const std::string& getDescription() const;
    void setDescription(const std::string& description);
    int getProgrammerId() const;
    void setProgrammerId(int programmerId);
    const std::string& getStatus() const;
    void setStatus(const std::string& status);
    int getIdentifier() const;
    void setIdentifier(int identifier);

    bool operator==(const Task& that) const;
    bool operator<(const Task& that) const;

  protected:
    std::string description_;
    std::string status_;
    int programmerId_;
    int identifier_;
};

std::istream& operator>>(std::istream& in, Task& T);
std::ostream& operator<<(std::ostream& out, Task& T);

#endif /* TASK_H_ */
