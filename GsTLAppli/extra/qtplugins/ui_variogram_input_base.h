/********************************************************************************
** Form generated from reading ui file 'variogram_input_base.ui'
**
** Created: Sun Nov 1 20:45:03 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VARIOGRAM_INPUT_BASE_H
#define UI_VARIOGRAM_INPUT_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_Variogram_input_base
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *load_button_;
    QSpacerItem *spacerItem1;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem3;
    QLabel *TextLabel1;
    QLineEdit *nugget_effect_edit_;
    QSpacerItem *spacerItem4;
    QSpacerItem *spacerItem5;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem6;
    QLabel *TextLabel2_2;
    QSpinBox *structures_count_;
    QSpacerItem *spacerItem7;
    QSpacerItem *spacerItem8;
    QGroupBox *structures_main_box_;
    QVBoxLayout *vboxLayout1;

    void setupUi(QWidget *Variogram_input_base)
    {
        if (Variogram_input_base->objectName().isEmpty())
            Variogram_input_base->setObjectName(QString::fromUtf8("Variogram_input_base"));
        Variogram_input_base->resize(194, 222);
        vboxLayout = new QVBoxLayout(Variogram_input_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(1);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(61, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        load_button_ = new QPushButton(Variogram_input_base);
        load_button_->setObjectName(QString::fromUtf8("load_button_"));

        hboxLayout->addWidget(load_button_);

        spacerItem1 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);


        vboxLayout->addLayout(hboxLayout);

        spacerItem2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem3 = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem3);

        TextLabel1 = new QLabel(Variogram_input_base);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        TextLabel1->setWordWrap(false);

        hboxLayout1->addWidget(TextLabel1);

        nugget_effect_edit_ = new QLineEdit(Variogram_input_base);
        nugget_effect_edit_->setObjectName(QString::fromUtf8("nugget_effect_edit_"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nugget_effect_edit_->sizePolicy().hasHeightForWidth());
        nugget_effect_edit_->setSizePolicy(sizePolicy);
        nugget_effect_edit_->setMaximumSize(QSize(60, 32767));

        hboxLayout1->addWidget(nugget_effect_edit_);

        spacerItem4 = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem4);


        vboxLayout->addLayout(hboxLayout1);

        spacerItem5 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem5);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacerItem6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem6);

        TextLabel2_2 = new QLabel(Variogram_input_base);
        TextLabel2_2->setObjectName(QString::fromUtf8("TextLabel2_2"));
        TextLabel2_2->setWordWrap(false);

        hboxLayout2->addWidget(TextLabel2_2);

        structures_count_ = new QSpinBox(Variogram_input_base);
        structures_count_->setObjectName(QString::fromUtf8("structures_count_"));
        structures_count_->setMaximum(10);
        structures_count_->setValue(1);

        hboxLayout2->addWidget(structures_count_);

        spacerItem7 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem7);


        vboxLayout->addLayout(hboxLayout2);

        spacerItem8 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem8);

        structures_main_box_ = new QGroupBox(Variogram_input_base);
        structures_main_box_->setObjectName(QString::fromUtf8("structures_main_box_"));
        structures_main_box_->setAlignment(Qt::AlignLeading);
        structures_main_box_->setFlat(false);
        vboxLayout1 = new QVBoxLayout(structures_main_box_);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(2);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));

        vboxLayout->addWidget(structures_main_box_);


        retranslateUi(Variogram_input_base);

        QMetaObject::connectSlotsByName(Variogram_input_base);
    } // setupUi

    void retranslateUi(QWidget *Variogram_input_base)
    {
        Variogram_input_base->setWindowTitle(QApplication::translate("Variogram_input_base", "Variogram Input", 0, QApplication::UnicodeUTF8));
        load_button_->setText(QApplication::translate("Variogram_input_base", "Load existing model...", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("Variogram_input_base", "Nugget Effect", 0, QApplication::UnicodeUTF8));
        TextLabel2_2->setText(QApplication::translate("Variogram_input_base", "Nb of Structures", 0, QApplication::UnicodeUTF8));
        structures_main_box_->setTitle(QString());
        Q_UNUSED(Variogram_input_base);
    } // retranslateUi

};

namespace Ui {
    class Variogram_input_base: public Ui_Variogram_input_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIOGRAM_INPUT_BASE_H
