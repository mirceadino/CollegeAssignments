#ifndef APP_H_
#define APP_H_

#include <QtGui/QMainWindow>
#include "Controller.h"
#include "UI.h"

class App: public QMainWindow {
  Q_OBJECT

  public:
    App(Controller& ctrl, QWidget * parent = 0);

    void populateList();
    void setConnections();

  private:
    Controller& ctrl_;
    Ui::MainWindow ui;

  private slots:
    void sortGenes();
    void displayCurrentGene();
    void countGenes();
};

#endif /* APP_H_ */
