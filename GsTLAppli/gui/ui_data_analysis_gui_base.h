/********************************************************************************
** Form generated from reading ui file 'data_analysis_gui_base.ui'
**
** Created: Sun Nov 1 20:46:24 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DATA_ANALYSIS_GUI_BASE_H
#define UI_DATA_ANALYSIS_GUI_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Data_analysis_gui_base
{
public:
    QVBoxLayout *vboxLayout;
    QSplitter *splitter;
    QTabWidget *controls_tabwidget_;
    QWidget *tab;
    QVBoxLayout *vboxLayout1;
    QFrame *controls_box_;
    QWidget *tab1;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1_5;
    QFrame *line3_4;
    QSpacerItem *spacerItem;
    QGroupBox *xaxis_options_;
    QVBoxLayout *vboxLayout3;
    QGridLayout *gridLayout;
    QLabel *textLabel3_4;
    QLabel *textLabel3_2_3;
    QLineEdit *minx_edit_;
    QLineEdit *maxx_edit_;
    QPushButton *reset_axis_x_button_;
    QCheckBox *x_logscale_checkbox_;
    QSpacerItem *spacerItem1;
    QGroupBox *yaxis_options_;
    QVBoxLayout *vboxLayout4;
    QGridLayout *gridLayout1;
    QLineEdit *miny_edit_;
    QLineEdit *maxy_edit_;
    QLabel *textLabel3_2_4;
    QLabel *textLabel3_5;
    QPushButton *reset_axis_y_button_;
    QCheckBox *y_logscale_checkbox_;
    QSpacerItem *spacerItem2;
    QGroupBox *display_box_;
    QHBoxLayout *hboxLayout1;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem3;
    QPushButton *save_button_;
    QSpacerItem *spacerItem4;
    QPushButton *close_button_;
    QSpacerItem *spacerItem5;
    QGroupBox *gripbox_;

    void setupUi(QWidget *Data_analysis_gui_base)
    {
        if (Data_analysis_gui_base->objectName().isEmpty())
            Data_analysis_gui_base->setObjectName(QString::fromUtf8("Data_analysis_gui_base"));
        Data_analysis_gui_base->resize(678, 643);
        vboxLayout = new QVBoxLayout(Data_analysis_gui_base);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        splitter = new QSplitter(Data_analysis_gui_base);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        controls_tabwidget_ = new QTabWidget(splitter);
        controls_tabwidget_->setObjectName(QString::fromUtf8("controls_tabwidget_"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(controls_tabwidget_->sizePolicy().hasHeightForWidth());
        controls_tabwidget_->setSizePolicy(sizePolicy);
        controls_tabwidget_->setBaseSize(QSize(250, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        vboxLayout1 = new QVBoxLayout(tab);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        controls_box_ = new QFrame(tab);
        controls_box_->setObjectName(QString::fromUtf8("controls_box_"));
        controls_box_->setFrameShape(QFrame::StyledPanel);
        controls_box_->setFrameShadow(QFrame::Raised);

        vboxLayout1->addWidget(controls_box_);

        controls_tabwidget_->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        vboxLayout2 = new QVBoxLayout(tab1);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setMargin(11);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1_5 = new QLabel(tab1);
        textLabel1_5->setObjectName(QString::fromUtf8("textLabel1_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textLabel1_5->sizePolicy().hasHeightForWidth());
        textLabel1_5->setSizePolicy(sizePolicy1);
        textLabel1_5->setMaximumSize(QSize(122, 32767));
        textLabel1_5->setTextFormat(Qt::AutoText);
        textLabel1_5->setAlignment(Qt::AlignVCenter);
        textLabel1_5->setWordWrap(false);

        hboxLayout->addWidget(textLabel1_5);

        line3_4 = new QFrame(tab1);
        line3_4->setObjectName(QString::fromUtf8("line3_4"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line3_4->sizePolicy().hasHeightForWidth());
        line3_4->setSizePolicy(sizePolicy2);
        line3_4->setFrameShape(QFrame::HLine);
        line3_4->setFrameShadow(QFrame::Sunken);
        line3_4->setFrameShape(QFrame::HLine);

        hboxLayout->addWidget(line3_4);


        vboxLayout2->addLayout(hboxLayout);

        spacerItem = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacerItem);

        xaxis_options_ = new QGroupBox(tab1);
        xaxis_options_->setObjectName(QString::fromUtf8("xaxis_options_"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(xaxis_options_->sizePolicy().hasHeightForWidth());
        xaxis_options_->setSizePolicy(sizePolicy3);
        xaxis_options_->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        xaxis_options_->setFlat(false);
        vboxLayout3 = new QVBoxLayout(xaxis_options_);
        vboxLayout3->setSpacing(6);
        vboxLayout3->setMargin(11);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textLabel3_4 = new QLabel(xaxis_options_);
        textLabel3_4->setObjectName(QString::fromUtf8("textLabel3_4"));
        sizePolicy3.setHeightForWidth(textLabel3_4->sizePolicy().hasHeightForWidth());
        textLabel3_4->setSizePolicy(sizePolicy3);
        textLabel3_4->setAlignment(Qt::AlignCenter);
        textLabel3_4->setWordWrap(false);

        gridLayout->addWidget(textLabel3_4, 0, 0, 1, 1);

        textLabel3_2_3 = new QLabel(xaxis_options_);
        textLabel3_2_3->setObjectName(QString::fromUtf8("textLabel3_2_3"));
        sizePolicy3.setHeightForWidth(textLabel3_2_3->sizePolicy().hasHeightForWidth());
        textLabel3_2_3->setSizePolicy(sizePolicy3);
        textLabel3_2_3->setAlignment(Qt::AlignCenter);
        textLabel3_2_3->setWordWrap(false);

        gridLayout->addWidget(textLabel3_2_3, 0, 1, 1, 1);

        minx_edit_ = new QLineEdit(xaxis_options_);
        minx_edit_->setObjectName(QString::fromUtf8("minx_edit_"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(minx_edit_->sizePolicy().hasHeightForWidth());
        minx_edit_->setSizePolicy(sizePolicy4);
        minx_edit_->setMaximumSize(QSize(500, 16777215));
        minx_edit_->setBaseSize(QSize(70, 0));

        gridLayout->addWidget(minx_edit_, 1, 0, 1, 1);

        maxx_edit_ = new QLineEdit(xaxis_options_);
        maxx_edit_->setObjectName(QString::fromUtf8("maxx_edit_"));
        sizePolicy4.setHeightForWidth(maxx_edit_->sizePolicy().hasHeightForWidth());
        maxx_edit_->setSizePolicy(sizePolicy4);
        maxx_edit_->setMaximumSize(QSize(500, 16777215));
        maxx_edit_->setBaseSize(QSize(70, 0));

        gridLayout->addWidget(maxx_edit_, 1, 1, 1, 1);


        vboxLayout3->addLayout(gridLayout);

        reset_axis_x_button_ = new QPushButton(xaxis_options_);
        reset_axis_x_button_->setObjectName(QString::fromUtf8("reset_axis_x_button_"));

        vboxLayout3->addWidget(reset_axis_x_button_);

        x_logscale_checkbox_ = new QCheckBox(xaxis_options_);
        x_logscale_checkbox_->setObjectName(QString::fromUtf8("x_logscale_checkbox_"));

        vboxLayout3->addWidget(x_logscale_checkbox_);


        vboxLayout2->addWidget(xaxis_options_);

        spacerItem1 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacerItem1);

        yaxis_options_ = new QGroupBox(tab1);
        yaxis_options_->setObjectName(QString::fromUtf8("yaxis_options_"));
        sizePolicy3.setHeightForWidth(yaxis_options_->sizePolicy().hasHeightForWidth());
        yaxis_options_->setSizePolicy(sizePolicy3);
        yaxis_options_->setAlignment(Qt::AlignHCenter);
        yaxis_options_->setFlat(false);
        vboxLayout4 = new QVBoxLayout(yaxis_options_);
        vboxLayout4->setSpacing(6);
        vboxLayout4->setMargin(11);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        miny_edit_ = new QLineEdit(yaxis_options_);
        miny_edit_->setObjectName(QString::fromUtf8("miny_edit_"));
        sizePolicy4.setHeightForWidth(miny_edit_->sizePolicy().hasHeightForWidth());
        miny_edit_->setSizePolicy(sizePolicy4);
        miny_edit_->setMaximumSize(QSize(500, 16777215));

        gridLayout1->addWidget(miny_edit_, 1, 0, 1, 1);

        maxy_edit_ = new QLineEdit(yaxis_options_);
        maxy_edit_->setObjectName(QString::fromUtf8("maxy_edit_"));
        sizePolicy4.setHeightForWidth(maxy_edit_->sizePolicy().hasHeightForWidth());
        maxy_edit_->setSizePolicy(sizePolicy4);
        maxy_edit_->setMaximumSize(QSize(500, 16777215));

        gridLayout1->addWidget(maxy_edit_, 1, 1, 1, 1);

        textLabel3_2_4 = new QLabel(yaxis_options_);
        textLabel3_2_4->setObjectName(QString::fromUtf8("textLabel3_2_4"));
        textLabel3_2_4->setAlignment(Qt::AlignCenter);
        textLabel3_2_4->setWordWrap(false);

        gridLayout1->addWidget(textLabel3_2_4, 0, 1, 1, 1);

        textLabel3_5 = new QLabel(yaxis_options_);
        textLabel3_5->setObjectName(QString::fromUtf8("textLabel3_5"));
        textLabel3_5->setAlignment(Qt::AlignCenter);
        textLabel3_5->setWordWrap(false);

        gridLayout1->addWidget(textLabel3_5, 0, 0, 1, 1);


        vboxLayout4->addLayout(gridLayout1);

        reset_axis_y_button_ = new QPushButton(yaxis_options_);
        reset_axis_y_button_->setObjectName(QString::fromUtf8("reset_axis_y_button_"));

        vboxLayout4->addWidget(reset_axis_y_button_);

        y_logscale_checkbox_ = new QCheckBox(yaxis_options_);
        y_logscale_checkbox_->setObjectName(QString::fromUtf8("y_logscale_checkbox_"));

        vboxLayout4->addWidget(y_logscale_checkbox_);


        vboxLayout2->addWidget(yaxis_options_);

        spacerItem2 = new QSpacerItem(276, 191, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem2);

        controls_tabwidget_->addTab(tab1, QString());
        splitter->addWidget(controls_tabwidget_);
        display_box_ = new QGroupBox(splitter);
        display_box_->setObjectName(QString::fromUtf8("display_box_"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(50);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(display_box_->sizePolicy().hasHeightForWidth());
        display_box_->setSizePolicy(sizePolicy5);
        splitter->addWidget(display_box_);

        vboxLayout->addWidget(splitter);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(0);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(4);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacerItem3 = new QSpacerItem(330, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem3);

        save_button_ = new QPushButton(Data_analysis_gui_base);
        save_button_->setObjectName(QString::fromUtf8("save_button_"));
        save_button_->setFlat(false);

        hboxLayout2->addWidget(save_button_);

        spacerItem4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem4);

        close_button_ = new QPushButton(Data_analysis_gui_base);
        close_button_->setObjectName(QString::fromUtf8("close_button_"));
        close_button_->setFlat(false);

        hboxLayout2->addWidget(close_button_);

        spacerItem5 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem5);


        hboxLayout1->addLayout(hboxLayout2);

        gripbox_ = new QGroupBox(Data_analysis_gui_base);
        gripbox_->setObjectName(QString::fromUtf8("gripbox_"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(gripbox_->sizePolicy().hasHeightForWidth());
        gripbox_->setSizePolicy(sizePolicy6);
        gripbox_->setMaximumSize(QSize(30, 30));

        hboxLayout1->addWidget(gripbox_);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(Data_analysis_gui_base);

        controls_tabwidget_->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Data_analysis_gui_base);
    } // setupUi

    void retranslateUi(QWidget *Data_analysis_gui_base)
    {
        Data_analysis_gui_base->setWindowTitle(QApplication::translate("Data_analysis_gui_base", "Data Analysis", 0, QApplication::UnicodeUTF8));
        controls_tabwidget_->setTabText(controls_tabwidget_->indexOf(tab), QApplication::translate("Data_analysis_gui_base", "Data", 0, QApplication::UnicodeUTF8));
        textLabel1_5->setText(QApplication::translate("Data_analysis_gui_base", "<b>Axis options</b>", 0, QApplication::UnicodeUTF8));
        xaxis_options_->setTitle(QApplication::translate("Data_analysis_gui_base", "X Axis", 0, QApplication::UnicodeUTF8));
        textLabel3_4->setText(QApplication::translate("Data_analysis_gui_base", "Min", 0, QApplication::UnicodeUTF8));
        textLabel3_2_3->setText(QApplication::translate("Data_analysis_gui_base", "Max", 0, QApplication::UnicodeUTF8));
        reset_axis_x_button_->setText(QApplication::translate("Data_analysis_gui_base", "Reset", 0, QApplication::UnicodeUTF8));
        x_logscale_checkbox_->setText(QApplication::translate("Data_analysis_gui_base", "Logarithmic scale", 0, QApplication::UnicodeUTF8));
        yaxis_options_->setTitle(QApplication::translate("Data_analysis_gui_base", "Y Axis", 0, QApplication::UnicodeUTF8));
        textLabel3_2_4->setText(QApplication::translate("Data_analysis_gui_base", "Max", 0, QApplication::UnicodeUTF8));
        textLabel3_5->setText(QApplication::translate("Data_analysis_gui_base", "Min", 0, QApplication::UnicodeUTF8));
        reset_axis_y_button_->setText(QApplication::translate("Data_analysis_gui_base", "Reset", 0, QApplication::UnicodeUTF8));
        y_logscale_checkbox_->setText(QApplication::translate("Data_analysis_gui_base", "Logarithmic scale", 0, QApplication::UnicodeUTF8));
        controls_tabwidget_->setTabText(controls_tabwidget_->indexOf(tab1), QApplication::translate("Data_analysis_gui_base", "Display Options", 0, QApplication::UnicodeUTF8));
        display_box_->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        save_button_->setToolTip(QApplication::translate("Data_analysis_gui_base", "save an image of the current histogram", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        save_button_->setText(QApplication::translate("Data_analysis_gui_base", "&Save as Image", 0, QApplication::UnicodeUTF8));
        save_button_->setShortcut(QApplication::translate("Data_analysis_gui_base", "Alt+S", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        close_button_->setToolTip(QApplication::translate("Data_analysis_gui_base", "close this window", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        close_button_->setText(QApplication::translate("Data_analysis_gui_base", "&Close", 0, QApplication::UnicodeUTF8));
        gripbox_->setTitle(QString());
        Q_UNUSED(Data_analysis_gui_base);
    } // retranslateUi

};

namespace Ui {
    class Data_analysis_gui_base: public Ui_Data_analysis_gui_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_ANALYSIS_GUI_BASE_H
