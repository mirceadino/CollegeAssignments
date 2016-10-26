/********************************************************************************
** Form generated from reading UI file 'subjectFg6824.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SUBJECTFG6824_H
#define SUBJECTFG6824_H

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
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *studentsList;
    QPushButton *removeStudentButton;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditName;
    QLineEdit *lineEditGroup;
    QPushButton *addStudentButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(687, 343);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 19, 651, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        studentsList = new QListWidget(verticalLayoutWidget);
        studentsList->setObjectName(QString::fromUtf8("studentsList"));

        verticalLayout->addWidget(studentsList);

        removeStudentButton = new QPushButton(verticalLayoutWidget);
        removeStudentButton->setObjectName(QString::fromUtf8("removeStudentButton"));

        verticalLayout->addWidget(removeStudentButton);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 210, 66, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 240, 66, 17));
        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(100, 210, 571, 27));
        lineEditGroup = new QLineEdit(centralwidget);
        lineEditGroup->setObjectName(QString::fromUtf8("lineEditGroup"));
        lineEditGroup->setGeometry(QRect(100, 240, 571, 27));
        addStudentButton = new QPushButton(centralwidget);
        addStudentButton->setObjectName(QString::fromUtf8("addStudentButton"));
        addStudentButton->setGeometry(QRect(20, 270, 651, 27));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 687, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Main Teacher", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Students:", 0, QApplication::UnicodeUTF8));
        removeStudentButton->setText(QApplication::translate("MainWindow", "Remove student", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Group:", 0, QApplication::UnicodeUTF8));
        addStudentButton->setText(QApplication::translate("MainWindow", "Add student", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SUBJECTFG6824_H
