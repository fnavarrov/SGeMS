/********************************************************************************
** Form generated from reading ui file 'controls_widget.ui'
**
** Created: Sun Nov 1 20:46:25 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONTROLS_WIDGET_H
#define UI_CONTROLS_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlsWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *Frame7;
    QVBoxLayout *vboxLayout;
    QGroupBox *param_groupbox_;
    QHBoxLayout *hboxLayout;
    QPushButton *load_button_;
    QPushButton *save_button_;
    QSpacerItem *spacerItem;
    QPushButton *clear_button_;
    QSpacerItem *spacerItem1;
    QPushButton *run_button_;

    void setupUi(QWidget *ControlsWidget)
    {
        if (ControlsWidget->objectName().isEmpty())
            ControlsWidget->setObjectName(QString::fromUtf8("ControlsWidget"));
        ControlsWidget->resize(301, 108);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlsWidget->sizePolicy().hasHeightForWidth());
        ControlsWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ControlsWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setVerticalSpacing(1);
        gridLayout->setContentsMargins(1, 1, 1, 1);
        Frame7 = new QFrame(ControlsWidget);
        Frame7->setObjectName(QString::fromUtf8("Frame7"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Frame7->sizePolicy().hasHeightForWidth());
        Frame7->setSizePolicy(sizePolicy1);
        Frame7->setFrameShape(QFrame::NoFrame);
        Frame7->setFrameShadow(QFrame::Plain);
        vboxLayout = new QVBoxLayout(Frame7);
        vboxLayout->setSpacing(1);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        param_groupbox_ = new QGroupBox(Frame7);
        param_groupbox_->setObjectName(QString::fromUtf8("param_groupbox_"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(param_groupbox_->sizePolicy().hasHeightForWidth());
        param_groupbox_->setSizePolicy(sizePolicy2);
        param_groupbox_->setMinimumSize(QSize(0, 50));
        param_groupbox_->setMaximumSize(QSize(32767, 60));
        param_groupbox_->setAlignment(Qt::AlignHCenter);
        param_groupbox_->setFlat(false);
        hboxLayout = new QHBoxLayout(param_groupbox_);
        hboxLayout->setSpacing(3);
        hboxLayout->setMargin(11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(4, 0, 4, 0);
        load_button_ = new QPushButton(param_groupbox_);
        load_button_->setObjectName(QString::fromUtf8("load_button_"));

        hboxLayout->addWidget(load_button_);

        save_button_ = new QPushButton(param_groupbox_);
        save_button_->setObjectName(QString::fromUtf8("save_button_"));

        hboxLayout->addWidget(save_button_);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        clear_button_ = new QPushButton(param_groupbox_);
        clear_button_->setObjectName(QString::fromUtf8("clear_button_"));

        hboxLayout->addWidget(clear_button_);


        vboxLayout->addWidget(param_groupbox_);

        spacerItem1 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem1);

        run_button_ = new QPushButton(Frame7);
        run_button_->setObjectName(QString::fromUtf8("run_button_"));
        run_button_->setMinimumSize(QSize(50, 0));

        vboxLayout->addWidget(run_button_);


        gridLayout->addWidget(Frame7, 0, 0, 1, 1);


        retranslateUi(ControlsWidget);

        QMetaObject::connectSlotsByName(ControlsWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlsWidget)
    {
        ControlsWidget->setWindowTitle(QApplication::translate("ControlsWidget", "Form2", 0, QApplication::UnicodeUTF8));
        param_groupbox_->setTitle(QApplication::translate("ControlsWidget", "Parameters", 0, QApplication::UnicodeUTF8));
        load_button_->setText(QApplication::translate("ControlsWidget", "Load", 0, QApplication::UnicodeUTF8));
        save_button_->setText(QApplication::translate("ControlsWidget", "Save", 0, QApplication::UnicodeUTF8));
        clear_button_->setText(QApplication::translate("ControlsWidget", "Clear All", 0, QApplication::UnicodeUTF8));
        run_button_->setText(QApplication::translate("ControlsWidget", "Run Algorithm", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ControlsWidget);
    } // retranslateUi

};

namespace Ui {
    class ControlsWidget: public Ui_ControlsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLS_WIDGET_H
