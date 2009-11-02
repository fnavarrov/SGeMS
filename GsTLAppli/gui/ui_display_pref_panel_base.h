/********************************************************************************
** Form generated from reading ui file 'display_pref_panel_base.ui'
**
** Created: Sun Nov 1 20:46:29 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DISPLAY_PREF_PANEL_BASE_H
#define UI_DISPLAY_PREF_PANEL_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
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

class Ui_DisplayPrefPanelBase
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel1_3;
    QFrame *Line3_3;
    QFrame *frame;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    QCheckBox *BBox_checkbox_;
    QCheckBox *show_mesh_checkbox_;
    QHBoxLayout *hboxLayout2;
    QLabel *point_size_label_;
    QSpinBox *point_size_spinbox_;
    QSpacerItem *spacerItem1;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout3;
    QLabel *TextLabel1_3_3;
    QFrame *Line3_3_3;
    QFrame *property_prefs_;
    QHBoxLayout *hboxLayout4;
    QSpacerItem *spacerItem3;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout5;
    QCheckBox *prop_painted_checkbox_;
    QSpacerItem *spacerItem4;
    QSpacerItem *spacerItem5;
    QHBoxLayout *hboxLayout6;
    QLabel *TextLabel1;
    QComboBox *property_selector_;
    QSpacerItem *spacerItem6;
    QHBoxLayout *hboxLayout7;
    QLabel *TextLabel1_2;
    QComboBox *colormap_selector_;
    QFrame *colormap_pix_;
    QVBoxLayout *vboxLayout3;
    QHBoxLayout *hboxLayout8;
    QLabel *TextLabel2;
    QLineEdit *min_cmap_value_edit_;
    QSpacerItem *spacerItem7;
    QLabel *TextLabel2_2;
    QLineEdit *max_cmap_value_edit_;
    QPushButton *reset_cmap_bounds_button_;
    QSpacerItem *spacerItem8;
    QSpacerItem *spacerItem9;
    QHBoxLayout *hboxLayout9;
    QLabel *slices_sep_label__2;
    QFrame *slices_sep__2;
    QFrame *volume_explorer_prefs_;
    QVBoxLayout *vboxLayout4;
    QHBoxLayout *hboxLayout10;
    QSpacerItem *spacerItem10;
    QCheckBox *volume_explorer_checkbox_;
    QSpacerItem *spacerItem11;
    QSpacerItem *spacerItem12;
    QHBoxLayout *hboxLayout11;
    QSpacerItem *spacerItem13;
    QFrame *transparency_box_;
    QVBoxLayout *vboxLayout5;
    QLabel *textLabel1;
    QLineEdit *transparency_lineedit_;
    QFrame *transparency_colormap_pix_;
    QHBoxLayout *hboxLayout12;
    QSpacerItem *spacerItem14;
    QCheckBox *hide_volume_checkbox_;
    QSpacerItem *spacerItem15;
    QSpacerItem *spacerItem16;
    QSpacerItem *spacerItem17;
    QHBoxLayout *hboxLayout13;
    QSpacerItem *spacerItem18;
    QPushButton *add_slice_button_;
    QComboBox *slice_axis_selector_;
    QSpacerItem *spacerItem19;
    QSpacerItem *spacerItem20;

    void setupUi(QWidget *DisplayPrefPanelBase)
    {
        if (DisplayPrefPanelBase->objectName().isEmpty())
            DisplayPrefPanelBase->setObjectName(QString::fromUtf8("DisplayPrefPanelBase"));
        DisplayPrefPanelBase->resize(250, 821);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DisplayPrefPanelBase->sizePolicy().hasHeightForWidth());
        DisplayPrefPanelBase->setSizePolicy(sizePolicy);
        DisplayPrefPanelBase->setMinimumSize(QSize(250, 0));
        vboxLayout = new QVBoxLayout(DisplayPrefPanelBase);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        TextLabel1_3 = new QLabel(DisplayPrefPanelBase);
        TextLabel1_3->setObjectName(QString::fromUtf8("TextLabel1_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabel1_3->sizePolicy().hasHeightForWidth());
        TextLabel1_3->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        TextLabel1_3->setFont(font);
        TextLabel1_3->setWordWrap(false);

        hboxLayout->addWidget(TextLabel1_3);

        Line3_3 = new QFrame(DisplayPrefPanelBase);
        Line3_3->setObjectName(QString::fromUtf8("Line3_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Line3_3->sizePolicy().hasHeightForWidth());
        Line3_3->setSizePolicy(sizePolicy2);
        Line3_3->setFrameShape(QFrame::HLine);
        Line3_3->setFrameShadow(QFrame::Raised);
        Line3_3->setLineWidth(1);
        Line3_3->setMidLineWidth(1);

        hboxLayout->addWidget(Line3_3);


        vboxLayout->addLayout(hboxLayout);

        frame = new QFrame(DisplayPrefPanelBase);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        hboxLayout1 = new QHBoxLayout(frame);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(11);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout1->setContentsMargins(2, 2, 2, 2);
        spacerItem = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        BBox_checkbox_ = new QCheckBox(frame);
        BBox_checkbox_->setObjectName(QString::fromUtf8("BBox_checkbox_"));
        BBox_checkbox_->setMinimumSize(QSize(0, 15));
        QFont font1;
        BBox_checkbox_->setFont(font1);

        vboxLayout1->addWidget(BBox_checkbox_);

        show_mesh_checkbox_ = new QCheckBox(frame);
        show_mesh_checkbox_->setObjectName(QString::fromUtf8("show_mesh_checkbox_"));
        show_mesh_checkbox_->setMinimumSize(QSize(0, 15));
        show_mesh_checkbox_->setFont(font1);

        vboxLayout1->addWidget(show_mesh_checkbox_);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        point_size_label_ = new QLabel(frame);
        point_size_label_->setObjectName(QString::fromUtf8("point_size_label_"));
        point_size_label_->setWordWrap(false);

        hboxLayout2->addWidget(point_size_label_);

        point_size_spinbox_ = new QSpinBox(frame);
        point_size_spinbox_->setObjectName(QString::fromUtf8("point_size_spinbox_"));
        point_size_spinbox_->setMinimumSize(QSize(0, 20));
        point_size_spinbox_->setMaximumSize(QSize(50, 32767));
        point_size_spinbox_->setMinimum(1);
        point_size_spinbox_->setMaximum(20);
        point_size_spinbox_->setValue(4);

        hboxLayout2->addWidget(point_size_spinbox_);


        vboxLayout1->addLayout(hboxLayout2);


        hboxLayout1->addLayout(vboxLayout1);

        spacerItem1 = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);


        vboxLayout->addWidget(frame);

        spacerItem2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        TextLabel1_3_3 = new QLabel(DisplayPrefPanelBase);
        TextLabel1_3_3->setObjectName(QString::fromUtf8("TextLabel1_3_3"));
        sizePolicy1.setHeightForWidth(TextLabel1_3_3->sizePolicy().hasHeightForWidth());
        TextLabel1_3_3->setSizePolicy(sizePolicy1);
        TextLabel1_3_3->setFont(font);
        TextLabel1_3_3->setWordWrap(false);

        hboxLayout3->addWidget(TextLabel1_3_3);

        Line3_3_3 = new QFrame(DisplayPrefPanelBase);
        Line3_3_3->setObjectName(QString::fromUtf8("Line3_3_3"));
        sizePolicy2.setHeightForWidth(Line3_3_3->sizePolicy().hasHeightForWidth());
        Line3_3_3->setSizePolicy(sizePolicy2);
        Line3_3_3->setFrameShape(QFrame::HLine);
        Line3_3_3->setFrameShadow(QFrame::Raised);
        Line3_3_3->setLineWidth(1);
        Line3_3_3->setMidLineWidth(1);

        hboxLayout3->addWidget(Line3_3_3);


        vboxLayout->addLayout(hboxLayout3);

        property_prefs_ = new QFrame(DisplayPrefPanelBase);
        property_prefs_->setObjectName(QString::fromUtf8("property_prefs_"));
        property_prefs_->setFrameShape(QFrame::StyledPanel);
        property_prefs_->setFrameShadow(QFrame::Raised);
        hboxLayout4 = new QHBoxLayout(property_prefs_);
        hboxLayout4->setSpacing(0);
        hboxLayout4->setMargin(11);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        hboxLayout4->setContentsMargins(2, 2, 2, 2);
        spacerItem3 = new QSpacerItem(4, 218, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem3);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        prop_painted_checkbox_ = new QCheckBox(property_prefs_);
        prop_painted_checkbox_->setObjectName(QString::fromUtf8("prop_painted_checkbox_"));
        prop_painted_checkbox_->setFont(font1);

        hboxLayout5->addWidget(prop_painted_checkbox_);

        spacerItem4 = new QSpacerItem(20, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem4);


        vboxLayout2->addLayout(hboxLayout5);

        spacerItem5 = new QSpacerItem(176, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacerItem5);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        TextLabel1 = new QLabel(property_prefs_);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy3);
        TextLabel1->setFont(font1);
        TextLabel1->setWordWrap(false);

        hboxLayout6->addWidget(TextLabel1);

        property_selector_ = new QComboBox(property_prefs_);
        property_selector_->setObjectName(QString::fromUtf8("property_selector_"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(property_selector_->sizePolicy().hasHeightForWidth());
        property_selector_->setSizePolicy(sizePolicy4);
        property_selector_->setFont(font1);
        property_selector_->setEditable(false);
        property_selector_->setAutoCompletion(false);
        property_selector_->setDuplicatesEnabled(false);

        hboxLayout6->addWidget(property_selector_);


        vboxLayout2->addLayout(hboxLayout6);

        spacerItem6 = new QSpacerItem(176, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacerItem6);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        TextLabel1_2 = new QLabel(property_prefs_);
        TextLabel1_2->setObjectName(QString::fromUtf8("TextLabel1_2"));
        sizePolicy3.setHeightForWidth(TextLabel1_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2->setSizePolicy(sizePolicy3);
        TextLabel1_2->setFont(font1);
        TextLabel1_2->setWordWrap(false);

        hboxLayout7->addWidget(TextLabel1_2);

        colormap_selector_ = new QComboBox(property_prefs_);
        colormap_selector_->setObjectName(QString::fromUtf8("colormap_selector_"));
        sizePolicy4.setHeightForWidth(colormap_selector_->sizePolicy().hasHeightForWidth());
        colormap_selector_->setSizePolicy(sizePolicy4);
        colormap_selector_->setFont(font1);

        hboxLayout7->addWidget(colormap_selector_);


        vboxLayout2->addLayout(hboxLayout7);

        colormap_pix_ = new QFrame(property_prefs_);
        colormap_pix_->setObjectName(QString::fromUtf8("colormap_pix_"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(colormap_pix_->sizePolicy().hasHeightForWidth());
        colormap_pix_->setSizePolicy(sizePolicy5);
        colormap_pix_->setMinimumSize(QSize(200, 50));
        colormap_pix_->setFrameShape(QFrame::NoFrame);
        colormap_pix_->setFrameShadow(QFrame::Plain);
        colormap_pix_->setLineWidth(1);

        vboxLayout2->addWidget(colormap_pix_);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setSpacing(6);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        hboxLayout8->setContentsMargins(0, 0, 0, 0);
        TextLabel2 = new QLabel(property_prefs_);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        TextLabel2->setFont(font1);
        TextLabel2->setWordWrap(false);

        hboxLayout8->addWidget(TextLabel2);

        min_cmap_value_edit_ = new QLineEdit(property_prefs_);
        min_cmap_value_edit_->setObjectName(QString::fromUtf8("min_cmap_value_edit_"));
        sizePolicy3.setHeightForWidth(min_cmap_value_edit_->sizePolicy().hasHeightForWidth());
        min_cmap_value_edit_->setSizePolicy(sizePolicy3);
        min_cmap_value_edit_->setMaximumSize(QSize(50, 32767));
        min_cmap_value_edit_->setFont(font1);

        hboxLayout8->addWidget(min_cmap_value_edit_);

        spacerItem7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        hboxLayout8->addItem(spacerItem7);

        TextLabel2_2 = new QLabel(property_prefs_);
        TextLabel2_2->setObjectName(QString::fromUtf8("TextLabel2_2"));
        TextLabel2_2->setFont(font1);
        TextLabel2_2->setWordWrap(false);

        hboxLayout8->addWidget(TextLabel2_2);

        max_cmap_value_edit_ = new QLineEdit(property_prefs_);
        max_cmap_value_edit_->setObjectName(QString::fromUtf8("max_cmap_value_edit_"));
        sizePolicy2.setHeightForWidth(max_cmap_value_edit_->sizePolicy().hasHeightForWidth());
        max_cmap_value_edit_->setSizePolicy(sizePolicy2);
        max_cmap_value_edit_->setMaximumSize(QSize(50, 32767));
        max_cmap_value_edit_->setFont(font1);

        hboxLayout8->addWidget(max_cmap_value_edit_);


        vboxLayout3->addLayout(hboxLayout8);

        reset_cmap_bounds_button_ = new QPushButton(property_prefs_);
        reset_cmap_bounds_button_->setObjectName(QString::fromUtf8("reset_cmap_bounds_button_"));
        reset_cmap_bounds_button_->setFont(font1);

        vboxLayout3->addWidget(reset_cmap_bounds_button_);


        vboxLayout2->addLayout(vboxLayout3);


        hboxLayout4->addLayout(vboxLayout2);

        spacerItem8 = new QSpacerItem(4, 218, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem8);


        vboxLayout->addWidget(property_prefs_);

        spacerItem9 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem9);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setSpacing(6);
        hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
        hboxLayout9->setContentsMargins(0, 0, 0, 0);
        slices_sep_label__2 = new QLabel(DisplayPrefPanelBase);
        slices_sep_label__2->setObjectName(QString::fromUtf8("slices_sep_label__2"));
        sizePolicy1.setHeightForWidth(slices_sep_label__2->sizePolicy().hasHeightForWidth());
        slices_sep_label__2->setSizePolicy(sizePolicy1);
        slices_sep_label__2->setFont(font);
        slices_sep_label__2->setWordWrap(false);

        hboxLayout9->addWidget(slices_sep_label__2);

        slices_sep__2 = new QFrame(DisplayPrefPanelBase);
        slices_sep__2->setObjectName(QString::fromUtf8("slices_sep__2"));
        sizePolicy2.setHeightForWidth(slices_sep__2->sizePolicy().hasHeightForWidth());
        slices_sep__2->setSizePolicy(sizePolicy2);
        slices_sep__2->setFrameShape(QFrame::HLine);
        slices_sep__2->setFrameShadow(QFrame::Raised);
        slices_sep__2->setLineWidth(1);
        slices_sep__2->setMidLineWidth(1);

        hboxLayout9->addWidget(slices_sep__2);


        vboxLayout->addLayout(hboxLayout9);

        volume_explorer_prefs_ = new QFrame(DisplayPrefPanelBase);
        volume_explorer_prefs_->setObjectName(QString::fromUtf8("volume_explorer_prefs_"));
        volume_explorer_prefs_->setFrameShape(QFrame::StyledPanel);
        volume_explorer_prefs_->setFrameShadow(QFrame::Raised);
        vboxLayout4 = new QVBoxLayout(volume_explorer_prefs_);
        vboxLayout4->setSpacing(6);
        vboxLayout4->setMargin(11);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        vboxLayout4->setContentsMargins(2, 2, 2, 2);
        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setSpacing(6);
        hboxLayout10->setObjectName(QString::fromUtf8("hboxLayout10"));
        hboxLayout10->setContentsMargins(0, 0, 0, 0);
        spacerItem10 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout10->addItem(spacerItem10);

        volume_explorer_checkbox_ = new QCheckBox(volume_explorer_prefs_);
        volume_explorer_checkbox_->setObjectName(QString::fromUtf8("volume_explorer_checkbox_"));
        volume_explorer_checkbox_->setFont(font1);

        hboxLayout10->addWidget(volume_explorer_checkbox_);

        spacerItem11 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout10->addItem(spacerItem11);


        vboxLayout4->addLayout(hboxLayout10);

        spacerItem12 = new QSpacerItem(190, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout4->addItem(spacerItem12);

        hboxLayout11 = new QHBoxLayout();
        hboxLayout11->setSpacing(0);
        hboxLayout11->setObjectName(QString::fromUtf8("hboxLayout11"));
        spacerItem13 = new QSpacerItem(4, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout11->addItem(spacerItem13);

        transparency_box_ = new QFrame(volume_explorer_prefs_);
        transparency_box_->setObjectName(QString::fromUtf8("transparency_box_"));
        transparency_box_->setFrameShape(QFrame::StyledPanel);
        transparency_box_->setFrameShadow(QFrame::Raised);
        vboxLayout5 = new QVBoxLayout(transparency_box_);
        vboxLayout5->setSpacing(6);
        vboxLayout5->setMargin(11);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        vboxLayout5->setContentsMargins(0, 0, 0, 0);
        textLabel1 = new QLabel(transparency_box_);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setMinimumSize(QSize(200, 0));
        textLabel1->setLineWidth(1);
        textLabel1->setAlignment(Qt::AlignCenter);
        textLabel1->setWordWrap(false);

        vboxLayout5->addWidget(textLabel1);

        transparency_lineedit_ = new QLineEdit(transparency_box_);
        transparency_lineedit_->setObjectName(QString::fromUtf8("transparency_lineedit_"));

        vboxLayout5->addWidget(transparency_lineedit_);

        transparency_colormap_pix_ = new QFrame(transparency_box_);
        transparency_colormap_pix_->setObjectName(QString::fromUtf8("transparency_colormap_pix_"));
        sizePolicy5.setHeightForWidth(transparency_colormap_pix_->sizePolicy().hasHeightForWidth());
        transparency_colormap_pix_->setSizePolicy(sizePolicy5);
        transparency_colormap_pix_->setMinimumSize(QSize(200, 50));
        transparency_colormap_pix_->setFrameShape(QFrame::NoFrame);
        transparency_colormap_pix_->setFrameShadow(QFrame::Plain);
        transparency_colormap_pix_->setLineWidth(1);

        vboxLayout5->addWidget(transparency_colormap_pix_);

        hboxLayout12 = new QHBoxLayout();
        hboxLayout12->setSpacing(6);
        hboxLayout12->setObjectName(QString::fromUtf8("hboxLayout12"));
        hboxLayout12->setContentsMargins(0, 0, 0, 0);
        spacerItem14 = new QSpacerItem(20, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout12->addItem(spacerItem14);

        hide_volume_checkbox_ = new QCheckBox(transparency_box_);
        hide_volume_checkbox_->setObjectName(QString::fromUtf8("hide_volume_checkbox_"));

        hboxLayout12->addWidget(hide_volume_checkbox_);

        spacerItem15 = new QSpacerItem(20, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout12->addItem(spacerItem15);


        vboxLayout5->addLayout(hboxLayout12);


        hboxLayout11->addWidget(transparency_box_);

        spacerItem16 = new QSpacerItem(4, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout11->addItem(spacerItem16);


        vboxLayout4->addLayout(hboxLayout11);

        spacerItem17 = new QSpacerItem(41, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout4->addItem(spacerItem17);

        hboxLayout13 = new QHBoxLayout();
        hboxLayout13->setSpacing(6);
        hboxLayout13->setObjectName(QString::fromUtf8("hboxLayout13"));
        hboxLayout13->setContentsMargins(0, 0, 0, 0);
        spacerItem18 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout13->addItem(spacerItem18);

        add_slice_button_ = new QPushButton(volume_explorer_prefs_);
        add_slice_button_->setObjectName(QString::fromUtf8("add_slice_button_"));
        add_slice_button_->setFont(font1);

        hboxLayout13->addWidget(add_slice_button_);

        slice_axis_selector_ = new QComboBox(volume_explorer_prefs_);
        slice_axis_selector_->setObjectName(QString::fromUtf8("slice_axis_selector_"));
        sizePolicy4.setHeightForWidth(slice_axis_selector_->sizePolicy().hasHeightForWidth());
        slice_axis_selector_->setSizePolicy(sizePolicy4);
        slice_axis_selector_->setFont(font1);

        hboxLayout13->addWidget(slice_axis_selector_);

        spacerItem19 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout13->addItem(spacerItem19);


        vboxLayout4->addLayout(hboxLayout13);


        vboxLayout->addWidget(volume_explorer_prefs_);

        spacerItem20 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem20);


        retranslateUi(DisplayPrefPanelBase);

        QMetaObject::connectSlotsByName(DisplayPrefPanelBase);
    } // setupUi

    void retranslateUi(QWidget *DisplayPrefPanelBase)
    {
        DisplayPrefPanelBase->setWindowTitle(QApplication::translate("DisplayPrefPanelBase", "Display preferences", 0, QApplication::UnicodeUTF8));
        TextLabel1_3->setText(QApplication::translate("DisplayPrefPanelBase", "General", 0, QApplication::UnicodeUTF8));
        BBox_checkbox_->setText(QApplication::translate("DisplayPrefPanelBase", "Show Bounding Box", 0, QApplication::UnicodeUTF8));
        show_mesh_checkbox_->setText(QApplication::translate("DisplayPrefPanelBase", "Show Mesh", 0, QApplication::UnicodeUTF8));
        point_size_label_->setText(QApplication::translate("DisplayPrefPanelBase", "Point Size", 0, QApplication::UnicodeUTF8));
        TextLabel1_3_3->setText(QApplication::translate("DisplayPrefPanelBase", "Properties", 0, QApplication::UnicodeUTF8));
        prop_painted_checkbox_->setText(QApplication::translate("DisplayPrefPanelBase", "Painted", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("DisplayPrefPanelBase", "Property", 0, QApplication::UnicodeUTF8));
        TextLabel1_2->setText(QApplication::translate("DisplayPrefPanelBase", "Colormap", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("DisplayPrefPanelBase", "Min", 0, QApplication::UnicodeUTF8));
        TextLabel2_2->setText(QApplication::translate("DisplayPrefPanelBase", "Max", 0, QApplication::UnicodeUTF8));
        reset_cmap_bounds_button_->setText(QApplication::translate("DisplayPrefPanelBase", "Recompute Min/Max", 0, QApplication::UnicodeUTF8));
        slices_sep_label__2->setText(QApplication::translate("DisplayPrefPanelBase", "Volume Explorer", 0, QApplication::UnicodeUTF8));
        volume_explorer_checkbox_->setText(QApplication::translate("DisplayPrefPanelBase", "Use Volume Explorer", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("DisplayPrefPanelBase", "Transparent Ranges (eg. 2, 4 ; 5,10 )", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        transparency_lineedit_->setToolTip(QApplication::translate("DisplayPrefPanelBase", "enter list of ranges to be made transparent, eg: 2, 4 ; 7, 10", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        hide_volume_checkbox_->setText(QApplication::translate("DisplayPrefPanelBase", "Hide Volume", 0, QApplication::UnicodeUTF8));
        add_slice_button_->setText(QApplication::translate("DisplayPrefPanelBase", "Add", 0, QApplication::UnicodeUTF8));
        slice_axis_selector_->clear();
        slice_axis_selector_->insertItems(0, QStringList()
         << QApplication::translate("DisplayPrefPanelBase", "X slice", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DisplayPrefPanelBase", "Y slice", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DisplayPrefPanelBase", "Z slice", 0, QApplication::UnicodeUTF8)
        );
        Q_UNUSED(DisplayPrefPanelBase);
    } // retranslateUi

};

namespace Ui {
    class DisplayPrefPanelBase: public Ui_DisplayPrefPanelBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_PREF_PANEL_BASE_H
