/********************************************************************************
** Form generated from reading ui file 'general_display_pref_panel_qt4_base.ui'
**
** Created: Sun Nov 1 16:47:14 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GENERAL_DISPLAY_PREF_PANEL_QT4_BASE_H
#define UI_GENERAL_DISPLAY_PREF_PANEL_QT4_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_general_display_pref_panel_qt4_base
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel2;
    QFrame *Line1;

    void setupUi(QWidget *general_display_pref_panel_qt4_base)
    {
        if (general_display_pref_panel_qt4_base->objectName().isEmpty())
            general_display_pref_panel_qt4_base->setObjectName(QString::fromUtf8("general_display_pref_panel_qt4_base"));
        general_display_pref_panel_qt4_base->resize(259, 703);
        layoutWidget = new QWidget(general_display_pref_panel_qt4_base);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 241, 16));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setMargin(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        TextLabel2 = new QLabel(layoutWidget);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
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

        Line1 = new QFrame(layoutWidget);
        Line1->setObjectName(QString::fromUtf8("Line1"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Line1->sizePolicy().hasHeightForWidth());
        Line1->setSizePolicy(sizePolicy1);
        Line1->setFrameShape(QFrame::HLine);
        Line1->setFrameShadow(QFrame::Raised);
        Line1->setMidLineWidth(1);
        Line1->setFrameShape(QFrame::HLine);

        hboxLayout->addWidget(Line1);


        retranslateUi(general_display_pref_panel_qt4_base);

        QMetaObject::connectSlotsByName(general_display_pref_panel_qt4_base);
    } // setupUi

    void retranslateUi(QWidget *general_display_pref_panel_qt4_base)
    {
        general_display_pref_panel_qt4_base->setWindowTitle(QApplication::translate("general_display_pref_panel_qt4_base", "Form", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("general_display_pref_panel_qt4_base", "Camera Settings", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(general_display_pref_panel_qt4_base);
    } // retranslateUi

};

namespace Ui {
    class general_display_pref_panel_qt4_base: public Ui_general_display_pref_panel_qt4_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERAL_DISPLAY_PREF_PANEL_QT4_BASE_H
