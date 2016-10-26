#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "Country.h"

class Repository {
public:
	Repository() :
			elements_(std::vector<Country>()) {
	}

	Repository(std::istream& in) {
		Country C;
		while (in >> C)
			elements_.push_back(C);
	}

	int size() const {
		return elements_.size();
	}

	bool empty() const {
		return elements_.empty();
	}

	void clear() {
		elements_.clear();
	}

	bool exists(const std::string& name) {
		for (auto &country : elements_)
			if (country.getName() == name)
				return true;

		return false;
	}

	void sort() {
		std::sort(elements_.begin(), elements_.end());
	}

	Country& find(const std::string& name) {
		if (!exists(name))
			throw new std::runtime_error("Inexistent country.");

		for (auto &country : elements_)
			if (country.getName() == name)
				return country;

		// Control never reaches the following line.
		return *(new Country());
	}

	void append(const Country C) {
		if (exists(C.getName()))
			throw new std::runtime_error("Country already exists.");

		elements_.push_back(C);
	}

	void erase(const std::string& name) {
		Country& country = find(name);

		std::swap(elements_.back(), country);
		elements_.pop_back();
	}

	std::vector<Country> getAll() {
		return elements_;
	}

private:
	std::vector<Country> elements_;
};

#endif /* REPOSITORY_H_ */
