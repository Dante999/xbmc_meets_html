#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configfile.h"

#include <QMessageBox>

#include "fileoperations.h"
#include "stringtools.h"
#include "moviefolder.h"
#include "dialog_config.h"
#include "dialog_filebrowser.h"

#include <string>
#include <vector>
#include <iostream>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    //ui->textBrowser_Commandline->append(">> Überprüfe Einstellungen...");
    if(FileOperations::fileExists(PATH_TO_CONFIG) == false)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Keine Config.ini vorhanden!");
        msgBox.setText("Es wurde keine config.ini gefunden!\n");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }

    else
    {
        ui->setupUi(this);
        ui->textBrowser_Commandline->append(">> config.ini vorhanden");
        initValuesFromConfig();

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initValuesFromConfig()
{
    std::string strBuffer = "";
    ConfigFile oConfigFile;    

    oConfigFile.getValue(CFG_PATH_MOVIES, strBuffer);
    ui->lineEdit_moviepath->setText(QString::fromStdString(strBuffer));

    oConfigFile.getValue(CFG_PATH_INDEX, strBuffer);
    ui->lineEdit_indexpath->setText(QString::fromStdString(strBuffer));

    oConfigFile.getValue(CFG_DO_MOVIE_HTML, strBuffer);
    if(strBuffer == "1") ui->checkBox_HTMLMovie->setChecked(true);
    else                ui->checkBox_HTMLMovie->setChecked(false);

    oConfigFile.getValue(CFG_DO_INDEX_HTML, strBuffer);
    if(strBuffer == "1") ui->checkBox_HTMLIndex->setChecked(true);
    else                ui->checkBox_HTMLIndex->setChecked(false);

    fillTreeWidget();
}

void MainWindow::on_checkBox_HTMLMovie_clicked()
{
    ConfigFile oConfigFile;

    if(ui->checkBox_HTMLMovie->isChecked())
    {
        oConfigFile.setValue(CFG_DO_MOVIE_HTML, "1");
    }
    else
    {
        oConfigFile.setValue(CFG_DO_MOVIE_HTML, "0");
    }
    ui->textBrowser_Commandline->append(">> Einstellung gespeichert!");
}

void MainWindow::on_checkBox_HTMLIndex_clicked()
{
    ConfigFile oConfigFile;

    if(ui->checkBox_HTMLIndex->isChecked())
    {
        oConfigFile.setValue(CFG_DO_INDEX_HTML, "1");
    }
    else
    {
        oConfigFile.setValue(CFG_DO_INDEX_HTML, "0");
    }

    ui->textBrowser_Commandline->append(">> Einstellung gespeichert!");
}


void MainWindow::on_pushButton_Start_clicked()
{
    ui->textBrowser_Commandline->append(">> Vorgang gestartet...");
}

void MainWindow::addTreeRoot(std::string folder, std::string movie, std::string cover, std::string nfo)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget_Filmordner);    
    treeItem->setText(0, QString::fromStdString(folder));
    treeItem->setText(1, QString::fromStdString(movie));
    treeItem->setText(2, QString::fromStdString(cover));
    treeItem->setText(3, QString::fromStdString(nfo));
}



void MainWindow::on_actionEinstellungen_triggered()
{
    Dialog_Config *configWindow = new Dialog_Config();

    configWindow->setWindowTitle("Einstellungen");
    configWindow->show();
    configWindow->raise();
    configWindow->activateWindow();

    int test = configWindow->exec();

    if(test == 1)
    {
        ui->textBrowser_Commandline->append(">> Einstellungen gespeichert!");
        fillTreeWidget();
    }
    else
    {
        ui->textBrowser_Commandline->append(">> Einstellungen verworfen!");
    }

}

void MainWindow::on_lineEdit_moviepath_returnPressed()
{
    ConfigFile oConfigFile;

    QString qstrMoviePath = ui->lineEdit_moviepath->text();

    oConfigFile.setValue(CFG_PATH_MOVIES, qstrMoviePath.toStdString());
    fillTreeWidget();
}

void MainWindow::on_toolButton_moviepath_clicked()
{
    Dialog_FileBrowser *fileBrowser = new Dialog_FileBrowser;
    fileBrowser->setConfigValue(CFG_PATH_MOVIES);
    ConfigFile oConfigFile;
    std::string strMoviePath;

    fileBrowser->setWindowTitle("Datei Explorer");
    fileBrowser->show();
    fileBrowser->raise();
    fileBrowser->activateWindow();

    if(fileBrowser->exec() == 1)
    {
        oConfigFile.getValue(CFG_PATH_MOVIES, strMoviePath);
        ui->lineEdit_moviepath->setText(QString::fromStdString(strMoviePath));
        fillTreeWidget();
        ui->textBrowser_Commandline->append("Pfad zu den Filmordnern aktualisiert!");
    }

    /**
    ConfigFile oConfigFile;

    QString qstrMoviePath = ui->lineEdit_moviepath->text();

    oConfigFile.setValue(CFG_PATH_MOVIES, qstrMoviePath.toStdString());
    fillTreeWidget();
    **/

}

void MainWindow::fillTreeWidget()
{
    ui->treeWidget_Filmordner->clear();
    ConfigFile oConfigFile;
    std::string strPathToMovies;
    std::vector <std::string> strvecMovieFolders;

    oConfigFile.getValue(CFG_PATH_MOVIES, strPathToMovies);

    FileOperations::listFolders(strPathToMovies, strvecMovieFolders);

    unsigned int i;

    for(i=0; i<strvecMovieFolders.size(); i++)
    {
        MovieFolder oMovieFolder(strPathToMovies + "\\" + strvecMovieFolders[i]);
        addTreeRoot(strvecMovieFolders[i], oMovieFolder.getMovieFilename() , oMovieFolder.getMovieCovername(), oMovieFolder.getNfoFilename());
    }

    ui->textBrowser_Commandline->append(">> Ordnerliste aktualisiert");
}
