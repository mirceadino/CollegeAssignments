#include "Controller.h"

using namespace std;

Controller::Controller(TaskRepository& repo) :
    Subject(), repo_(repo) {
}

Controller::~Controller() {
}

/* Adds a task to the repository. By default, the task will be open and no programmer is assigned to it.
 * GETS: std::string description of the task
 * RETURNS: -
 * EFFECT: If description has at least 3 characters, a task is added to the repository and observers are updated.
 * THROWS: TaskException if description is below 3 characters. */
void Controller::addTask(std::string description) {
  if (description.size() < 3)
    throw TaskException("Description must have at least 3 characters.");

  Task T(description);

  repo_.add(T);
  this->notify();
}

void Controller::removeTask(int identifier) {
  repo_.remove(identifier);
  this->notify();
}

void Controller::startTask(int identifier, Programmer& programmer) {
  Task& T = repo_.find(identifier);

  if (T.getStatus() == "open") {
    T.setStatus("in progress");
    T.setProgrammerId(programmer.getId());
    this->notify();
    return;
  }

  throw TaskException("Task is not open.");
}

void Controller::finishTask(int identifier, Programmer& programmer) {
  Task& T = repo_.find(identifier);

  if (T.getStatus() == "in progress" && T.getProgrammerId() == programmer.getId()) {
    T.setStatus("closed");
    this->notify();
    return;
  }

  if (T.getStatus() == "in progress")
    throw TaskException("Task is not yours to finish.");

  if (T.getStatus() == "closed")
    throw TaskException("Task is already finished.");

  throw TaskException("Task is open, you must start it.");
}

std::vector<Task> Controller::getTasks() {
  return repo_.all();
}
