#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Repository.h"

class Controller {
public:
	Controller(Repository* repo);

	Bill findBill(std::string number);
	double computeSumUnpaid(std::string company);
	void sortAll();
	std::vector<Bill> getAll();

private:
	Repository* repository_;
};

#endif /* CONTROLLER_H_ */
