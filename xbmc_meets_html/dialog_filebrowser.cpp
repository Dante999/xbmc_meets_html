#include <iostream>
#include <string>

#include "dialog_filebrowser.h"
#include "ui_dialog_filebrowser.h"
#include "configfile.h"




Dialog_FileBrowser::Dialog_FileBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_FileBrowser)
{
    ui->setupUi(this);

    QString sPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    ui->treeView_FileBrowser->setModel(dirmodel);
}

Dialog_FileBrowser::~Dialog_FileBrowser()
{
    delete ui;
}

void Dialog_FileBrowser::on_buttonBox_accepted()
{
    ConfigFile oConfigFile;

    oConfigFile.setValue(this->strConfigValue, this->qstrNewPath.toStdString());
}

void Dialog_FileBrowser::on_treeView_FileBrowser_clicked(const QModelIndex &index)
{
    this->qstrNewPath = dirmodel->filePath(index);
}

void Dialog_FileBrowser::setConfigValue( std::string strConfigValue)
{
    this->strConfigValue = strConfigValue;
}
