#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Repository.h"

class Controller {
  public:
    Controller(Repository& repository);
    std::vector<Gene> getGenes();
    Gene getGeneFromPosition(int index);

    /* Sorts the genes from the repository by organism, in lexicographic order (as
     * by the default less operator for Gene).
     * GETS: -
     * RETURNS: -
     * EFFECT: The repository is modified such that the genes are in sorted order. */
    void sortGenes();

    /* Counts the genes whose genetic sequence begin with a certain substring.
     * GETS: std::string beginning
     * RETURNS: int - number of found genes
     * EFFECT: - */
    int countGenesBeginningWith(std::string beginning);

  private:
    Repository& repository_;
};

void testController();

#endif /* CONTROLLER_H_ */
