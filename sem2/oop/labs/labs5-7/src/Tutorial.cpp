#include "Tutorial.h"
#include <string>
#include <cstdio>
#include <cstring>

Tutorial::Tutorial() :
		title_(""), presenter_(""), duration_(Duration()), upvotes_(0), url_("") {
}

Tutorial::Tutorial(std::string title, std::string presenter, Duration duration, int upvotes, std::string url) :
		title_(title), presenter_(presenter), duration_(duration), upvotes_(upvotes), url_(url) {
}

Tutorial::Tutorial(const Tutorial& that) :
		title_(that.title_), presenter_(that.presenter_), duration_(that.duration_), upvotes_(that.upvotes_), url_(that.url_) {
}

Tutorial& Tutorial::operator=(const Tutorial& that) {
	this->title_ = std::string(that.title_);
	this->presenter_ = std::string(that.presenter_);
	this->duration_ = Duration(that.duration_);
	this->upvotes_ = int(that.upvotes_);
	this->url_ = std::string(that.url_);
	return *this;
}

Tutorial::~Tutorial() {
}

bool Tutorial::is_valid() const {
	return ((this->title_.size() != 0) && (this->presenter_.size() != 0) && this->duration_.is_valid() && (this->upvotes_ >= 0) && (this->url_.size() != 0));
}

std::string Tutorial::get_title() const {
	return this->title_;
}

std::string Tutorial::get_presenter() const {
	return this->presenter_;
}

Duration Tutorial::get_duration() const {
	return this->duration_;
}

int Tutorial::get_upvotes() const {
	return this->upvotes_;
}

std::string Tutorial::get_url() const {
	return this->url_;
}

int Tutorial::set_title(std::string new_title) {
	this->title_ = std::string(new_title);
	return 1;
}

int Tutorial::set_presenter(std::string new_presenter) {
	this->presenter_ = std::string(new_presenter);
	return 1;
}

int Tutorial::set_duration(Duration new_duration) {
	this->duration_ = Duration(new_duration);
	return 1;
}

int Tutorial::set_upvotes(int new_upvotes) {
	this->upvotes_ = int(new_upvotes);
	return 1;
}

int Tutorial::set_url(std::string new_url) {
	this->url_ = std::string(new_url);
	return 1;
}

Tutorial& Tutorial::operator+=(int x) {
	this->upvotes_ += x;
	return *this;
}

Tutorial& Tutorial::operator++() {
	this->upvotes_++;
	return *this;
}

Tutorial Tutorial::operator++(int) {
	Tutorial copy = *this;
	this->upvotes_++;
	return copy;
}

bool Tutorial::operator==(const Tutorial& that) const {
	return this->title_ == that.title_ && this->presenter_ == that.presenter_ && this->duration_ == that.duration_ && this->upvotes_ == that.upvotes_ && this->url_ == that.url_;
}

std::string Tutorial::str() const {
	char text[205];
	sprintf(text, "\"%s\" by %s (%s) - %d upvotes", this->title_.c_str(), this->presenter_.c_str(), this->duration_.str().c_str(), this->upvotes_);
	if (strlen(text) > 75) {
		memset(text + 75, 0, 100 * sizeof(char));
		text[strlen(text)] = '.';
		text[strlen(text)] = '.';
		text[strlen(text)] = '.';
	}
	return std::string(text);
}
