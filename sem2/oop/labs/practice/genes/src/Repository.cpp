#include "Repository.h"
#include <algorithm>

Repository::Repository() :
    genes_(std::vector<Gene>()) {
}

Repository::Repository(std::istream& in) :
    genes_(std::vector<Gene>()) {

  Gene G;

  while (in >> G)
    genes_.push_back(G);
}

std::vector<Gene> Repository::getAll() {
  return genes_;
}

void Repository::append(Gene G) {
  genes_.push_back(G);
}

void Repository::sort() {
  std::sort(genes_.begin(), genes_.end());
}

bool Repository::empty() const {
  return genes_.empty();
}

int Repository::size() const {
  return genes_.size();
}
