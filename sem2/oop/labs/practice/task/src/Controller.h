#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Programmer.h"
#include "TaskRepository.h"
#include "Observer.h"

class Controller: public Subject {
  public:
    Controller(TaskRepository& repo);
    ~Controller();
    void addTask(std::string description);
    void removeTask(int identifier);
    void startTask(int identifier, Programmer& programmer);
    void finishTask(int identifier, Programmer& programmer);
    std::vector<Task> getTasks();

  protected:
    TaskRepository& repo_;
};

#endif /* CONTROLLER_H_ */
