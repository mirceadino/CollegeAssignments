#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Repository.h"

class Playlist: public Repository {
	public:
		/* Default constructor. */
		Playlist();

		/* Returns true if the playlist can start (is not empty) or false otherwise. */
		bool start();

		/* Returns the current Tutorial in the playlist. */
		Tutorial& current();

		/* Returns true if the playlist can advance to the next tutorial (is not empty) or false otherwise.
		 * Playlist is circular (when it reaches end, it starts again). */
		bool next();

	protected:
		int current_;
};

#endif /* PLAYLIST_H_ */
