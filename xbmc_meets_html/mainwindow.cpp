#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configfile.h"

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


MainWindow::setPath()
{
    ui->lineEdit_indexpath->setText("Hallo");

}
