/********************************************************************************
** Form generated from reading ui file 'variogram_structure_base.ui'
**
** Created: Sun Nov 1 20:45:03 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VARIOGRAM_STRUCTURE_BASE_H
#define UI_VARIOGRAM_STRUCTURE_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Variogram_structure_base
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QLabel *TextLabel2;
    QLineEdit *contribution_edit_;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem2;
    QLabel *TextLabel1;
    QComboBox *type_selector_;
    QSpacerItem *spacerItem3;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem5;
    QGroupBox *anisotropy_table_box_;
    QSpacerItem *spacerItem6;

    void setupUi(QWidget *Variogram_structure_base)
    {
        if (Variogram_structure_base->objectName().isEmpty())
            Variogram_structure_base->setObjectName(QString::fromUtf8("Variogram_structure_base"));
        Variogram_structure_base->resize(435, 174);
        vboxLayout = new QVBoxLayout(Variogram_structure_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(9);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        TextLabel2 = new QLabel(Variogram_structure_base);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel2->sizePolicy().hasHeightForWidth());
        TextLabel2->setSizePolicy(sizePolicy);
        TextLabel2->setWordWrap(false);

        hboxLayout->addWidget(TextLabel2);

        contribution_edit_ = new QLineEdit(Variogram_structure_base);
        contribution_edit_->setObjectName(QString::fromUtf8("contribution_edit_"));
        contribution_edit_->setMinimumSize(QSize(40, 0));
        contribution_edit_->setMaximumSize(QSize(40, 32767));

        hboxLayout->addWidget(contribution_edit_);

        spacerItem1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem2);

        TextLabel1 = new QLabel(Variogram_structure_base);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        sizePolicy.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy);
        TextLabel1->setWordWrap(false);

        hboxLayout1->addWidget(TextLabel1);

        type_selector_ = new QComboBox(Variogram_structure_base);
        type_selector_->setObjectName(QString::fromUtf8("type_selector_"));

        hboxLayout1->addWidget(type_selector_);

        spacerItem3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem3);


        vboxLayout->addLayout(hboxLayout1);

        spacerItem4 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem4);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacerItem5 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem5);

        anisotropy_table_box_ = new QGroupBox(Variogram_structure_base);
        anisotropy_table_box_->setObjectName(QString::fromUtf8("anisotropy_table_box_"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(anisotropy_table_box_->sizePolicy().hasHeightForWidth());
        anisotropy_table_box_->setSizePolicy(sizePolicy1);

        hboxLayout2->addWidget(anisotropy_table_box_);

        spacerItem6 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem6);


        vboxLayout->addLayout(hboxLayout2);


        retranslateUi(Variogram_structure_base);

        QMetaObject::connectSlotsByName(Variogram_structure_base);
    } // setupUi

    void retranslateUi(QWidget *Variogram_structure_base)
    {
        Variogram_structure_base->setWindowTitle(QApplication::translate("Variogram_structure_base", "Variogram Input", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("Variogram_structure_base", "Contribution", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("Variogram_structure_base", "Type", 0, QApplication::UnicodeUTF8));
        type_selector_->clear();
        type_selector_->insertItems(0, QStringList()
         << QApplication::translate("Variogram_structure_base", "Spherical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Variogram_structure_base", "Exponential", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Variogram_structure_base", "Gaussian", 0, QApplication::UnicodeUTF8)
        );
        anisotropy_table_box_->setTitle(QString());
        Q_UNUSED(Variogram_structure_base);
    } // retranslateUi

};

namespace Ui {
    class Variogram_structure_base: public Ui_Variogram_structure_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIOGRAM_STRUCTURE_BASE_H
