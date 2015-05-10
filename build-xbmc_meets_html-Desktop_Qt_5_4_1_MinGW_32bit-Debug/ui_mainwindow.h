/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTreeWidget *treeWidget;
    QProgressBar *progressBar;
    QSplitter *splitter_2;
    QLabel *label;
    QLineEdit *lineEdit_moviepath;
    QToolButton *toolButton;
    QSplitter *splitter;
    QLabel *label_2;
    QLineEdit *lineEdit_indexpath;
    QToolButton *toolButton_2;
    QSplitter *splitter_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QMenuBar *menuBar;
    QMenu *menuEinstellungen;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(587, 565);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 220, 75, 23));
        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(15, 91, 341, 371));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(380, 270, 181, 23));
        progressBar->setValue(24);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(30, 20, 274, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QStringLiteral("label"));
        splitter_2->addWidget(label);
        lineEdit_moviepath = new QLineEdit(splitter_2);
        lineEdit_moviepath->setObjectName(QStringLiteral("lineEdit_moviepath"));
        lineEdit_moviepath->setReadOnly(true);
        splitter_2->addWidget(lineEdit_moviepath);
        toolButton = new QToolButton(splitter_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        splitter_2->addWidget(toolButton);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(30, 60, 280, 20));
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter->addWidget(label_2);
        lineEdit_indexpath = new QLineEdit(splitter);
        lineEdit_indexpath->setObjectName(QStringLiteral("lineEdit_indexpath"));
        lineEdit_indexpath->setReadOnly(true);
        splitter->addWidget(lineEdit_indexpath);
        toolButton_2 = new QToolButton(splitter);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        splitter->addWidget(toolButton_2);
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(380, 170, 191, 34));
        splitter_3->setOrientation(Qt::Vertical);
        checkBox = new QCheckBox(splitter_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        splitter_3->addWidget(checkBox);
        checkBox_2 = new QCheckBox(splitter_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        splitter_3->addWidget(checkBox_2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 587, 21));
        menuEinstellungen = new QMenu(menuBar);
        menuEinstellungen->setObjectName(QStringLiteral("menuEinstellungen"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuEinstellungen->menuAction());
        menuBar->addAction(menuInfo->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Start", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Nfo", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Cover", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Filmdatei", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Pfad", 0));
        label->setText(QApplication::translate("MainWindow", "Pfad zu den Filmordnern", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        label_2->setText(QApplication::translate("MainWindow", "Export Pfad Film\303\274bersicht", 0));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0));
        checkBox->setText(QApplication::translate("MainWindow", "HTML Datei im Filmordner erzeugen", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "HTMLFilm\303\274bersicht erzeugen", 0));
        menuEinstellungen->setTitle(QApplication::translate("MainWindow", "Einstellungen", 0));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
