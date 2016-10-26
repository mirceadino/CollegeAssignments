#include "IssueRepository.h"

using namespace std;

IssueRepository::IssueRepository(std::string issuesfilename, std::string usersfilename) :
    filename_(issuesfilename) {

  if (!filename_.empty()) {
    ifstream fin(filename_);
    Issue I;

    while (fin >> I)
      issues_.push_back(I);
  }

  if (!usersfilename.empty()) {
    ifstream fin(usersfilename);
    User I;

    while (fin >> I)
      users_.push_back(I);
  }
}

IssueRepository::~IssueRepository() {
  if (filename_.empty())
    return;

  ofstream fout(filename_);

  for (auto I : issues_)
    fout << I;
}

void IssueRepository::add(Issue I) {
  issues_.push_back(I);
}

void IssueRepository::remove(std::string description) {
  for (auto& I : issues_)
    if (I.getDescription() == description) {
      swap(issues_.back(), I);
      issues_.pop_back();
      return;
    }

  throw IssueException("Issue doesn't exist.");
}

Issue& IssueRepository::find(std::string description) {
  for (auto& I : issues_)
    if (I.getDescription() == description)
      return I;

  throw IssueException("Issue doesn't exist.");
}

bool IssueRepository::exists(std::string description) {
  for (auto& I : issues_)
    if (I.getDescription() == description)
      return true;

  return false;
}

std::vector<Issue> IssueRepository::allIssues() {
  return issues_;
}

std::vector<User> IssueRepository::allUsers() {
  return users_;
}
