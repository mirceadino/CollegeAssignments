#include "App.h"
#include <cstdio>
#include <iostream>

App::App(Controller& ctrl, QWidget * parent) :
    QMainWindow(parent), ctrl_(ctrl) {

  ui = Ui::MainWindow();
  ui.setupUi(this);

  populateList();
  setConnections();
}

void App::populateList() {
  if (ui.listGenes->count()) ui.listGenes->clear();

  for (auto gene : ctrl_.getGenes()) {
    char buffer[500];
    sprintf(buffer, "%s | %s", gene.getName().c_str(), gene.getOrganism().c_str());
    ui.listGenes->addItem(QString(buffer));
  }

  ui.listGenes->setCurrentRow(-1);
}

void App::setConnections() {
  connect(ui.listGenes, SIGNAL(itemSelectionChanged()), this, SLOT(displayCurrentGene()));
  connect(ui.sortButton, SIGNAL(clicked()), this, SLOT(sortGenes()));
  connect(ui.countButton, SIGNAL(clicked()), this, SLOT(countGenes()));
}

void App::sortGenes() {
  ctrl_.sortGenes();
  populateList();
}

void App::displayCurrentGene() {
  int index = ui.listGenes->currentRow();
  char buffer[500];
  Gene gene = ctrl_.getGeneFromPosition(index);

  sprintf(buffer, "Name: %s", gene.getName().c_str());
  ui.showName->setPlaceholderText(QString(buffer));
  sprintf(buffer, "Name: %s", gene.getSequence().c_str());
  ui.showSequence->setPlaceholderText(QString(buffer));
  sprintf(buffer, "Name: %s", gene.getOrganism().c_str());
  ui.showOrganism->setPlaceholderText(QString(buffer));
}

void App::countGenes() {
  std::string sequence = ui.inputBeginning->displayText().toStdString();

  int solution = ctrl_.countGenesBeginningWith(sequence);

  char buffer[500];
  sprintf(buffer, "%d", solution);

  ui.outputCounter->setPlaceholderText(QString(buffer));
}
