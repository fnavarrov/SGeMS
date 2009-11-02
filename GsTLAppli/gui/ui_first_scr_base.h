/********************************************************************************
** Form generated from reading ui file 'first_scr_base.ui'
**
** Created: Sun Nov 1 20:46:22 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FIRST_SCR_BASE_H
#define UI_FIRST_SCR_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_First_scr_base
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QGroupBox *buttonGroup1;
    QVBoxLayout *vboxLayout;
    QRadioButton *compute_variograms_button_;
    QRadioButton *load_variograms_button_;
    QSpacerItem *spacerItem1;
    QSpacerItem *spacerItem2;
    QSpacerItem *spacerItem3;
    QFrame *line4;
    QSpacerItem *spacerItem4;
    QSpacerItem *spacerItem5;
    QSpacerItem *spacerItem6;
    QGroupBox *compute_variog_box_;
    QVBoxLayout *vboxLayout1;
    QGroupBox *grid_name_;
    QSpacerItem *spacerItem7;
    QGroupBox *head_groupbox_;
    QGroupBox *tail_groupbox_;
    QSpacerItem *spacerItem8;
    QSpacerItem *spacerItem9;
    QGroupBox *variog_file_box_;
    QSpacerItem *spacerItem10;

    void setupUi(QWidget *First_scr_base)
    {
        if (First_scr_base->objectName().isEmpty())
            First_scr_base->setObjectName(QString::fromUtf8("First_scr_base"));
        First_scr_base->resize(433, 436);
        gridLayout = new QGridLayout(First_scr_base);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacerItem = new QSpacerItem(150, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 6, 1, 1);

        buttonGroup1 = new QGroupBox(First_scr_base);
        buttonGroup1->setObjectName(QString::fromUtf8("buttonGroup1"));
        vboxLayout = new QVBoxLayout(buttonGroup1);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        compute_variograms_button_ = new QRadioButton(buttonGroup1);
        compute_variograms_button_->setObjectName(QString::fromUtf8("compute_variograms_button_"));
        compute_variograms_button_->setChecked(true);

        vboxLayout->addWidget(compute_variograms_button_);

        load_variograms_button_ = new QRadioButton(buttonGroup1);
        load_variograms_button_->setObjectName(QString::fromUtf8("load_variograms_button_"));

        vboxLayout->addWidget(load_variograms_button_);


        gridLayout->addWidget(buttonGroup1, 1, 1, 1, 5);

        spacerItem1 = new QSpacerItem(130, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 1, 0, 1, 1);

        spacerItem2 = new QSpacerItem(21, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem2, 7, 3, 1, 1);

        spacerItem3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(spacerItem3, 4, 3, 1, 1);

        line4 = new QFrame(First_scr_base);
        line4->setObjectName(QString::fromUtf8("line4"));
        line4->setFrameShape(QFrame::HLine);
        line4->setFrameShadow(QFrame::Raised);
        line4->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line4, 3, 0, 1, 7);

        spacerItem4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(spacerItem4, 2, 3, 1, 1);

        spacerItem5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(spacerItem5, 0, 3, 1, 1);

        spacerItem6 = new QSpacerItem(81, 21, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem6, 5, 0, 1, 2);

        compute_variog_box_ = new QGroupBox(First_scr_base);
        compute_variog_box_->setObjectName(QString::fromUtf8("compute_variog_box_"));
        vboxLayout1 = new QVBoxLayout(compute_variog_box_);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        grid_name_ = new QGroupBox(compute_variog_box_);
        grid_name_->setObjectName(QString::fromUtf8("grid_name_"));

        vboxLayout1->addWidget(grid_name_);

        spacerItem7 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout1->addItem(spacerItem7);

        head_groupbox_ = new QGroupBox(compute_variog_box_);
        head_groupbox_->setObjectName(QString::fromUtf8("head_groupbox_"));

        vboxLayout1->addWidget(head_groupbox_);

        tail_groupbox_ = new QGroupBox(compute_variog_box_);
        tail_groupbox_->setObjectName(QString::fromUtf8("tail_groupbox_"));

        vboxLayout1->addWidget(tail_groupbox_);


        gridLayout->addWidget(compute_variog_box_, 5, 2, 1, 3);

        spacerItem8 = new QSpacerItem(101, 21, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem8, 5, 5, 1, 2);

        spacerItem9 = new QSpacerItem(91, 21, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem9, 6, 4, 1, 3);

        variog_file_box_ = new QGroupBox(First_scr_base);
        variog_file_box_->setObjectName(QString::fromUtf8("variog_file_box_"));

        gridLayout->addWidget(variog_file_box_, 6, 3, 1, 1);

        spacerItem10 = new QSpacerItem(71, 21, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem10, 6, 0, 1, 3);


        retranslateUi(First_scr_base);

        QMetaObject::connectSlotsByName(First_scr_base);
    } // setupUi

    void retranslateUi(QWidget *First_scr_base)
    {
        First_scr_base->setWindowTitle(QApplication::translate("First_scr_base", "Form1", 0, QApplication::UnicodeUTF8));
        compute_variograms_button_->setText(QApplication::translate("First_scr_base", "Compute variograms from scratch", 0, QApplication::UnicodeUTF8));
        load_variograms_button_->setText(QApplication::translate("First_scr_base", "Load exisiting experimental variograms", 0, QApplication::UnicodeUTF8));
        compute_variog_box_->setTitle(QApplication::translate("First_scr_base", "Choose grid and properties", 0, QApplication::UnicodeUTF8));
        grid_name_->setTitle(QApplication::translate("First_scr_base", "Grid Name", 0, QApplication::UnicodeUTF8));
        head_groupbox_->setTitle(QApplication::translate("First_scr_base", "Head Property", 0, QApplication::UnicodeUTF8));
        tail_groupbox_->setTitle(QApplication::translate("First_scr_base", "Tail Property", 0, QApplication::UnicodeUTF8));
        variog_file_box_->setTitle(QApplication::translate("First_scr_base", "Select Variogram File", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(First_scr_base);
    } // retranslateUi

};

namespace Ui {
    class First_scr_base: public Ui_First_scr_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_SCR_BASE_H
