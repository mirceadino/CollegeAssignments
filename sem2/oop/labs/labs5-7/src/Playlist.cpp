#include "Playlist.h"

Playlist::Playlist() :
		current_(0) {
	Repository();
}

bool Playlist::start() {
	if (this->tutorials_.size() == 0)
		return false;

	this->current_ = 0;
	return true;
}

Tutorial& Playlist::current() {
	return this->tutorials_[this->current_];
}

bool Playlist::next() {
	if (this->tutorials_.size() == 0)
		return false;

	this->current_++;
	this->current_ %= this->tutorials_.size();
	return true;
}
