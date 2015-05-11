#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configfile.h"

#include "fileoperations.h"
#include "stringtools.h"
#include "moviefolder.h"
#include "dialog_config.h"

#include <string>
#include <vector>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPath();    
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setPath()
{
    std::string strBuffer = "";

    ConfigFile oConfigFile;

    oConfigFile.getValue("path_movies", strBuffer);
    ui->lineEdit_moviepath->setText(QString::fromStdString(strBuffer));

    oConfigFile.getValue("path_index", strBuffer);
    ui->lineEdit_indexpath->setText(QString::fromStdString(strBuffer));

    oConfigFile.getValue("do_movieHTML", strBuffer);
    if(strBuffer == "1") ui->checkBox_HTMLMovie->setChecked(true);
    else                ui->checkBox_HTMLMovie->setChecked(false);

    oConfigFile.getValue("do_indexHTML", strBuffer);
    if(strBuffer == "1") ui->checkBox_HTMLIndex->setChecked(true);
    else                ui->checkBox_HTMLIndex->setChecked(false);


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
}


void MainWindow::on_pushButton_Start_clicked()
{
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

}

void MainWindow::addTreeRoot(std::string folder, std::string movie, std::string cover, std::string nfo)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget_Filmordner);
    std::cout << folder << std::endl;
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
}
