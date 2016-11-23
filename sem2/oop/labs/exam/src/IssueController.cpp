#include "IssueController.h"

using namespace std;

IssueController::IssueController(IssueRepository& repository) :
    Subject(), repository_(repository) {
}

IssueController::~IssueController() {
}

/* Adds an issue with a specified description to the repository.
 * Input: std::string description - description of the new issue
 *        User& user - reference to the user that reports the issue
 * Output: -
 * Exception: throws IssueException if:
 *            - user is not a tester
 *            - description is empty
 *            - there's already an issue with such description */
void IssueController::reportIssue(std::string description, User& user) {
  if (user.getType() != "tester")
    throw IssueException("Only testers can report issues.");

  Issue I(description, "open", user.getName(), "");

  if (repository_.exists(I.getDescription()))
    throw IssueException("Issue already exists.");

  if (I.getDescription().empty())
    throw IssueException("Issue has no description.");

  repository_.add(I);

  this->notify();
}

/* Removes an issue with a specified description from the repository.
 * Input: std::string description - description of the removed issue
 *        User& user - reference to the user that removes the issue
 * Output: -
 * Exception: throws IssueException if:
 *            - issue with such description doesn't exist (thrown from repository)
 *            - issue is not closed */
void IssueController::removeIssue(std::string description, User& user) {
  Issue& I = repository_.find(description);

  if (I.getStatus() != "closed")
    throw IssueException("Issue must be closed before removing it.");

  repository_.remove(description);

  this->notify();
}

/* Resolves an issue with a specified description.
 * Input: std::string description - description of the resolved issue
 *        User& user - reference to the user that resolves the issue
 * Output: -
 * Exception: throws IssueException if:
 *            - user is not a programmer
 *            - issue with such description doesn't exist (thrown from repository)
 *            - issue is not open */
void IssueController::resolveIssue(std::string description, User& user) {
  if (user.getType() != "programmer")
    throw IssueException("Only programmers can resolve issues.");

  Issue& I = repository_.find(description);

  if (I.getStatus() != "open")
    throw IssueException("Issue must be open in order to resolve it.");

  I.setStatus("closed");
  I.setSolver(user.getName());

  this->notify();
}

std::vector<Issue> IssueController::getIssues() {
  return repository_.allIssues();
}
