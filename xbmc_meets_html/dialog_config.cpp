#include "dialog_config.h"
#include "ui_dialog_config.h"
#include "configfile.h"

#include <string>

Dialog_Config::Dialog_Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Config)
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





}
