/********************************************************************************
** Form generated from reading ui file 'histogram_control_panel_base.ui'
**
** Created: Sun Nov 1 20:46:28 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HISTOGRAM_CONTROL_PANEL_BASE_H
#define UI_HISTOGRAM_CONTROL_PANEL_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Histogram_control_panel_base
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *property_selector_box_;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1;
    QSpinBox *bins_spinbox_;
    QSpacerItem *spacer3;
    QSpacerItem *spacer5;
    QGroupBox *groupBox12;
    QGridLayout *gridLayout;
    QPushButton *reset_clips_button_;
    QLineEdit *minval_edit_;
    QLineEdit *maxval_edit_;
    QLabel *textLabel3_2;
    QLabel *textLabel3;
    QGroupBox *_curves_box;
    QSpacerItem *spacer4;

    void setupUi(QWidget *Histogram_control_panel_base)
    {
        if (Histogram_control_panel_base->objectName().isEmpty())
            Histogram_control_panel_base->setObjectName(QString::fromUtf8("Histogram_control_panel_base"));
        Histogram_control_panel_base->resize(198, 644);
        vboxLayout = new QVBoxLayout(Histogram_control_panel_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        property_selector_box_ = new QGroupBox(Histogram_control_panel_base);
        property_selector_box_->setObjectName(QString::fromUtf8("property_selector_box_"));
        property_selector_box_->setFlat(false);

        vboxLayout->addWidget(property_selector_box_);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1 = new QLabel(Histogram_control_panel_base);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout->addWidget(textLabel1);

        bins_spinbox_ = new QSpinBox(Histogram_control_panel_base);
        bins_spinbox_->setObjectName(QString::fromUtf8("bins_spinbox_"));
        bins_spinbox_->setMaximum(2000);
        bins_spinbox_->setMinimum(1);
        bins_spinbox_->setValue(20);

        hboxLayout->addWidget(bins_spinbox_);

        spacer3 = new QSpacerItem(180, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer3);


        vboxLayout->addLayout(hboxLayout);

        spacer5 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer5);

        groupBox12 = new QGroupBox(Histogram_control_panel_base);
        groupBox12->setObjectName(QString::fromUtf8("groupBox12"));
        groupBox12->setAlignment(Qt::AlignHCenter);
        gridLayout = new QGridLayout(groupBox12);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        reset_clips_button_ = new QPushButton(groupBox12);
        reset_clips_button_->setObjectName(QString::fromUtf8("reset_clips_button_"));

        gridLayout->addWidget(reset_clips_button_, 2, 0, 1, 2);

        minval_edit_ = new QLineEdit(groupBox12);
        minval_edit_->setObjectName(QString::fromUtf8("minval_edit_"));

        gridLayout->addWidget(minval_edit_, 1, 0, 1, 1);

        maxval_edit_ = new QLineEdit(groupBox12);
        maxval_edit_->setObjectName(QString::fromUtf8("maxval_edit_"));

        gridLayout->addWidget(maxval_edit_, 1, 1, 1, 1);

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

        _curves_box = new QGroupBox(Histogram_control_panel_base);
        _curves_box->setObjectName(QString::fromUtf8("_curves_box"));
        _curves_box->setAcceptDrops(true);
        _curves_box->setAlignment(Qt::AlignVCenter);

        vboxLayout->addWidget(_curves_box);

        spacer4 = new QSpacerItem(20, 260, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer4);


        retranslateUi(Histogram_control_panel_base);

        QMetaObject::connectSlotsByName(Histogram_control_panel_base);
    } // setupUi

    void retranslateUi(QWidget *Histogram_control_panel_base)
    {
        Histogram_control_panel_base->setWindowTitle(QApplication::translate("Histogram_control_panel_base", "Histogram", 0, QApplication::UnicodeUTF8));
        property_selector_box_->setTitle(QString());
        textLabel1->setText(QApplication::translate("Histogram_control_panel_base", "Bins", 0, QApplication::UnicodeUTF8));
        groupBox12->setTitle(QApplication::translate("Histogram_control_panel_base", "Clipping Values", 0, QApplication::UnicodeUTF8));
        reset_clips_button_->setText(QApplication::translate("Histogram_control_panel_base", "Reset", 0, QApplication::UnicodeUTF8));
        textLabel3_2->setText(QApplication::translate("Histogram_control_panel_base", "Max", 0, QApplication::UnicodeUTF8));
        textLabel3->setText(QApplication::translate("Histogram_control_panel_base", "Min", 0, QApplication::UnicodeUTF8));
        _curves_box->setTitle(QApplication::translate("Histogram_control_panel_base", "Plot type", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Histogram_control_panel_base);
    } // retranslateUi

};

namespace Ui {
    class Histogram_control_panel_base: public Ui_Histogram_control_panel_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_CONTROL_PANEL_BASE_H
