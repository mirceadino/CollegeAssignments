#ifndef ISSUECONTROLLER_H_
#define ISSUECONTROLLER_H_

#include "IssueRepository.h"
#include "User.h"
#include "Observer.h"
#include <random>

class IssueController: public Subject {
  public:
    IssueController(IssueRepository& repository);
    ~IssueController();
    void reportIssue(std::string description, User& user);
    void removeIssue(std::string description, User& user);
    void resolveIssue(std::string description, User& user);
    std::vector<Issue> getIssues();

  protected:
    IssueRepository& repository_;
};

void test_controller();

#endif /* ISSUECONTROLLER_H_ */
