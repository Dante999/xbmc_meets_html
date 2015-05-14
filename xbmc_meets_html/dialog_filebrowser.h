#ifndef DIALOG_FILEBROWSER_H
#define DIALOG_FILEBROWSER_H

#include <QDialog>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QString>

namespace Ui {
class Dialog_FileBrowser;
}

class Dialog_FileBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_FileBrowser(QWidget *parent = 0);
    ~Dialog_FileBrowser();
    void setConfigValue( std::string strConfigValue);

private slots:
    void on_buttonBox_accepted();

    void on_treeView_FileBrowser_clicked(const QModelIndex &index);

private:
    Ui::Dialog_FileBrowser *ui;
    QFileSystemModel *dirmodel;
    QString qstrNewPath;
    std::string strConfigValue;
};

#endif // DIALOG_FILEBROWSER_H
