#include "User.h"
#include <cstdio>

User::User(Admin& admin, std::string username) :
    QMainWindow(0), admin_(admin), username_(username) {

  ui_.setupUi(this, username);
  setConnections();
  populateList();
}

User::~User() {
  admin_.removeUser(this);
}

std::string User::getName() {
  return username_;
}

void User::update() {
  populateList();
}

void User::populateList() {
  ui_.messages->clear();

  for (auto message : admin_.getMessages(20, username_))
    ui_.messages->addItem(QString(message.c_str()));

  ui_.messages->setCurrentRow(ui_.messages->count() - 1);
}

void User::setConnections() {
  connect(ui_.enter, SIGNAL(clicked()), this, SLOT(addMessage()));
  connect(ui_.message, SIGNAL(returnPressed()), this, SLOT(addMessage()));
}

void User::addMessage() {
  std::string message = "[ " + username_ + " ] ";
  std::string buffer(ui_.message->displayText().toStdString());

  if (buffer.find("/me ") == 0) {
    message = buffer;
    message.replace(0, 3, username_);
    if (message.back() != '.')
      message.push_back('.');

  } else
    message += ui_.message->displayText().toStdString();

  admin_.addMessage(message);
  ui_.message->clear();
}
