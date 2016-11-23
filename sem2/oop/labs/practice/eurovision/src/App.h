#ifndef APP_H_
#define APP_H_

#include <cstdio>

#include <QtGui/QMainWindow>

#include "Controller.h"
#include "QTUI.h"

class App: public QMainWindow {
Q_OBJECT

public:
	App(Controller* ctrl, QWidget* parent = 0);
	~App();

	void populateList();
	int getSelectedItem();
	void setConnections();

private:
	Controller* ctrl_;
	Ui::MainWindow ui_;
	int currentIndex_;

private slots:
	void itemWasChanged();
	void sortAll();
	void upvote();
};

#endif /* APP_H_ */
