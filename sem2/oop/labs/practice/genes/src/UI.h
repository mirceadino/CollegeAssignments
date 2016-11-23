/********************************************************************************
 ** Form generated from reading UI file 'designr24248.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef DESIGNR24248_H
#define DESIGNR24248_H

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
    QLabel *label;
    QListWidget *listGenes;
    QPushButton *sortButton;
    QSpacerItem *horizontalSpacer_1;
    QLabel *geneInfoText;
    QLineEdit *showName;
    QLineEdit *showOrganism;
    QLineEdit *showSequence;
    QSpacerItem *horizontalSpacer_2;
    QLabel *countText;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputBeginning;
    QPushButton *countButton;
    QLineEdit *outputCounter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow) {
      if (MainWindow->objectName().isEmpty()) MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
      MainWindow->resize(617, 600);
      centralwidget = new QWidget(MainWindow);
      centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
      verticalLayoutWidget = new QWidget(centralwidget);
      verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
      verticalLayoutWidget->setGeometry(QRect(19, 19, 571, 531));
      verticalLayout = new QVBoxLayout(verticalLayoutWidget);
      verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
      verticalLayout->setContentsMargins(0, 0, 0, 0);
      label = new QLabel(verticalLayoutWidget);
      label->setObjectName(QString::fromUtf8("label"));

      verticalLayout->addWidget(label);

      listGenes = new QListWidget(verticalLayoutWidget);
      listGenes->setObjectName(QString::fromUtf8("listGenes"));

      verticalLayout->addWidget(listGenes);

      sortButton = new QPushButton(verticalLayoutWidget);
      sortButton->setObjectName(QString::fromUtf8("sortButton"));

      verticalLayout->addWidget(sortButton);

      horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

      verticalLayout->addItem(horizontalSpacer_1);

      geneInfoText = new QLabel(verticalLayoutWidget);
      geneInfoText->setObjectName(QString::fromUtf8("geneInfoText"));

      verticalLayout->addWidget(geneInfoText);

      showName = new QLineEdit(verticalLayoutWidget);
      showName->setObjectName(QString::fromUtf8("showName"));
      showName->setEnabled(false);

      verticalLayout->addWidget(showName);

      showOrganism = new QLineEdit(verticalLayoutWidget);
      showOrganism->setObjectName(QString::fromUtf8("showOrganism"));
      showOrganism->setEnabled(false);

      verticalLayout->addWidget(showOrganism);

      showSequence = new QLineEdit(verticalLayoutWidget);
      showSequence->setObjectName(QString::fromUtf8("showSequence"));
      showSequence->setEnabled(false);

      verticalLayout->addWidget(showSequence);

      horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

      verticalLayout->addItem(horizontalSpacer_2);

      countText = new QLabel(verticalLayoutWidget);
      countText->setObjectName(QString::fromUtf8("countText"));

      verticalLayout->addWidget(countText);

      horizontalLayout = new QHBoxLayout();
      horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
      inputBeginning = new QLineEdit(verticalLayoutWidget);
      inputBeginning->setObjectName(QString::fromUtf8("inputBeginning"));

      horizontalLayout->addWidget(inputBeginning);

      countButton = new QPushButton(verticalLayoutWidget);
      countButton->setObjectName(QString::fromUtf8("countButton"));

      horizontalLayout->addWidget(countButton);

      outputCounter = new QLineEdit(verticalLayoutWidget);
      outputCounter->setObjectName(QString::fromUtf8("outputCounter"));
      outputCounter->setEnabled(false);

      horizontalLayout->addWidget(outputCounter);

      verticalLayout->addLayout(horizontalLayout);

      MainWindow->setCentralWidget(centralwidget);
      menubar = new QMenuBar(MainWindow);
      menubar->setObjectName(QString::fromUtf8("menubar"));
      menubar->setGeometry(QRect(0, 0, 617, 25));
      MainWindow->setMenuBar(menubar);
      statusbar = new QStatusBar(MainWindow);
      statusbar->setObjectName(QString::fromUtf8("statusbar"));
      MainWindow->setStatusBar(statusbar);

      retranslateUi(MainWindow);

      QMetaObject::connectSlotsByName(MainWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
      MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gene Manager", 0, QApplication::UnicodeUTF8));
      label->setText(QApplication::translate("MainWindow", "Genes:", 0, QApplication::UnicodeUTF8));
      sortButton->setText(QApplication::translate("MainWindow", "Sort genes by organism !", 0, QApplication::UnicodeUTF8));
      geneInfoText->setText(QApplication::translate("MainWindow", "Information about the selected gene:", 0, QApplication::UnicodeUTF8));
      countText->setText(QApplication::translate("MainWindow", "Count the genes that whose sequences begin with a certain string:", 0, QApplication::UnicodeUTF8));
      countButton->setText(QApplication::translate("MainWindow", "Count genes !", 0, QApplication::UnicodeUTF8));
    }  // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {
};
}  // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNR24248_H
