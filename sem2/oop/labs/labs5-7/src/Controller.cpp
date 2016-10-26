#include "Controller.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

Controller::Controller() :
		repository_(Repository()) {
}

Controller::Controller(const Repository& repo) :
		repository_(repo) {
}

bool Controller::add_tutorial_to_repository(std::string title, std::string presenter, Duration duration, int upvotes, std::string url) {
	Tutorial tuto(title, presenter, duration, upvotes, url);
	if (!tuto.is_valid())
		return false;
	return this->repository_.add(tuto);
}

bool Controller::remove_tutorial_from_repository(std::string title) {
	Tutorial& tuto = this->repository_.find_by_title(title);
	this->watchlist_.remove(tuto);
	return this->repository_.remove(tuto);
}

bool Controller::update_tutorial(std::string title, std::string new_title, std::string new_presenter, Duration new_duration, int new_upvotes, std::string new_url) {
	// check if tutorial to be updated exists
	Tutorial& tuto = this->repository_.find_by_title(title);

	if (!(this->repository_.find(tuto)))
		return false;

	// check if the new address doesn't already exist
	Tutorial& aux = this->repository_.find_by_title(new_title);

	if (this->repository_.find(aux) && !(aux == tuto))
		return false;

	// keep old parameters if mentioned
	if (new_title.size() == 0)
		new_title = tuto.get_title();
	if (new_presenter.size() == 0)
		new_presenter = tuto.get_presenter();
	if (new_url.size() == 0)
		new_url = tuto.get_url();

	// check if the parameters are valid
	Tutorial temp(new_title, new_presenter, new_duration, new_upvotes, new_url);

	if (!temp.is_valid())
		return false;

	// effectively update
	tuto.set_title(new_title);
	tuto.set_presenter(new_presenter);
	tuto.set_duration(new_duration);
	tuto.set_upvotes(new_upvotes);
	tuto.set_url(new_url);

	// update in the watchlist too
	Tutorial& tuto2 = this->watchlist_.find_by_title(title);

	if (!(this->watchlist_.find(tuto2)))
		return true;

	tuto2.set_title(new_title);
	tuto2.set_presenter(new_presenter);
	tuto2.set_duration(new_duration);
	tuto2.set_upvotes(new_upvotes);
	tuto2.set_url(new_url);

	return true;
}

DynamicVector<Tutorial>& Controller::get_all_from_repository() {
	return this->repository_.get_all();
}

bool Controller::create_playlist(std::string presenter) {
	DynamicVector<Tutorial> all = this->get_all_from_repository();
	this->playlist_ = Playlist();

	for (int i = 0; i < all.size(); i++)
		if (presenter == "" || all[i].get_presenter() == presenter)
			this->playlist_.add(all[i]);

	if (this->playlist_.size() == 0)
		return false;

	return true;
}

bool Controller::start_playlist() {
	return this->playlist_.start();
}

Tutorial& Controller::play_current_in_playlist() {
	std::string command = "xdg-open ";
	command += this->playlist_.current().get_url();
	command += "> /dev/null";
	system(command.c_str());
	return this->playlist_.current();
}

bool Controller::go_next_in_playlist() {
	return this->playlist_.next();
}

bool Controller::add_tutorial_to_watchlist(const Tutorial& tuto) {
	return this->watchlist_.add(tuto);
}

bool Controller::remove_tutorial_from_watchlist(std::string title) {
	Tutorial tuto = this->watchlist_.find_by_title(title);
	return this->watchlist_.remove(tuto);
}

bool Controller::upvote_tutorial(std::string title) {
	Tutorial& tuto = this->repository_.find_by_title(title);
	if (!this->repository_.find(tuto))
		return false;

	tuto++;

	return true;
}

DynamicVector<Tutorial>& Controller::get_all_from_watchlist() {
	return this->watchlist_.get_all();
}
