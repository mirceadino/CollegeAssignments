#include "Issue.h"
#include <sstream>

using namespace std;

Issue::Issue(std::string description, std::string status, std::string reporter, std::string solver) :
    description_(description), status_(status), reporter_(reporter), solver_(solver) {
}

const std::string& Issue::getDescription() const {
  return description_;
}

void Issue::setDescription(const std::string& description) {
  description_ = description;
}

const std::string& Issue::getReporter() const {
  return reporter_;
}

void Issue::setReporter(const std::string& reporter) {
  reporter_ = reporter;
}

const std::string& Issue::getSolver() const {
  return solver_;
}

void Issue::setSolver(const std::string& solver) {
  solver_ = solver;
}

const std::string& Issue::getStatus() const {
  return status_;
}

void Issue::setStatus(const std::string& status) {
  status_ = status;
}

bool Issue::operator <(const Issue& that) const {
  if (status_ == that.status_)
    return description_ < that.description_;
  return status_ > that.status_;
}

std::istream& operator >>(std::istream& in, Issue& I) {
  string line;

  if (!getline(in, line))
    return in;

  if (line.empty())
    return in;

  string description;
  string status;
  string reporter;
  string solver;

  istringstream ss(line);
  getline(ss, description, '|');
  getline(ss, status, '|');
  getline(ss, reporter, '|');
  getline(ss, solver, '|');

  I.setDescription(description);
  I.setStatus(status);
  I.setReporter(reporter);
  I.setSolver(solver);

  return in;
}

std::ostream& operator <<(std::ostream& out, Issue& I) {
  ostringstream ss;

  ss << I.getDescription() << "|";
  ss << I.getStatus() << "|";
  ss << I.getReporter() << "|";
  ss << I.getSolver() << "|\n";

  out << ss.str();

  return out;
}
