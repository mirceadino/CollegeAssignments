#include <cstdio>
#include "App.h"

App::App(Controller* ctrl, QWidget* parent) :
		QMainWindow(parent) {
	ctrl_ = ctrl;
	ui_.setupUi(this);
	populateList();
	setConnections();
}

App::~App() {

}

void App::populateList() {
	if (ui_.bills->count())
		ui_.bills->clear();

	if (!ctrl_->getAll().empty()) {
		for (auto bill : ctrl_->getAll()) {
			char buffer[400];
			sprintf(buffer, "%s | %s | %.2f | %s\n",
					bill.getCompanyName().c_str(),
					bill.getSerialNumber().c_str(), bill.getSum(),
					bill.isPaid() ? "paid" : "unpaid");
			ui_.bills->addItem(QString(buffer));
		}
	}
}

void App::setConnections() {
	QObject::connect(ui_.bills, SIGNAL(itemSelectionChanged()), this,
			SLOT(showItem()));
	QObject::connect(ui_.sortButton, SIGNAL(clicked()), this, SLOT(sort()));
	QObject::connect(ui_.computeButton, SIGNAL(clicked()), this,
			SLOT(compute()));
}

int App::getSelectedItem() {
	if (ui_.bills->count() == 0)
		return -1;

	return ui_.bills->currentRow();
}

void App::sort() {
	ctrl_->sortAll();
	populateList();
}

void App::showItem() {
	int i = getSelectedItem();

	if (i == -1) {
		ui_.companyName->setPlaceholderText("");
		ui_.serialNumber->setPlaceholderText("");
		ui_.sum->setPlaceholderText("");
		ui_.isPaid->setPlaceholderText("");
		return;
	}

	Bill bill = ctrl_->getAll()[i];
	char buffer[400];

	sprintf(buffer, "Company: %s", bill.getCompanyName().c_str());
	ui_.companyName->setPlaceholderText(QString(buffer));
	sprintf(buffer, "Serial number: %s", bill.getSerialNumber().c_str());
	ui_.serialNumber->setPlaceholderText(QString(buffer));
	sprintf(buffer, "Sum: %.2f", bill.getSum());
	ui_.sum->setPlaceholderText(QString(buffer));
	sprintf(buffer, "Status: %s", bill.isPaid() ? "paid" : "unpaid");
	ui_.isPaid->setPlaceholderText(QString(buffer));
}

void App::compute() {
	std::string company = ui_.inputCompanyName->displayText().toStdString();
	char buffer[400];

	try {
		double sum = ctrl_->computeSumUnpaid(company);
		sprintf(buffer, "Unpaid bills: %.2f", sum);
	} catch (std::runtime_error& e) {
		sprintf(buffer, "%s", e.what());
	}

	ui_.totalBalance->setPlaceholderText(QString(buffer));
}
