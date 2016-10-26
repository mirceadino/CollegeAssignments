#include <algorithm>

#include "Repository.h"

Repository::Repository() {
}

Repository::Repository(std::istream& in) {
	Bill b;
	while (in >> b)
		bills_.push_back(b);
}

void Repository::sort() {
	std::sort(bills_.begin(), bills_.end());
}

std::vector<Bill> Repository::getAll() {
	return bills_;
}
