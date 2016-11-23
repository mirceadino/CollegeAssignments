#include "Task.h"

Task::Task(std::string description, std::string status, int id) :
    description_(description), status_(status), programmerId_(id), identifier_(-1) {
}

const std::string& Task::getDescription() const {
  return description_;
}

void Task::setDescription(const std::string& description) {
  description_ = description;
}

int Task::getProgrammerId() const {
  return programmerId_;
}

void Task::setProgrammerId(int programmerId) {
  programmerId_ = programmerId;
}

const std::string& Task::getStatus() const {
  return status_;
}

void Task::setStatus(const std::string& status) {
  status_ = status;
}

int Task::getIdentifier() const {
  return identifier_;
}

void Task::setIdentifier(int identifier) {
  identifier_ = identifier;
}

bool Task::operator ==(const Task& that) const {
  return (description_ == that.description_ && status_ == that.status_ && programmerId_ == that.programmerId_);
}

bool Task::operator <(const Task& that) const {
  int sa = (status_ == "open") ? 0 : ((status_ == "in progress") ? 1 : 2);
  int sb = (that.status_ == "open") ? 0 : ((that.status_ == "in progress") ? 1 : 2);
  return sa < sb;
}

std::istream& operator >>(std::istream& in, Task& T) {
  std::string entry;

  if (!(getline(in, entry)))
    return in;

  std::istringstream ss(entry);
  std::string descriptionbuffer;
  std::string statusbuffer;
  std::string idbuffer;

  getline(ss, descriptionbuffer, '|');
  getline(ss, statusbuffer, '|');
  getline(ss, idbuffer, '|');

  T.setDescription(descriptionbuffer);
  T.setStatus(statusbuffer);
  T.setProgrammerId(stoi(idbuffer));

  return in;
}

std::ostream& operator <<(std::ostream& out, Task& T) {
  char buffer[500];
  sprintf(buffer, "%s|%s|%d", T.getDescription().c_str(), T.getStatus().c_str(), T.getProgrammerId());
  out << buffer;
  return out;
}
