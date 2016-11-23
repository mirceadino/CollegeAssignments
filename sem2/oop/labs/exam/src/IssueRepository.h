#ifndef ISSUEREPOSITORY_H_
#define ISSUEREPOSITORY_H_

#include "Issue.h"
#include "User.h"
#include <vector>
#include <algorithm>

class IssueRepository {
  public:
    IssueRepository(std::string issuesfilename = "", std::string usersfilename = "");
    ~IssueRepository();
    void add(Issue I);
    void remove(std::string description);
    Issue& find(std::string description);
    bool exists(std::string description);
    std::vector<Issue> allIssues();
    std::vector<User> allUsers();

  protected:
    std::vector<Issue> issues_;
    std::vector<User> users_;
    std::string filename_;
};

#endif /* ISSUEREPOSITORY_H_ */
