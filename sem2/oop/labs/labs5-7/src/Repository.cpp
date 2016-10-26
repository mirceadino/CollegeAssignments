#include "Repository.h"
#include <iostream>
#include <fstream>

Repository::Repository() :
		tutorials_(DynamicVector<Tutorial>()) {
}

Repository::Repository(const Repository& repo) :
		tutorials_(repo.tutorials_) {
}

Repository& Repository::operator=(const Repository& repo) {
	this->tutorials_ = DynamicVector<Tutorial>(repo.tutorials_);
	return *this;
}

Repository::~Repository() {
}

int Repository::size() {
	return this->tutorials_.size();
}

int Repository::add(Tutorial tuto) {
	if (!(this->find_by_title(tuto.get_title()) == Tutorial()))
		return 0;

	this->tutorials_.append(tuto);

	return 1;
}

int Repository::remove(Tutorial tuto) {
	if (this->find_by_title(tuto.get_title()) == Tutorial())
		return 0;

	this->tutorials_.erase(tuto);

	return 1;
}

bool Repository::find(Tutorial tuto) {
	for (int i = 0; i < this->tutorials_.size(); i++)
		if (this->tutorials_[i] == tuto)
			return true;

	return false;
}

Tutorial& Repository::find_by_title(std::string title) {
	for (int i = 0; i < this->tutorials_.size(); i++)
		if (this->tutorials_[i].get_title() == title)
			return this->tutorials_[i];

	return *(new Tutorial);
}

DynamicVector<Tutorial>& Repository::get_all() {
	return this->tutorials_;
}
