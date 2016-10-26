#include "Gene.h"

Gene::Gene(const std::string& organism, const std::string& name, const std::string& sequence) :
    organism_(organism), name_(name), sequence_(sequence) {
}

std::string Gene::getName() const {
  return name_;
}

void Gene::setName(const std::string& name) {
  name_ = name;
}

std::string Gene::getOrganism() const {
  return organism_;
}

void Gene::setOrganism(const std::string& organism) {
  organism_ = organism;
}

std::string Gene::getSequence() const {
  return sequence_;
}

void Gene::setSequence(const std::string& sequence) {
  sequence_ = sequence;
}

bool Gene::operator<(const Gene& that) const {
  return organism_ < that.organism_;
}

std::istream& operator >>(std::istream& in, Gene& G) {
  std::string organism;
  std::string name;
  std::string sequence;
  std::string separator;

  if (!(in >> organism)) return in;

  in >> separator;
  in >> name;
  in >> separator;
  in >> sequence;

  G = Gene(organism, name, sequence);

  return in;
}

std::ostream& operator <<(std::ostream& out, Gene& G) {
  std::string separator = " | ";

  out << G.getOrganism() << separator;
  out << G.getName() << separator;
  out << G.getSequence() << '\n';

  return out;
}
