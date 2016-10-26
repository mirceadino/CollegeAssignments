#ifndef BILL_H_
#define BILL_H_

#include <iostream>
#include <fstream>
#include <string>

class Bill {
public:
	Bill(std::string name = "", std::string number = "", double sum = 0.0,
			bool paid = false);

	std::string getCompanyName() const;
	void setCompanyName(const std::string& companyName);
	bool isPaid() const;
	void pay();
	void unpay();
	std::string getSerialNumber() const;
	void setSerialNumber(const std::string& serialNumber);
	double getSum() const;
	void setSum(double sum);
	bool operator<(const Bill& that) const;

private:
	std::string companyName_;
	std::string serialNumber_;
	double sum_;
	bool isPaid_;
};

std::istream& operator>>(std::istream& in, Bill& bill);
std::ostream& operator<<(std::ostream& out, Bill& bill);

#endif /* BILL_H_ */
