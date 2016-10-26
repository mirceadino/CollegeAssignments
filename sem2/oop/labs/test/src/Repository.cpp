#include "Repository.h"
#include <algorithm>

Repository::Repository() :
		players_(std::vector<Player>()) {
}

#include <iostream>
int Repository::add(const Player& player) {
	if (!(this->findByName(player.getName()) == Player()))
		return 0;

	this->players_.push_back(player);

	return 1;
}

int Repository::remove(const Player& player) {
	if (this->findByName(player.getName()) == Player())
		return 0;

	for (unsigned int i = 0; i < players_.size(); i++)
		if (players_[i] == player) {
			std::swap(this->players_[i], this->players_.back());
			this->players_.pop_back();
			break;
		}

	return 1;
}

bool Repository::find(const Player& player) {
	Player found = this->findByName(player.getName());
	return found == player;
}

Player& Repository::findByName(const std::string& name) {
	for (unsigned int i = 0; i < players_.size(); i++)
		if (players_[i].getName() == name)
			return players_[i];

	return *(new Player);
}

std::vector<Player> Repository::getAllPlayers() const {
	return this->players_;
}

int Repository::size() const {
	return this->players_.size();
}
