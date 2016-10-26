#include "Admin.h"
#include "User.h"
#include <stdexcept>

using namespace std;

Admin::Admin() :
    Subject() {
}

void Admin::addUser(std::string username) {
  if (username.size() < 3)
    throw runtime_error("Username is too short, length must be at least 3.");

  for (auto user : getUsers())
    if (username == user)
      throw runtime_error("Username already exists, choose a different one.");

  messages_.push_back(username + " has joined.");

  User* user = new User(*this, username);
  this->addObserver(user);
  user->setAttribute(Qt::WA_DeleteOnClose);
  user->show();

  notify();
}

void Admin::removeUser(Observer* user) {
  messages_.push_back(user->getName() + " has exited.");

  this->removeObserver(user);

  notify();
}

void Admin::addMessage(std::string message) {
  messages_.push_back(message);

  notify();
}

std::vector<std::string> Admin::getMessages(int number, std::string username) {
  vector<string> messages;

  for (auto it = messages_.rbegin(); it != messages_.rend() && number; it++, number--) {
    messages.push_back(*it);
    if (*it == (username + " has joined."))
      break;
  }

  reverse(messages.begin(), messages.end());

  return messages;
}

std::vector<std::string> Admin::getUsers() {
  vector<string> users;

  for (auto obs : this->observers_)
    if (!obs->getName().empty())
      users.push_back(obs->getName());

  return users;
}
