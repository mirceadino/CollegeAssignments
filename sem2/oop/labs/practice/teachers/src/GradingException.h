#ifndef GRADINGEXCEPTION_H_
#define GRADINGEXCEPTION_H_

#include <exception>
#include <string>

class GradingException: public std::exception {
  public:
    GradingException(const std::string& message) :
        message_(message) {
    }

    const std::string& what() {
      return message_;
    }

    ~GradingException() {
    }

  protected:
    std::string message_;
};

#endif /* GRADINGEXCEPTION_H_ */
