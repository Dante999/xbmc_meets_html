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


private slots:
    void initValuesFromConfig();
    void addTreeRoot(std::string folder, std::string movie, std::string cover, std::string nfo);
    void fillTreeWidget();
    void on_checkBox_HTMLMovie_clicked();
    void on_pushButton_Start_clicked();
    void on_checkBox_HTMLIndex_clicked();
    void on_actionEinstellungen_triggered();
    void on_lineEdit_moviepath_returnPressed();
    void on_toolButton_moviepath_clicked();

    void on_toolButton_indexpath_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
