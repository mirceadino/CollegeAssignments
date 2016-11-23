#include "App.h"
#include <iostream>

App::App(Controller* ctrl, QWidget* parent) :
		QMainWindow(parent) {
	ctrl_ = ctrl;
	currentIndex_ = 0;
	ui_.setupUi(this);
	this->populateList();
	this->setConnections();
	this->itemWasChanged();
}

App::~App() {

}

void App::populateList() {
	if (this->ui_.listWidget->count())
		this->ui_.listWidget->clear();

	std::vector<Country> all = ctrl_->getAllCountries();

	if (!all.empty()) {
		for (auto country : all) {
			char buffer[500];
			sprintf(buffer, "%s | %s | %s | Score: %d",
					country.getName().c_str(), country.getSinger().c_str(),
					country.getSong().c_str(), country.getScore());

//			std::cout << country;

			QString item = QString::fromStdString(std::string(buffer));
			this->ui_.listWidget->addItem(item);
		}

		this->ui_.listWidget->setCurrentRow(this->currentIndex_);
	}
}

int App::getSelectedItem() {
	QModelIndexList indexes =
			this->ui_.listWidget->selectionModel()->selectedIndexes();
	if (indexes.size() == 0)
		return -1;
	return indexes.at(0).row();
}

void App::setConnections() {
	QObject::connect(this->ui_.listWidget, SIGNAL(itemSelectionChanged()), this,
			SLOT(itemWasChanged()));
	QObject::connect(this->ui_.pushButton_2, SIGNAL(clicked()), this,
			SLOT(upvote()));
	QObject::connect(this->ui_.pushButtonSort, SIGNAL(clicked()), this,
			SLOT(sortAll()));
}

void App::itemWasChanged() {
	int index = this->getSelectedItem();

	if (index == -1) {
		this->ui_.lineEditCountry->clear();
		this->ui_.lineEditSinger->clear();
		this->ui_.lineEditSong->clear();
		this->ui_.lineEditVotes->clear();
		return;
	}

	Country current = this->ctrl_->getAllCountries()[index];
	char buffer[500];

	sprintf(buffer, "Country: %s", current.getName().c_str());
	this->ui_.lineEditCountry->setText(buffer);
	sprintf(buffer, "Singer: %s", current.getSinger().c_str());
	this->ui_.lineEditSinger->setText(buffer);
	sprintf(buffer, "Song: %s", current.getSong().c_str());
	this->ui_.lineEditSong->setText(buffer);
	sprintf(buffer, "Score: %d", current.getScore());
	this->ui_.lineEditVotes->setText(buffer);
}

void App::sortAll() {
	this->ctrl_->sortByScore();
	this->populateList();
}

void App::upvote() {
	int index = this->getSelectedItem();

	if (index == -1) {
		return;
	}

	Country current = this->ctrl_->getAllCountries()[index];
	ctrl_->upvoteCountry(current.getName());
	currentIndex_ = index;
	itemWasChanged();
	populateList();
	return;
	char buffer[500];

	sprintf(buffer, "Country: %s", current.getName().c_str());
	this->ui_.lineEditCountry->setText(buffer);
	sprintf(buffer, "Singer: %s", current.getSinger().c_str());
	this->ui_.lineEditSinger->setText(buffer);
	sprintf(buffer, "Song: %s", current.getSong().c_str());
	this->ui_.lineEditSong->setText(buffer);
	sprintf(buffer, "Score: %d", current.getScore());
	this->ui_.lineEditVotes->setText(buffer);
}
