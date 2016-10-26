#include "TaskRepository.h"
#include <algorithm>

using namespace std;

TaskRepository::TaskRepository() {
}

TaskRepository::TaskRepository(std::string filename) :
    filename_(filename) {

  ifstream fin(filename_);
  Task T("");

  while (fin >> T)
    add(T);

  fin.close();
}

TaskRepository::~TaskRepository() {
  if (filename_.empty())
    return;

  ofstream fout(filename_);

  for (auto T : tasks_)
    fout << T << "\n";

  fout.close();
}

void TaskRepository::add(Task T) {
  T.setIdentifier(rand_());
  tasks_.push_back(T);
}

void TaskRepository::remove(int identifier) {
  for (auto& T : tasks_)
    if (T.getIdentifier() == identifier) {
      swap(tasks_.back(), T);
      tasks_.pop_back();
      return;
    }
}

Task& TaskRepository::find(int identifier) {
  for (auto& T : tasks_)
    if (T.getIdentifier() == identifier)
      return T;

  throw TaskException("No task with such identifier.");
}

std::vector<Task>& TaskRepository::all() {
  return tasks_;
}
