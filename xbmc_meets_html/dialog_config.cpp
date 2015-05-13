#include "dialog_config.h"
#include "ui_dialog_config.h"
#include "configfile.h"
#include "mainwindow.h"
#include "stringtools.h"

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
    if(strBuffer == "0")        ui->radioButton_cover_0->setChecked(true);
    else if(strBuffer == "1")   ui->radioButton_cover_1->setChecked(true);

    oConfigFile.getValue(CFG_NAME_NFO, strBuffer);
    if(strBuffer == "0")        ui->radioButton_nfo_0->setChecked(true);
    else if(strBuffer == "1")   ui->radioButton_nfo_1->setChecked(true);

    oConfigFile.getValue(CFG_COVER_LINE, strBuffer);
    ui->spinBox_cover_line->setValue(StringTools::strToint(strBuffer));

    oConfigFile.getValue(CFG_COVER_COLUMN, strBuffer);
    ui->spinBox_cover_column->setValue(StringTools::strToint(strBuffer));
}

void Dialog_Config::on_buttonBox_accepted()
{
    ConfigFile oConfigFile;
    int iBuffer;
    std::string strBuffer;
    QString qstrBuffer;

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

    qstrBuffer = ui->spinBox_cover_line->text();
    strBuffer = qstrBuffer.toStdString();
    oConfigFile.setValue(CFG_COVER_LINE, strBuffer);

    qstrBuffer = ui->spinBox_cover_column->text();
    strBuffer = qstrBuffer.toStdString();
    oConfigFile.setValue(CFG_COVER_COLUMN, strBuffer);
}
