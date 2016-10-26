#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Repository.h"
#include "Playlist.h"
#include <cstring>

class Controller {
	public:
		/* Default constructor. */
		Controller();

		/* Constructor with parameter. */
		Controller(const Repository& repo);

		/* Adds a tutorial in the repository.
		 * Input: title - std::string,
		 * 	      presenter - std::string,
		 * 	      duration - Duration,
		 * 	      upvotes - int,
		 * 	      url - std::string
		 * Output: true if successfully added, false otherwise (if there'a already a tutorial with the same title or tutorial is invalid). */
		bool add_tutorial_to_repository(std::string title, std::string presenter, Duration duration, int upvotes, std::string url);

		/* Removes a tutorial of a certain title from the repository.
		 * Input: title - std::string
		 * Output: true if successfully removed, false otherwise (if tutorial with such title doesn't exist). */
		bool remove_tutorial_from_repository(std::string title);

		/* Updates a tutorial from the repository.
		 * Input: title - std::string
		 * 	      new_title - std::string,
		 * 	      new_presenter - std::string,
		 * 	      new_duration - Duration,
		 * 	      new_upvotes - int,
		 * 	      new_url - std::string
		 * Output: true if successfully updated, false otherwise (if tutorial with such title doesn't exist, new parameters are invalid or there's already a tutorial with the new title). */
		bool update_tutorial(std::string title, std::string new_title, std::string new_presenter, Duration new_duration, int new_upvotes, std::string new_url);

		/* Returns all the tutorials from the repository.
		 * Input: -
		 * Output: reference to the DynamicVector of Tutorials held in the repository. */
		DynamicVector<Tutorial>& get_all_from_repository();

		/* Creates a playlist with tutorials of a given presenter. */
		bool create_playlist(std::string presenter);

		/* Starts the tutorial. */
		bool start_playlist();

		/* Returns the current tutorial from playlist. */
		Tutorial& play_current_in_playlist();

		/* Advances to the next tutorial in playlist. */
		bool go_next_in_playlist();

		/* Adds a tutorial in the watchlist. */
		bool add_tutorial_to_watchlist(const Tutorial& tuto);

		/* Removes a tutorial of a certain title from the watchlist. */
		bool remove_tutorial_from_watchlist(std::string title);

		/* Upvotes a tutorial of a certain title. */
		bool upvote_tutorial(std::string title);

		/* Returns all the tutorials from the watchlist. */
		DynamicVector<Tutorial>& get_all_from_watchlist();

	private:
		Repository repository_;
		Repository watchlist_;
		Playlist playlist_;
};

void testController();

#endif /* CONTROLLER_H_ */
