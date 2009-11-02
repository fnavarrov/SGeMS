/********************************************************************************
** Form generated from reading ui file 'gslibgridimport.ui'
**
** Created: Sun Nov 1 20:45:42 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GSLIBGRIDIMPORT_H
#define UI_GSLIBGRIDIMPORT_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GslibGridImport
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GroupBox1;
    QHBoxLayout *hboxLayout;
    QSpacerItem *Spacer9;
    QGridLayout *gridLayout1;
    QLabel *TextLabel4;
    QSpinBox *ny_;
    QSpinBox *nz_;
    QLabel *TextLabel4_2;
    QSpinBox *nx_;
    QLabel *TextLabel4_3;
    QSpacerItem *Spacer8;
    QSpacerItem *Spacer14_2;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabel1_2;
    QFrame *Line1_2;
    QGroupBox *groupBox5;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacer24;
    QCheckBox *use_no_data_value_;
    QSpacerItem *spacer25;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacer23;
    QGroupBox *NoDataValueBox;
    QHBoxLayout *hboxLayout4;
    QLabel *textLabel1;
    QLineEdit *no_data_value_edit_;
    QSpacerItem *spacer22;
    QHBoxLayout *hboxLayout5;
    QLabel *TextLabel1;
    QFrame *Line1;
    QHBoxLayout *hboxLayout6;
    QLabel *TextLabel4_4;
    QLineEdit *name_;
    QSpacerItem *Spacer6;
    QHBoxLayout *hboxLayout7;
    QLabel *TextLabel1_2_2_2_2;
    QFrame *Line1_2_2_2_2;
    QLabel *TextLabel2_2;
    QGroupBox *GroupBox1_2;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *Spacer9_2;
    QGridLayout *gridLayout2;
    QLineEdit *x_size_;
    QLineEdit *y_size_;
    QLineEdit *z_size_;
    QLabel *TextLabel4_5;
    QLabel *TextLabel4_2_2;
    QLabel *TextLabel4_3_2;
    QSpacerItem *Spacer8_2;
    QHBoxLayout *hboxLayout9;
    QLabel *TextLabel1_2_2;
    QFrame *Line1_2_2;
    QSpacerItem *Spacer14;
    QGroupBox *GroupBox1_2_2;
    QGridLayout *gridLayout3;
    QLineEdit *xmn_;
    QSpacerItem *Spacer10_2;
    QLabel *TextLabel4_5_2_2;
    QLineEdit *ymn_;
    QLabel *TextLabel4_5_2_2_2;
    QLineEdit *zmn_;
    QSpacerItem *Spacer10_2_2;
    QLabel *TextLabel4_5_2;
    QLabel *TextLabel2;

    void setupUi(QWidget *GslibGridImport)
    {
        if (GslibGridImport->objectName().isEmpty())
            GslibGridImport->setObjectName(QString::fromUtf8("GslibGridImport"));
        GslibGridImport->resize(338, 791);
        gridLayout = new QGridLayout(GslibGridImport);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GroupBox1 = new QGroupBox(GslibGridImport);
        GroupBox1->setObjectName(QString::fromUtf8("GroupBox1"));
        GroupBox1->setMaximumSize(QSize(32767, 120));
        hboxLayout = new QHBoxLayout(GroupBox1);
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Spacer9 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Spacer9);

        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        TextLabel4 = new QLabel(GroupBox1);
        TextLabel4->setObjectName(QString::fromUtf8("TextLabel4"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel4->sizePolicy().hasHeightForWidth());
        TextLabel4->setSizePolicy(sizePolicy);
        TextLabel4->setWordWrap(false);

        gridLayout1->addWidget(TextLabel4, 0, 0, 1, 1);

        ny_ = new QSpinBox(GroupBox1);
        ny_->setObjectName(QString::fromUtf8("ny_"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ny_->sizePolicy().hasHeightForWidth());
        ny_->setSizePolicy(sizePolicy1);
        ny_->setMaximumSize(QSize(80, 32767));
        ny_->setMaximum(1000000000);
        ny_->setMinimum(1);

        gridLayout1->addWidget(ny_, 1, 1, 1, 1);

        nz_ = new QSpinBox(GroupBox1);
        nz_->setObjectName(QString::fromUtf8("nz_"));
        sizePolicy1.setHeightForWidth(nz_->sizePolicy().hasHeightForWidth());
        nz_->setSizePolicy(sizePolicy1);
        nz_->setMaximumSize(QSize(80, 32767));
        nz_->setMaximum(1000000000);
        nz_->setMinimum(1);

        gridLayout1->addWidget(nz_, 2, 1, 1, 1);

        TextLabel4_2 = new QLabel(GroupBox1);
        TextLabel4_2->setObjectName(QString::fromUtf8("TextLabel4_2"));
        sizePolicy.setHeightForWidth(TextLabel4_2->sizePolicy().hasHeightForWidth());
        TextLabel4_2->setSizePolicy(sizePolicy);
        TextLabel4_2->setWordWrap(false);

        gridLayout1->addWidget(TextLabel4_2, 1, 0, 1, 1);

        nx_ = new QSpinBox(GroupBox1);
        nx_->setObjectName(QString::fromUtf8("nx_"));
        sizePolicy1.setHeightForWidth(nx_->sizePolicy().hasHeightForWidth());
        nx_->setSizePolicy(sizePolicy1);
        nx_->setMaximumSize(QSize(80, 32767));
        nx_->setMaximum(100000000);
        nx_->setMinimum(1);

        gridLayout1->addWidget(nx_, 0, 1, 1, 1);

        TextLabel4_3 = new QLabel(GroupBox1);
        TextLabel4_3->setObjectName(QString::fromUtf8("TextLabel4_3"));
        sizePolicy.setHeightForWidth(TextLabel4_3->sizePolicy().hasHeightForWidth());
        TextLabel4_3->setSizePolicy(sizePolicy);
        TextLabel4_3->setWordWrap(false);

        gridLayout1->addWidget(TextLabel4_3, 2, 0, 1, 1);


        hboxLayout->addLayout(gridLayout1);

        Spacer8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Spacer8);


        gridLayout->addWidget(GroupBox1, 3, 0, 1, 1);

        Spacer14_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(Spacer14_2, 4, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        TextLabel1_2 = new QLabel(GslibGridImport);
        TextLabel1_2->setObjectName(QString::fromUtf8("TextLabel1_2"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TextLabel1_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2->setSizePolicy(sizePolicy2);
        QFont font;
        font.setBold(true);
        TextLabel1_2->setFont(font);
        TextLabel1_2->setWordWrap(false);

        hboxLayout1->addWidget(TextLabel1_2);

        Line1_2 = new QFrame(GslibGridImport);
        Line1_2->setObjectName(QString::fromUtf8("Line1_2"));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Line1_2->sizePolicy().hasHeightForWidth());
        Line1_2->setSizePolicy(sizePolicy3);
        Line1_2->setFrameShape(QFrame::HLine);
        Line1_2->setFrameShadow(QFrame::Sunken);

        hboxLayout1->addWidget(Line1_2);


        gridLayout->addLayout(hboxLayout1, 5, 0, 1, 1);

        groupBox5 = new QGroupBox(GslibGridImport);
        groupBox5->setObjectName(QString::fromUtf8("groupBox5"));
        vboxLayout = new QVBoxLayout(groupBox5);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacer24 = new QSpacerItem(31, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer24);

        use_no_data_value_ = new QCheckBox(groupBox5);
        use_no_data_value_->setObjectName(QString::fromUtf8("use_no_data_value_"));

        hboxLayout2->addWidget(use_no_data_value_);

        spacer25 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer25);


        vboxLayout->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setMargin(0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        spacer23 = new QSpacerItem(22, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer23);

        NoDataValueBox = new QGroupBox(groupBox5);
        NoDataValueBox->setObjectName(QString::fromUtf8("NoDataValueBox"));
        NoDataValueBox->setEnabled(false);
        hboxLayout4 = new QHBoxLayout(NoDataValueBox);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setMargin(0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        textLabel1 = new QLabel(NoDataValueBox);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout4->addWidget(textLabel1);

        no_data_value_edit_ = new QLineEdit(NoDataValueBox);
        no_data_value_edit_->setObjectName(QString::fromUtf8("no_data_value_edit_"));

        hboxLayout4->addWidget(no_data_value_edit_);


        hboxLayout3->addWidget(NoDataValueBox);

        spacer22 = new QSpacerItem(22, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer22);


        vboxLayout->addLayout(hboxLayout3);


        gridLayout->addWidget(groupBox5, 14, 0, 1, 1);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setMargin(0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        TextLabel1 = new QLabel(GslibGridImport);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        sizePolicy2.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy2);
        TextLabel1->setFont(font);
        TextLabel1->setWordWrap(false);

        hboxLayout5->addWidget(TextLabel1);

        Line1 = new QFrame(GslibGridImport);
        Line1->setObjectName(QString::fromUtf8("Line1"));
        QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Line1->sizePolicy().hasHeightForWidth());
        Line1->setSizePolicy(sizePolicy4);
        Line1->setFrameShape(QFrame::HLine);
        Line1->setFrameShadow(QFrame::Sunken);

        hboxLayout5->addWidget(Line1);


        gridLayout->addLayout(hboxLayout5, 2, 0, 1, 1);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setMargin(0);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        TextLabel4_4 = new QLabel(GslibGridImport);
        TextLabel4_4->setObjectName(QString::fromUtf8("TextLabel4_4"));
        sizePolicy.setHeightForWidth(TextLabel4_4->sizePolicy().hasHeightForWidth());
        TextLabel4_4->setSizePolicy(sizePolicy);
        TextLabel4_4->setWordWrap(false);

        hboxLayout6->addWidget(TextLabel4_4);

        name_ = new QLineEdit(GslibGridImport);
        name_->setObjectName(QString::fromUtf8("name_"));

        hboxLayout6->addWidget(name_);


        gridLayout->addLayout(hboxLayout6, 0, 0, 1, 1);

        Spacer6 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(Spacer6, 1, 0, 1, 1);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setMargin(0);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        TextLabel1_2_2_2_2 = new QLabel(GslibGridImport);
        TextLabel1_2_2_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2_2_2"));
        sizePolicy2.setHeightForWidth(TextLabel1_2_2_2_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2_2_2_2->setSizePolicy(sizePolicy2);
        TextLabel1_2_2_2_2->setFont(font);
        TextLabel1_2_2_2_2->setWordWrap(false);

        hboxLayout7->addWidget(TextLabel1_2_2_2_2);

        Line1_2_2_2_2 = new QFrame(GslibGridImport);
        Line1_2_2_2_2->setObjectName(QString::fromUtf8("Line1_2_2_2_2"));
        sizePolicy3.setHeightForWidth(Line1_2_2_2_2->sizePolicy().hasHeightForWidth());
        Line1_2_2_2_2->setSizePolicy(sizePolicy3);
        Line1_2_2_2_2->setFrameShape(QFrame::HLine);
        Line1_2_2_2_2->setFrameShadow(QFrame::Sunken);

        hboxLayout7->addWidget(Line1_2_2_2_2);


        gridLayout->addLayout(hboxLayout7, 13, 0, 1, 1);

        TextLabel2_2 = new QLabel(GslibGridImport);
        TextLabel2_2->setObjectName(QString::fromUtf8("TextLabel2_2"));
        TextLabel2_2->setWordWrap(false);

        gridLayout->addWidget(TextLabel2_2, 6, 0, 1, 1);

        GroupBox1_2 = new QGroupBox(GslibGridImport);
        GroupBox1_2->setObjectName(QString::fromUtf8("GroupBox1_2"));
        GroupBox1_2->setMaximumSize(QSize(32767, 120));
        hboxLayout8 = new QHBoxLayout(GroupBox1_2);
        hboxLayout8->setSpacing(6);
        hboxLayout8->setMargin(11);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        Spacer9_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(Spacer9_2);

        gridLayout2 = new QGridLayout();
        gridLayout2->setSpacing(6);
        gridLayout2->setMargin(0);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        x_size_ = new QLineEdit(GroupBox1_2);
        x_size_->setObjectName(QString::fromUtf8("x_size_"));
        x_size_->setAlignment(Qt::AlignRight);

        gridLayout2->addWidget(x_size_, 0, 1, 1, 1);

        y_size_ = new QLineEdit(GroupBox1_2);
        y_size_->setObjectName(QString::fromUtf8("y_size_"));
        y_size_->setAlignment(Qt::AlignRight);

        gridLayout2->addWidget(y_size_, 1, 1, 1, 1);

        z_size_ = new QLineEdit(GroupBox1_2);
        z_size_->setObjectName(QString::fromUtf8("z_size_"));
        z_size_->setAlignment(Qt::AlignRight);

        gridLayout2->addWidget(z_size_, 2, 1, 1, 1);

        TextLabel4_5 = new QLabel(GroupBox1_2);
        TextLabel4_5->setObjectName(QString::fromUtf8("TextLabel4_5"));
        sizePolicy.setHeightForWidth(TextLabel4_5->sizePolicy().hasHeightForWidth());
        TextLabel4_5->setSizePolicy(sizePolicy);
        TextLabel4_5->setWordWrap(false);

        gridLayout2->addWidget(TextLabel4_5, 0, 0, 1, 1);

        TextLabel4_2_2 = new QLabel(GroupBox1_2);
        TextLabel4_2_2->setObjectName(QString::fromUtf8("TextLabel4_2_2"));
        sizePolicy.setHeightForWidth(TextLabel4_2_2->sizePolicy().hasHeightForWidth());
        TextLabel4_2_2->setSizePolicy(sizePolicy);
        TextLabel4_2_2->setWordWrap(false);

        gridLayout2->addWidget(TextLabel4_2_2, 1, 0, 1, 1);

        TextLabel4_3_2 = new QLabel(GroupBox1_2);
        TextLabel4_3_2->setObjectName(QString::fromUtf8("TextLabel4_3_2"));
        sizePolicy.setHeightForWidth(TextLabel4_3_2->sizePolicy().hasHeightForWidth());
        TextLabel4_3_2->setSizePolicy(sizePolicy);
        TextLabel4_3_2->setWordWrap(false);

        gridLayout2->addWidget(TextLabel4_3_2, 2, 0, 1, 1);


        hboxLayout8->addLayout(gridLayout2);

        Spacer8_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(Spacer8_2);


        gridLayout->addWidget(GroupBox1_2, 7, 0, 1, 1);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setSpacing(6);
        hboxLayout9->setMargin(0);
        hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
        TextLabel1_2_2 = new QLabel(GslibGridImport);
        TextLabel1_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2"));
        sizePolicy2.setHeightForWidth(TextLabel1_2_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2_2->setSizePolicy(sizePolicy2);
        TextLabel1_2_2->setFont(font);
        TextLabel1_2_2->setWordWrap(false);

        hboxLayout9->addWidget(TextLabel1_2_2);

        Line1_2_2 = new QFrame(GslibGridImport);
        Line1_2_2->setObjectName(QString::fromUtf8("Line1_2_2"));
        sizePolicy3.setHeightForWidth(Line1_2_2->sizePolicy().hasHeightForWidth());
        Line1_2_2->setSizePolicy(sizePolicy3);
        Line1_2_2->setFrameShape(QFrame::HLine);
        Line1_2_2->setFrameShadow(QFrame::Sunken);

        hboxLayout9->addWidget(Line1_2_2);


        gridLayout->addLayout(hboxLayout9, 9, 0, 1, 1);

        Spacer14 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(Spacer14, 8, 0, 1, 1);

        GroupBox1_2_2 = new QGroupBox(GslibGridImport);
        GroupBox1_2_2->setObjectName(QString::fromUtf8("GroupBox1_2_2"));
        GroupBox1_2_2->setMaximumSize(QSize(32767, 120));
        gridLayout3 = new QGridLayout(GroupBox1_2_2);
        gridLayout3->setSpacing(6);
        gridLayout3->setMargin(0);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        xmn_ = new QLineEdit(GroupBox1_2_2);
        xmn_->setObjectName(QString::fromUtf8("xmn_"));
        xmn_->setAlignment(Qt::AlignRight);

        gridLayout3->addWidget(xmn_, 0, 1, 1, 1);

        Spacer10_2 = new QSpacerItem(16, 21, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout3->addItem(Spacer10_2, 0, 2, 1, 1);

        TextLabel4_5_2_2 = new QLabel(GroupBox1_2_2);
        TextLabel4_5_2_2->setObjectName(QString::fromUtf8("TextLabel4_5_2_2"));
        sizePolicy.setHeightForWidth(TextLabel4_5_2_2->sizePolicy().hasHeightForWidth());
        TextLabel4_5_2_2->setSizePolicy(sizePolicy);
        TextLabel4_5_2_2->setWordWrap(false);

        gridLayout3->addWidget(TextLabel4_5_2_2, 0, 3, 1, 1);

        ymn_ = new QLineEdit(GroupBox1_2_2);
        ymn_->setObjectName(QString::fromUtf8("ymn_"));
        ymn_->setAlignment(Qt::AlignRight);

        gridLayout3->addWidget(ymn_, 0, 4, 1, 1);

        TextLabel4_5_2_2_2 = new QLabel(GroupBox1_2_2);
        TextLabel4_5_2_2_2->setObjectName(QString::fromUtf8("TextLabel4_5_2_2_2"));
        sizePolicy.setHeightForWidth(TextLabel4_5_2_2_2->sizePolicy().hasHeightForWidth());
        TextLabel4_5_2_2_2->setSizePolicy(sizePolicy);
        TextLabel4_5_2_2_2->setWordWrap(false);

        gridLayout3->addWidget(TextLabel4_5_2_2_2, 0, 5, 1, 1);

        zmn_ = new QLineEdit(GroupBox1_2_2);
        zmn_->setObjectName(QString::fromUtf8("zmn_"));
        zmn_->setAlignment(Qt::AlignRight);

        gridLayout3->addWidget(zmn_, 0, 6, 1, 1);

        Spacer10_2_2 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout3->addItem(Spacer10_2_2, 0, 7, 1, 1);

        TextLabel4_5_2 = new QLabel(GroupBox1_2_2);
        TextLabel4_5_2->setObjectName(QString::fromUtf8("TextLabel4_5_2"));
        sizePolicy.setHeightForWidth(TextLabel4_5_2->sizePolicy().hasHeightForWidth());
        TextLabel4_5_2->setSizePolicy(sizePolicy);
        TextLabel4_5_2->setWordWrap(false);

        gridLayout3->addWidget(TextLabel4_5_2, 0, 0, 1, 1);


        gridLayout->addWidget(GroupBox1_2_2, 11, 0, 1, 1);

        TextLabel2 = new QLabel(GslibGridImport);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        TextLabel2->setWordWrap(false);

        gridLayout->addWidget(TextLabel2, 10, 0, 1, 1);

        QWidget::setTabOrder(name_, nx_);
        QWidget::setTabOrder(nx_, ny_);
        QWidget::setTabOrder(ny_, nz_);

        retranslateUi(GslibGridImport);
        QObject::connect(use_no_data_value_, SIGNAL(toggled(bool)), NoDataValueBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(GslibGridImport);
    } // setupUi

    void retranslateUi(QWidget *GslibGridImport)
    {
        GslibGridImport->setWindowTitle(QApplication::translate("GslibGridImport", "Grid Characteristics", 0, QApplication::UnicodeUTF8));
        GroupBox1->setTitle(QString());
        TextLabel4->setText(QApplication::translate("GslibGridImport", "Number of cells in X", 0, QApplication::UnicodeUTF8));
        TextLabel4_2->setText(QApplication::translate("GslibGridImport", "Number of cells in Y", 0, QApplication::UnicodeUTF8));
        TextLabel4_3->setText(QApplication::translate("GslibGridImport", "Number of cells in Z", 0, QApplication::UnicodeUTF8));
        TextLabel1_2->setText(QApplication::translate("GslibGridImport", "Cell Size", 0, QApplication::UnicodeUTF8));
        groupBox5->setTitle(QString());
        use_no_data_value_->setText(QApplication::translate("GslibGridImport", "Use No-Data-Value", 0, QApplication::UnicodeUTF8));
        NoDataValueBox->setTitle(QString());
        textLabel1->setText(QApplication::translate("GslibGridImport", "No-Data-Value:", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("GslibGridImport", "Grid Dimensions", 0, QApplication::UnicodeUTF8));
        TextLabel4_4->setText(QApplication::translate("GslibGridImport", "Grid name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        name_->setProperty("toolTip", QVariant(QApplication::translate("GslibGridImport", "name of new grid", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
        TextLabel1_2_2_2_2->setText(QApplication::translate("GslibGridImport", "No Data Value", 0, QApplication::UnicodeUTF8));
        TextLabel2_2->setText(QApplication::translate("GslibGridImport", "The dimensions of a single cell", 0, QApplication::UnicodeUTF8));
        GroupBox1_2->setTitle(QString());
        x_size_->setText(QApplication::translate("GslibGridImport", "1.0", 0, QApplication::UnicodeUTF8));
        y_size_->setText(QApplication::translate("GslibGridImport", "1.0", 0, QApplication::UnicodeUTF8));
        z_size_->setText(QApplication::translate("GslibGridImport", "1.0", 0, QApplication::UnicodeUTF8));
        TextLabel4_5->setText(QApplication::translate("GslibGridImport", "Size in X", 0, QApplication::UnicodeUTF8));
        TextLabel4_2_2->setText(QApplication::translate("GslibGridImport", "Size in Y", 0, QApplication::UnicodeUTF8));
        TextLabel4_3_2->setText(QApplication::translate("GslibGridImport", "Size in Z", 0, QApplication::UnicodeUTF8));
        TextLabel1_2_2->setText(QApplication::translate("GslibGridImport", "Origin Coordinates", 0, QApplication::UnicodeUTF8));
        GroupBox1_2_2->setTitle(QString());
        xmn_->setText(QApplication::translate("GslibGridImport", "0", 0, QApplication::UnicodeUTF8));
        TextLabel4_5_2_2->setText(QApplication::translate("GslibGridImport", "Oy", 0, QApplication::UnicodeUTF8));
        ymn_->setText(QApplication::translate("GslibGridImport", "0", 0, QApplication::UnicodeUTF8));
        TextLabel4_5_2_2_2->setText(QApplication::translate("GslibGridImport", "Oz", 0, QApplication::UnicodeUTF8));
        zmn_->setText(QApplication::translate("GslibGridImport", "0", 0, QApplication::UnicodeUTF8));
        TextLabel4_5_2->setText(QApplication::translate("GslibGridImport", "Ox", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("GslibGridImport", "The coordinates of the lower left corner of the grid", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GslibGridImport);
    } // retranslateUi

};

namespace Ui {
    class GslibGridImport: public Ui_GslibGridImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GSLIBGRIDIMPORT_H
