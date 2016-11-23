#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <vector>

#include "Bill.h"

class Repository {
public:
	Repository();
	Repository(std::istream& in);
	void sort();
	std::vector<Bill> getAll();

private:
	std::vector<Bill> bills_;
};

#endif /* REPOSITORY_H_ */
