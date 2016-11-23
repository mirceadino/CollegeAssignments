#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include "Gene.h"
#include <vector>

class Repository {
  public:
    Repository();
    Repository(std::istream& in);
    std::vector<Gene> getAll();
    void append(Gene G);
    void sort();
    bool empty() const;
    int size() const;

  private:
    std::vector<Gene> genes_;
};

#endif /* REPOSITORY_H_ */
