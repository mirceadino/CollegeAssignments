#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include "Tutorial.h"
#include "DynamicVector.h"
#include <cstring>

class Repository {
	public:
		/* Default constructor. */
		Repository();

		/* Copy constructor. */
		Repository(const Repository& repo);

		/* Assignment operator. */
		Repository& operator=(const Repository& repo);

		/* Destructor. */
		~Repository();

		/* Size of the repository. */
		int size();

		/* Adds a tutorial to the repository.
		 * Input: tuto - Tutorial
		 * Output: true if successfully added, false otherwise (if there'a already a tutorial with the same title). */
		int add(Tutorial tuto);

		/* Removes a tutorial from the repository.
		 * Input: tuto - Tutorial
		 * Output: true if successfully removed, false otherwise (if tuto doesn't exist in the repository). */
		int remove(Tutorial tuto);

		/* Checks if a tutorial exists or not in the repository.
		 * Input: tuto - Tutorial
		 * Output: true if it exists, false otherwise. */
		bool find(Tutorial tuto);

		/* Checks if there's a tutorial with a certain title and returns the reference to that tutorial.
		 * Input: title - std::string
		 * Output: reference to the Tutorial with the given title or an empty Tutorial if it doesn't exist. */
		Tutorial& find_by_title(std::string title);

		/* Returns all the tutorials.
		 * Input: -
		 * Output: reference to the DynamicVector of Tutorials held in the repository. */
		DynamicVector<Tutorial>& get_all();

	protected:
		DynamicVector<Tutorial> tutorials_;
};

void testRepository();

#endif /* REPOSITORY_H_ */
