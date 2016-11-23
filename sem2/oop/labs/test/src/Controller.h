#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Repository.h"

class Controller {
	public:
		Controller(const Repository& repo);
		int add(std::string name, std::string nationality, std::string team, int goals);
		int remove(std::string& name);
		std::vector<Player> getAllPlayers() const;

		/* Gets the players of a certain nationality, sorted ascendingly (by the number of goals, default comparator for Player).
		 * Parameters: nationality - nationality to filter by
		 * Return: vector of Players respecting the criteria and sorted ascendingly  */
		std::vector<Player> getPlayerByNationalitySorted(std::string nationality) const;

	private:
		Repository repo_;
};

#endif /* CONTROLLER_H_ */
