#ifndef ISSUE_H_
#define ISSUE_H_

#include "IssueException.h"
#include <string>
#include <iostream>
#include <fstream>

class Issue {
  public:
    Issue(std::string description = "", std::string status = "open", std::string reporter = "", std::string solver = "");

    const std::string& getDescription() const;
    void setDescription(const std::string& description);
    const std::string& getReporter() const;
    void setReporter(const std::string& reporter);
    const std::string& getSolver() const;
    void setSolver(const std::string& solver);
    const std::string& getStatus() const;
    void setStatus(const std::string& status);

    bool operator<(const Issue& that) const;

  protected:
    std::string description_;
    std::string status_;
    std::string reporter_;
    std::string solver_;
};

std::istream& operator>>(std::istream& in, Issue& I);
std::ostream& operator<<(std::ostream& out, Issue& I);

#endif /* ISSUE_H_ */
