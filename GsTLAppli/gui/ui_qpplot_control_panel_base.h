/********************************************************************************
** Form generated from reading ui file 'qpplot_control_panel_base.ui'
**
** Created: Sun Nov 1 20:46:26 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QPPLOT_CONTROL_PANEL_BASE_H
#define UI_QPPLOT_CONTROL_PANEL_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
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

class Ui_QPplot_control_panel_base
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel2_3;
    QComboBox *analysis_combobox_;
    QSpacerItem *spacer15;
    QSpacerItem *spacer13;
    QHBoxLayout *hboxLayout1;
    QLabel *textLabel1_2;
    QFrame *line3_2;
    QGroupBox *property_selector_box_1_;
    QSpacerItem *spacer5;
    QGroupBox *groupBox7;
    QGridLayout *gridLayout;
    QPushButton *reset_clips_button_1_;
    QLineEdit *minval_edit_1_;
    QLineEdit *maxval_edit_1_;
    QLabel *textLabel3_2;
    QLabel *textLabel3;
    QSpacerItem *spacer12;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabel1;
    QFrame *line3;
    QGroupBox *property_selector_box_2_;
    QSpacerItem *spacer5_2;
    QGroupBox *groupBox8;
    QGridLayout *gridLayout1;
    QPushButton *reset_clips_button_2_;
    QLineEdit *minval_edit_2_;
    QLineEdit *maxval_edit_2_;
    QLabel *textLabel3_2_2;
    QLabel *textLabel3_3;
    QSpacerItem *spacer44;

    void setupUi(QWidget *QPplot_control_panel_base)
    {
        if (QPplot_control_panel_base->objectName().isEmpty())
            QPplot_control_panel_base->setObjectName(QString::fromUtf8("QPplot_control_panel_base"));
        QPplot_control_panel_base->resize(211, 610);
        vboxLayout = new QVBoxLayout(QPplot_control_panel_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(4);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel2_3 = new QLabel(QPplot_control_panel_base);
        textLabel2_3->setObjectName(QString::fromUtf8("textLabel2_3"));
        textLabel2_3->setWordWrap(false);

        hboxLayout->addWidget(textLabel2_3);

        analysis_combobox_ = new QComboBox(QPplot_control_panel_base);
        analysis_combobox_->setObjectName(QString::fromUtf8("analysis_combobox_"));

        hboxLayout->addWidget(analysis_combobox_);

        spacer15 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer15);


        vboxLayout->addLayout(hboxLayout);

        spacer13 = new QSpacerItem(21, 31, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer13);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        textLabel1_2 = new QLabel(QPplot_control_panel_base);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setMaximumSize(QSize(122, 32767));
        textLabel1_2->setAlignment(Qt::AlignVCenter);
        textLabel1_2->setWordWrap(false);

        hboxLayout1->addWidget(textLabel1_2);

        line3_2 = new QFrame(QPplot_control_panel_base);
        line3_2->setObjectName(QString::fromUtf8("line3_2"));
        line3_2->setFrameShape(QFrame::HLine);
        line3_2->setFrameShadow(QFrame::Sunken);

        hboxLayout1->addWidget(line3_2);


        vboxLayout->addLayout(hboxLayout1);

        property_selector_box_1_ = new QGroupBox(QPplot_control_panel_base);
        property_selector_box_1_->setObjectName(QString::fromUtf8("property_selector_box_1_"));

        vboxLayout->addWidget(property_selector_box_1_);

        spacer5 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer5);

        groupBox7 = new QGroupBox(QPplot_control_panel_base);
        groupBox7->setObjectName(QString::fromUtf8("groupBox7"));
        groupBox7->setAlignment(Qt::AlignHCenter);
        gridLayout = new QGridLayout(groupBox7);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        reset_clips_button_1_ = new QPushButton(groupBox7);
        reset_clips_button_1_->setObjectName(QString::fromUtf8("reset_clips_button_1_"));

        gridLayout->addWidget(reset_clips_button_1_, 2, 0, 1, 2);

        minval_edit_1_ = new QLineEdit(groupBox7);
        minval_edit_1_->setObjectName(QString::fromUtf8("minval_edit_1_"));

        gridLayout->addWidget(minval_edit_1_, 1, 0, 1, 1);

        maxval_edit_1_ = new QLineEdit(groupBox7);
        maxval_edit_1_->setObjectName(QString::fromUtf8("maxval_edit_1_"));

        gridLayout->addWidget(maxval_edit_1_, 1, 1, 1, 1);

        textLabel3_2 = new QLabel(groupBox7);
        textLabel3_2->setObjectName(QString::fromUtf8("textLabel3_2"));
        textLabel3_2->setAlignment(Qt::AlignCenter);
        textLabel3_2->setWordWrap(false);

        gridLayout->addWidget(textLabel3_2, 0, 1, 1, 1);

        textLabel3 = new QLabel(groupBox7);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        textLabel3->setAlignment(Qt::AlignCenter);
        textLabel3->setWordWrap(false);

        gridLayout->addWidget(textLabel3, 0, 0, 1, 1);


        vboxLayout->addWidget(groupBox7);

        spacer12 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Minimum);

        vboxLayout->addItem(spacer12);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabel1 = new QLabel(QPplot_control_panel_base);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setMaximumSize(QSize(122, 32767));
        textLabel1->setTextFormat(Qt::AutoText);
        textLabel1->setAlignment(Qt::AlignVCenter);
        textLabel1->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1);

        line3 = new QFrame(QPplot_control_panel_base);
        line3->setObjectName(QString::fromUtf8("line3"));
        line3->setFrameShape(QFrame::HLine);
        line3->setFrameShadow(QFrame::Sunken);

        hboxLayout2->addWidget(line3);


        vboxLayout->addLayout(hboxLayout2);

        property_selector_box_2_ = new QGroupBox(QPplot_control_panel_base);
        property_selector_box_2_->setObjectName(QString::fromUtf8("property_selector_box_2_"));

        vboxLayout->addWidget(property_selector_box_2_);

        spacer5_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer5_2);

        groupBox8 = new QGroupBox(QPplot_control_panel_base);
        groupBox8->setObjectName(QString::fromUtf8("groupBox8"));
        groupBox8->setAlignment(Qt::AlignHCenter);
        gridLayout1 = new QGridLayout(groupBox8);
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        reset_clips_button_2_ = new QPushButton(groupBox8);
        reset_clips_button_2_->setObjectName(QString::fromUtf8("reset_clips_button_2_"));

        gridLayout1->addWidget(reset_clips_button_2_, 2, 0, 1, 2);

        minval_edit_2_ = new QLineEdit(groupBox8);
        minval_edit_2_->setObjectName(QString::fromUtf8("minval_edit_2_"));

        gridLayout1->addWidget(minval_edit_2_, 1, 0, 1, 1);

        maxval_edit_2_ = new QLineEdit(groupBox8);
        maxval_edit_2_->setObjectName(QString::fromUtf8("maxval_edit_2_"));

        gridLayout1->addWidget(maxval_edit_2_, 1, 1, 1, 1);

        textLabel3_2_2 = new QLabel(groupBox8);
        textLabel3_2_2->setObjectName(QString::fromUtf8("textLabel3_2_2"));
        textLabel3_2_2->setAlignment(Qt::AlignCenter);
        textLabel3_2_2->setWordWrap(false);

        gridLayout1->addWidget(textLabel3_2_2, 0, 1, 1, 1);

        textLabel3_3 = new QLabel(groupBox8);
        textLabel3_3->setObjectName(QString::fromUtf8("textLabel3_3"));
        textLabel3_3->setAlignment(Qt::AlignCenter);
        textLabel3_3->setWordWrap(false);

        gridLayout1->addWidget(textLabel3_3, 0, 0, 1, 1);


        vboxLayout->addWidget(groupBox8);

        spacer44 = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer44);


        retranslateUi(QPplot_control_panel_base);

        QMetaObject::connectSlotsByName(QPplot_control_panel_base);
    } // setupUi

    void retranslateUi(QWidget *QPplot_control_panel_base)
    {
        QPplot_control_panel_base->setWindowTitle(QApplication::translate("QPplot_control_panel_base", "QPplot", 0, QApplication::UnicodeUTF8));
        textLabel2_3->setText(QApplication::translate("QPplot_control_panel_base", "Plot Type:", 0, QApplication::UnicodeUTF8));
        analysis_combobox_->clear();
        analysis_combobox_->insertItems(0, QStringList()
         << QApplication::translate("QPplot_control_panel_base", "QQ-plot", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QPplot_control_panel_base", "PP-plot", 0, QApplication::UnicodeUTF8)
        );
        textLabel1_2->setText(QApplication::translate("QPplot_control_panel_base", "<b>Variable 1</b> (X axis)", 0, QApplication::UnicodeUTF8));
        property_selector_box_1_->setTitle(QString());
        groupBox7->setTitle(QApplication::translate("QPplot_control_panel_base", "Clipping Values", 0, QApplication::UnicodeUTF8));
        reset_clips_button_1_->setText(QApplication::translate("QPplot_control_panel_base", "Reset", 0, QApplication::UnicodeUTF8));
        textLabel3_2->setText(QApplication::translate("QPplot_control_panel_base", "Max", 0, QApplication::UnicodeUTF8));
        textLabel3->setText(QApplication::translate("QPplot_control_panel_base", "Min", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("QPplot_control_panel_base", "<b>Variable 2</b> (Y axis)", 0, QApplication::UnicodeUTF8));
        property_selector_box_2_->setTitle(QString());
        groupBox8->setTitle(QApplication::translate("QPplot_control_panel_base", "Clipping Values", 0, QApplication::UnicodeUTF8));
        reset_clips_button_2_->setText(QApplication::translate("QPplot_control_panel_base", "Reset", 0, QApplication::UnicodeUTF8));
        textLabel3_2_2->setText(QApplication::translate("QPplot_control_panel_base", "Max", 0, QApplication::UnicodeUTF8));
        textLabel3_3->setText(QApplication::translate("QPplot_control_panel_base", "Min", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(QPplot_control_panel_base);
    } // retranslateUi

};

namespace Ui {
    class QPplot_control_panel_base: public Ui_QPplot_control_panel_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPPLOT_CONTROL_PANEL_BASE_H
