#include <stdexcept>

#include "Controller.h"

Controller::Controller(Repository* repo) :
		repository_(repo) {
}

Bill Controller::findBill(std::string number) {
	for (auto bill : repository_->getAll())
		if (bill.getSerialNumber() == number)
			return bill;

	throw std::runtime_error("Bill doesn't exist.");
}

double Controller::computeSumUnpaid(std::string company) {
	double sum = 0.0;
	bool exists = false;

	for (auto bill : repository_->getAll()) {
		if (bill.getCompanyName() == company)
			exists = true;
		if (bill.getCompanyName() == company && !bill.isPaid())
			sum += bill.getSum();
	}

	if (!exists)
		throw std::runtime_error("Company doesn't exist");

	return sum;
}

void Controller::sortAll() {
	repository_->sort();
}

std::vector<Bill> Controller::getAll() {
	return repository_->getAll();
}
