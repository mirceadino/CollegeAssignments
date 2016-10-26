/********************************************************************************
 ** Form generated from reading UI file 'observeruy6824.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef OBSERVERUY6824_H
#define OBSERVERUY6824_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OMainWindow {
  public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow, std::string title) {
      if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
      MainWindow->resize(544, 260);
      centralwidget = new QWidget(MainWindow);
      centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
      verticalLayoutWidget = new QWidget(centralwidget);
      verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
      verticalLayoutWidget->setGeometry(QRect(10, 10, 521, 161));
      verticalLayout = new QVBoxLayout(verticalLayoutWidget);
      verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
      verticalLayout->setContentsMargins(0, 0, 0, 0);
      label = new QLabel(verticalLayoutWidget);
      label->setObjectName(QString::fromUtf8("label"));

      verticalLayout->addWidget(label);

      listWidget = new QListWidget(verticalLayoutWidget);
      listWidget->setObjectName(QString::fromUtf8("listWidget"));

      verticalLayout->addWidget(listWidget);

      label_2 = new QLabel(verticalLayoutWidget);
      label_2->setObjectName(QString::fromUtf8("label_2"));

      verticalLayout->addWidget(label_2);

      horizontalLayoutWidget = new QWidget(centralwidget);
      horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
      horizontalLayoutWidget->setGeometry(QRect(10, 180, 521, 31));
      horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
      horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
      horizontalLayout->setContentsMargins(0, 0, 0, 0);
      lineEdit = new QLineEdit(horizontalLayoutWidget);
      lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

      horizontalLayout->addWidget(lineEdit);

      pushButton = new QPushButton(horizontalLayoutWidget);
      pushButton->setObjectName(QString::fromUtf8("pushButton"));

      horizontalLayout->addWidget(pushButton);

      MainWindow->setCentralWidget(centralwidget);
      menubar = new QMenuBar(MainWindow);
      menubar->setObjectName(QString::fromUtf8("menubar"));
      menubar->setGeometry(QRect(0, 0, 544, 25));
      MainWindow->setMenuBar(menubar);
      statusbar = new QStatusBar(MainWindow);
      statusbar->setObjectName(QString::fromUtf8("statusbar"));
      MainWindow->setStatusBar(statusbar);

      retranslateUi(MainWindow, title);

      QMetaObject::connectSlotsByName(MainWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *MainWindow, std::string title) {
      MainWindow->setWindowTitle(QApplication::translate("MainWindow", title.c_str(), 0, QApplication::UnicodeUTF8));
      label->setText(QApplication::translate("MainWindow", "Your students :", 0, QApplication::UnicodeUTF8));
      label_2->setText(QApplication::translate("MainWindow", "Grade selected student :", 0, QApplication::UnicodeUTF8));
      pushButton->setText(QApplication::translate("MainWindow", "Grade", 0, QApplication::UnicodeUTF8));
    }  // retranslateUi

};

namespace OUi {
class MainWindow: public Ui_OMainWindow {
};
}  // namespace Ui

QT_END_NAMESPACE

#endif // OBSERVERUY6824_H
