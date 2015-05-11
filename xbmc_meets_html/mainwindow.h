#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QString>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPath();
    void addTreeRoot(std::string folder, std::string movie, std::string cover, std::string nfo);

private slots:
    void on_checkBox_HTMLMovie_clicked();

    void on_pushButton_Start_clicked();

    void on_checkBox_HTMLIndex_clicked();

    void on_actionEinstellungen_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
