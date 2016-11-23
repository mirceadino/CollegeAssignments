/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGN_H
#define UI_DESIGN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
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
    QListWidget *listWidget;
    QPushButton *pushButtonSort;
    QLineEdit *lineEditCountry;
    QLineEdit *lineEditSinger;
    QLineEdit *lineEditSong;
    QLineEdit *lineEditVotes;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(736, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(159, 59, 461, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButtonSort = new QPushButton(verticalLayoutWidget);
        pushButtonSort->setObjectName(QString::fromUtf8("pushButtonSort"));

        verticalLayout->addWidget(pushButtonSort);

        lineEditCountry = new QLineEdit(verticalLayoutWidget);
        lineEditCountry->setObjectName(QString::fromUtf8("lineEditCountry"));
        lineEditCountry->setEnabled(false);

        verticalLayout->addWidget(lineEditCountry);

        lineEditSinger = new QLineEdit(verticalLayoutWidget);
        lineEditSinger->setObjectName(QString::fromUtf8("lineEditSinger"));
        lineEditSinger->setEnabled(false);

        verticalLayout->addWidget(lineEditSinger);

        lineEditSong = new QLineEdit(verticalLayoutWidget);
        lineEditSong->setObjectName(QString::fromUtf8("lineEditSong"));
        lineEditSong->setEnabled(false);

        verticalLayout->addWidget(lineEditSong);

        lineEditVotes = new QLineEdit(verticalLayoutWidget);
        lineEditVotes->setObjectName(QString::fromUtf8("lineEditVotes"));
        lineEditVotes->setEnabled(false);

        verticalLayout->addWidget(lineEditVotes);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        MainWindow->setCentralWidget(centralwidget);
        verticalLayoutWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 736, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButtonSort->setText(QApplication::translate("MainWindow", "Sort", 0, QApplication::UnicodeUTF8));
        lineEditCountry->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Vote", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGN_H
