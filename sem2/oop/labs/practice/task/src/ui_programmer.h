/********************************************************************************
 ** Form generated from reading UI file 'programmeryB1679.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef PROGRAMMERYB1679_H
#define PROGRAMMERYB1679_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
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
#include <string>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
  public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *tasks;
    QHBoxLayout *horizontalLayout;
    QPushButton *removeButton;
    QPushButton *startButton;
    QPushButton *finishButton;
    QFrame *line;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *description;
    QPushButton *addButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow, std::string title) {
      if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
      MainWindow->resize(467, 325);
      centralwidget = new QWidget(MainWindow);
      centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
      verticalLayoutWidget = new QWidget(centralwidget);
      verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
      verticalLayoutWidget->setGeometry(QRect(10, 4, 441, 271));
      verticalLayout = new QVBoxLayout(verticalLayoutWidget);
      verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
      verticalLayout->setContentsMargins(0, 0, 0, 0);
      label = new QLabel(verticalLayoutWidget);
      label->setObjectName(QString::fromUtf8("label"));

      verticalLayout->addWidget(label);

      tasks = new QListWidget(verticalLayoutWidget);
      tasks->setObjectName(QString::fromUtf8("tasks"));

      verticalLayout->addWidget(tasks);

      horizontalLayout = new QHBoxLayout();
      horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
      removeButton = new QPushButton(verticalLayoutWidget);
      removeButton->setObjectName(QString::fromUtf8("removeButton"));

      horizontalLayout->addWidget(removeButton);

      startButton = new QPushButton(verticalLayoutWidget);
      startButton->setObjectName(QString::fromUtf8("startButton"));

      horizontalLayout->addWidget(startButton);

      finishButton = new QPushButton(verticalLayoutWidget);
      finishButton->setObjectName(QString::fromUtf8("finishButton"));

      horizontalLayout->addWidget(finishButton);

      verticalLayout->addLayout(horizontalLayout);

      line = new QFrame(verticalLayoutWidget);
      line->setObjectName(QString::fromUtf8("line"));
      line->setFrameShape(QFrame::HLine);
      line->setFrameShadow(QFrame::Sunken);

      verticalLayout->addWidget(line);

      label_2 = new QLabel(verticalLayoutWidget);
      label_2->setObjectName(QString::fromUtf8("label_2"));

      verticalLayout->addWidget(label_2);

      horizontalLayout_2 = new QHBoxLayout();
      horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
      description = new QLineEdit(verticalLayoutWidget);
      description->setObjectName(QString::fromUtf8("description"));

      horizontalLayout_2->addWidget(description);

      addButton = new QPushButton(verticalLayoutWidget);
      addButton->setObjectName(QString::fromUtf8("addButton"));

      horizontalLayout_2->addWidget(addButton);

      verticalLayout->addLayout(horizontalLayout_2);

      MainWindow->setCentralWidget(centralwidget);
      menubar = new QMenuBar(MainWindow);
      menubar->setObjectName(QString::fromUtf8("menubar"));
      menubar->setGeometry(QRect(0, 0, 467, 25));
      MainWindow->setMenuBar(menubar);
      statusbar = new QStatusBar(MainWindow);
      statusbar->setObjectName(QString::fromUtf8("statusbar"));
      MainWindow->setStatusBar(statusbar);

      retranslateUi(MainWindow, title);

      QMetaObject::connectSlotsByName(MainWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *MainWindow, std::string title) {
      MainWindow->setWindowTitle(QApplication::translate("MainWindow", title.c_str(), 0, QApplication::UnicodeUTF8));
      label->setText(QApplication::translate("MainWindow", "Tasks :", 0, QApplication::UnicodeUTF8));
      removeButton->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
      startButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
      finishButton->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
      label_2->setText(QApplication::translate("MainWindow", "Add a new task :", 0, QApplication::UnicodeUTF8));
      addButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
    }  // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {
};
}  // namespace Ui

QT_END_NAMESPACE

#endif // PROGRAMMERYB1679_H
