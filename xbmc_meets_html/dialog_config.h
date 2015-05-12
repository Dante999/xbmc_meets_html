#ifndef DIALOG_CONFIG_H
#define DIALOG_CONFIG_H

#include <QDialog>

namespace Ui {
class Dialog_Config;
}

class Dialog_Config : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Config(QWidget *parent = 0);
    ~Dialog_Config();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_Config *ui;
    void readConfig();
};

#endif // DIALOG_CONFIG_H
