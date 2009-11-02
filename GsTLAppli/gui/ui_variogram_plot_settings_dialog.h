/********************************************************************************
** Form generated from reading ui file 'variogram_plot_settings_dialog.ui'
**
** Created: Sun Nov 1 20:46:27 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VARIOGRAM_PLOT_SETTINGS_DIALOG_H
#define UI_VARIOGRAM_PLOT_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlotSettingsDialogBase
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *buttonGroup1;
    QVBoxLayout *vboxLayout1;
    QRadioButton *all_plots_button_;
    QRadioButton *selected_plots_button_;
    QListWidget *plots_list_;
    QSpacerItem *spacer1_2;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1;
    QFrame *line1;
    QGroupBox *buttonGroup2_2;
    QVBoxLayout *vboxLayout2;
    QRadioButton *x_leave_unchanged_;
    QRadioButton *x_autoscale_;
    QRadioButton *x_manual_set_;
    QGroupBox *xgroupbox_;
    QGridLayout *gridLayout;
    QLineEdit *xmin_;
    QLineEdit *xmax_;
    QLabel *textLabel2_3_2;
    QLabel *textLabel2_2_2_2;
    QSpacerItem *spacer1;
    QHBoxLayout *hboxLayout1;
    QLabel *textLabel1_2;
    QFrame *line1_2;
    QGroupBox *buttonGroup2;
    QVBoxLayout *vboxLayout3;
    QRadioButton *y_leave_unchanged_;
    QRadioButton *y_autoscale_;
    QRadioButton *y_manual_set_;
    QGroupBox *ygroupbox_;
    QGridLayout *gridLayout1;
    QLineEdit *ymin_;
    QLineEdit *ymax_;
    QLabel *textLabel2_3;
    QLabel *textLabel2_2_2;
    QSpacerItem *spacer7;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacer9;
    QPushButton *ok_button_;
    QSpacerItem *spacer6;
    QPushButton *cancel_button_;
    QSpacerItem *spacer8;
    QSpacerItem *spacer3;

    void setupUi(QDialog *PlotSettingsDialogBase)
    {
        if (PlotSettingsDialogBase->objectName().isEmpty())
            PlotSettingsDialogBase->setObjectName(QString::fromUtf8("PlotSettingsDialogBase"));
        PlotSettingsDialogBase->resize(234, 612);
        PlotSettingsDialogBase->setBaseSize(QSize(0, 400));
        vboxLayout = new QVBoxLayout(PlotSettingsDialogBase);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        buttonGroup1 = new QGroupBox(PlotSettingsDialogBase);
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

        spacer1_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer1_2);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1 = new QLabel(PlotSettingsDialogBase);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setMaximumSize(QSize(50, 32767));
        textLabel1->setWordWrap(false);

        hboxLayout->addWidget(textLabel1);

        line1 = new QFrame(PlotSettingsDialogBase);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Raised);

        hboxLayout->addWidget(line1);


        vboxLayout->addLayout(hboxLayout);

        buttonGroup2_2 = new QGroupBox(PlotSettingsDialogBase);
        buttonGroup2_2->setObjectName(QString::fromUtf8("buttonGroup2_2"));
        vboxLayout2 = new QVBoxLayout(buttonGroup2_2);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setMargin(0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        x_leave_unchanged_ = new QRadioButton(buttonGroup2_2);
        x_leave_unchanged_->setObjectName(QString::fromUtf8("x_leave_unchanged_"));
        x_leave_unchanged_->setChecked(true);

        vboxLayout2->addWidget(x_leave_unchanged_);

        x_autoscale_ = new QRadioButton(buttonGroup2_2);
        x_autoscale_->setObjectName(QString::fromUtf8("x_autoscale_"));

        vboxLayout2->addWidget(x_autoscale_);

        x_manual_set_ = new QRadioButton(buttonGroup2_2);
        x_manual_set_->setObjectName(QString::fromUtf8("x_manual_set_"));

        vboxLayout2->addWidget(x_manual_set_);

        xgroupbox_ = new QGroupBox(buttonGroup2_2);
        xgroupbox_->setObjectName(QString::fromUtf8("xgroupbox_"));
        xgroupbox_->setEnabled(true);
        xgroupbox_->setAlignment(Qt::AlignHCenter);
        gridLayout = new QGridLayout(xgroupbox_);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        xmin_ = new QLineEdit(xgroupbox_);
        xmin_->setObjectName(QString::fromUtf8("xmin_"));

        gridLayout->addWidget(xmin_, 1, 0, 1, 1);

        xmax_ = new QLineEdit(xgroupbox_);
        xmax_->setObjectName(QString::fromUtf8("xmax_"));

        gridLayout->addWidget(xmax_, 1, 1, 1, 1);

        textLabel2_3_2 = new QLabel(xgroupbox_);
        textLabel2_3_2->setObjectName(QString::fromUtf8("textLabel2_3_2"));
        textLabel2_3_2->setWordWrap(false);

        gridLayout->addWidget(textLabel2_3_2, 0, 0, 1, 1);

        textLabel2_2_2_2 = new QLabel(xgroupbox_);
        textLabel2_2_2_2->setObjectName(QString::fromUtf8("textLabel2_2_2_2"));
        textLabel2_2_2_2->setWordWrap(false);

        gridLayout->addWidget(textLabel2_2_2_2, 0, 1, 1, 1);


        vboxLayout2->addWidget(xgroupbox_);


        vboxLayout->addWidget(buttonGroup2_2);

        spacer1 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        textLabel1_2 = new QLabel(PlotSettingsDialogBase);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setMaximumSize(QSize(50, 32767));
        textLabel1_2->setWordWrap(false);

        hboxLayout1->addWidget(textLabel1_2);

        line1_2 = new QFrame(PlotSettingsDialogBase);
        line1_2->setObjectName(QString::fromUtf8("line1_2"));
        line1_2->setFrameShape(QFrame::HLine);
        line1_2->setFrameShadow(QFrame::Raised);

        hboxLayout1->addWidget(line1_2);


        vboxLayout->addLayout(hboxLayout1);

        buttonGroup2 = new QGroupBox(PlotSettingsDialogBase);
        buttonGroup2->setObjectName(QString::fromUtf8("buttonGroup2"));
        vboxLayout3 = new QVBoxLayout(buttonGroup2);
        vboxLayout3->setSpacing(6);
        vboxLayout3->setMargin(0);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        y_leave_unchanged_ = new QRadioButton(buttonGroup2);
        y_leave_unchanged_->setObjectName(QString::fromUtf8("y_leave_unchanged_"));
        y_leave_unchanged_->setChecked(true);

        vboxLayout3->addWidget(y_leave_unchanged_);

        y_autoscale_ = new QRadioButton(buttonGroup2);
        y_autoscale_->setObjectName(QString::fromUtf8("y_autoscale_"));

        vboxLayout3->addWidget(y_autoscale_);

        y_manual_set_ = new QRadioButton(buttonGroup2);
        y_manual_set_->setObjectName(QString::fromUtf8("y_manual_set_"));

        vboxLayout3->addWidget(y_manual_set_);

        ygroupbox_ = new QGroupBox(buttonGroup2);
        ygroupbox_->setObjectName(QString::fromUtf8("ygroupbox_"));
        ygroupbox_->setEnabled(true);
        ygroupbox_->setAlignment(Qt::AlignHCenter);
        gridLayout1 = new QGridLayout(ygroupbox_);
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(2);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        ymin_ = new QLineEdit(ygroupbox_);
        ymin_->setObjectName(QString::fromUtf8("ymin_"));

        gridLayout1->addWidget(ymin_, 1, 0, 1, 1);

        ymax_ = new QLineEdit(ygroupbox_);
        ymax_->setObjectName(QString::fromUtf8("ymax_"));

        gridLayout1->addWidget(ymax_, 1, 1, 1, 1);

        textLabel2_3 = new QLabel(ygroupbox_);
        textLabel2_3->setObjectName(QString::fromUtf8("textLabel2_3"));
        textLabel2_3->setWordWrap(false);

        gridLayout1->addWidget(textLabel2_3, 0, 0, 1, 1);

        textLabel2_2_2 = new QLabel(ygroupbox_);
        textLabel2_2_2->setObjectName(QString::fromUtf8("textLabel2_2_2"));
        textLabel2_2_2->setWordWrap(false);

        gridLayout1->addWidget(textLabel2_2_2, 0, 1, 1, 1);


        vboxLayout3->addWidget(ygroupbox_);


        vboxLayout->addWidget(buttonGroup2);

        spacer7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer7);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacer9 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer9);

        ok_button_ = new QPushButton(PlotSettingsDialogBase);
        ok_button_->setObjectName(QString::fromUtf8("ok_button_"));

        hboxLayout2->addWidget(ok_button_);

        spacer6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer6);

        cancel_button_ = new QPushButton(PlotSettingsDialogBase);
        cancel_button_->setObjectName(QString::fromUtf8("cancel_button_"));

        hboxLayout2->addWidget(cancel_button_);

        spacer8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer8);


        vboxLayout->addLayout(hboxLayout2);

        spacer3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout->addItem(spacer3);


        retranslateUi(PlotSettingsDialogBase);
        QObject::connect(selected_plots_button_, SIGNAL(toggled(bool)), plots_list_, SLOT(setShown(bool)));
        QObject::connect(x_manual_set_, SIGNAL(toggled(bool)), xgroupbox_, SLOT(setShown(bool)));
        QObject::connect(y_manual_set_, SIGNAL(toggled(bool)), ygroupbox_, SLOT(setShown(bool)));

        QMetaObject::connectSlotsByName(PlotSettingsDialogBase);
    } // setupUi

    void retranslateUi(QDialog *PlotSettingsDialogBase)
    {
        PlotSettingsDialogBase->setWindowTitle(QApplication::translate("PlotSettingsDialogBase", "Variogram Plot Settings", 0, QApplication::UnicodeUTF8));
        buttonGroup1->setTitle(QApplication::translate("PlotSettingsDialogBase", "Apply settings to", 0, QApplication::UnicodeUTF8));
        all_plots_button_->setText(QApplication::translate("PlotSettingsDialogBase", "All plots", 0, QApplication::UnicodeUTF8));
        selected_plots_button_->setText(QApplication::translate("PlotSettingsDialogBase", "Selected plots:", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("PlotSettingsDialogBase", "X axis", 0, QApplication::UnicodeUTF8));
        buttonGroup2_2->setTitle(QString());
        x_leave_unchanged_->setText(QApplication::translate("PlotSettingsDialogBase", "Leave unchanged", 0, QApplication::UnicodeUTF8));
        x_autoscale_->setText(QApplication::translate("PlotSettingsDialogBase", "Auto-scale", 0, QApplication::UnicodeUTF8));
        x_manual_set_->setText(QApplication::translate("PlotSettingsDialogBase", "Set to:", 0, QApplication::UnicodeUTF8));
        xgroupbox_->setTitle(QString());
        textLabel2_3_2->setText(QApplication::translate("PlotSettingsDialogBase", "X min", 0, QApplication::UnicodeUTF8));
        textLabel2_2_2_2->setText(QApplication::translate("PlotSettingsDialogBase", "X max", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("PlotSettingsDialogBase", "Y axis", 0, QApplication::UnicodeUTF8));
        buttonGroup2->setTitle(QString());
        y_leave_unchanged_->setText(QApplication::translate("PlotSettingsDialogBase", "Leave unchanged", 0, QApplication::UnicodeUTF8));
        y_autoscale_->setText(QApplication::translate("PlotSettingsDialogBase", "Auto-scale", 0, QApplication::UnicodeUTF8));
        y_manual_set_->setText(QApplication::translate("PlotSettingsDialogBase", "Set to:", 0, QApplication::UnicodeUTF8));
        ygroupbox_->setTitle(QString());
        textLabel2_3->setText(QApplication::translate("PlotSettingsDialogBase", "Y min", 0, QApplication::UnicodeUTF8));
        textLabel2_2_2->setText(QApplication::translate("PlotSettingsDialogBase", "Y max", 0, QApplication::UnicodeUTF8));
        ok_button_->setText(QApplication::translate("PlotSettingsDialogBase", "Apply Changes", 0, QApplication::UnicodeUTF8));
        cancel_button_->setText(QApplication::translate("PlotSettingsDialogBase", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PlotSettingsDialogBase);
    } // retranslateUi

};

namespace Ui {
    class PlotSettingsDialogBase: public Ui_PlotSettingsDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIOGRAM_PLOT_SETTINGS_DIALOG_H
