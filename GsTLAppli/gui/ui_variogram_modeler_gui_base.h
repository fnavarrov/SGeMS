/********************************************************************************
** Form generated from reading ui file 'variogram_modeler_gui_base.ui'
**
** Created: Sun Nov 1 20:46:22 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VARIOGRAM_MODELER_GUI_BASE_H
#define UI_VARIOGRAM_MODELER_GUI_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_variogram_modeler_gui_base
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *_back;
    QPushButton *_next;
    QPushButton *_cancel;
    QStackedWidget *_stack;
    QWidget *_default_page;

    void setupUi(QDialog *variogram_modeler_gui_base)
    {
        if (variogram_modeler_gui_base->objectName().isEmpty())
            variogram_modeler_gui_base->setObjectName(QString::fromUtf8("variogram_modeler_gui_base"));
        variogram_modeler_gui_base->resize(497, 453);
        gridLayout = new QGridLayout(variogram_modeler_gui_base);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setMargin(9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setMargin(0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        _back = new QPushButton(variogram_modeler_gui_base);
        _back->setObjectName(QString::fromUtf8("_back"));

        hboxLayout->addWidget(_back);

        _next = new QPushButton(variogram_modeler_gui_base);
        _next->setObjectName(QString::fromUtf8("_next"));

        hboxLayout->addWidget(_next);

        _cancel = new QPushButton(variogram_modeler_gui_base);
        _cancel->setObjectName(QString::fromUtf8("_cancel"));

        hboxLayout->addWidget(_cancel);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);

        _stack = new QStackedWidget(variogram_modeler_gui_base);
        _stack->setObjectName(QString::fromUtf8("_stack"));
        _default_page = new QWidget();
        _default_page->setObjectName(QString::fromUtf8("_default_page"));
        _stack->addWidget(_default_page);

        gridLayout->addWidget(_stack, 0, 0, 1, 1);


        retranslateUi(variogram_modeler_gui_base);

        _stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(variogram_modeler_gui_base);
    } // setupUi

    void retranslateUi(QDialog *variogram_modeler_gui_base)
    {
        variogram_modeler_gui_base->setWindowTitle(QApplication::translate("variogram_modeler_gui_base", "Dialog", 0, QApplication::UnicodeUTF8));
        _back->setText(QApplication::translate("variogram_modeler_gui_base", "< Back", 0, QApplication::UnicodeUTF8));
        _next->setText(QApplication::translate("variogram_modeler_gui_base", "Next >", 0, QApplication::UnicodeUTF8));
        _cancel->setText(QApplication::translate("variogram_modeler_gui_base", "Close", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(variogram_modeler_gui_base);
    } // retranslateUi

};

namespace Ui {
    class variogram_modeler_gui_base: public Ui_variogram_modeler_gui_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIOGRAM_MODELER_GUI_BASE_H
