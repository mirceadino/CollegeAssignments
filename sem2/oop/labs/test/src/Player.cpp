#include "Player.h"
#include <cstdio>

Player::Player() :
		name_(""), nationality_(""), team_(""), goals_(-1) {
}

Player::Player(std::string name, std::string nationality, std::string team, int goals) :
		name_(name), nationality_(nationality), team_(team), goals_(goals) {
}

Player::Player(const Player& that) :
		name_(that.name_), nationality_(that.nationality_), team_(that.team_), goals_(that.goals_) {
}

Player& Player::operator=(const Player& that) {
	this->name_ = that.name_;
	this->nationality_ = that.nationality_;
	this->team_ = that.team_;
	this->goals_ = that.goals_;
	return *this;
}

Player::~Player() {
}

bool Player::isValid() const {
	if (this->nationality_.size() != 3)
		return false;

	if (this->goals_ < 0)
		return false;
	return true;
}

std::string Player::getName() const {
	return this->name_;
}

std::string Player::getNationality() const {
	return this->nationality_;
}

std::string Player::getTeam() const {
	return this->team_;
}

int Player::getGoals() const {
	return this->goals_;
}

bool Player::operator==(const Player& that) const {
	return this->name_ == that.name_ && this->nationality_ == that.nationality_ && this->team_ == that.team_ && this->goals_ == that.goals_;
}

std::string Player::toString() const {
	char str[300];
	sprintf(str, "%s | %s | %s | %d", this->name_.c_str(), this->nationality_.c_str(), this->team_.c_str(), this->goals_);
	return std::string(str);
}

bool Player::operator<(const Player& that) const {
	return this->goals_ < that.goals_;
}
