/********************************************************************************
** Form generated from reading ui file 'variogram_structure_controls_base.ui'
**
** Created: Sun Nov 1 20:46:23 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VARIOGRAM_STRUCTURE_CONTROLS_BASE_H
#define UI_VARIOGRAM_STRUCTURE_CONTROLS_BASE_H

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

class Ui_Variogram_structure_controls_base
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QSpacerItem *Spacer14;
    QLabel *Sill;
    QLineEdit *sill_value_;
    QSpacerItem *Spacer12;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *Spacer10;
    QLabel *Type;
    QComboBox *model_type_;
    QSpacerItem *Spacer11;
    QGroupBox *ranges_box_;
    QHBoxLayout *hboxLayout2;
    QLabel *Angles;
    QLineEdit *ang1_;
    QLineEdit *ang2_;
    QLineEdit *ang3_;
    QSpacerItem *spacer9;

    void setupUi(QWidget *Variogram_structure_controls_base)
    {
        if (Variogram_structure_controls_base->objectName().isEmpty())
            Variogram_structure_controls_base->setObjectName(QString::fromUtf8("Variogram_structure_controls_base"));
        Variogram_structure_controls_base->resize(380, 175);
        vboxLayout = new QVBoxLayout(Variogram_structure_controls_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Spacer14 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Spacer14);

        Sill = new QLabel(Variogram_structure_controls_base);
        Sill->setObjectName(QString::fromUtf8("Sill"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sill->sizePolicy().hasHeightForWidth());
        Sill->setSizePolicy(sizePolicy);
        Sill->setWordWrap(false);

        hboxLayout->addWidget(Sill);

        sill_value_ = new QLineEdit(Variogram_structure_controls_base);
        sill_value_->setObjectName(QString::fromUtf8("sill_value_"));
        sill_value_->setMinimumSize(QSize(40, 0));
        sill_value_->setMaximumSize(QSize(40, 32767));

        hboxLayout->addWidget(sill_value_);

        Spacer12 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Spacer12);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Spacer10 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(Spacer10);

        Type = new QLabel(Variogram_structure_controls_base);
        Type->setObjectName(QString::fromUtf8("Type"));
        sizePolicy.setHeightForWidth(Type->sizePolicy().hasHeightForWidth());
        Type->setSizePolicy(sizePolicy);
        Type->setWordWrap(false);

        hboxLayout1->addWidget(Type);

        model_type_ = new QComboBox(Variogram_structure_controls_base);
        model_type_->setObjectName(QString::fromUtf8("model_type_"));

        hboxLayout1->addWidget(model_type_);

        Spacer11 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(Spacer11);


        vboxLayout->addLayout(hboxLayout1);

        ranges_box_ = new QGroupBox(Variogram_structure_controls_base);
        ranges_box_->setObjectName(QString::fromUtf8("ranges_box_"));

        vboxLayout->addWidget(ranges_box_);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        Angles = new QLabel(Variogram_structure_controls_base);
        Angles->setObjectName(QString::fromUtf8("Angles"));
        Angles->setWordWrap(false);

        hboxLayout2->addWidget(Angles);

        ang1_ = new QLineEdit(Variogram_structure_controls_base);
        ang1_->setObjectName(QString::fromUtf8("ang1_"));

        hboxLayout2->addWidget(ang1_);

        ang2_ = new QLineEdit(Variogram_structure_controls_base);
        ang2_->setObjectName(QString::fromUtf8("ang2_"));

        hboxLayout2->addWidget(ang2_);

        ang3_ = new QLineEdit(Variogram_structure_controls_base);
        ang3_->setObjectName(QString::fromUtf8("ang3_"));

        hboxLayout2->addWidget(ang3_);


        vboxLayout->addLayout(hboxLayout2);

        spacer9 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer9);


        retranslateUi(Variogram_structure_controls_base);

        model_type_->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Variogram_structure_controls_base);
    } // setupUi

    void retranslateUi(QWidget *Variogram_structure_controls_base)
    {
        Variogram_structure_controls_base->setWindowTitle(QApplication::translate("Variogram_structure_controls_base", "Variogram Input", 0, QApplication::UnicodeUTF8));
        Sill->setText(QApplication::translate("Variogram_structure_controls_base", "Sill (Contribution)", 0, QApplication::UnicodeUTF8));
        Type->setText(QApplication::translate("Variogram_structure_controls_base", "Type", 0, QApplication::UnicodeUTF8));
        model_type_->clear();
        model_type_->insertItems(0, QStringList()
         << QApplication::translate("Variogram_structure_controls_base", "Spherical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Variogram_structure_controls_base", "Exponential", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Variogram_structure_controls_base", "Gaussian", 0, QApplication::UnicodeUTF8)
        );
        ranges_box_->setTitle(QApplication::translate("Variogram_structure_controls_base", "Ranges", 0, QApplication::UnicodeUTF8));
        Angles->setText(QApplication::translate("Variogram_structure_controls_base", "Angles", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Variogram_structure_controls_base);
    } // retranslateUi

};

namespace Ui {
    class Variogram_structure_controls_base: public Ui_Variogram_structure_controls_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIOGRAM_STRUCTURE_CONTROLS_BASE_H
