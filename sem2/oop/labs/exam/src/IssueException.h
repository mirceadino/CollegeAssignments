#ifndef ISSUEEXCEPTION_H_
#define ISSUEEXCEPTION_H_

#include <exception>
#include <string>

class IssueException: public std::exception {
  public:
    IssueException(std::string message) :
        message_(message) {
    }

    std::string what() noexcept {
      return message_;
    }

  protected:
    std::string message_;
};

#endif /* ISSUEEXCEPTION_H_ */
