#include "dialog_config.h"
#include "ui_dialog_config.h"
#include "configfile.h"
#include "mainwindow.h"

#include <string>
#include <iostream>

Dialog_Config::Dialog_Config(QWidget *parent):QDialog(parent),ui(new Ui::Dialog_Config)
{
    ui->setupUi(this);
    readConfig();
}

Dialog_Config::~Dialog_Config()
{
    delete ui;
}

void Dialog_Config::readConfig()
{
    std::string strBuffer;
    ConfigFile oConfigFile;

    oConfigFile.getValue(CFG_NAME_COVER, strBuffer);

    if(strBuffer == "0")
    {
        ui->radioButton_cover_0->setChecked(true);
    }

    else if(strBuffer == "1")
    {
        ui->radioButton_cover_1->setChecked(true);
    }

    oConfigFile.getValue(CFG_NAME_NFO, strBuffer);

    if(strBuffer == "0")
    {
        ui->radioButton_nfo_0->setChecked(true);
    }

    else if(strBuffer == "1")
    {
        ui->radioButton_nfo_1->setChecked(true);
    }

    //TODO Einlesen der Cover pro Zeile
    //TODO Einlesen der Cover pro Spalte
}

void Dialog_Config::on_buttonBox_accepted()
{
    ConfigFile oConfigFile;

    if(ui->radioButton_cover_0->isChecked())
    {
        oConfigFile.setValue(CFG_NAME_COVER, "0");
    }
    else if(ui->radioButton_cover_1->isChecked())
    {
        oConfigFile.setValue(CFG_NAME_COVER, "1");
    }
    else
    {
        std::cout << "unerwarteter Zustand Configuration->NAME_COVER!" << std::endl;
    }

    if(ui->radioButton_nfo_0->isChecked())
    {
        oConfigFile.setValue(CFG_NAME_NFO, "0");
    }
    else if(ui->radioButton_nfo_1->isChecked())
    {
        oConfigFile.setValue(CFG_NAME_NFO, "1");
    }
    else
    {
        std::cout << "unerwarteter Zustand Configuration->NAME_NFO!" << std::endl;
    }

    //TODO Einstellungen cover pro Zeile in config schreiben
    //TODO Einstellungen cover pro Spalte in config schreiben

}
