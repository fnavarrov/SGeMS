/********************************************************************************
** Form generated from reading ui file 'snapshot_dialog_base.ui'
**
** Created: Sun Nov 1 20:46:24 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SNAPSHOT_DIALOG_BASE_H
#define UI_SNAPSHOT_DIALOG_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Snapshot_dialog_base
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *textLabel1;
    QGroupBox *file_chooser_box_;
    QLabel *textLabel2;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer7;
    QComboBox *filter_chooser_;
    QSpacerItem *spacer6;
    QSpacerItem *spacer5;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacer4;
    QPushButton *close_button_;
    QSpacerItem *spacer2;
    QPushButton *snapshot_button_;
    QSpacerItem *spacer3;
    QSpacerItem *spacer1;

    void setupUi(QDialog *Snapshot_dialog_base)
    {
        if (Snapshot_dialog_base->objectName().isEmpty())
            Snapshot_dialog_base->setObjectName(QString::fromUtf8("Snapshot_dialog_base"));
        Snapshot_dialog_base->resize(287, 298);
        Snapshot_dialog_base->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(Snapshot_dialog_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(10);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        textLabel1 = new QLabel(Snapshot_dialog_base);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setAlignment(Qt::AlignCenter);
        textLabel1->setWordWrap(false);

        vboxLayout->addWidget(textLabel1);

        file_chooser_box_ = new QGroupBox(Snapshot_dialog_base);
        file_chooser_box_->setObjectName(QString::fromUtf8("file_chooser_box_"));
        sizePolicy.setHeightForWidth(file_chooser_box_->sizePolicy().hasHeightForWidth());
        file_chooser_box_->setSizePolicy(sizePolicy);

        vboxLayout->addWidget(file_chooser_box_);

        textLabel2 = new QLabel(Snapshot_dialog_base);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        sizePolicy.setHeightForWidth(textLabel2->sizePolicy().hasHeightForWidth());
        textLabel2->setSizePolicy(sizePolicy);
        textLabel2->setAlignment(Qt::AlignCenter);
        textLabel2->setWordWrap(false);

        vboxLayout->addWidget(textLabel2);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer7 = new QSpacerItem(41, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer7);

        filter_chooser_ = new QComboBox(Snapshot_dialog_base);
        filter_chooser_->setObjectName(QString::fromUtf8("filter_chooser_"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filter_chooser_->sizePolicy().hasHeightForWidth());
        filter_chooser_->setSizePolicy(sizePolicy1);
        filter_chooser_->setMinimumSize(QSize(150, 0));

        hboxLayout->addWidget(filter_chooser_);

        spacer6 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer6);


        vboxLayout->addLayout(hboxLayout);

        spacer5 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer5);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacer4 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer4);

        close_button_ = new QPushButton(Snapshot_dialog_base);
        close_button_->setObjectName(QString::fromUtf8("close_button_"));

        hboxLayout1->addWidget(close_button_);

        spacer2 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer2);

        snapshot_button_ = new QPushButton(Snapshot_dialog_base);
        snapshot_button_->setObjectName(QString::fromUtf8("snapshot_button_"));
        snapshot_button_->setDefault(true);

        hboxLayout1->addWidget(snapshot_button_);

        spacer3 = new QSpacerItem(51, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer3);


        vboxLayout->addLayout(hboxLayout1);

        spacer1 = new QSpacerItem(21, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer1);

        QWidget::setTabOrder(filter_chooser_, snapshot_button_);
        QWidget::setTabOrder(snapshot_button_, close_button_);

        retranslateUi(Snapshot_dialog_base);

        QMetaObject::connectSlotsByName(Snapshot_dialog_base);
    } // setupUi

    void retranslateUi(QDialog *Snapshot_dialog_base)
    {
        Snapshot_dialog_base->setWindowTitle(QApplication::translate("Snapshot_dialog_base", "Camera Snapshot", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("Snapshot_dialog_base", "Save snapshot as:", 0, QApplication::UnicodeUTF8));
        file_chooser_box_->setTitle(QString());
        textLabel2->setText(QApplication::translate("Snapshot_dialog_base", "Image Filter:", 0, QApplication::UnicodeUTF8));
        close_button_->setText(QApplication::translate("Snapshot_dialog_base", "&Close", 0, QApplication::UnicodeUTF8));
        snapshot_button_->setText(QApplication::translate("Snapshot_dialog_base", "Take &Snapshot", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Snapshot_dialog_base);
    } // retranslateUi

};

namespace Ui {
    class Snapshot_dialog_base: public Ui_Snapshot_dialog_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPSHOT_DIALOG_BASE_H
