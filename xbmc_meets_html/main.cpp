#include "mainwindow.h"
#include <QApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "XBMC to HTML creator" << std::endl;
    std::cout << "created by Dante999" << std::endl;
    std::cout << "#################################################" << std::endl << std::endl;


    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("XBMC meets HTML");
    w.show();





    return a.exec();
}
