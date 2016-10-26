#ifndef DURATION_H_
#define DURATION_H_

#include <string>
#include <cstdio>

class Duration {
	public:
		/* Default constructor. */
		Duration();

		/* Constructor with parameters. */
		Duration(int min, int sec);

		/* Copy constructor. */
		Duration(const Duration& that);

		/* Assignment operator. */
		Duration& operator=(const Duration& that);

		/* Destructor. */
		~Duration();

		/* Checks if a Duration is valid i.e. minutes and seconds are natural numbers, seconds are between 0 and 59 and duration lasts more than 1 second. */
		bool is_valid() const;

		/* Gets the number of minutes of the duration. */
		int get_minutes() const;

		/* Gets the number of seconds of the duration. */
		int get_seconds() const;

		/* Sets the number of minutes of the duration. */
		int set_minutes(int min);

		/* Sets the number of seconds of the duration. */
		int set_seconds(int sec);

		/* Returns the duration completely converted to seconds. */
		int total_seconds() const;

		/* Checks if two instances of Duration are equal. */
		bool operator==(const Duration& that) const;

		/* Returns the duration as a string of form "mm:ss". */
		std::string str() const;

	private:
		int minutes_;
		int seconds_;
};

inline Duration::Duration() :
		minutes_(0), seconds_(0) {
}

inline Duration::Duration(int min, int sec) :
		minutes_(min), seconds_(sec) {
}

inline Duration::Duration(const Duration& that) :
		minutes_(that.minutes_), seconds_(that.seconds_) {
}

inline Duration& Duration::operator=(const Duration& that) {
	this->minutes_ = int(that.minutes_);
	this->seconds_ = int(that.seconds_);
	return *this;
}

inline Duration::~Duration() {
}

inline bool Duration::is_valid() const {
	return this->minutes_ >= 0 && this->seconds_ >= 0 && this->seconds_ <= 59 && (this->minutes_ || this->seconds_);
}

inline int Duration::get_minutes() const {
	return this->minutes_;
}

inline int Duration::get_seconds() const {
	return this->seconds_;
}

inline int Duration::set_minutes(int min) {
	this->minutes_ = min;
	return 1;
}

inline int Duration::set_seconds(int sec) {
	this->seconds_ = sec;
	return 1;
}

inline int Duration::total_seconds() const {
	return this->minutes_ * 60 + this->seconds_;
}

inline bool Duration::operator==(const Duration& that) const {
	return this->minutes_ == that.minutes_ && this->seconds_ == that.seconds_;
}

inline std::string Duration::str() const {
	char text[105];
	sprintf(text, "%02d:%02d", this->minutes_, this->seconds_);
	return std::string(text);
}

#endif /* DURATION_H_ */
