/********************************************************************************
 ** Form generated from reading UI file 'designOj5747.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef DESIGNOJ5747_H
#define DESIGNOJ5747_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
	QWidget *centralwidget;
	QWidget *verticalLayoutWidget;
	QVBoxLayout *verticalLayout;
	QListWidget *bills;
	QPushButton *sortButton;
	QLineEdit *companyName;
	QLineEdit *serialNumber;
	QLineEdit *sum;
	QLineEdit *isPaid;
	QSpacerItem *horizontalSpacer;
	QLabel *label;
	QLineEdit *inputCompanyName;
	QPushButton *computeButton;
	QLineEdit *totalBalance;
	QMenuBar *menubar;
	QStatusBar *statusbar;

	void setupUi(QMainWindow *MainWindow) {
		if (MainWindow->objectName().isEmpty())
			MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
		MainWindow->resize(439, 600);
		centralwidget = new QWidget(MainWindow);
		centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		verticalLayoutWidget = new QWidget(centralwidget);
		verticalLayoutWidget->setObjectName(
				QString::fromUtf8("verticalLayoutWidget"));
		verticalLayoutWidget->setGeometry(QRect(19, 19, 401, 531));
		verticalLayout = new QVBoxLayout(verticalLayoutWidget);
		verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
		verticalLayout->setContentsMargins(0, 0, 0, 0);
		bills = new QListWidget(verticalLayoutWidget);
		bills->setObjectName(QString::fromUtf8("bills"));

		verticalLayout->addWidget(bills);

		sortButton = new QPushButton(verticalLayoutWidget);
		sortButton->setObjectName(QString::fromUtf8("sortButton"));

		verticalLayout->addWidget(sortButton);

		companyName = new QLineEdit(verticalLayoutWidget);
		companyName->setObjectName(QString::fromUtf8("companyName"));
		companyName->setEnabled(false);

		verticalLayout->addWidget(companyName);

		serialNumber = new QLineEdit(verticalLayoutWidget);
		serialNumber->setObjectName(QString::fromUtf8("serialNumber"));
		serialNumber->setEnabled(false);

		verticalLayout->addWidget(serialNumber);

		sum = new QLineEdit(verticalLayoutWidget);
		sum->setObjectName(QString::fromUtf8("sum"));
		sum->setEnabled(false);

		verticalLayout->addWidget(sum);

		isPaid = new QLineEdit(verticalLayoutWidget);
		isPaid->setObjectName(QString::fromUtf8("isPaid"));
		isPaid->setEnabled(false);

		verticalLayout->addWidget(isPaid);

		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding,
				QSizePolicy::Minimum);

		verticalLayout->addItem(horizontalSpacer);

		label = new QLabel(verticalLayoutWidget);
		label->setObjectName(QString::fromUtf8("label"));

		verticalLayout->addWidget(label);

		inputCompanyName = new QLineEdit(verticalLayoutWidget);
		inputCompanyName->setObjectName(QString::fromUtf8("inputCompanyName"));

		verticalLayout->addWidget(inputCompanyName);

		computeButton = new QPushButton(verticalLayoutWidget);
		computeButton->setObjectName(QString::fromUtf8("computeButton"));

		verticalLayout->addWidget(computeButton);

		totalBalance = new QLineEdit(verticalLayoutWidget);
		totalBalance->setObjectName(QString::fromUtf8("totalBalance"));
		totalBalance->setEnabled(false);

		verticalLayout->addWidget(totalBalance);

		MainWindow->setCentralWidget(centralwidget);
		menubar = new QMenuBar(MainWindow);
		menubar->setObjectName(QString::fromUtf8("menubar"));
		menubar->setGeometry(QRect(0, 0, 439, 25));
		MainWindow->setMenuBar(menubar);
		statusbar = new QStatusBar(MainWindow);
		statusbar->setObjectName(QString::fromUtf8("statusbar"));
		MainWindow->setStatusBar(statusbar);

		retranslateUi(MainWindow);

		QMetaObject::connectSlotsByName(MainWindow);
	} // setupUi

	void retranslateUi(QMainWindow *MainWindow) {
		MainWindow->setWindowTitle(
				QApplication::translate("MainWindow", "Bills, bills, bills", 0,
						QApplication::UnicodeUTF8));
		sortButton->setText(
				QApplication::translate("MainWindow", "Sort", 0,
						QApplication::UnicodeUTF8));
		label->setText(
				QApplication::translate("MainWindow",
						"Compute sum of unpaid bills for a company", 0,
						QApplication::UnicodeUTF8));
		computeButton->setText(
				QApplication::translate("MainWindow", "Compute", 0,
						QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNOJ5747_H
