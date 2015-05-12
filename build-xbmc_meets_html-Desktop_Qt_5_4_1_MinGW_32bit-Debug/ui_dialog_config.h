/********************************************************************************
** Form generated from reading UI file 'dialog_config.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CONFIG_H
#define UI_DIALOG_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Config
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_nfo_0;
    QRadioButton *radioButton_nfo_1;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_cover_line;
    QSpinBox *spinBox_cover_line;
    QLabel *label_cover_column;
    QSpinBox *spinBox_cover_column;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_cover_0;
    QRadioButton *radioButton_cover_1;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QDialog *Dialog_Config)
    {
        if (Dialog_Config->objectName().isEmpty())
            Dialog_Config->setObjectName(QStringLiteral("Dialog_Config"));
        Dialog_Config->resize(507, 185);
        gridLayout_4 = new QGridLayout(Dialog_Config);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_2 = new QGroupBox(Dialog_Config);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(160, 80));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton_nfo_0 = new QRadioButton(groupBox_2);
        buttonGroup_2 = new QButtonGroup(Dialog_Config);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_nfo_0);
        radioButton_nfo_0->setObjectName(QStringLiteral("radioButton_nfo_0"));

        gridLayout_2->addWidget(radioButton_nfo_0, 0, 0, 1, 1);

        radioButton_nfo_1 = new QRadioButton(groupBox_2);
        buttonGroup_2->addButton(radioButton_nfo_1);
        radioButton_nfo_1->setObjectName(QStringLiteral("radioButton_nfo_1"));

        gridLayout_2->addWidget(radioButton_nfo_1, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(Dialog_Config);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(160, 80));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_cover_line = new QLabel(groupBox_3);
        label_cover_line->setObjectName(QStringLiteral("label_cover_line"));

        gridLayout->addWidget(label_cover_line, 0, 0, 1, 1);

        spinBox_cover_line = new QSpinBox(groupBox_3);
        spinBox_cover_line->setObjectName(QStringLiteral("spinBox_cover_line"));
        spinBox_cover_line->setMinimum(1);

        gridLayout->addWidget(spinBox_cover_line, 0, 1, 1, 1);

        label_cover_column = new QLabel(groupBox_3);
        label_cover_column->setObjectName(QStringLiteral("label_cover_column"));

        gridLayout->addWidget(label_cover_column, 1, 0, 1, 1);

        spinBox_cover_column = new QSpinBox(groupBox_3);
        spinBox_cover_column->setObjectName(QStringLiteral("spinBox_cover_column"));
        spinBox_cover_column->setMinimum(1);

        gridLayout->addWidget(spinBox_cover_column, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox = new QGroupBox(Dialog_Config);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(160, 80));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        radioButton_cover_0 = new QRadioButton(groupBox);
        buttonGroup = new QButtonGroup(Dialog_Config);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_cover_0);
        radioButton_cover_0->setObjectName(QStringLiteral("radioButton_cover_0"));

        gridLayout_3->addWidget(radioButton_cover_0, 0, 0, 1, 1);

        radioButton_cover_1 = new QRadioButton(groupBox);
        buttonGroup->addButton(radioButton_cover_1);
        radioButton_cover_1->setObjectName(QStringLiteral("radioButton_cover_1"));

        gridLayout_3->addWidget(radioButton_cover_1, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog_Config);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 1, 1, 1, 1);


        retranslateUi(Dialog_Config);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Config, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Config, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Config);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Config)
    {
        Dialog_Config->setWindowTitle(QApplication::translate("Dialog_Config", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog_Config", "Namensgebung der nfo Datei", 0));
        radioButton_nfo_0->setText(QApplication::translate("Dialog_Config", "movie.nfo", 0));
        radioButton_nfo_1->setText(QApplication::translate("Dialog_Config", "[Filmdatei].nfo", 0));
        groupBox_3->setTitle(QApplication::translate("Dialog_Config", "Einstellungen HTML Filmindex", 0));
        label_cover_line->setText(QApplication::translate("Dialog_Config", "Cover pro Zeile", 0));
        label_cover_column->setText(QApplication::translate("Dialog_Config", "Cover pro Spalte", 0));
        groupBox->setTitle(QApplication::translate("Dialog_Config", "Namensgebung des Filmcover", 0));
        radioButton_cover_0->setText(QApplication::translate("Dialog_Config", "folder.jpg", 0));
        radioButton_cover_1->setText(QApplication::translate("Dialog_Config", "[Filmdatei]-poster.jpg", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Config: public Ui_Dialog_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CONFIG_H
