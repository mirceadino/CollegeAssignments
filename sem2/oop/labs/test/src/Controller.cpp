#include "Controller.h"
#include <algorithm>

Controller::Controller(const Repository& repo) :
		repo_(repo) {
}

int Controller::add(std::string name, std::string nationality, std::string team, int goals) {
	Player p(name, nationality, team, goals);
	if (!p.isValid())
		return false;
	return this->repo_.add(p);
}

int Controller::remove(std::string& name) {
	Player p = this->repo_.findByName(name);
	return this->repo_.remove(p);
}

std::vector<Player> Controller::getAllPlayers() const {
	return this->repo_.getAllPlayers();
}

std::vector<Player> Controller::getPlayerByNationalitySorted(std::string nationality) const {
	std::vector<Player> all = this->repo_.getAllPlayers();
	std::vector<Player> answer;

	for (unsigned int i = 0; i < all.size(); i++)
		if (all[i].getNationality() == nationality)
			answer.push_back(all[i]);

	std::sort(answer.begin(), answer.end());

	return answer;
}
