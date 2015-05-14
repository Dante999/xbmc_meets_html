/********************************************************************************
** Form generated from reading UI file 'dialog_filebrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FILEBROWSER_H
#define UI_DIALOG_FILEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_Dialog_FileBrowser
{
public:
    QGridLayout *gridLayout;
    QTreeView *treeView_FileBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_FileBrowser)
    {
        if (Dialog_FileBrowser->objectName().isEmpty())
            Dialog_FileBrowser->setObjectName(QStringLiteral("Dialog_FileBrowser"));
        Dialog_FileBrowser->resize(622, 468);
        gridLayout = new QGridLayout(Dialog_FileBrowser);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeView_FileBrowser = new QTreeView(Dialog_FileBrowser);
        treeView_FileBrowser->setObjectName(QStringLiteral("treeView_FileBrowser"));

        gridLayout->addWidget(treeView_FileBrowser, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog_FileBrowser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(Dialog_FileBrowser);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_FileBrowser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_FileBrowser, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_FileBrowser);
    } // setupUi

    void retranslateUi(QDialog *Dialog_FileBrowser)
    {
        Dialog_FileBrowser->setWindowTitle(QApplication::translate("Dialog_FileBrowser", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_FileBrowser: public Ui_Dialog_FileBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FILEBROWSER_H
