#ifndef TASKEXCEPTION_H_
#define TASKEXCEPTION_H_

#include <exception>
#include <string>

class TaskException: public std::exception {
  public:
    TaskException(std::string message) :
        message_(message) {
    }

    const char* what() const noexcept {
      return message_.c_str();
    }

  protected:
    std::string message_;
};

#endif /* TASKEXCEPTION_H_ */
