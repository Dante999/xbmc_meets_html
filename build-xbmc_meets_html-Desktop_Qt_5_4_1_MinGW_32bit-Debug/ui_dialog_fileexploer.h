/********************************************************************************
** Form generated from reading UI file 'dialog_fileexploer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FILEEXPLOER_H
#define UI_DIALOG_FILEEXPLOER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_Dialog_FileExploer
{
public:
    QTreeView *treeView_FileExplorer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_FileExploer)
    {
        if (Dialog_FileExploer->objectName().isEmpty())
            Dialog_FileExploer->setObjectName(QStringLiteral("Dialog_FileExploer"));
        Dialog_FileExploer->resize(997, 518);
        treeView_FileExplorer = new QTreeView(Dialog_FileExploer);
        treeView_FileExplorer->setObjectName(QStringLiteral("treeView_FileExplorer"));
        treeView_FileExplorer->setGeometry(QRect(50, 10, 761, 381));
        buttonBox = new QDialogButtonBox(Dialog_FileExploer);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(350, 430, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Dialog_FileExploer);

        QMetaObject::connectSlotsByName(Dialog_FileExploer);
    } // setupUi

    void retranslateUi(QDialog *Dialog_FileExploer)
    {
        Dialog_FileExploer->setWindowTitle(QApplication::translate("Dialog_FileExploer", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_FileExploer: public Ui_Dialog_FileExploer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FILEEXPLOER_H
