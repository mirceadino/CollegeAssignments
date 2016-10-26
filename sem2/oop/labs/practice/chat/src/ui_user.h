/********************************************************************************
 ** Form generated from reading UI file 'admint24576.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef ADMINT24576_H
#define ADMINT24576_H

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
#include <QtGui/QWidget>
#include <string>

QT_BEGIN_NAMESPACE

class Ui_UserWindow {
  public:
    QWidget *centralwidget;
    QListWidget *messages;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *message;
    QPushButton *enter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow, std::string title) {
      if (UserWindow->objectName().isEmpty())
        UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
      UserWindow->resize(402, 286);
      centralwidget = new QWidget(UserWindow);
      centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
      messages = new QListWidget(centralwidget);
      messages->setObjectName(QString::fromUtf8("messages"));
      messages->setGeometry(QRect(15, 21, 371, 181));
      horizontalLayoutWidget = new QWidget(centralwidget);
      horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
      horizontalLayoutWidget->setGeometry(QRect(19, 209, 371, 29));
      horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
      horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
      horizontalLayout->setContentsMargins(0, 0, 0, 0);
      label = new QLabel(horizontalLayoutWidget);
      label->setObjectName(QString::fromUtf8("label"));

      horizontalLayout->addWidget(label);

      message = new QLineEdit(horizontalLayoutWidget);
      message->setObjectName(QString::fromUtf8("message"));

      horizontalLayout->addWidget(message);

      enter = new QPushButton(horizontalLayoutWidget);
      enter->setObjectName(QString::fromUtf8("enter"));

      horizontalLayout->addWidget(enter);

      UserWindow->setCentralWidget(centralwidget);
      menubar = new QMenuBar(UserWindow);
      menubar->setObjectName(QString::fromUtf8("menubar"));
      menubar->setGeometry(QRect(0, 0, 402, 25));
      UserWindow->setMenuBar(menubar);
      statusbar = new QStatusBar(UserWindow);
      statusbar->setObjectName(QString::fromUtf8("statusbar"));
      UserWindow->setStatusBar(statusbar);

      retranslateUi(UserWindow, title);

      QMetaObject::connectSlotsByName(UserWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *UserWindow, std::string title) {
      UserWindow->setWindowTitle(QApplication::translate("UserWindow", title.c_str(), 0, QApplication::UnicodeUTF8));
      label->setText(QApplication::translate("UserWindow", "Message:", 0, QApplication::UnicodeUTF8));
      enter->setText(QApplication::translate("UserWindow", "Enter", 0, QApplication::UnicodeUTF8));
    }  // retranslateUi

};

namespace Ui {
class UserWindow: public Ui_UserWindow {
};
}  // namespace Ui

QT_END_NAMESPACE

#endif // ADMINT24576_H
