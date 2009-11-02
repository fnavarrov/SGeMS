/********************************************************************************
** Form generated from reading ui file 'general_display_pref_panel_base.ui'
**
** Created: Sun Nov 1 20:46:27 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GENERAL_DISPLAY_PREF_PANEL_BASE_H
#define UI_GENERAL_DISPLAY_PREF_PANEL_BASE_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_General_display_pref_panel_base
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel2;
    QFrame *Line1;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout2;
    QLabel *TextLabel1;
    QSpinBox *z_scaling_box_;
    QSpacerItem *spacerItem1;
    QGroupBox *ButtonGroup1;
    QVBoxLayout *vboxLayout2;
    QRadioButton *perspective_button_;
    QRadioButton *orthotropic_button_;
    QSpacerItem *spacerItem2;
    QCheckBox *white_background_checkbox_;
    QSpacerItem *spacerItem3;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout3;
    QLabel *TextLabel2_2;
    QFrame *Line1_2;
    QHBoxLayout *hboxLayout4;
    QSpacerItem *spacerItem5;
    QVBoxLayout *vboxLayout3;
    QFrame *colorbar_frame_;
    QVBoxLayout *vboxLayout4;
    QCheckBox *show_colobar_checkbox_;
    QSpacerItem *spacerItem6;
    QCheckBox *_horizontal;
    QHBoxLayout *hboxLayout5;
    QLabel *textLabel1;
    QSpinBox *_numticks;
    QSpacerItem *spacerItem7;
    QPushButton *_load;
    QPushButton *_save;
    QSpacerItem *spacerItem8;
    QSpacerItem *spacerItem9;

    void setupUi(QWidget *General_display_pref_panel_base)
    {
        if (General_display_pref_panel_base->objectName().isEmpty())
            General_display_pref_panel_base->setObjectName(QString::fromUtf8("General_display_pref_panel_base"));
        General_display_pref_panel_base->resize(257, 701);
        vboxLayout = new QVBoxLayout(General_display_pref_panel_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        TextLabel2 = new QLabel(General_display_pref_panel_base);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel2->sizePolicy().hasHeightForWidth());
        TextLabel2->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        TextLabel2->setFont(font);
        TextLabel2->setWordWrap(false);

        hboxLayout->addWidget(TextLabel2);

        Line1 = new QFrame(General_display_pref_panel_base);
        Line1->setObjectName(QString::fromUtf8("Line1"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Line1->sizePolicy().hasHeightForWidth());
        Line1->setSizePolicy(sizePolicy1);
        Line1->setFrameShape(QFrame::HLine);
        Line1->setFrameShadow(QFrame::Raised);
        Line1->setMidLineWidth(1);
        Line1->setFrameShape(QFrame::HLine);

        hboxLayout->addWidget(Line1);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem = new QSpacerItem(47, 21, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        TextLabel1 = new QLabel(General_display_pref_panel_base);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        TextLabel1->setWordWrap(false);

        hboxLayout2->addWidget(TextLabel1);

        z_scaling_box_ = new QSpinBox(General_display_pref_panel_base);
        z_scaling_box_->setObjectName(QString::fromUtf8("z_scaling_box_"));
        sizePolicy1.setHeightForWidth(z_scaling_box_->sizePolicy().hasHeightForWidth());
        z_scaling_box_->setSizePolicy(sizePolicy1);
        z_scaling_box_->setMinimum(1);
        z_scaling_box_->setMaximum(20);

        hboxLayout2->addWidget(z_scaling_box_);


        vboxLayout1->addLayout(hboxLayout2);

        spacerItem1 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout1->addItem(spacerItem1);

        ButtonGroup1 = new QGroupBox(General_display_pref_panel_base);
        ButtonGroup1->setObjectName(QString::fromUtf8("ButtonGroup1"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ButtonGroup1->sizePolicy().hasHeightForWidth());
        ButtonGroup1->setSizePolicy(sizePolicy2);
        ButtonGroup1->setMaximumSize(QSize(16777215, 75));
        vboxLayout2 = new QVBoxLayout(ButtonGroup1);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setMargin(11);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout2->setContentsMargins(11, 11, 11, 11);
        perspective_button_ = new QRadioButton(ButtonGroup1);
        perspective_button_->setObjectName(QString::fromUtf8("perspective_button_"));
        sizePolicy1.setHeightForWidth(perspective_button_->sizePolicy().hasHeightForWidth());
        perspective_button_->setSizePolicy(sizePolicy1);
        perspective_button_->setChecked(true);

        vboxLayout2->addWidget(perspective_button_);

        orthotropic_button_ = new QRadioButton(ButtonGroup1);
        orthotropic_button_->setObjectName(QString::fromUtf8("orthotropic_button_"));
        sizePolicy1.setHeightForWidth(orthotropic_button_->sizePolicy().hasHeightForWidth());
        orthotropic_button_->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(orthotropic_button_);


        vboxLayout1->addWidget(ButtonGroup1);

        spacerItem2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout1->addItem(spacerItem2);

        white_background_checkbox_ = new QCheckBox(General_display_pref_panel_base);
        white_background_checkbox_->setObjectName(QString::fromUtf8("white_background_checkbox_"));
        sizePolicy1.setHeightForWidth(white_background_checkbox_->sizePolicy().hasHeightForWidth());
        white_background_checkbox_->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(white_background_checkbox_);


        hboxLayout1->addLayout(vboxLayout1);

        spacerItem3 = new QSpacerItem(46, 31, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem3);


        vboxLayout->addLayout(hboxLayout1);

        spacerItem4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem4);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        TextLabel2_2 = new QLabel(General_display_pref_panel_base);
        TextLabel2_2->setObjectName(QString::fromUtf8("TextLabel2_2"));
        sizePolicy.setHeightForWidth(TextLabel2_2->sizePolicy().hasHeightForWidth());
        TextLabel2_2->setSizePolicy(sizePolicy);
        TextLabel2_2->setFont(font);
        TextLabel2_2->setWordWrap(false);

        hboxLayout3->addWidget(TextLabel2_2);

        Line1_2 = new QFrame(General_display_pref_panel_base);
        Line1_2->setObjectName(QString::fromUtf8("Line1_2"));
        sizePolicy1.setHeightForWidth(Line1_2->sizePolicy().hasHeightForWidth());
        Line1_2->setSizePolicy(sizePolicy1);
        Line1_2->setFrameShape(QFrame::HLine);
        Line1_2->setFrameShadow(QFrame::Raised);
        Line1_2->setMidLineWidth(1);
        Line1_2->setFrameShape(QFrame::HLine);

        hboxLayout3->addWidget(Line1_2);


        vboxLayout->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem5);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        colorbar_frame_ = new QFrame(General_display_pref_panel_base);
        colorbar_frame_->setObjectName(QString::fromUtf8("colorbar_frame_"));
        colorbar_frame_->setFrameShape(QFrame::StyledPanel);
        colorbar_frame_->setFrameShadow(QFrame::Raised);
        vboxLayout4 = new QVBoxLayout(colorbar_frame_);
        vboxLayout4->setSpacing(6);
        vboxLayout4->setMargin(11);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        show_colobar_checkbox_ = new QCheckBox(colorbar_frame_);
        show_colobar_checkbox_->setObjectName(QString::fromUtf8("show_colobar_checkbox_"));
        show_colobar_checkbox_->setEnabled(false);

        vboxLayout4->addWidget(show_colobar_checkbox_);


        vboxLayout3->addWidget(colorbar_frame_);

        spacerItem6 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout3->addItem(spacerItem6);

        _horizontal = new QCheckBox(General_display_pref_panel_base);
        _horizontal->setObjectName(QString::fromUtf8("_horizontal"));

        vboxLayout3->addWidget(_horizontal);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        textLabel1 = new QLabel(General_display_pref_panel_base);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy3);
        textLabel1->setMaximumSize(QSize(50, 16777215));
        textLabel1->setWordWrap(false);

        hboxLayout5->addWidget(textLabel1);

        _numticks = new QSpinBox(General_display_pref_panel_base);
        _numticks->setObjectName(QString::fromUtf8("_numticks"));
        _numticks->setMinimum(1);
        _numticks->setValue(6);

        hboxLayout5->addWidget(_numticks);


        vboxLayout3->addLayout(hboxLayout5);

        spacerItem7 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout3->addItem(spacerItem7);

        _load = new QPushButton(General_display_pref_panel_base);
        _load->setObjectName(QString::fromUtf8("_load"));

        vboxLayout3->addWidget(_load);

        _save = new QPushButton(General_display_pref_panel_base);
        _save->setObjectName(QString::fromUtf8("_save"));

        vboxLayout3->addWidget(_save);


        hboxLayout4->addLayout(vboxLayout3);

        spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem8);


        vboxLayout->addLayout(hboxLayout4);

        spacerItem9 = new QSpacerItem(20, 131, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem9);


        retranslateUi(General_display_pref_panel_base);

        QMetaObject::connectSlotsByName(General_display_pref_panel_base);
    } // setupUi

    void retranslateUi(QWidget *General_display_pref_panel_base)
    {
        General_display_pref_panel_base->setWindowTitle(QApplication::translate("General_display_pref_panel_base", "Form1", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("General_display_pref_panel_base", "Camera Settings", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("General_display_pref_panel_base", "Z-scaling", 0, QApplication::UnicodeUTF8));
        ButtonGroup1->setTitle(QString());
        perspective_button_->setText(QApplication::translate("General_display_pref_panel_base", "Perspective View", 0, QApplication::UnicodeUTF8));
        orthotropic_button_->setText(QApplication::translate("General_display_pref_panel_base", "Orthotropic View", 0, QApplication::UnicodeUTF8));
        white_background_checkbox_->setText(QApplication::translate("General_display_pref_panel_base", "Use white background", 0, QApplication::UnicodeUTF8));
        TextLabel2_2->setText(QApplication::translate("General_display_pref_panel_base", "Colorbar", 0, QApplication::UnicodeUTF8));
        show_colobar_checkbox_->setText(QApplication::translate("General_display_pref_panel_base", "Show colorbar of :", 0, QApplication::UnicodeUTF8));
        _horizontal->setText(QApplication::translate("General_display_pref_panel_base", "Display Colorbar Horizontally", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("General_display_pref_panel_base", "# of ticks", 0, QApplication::UnicodeUTF8));
        _load->setText(QApplication::translate("General_display_pref_panel_base", "Load colorbar", 0, QApplication::UnicodeUTF8));
        _save->setText(QApplication::translate("General_display_pref_panel_base", "Save colorbar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(General_display_pref_panel_base);
    } // retranslateUi

};

namespace Ui {
    class General_display_pref_panel_base: public Ui_General_display_pref_panel_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERAL_DISPLAY_PREF_PANEL_BASE_H
