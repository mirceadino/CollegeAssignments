#include "Bill.h"

Bill::Bill(std::string name, std::string number, double sum, bool paid) :
		companyName_(name), serialNumber_(number), sum_(sum), isPaid_(paid) {
}

std::string Bill::getCompanyName() const {
	return companyName_;
}

void Bill::setCompanyName(const std::string& companyName) {
	companyName_ = companyName;
}

bool Bill::isPaid() const {
	return isPaid_;
}

void Bill::pay() {
	if (!isPaid_)
		isPaid_ = true;
}

void Bill::unpay() {
	if (isPaid_)
		isPaid_ = false;
}

std::string Bill::getSerialNumber() const {
	return serialNumber_;
}

void Bill::setSerialNumber(const std::string& serialNumber) {
	serialNumber_ = serialNumber;
}

double Bill::getSum() const {
	return sum_;
}

void Bill::setSum(double sum) {
	sum_ = sum;
}

bool Bill::operator<(const Bill& that) const {
	return companyName_ < that.companyName_;
}

std::istream& operator >>(std::istream& in, Bill& bill) {
	std::string buffer;
	std::string name;
	std::string number;
	double sum;
	bool isPaid;

	if (!(in >> buffer))
		return in;

	while (buffer != "|") {
		name += buffer + " ";
		in >> buffer;
	}
	name.erase(name.end() - 1);

	in >> buffer;
	while (buffer != "|") {
		number += buffer + " ";
		in >> buffer;
	}
	number.erase(number.end() - 1);

	in >> sum;
	in >> buffer;
	in >> isPaid;

	bill.setCompanyName(name);
	bill.setSerialNumber(number);
	bill.setSum(sum);
	if (isPaid)
		bill.pay();
	else
		bill.unpay();

	return in;
}

std::ostream& operator <<(std::ostream& out, Bill& bill) {
	char buffer[400];

	sprintf(buffer, "%s | %s | %.10f | %d\n", bill.getCompanyName().c_str(),
			bill.getSerialNumber().c_str(), bill.getSum(), bill.isPaid());

	out << buffer;

	return out;
}
