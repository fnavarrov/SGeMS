/********************************************************************************
** Form generated from reading ui file 'scatterplot_control_panel_base.ui'
**
** Created: Sun Nov 1 20:46:24 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SCATTERPLOT_CONTROL_PANEL_BASE_H
#define UI_SCATTERPLOT_CONTROL_PANEL_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scatterplot_control_panel_base
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *grid_selector_box_;
    QSpacerItem *spacer12_2;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1_2;
    QFrame *line3_2;
    QGroupBox *property_selector_box_1_;
    QSpacerItem *spacer5;
    QGroupBox *groupBox12;
    QGridLayout *gridLayout;
    QPushButton *reset_clips_button_1_;
    QLineEdit *minval_edit_1_;
    QLineEdit *maxval_edit_1_;
    QLabel *textLabel3_2;
    QLabel *textLabel3;
    QSpacerItem *spacer12;
    QHBoxLayout *hboxLayout1;
    QLabel *textLabel1;
    QFrame *line3;
    QGroupBox *property_selector_box_2_;
    QSpacerItem *spacer5_2;
    QGroupBox *groupBox13;
    QGridLayout *gridLayout1;
    QPushButton *reset_clips_button_2_;
    QLineEdit *minval_edit_2_;
    QLineEdit *maxval_edit_2_;
    QLabel *textLabel3_2_2;
    QLabel *textLabel3_3;
    QSpacerItem *spacer7;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabel1_3;
    QFrame *line3_3;
    QSpacerItem *spacer9;
    QGroupBox *lsfit_groupbox_;
    QVBoxLayout *vboxLayout1;
    QCheckBox *lsfit_checkbox_;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacer10;
    QGridLayout *gridLayout2;
    QLabel *textLabel1_4;
    QLabel *textLabel1_4_2;
    QLabel *intercept_label_;
    QLabel *slope_label_;
    QSpacerItem *spacer8;
    QSpacerItem *spacer44;

    void setupUi(QWidget *Scatterplot_control_panel_base)
    {
        if (Scatterplot_control_panel_base->objectName().isEmpty())
            Scatterplot_control_panel_base->setObjectName(QString::fromUtf8("Scatterplot_control_panel_base"));
        Scatterplot_control_panel_base->resize(244, 838);
        Scatterplot_control_panel_base->setCursor(QCursor(static_cast<Qt::CursorShape>(0)));
        vboxLayout = new QVBoxLayout(Scatterplot_control_panel_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(4);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        grid_selector_box_ = new QGroupBox(Scatterplot_control_panel_base);
        grid_selector_box_->setObjectName(QString::fromUtf8("grid_selector_box_"));
        grid_selector_box_->setAlignment(Qt::AlignHCenter);

        vboxLayout->addWidget(grid_selector_box_);

        spacer12_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer12_2);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1_2 = new QLabel(Scatterplot_control_panel_base);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1_2->sizePolicy().hasHeightForWidth());
        textLabel1_2->setSizePolicy(sizePolicy);
        textLabel1_2->setMaximumSize(QSize(122, 32767));
        textLabel1_2->setAlignment(Qt::AlignVCenter);
        textLabel1_2->setWordWrap(false);

        hboxLayout->addWidget(textLabel1_2);

        line3_2 = new QFrame(Scatterplot_control_panel_base);
        line3_2->setObjectName(QString::fromUtf8("line3_2"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line3_2->sizePolicy().hasHeightForWidth());
        line3_2->setSizePolicy(sizePolicy1);
        line3_2->setFrameShape(QFrame::HLine);
        line3_2->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(line3_2);


        vboxLayout->addLayout(hboxLayout);

        property_selector_box_1_ = new QGroupBox(Scatterplot_control_panel_base);
        property_selector_box_1_->setObjectName(QString::fromUtf8("property_selector_box_1_"));

        vboxLayout->addWidget(property_selector_box_1_);

        spacer5 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer5);

        groupBox12 = new QGroupBox(Scatterplot_control_panel_base);
        groupBox12->setObjectName(QString::fromUtf8("groupBox12"));
        groupBox12->setAlignment(Qt::AlignHCenter);
        gridLayout = new QGridLayout(groupBox12);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        reset_clips_button_1_ = new QPushButton(groupBox12);
        reset_clips_button_1_->setObjectName(QString::fromUtf8("reset_clips_button_1_"));

        gridLayout->addWidget(reset_clips_button_1_, 2, 0, 1, 2);

        minval_edit_1_ = new QLineEdit(groupBox12);
        minval_edit_1_->setObjectName(QString::fromUtf8("minval_edit_1_"));

        gridLayout->addWidget(minval_edit_1_, 1, 0, 1, 1);

        maxval_edit_1_ = new QLineEdit(groupBox12);
        maxval_edit_1_->setObjectName(QString::fromUtf8("maxval_edit_1_"));

        gridLayout->addWidget(maxval_edit_1_, 1, 1, 1, 1);

        textLabel3_2 = new QLabel(groupBox12);
        textLabel3_2->setObjectName(QString::fromUtf8("textLabel3_2"));
        textLabel3_2->setAlignment(Qt::AlignCenter);
        textLabel3_2->setWordWrap(false);

        gridLayout->addWidget(textLabel3_2, 0, 1, 1, 1);

        textLabel3 = new QLabel(groupBox12);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        textLabel3->setAlignment(Qt::AlignCenter);
        textLabel3->setWordWrap(false);

        gridLayout->addWidget(textLabel3, 0, 0, 1, 1);


        vboxLayout->addWidget(groupBox12);

        spacer12 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Minimum);

        vboxLayout->addItem(spacer12);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        textLabel1 = new QLabel(Scatterplot_control_panel_base);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setMaximumSize(QSize(122, 32767));
        textLabel1->setTextFormat(Qt::AutoText);
        textLabel1->setAlignment(Qt::AlignVCenter);
        textLabel1->setWordWrap(false);

        hboxLayout1->addWidget(textLabel1);

        line3 = new QFrame(Scatterplot_control_panel_base);
        line3->setObjectName(QString::fromUtf8("line3"));
        sizePolicy1.setHeightForWidth(line3->sizePolicy().hasHeightForWidth());
        line3->setSizePolicy(sizePolicy1);
        line3->setFrameShape(QFrame::HLine);
        line3->setFrameShadow(QFrame::Sunken);

        hboxLayout1->addWidget(line3);


        vboxLayout->addLayout(hboxLayout1);

        property_selector_box_2_ = new QGroupBox(Scatterplot_control_panel_base);
        property_selector_box_2_->setObjectName(QString::fromUtf8("property_selector_box_2_"));

        vboxLayout->addWidget(property_selector_box_2_);

        spacer5_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer5_2);

        groupBox13 = new QGroupBox(Scatterplot_control_panel_base);
        groupBox13->setObjectName(QString::fromUtf8("groupBox13"));
        groupBox13->setAlignment(Qt::AlignHCenter);
        gridLayout1 = new QGridLayout(groupBox13);
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        reset_clips_button_2_ = new QPushButton(groupBox13);
        reset_clips_button_2_->setObjectName(QString::fromUtf8("reset_clips_button_2_"));

        gridLayout1->addWidget(reset_clips_button_2_, 2, 0, 1, 2);

        minval_edit_2_ = new QLineEdit(groupBox13);
        minval_edit_2_->setObjectName(QString::fromUtf8("minval_edit_2_"));

        gridLayout1->addWidget(minval_edit_2_, 1, 0, 1, 1);

        maxval_edit_2_ = new QLineEdit(groupBox13);
        maxval_edit_2_->setObjectName(QString::fromUtf8("maxval_edit_2_"));

        gridLayout1->addWidget(maxval_edit_2_, 1, 1, 1, 1);

        textLabel3_2_2 = new QLabel(groupBox13);
        textLabel3_2_2->setObjectName(QString::fromUtf8("textLabel3_2_2"));
        textLabel3_2_2->setAlignment(Qt::AlignCenter);
        textLabel3_2_2->setWordWrap(false);

        gridLayout1->addWidget(textLabel3_2_2, 0, 1, 1, 1);

        textLabel3_3 = new QLabel(groupBox13);
        textLabel3_3->setObjectName(QString::fromUtf8("textLabel3_3"));
        textLabel3_3->setAlignment(Qt::AlignCenter);
        textLabel3_3->setWordWrap(false);

        gridLayout1->addWidget(textLabel3_3, 0, 0, 1, 1);


        vboxLayout->addWidget(groupBox13);

        spacer7 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Minimum);

        vboxLayout->addItem(spacer7);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabel1_3 = new QLabel(Scatterplot_control_panel_base);
        textLabel1_3->setObjectName(QString::fromUtf8("textLabel1_3"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textLabel1_3->sizePolicy().hasHeightForWidth());
        textLabel1_3->setSizePolicy(sizePolicy2);
        textLabel1_3->setMaximumSize(QSize(122, 32767));
        textLabel1_3->setTextFormat(Qt::AutoText);
        textLabel1_3->setAlignment(Qt::AlignVCenter);
        textLabel1_3->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1_3);

        line3_3 = new QFrame(Scatterplot_control_panel_base);
        line3_3->setObjectName(QString::fromUtf8("line3_3"));
        sizePolicy1.setHeightForWidth(line3_3->sizePolicy().hasHeightForWidth());
        line3_3->setSizePolicy(sizePolicy1);
        line3_3->setFrameShape(QFrame::HLine);
        line3_3->setFrameShadow(QFrame::Sunken);

        hboxLayout2->addWidget(line3_3);


        vboxLayout->addLayout(hboxLayout2);

        spacer9 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer9);

        lsfit_groupbox_ = new QGroupBox(Scatterplot_control_panel_base);
        lsfit_groupbox_->setObjectName(QString::fromUtf8("lsfit_groupbox_"));
        vboxLayout1 = new QVBoxLayout(lsfit_groupbox_);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        lsfit_checkbox_ = new QCheckBox(lsfit_groupbox_);
        lsfit_checkbox_->setObjectName(QString::fromUtf8("lsfit_checkbox_"));

        vboxLayout1->addWidget(lsfit_checkbox_);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setMargin(0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        spacer10 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer10);

        gridLayout2 = new QGridLayout();
        gridLayout2->setSpacing(9);
        gridLayout2->setMargin(6);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        textLabel1_4 = new QLabel(lsfit_groupbox_);
        textLabel1_4->setObjectName(QString::fromUtf8("textLabel1_4"));
        textLabel1_4->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
        textLabel1_4->setWordWrap(false);

        gridLayout2->addWidget(textLabel1_4, 0, 0, 1, 1);

        textLabel1_4_2 = new QLabel(lsfit_groupbox_);
        textLabel1_4_2->setObjectName(QString::fromUtf8("textLabel1_4_2"));
        textLabel1_4_2->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
        textLabel1_4_2->setWordWrap(false);

        gridLayout2->addWidget(textLabel1_4_2, 1, 0, 1, 1);

        intercept_label_ = new QLabel(lsfit_groupbox_);
        intercept_label_->setObjectName(QString::fromUtf8("intercept_label_"));
        intercept_label_->setWordWrap(false);

        gridLayout2->addWidget(intercept_label_, 1, 1, 1, 1);

        slope_label_ = new QLabel(lsfit_groupbox_);
        slope_label_->setObjectName(QString::fromUtf8("slope_label_"));
        slope_label_->setWordWrap(false);

        gridLayout2->addWidget(slope_label_, 0, 1, 1, 1);


        hboxLayout3->addLayout(gridLayout2);

        spacer8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer8);


        vboxLayout1->addLayout(hboxLayout3);


        vboxLayout->addWidget(lsfit_groupbox_);

        spacer44 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer44);


        retranslateUi(Scatterplot_control_panel_base);

        QMetaObject::connectSlotsByName(Scatterplot_control_panel_base);
    } // setupUi

    void retranslateUi(QWidget *Scatterplot_control_panel_base)
    {
        Scatterplot_control_panel_base->setWindowTitle(QApplication::translate("Scatterplot_control_panel_base", "Scatter_plot", 0, QApplication::UnicodeUTF8));
        grid_selector_box_->setTitle(QApplication::translate("Scatterplot_control_panel_base", "Work on Object:", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("Scatterplot_control_panel_base", "<b>Variable 1</b> (X axis)", 0, QApplication::UnicodeUTF8));
        property_selector_box_1_->setTitle(QString());
        groupBox12->setTitle(QApplication::translate("Scatterplot_control_panel_base", "Clipping Values", 0, QApplication::UnicodeUTF8));
        reset_clips_button_1_->setText(QApplication::translate("Scatterplot_control_panel_base", "Reset", 0, QApplication::UnicodeUTF8));
        textLabel3_2->setText(QApplication::translate("Scatterplot_control_panel_base", "Max", 0, QApplication::UnicodeUTF8));
        textLabel3->setText(QApplication::translate("Scatterplot_control_panel_base", "Min", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("Scatterplot_control_panel_base", "<b>Variable 2</b> (Y axis)", 0, QApplication::UnicodeUTF8));
        property_selector_box_2_->setTitle(QString());
        groupBox13->setTitle(QApplication::translate("Scatterplot_control_panel_base", "Clipping Values", 0, QApplication::UnicodeUTF8));
        reset_clips_button_2_->setText(QApplication::translate("Scatterplot_control_panel_base", "Reset", 0, QApplication::UnicodeUTF8));
        textLabel3_2_2->setText(QApplication::translate("Scatterplot_control_panel_base", "Max", 0, QApplication::UnicodeUTF8));
        textLabel3_3->setText(QApplication::translate("Scatterplot_control_panel_base", "Min", 0, QApplication::UnicodeUTF8));
        textLabel1_3->setText(QApplication::translate("Scatterplot_control_panel_base", "<b>Options</b>", 0, QApplication::UnicodeUTF8));
        lsfit_groupbox_->setTitle(QString());
        lsfit_checkbox_->setText(QApplication::translate("Scatterplot_control_panel_base", "Show Linear Regression Line", 0, QApplication::UnicodeUTF8));
        textLabel1_4->setText(QApplication::translate("Scatterplot_control_panel_base", "Slope:", 0, QApplication::UnicodeUTF8));
        textLabel1_4_2->setText(QApplication::translate("Scatterplot_control_panel_base", "Intercept:", 0, QApplication::UnicodeUTF8));
        intercept_label_->setText(QString());
        slope_label_->setText(QString());
        Q_UNUSED(Scatterplot_control_panel_base);
    } // retranslateUi

};

namespace Ui {
    class Scatterplot_control_panel_base: public Ui_Scatterplot_control_panel_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCATTERPLOT_CONTROL_PANEL_BASE_H
