/********************************************************************************
** Form generated from reading ui file 'delete_properties_dialog_base.ui'
**
** Created: Sun Nov 1 20:46:30 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DELETE_PROPERTIES_DIALOG_BASE_H
#define UI_DELETE_PROPERTIES_DIALOG_BASE_H

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

class Ui_Delete_properties_dialog_base
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *textLabel2;
    QHBoxLayout *hboxLayout;
    QGroupBox *grid_selector_box_;
    QLabel *textLabel3;
    QGroupBox *properties_selector_box_;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *ok_button_;
    QSpacerItem *spacerItem1;
    QPushButton *cancel_button_;
    QSpacerItem *spacerItem2;

    void setupUi(QDialog *Delete_properties_dialog_base)
    {
        if (Delete_properties_dialog_base->objectName().isEmpty())
            Delete_properties_dialog_base->setObjectName(QString::fromUtf8("Delete_properties_dialog_base"));
        Delete_properties_dialog_base->resize(414, 328);
        Delete_properties_dialog_base->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(Delete_properties_dialog_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        textLabel2 = new QLabel(Delete_properties_dialog_base);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel2->sizePolicy().hasHeightForWidth());
        textLabel2->setSizePolicy(sizePolicy);
        textLabel2->setWordWrap(false);

        vboxLayout->addWidget(textLabel2);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        grid_selector_box_ = new QGroupBox(Delete_properties_dialog_base);
        grid_selector_box_->setObjectName(QString::fromUtf8("grid_selector_box_"));
        sizePolicy.setHeightForWidth(grid_selector_box_->sizePolicy().hasHeightForWidth());
        grid_selector_box_->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(grid_selector_box_);


        vboxLayout->addLayout(hboxLayout);

        textLabel3 = new QLabel(Delete_properties_dialog_base);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        sizePolicy.setHeightForWidth(textLabel3->sizePolicy().hasHeightForWidth());
        textLabel3->setSizePolicy(sizePolicy);
        textLabel3->setWordWrap(false);

        vboxLayout->addWidget(textLabel3);

        properties_selector_box_ = new QGroupBox(Delete_properties_dialog_base);
        properties_selector_box_->setObjectName(QString::fromUtf8("properties_selector_box_"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(5));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(properties_selector_box_->sizePolicy().hasHeightForWidth());
        properties_selector_box_->setSizePolicy(sizePolicy1);

        vboxLayout->addWidget(properties_selector_box_);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem = new QSpacerItem(42, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        ok_button_ = new QPushButton(Delete_properties_dialog_base);
        ok_button_->setObjectName(QString::fromUtf8("ok_button_"));

        hboxLayout1->addWidget(ok_button_);

        spacerItem1 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        cancel_button_ = new QPushButton(Delete_properties_dialog_base);
        cancel_button_->setObjectName(QString::fromUtf8("cancel_button_"));

        hboxLayout1->addWidget(cancel_button_);

        spacerItem2 = new QSpacerItem(42, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem2);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(Delete_properties_dialog_base);

        QMetaObject::connectSlotsByName(Delete_properties_dialog_base);
    } // setupUi

    void retranslateUi(QDialog *Delete_properties_dialog_base)
    {
        Delete_properties_dialog_base->setWindowTitle(QApplication::translate("Delete_properties_dialog_base", "Delete Properties", 0, QApplication::UnicodeUTF8));
        textLabel2->setText(QApplication::translate("Delete_properties_dialog_base", "Delete properties from object:", 0, QApplication::UnicodeUTF8));
        grid_selector_box_->setTitle(QString());
        textLabel3->setText(QApplication::translate("Delete_properties_dialog_base", "Delete properties:", 0, QApplication::UnicodeUTF8));
        properties_selector_box_->setTitle(QString());
        ok_button_->setText(QApplication::translate("Delete_properties_dialog_base", "&Delete", 0, QApplication::UnicodeUTF8));
        cancel_button_->setText(QApplication::translate("Delete_properties_dialog_base", "&Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Delete_properties_dialog_base);
    } // retranslateUi

};

namespace Ui {
    class Delete_properties_dialog_base: public Ui_Delete_properties_dialog_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_PROPERTIES_DIALOG_BASE_H
