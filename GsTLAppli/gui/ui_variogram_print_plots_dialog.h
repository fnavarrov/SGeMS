/********************************************************************************
** Form generated from reading ui file 'variogram_print_plots_dialog.ui'
**
** Created: Sun Nov 1 20:46:27 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VARIOGRAM_PRINT_PLOTS_DIALOG_H
#define UI_VARIOGRAM_PRINT_PLOTS_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PrintPlotsDialogBase
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *buttonGroup1;
    QVBoxLayout *vboxLayout1;
    QRadioButton *all_plots_button_;
    QRadioButton *selected_plots_button_;
    QListWidget *plots_list_;
    QSpacerItem *spacer8_2;
    QLabel *textLabel4;
    QGridLayout *gridLayout;
    QCheckBox *show_grid_;
    QComboBox *format_;
    QLabel *textLabel1;
    QLabel *textLabel3;
    QGroupBox *filechooser_groupbox_;
    QSpacerItem *spacer7;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer9;
    QPushButton *ok_button_;
    QSpacerItem *spacer6;
    QPushButton *cancel_button_;
    QSpacerItem *spacer8;
    QSpacerItem *spacer3;

    void setupUi(QDialog *PrintPlotsDialogBase)
    {
        if (PrintPlotsDialogBase->objectName().isEmpty())
            PrintPlotsDialogBase->setObjectName(QString::fromUtf8("PrintPlotsDialogBase"));
        PrintPlotsDialogBase->resize(277, 462);
        PrintPlotsDialogBase->setBaseSize(QSize(0, 400));
        vboxLayout = new QVBoxLayout(PrintPlotsDialogBase);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        buttonGroup1 = new QGroupBox(PrintPlotsDialogBase);
        buttonGroup1->setObjectName(QString::fromUtf8("buttonGroup1"));
        buttonGroup1->setAlignment(Qt::AlignHCenter);
        vboxLayout1 = new QVBoxLayout(buttonGroup1);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        all_plots_button_ = new QRadioButton(buttonGroup1);
        all_plots_button_->setObjectName(QString::fromUtf8("all_plots_button_"));
        all_plots_button_->setChecked(true);

        vboxLayout1->addWidget(all_plots_button_);

        selected_plots_button_ = new QRadioButton(buttonGroup1);
        selected_plots_button_->setObjectName(QString::fromUtf8("selected_plots_button_"));

        vboxLayout1->addWidget(selected_plots_button_);

        plots_list_ = new QListWidget(buttonGroup1);
        plots_list_->setObjectName(QString::fromUtf8("plots_list_"));
        plots_list_->setEnabled(true);

        vboxLayout1->addWidget(plots_list_);


        vboxLayout->addWidget(buttonGroup1);

        spacer8_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer8_2);

        textLabel4 = new QLabel(PrintPlotsDialogBase);
        textLabel4->setObjectName(QString::fromUtf8("textLabel4"));
        textLabel4->setAlignment(Qt::AlignVCenter);
        textLabel4->setWordWrap(true);

        vboxLayout->addWidget(textLabel4);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        show_grid_ = new QCheckBox(PrintPlotsDialogBase);
        show_grid_->setObjectName(QString::fromUtf8("show_grid_"));

        gridLayout->addWidget(show_grid_, 2, 0, 1, 2);

        format_ = new QComboBox(PrintPlotsDialogBase);
        format_->setObjectName(QString::fromUtf8("format_"));

        gridLayout->addWidget(format_, 1, 1, 1, 1);

        textLabel1 = new QLabel(PrintPlotsDialogBase);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setWordWrap(false);

        gridLayout->addWidget(textLabel1, 1, 0, 1, 1);

        textLabel3 = new QLabel(PrintPlotsDialogBase);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        sizePolicy.setHeightForWidth(textLabel3->sizePolicy().hasHeightForWidth());
        textLabel3->setSizePolicy(sizePolicy);
        textLabel3->setMaximumSize(QSize(50, 32767));
        textLabel3->setWordWrap(false);

        gridLayout->addWidget(textLabel3, 0, 0, 1, 1);

        filechooser_groupbox_ = new QGroupBox(PrintPlotsDialogBase);
        filechooser_groupbox_->setObjectName(QString::fromUtf8("filechooser_groupbox_"));

        gridLayout->addWidget(filechooser_groupbox_, 0, 1, 1, 1);


        vboxLayout->addLayout(gridLayout);

        spacer7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer7);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer9 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer9);

        ok_button_ = new QPushButton(PrintPlotsDialogBase);
        ok_button_->setObjectName(QString::fromUtf8("ok_button_"));

        hboxLayout->addWidget(ok_button_);

        spacer6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer6);

        cancel_button_ = new QPushButton(PrintPlotsDialogBase);
        cancel_button_->setObjectName(QString::fromUtf8("cancel_button_"));

        hboxLayout->addWidget(cancel_button_);

        spacer8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer8);


        vboxLayout->addLayout(hboxLayout);

        spacer3 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout->addItem(spacer3);


        retranslateUi(PrintPlotsDialogBase);
        QObject::connect(selected_plots_button_, SIGNAL(toggled(bool)), plots_list_, SLOT(setShown(bool)));

        QMetaObject::connectSlotsByName(PrintPlotsDialogBase);
    } // setupUi

    void retranslateUi(QDialog *PrintPlotsDialogBase)
    {
        PrintPlotsDialogBase->setWindowTitle(QApplication::translate("PrintPlotsDialogBase", "Variogram Plot Settings", 0, QApplication::UnicodeUTF8));
        buttonGroup1->setTitle(QApplication::translate("PrintPlotsDialogBase", "Apply settings to", 0, QApplication::UnicodeUTF8));
        all_plots_button_->setText(QApplication::translate("PrintPlotsDialogBase", "All plots", 0, QApplication::UnicodeUTF8));
        selected_plots_button_->setText(QApplication::translate("PrintPlotsDialogBase", "Selected plots:", 0, QApplication::UnicodeUTF8));
        textLabel4->setText(QApplication::translate("PrintPlotsDialogBase", "<i><b>Note</b>: if \"Save as\" is \"/home/toto/myprefix_\", the plots will be saved as:<br>\n"
"\n"
"  - /home/toto/myprefix_plot_1_azth=0_dip=0.png<br>\n"
"\n"
"  - /home/toto/myprefix_plot_2_azth=45_dip=14.png<br>\n"
"\n"
"  - /home/toto/myprefix_all_directions.png<br>\n"
"\n"
"If files with such names exit, they will be overwritten...", 0, QApplication::UnicodeUTF8));
        show_grid_->setText(QApplication::translate("PrintPlotsDialogBase", "Show Grid", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("PrintPlotsDialogBase", "Format", 0, QApplication::UnicodeUTF8));
        textLabel3->setText(QApplication::translate("PrintPlotsDialogBase", "Save as", 0, QApplication::UnicodeUTF8));
        filechooser_groupbox_->setTitle(QString());
        ok_button_->setText(QApplication::translate("PrintPlotsDialogBase", "Save", 0, QApplication::UnicodeUTF8));
        cancel_button_->setText(QApplication::translate("PrintPlotsDialogBase", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PrintPlotsDialogBase);
    } // retranslateUi

};

namespace Ui {
    class PrintPlotsDialogBase: public Ui_PrintPlotsDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIOGRAM_PRINT_PLOTS_DIALOG_H
