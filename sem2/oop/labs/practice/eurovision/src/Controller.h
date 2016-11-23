#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <algorithm>
#include <vector>

#include "Repository.h"

class Controller {
public:
	Controller(Repository* repository) :
			repository_(repository) {
	}

	int getNumberOfCountries() const {
		return repository_->size();
	}

	void clearRepository() {
		repository_->clear();
	}

	Country& getCountry(const std::string name) {
		return repository_->find(name);
	}

	void upvoteCountry(const std::string name) {
		Country& c = repository_->find(name);
		c.upvote();
	}

	std::vector<Country> getAllCountries() {
		return repository_->getAll();
	}

	void sortByScore() {
		repository_->sort();
	}

private:
	Repository* repository_;
};

#endif /* CONTROLLER_H_ */
