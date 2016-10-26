#ifndef APP_H_
#define APP_H_

#include <QtGui/QMainWindow>
#include "Controller.h"
#include "QtUi.h"

class App: public QMainWindow {
Q_OBJECT

public:
	App(Controller* ctrl, QWidget* parent = 0);
	~App();
	void populateList();
	void setConnections();
	int getSelectedItem();

private:
	Controller* ctrl_;
	Ui::MainWindow ui_;

private slots:
	void sort();
	void showItem();
	void compute();
};

#endif /* APP_H_ */
