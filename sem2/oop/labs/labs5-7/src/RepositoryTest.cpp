#include <cassert>
#include "Repository.h"

void testRepository() {
	Tutorial A("a", "a", Duration(3, 3), 30, "ha");
	Tutorial B("b", "b", Duration(3, 3), 30, "hb");
	Tutorial C("c", "c", Duration(3, 3), 30, "hc");
	Repository repo;

	// append, find
	assert(repo.add(A));
	assert(repo.add(B));
	assert(!repo.add(B));
	assert(repo.get_all().size() == 2);
	assert(repo.find(A));
	assert(repo.find(B));
	assert(!repo.find(C));
	assert(repo.add(C));
	assert(repo.get_all().size() == 3);
	assert(repo.find(C));

	// findByTitle
	assert(repo.find_by_title("a") == A);
	assert(repo.find_by_title("b") == B);
	assert(repo.find_by_title("c") == C);
	assert(repo.find_by_title("d") == Tutorial());

	// remove
	assert(repo.remove(A));
	assert(!repo.find(A));
	assert(!repo.remove(A));
	assert(repo.get_all().size() == 2);
}
