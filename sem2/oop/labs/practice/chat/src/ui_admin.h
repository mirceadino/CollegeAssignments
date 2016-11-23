/********************************************************************************
** Form generated from reading UI file 'adminy24576.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADMINY24576_H
#define ADMINY24576_H

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

QT_BEGIN_NAMESPACE

class Ui_AdminMainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *users;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *username;
    QPushButton *enter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMainWindow)
    {
        if (AdminMainWindow->objectName().isEmpty())
            AdminMainWindow->setObjectName(QString::fromUtf8("AdminMainWindow"));
        AdminMainWindow->resize(402, 286);
        centralwidget = new QWidget(AdminMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        users = new QListWidget(centralwidget);
        users->setObjectName(QString::fromUtf8("users"));
        users->setGeometry(QRect(15, 21, 371, 181));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(19, 209, 371, 29));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        username = new QLineEdit(horizontalLayoutWidget);
        username->setObjectName(QString::fromUtf8("username"));

        horizontalLayout->addWidget(username);

        enter = new QPushButton(horizontalLayoutWidget);
        enter->setObjectName(QString::fromUtf8("enter"));

        horizontalLayout->addWidget(enter);

        AdminMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 402, 25));
        AdminMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminMainWindow->setStatusBar(statusbar);

        retranslateUi(AdminMainWindow);

        QMetaObject::connectSlotsByName(AdminMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMainWindow)
    {
        AdminMainWindow->setWindowTitle(QApplication::translate("AdminMainWindow", "Admin", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdminMainWindow", "New user: ", 0, QApplication::UnicodeUTF8));
        enter->setText(QApplication::translate("AdminMainWindow", "Enter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdminMainWindow: public Ui_AdminMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADMINY24576_H
