/********************************************************************************
** Form generated from reading ui file 'gslibmaskedimport.ui'
**
** Created: Sun Nov 1 20:45:42 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GSLIBMASKEDIMPORT_H
#define UI_GSLIBMASKEDIMPORT_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GslibMaskedImport
{
public:
    QWidget *Layout8;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel4_4;
    QLineEdit *name_;
    QLabel *TextLabel1_2_2_2_2;
    QFrame *Line1_2_2_2_2;
    QSpinBox *_maskcol;
    QLabel *TextLabel4_5;
    QGroupBox *_ps;
    QLabel *TextLabel4_3;
    QLabel *TextLabel4;
    QLabel *TextLabel4_2;
    QSpinBox *X_col_;
    QSpinBox *Y_col_;
    QSpinBox *Z_col_;
    QGroupBox *buttonGroup1;
    QRadioButton *_isps;
    QRadioButton *_isregular;
    QGroupBox *_rgrid;
    QLabel *textLabel1_2_2;
    QLabel *textLabel1_2;
    QLabel *sizeXLabel;
    QLabel *sizeXLabel_2;
    QLabel *sizeX_2_3;
    QLabel *sizeX_2_2_2;
    QLabel *sizeX_2;
    QLineEdit *xmn_;
    QLineEdit *ymn_;
    QLineEdit *zmn_;
    QLabel *sizeX_2_2;
    QLineEdit *x_size_;
    QLineEdit *y_size_;
    QLineEdit *z_size_;
    QLabel *textLabel1_2_3;
    QLineEdit *ny_;
    QLineEdit *nz_;
    QLineEdit *nx_;
    QGroupBox *groupBox5;
    QCheckBox *use_no_data_value_;
    QGroupBox *_edit;
    QLabel *textLabel1;
    QLineEdit *no_data_value_edit_;

    void setupUi(QWidget *GslibMaskedImport)
    {
        if (GslibMaskedImport->objectName().isEmpty())
            GslibMaskedImport->setObjectName(QString::fromUtf8("GslibMaskedImport"));
        GslibMaskedImport->resize(338, 789);
        Layout8 = new QWidget(GslibMaskedImport);
        Layout8->setObjectName(QString::fromUtf8("Layout8"));
        Layout8->setGeometry(QRect(11, 11, 316, 25));
        hboxLayout = new QHBoxLayout(Layout8);
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        TextLabel4_4 = new QLabel(Layout8);
        TextLabel4_4->setObjectName(QString::fromUtf8("TextLabel4_4"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel4_4->sizePolicy().hasHeightForWidth());
        TextLabel4_4->setSizePolicy(sizePolicy);
        TextLabel4_4->setWordWrap(false);

        hboxLayout->addWidget(TextLabel4_4);

        name_ = new QLineEdit(Layout8);
        name_->setObjectName(QString::fromUtf8("name_"));

        hboxLayout->addWidget(name_);

        TextLabel1_2_2_2_2 = new QLabel(GslibMaskedImport);
        TextLabel1_2_2_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2_2_2"));
        TextLabel1_2_2_2_2->setGeometry(QRect(11, 434, 102, 17));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabel1_2_2_2_2->sizePolicy().hasHeightForWidth());
        TextLabel1_2_2_2_2->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        TextLabel1_2_2_2_2->setFont(font);
        TextLabel1_2_2_2_2->setWordWrap(false);
        Line1_2_2_2_2 = new QFrame(GslibMaskedImport);
        Line1_2_2_2_2->setObjectName(QString::fromUtf8("Line1_2_2_2_2"));
        Line1_2_2_2_2->setGeometry(QRect(129, 441, 198, 16));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Line1_2_2_2_2->sizePolicy().hasHeightForWidth());
        Line1_2_2_2_2->setSizePolicy(sizePolicy2);
        Line1_2_2_2_2->setFrameShape(QFrame::HLine);
        Line1_2_2_2_2->setFrameShadow(QFrame::Sunken);
        _maskcol = new QSpinBox(GslibMaskedImport);
        _maskcol->setObjectName(QString::fromUtf8("_maskcol"));
        _maskcol->setGeometry(QRect(247, 405, 80, 23));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(0));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(_maskcol->sizePolicy().hasHeightForWidth());
        _maskcol->setSizePolicy(sizePolicy3);
        _maskcol->setMaximumSize(QSize(80, 32767));
        _maskcol->setMaximum(100000000);
        _maskcol->setMinimum(1);
        TextLabel4_5 = new QLabel(GslibMaskedImport);
        TextLabel4_5->setObjectName(QString::fromUtf8("TextLabel4_5"));
        TextLabel4_5->setGeometry(QRect(11, 405, 88, 23));
        sizePolicy.setHeightForWidth(TextLabel4_5->sizePolicy().hasHeightForWidth());
        TextLabel4_5->setSizePolicy(sizePolicy);
        TextLabel4_5->setWordWrap(false);
        _ps = new QGroupBox(GslibMaskedImport);
        _ps->setObjectName(QString::fromUtf8("_ps"));
        _ps->setEnabled(false);
        _ps->setGeometry(QRect(11, 239, 316, 124));
        TextLabel4_3 = new QLabel(_ps);
        TextLabel4_3->setObjectName(QString::fromUtf8("TextLabel4_3"));
        TextLabel4_3->setGeometry(QRect(43, 80, 137, 23));
        sizePolicy.setHeightForWidth(TextLabel4_3->sizePolicy().hasHeightForWidth());
        TextLabel4_3->setSizePolicy(sizePolicy);
        TextLabel4_3->setWordWrap(false);
        TextLabel4 = new QLabel(_ps);
        TextLabel4->setObjectName(QString::fromUtf8("TextLabel4"));
        TextLabel4->setGeometry(QRect(43, 22, 137, 23));
        sizePolicy.setHeightForWidth(TextLabel4->sizePolicy().hasHeightForWidth());
        TextLabel4->setSizePolicy(sizePolicy);
        TextLabel4->setWordWrap(false);
        TextLabel4_2 = new QLabel(_ps);
        TextLabel4_2->setObjectName(QString::fromUtf8("TextLabel4_2"));
        TextLabel4_2->setGeometry(QRect(43, 51, 138, 23));
        sizePolicy.setHeightForWidth(TextLabel4_2->sizePolicy().hasHeightForWidth());
        TextLabel4_2->setSizePolicy(sizePolicy);
        TextLabel4_2->setWordWrap(false);
        X_col_ = new QSpinBox(_ps);
        X_col_->setObjectName(QString::fromUtf8("X_col_"));
        X_col_->setGeometry(QRect(187, 22, 80, 23));
        sizePolicy3.setHeightForWidth(X_col_->sizePolicy().hasHeightForWidth());
        X_col_->setSizePolicy(sizePolicy3);
        X_col_->setMaximumSize(QSize(80, 32767));
        X_col_->setMaximum(100000000);
        X_col_->setMinimum(1);
        Y_col_ = new QSpinBox(_ps);
        Y_col_->setObjectName(QString::fromUtf8("Y_col_"));
        Y_col_->setGeometry(QRect(187, 51, 80, 23));
        sizePolicy3.setHeightForWidth(Y_col_->sizePolicy().hasHeightForWidth());
        Y_col_->setSizePolicy(sizePolicy3);
        Y_col_->setMaximumSize(QSize(80, 32767));
        Y_col_->setMaximum(1000000000);
        Y_col_->setMinimum(1);
        Y_col_->setValue(2);
        Z_col_ = new QSpinBox(_ps);
        Z_col_->setObjectName(QString::fromUtf8("Z_col_"));
        Z_col_->setGeometry(QRect(187, 80, 80, 23));
        sizePolicy3.setHeightForWidth(Z_col_->sizePolicy().hasHeightForWidth());
        Z_col_->setSizePolicy(sizePolicy3);
        Z_col_->setMaximumSize(QSize(80, 32767));
        Z_col_->setMaximum(1000000000);
        Z_col_->setMinimum(0);
        Z_col_->setValue(0);
        buttonGroup1 = new QGroupBox(GslibMaskedImport);
        buttonGroup1->setObjectName(QString::fromUtf8("buttonGroup1"));
        buttonGroup1->setGeometry(QRect(11, 42, 316, 58));
        _isps = new QRadioButton(buttonGroup1);
        _isps->setObjectName(QString::fromUtf8("_isps"));
        _isps->setGeometry(QRect(180, 19, 70, 21));
        _isregular = new QRadioButton(buttonGroup1);
        _isregular->setObjectName(QString::fromUtf8("_isregular"));
        _isregular->setGeometry(QRect(20, 19, 101, 21));
        _isregular->setChecked(true);
        _rgrid = new QGroupBox(GslibMaskedImport);
        _rgrid->setObjectName(QString::fromUtf8("_rgrid"));
        _rgrid->setEnabled(true);
        _rgrid->setGeometry(QRect(11, 106, 316, 127));
        textLabel1_2_2 = new QLabel(_rgrid);
        textLabel1_2_2->setObjectName(QString::fromUtf8("textLabel1_2_2"));
        textLabel1_2_2->setGeometry(QRect(111, 23, 36, 23));
        textLabel1_2_2->setWordWrap(false);
        textLabel1_2 = new QLabel(_rgrid);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setGeometry(QRect(11, 23, 35, 23));
        textLabel1_2->setWordWrap(false);
        sizeXLabel = new QLabel(_rgrid);
        sizeXLabel->setObjectName(QString::fromUtf8("sizeXLabel"));
        sizeXLabel->setGeometry(QRect(11, 52, 35, 23));
        sizeXLabel->setWordWrap(false);
        sizeXLabel_2 = new QLabel(_rgrid);
        sizeXLabel_2->setObjectName(QString::fromUtf8("sizeXLabel_2"));
        sizeXLabel_2->setGeometry(QRect(11, 81, 35, 23));
        sizeXLabel_2->setWordWrap(false);
        sizeX_2_3 = new QLabel(_rgrid);
        sizeX_2_3->setObjectName(QString::fromUtf8("sizeX_2_3"));
        sizeX_2_3->setGeometry(QRect(111, 81, 36, 23));
        sizeX_2_3->setWordWrap(false);
        sizeX_2_2_2 = new QLabel(_rgrid);
        sizeX_2_2_2->setObjectName(QString::fromUtf8("sizeX_2_2_2"));
        sizeX_2_2_2->setGeometry(QRect(211, 81, 35, 23));
        sizeX_2_2_2->setWordWrap(false);
        sizeX_2 = new QLabel(_rgrid);
        sizeX_2->setObjectName(QString::fromUtf8("sizeX_2"));
        sizeX_2->setGeometry(QRect(111, 52, 36, 23));
        sizeX_2->setLineWidth(1);
        sizeX_2->setWordWrap(false);
        xmn_ = new QLineEdit(_rgrid);
        xmn_->setObjectName(QString::fromUtf8("xmn_"));
        xmn_->setGeometry(QRect(52, 81, 53, 23));
        ymn_ = new QLineEdit(_rgrid);
        ymn_->setObjectName(QString::fromUtf8("ymn_"));
        ymn_->setGeometry(QRect(153, 81, 52, 23));
        zmn_ = new QLineEdit(_rgrid);
        zmn_->setObjectName(QString::fromUtf8("zmn_"));
        zmn_->setGeometry(QRect(252, 81, 53, 23));
        sizeX_2_2 = new QLabel(_rgrid);
        sizeX_2_2->setObjectName(QString::fromUtf8("sizeX_2_2"));
        sizeX_2_2->setGeometry(QRect(211, 52, 35, 23));
        sizeX_2_2->setWordWrap(false);
        x_size_ = new QLineEdit(_rgrid);
        x_size_->setObjectName(QString::fromUtf8("x_size_"));
        x_size_->setGeometry(QRect(52, 52, 53, 23));
        y_size_ = new QLineEdit(_rgrid);
        y_size_->setObjectName(QString::fromUtf8("y_size_"));
        y_size_->setGeometry(QRect(153, 52, 52, 23));
        z_size_ = new QLineEdit(_rgrid);
        z_size_->setObjectName(QString::fromUtf8("z_size_"));
        z_size_->setGeometry(QRect(252, 52, 53, 23));
        textLabel1_2_3 = new QLabel(_rgrid);
        textLabel1_2_3->setObjectName(QString::fromUtf8("textLabel1_2_3"));
        textLabel1_2_3->setGeometry(QRect(211, 23, 35, 23));
        textLabel1_2_3->setWordWrap(false);
        ny_ = new QLineEdit(_rgrid);
        ny_->setObjectName(QString::fromUtf8("ny_"));
        ny_->setGeometry(QRect(153, 23, 52, 23));
        nz_ = new QLineEdit(_rgrid);
        nz_->setObjectName(QString::fromUtf8("nz_"));
        nz_->setGeometry(QRect(252, 23, 53, 23));
        nx_ = new QLineEdit(_rgrid);
        nx_->setObjectName(QString::fromUtf8("nx_"));
        nx_->setGeometry(QRect(52, 23, 53, 23));
        groupBox5 = new QGroupBox(GslibMaskedImport);
        groupBox5->setObjectName(QString::fromUtf8("groupBox5"));
        groupBox5->setGeometry(QRect(11, 457, 316, 125));
        use_no_data_value_ = new QCheckBox(groupBox5);
        use_no_data_value_->setObjectName(QString::fromUtf8("use_no_data_value_"));
        use_no_data_value_->setGeometry(QRect(87, 12, 142, 22));
        _edit = new QGroupBox(groupBox5);
        _edit->setObjectName(QString::fromUtf8("_edit"));
        _edit->setEnabled(false);
        _edit->setGeometry(QRect(9, 44, 291, 70));
        textLabel1 = new QLabel(_edit);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setGeometry(QRect(10, 15, 90, 31));
        textLabel1->setWordWrap(false);
        no_data_value_edit_ = new QLineEdit(_edit);
        no_data_value_edit_->setObjectName(QString::fromUtf8("no_data_value_edit_"));
        no_data_value_edit_->setGeometry(QRect(110, 15, 161, 31));
        QWidget::setTabOrder(name_, _isregular);
        QWidget::setTabOrder(_isregular, nx_);
        QWidget::setTabOrder(nx_, ny_);
        QWidget::setTabOrder(ny_, nz_);
        QWidget::setTabOrder(nz_, x_size_);
        QWidget::setTabOrder(x_size_, y_size_);
        QWidget::setTabOrder(y_size_, z_size_);
        QWidget::setTabOrder(z_size_, xmn_);
        QWidget::setTabOrder(xmn_, ymn_);
        QWidget::setTabOrder(ymn_, zmn_);
        QWidget::setTabOrder(zmn_, X_col_);
        QWidget::setTabOrder(X_col_, Y_col_);
        QWidget::setTabOrder(Y_col_, Z_col_);
        QWidget::setTabOrder(Z_col_, _maskcol);
        QWidget::setTabOrder(_maskcol, use_no_data_value_);
        QWidget::setTabOrder(use_no_data_value_, no_data_value_edit_);

        retranslateUi(GslibMaskedImport);
        QObject::connect(_isps, SIGNAL(toggled(bool)), _ps, SLOT(setEnabled(bool)));
        QObject::connect(use_no_data_value_, SIGNAL(toggled(bool)), _edit, SLOT(setEnabled(bool)));
        QObject::connect(_isps, SIGNAL(toggled(bool)), _maskcol, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(GslibMaskedImport);
    } // setupUi

    void retranslateUi(QWidget *GslibMaskedImport)
    {
        GslibMaskedImport->setWindowTitle(QApplication::translate("GslibMaskedImport", "Grid with inactive cells", 0, QApplication::UnicodeUTF8));
        TextLabel4_4->setText(QApplication::translate("GslibMaskedImport", "Grid name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        name_->setProperty("toolTip", QVariant(QApplication::translate("GslibMaskedImport", "name of new grid", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
        TextLabel1_2_2_2_2->setText(QApplication::translate("GslibMaskedImport", "No Data Value", 0, QApplication::UnicodeUTF8));
        TextLabel4_5->setText(QApplication::translate("GslibMaskedImport", "Col. # for mask", 0, QApplication::UnicodeUTF8));
        _ps->setTitle(QApplication::translate("GslibMaskedImport", "Point set", 0, QApplication::UnicodeUTF8));
        TextLabel4_3->setText(QApplication::translate("GslibMaskedImport", "Col. # for Z coordinates", 0, QApplication::UnicodeUTF8));
        TextLabel4->setText(QApplication::translate("GslibMaskedImport", "Col. # for X coordinates", 0, QApplication::UnicodeUTF8));
        TextLabel4_2->setText(QApplication::translate("GslibMaskedImport", "Col. # for Y coordinates", 0, QApplication::UnicodeUTF8));
        Z_col_->setSpecialValueText(QApplication::translate("GslibMaskedImport", "NA (2d)", 0, QApplication::UnicodeUTF8));
        buttonGroup1->setTitle(QString());
        _isps->setText(QApplication::translate("GslibMaskedImport", "point set", 0, QApplication::UnicodeUTF8));
        _isregular->setText(QApplication::translate("GslibMaskedImport", "regular grid", 0, QApplication::UnicodeUTF8));
        _rgrid->setTitle(QApplication::translate("GslibMaskedImport", "Bounding box", 0, QApplication::UnicodeUTF8));
        textLabel1_2_2->setText(QApplication::translate("GslibMaskedImport", "DimY", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("GslibMaskedImport", "DimX", 0, QApplication::UnicodeUTF8));
        sizeXLabel->setText(QApplication::translate("GslibMaskedImport", "SizeX", 0, QApplication::UnicodeUTF8));
        sizeXLabel_2->setText(QApplication::translate("GslibMaskedImport", "OX", 0, QApplication::UnicodeUTF8));
        sizeX_2_3->setText(QApplication::translate("GslibMaskedImport", "OY", 0, QApplication::UnicodeUTF8));
        sizeX_2_2_2->setText(QApplication::translate("GslibMaskedImport", "OZ", 0, QApplication::UnicodeUTF8));
        sizeX_2->setText(QApplication::translate("GslibMaskedImport", "SizeY", 0, QApplication::UnicodeUTF8));
        xmn_->setText(QApplication::translate("GslibMaskedImport", "0", 0, QApplication::UnicodeUTF8));
        ymn_->setText(QApplication::translate("GslibMaskedImport", "0", 0, QApplication::UnicodeUTF8));
        zmn_->setText(QApplication::translate("GslibMaskedImport", "0", 0, QApplication::UnicodeUTF8));
        sizeX_2_2->setText(QApplication::translate("GslibMaskedImport", "SizeZ", 0, QApplication::UnicodeUTF8));
        x_size_->setText(QApplication::translate("GslibMaskedImport", "1", 0, QApplication::UnicodeUTF8));
        y_size_->setText(QApplication::translate("GslibMaskedImport", "1", 0, QApplication::UnicodeUTF8));
        z_size_->setText(QApplication::translate("GslibMaskedImport", "1", 0, QApplication::UnicodeUTF8));
        textLabel1_2_3->setText(QApplication::translate("GslibMaskedImport", "DimZ", 0, QApplication::UnicodeUTF8));
        ny_->setText(QApplication::translate("GslibMaskedImport", "0", 0, QApplication::UnicodeUTF8));
        nz_->setText(QApplication::translate("GslibMaskedImport", "0", 0, QApplication::UnicodeUTF8));
        nx_->setText(QApplication::translate("GslibMaskedImport", "0", 0, QApplication::UnicodeUTF8));
        groupBox5->setTitle(QString());
        use_no_data_value_->setText(QApplication::translate("GslibMaskedImport", "Use No-Data-Value", 0, QApplication::UnicodeUTF8));
        _edit->setTitle(QString());
        textLabel1->setText(QApplication::translate("GslibMaskedImport", "No-data-value", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GslibMaskedImport);
    } // retranslateUi

};

namespace Ui {
    class GslibMaskedImport: public Ui_GslibMaskedImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GSLIBMASKEDIMPORT_H
