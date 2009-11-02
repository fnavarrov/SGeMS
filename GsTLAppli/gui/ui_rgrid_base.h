/********************************************************************************
** Form generated from reading ui file 'rgrid_base.ui'
**
** Created: Sun Nov 1 20:46:22 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RGRID_BASE_H
#define UI_RGRID_BASE_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RGrid_base
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer12;
    QPushButton *load_button_;
    QPushButton *save_button_;
    QSpacerItem *spacer11;
    QSpacerItem *spacer10_3_2;
    QHBoxLayout *hboxLayout1;
    QLabel *textLabel1;
    QFrame *line1;
    QSpacerItem *spacer10_3;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacer14;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout3;
    QLabel *TextLabel1;
    QSpinBox *num_lags_;
    QSpacerItem *Spacer7_2;
    QHBoxLayout *hboxLayout4;
    QLabel *textLabel1_4;
    QSpinBox *directions_count_;
    QSpacerItem *spacer15;
    QLabel *textLabel1_5;
    QSpacerItem *spacer37;
    QSpacerItem *spacer16;
    QGroupBox *table_frame_;
    QSpacerItem *Spacer10_2;
    QGroupBox *standardize_options_box_;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout5;
    QLabel *textLabel1_3;
    QFrame *line1_3;
    QSpacerItem *spacer10;
    QHBoxLayout *hboxLayout6;
    QSpacerItem *spacer23;
    QCheckBox *variance_scale_;
    QSpacerItem *spacer24;
    QSpacerItem *Spacer9_2;

    void setupUi(QWidget *RGrid_base)
    {
        if (RGrid_base->objectName().isEmpty())
            RGrid_base->setObjectName(QString::fromUtf8("RGrid_base"));
        RGrid_base->resize(528, 466);
        vboxLayout = new QVBoxLayout(RGrid_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer12 = new QSpacerItem(249, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer12);

        load_button_ = new QPushButton(RGrid_base);
        load_button_->setObjectName(QString::fromUtf8("load_button_"));

        hboxLayout->addWidget(load_button_);

        save_button_ = new QPushButton(RGrid_base);
        save_button_->setObjectName(QString::fromUtf8("save_button_"));

        hboxLayout->addWidget(save_button_);

        spacer11 = new QSpacerItem(31, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer11);


        vboxLayout->addLayout(hboxLayout);

        spacer10_3_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer10_3_2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        textLabel1 = new QLabel(RGrid_base);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        textLabel1->setFont(font);
        textLabel1->setWordWrap(false);

        hboxLayout1->addWidget(textLabel1);

        line1 = new QFrame(RGrid_base);
        line1->setObjectName(QString::fromUtf8("line1"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line1->sizePolicy().hasHeightForWidth());
        line1->setSizePolicy(sizePolicy1);
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Raised);

        hboxLayout1->addWidget(line1);


        vboxLayout->addLayout(hboxLayout1);

        spacer10_3 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer10_3);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacer14 = new QSpacerItem(82, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer14);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setMargin(0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        TextLabel1 = new QLabel(RGrid_base);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        TextLabel1->setWordWrap(false);

        hboxLayout3->addWidget(TextLabel1);

        num_lags_ = new QSpinBox(RGrid_base);
        num_lags_->setObjectName(QString::fromUtf8("num_lags_"));
        num_lags_->setMaximum(500);
        num_lags_->setMinimum(1);
        num_lags_->setSingleStep(1);
        num_lags_->setValue(1);

        hboxLayout3->addWidget(num_lags_);


        vboxLayout1->addLayout(hboxLayout3);

        Spacer7_2 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout1->addItem(Spacer7_2);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setMargin(0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        textLabel1_4 = new QLabel(RGrid_base);
        textLabel1_4->setObjectName(QString::fromUtf8("textLabel1_4"));
        textLabel1_4->setWordWrap(false);

        hboxLayout4->addWidget(textLabel1_4);

        directions_count_ = new QSpinBox(RGrid_base);
        directions_count_->setObjectName(QString::fromUtf8("directions_count_"));
        directions_count_->setMaximum(20);
        directions_count_->setMinimum(1);

        hboxLayout4->addWidget(directions_count_);


        vboxLayout1->addLayout(hboxLayout4);


        hboxLayout2->addLayout(vboxLayout1);

        spacer15 = new QSpacerItem(41, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer15);

        textLabel1_5 = new QLabel(RGrid_base);
        textLabel1_5->setObjectName(QString::fromUtf8("textLabel1_5"));
        textLabel1_5->setMinimumSize(QSize(150, 0));
        textLabel1_5->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1_5);

        spacer37 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer37);


        vboxLayout->addLayout(hboxLayout2);

        spacer16 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacer16);

        table_frame_ = new QGroupBox(RGrid_base);
        table_frame_->setObjectName(QString::fromUtf8("table_frame_"));

        vboxLayout->addWidget(table_frame_);

        Spacer10_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(Spacer10_2);

        standardize_options_box_ = new QGroupBox(RGrid_base);
        standardize_options_box_->setObjectName(QString::fromUtf8("standardize_options_box_"));
        vboxLayout2 = new QVBoxLayout(standardize_options_box_);
        vboxLayout2->setSpacing(0);
        vboxLayout2->setMargin(0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setMargin(0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        textLabel1_3 = new QLabel(standardize_options_box_);
        textLabel1_3->setObjectName(QString::fromUtf8("textLabel1_3"));
        sizePolicy.setHeightForWidth(textLabel1_3->sizePolicy().hasHeightForWidth());
        textLabel1_3->setSizePolicy(sizePolicy);
        textLabel1_3->setFont(font);
        textLabel1_3->setWordWrap(false);

        hboxLayout5->addWidget(textLabel1_3);

        line1_3 = new QFrame(standardize_options_box_);
        line1_3->setObjectName(QString::fromUtf8("line1_3"));
        sizePolicy1.setHeightForWidth(line1_3->sizePolicy().hasHeightForWidth());
        line1_3->setSizePolicy(sizePolicy1);
        line1_3->setFrameShape(QFrame::HLine);
        line1_3->setFrameShadow(QFrame::Raised);

        hboxLayout5->addWidget(line1_3);


        vboxLayout2->addLayout(hboxLayout5);

        spacer10 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacer10);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setMargin(0);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        spacer23 = new QSpacerItem(71, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout6->addItem(spacer23);

        variance_scale_ = new QCheckBox(standardize_options_box_);
        variance_scale_->setObjectName(QString::fromUtf8("variance_scale_"));

        hboxLayout6->addWidget(variance_scale_);

        spacer24 = new QSpacerItem(81, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout6->addItem(spacer24);


        vboxLayout2->addLayout(hboxLayout6);


        vboxLayout->addWidget(standardize_options_box_);

        Spacer9_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(Spacer9_2);

        QWidget::setTabOrder(num_lags_, directions_count_);
        QWidget::setTabOrder(directions_count_, variance_scale_);
        QWidget::setTabOrder(variance_scale_, load_button_);
        QWidget::setTabOrder(load_button_, save_button_);

        retranslateUi(RGrid_base);

        QMetaObject::connectSlotsByName(RGrid_base);
    } // setupUi

    void retranslateUi(QWidget *RGrid_base)
    {
        RGrid_base->setWindowTitle(QApplication::translate("RGrid_base", "RGrid_base", 0, QApplication::UnicodeUTF8));
        load_button_->setText(QApplication::translate("RGrid_base", "Load Parameters...", 0, QApplication::UnicodeUTF8));
        save_button_->setText(QApplication::translate("RGrid_base", "Save", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("RGrid_base", "Lags and Directions", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("RGrid_base", "Number of lags", 0, QApplication::UnicodeUTF8));
        textLabel1_4->setText(QApplication::translate("RGrid_base", "Number of directions", 0, QApplication::UnicodeUTF8));
        textLabel1_5->setText(QApplication::translate("RGrid_base", "<i>Directions are defined by a vector  (x,y,z)<br>\n"
"\n"
"For example (1,1,0) is the 45degrees line in the (X,Y) plane. Units are \"number of grid cells\" (hence x, y and z are integers)</i>", 0, QApplication::UnicodeUTF8));
        table_frame_->setTitle(QString());
        standardize_options_box_->setTitle(QString());
        textLabel1_3->setText(QApplication::translate("RGrid_base", "Misc.", 0, QApplication::UnicodeUTF8));
        variance_scale_->setText(QApplication::translate("RGrid_base", "Standardize by Cov(head, tail)", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(RGrid_base);
    } // retranslateUi

};

namespace Ui {
    class RGrid_base: public Ui_RGrid_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGRID_BASE_H
