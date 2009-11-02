/********************************************************************************
** Form generated from reading ui file 'gslib_pointset_import.ui'
**
** Created: Sun Nov 1 20:45:42 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GSLIB_POINTSET_IMPORT_H
#define UI_GSLIB_POINTSET_IMPORT_H

#include <Qt3Support/Q3MimeSourceFactory>
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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GslibPointsetImport
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel4_4;
    QLineEdit *name_;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabel1_2_2;
    QFrame *Line1_2_2;
    QLabel *TextLabel1_3;
    QGroupBox *GroupBox1;
    QVBoxLayout *vboxLayout1;
    QGridLayout *gridLayout;
    QLabel *TextLabel4;
    QSpinBox *Y_col_;
    QSpinBox *Z_col_;
    QLabel *TextLabel4_2;
    QSpinBox *X_col_;
    QLabel *TextLabel4_3;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QLabel *TextLabel1_2_2_2;
    QFrame *Line1_2_2_2;
    QTextBrowser *text_preview_;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout3;
    QLabel *TextLabel1_2_2_2_2;
    QFrame *Line1_2_2_2_2;
    QGroupBox *groupBox5;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout4;
    QSpacerItem *spacerItem3;
    QCheckBox *use_no_data_value_;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout5;
    QSpacerItem *spacerItem5;
    QGroupBox *NoDataValueBox;
    QHBoxLayout *hboxLayout6;
    QLabel *textLabel1;
    QLineEdit *no_data_value_edit_;
    QSpacerItem *spacerItem6;
    QSpacerItem *spacerItem7;

    void setupUi(QWidget *GslibPointsetImport)
    {
        if (GslibPointsetImport->objectName().isEmpty())
            GslibPointsetImport->setObjectName(QString::fromUtf8("GslibPointsetImport"));
        GslibPointsetImport->resize(331, 821);
        vboxLayout = new QVBoxLayout(GslibPointsetImport);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        TextLabel4_4 = new QLabel(GslibPointsetImport);
        TextLabel4_4->setObjectName(QString::fromUtf8("TextLabel4_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel4_4->sizePolicy().hasHeightForWidth());
        TextLabel4_4->setSizePolicy(sizePolicy);
        TextLabel4_4->setWordWrap(false);

        hboxLayout->addWidget(TextLabel4_4);

        name_ = new QLineEdit(GslibPointsetImport);
        name_->setObjectName(QString::fromUtf8("name_"));

        hboxLayout->addWidget(name_);


        vboxLayout->addLayout(hboxLayout);

        spacerItem = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        TextLabel1_2_2 = new QLabel(GslibPointsetImport);
        TextLabel1_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabel1_2_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2_2->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        TextLabel1_2_2->setFont(font);
        TextLabel1_2_2->setWordWrap(false);

        hboxLayout1->addWidget(TextLabel1_2_2);

        Line1_2_2 = new QFrame(GslibPointsetImport);
        Line1_2_2->setObjectName(QString::fromUtf8("Line1_2_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Line1_2_2->sizePolicy().hasHeightForWidth());
        Line1_2_2->setSizePolicy(sizePolicy2);
        Line1_2_2->setFrameShape(QFrame::HLine);
        Line1_2_2->setFrameShadow(QFrame::Sunken);
        Line1_2_2->setFrameShape(QFrame::HLine);

        hboxLayout1->addWidget(Line1_2_2);


        vboxLayout->addLayout(hboxLayout1);

        TextLabel1_3 = new QLabel(GslibPointsetImport);
        TextLabel1_3->setObjectName(QString::fromUtf8("TextLabel1_3"));
        TextLabel1_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TextLabel1_3->setWordWrap(true);

        vboxLayout->addWidget(TextLabel1_3);

        GroupBox1 = new QGroupBox(GslibPointsetImport);
        GroupBox1->setObjectName(QString::fromUtf8("GroupBox1"));
        GroupBox1->setMaximumSize(QSize(32767, 120));
        vboxLayout1 = new QVBoxLayout(GroupBox1);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TextLabel4 = new QLabel(GroupBox1);
        TextLabel4->setObjectName(QString::fromUtf8("TextLabel4"));
        sizePolicy.setHeightForWidth(TextLabel4->sizePolicy().hasHeightForWidth());
        TextLabel4->setSizePolicy(sizePolicy);
        TextLabel4->setWordWrap(false);

        gridLayout->addWidget(TextLabel4, 0, 0, 1, 1);

        Y_col_ = new QSpinBox(GroupBox1);
        Y_col_->setObjectName(QString::fromUtf8("Y_col_"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Y_col_->sizePolicy().hasHeightForWidth());
        Y_col_->setSizePolicy(sizePolicy3);
        Y_col_->setMaximumSize(QSize(80, 32767));
        Y_col_->setMinimum(1);
        Y_col_->setMaximum(1000000000);
        Y_col_->setValue(2);

        gridLayout->addWidget(Y_col_, 1, 1, 1, 1);

        Z_col_ = new QSpinBox(GroupBox1);
        Z_col_->setObjectName(QString::fromUtf8("Z_col_"));
        sizePolicy3.setHeightForWidth(Z_col_->sizePolicy().hasHeightForWidth());
        Z_col_->setSizePolicy(sizePolicy3);
        Z_col_->setMaximumSize(QSize(80, 32767));
        Z_col_->setMinimum(0);
        Z_col_->setMaximum(1000000000);
        Z_col_->setValue(0);

        gridLayout->addWidget(Z_col_, 2, 1, 1, 1);

        TextLabel4_2 = new QLabel(GroupBox1);
        TextLabel4_2->setObjectName(QString::fromUtf8("TextLabel4_2"));
        sizePolicy.setHeightForWidth(TextLabel4_2->sizePolicy().hasHeightForWidth());
        TextLabel4_2->setSizePolicy(sizePolicy);
        TextLabel4_2->setWordWrap(false);

        gridLayout->addWidget(TextLabel4_2, 1, 0, 1, 1);

        X_col_ = new QSpinBox(GroupBox1);
        X_col_->setObjectName(QString::fromUtf8("X_col_"));
        sizePolicy3.setHeightForWidth(X_col_->sizePolicy().hasHeightForWidth());
        X_col_->setSizePolicy(sizePolicy3);
        X_col_->setMaximumSize(QSize(80, 32767));
        X_col_->setMinimum(1);
        X_col_->setMaximum(100000000);

        gridLayout->addWidget(X_col_, 0, 1, 1, 1);

        TextLabel4_3 = new QLabel(GroupBox1);
        TextLabel4_3->setObjectName(QString::fromUtf8("TextLabel4_3"));
        sizePolicy.setHeightForWidth(TextLabel4_3->sizePolicy().hasHeightForWidth());
        TextLabel4_3->setSizePolicy(sizePolicy);
        TextLabel4_3->setWordWrap(false);

        gridLayout->addWidget(TextLabel4_3, 2, 0, 1, 1);


        vboxLayout1->addLayout(gridLayout);


        vboxLayout->addWidget(GroupBox1);

        spacerItem1 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        TextLabel1_2_2_2 = new QLabel(GslibPointsetImport);
        TextLabel1_2_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2_2"));
        sizePolicy1.setHeightForWidth(TextLabel1_2_2_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2_2_2->setSizePolicy(sizePolicy1);
        TextLabel1_2_2_2->setFont(font);
        TextLabel1_2_2_2->setWordWrap(false);

        hboxLayout2->addWidget(TextLabel1_2_2_2);

        Line1_2_2_2 = new QFrame(GslibPointsetImport);
        Line1_2_2_2->setObjectName(QString::fromUtf8("Line1_2_2_2"));
        sizePolicy2.setHeightForWidth(Line1_2_2_2->sizePolicy().hasHeightForWidth());
        Line1_2_2_2->setSizePolicy(sizePolicy2);
        Line1_2_2_2->setFrameShape(QFrame::HLine);
        Line1_2_2_2->setFrameShadow(QFrame::Sunken);
        Line1_2_2_2->setFrameShape(QFrame::HLine);

        hboxLayout2->addWidget(Line1_2_2_2);


        vboxLayout->addLayout(hboxLayout2);

        text_preview_ = new QTextBrowser(GslibPointsetImport);
        text_preview_->setObjectName(QString::fromUtf8("text_preview_"));

        vboxLayout->addWidget(text_preview_);

        spacerItem2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        TextLabel1_2_2_2_2 = new QLabel(GslibPointsetImport);
        TextLabel1_2_2_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2_2_2"));
        sizePolicy1.setHeightForWidth(TextLabel1_2_2_2_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2_2_2_2->setSizePolicy(sizePolicy1);
        TextLabel1_2_2_2_2->setFont(font);
        TextLabel1_2_2_2_2->setWordWrap(false);

        hboxLayout3->addWidget(TextLabel1_2_2_2_2);

        Line1_2_2_2_2 = new QFrame(GslibPointsetImport);
        Line1_2_2_2_2->setObjectName(QString::fromUtf8("Line1_2_2_2_2"));
        sizePolicy2.setHeightForWidth(Line1_2_2_2_2->sizePolicy().hasHeightForWidth());
        Line1_2_2_2_2->setSizePolicy(sizePolicy2);
        Line1_2_2_2_2->setFrameShape(QFrame::HLine);
        Line1_2_2_2_2->setFrameShadow(QFrame::Sunken);
        Line1_2_2_2_2->setFrameShape(QFrame::HLine);

        hboxLayout3->addWidget(Line1_2_2_2_2);


        vboxLayout->addLayout(hboxLayout3);

        groupBox5 = new QGroupBox(GslibPointsetImport);
        groupBox5->setObjectName(QString::fromUtf8("groupBox5"));
        vboxLayout2 = new QVBoxLayout(groupBox5);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setMargin(11);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        spacerItem3 = new QSpacerItem(31, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem3);

        use_no_data_value_ = new QCheckBox(groupBox5);
        use_no_data_value_->setObjectName(QString::fromUtf8("use_no_data_value_"));

        hboxLayout4->addWidget(use_no_data_value_);

        spacerItem4 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem4);


        vboxLayout2->addLayout(hboxLayout4);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        spacerItem5 = new QSpacerItem(22, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem5);

        NoDataValueBox = new QGroupBox(groupBox5);
        NoDataValueBox->setObjectName(QString::fromUtf8("NoDataValueBox"));
        NoDataValueBox->setEnabled(false);
        hboxLayout6 = new QHBoxLayout(NoDataValueBox);
        hboxLayout6->setSpacing(6);
        hboxLayout6->setMargin(11);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        textLabel1 = new QLabel(NoDataValueBox);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout6->addWidget(textLabel1);

        no_data_value_edit_ = new QLineEdit(NoDataValueBox);
        no_data_value_edit_->setObjectName(QString::fromUtf8("no_data_value_edit_"));

        hboxLayout6->addWidget(no_data_value_edit_);


        hboxLayout5->addWidget(NoDataValueBox);

        spacerItem6 = new QSpacerItem(22, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem6);


        vboxLayout2->addLayout(hboxLayout5);


        vboxLayout->addWidget(groupBox5);

        spacerItem7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        vboxLayout->addItem(spacerItem7);

        QWidget::setTabOrder(name_, X_col_);
        QWidget::setTabOrder(X_col_, Y_col_);
        QWidget::setTabOrder(Y_col_, Z_col_);
        QWidget::setTabOrder(Z_col_, use_no_data_value_);
        QWidget::setTabOrder(use_no_data_value_, no_data_value_edit_);

        retranslateUi(GslibPointsetImport);
        QObject::connect(use_no_data_value_, SIGNAL(toggled(bool)), NoDataValueBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(GslibPointsetImport);
    } // setupUi

    void retranslateUi(QWidget *GslibPointsetImport)
    {
        GslibPointsetImport->setWindowTitle(QApplication::translate("GslibPointsetImport", "Pointset Characteristics", 0, QApplication::UnicodeUTF8));
        TextLabel4_4->setText(QApplication::translate("GslibPointsetImport", "Pointset name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        name_->setToolTip(QApplication::translate("GslibPointsetImport", "name of new grid", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        TextLabel1_2_2->setText(QApplication::translate("GslibPointsetImport", "Points Coordinates", 0, QApplication::UnicodeUTF8));
        TextLabel1_3->setText(QApplication::translate("GslibPointsetImport", "Specify the columns containing the coordinates of the points", 0, QApplication::UnicodeUTF8));
        GroupBox1->setTitle(QString());
        TextLabel4->setText(QApplication::translate("GslibPointsetImport", "Col. # for X coordinates", 0, QApplication::UnicodeUTF8));
        Z_col_->setSpecialValueText(QApplication::translate("GslibPointsetImport", "NA (2d)", 0, QApplication::UnicodeUTF8));
        TextLabel4_2->setText(QApplication::translate("GslibPointsetImport", "Col. # for Y coordinates", 0, QApplication::UnicodeUTF8));
        TextLabel4_3->setText(QApplication::translate("GslibPointsetImport", "Col. # for Z coordinates", 0, QApplication::UnicodeUTF8));
        TextLabel1_2_2_2->setText(QApplication::translate("GslibPointsetImport", "File Preview", 0, QApplication::UnicodeUTF8));
        TextLabel1_2_2_2_2->setText(QApplication::translate("GslibPointsetImport", "No Data Value", 0, QApplication::UnicodeUTF8));
        groupBox5->setTitle(QString());
        use_no_data_value_->setText(QApplication::translate("GslibPointsetImport", "Use No-Data-Value", 0, QApplication::UnicodeUTF8));
        NoDataValueBox->setTitle(QString());
        textLabel1->setText(QApplication::translate("GslibPointsetImport", "No-Data-Value:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GslibPointsetImport);
    } // retranslateUi

};

namespace Ui {
    class GslibPointsetImport: public Ui_GslibPointsetImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GSLIB_POINTSET_IMPORT_H
