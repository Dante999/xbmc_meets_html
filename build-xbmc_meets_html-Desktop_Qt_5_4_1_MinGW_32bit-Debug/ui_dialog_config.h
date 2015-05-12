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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Config
{
public:
    QDialogButtonBox *buttonBox;
    QSplitter *splitter_cover;
    QLabel *label_cover_headline;
    QRadioButton *radioButton_cover_0;
    QRadioButton *radioButton_cover_1;
    QSplitter *splitter_nfo;
    QLabel *label_nfo_headline;
    QRadioButton *radioButton_nfo_0;
    QRadioButton *radioButton_nfo_1;
    QSplitter *splitter_index;
    QLabel *label_index_headline;
    QSplitter *splitter_cover_line;
    QLabel *label_cover_line;
    QSpinBox *spinBox_cover_line;
    QSplitter *splitter_cover_column;
    QLabel *label_cover_column;
    QSpinBox *spinBox_cover_column;

    void setupUi(QDialog *Dialog_Config)
    {
        if (Dialog_Config->objectName().isEmpty())
            Dialog_Config->setObjectName(QStringLiteral("Dialog_Config"));
        Dialog_Config->resize(541, 257);
        buttonBox = new QDialogButtonBox(Dialog_Config);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 220, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        splitter_cover = new QSplitter(Dialog_Config);
        splitter_cover->setObjectName(QStringLiteral("splitter_cover"));
        splitter_cover->setGeometry(QRect(20, 20, 147, 47));
        splitter_cover->setOrientation(Qt::Vertical);
        label_cover_headline = new QLabel(splitter_cover);
        label_cover_headline->setObjectName(QStringLiteral("label_cover_headline"));
        splitter_cover->addWidget(label_cover_headline);
        radioButton_cover_0 = new QRadioButton(splitter_cover);
        radioButton_cover_0->setObjectName(QStringLiteral("radioButton_cover_0"));
        splitter_cover->addWidget(radioButton_cover_0);
        radioButton_cover_1 = new QRadioButton(splitter_cover);
        radioButton_cover_1->setObjectName(QStringLiteral("radioButton_cover_1"));
        splitter_cover->addWidget(radioButton_cover_1);
        splitter_nfo = new QSplitter(Dialog_Config);
        splitter_nfo->setObjectName(QStringLiteral("splitter_nfo"));
        splitter_nfo->setGeometry(QRect(220, 20, 140, 47));
        splitter_nfo->setOrientation(Qt::Vertical);
        label_nfo_headline = new QLabel(splitter_nfo);
        label_nfo_headline->setObjectName(QStringLiteral("label_nfo_headline"));
        splitter_nfo->addWidget(label_nfo_headline);
        radioButton_nfo_0 = new QRadioButton(splitter_nfo);
        radioButton_nfo_0->setObjectName(QStringLiteral("radioButton_nfo_0"));
        splitter_nfo->addWidget(radioButton_nfo_0);
        radioButton_nfo_1 = new QRadioButton(splitter_nfo);
        radioButton_nfo_1->setObjectName(QStringLiteral("radioButton_nfo_1"));
        splitter_nfo->addWidget(radioButton_nfo_1);
        splitter_index = new QSplitter(Dialog_Config);
        splitter_index->setObjectName(QStringLiteral("splitter_index"));
        splitter_index->setGeometry(QRect(30, 120, 139, 53));
        splitter_index->setOrientation(Qt::Vertical);
        label_index_headline = new QLabel(splitter_index);
        label_index_headline->setObjectName(QStringLiteral("label_index_headline"));
        splitter_index->addWidget(label_index_headline);
        splitter_cover_line = new QSplitter(splitter_index);
        splitter_cover_line->setObjectName(QStringLiteral("splitter_cover_line"));
        splitter_cover_line->setOrientation(Qt::Horizontal);
        label_cover_line = new QLabel(splitter_cover_line);
        label_cover_line->setObjectName(QStringLiteral("label_cover_line"));
        splitter_cover_line->addWidget(label_cover_line);
        spinBox_cover_line = new QSpinBox(splitter_cover_line);
        spinBox_cover_line->setObjectName(QStringLiteral("spinBox_cover_line"));
        spinBox_cover_line->setMinimum(1);
        splitter_cover_line->addWidget(spinBox_cover_line);
        splitter_index->addWidget(splitter_cover_line);
        splitter_cover_column = new QSplitter(splitter_index);
        splitter_cover_column->setObjectName(QStringLiteral("splitter_cover_column"));
        splitter_cover_column->setOrientation(Qt::Horizontal);
        label_cover_column = new QLabel(splitter_cover_column);
        label_cover_column->setObjectName(QStringLiteral("label_cover_column"));
        splitter_cover_column->addWidget(label_cover_column);
        spinBox_cover_column = new QSpinBox(splitter_cover_column);
        spinBox_cover_column->setObjectName(QStringLiteral("spinBox_cover_column"));
        spinBox_cover_column->setMinimum(1);
        splitter_cover_column->addWidget(spinBox_cover_column);
        splitter_index->addWidget(splitter_cover_column);

        retranslateUi(Dialog_Config);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Config, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Config, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Config);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Config)
    {
        Dialog_Config->setWindowTitle(QApplication::translate("Dialog_Config", "Dialog", 0));
        label_cover_headline->setText(QApplication::translate("Dialog_Config", "Namensgebung des Filmcovers", 0));
        radioButton_cover_0->setText(QApplication::translate("Dialog_Config", "folder.jpg", 0));
        radioButton_cover_1->setText(QApplication::translate("Dialog_Config", "[Filmdatei]-poster.jpg", 0));
        label_nfo_headline->setText(QApplication::translate("Dialog_Config", "Namensgebung der nfo Datei", 0));
        radioButton_nfo_0->setText(QApplication::translate("Dialog_Config", "movie.nfo", 0));
        radioButton_nfo_1->setText(QApplication::translate("Dialog_Config", "[Filmdatei].nfo", 0));
        label_index_headline->setText(QApplication::translate("Dialog_Config", "Einstellungen HTML Filmindex", 0));
        label_cover_line->setText(QApplication::translate("Dialog_Config", "Cover pro Zeile", 0));
        label_cover_column->setText(QApplication::translate("Dialog_Config", "Cover pro Spalte", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Config: public Ui_Dialog_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CONFIG_H
