#include "IssueController.h"
#include <cassert>

using namespace std;

void test_add_controller(IssueRepository& repo, IssueController& ctrl, User& tester, User& programmer);
void test_resolve_controller(IssueRepository& repo, IssueController& ctrl, User& tester, User& programmer);
void test_remove_controller(IssueRepository& repo, IssueController& ctrl, User& tester, User& programmer);

void test_controller() {
  IssueRepository repo;
  IssueController ctrl(repo);
  User tester("X", "tester");
  User programmer("Y", "programmer");

  test_add_controller(repo, ctrl, tester, programmer);
  test_resolve_controller(repo, ctrl, tester, programmer);
  test_remove_controller(repo, ctrl, tester, programmer);
}

void test_add_controller(IssueRepository& repo, IssueController& ctrl, User& tester, User& programmer) {
  // simple reports by tester
  ctrl.reportIssue("AAA", tester);
  ctrl.reportIssue("BBB", tester);
  assert(repo.exists("AAA"));
  assert(repo.find("AAA").getStatus() == "open");
  assert(repo.find("AAA").getReporter() == tester.getName());
  assert(repo.exists("BBB"));
  assert(repo.find("BBB").getStatus() == "open");
  assert(repo.find("BBB").getReporter() == tester.getName());

  // duplicate reports
  try {
    ctrl.reportIssue("AAA", tester);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }

  try {
    ctrl.reportIssue("BBB", tester);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }

  // invalid reports by programmer
  try {
    ctrl.reportIssue("CCC", programmer);
    assert(false);
  } catch (IssueException& err) {
    assert(!repo.exists("CCC"));
  }

  try {
    ctrl.reportIssue("BBB", programmer);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }
}

void test_resolve_controller(IssueRepository& repo, IssueController& ctrl, User& tester, User& programmer) {
  // resolve by programmer
  ctrl.reportIssue("CCC", tester);
  ctrl.reportIssue("DDD", tester);
  ctrl.reportIssue("EEE", tester);
  ctrl.resolveIssue("AAA", programmer);
  assert(repo.find("AAA").getStatus() == "closed");
  assert(repo.find("AAA").getSolver() == programmer.getName());
  ctrl.resolveIssue("BBB", programmer);
  assert(repo.find("BBB").getStatus() == "closed");
  assert(repo.find("BBB").getSolver() == programmer.getName());

  // resolve issues again
  try {
    ctrl.resolveIssue("AAA", programmer);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }
  try {
    ctrl.resolveIssue("BBB", programmer);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }

  // invalid resolves by tester
  try {
    ctrl.resolveIssue("CCC", tester);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }
  try {
    ctrl.resolveIssue("DDD", tester);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }
}

void test_remove_controller(IssueRepository& repo, IssueController& ctrl, User& tester, User& programmer) {
  // closed remove by programmer
  ctrl.removeIssue("AAA", programmer);
  assert(!repo.exists("AAA"));

  // closed remove by tester
  ctrl.removeIssue("BBB", tester);
  assert(!repo.exists("BBB"));

  // try to remove open issue
  try {
    ctrl.removeIssue("CCC", programmer);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }
  try {
    ctrl.removeIssue("DDD", tester);
    assert(false);
  } catch (IssueException& err) {
    assert(true);
  }
}
