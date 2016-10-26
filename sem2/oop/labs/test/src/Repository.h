#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <vector>
#include "Player.h"

class Repository {
	public:
		Repository();

		/* Adds a player to the repository.
		 * Parameters: player - player to be added
		 * Return: 1 if player was added, 0 otherwise */
		int add(const Player& player);
		int remove(const Player& player);
		Player& findByName(const std::string& name);
		bool find(const Player& player);
		std::vector<Player> getAllPlayers() const;
		int size() const;

	private:
		std::vector<Player> players_;
};

#endif /* REPOSITORY_H_ */
