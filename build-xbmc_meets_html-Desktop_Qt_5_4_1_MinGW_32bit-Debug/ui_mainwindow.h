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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEinstellungen;
    QWidget *centralWidget;
    QPushButton *pushButton_Start;
    QTreeWidget *treeWidget_Filmordner;
    QProgressBar *progressBar;
    QSplitter *splitter_3;
    QCheckBox *checkBox_HTMLMovie;
    QCheckBox *checkBox_HTMLIndex;
    QTextBrowser *textBrowser_Commandline;
    QLabel *label_3;
    QLineEdit *lineEdit_moviepath;
    QLabel *label;
    QToolButton *toolButton_moviepath;
    QLabel *label_2;
    QLineEdit *lineEdit_indexpath;
    QToolButton *toolButton_indexpath;
    QMenuBar *menuBar;
    QMenu *menuEinstellungen;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1092, 565);
        actionEinstellungen = new QAction(MainWindow);
        actionEinstellungen->setObjectName(QStringLiteral("actionEinstellungen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(890, 150, 75, 23));
        treeWidget_Filmordner = new QTreeWidget(centralWidget);
        treeWidget_Filmordner->setObjectName(QStringLiteral("treeWidget_Filmordner"));
        treeWidget_Filmordner->setGeometry(QRect(20, 100, 771, 401));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(880, 190, 181, 23));
        progressBar->setValue(24);
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(860, 100, 191, 34));
        splitter_3->setOrientation(Qt::Vertical);
        checkBox_HTMLMovie = new QCheckBox(splitter_3);
        checkBox_HTMLMovie->setObjectName(QStringLiteral("checkBox_HTMLMovie"));
        splitter_3->addWidget(checkBox_HTMLMovie);
        checkBox_HTMLIndex = new QCheckBox(splitter_3);
        checkBox_HTMLIndex->setObjectName(QStringLiteral("checkBox_HTMLIndex"));
        splitter_3->addWidget(checkBox_HTMLIndex);
        textBrowser_Commandline = new QTextBrowser(centralWidget);
        textBrowser_Commandline->setObjectName(QStringLiteral("textBrowser_Commandline"));
        textBrowser_Commandline->setGeometry(QRect(850, 230, 191, 192));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(900, 10, 191, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Plain);
        label_3->setTextFormat(Qt::AutoText);
        lineEdit_moviepath = new QLineEdit(centralWidget);
        lineEdit_moviepath->setObjectName(QStringLiteral("lineEdit_moviepath"));
        lineEdit_moviepath->setGeometry(QRect(150, 20, 300, 20));
        lineEdit_moviepath->setReadOnly(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 116, 16));
        toolButton_moviepath = new QToolButton(centralWidget);
        toolButton_moviepath->setObjectName(QStringLiteral("toolButton_moviepath"));
        toolButton_moviepath->setGeometry(QRect(460, 20, 25, 19));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 122, 16));
        lineEdit_indexpath = new QLineEdit(centralWidget);
        lineEdit_indexpath->setObjectName(QStringLiteral("lineEdit_indexpath"));
        lineEdit_indexpath->setGeometry(QRect(150, 60, 300, 20));
        lineEdit_indexpath->setReadOnly(true);
        toolButton_indexpath = new QToolButton(centralWidget);
        toolButton_indexpath->setObjectName(QStringLiteral("toolButton_indexpath"));
        toolButton_indexpath->setGeometry(QRect(460, 60, 25, 19));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1092, 21));
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
        menuEinstellungen->addAction(actionEinstellungen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionEinstellungen->setText(QApplication::translate("MainWindow", "Einstellungen", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "Start", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_Filmordner->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Nfo", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Cover", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Filmdatei", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Ordner", 0));
        checkBox_HTMLMovie->setText(QApplication::translate("MainWindow", "HTML Datei im Filmordner erzeugen", 0));
        checkBox_HTMLIndex->setText(QApplication::translate("MainWindow", "HTMLFilm\303\274bersicht erzeugen", 0));
        textBrowser_Commandline->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "by Dante999", 0));
        label->setText(QApplication::translate("MainWindow", "Pfad zu den Filmordnern", 0));
        toolButton_moviepath->setText(QApplication::translate("MainWindow", "...", 0));
        label_2->setText(QApplication::translate("MainWindow", "Export Pfad Film\303\274bersicht", 0));
        toolButton_indexpath->setText(QApplication::translate("MainWindow", "...", 0));
        menuEinstellungen->setTitle(QApplication::translate("MainWindow", "Einstellungen", 0));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
