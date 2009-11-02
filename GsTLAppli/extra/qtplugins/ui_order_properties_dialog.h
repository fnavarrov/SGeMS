/********************************************************************************
** Form generated from reading ui file 'order_properties_dialog.ui'
**
** Created: Sun Nov 1 20:45:03 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ORDER_PROPERTIES_DIALOG_H
#define UI_ORDER_PROPERTIES_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Ordered_property_selector_dialog_base
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QGroupBox *selector_box_;
    QVBoxLayout *vboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *left2right_button_;
    QPushButton *right2left_button_;
    QSpacerItem *spacerItem1;
    QGroupBox *groupBox2;
    QVBoxLayout *vboxLayout1;
    QListWidget *selected_properties_;
    QVBoxLayout *vboxLayout2;
    QPushButton *up_button_;
    QPushButton *down_button_;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem3;
    QPushButton *ok_button_;
    QPushButton *cancel_button_;

    void setupUi(QDialog *Ordered_property_selector_dialog_base)
    {
        if (Ordered_property_selector_dialog_base->objectName().isEmpty())
            Ordered_property_selector_dialog_base->setObjectName(QString::fromUtf8("Ordered_property_selector_dialog_base"));
        Ordered_property_selector_dialog_base->resize(469, 344);
        Ordered_property_selector_dialog_base->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(Ordered_property_selector_dialog_base);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        selector_box_ = new QGroupBox(Ordered_property_selector_dialog_base);
        selector_box_->setObjectName(QString::fromUtf8("selector_box_"));

        hboxLayout->addWidget(selector_box_);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        spacerItem = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

        left2right_button_ = new QPushButton(Ordered_property_selector_dialog_base);
        left2right_button_->setObjectName(QString::fromUtf8("left2right_button_"));
        const QIcon icon = QIcon(QString::fromUtf8(":/icons/icons/right.png"));
        left2right_button_->setIcon(icon);

        vboxLayout->addWidget(left2right_button_);

        right2left_button_ = new QPushButton(Ordered_property_selector_dialog_base);
        right2left_button_->setObjectName(QString::fromUtf8("right2left_button_"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/icons/icons/left.png"));
        right2left_button_->setIcon(icon1);

        vboxLayout->addWidget(right2left_button_);

        spacerItem1 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem1);


        hboxLayout->addLayout(vboxLayout);

        groupBox2 = new QGroupBox(Ordered_property_selector_dialog_base);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        vboxLayout1 = new QVBoxLayout(groupBox2);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        selected_properties_ = new QListWidget(groupBox2);
        selected_properties_->setObjectName(QString::fromUtf8("selected_properties_"));

        vboxLayout1->addWidget(selected_properties_);


        hboxLayout->addWidget(groupBox2);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setMargin(0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        up_button_ = new QPushButton(Ordered_property_selector_dialog_base);
        up_button_->setObjectName(QString::fromUtf8("up_button_"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/icons/icons/up.png"));
        up_button_->setIcon(icon2);

        vboxLayout2->addWidget(up_button_);

        down_button_ = new QPushButton(Ordered_property_selector_dialog_base);
        down_button_->setObjectName(QString::fromUtf8("down_button_"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/icons/icons/down.png"));
        down_button_->setIcon(icon3);

        vboxLayout2->addWidget(down_button_);

        spacerItem2 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem2);


        hboxLayout->addLayout(vboxLayout2);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem3);

        ok_button_ = new QPushButton(Ordered_property_selector_dialog_base);
        ok_button_->setObjectName(QString::fromUtf8("ok_button_"));
        ok_button_->setAutoDefault(true);
        ok_button_->setDefault(true);

        hboxLayout1->addWidget(ok_button_);

        cancel_button_ = new QPushButton(Ordered_property_selector_dialog_base);
        cancel_button_->setObjectName(QString::fromUtf8("cancel_button_"));
        cancel_button_->setAutoDefault(true);

        hboxLayout1->addWidget(cancel_button_);


        gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);


        retranslateUi(Ordered_property_selector_dialog_base);
        QObject::connect(ok_button_, SIGNAL(clicked()), Ordered_property_selector_dialog_base, SLOT(accept()));
        QObject::connect(cancel_button_, SIGNAL(clicked()), Ordered_property_selector_dialog_base, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ordered_property_selector_dialog_base);
    } // setupUi

    void retranslateUi(QDialog *Ordered_property_selector_dialog_base)
    {
        Ordered_property_selector_dialog_base->setWindowTitle(QApplication::translate("Ordered_property_selector_dialog_base", "MyDialog", 0, QApplication::UnicodeUTF8));
        selector_box_->setTitle(QApplication::translate("Ordered_property_selector_dialog_base", "Available Properties", 0, QApplication::UnicodeUTF8));
        left2right_button_->setText(QString());
        right2left_button_->setText(QString());
        groupBox2->setTitle(QApplication::translate("Ordered_property_selector_dialog_base", "Selected Properties", 0, QApplication::UnicodeUTF8));
        up_button_->setText(QString());
        down_button_->setText(QString());
        ok_button_->setText(QApplication::translate("Ordered_property_selector_dialog_base", "&OK", 0, QApplication::UnicodeUTF8));
        ok_button_->setShortcut(QString());
        cancel_button_->setText(QApplication::translate("Ordered_property_selector_dialog_base", "&Cancel", 0, QApplication::UnicodeUTF8));
        cancel_button_->setShortcut(QString());
        Q_UNUSED(Ordered_property_selector_dialog_base);
    } // retranslateUi

};

namespace Ui {
    class Ordered_property_selector_dialog_base: public Ui_Ordered_property_selector_dialog_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_PROPERTIES_DIALOG_H
