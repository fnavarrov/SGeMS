/********************************************************************************
** Form generated from reading ui file 'multichoice_dialog_base.ui'
**
** Created: Sun Nov 1 20:46:28 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MULTICHOICE_DIALOG_BASE_H
#define UI_MULTICHOICE_DIALOG_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Multichoice_dialog_base
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label_;
    QGroupBox *choice_list_box_;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer2;
    QPushButton *ok_button_;
    QSpacerItem *spacer3;
    QPushButton *cancel_button_;
    QSpacerItem *spacer4;

    void setupUi(QDialog *Multichoice_dialog_base)
    {
        if (Multichoice_dialog_base->objectName().isEmpty())
            Multichoice_dialog_base->setObjectName(QString::fromUtf8("Multichoice_dialog_base"));
        Multichoice_dialog_base->resize(310, 168);
        Multichoice_dialog_base->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(Multichoice_dialog_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        label_ = new QLabel(Multichoice_dialog_base);
        label_->setObjectName(QString::fromUtf8("label_"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_->sizePolicy().hasHeightForWidth());
        label_->setSizePolicy(sizePolicy);
        label_->setWordWrap(false);

        vboxLayout->addWidget(label_);

        choice_list_box_ = new QGroupBox(Multichoice_dialog_base);
        choice_list_box_->setObjectName(QString::fromUtf8("choice_list_box_"));

        vboxLayout->addWidget(choice_list_box_);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer2 = new QSpacerItem(42, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer2);

        ok_button_ = new QPushButton(Multichoice_dialog_base);
        ok_button_->setObjectName(QString::fromUtf8("ok_button_"));

        hboxLayout->addWidget(ok_button_);

        spacer3 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer3);

        cancel_button_ = new QPushButton(Multichoice_dialog_base);
        cancel_button_->setObjectName(QString::fromUtf8("cancel_button_"));

        hboxLayout->addWidget(cancel_button_);

        spacer4 = new QSpacerItem(42, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer4);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(Multichoice_dialog_base);

        QMetaObject::connectSlotsByName(Multichoice_dialog_base);
    } // setupUi

    void retranslateUi(QDialog *Multichoice_dialog_base)
    {
        Multichoice_dialog_base->setWindowTitle(QApplication::translate("Multichoice_dialog_base", "Select Objects", 0, QApplication::UnicodeUTF8));
        label_->setText(QApplication::translate("Multichoice_dialog_base", "Select objects:", 0, QApplication::UnicodeUTF8));
        choice_list_box_->setTitle(QString());
        ok_button_->setText(QApplication::translate("Multichoice_dialog_base", "&Ok", 0, QApplication::UnicodeUTF8));
        cancel_button_->setText(QApplication::translate("Multichoice_dialog_base", "&Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Multichoice_dialog_base);
    } // retranslateUi

};

namespace Ui {
    class Multichoice_dialog_base: public Ui_Multichoice_dialog_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTICHOICE_DIALOG_BASE_H
