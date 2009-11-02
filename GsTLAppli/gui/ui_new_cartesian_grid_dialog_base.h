/********************************************************************************
** Form generated from reading ui file 'new_cartesian_grid_dialog_base.ui'
**
** Created: Sun Nov 1 20:46:31 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEW_CARTESIAN_GRID_DIALOG_BASE_H
#define UI_NEW_CARTESIAN_GRID_DIALOG_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewCartesianGridDialogBase
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel4_4;
    QLineEdit *name_;
    QSpacerItem *Spacer6;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabel1;
    QFrame *Line1;
    QGroupBox *GroupBox1;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *Spacer9;
    QGridLayout *gridLayout;
    QLabel *TextLabel4;
    QSpinBox *ny_;
    QSpinBox *nz_;
    QLabel *TextLabel4_2;
    QSpinBox *nx_;
    QLabel *TextLabel4_3;
    QSpacerItem *Spacer8;
    QSpacerItem *Spacer14_2;
    QHBoxLayout *hboxLayout3;
    QLabel *TextLabel1_2;
    QFrame *Line1_2;
    QLabel *TextLabel2_2;
    QGroupBox *GroupBox1_2;
    QHBoxLayout *hboxLayout4;
    QSpacerItem *Spacer9_2;
    QGridLayout *gridLayout1;
    QLineEdit *x_size_;
    QLineEdit *y_size_;
    QLineEdit *z_size_;
    QLabel *TextLabel4_5;
    QLabel *TextLabel4_2_2;
    QLabel *TextLabel4_3_2;
    QSpacerItem *Spacer8_2;
    QSpacerItem *Spacer14;
    QHBoxLayout *hboxLayout5;
    QLabel *TextLabel1_2_2;
    QFrame *Line1_2_2;
    QLabel *TextLabel2;
    QGroupBox *GroupBox1_2_2;
    QHBoxLayout *hboxLayout6;
    QHBoxLayout *hboxLayout7;
    QSpacerItem *Spacer10_2_2_2;
    QLabel *TextLabel4_5_2;
    QLineEdit *xmn_;
    QSpacerItem *Spacer10_2;
    QLabel *TextLabel4_5_2_2;
    QLineEdit *ymn_;
    QSpacerItem *Spacer10_2_2;
    QLabel *TextLabel4_5_2_2_2;
    QLineEdit *zmn_;
    QSpacerItem *Spacer13;
    QSpacerItem *Spacer25;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *Spacer26;
    QPushButton *ok_button_;
    QSpacerItem *Spacer27;
    QPushButton *cancel_button_;
    QSpacerItem *Spacer28;

    void setupUi(QDialog *NewCartesianGridDialogBase)
    {
        if (NewCartesianGridDialogBase->objectName().isEmpty())
            NewCartesianGridDialogBase->setObjectName(QString::fromUtf8("NewCartesianGridDialogBase"));
        NewCartesianGridDialogBase->resize(318, 548);
        vboxLayout = new QVBoxLayout(NewCartesianGridDialogBase);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        TextLabel4_4 = new QLabel(NewCartesianGridDialogBase);
        TextLabel4_4->setObjectName(QString::fromUtf8("TextLabel4_4"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel4_4->sizePolicy().hasHeightForWidth());
        TextLabel4_4->setSizePolicy(sizePolicy);
        TextLabel4_4->setWordWrap(false);

        hboxLayout->addWidget(TextLabel4_4);

        name_ = new QLineEdit(NewCartesianGridDialogBase);
        name_->setObjectName(QString::fromUtf8("name_"));

        hboxLayout->addWidget(name_);


        vboxLayout->addLayout(hboxLayout);

        Spacer6 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(Spacer6);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        TextLabel1 = new QLabel(NewCartesianGridDialogBase);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        TextLabel1->setFont(font);
        TextLabel1->setWordWrap(false);

        hboxLayout1->addWidget(TextLabel1);

        Line1 = new QFrame(NewCartesianGridDialogBase);
        Line1->setObjectName(QString::fromUtf8("Line1"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Line1->sizePolicy().hasHeightForWidth());
        Line1->setSizePolicy(sizePolicy2);
        Line1->setFrameShape(QFrame::HLine);
        Line1->setFrameShadow(QFrame::Sunken);

        hboxLayout1->addWidget(Line1);


        vboxLayout->addLayout(hboxLayout1);

        GroupBox1 = new QGroupBox(NewCartesianGridDialogBase);
        GroupBox1->setObjectName(QString::fromUtf8("GroupBox1"));
        GroupBox1->setMaximumSize(QSize(32767, 120));
        hboxLayout2 = new QHBoxLayout(GroupBox1);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(11);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        Spacer9 = new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(Spacer9);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TextLabel4 = new QLabel(GroupBox1);
        TextLabel4->setObjectName(QString::fromUtf8("TextLabel4"));
        sizePolicy.setHeightForWidth(TextLabel4->sizePolicy().hasHeightForWidth());
        TextLabel4->setSizePolicy(sizePolicy);
        TextLabel4->setWordWrap(false);

        gridLayout->addWidget(TextLabel4, 0, 0, 1, 1);

        ny_ = new QSpinBox(GroupBox1);
        ny_->setObjectName(QString::fromUtf8("ny_"));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(0));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ny_->sizePolicy().hasHeightForWidth());
        ny_->setSizePolicy(sizePolicy3);
        ny_->setMaximumSize(QSize(80, 32767));
        ny_->setMaximum(1000000000);
        ny_->setMinimum(1);

        gridLayout->addWidget(ny_, 1, 1, 1, 1);

        nz_ = new QSpinBox(GroupBox1);
        nz_->setObjectName(QString::fromUtf8("nz_"));
        sizePolicy3.setHeightForWidth(nz_->sizePolicy().hasHeightForWidth());
        nz_->setSizePolicy(sizePolicy3);
        nz_->setMaximumSize(QSize(80, 32767));
        nz_->setMaximum(1000000000);
        nz_->setMinimum(1);

        gridLayout->addWidget(nz_, 2, 1, 1, 1);

        TextLabel4_2 = new QLabel(GroupBox1);
        TextLabel4_2->setObjectName(QString::fromUtf8("TextLabel4_2"));
        sizePolicy.setHeightForWidth(TextLabel4_2->sizePolicy().hasHeightForWidth());
        TextLabel4_2->setSizePolicy(sizePolicy);
        TextLabel4_2->setWordWrap(false);

        gridLayout->addWidget(TextLabel4_2, 1, 0, 1, 1);

        nx_ = new QSpinBox(GroupBox1);
        nx_->setObjectName(QString::fromUtf8("nx_"));
        sizePolicy3.setHeightForWidth(nx_->sizePolicy().hasHeightForWidth());
        nx_->setSizePolicy(sizePolicy3);
        nx_->setMaximumSize(QSize(80, 32767));
        nx_->setMaximum(100000000);
        nx_->setMinimum(1);

        gridLayout->addWidget(nx_, 0, 1, 1, 1);

        TextLabel4_3 = new QLabel(GroupBox1);
        TextLabel4_3->setObjectName(QString::fromUtf8("TextLabel4_3"));
        sizePolicy.setHeightForWidth(TextLabel4_3->sizePolicy().hasHeightForWidth());
        TextLabel4_3->setSizePolicy(sizePolicy);
        TextLabel4_3->setWordWrap(false);

        gridLayout->addWidget(TextLabel4_3, 2, 0, 1, 1);


        hboxLayout2->addLayout(gridLayout);

        Spacer8 = new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(Spacer8);


        vboxLayout->addWidget(GroupBox1);

        Spacer14_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(Spacer14_2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setMargin(0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        TextLabel1_2 = new QLabel(NewCartesianGridDialogBase);
        TextLabel1_2->setObjectName(QString::fromUtf8("TextLabel1_2"));
        sizePolicy1.setHeightForWidth(TextLabel1_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2->setSizePolicy(sizePolicy1);
        TextLabel1_2->setFont(font);
        TextLabel1_2->setWordWrap(false);

        hboxLayout3->addWidget(TextLabel1_2);

        Line1_2 = new QFrame(NewCartesianGridDialogBase);
        Line1_2->setObjectName(QString::fromUtf8("Line1_2"));
        sizePolicy2.setHeightForWidth(Line1_2->sizePolicy().hasHeightForWidth());
        Line1_2->setSizePolicy(sizePolicy2);
        Line1_2->setFrameShape(QFrame::HLine);
        Line1_2->setFrameShadow(QFrame::Sunken);

        hboxLayout3->addWidget(Line1_2);


        vboxLayout->addLayout(hboxLayout3);

        TextLabel2_2 = new QLabel(NewCartesianGridDialogBase);
        TextLabel2_2->setObjectName(QString::fromUtf8("TextLabel2_2"));
        TextLabel2_2->setWordWrap(false);

        vboxLayout->addWidget(TextLabel2_2);

        GroupBox1_2 = new QGroupBox(NewCartesianGridDialogBase);
        GroupBox1_2->setObjectName(QString::fromUtf8("GroupBox1_2"));
        GroupBox1_2->setMaximumSize(QSize(32767, 120));
        hboxLayout4 = new QHBoxLayout(GroupBox1_2);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setMargin(11);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        Spacer9_2 = new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(Spacer9_2);

        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        x_size_ = new QLineEdit(GroupBox1_2);
        x_size_->setObjectName(QString::fromUtf8("x_size_"));
        x_size_->setAlignment(Qt::AlignRight);

        gridLayout1->addWidget(x_size_, 0, 1, 1, 1);

        y_size_ = new QLineEdit(GroupBox1_2);
        y_size_->setObjectName(QString::fromUtf8("y_size_"));
        y_size_->setAlignment(Qt::AlignRight);

        gridLayout1->addWidget(y_size_, 1, 1, 1, 1);

        z_size_ = new QLineEdit(GroupBox1_2);
        z_size_->setObjectName(QString::fromUtf8("z_size_"));
        z_size_->setAlignment(Qt::AlignRight);

        gridLayout1->addWidget(z_size_, 2, 1, 1, 1);

        TextLabel4_5 = new QLabel(GroupBox1_2);
        TextLabel4_5->setObjectName(QString::fromUtf8("TextLabel4_5"));
        sizePolicy.setHeightForWidth(TextLabel4_5->sizePolicy().hasHeightForWidth());
        TextLabel4_5->setSizePolicy(sizePolicy);
        TextLabel4_5->setWordWrap(false);

        gridLayout1->addWidget(TextLabel4_5, 0, 0, 1, 1);

        TextLabel4_2_2 = new QLabel(GroupBox1_2);
        TextLabel4_2_2->setObjectName(QString::fromUtf8("TextLabel4_2_2"));
        sizePolicy.setHeightForWidth(TextLabel4_2_2->sizePolicy().hasHeightForWidth());
        TextLabel4_2_2->setSizePolicy(sizePolicy);
        TextLabel4_2_2->setWordWrap(false);

        gridLayout1->addWidget(TextLabel4_2_2, 1, 0, 1, 1);

        TextLabel4_3_2 = new QLabel(GroupBox1_2);
        TextLabel4_3_2->setObjectName(QString::fromUtf8("TextLabel4_3_2"));
        sizePolicy.setHeightForWidth(TextLabel4_3_2->sizePolicy().hasHeightForWidth());
        TextLabel4_3_2->setSizePolicy(sizePolicy);
        TextLabel4_3_2->setWordWrap(false);

        gridLayout1->addWidget(TextLabel4_3_2, 2, 0, 1, 1);


        hboxLayout4->addLayout(gridLayout1);

        Spacer8_2 = new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(Spacer8_2);


        vboxLayout->addWidget(GroupBox1_2);

        Spacer14 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(Spacer14);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setMargin(0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        TextLabel1_2_2 = new QLabel(NewCartesianGridDialogBase);
        TextLabel1_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2"));
        sizePolicy1.setHeightForWidth(TextLabel1_2_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2_2->setSizePolicy(sizePolicy1);
        TextLabel1_2_2->setFont(font);
        TextLabel1_2_2->setWordWrap(false);

        hboxLayout5->addWidget(TextLabel1_2_2);

        Line1_2_2 = new QFrame(NewCartesianGridDialogBase);
        Line1_2_2->setObjectName(QString::fromUtf8("Line1_2_2"));
        sizePolicy2.setHeightForWidth(Line1_2_2->sizePolicy().hasHeightForWidth());
        Line1_2_2->setSizePolicy(sizePolicy2);
        Line1_2_2->setFrameShape(QFrame::HLine);
        Line1_2_2->setFrameShadow(QFrame::Sunken);

        hboxLayout5->addWidget(Line1_2_2);


        vboxLayout->addLayout(hboxLayout5);

        TextLabel2 = new QLabel(NewCartesianGridDialogBase);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        TextLabel2->setWordWrap(false);

        vboxLayout->addWidget(TextLabel2);

        GroupBox1_2_2 = new QGroupBox(NewCartesianGridDialogBase);
        GroupBox1_2_2->setObjectName(QString::fromUtf8("GroupBox1_2_2"));
        GroupBox1_2_2->setMaximumSize(QSize(32767, 120));
        hboxLayout6 = new QHBoxLayout(GroupBox1_2_2);
        hboxLayout6->setSpacing(6);
        hboxLayout6->setMargin(11);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setMargin(0);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        Spacer10_2_2_2 = new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(Spacer10_2_2_2);

        TextLabel4_5_2 = new QLabel(GroupBox1_2_2);
        TextLabel4_5_2->setObjectName(QString::fromUtf8("TextLabel4_5_2"));
        sizePolicy.setHeightForWidth(TextLabel4_5_2->sizePolicy().hasHeightForWidth());
        TextLabel4_5_2->setSizePolicy(sizePolicy);
        TextLabel4_5_2->setWordWrap(false);

        hboxLayout7->addWidget(TextLabel4_5_2);

        xmn_ = new QLineEdit(GroupBox1_2_2);
        xmn_->setObjectName(QString::fromUtf8("xmn_"));
        xmn_->setAlignment(Qt::AlignRight);

        hboxLayout7->addWidget(xmn_);

        Spacer10_2 = new QSpacerItem(16, 21, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout7->addItem(Spacer10_2);

        TextLabel4_5_2_2 = new QLabel(GroupBox1_2_2);
        TextLabel4_5_2_2->setObjectName(QString::fromUtf8("TextLabel4_5_2_2"));
        sizePolicy.setHeightForWidth(TextLabel4_5_2_2->sizePolicy().hasHeightForWidth());
        TextLabel4_5_2_2->setSizePolicy(sizePolicy);
        TextLabel4_5_2_2->setWordWrap(false);

        hboxLayout7->addWidget(TextLabel4_5_2_2);

        ymn_ = new QLineEdit(GroupBox1_2_2);
        ymn_->setObjectName(QString::fromUtf8("ymn_"));
        ymn_->setAlignment(Qt::AlignRight);

        hboxLayout7->addWidget(ymn_);

        Spacer10_2_2 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout7->addItem(Spacer10_2_2);

        TextLabel4_5_2_2_2 = new QLabel(GroupBox1_2_2);
        TextLabel4_5_2_2_2->setObjectName(QString::fromUtf8("TextLabel4_5_2_2_2"));
        sizePolicy.setHeightForWidth(TextLabel4_5_2_2_2->sizePolicy().hasHeightForWidth());
        TextLabel4_5_2_2_2->setSizePolicy(sizePolicy);
        TextLabel4_5_2_2_2->setWordWrap(false);

        hboxLayout7->addWidget(TextLabel4_5_2_2_2);

        zmn_ = new QLineEdit(GroupBox1_2_2);
        zmn_->setObjectName(QString::fromUtf8("zmn_"));
        zmn_->setAlignment(Qt::AlignRight);

        hboxLayout7->addWidget(zmn_);

        Spacer13 = new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(Spacer13);


        hboxLayout6->addLayout(hboxLayout7);


        vboxLayout->addWidget(GroupBox1_2_2);

        Spacer25 = new QSpacerItem(0, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(Spacer25);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setSpacing(6);
        hboxLayout8->setMargin(0);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        Spacer26 = new QSpacerItem(31, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(Spacer26);

        ok_button_ = new QPushButton(NewCartesianGridDialogBase);
        ok_button_->setObjectName(QString::fromUtf8("ok_button_"));

        hboxLayout8->addWidget(ok_button_);

        Spacer27 = new QSpacerItem(21, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(Spacer27);

        cancel_button_ = new QPushButton(NewCartesianGridDialogBase);
        cancel_button_->setObjectName(QString::fromUtf8("cancel_button_"));

        hboxLayout8->addWidget(cancel_button_);

        Spacer28 = new QSpacerItem(41, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(Spacer28);


        vboxLayout->addLayout(hboxLayout8);

        QWidget::setTabOrder(name_, nx_);
        QWidget::setTabOrder(nx_, ny_);
        QWidget::setTabOrder(ny_, nz_);
        QWidget::setTabOrder(nz_, x_size_);
        QWidget::setTabOrder(x_size_, y_size_);
        QWidget::setTabOrder(y_size_, z_size_);
        QWidget::setTabOrder(z_size_, xmn_);
        QWidget::setTabOrder(xmn_, ymn_);
        QWidget::setTabOrder(ymn_, zmn_);
        QWidget::setTabOrder(zmn_, ok_button_);
        QWidget::setTabOrder(ok_button_, cancel_button_);

        retranslateUi(NewCartesianGridDialogBase);

        QMetaObject::connectSlotsByName(NewCartesianGridDialogBase);
    } // setupUi

    void retranslateUi(QDialog *NewCartesianGridDialogBase)
    {
        NewCartesianGridDialogBase->setWindowTitle(QApplication::translate("NewCartesianGridDialogBase", "Form1", 0, QApplication::UnicodeUTF8));
        TextLabel4_4->setText(QApplication::translate("NewCartesianGridDialogBase", "Grid name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        name_->setProperty("toolTip", QVariant(QApplication::translate("NewCartesianGridDialogBase", "name of new grid", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
        TextLabel1->setText(QApplication::translate("NewCartesianGridDialogBase", "Grid Dimensions", 0, QApplication::UnicodeUTF8));
        GroupBox1->setTitle(QString());
        TextLabel4->setText(QApplication::translate("NewCartesianGridDialogBase", "Number of cells in X", 0, QApplication::UnicodeUTF8));
        TextLabel4_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Number of cells in Y", 0, QApplication::UnicodeUTF8));
        TextLabel4_3->setText(QApplication::translate("NewCartesianGridDialogBase", "Number of cells in Z", 0, QApplication::UnicodeUTF8));
        TextLabel1_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Cell Size", 0, QApplication::UnicodeUTF8));
        TextLabel2_2->setText(QApplication::translate("NewCartesianGridDialogBase", "The dimensions of a single cell", 0, QApplication::UnicodeUTF8));
        GroupBox1_2->setTitle(QString());
        x_size_->setText(QApplication::translate("NewCartesianGridDialogBase", "1.0", 0, QApplication::UnicodeUTF8));
        y_size_->setText(QApplication::translate("NewCartesianGridDialogBase", "1.0", 0, QApplication::UnicodeUTF8));
        z_size_->setText(QApplication::translate("NewCartesianGridDialogBase", "1.0", 0, QApplication::UnicodeUTF8));
        TextLabel4_5->setText(QApplication::translate("NewCartesianGridDialogBase", "Size in X", 0, QApplication::UnicodeUTF8));
        TextLabel4_2_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Size in Y", 0, QApplication::UnicodeUTF8));
        TextLabel4_3_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Size in Z", 0, QApplication::UnicodeUTF8));
        TextLabel1_2_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Origin Coordinates", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("NewCartesianGridDialogBase", "The coordinates of the lower left corner of the grid", 0, QApplication::UnicodeUTF8));
        GroupBox1_2_2->setTitle(QString());
        TextLabel4_5_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Ox", 0, QApplication::UnicodeUTF8));
        xmn_->setText(QApplication::translate("NewCartesianGridDialogBase", "0", 0, QApplication::UnicodeUTF8));
        TextLabel4_5_2_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Oy", 0, QApplication::UnicodeUTF8));
        ymn_->setText(QApplication::translate("NewCartesianGridDialogBase", "0", 0, QApplication::UnicodeUTF8));
        TextLabel4_5_2_2_2->setText(QApplication::translate("NewCartesianGridDialogBase", "Oz", 0, QApplication::UnicodeUTF8));
        zmn_->setText(QApplication::translate("NewCartesianGridDialogBase", "0", 0, QApplication::UnicodeUTF8));
        ok_button_->setText(QApplication::translate("NewCartesianGridDialogBase", "Create Grid", 0, QApplication::UnicodeUTF8));
        cancel_button_->setText(QApplication::translate("NewCartesianGridDialogBase", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NewCartesianGridDialogBase);
    } // retranslateUi

};

namespace Ui {
    class NewCartesianGridDialogBase: public Ui_NewCartesianGridDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_CARTESIAN_GRID_DIALOG_BASE_H
