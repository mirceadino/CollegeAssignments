#ifndef TESTS_H_
#define TESTS_H_

#include "Repository.h"
#include "Controller.h"
#include <cassert>

void test_add() {
	Repository repo;
	Player A("a", "aaa", "a", 3);
	Player B("b", "aaa", "a", 1);
	Player C("c", "bbb", "a", 10);

	assert(repo.add(A));
	assert(repo.size() == 1);
	assert(!repo.add(A));
	assert(repo.size() == 1);
	assert(repo.findByName("a") == A);

	assert(repo.add(B));
	assert(repo.size() == 2);
	assert(!repo.add(B));
	assert(repo.size() == 2);
	assert(repo.findByName("a") == A);
	assert(repo.findByName("b") == B);

	assert(repo.add(C));
	assert(repo.size() == 3);
	assert(!repo.add(C));
	assert(repo.size() == 3);
	assert(repo.findByName("c") == C);
	assert(repo.findByName("a") == A);
	assert(repo.findByName("b") == B);
}

void test_filter() {
	Repository repo;
	Controller ctrl(repo);
	Player A("a", "aaa", "a", 3);
	Player B("b", "aaa", "a", 1);
	Player C("c", "bbb", "a", 10);
	Player D("d", "aaa", "a", 21);
	Player E("e", "bbb", "a", 11);
	ctrl.add(A.getName(), A.getNationality(), A.getTeam(), A.getGoals());
	ctrl.add(B.getName(), B.getNationality(), B.getTeam(), B.getGoals());
	ctrl.add(C.getName(), C.getNationality(), C.getTeam(), C.getGoals());
	ctrl.add(D.getName(), D.getNationality(), D.getTeam(), D.getGoals());
	ctrl.add(E.getName(), E.getNationality(), E.getTeam(), E.getGoals());

	std::vector<Player> aaa = ctrl.getPlayerByNationalitySorted("aaa");
	assert(aaa.size() == 3);
	assert(aaa[0] == B);
	assert(aaa[1] == A);
	assert(aaa[2] == D);

	std::vector<Player> bbb = ctrl.getPlayerByNationalitySorted("bbb");
	assert(bbb.size() == 2);
	assert(bbb[0] == C);
	assert(bbb[1] == E);

	std::vector<Player> ccc = ctrl.getPlayerByNationalitySorted("ccc");
	assert(ccc.size() == 0);
}

#endif /* TESTS_H_ */
