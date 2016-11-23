#include "Controller.h"
#include <cassert>
#include <stdexcept>
#include <iostream>

Controller::Controller(Repository& repository) :
    repository_(repository) {
}

std::vector<Gene> Controller::getGenes() {
  return repository_.getAll();
}

Gene Controller::getGeneFromPosition(int index) {
  if (0 <= index && index < repository_.size()) return repository_.getAll()[index];

  if (repository_.empty())
    throw std::runtime_error("No genes.\n");
  else
    throw std::runtime_error("Invalid position.");
}

void Controller::sortGenes() {
  repository_.sort();
}

int Controller::countGenesBeginningWith(std::string beginning) {
  int counter = 0;

  for (auto gene : repository_.getAll())
    if (gene.getSequence().find(beginning) == 0) counter++;

  return counter;
}

void testController() {
  Repository repo;
  Controller ctrl(repo);

  repo.append(Gene("Cat", "3", "ACCC"));
  repo.append(Gene("Human", "1", "ACCC"));
  repo.append(Gene("Dog", "1", "TAAGC"));
  repo.append(Gene("Cat", "2", "ACTTT"));
  repo.append(Gene("Human", "2", "ACTT"));
  repo.append(Gene("Dragon", "1", "TTAACA"));
  repo.append(Gene("Cat", "1", "ACTGA"));

  assert(ctrl.countGenesBeginningWith("ACC") == 2);
  assert(ctrl.countGenesBeginningWith("TAA") == 1);
  assert(ctrl.countGenesBeginningWith("AC") == 5);
  assert(ctrl.countGenesBeginningWith("T") == 2);

  ctrl.sortGenes();

  assert(ctrl.getGeneFromPosition(0).getOrganism() == "Cat");
  assert(ctrl.getGeneFromPosition(1).getOrganism() == "Cat");
  assert(ctrl.getGeneFromPosition(2).getOrganism() == "Cat");
  assert(ctrl.getGeneFromPosition(3).getOrganism() == "Dog");
  assert(ctrl.getGeneFromPosition(4).getOrganism() == "Dragon");
  assert(ctrl.getGeneFromPosition(5).getOrganism() == "Human");
  assert(ctrl.getGeneFromPosition(6).getOrganism() == "Human");
}
