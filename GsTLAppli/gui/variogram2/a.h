/********************************************************************************
** Form generated from reading ui file 'variogram_modeler_gui_base.ui'
**
** Created: Fri Sep 28 07:54:56 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef A_H
#define A_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

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
    variogram_modeler_gui_base->setObjectName(QString::fromUtf8("variogram_modeler_gui_base"));
    gridLayout = new QGridLayout(variogram_modeler_gui_base);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
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

    QSize size(497, 453);
    size = size.expandedTo(variogram_modeler_gui_base->minimumSizeHint());
    variogram_modeler_gui_base->resize(size);


    _stack->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(variogram_modeler_gui_base);
    } // setupUi

    void retranslateUi(QDialog *variogram_modeler_gui_base)
    {
    variogram_modeler_gui_base->setWindowTitle(QApplication::translate("variogram_modeler_gui_base", "Dialog", 0, QApplication::UnicodeUTF8));
    _back->setText(QApplication::translate("variogram_modeler_gui_base", "< Back", 0, QApplication::UnicodeUTF8));
    _next->setText(QApplication::translate("variogram_modeler_gui_base", "Next >", 0, QApplication::UnicodeUTF8));
    _cancel->setText(QApplication::translate("variogram_modeler_gui_base", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(variogram_modeler_gui_base);
    } // retranslateUi

};

namespace Ui {
    class variogram_modeler_gui_base: public Ui_variogram_modeler_gui_base {};
} // namespace Ui

#endif // A_H
