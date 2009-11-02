/********************************************************************************
** Form generated from reading ui file 'qt_algo_control_panel_base.ui'
**
** Created: Sun Nov 1 20:46:25 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QT_ALGO_CONTROL_PANEL_BASE_H
#define UI_QT_ALGO_CONTROL_PANEL_BASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Algo_control_panel_base
{
public:
    QVBoxLayout *vboxLayout;
    QSplitter *splitter;
    QGroupBox *_algo_group;
    QGroupBox *_input_group;
    QGroupBox *_controls_group;

    void setupUi(QWidget *Algo_control_panel_base)
    {
        if (Algo_control_panel_base->objectName().isEmpty())
            Algo_control_panel_base->setObjectName(QString::fromUtf8("Algo_control_panel_base"));
        Algo_control_panel_base->resize(272, 576);
        vboxLayout = new QVBoxLayout(Algo_control_panel_base);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(Algo_control_panel_base);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        _algo_group = new QGroupBox(splitter);
        _algo_group->setObjectName(QString::fromUtf8("_algo_group"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(120);
        sizePolicy.setHeightForWidth(_algo_group->sizePolicy().hasHeightForWidth());
        _algo_group->setSizePolicy(sizePolicy);
        _algo_group->setFlat(true);
        splitter->addWidget(_algo_group);
        _input_group = new QGroupBox(splitter);
        _input_group->setObjectName(QString::fromUtf8("_input_group"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(_input_group->sizePolicy().hasHeightForWidth());
        _input_group->setSizePolicy(sizePolicy1);
        _input_group->setFlat(true);
        splitter->addWidget(_input_group);

        vboxLayout->addWidget(splitter);

        _controls_group = new QGroupBox(Algo_control_panel_base);
        _controls_group->setObjectName(QString::fromUtf8("_controls_group"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(_controls_group->sizePolicy().hasHeightForWidth());
        _controls_group->setSizePolicy(sizePolicy2);
        _controls_group->setMinimumSize(QSize(0, 90));
        _controls_group->setFlat(true);

        vboxLayout->addWidget(_controls_group);


        retranslateUi(Algo_control_panel_base);

        QMetaObject::connectSlotsByName(Algo_control_panel_base);
    } // setupUi

    void retranslateUi(QWidget *Algo_control_panel_base)
    {
        Algo_control_panel_base->setWindowTitle(QApplication::translate("Algo_control_panel_base", "Form", 0, QApplication::UnicodeUTF8));
        _algo_group->setTitle(QString());
        _input_group->setTitle(QString());
        _controls_group->setTitle(QString());
        Q_UNUSED(Algo_control_panel_base);
    } // retranslateUi

};

namespace Ui {
    class Algo_control_panel_base: public Ui_Algo_control_panel_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_ALGO_CONTROL_PANEL_BASE_H
