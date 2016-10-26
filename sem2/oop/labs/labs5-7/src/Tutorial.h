#ifndef TUTORIAL_H_
#define TUTORIAL_H_

#include "Duration.h"
#include <string>

class Tutorial {
	public:
		/* Default constructor. */
		Tutorial();

		/* Constructor with parameters. */
		Tutorial(std::string title, std::string presenter, Duration duration, int upvotes, std::string url);

		/* Copy constructor. */
		Tutorial(const Tutorial& that);

		/* Assignment operator. */
		Tutorial& operator=(const Tutorial& that);

		/* Destructor. */
		~Tutorial();

		/* Checks if a Tutorial is valid i.e. title, presenter, url aren't empty, duration is valid, upvotes is natural number. */
		bool is_valid() const;

		/* Gets the title of the tutorial. */
		std::string get_title() const;

		/* Gets the presenter of the tutorial. */
		std::string get_presenter() const;

		/* Gets the duration of the tutorial. */
		Duration get_duration() const;

		/* Gets the number of upvotes of the tutorial. */
		int get_upvotes() const;

		/* Gets the URL of the tutorial. */
		std::string get_url() const;

		/* Sets the title of the tutorial. */
		int set_title(std::string new_title);

		/* Sets the presenter of the tutorial. */
		int set_presenter(std::string new_presenter);

		/* Sets the duration of the tutorial. */
		int set_duration(Duration new_duration);

		/* Sets the number of upvotes of the tutorial. */
		int set_upvotes(int new_upvotes);

		/* Sets the URL of the tutorial. */
		int set_url(std::string new_url);

		/* Adds a value to the number of upvotes of the tutorial. */
		Tutorial& operator+=(int x);

		/* Preincrements the number of upvotes of the tutorial. */
		Tutorial& operator++();

		/* Postincrements the number of upvotes of the tutorial. */
		Tutorial operator++(int);

		/* Checks if two instances of Tutorial are equal. */
		bool operator==(const Tutorial& that) const;

		/* Returns the tutorial as a string. */
		std::string str() const;

	private:
		std::string title_;
		std::string presenter_;
		Duration duration_;
		int upvotes_;
		std::string url_;
};

#endif /* TUTORIAL_H_ */
