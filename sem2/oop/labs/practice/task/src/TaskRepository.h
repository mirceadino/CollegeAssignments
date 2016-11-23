#ifndef TASKREPOSITORY_H_
#define TASKREPOSITORY_H_

#include <vector>
#include <random>
#include "Task.h"
#include "TaskException.h"

class TaskRepository {
  public:
    TaskRepository();
    TaskRepository(std::string filename);
    ~TaskRepository();
    void add(Task T);
    void remove(int identifier);
    Task& find(int identifier);
    std::vector<Task>& all();

  protected:
    std::vector<Task> tasks_;
    std::string filename_;
    std::random_device rand_;
};

#endif /* TASKREPOSITORY_H_ */
