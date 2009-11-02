/********************************************************************************
** Form generated from reading ui file 'importwizard.ui'
**
** Created: Sun Nov 1 20:45:42 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_IMPORTWIZARD_H
#define UI_IMPORTWIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportWizard
{
public:
    QVBoxLayout *vboxLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *vboxLayout1;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel1;
    QComboBox *ObjectType;
    QSpacerItem *spacerItem;
    QLabel *TextLabel2;
    QTextEdit *text_preview_;
    QFrame *line;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QPushButton *_back;
    QPushButton *_next;
    QPushButton *_cancel;

    void setupUi(QDialog *ImportWizard)
    {
        if (ImportWizard->objectName().isEmpty())
            ImportWizard->setObjectName(QString::fromUtf8("ImportWizard"));
        ImportWizard->resize(464, 709);
        vboxLayout = new QVBoxLayout(ImportWizard);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setMargin(9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        stackedWidget = new QStackedWidget(ImportWizard);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        vboxLayout1 = new QVBoxLayout(page);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setMargin(9);
#endif
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setMargin(0);
#endif
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setMargin(0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        TextLabel1 = new QLabel(page);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy);
        TextLabel1->setWordWrap(false);

        hboxLayout->addWidget(TextLabel1);

        ObjectType = new QComboBox(page);
        ObjectType->setObjectName(QString::fromUtf8("ObjectType"));

        hboxLayout->addWidget(ObjectType);


        vboxLayout2->addLayout(hboxLayout);

        spacerItem = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacerItem);

        TextLabel2 = new QLabel(page);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        TextLabel2->setWordWrap(false);

        vboxLayout2->addWidget(TextLabel2);

        text_preview_ = new QTextEdit(page);
        text_preview_->setObjectName(QString::fromUtf8("text_preview_"));
        text_preview_->setUndoRedoEnabled(false);
        text_preview_->setReadOnly(true);

        vboxLayout2->addWidget(text_preview_);


        vboxLayout1->addLayout(vboxLayout2);

        stackedWidget->addWidget(page);

        vboxLayout->addWidget(stackedWidget);

        line = new QFrame(ImportWizard);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        _back = new QPushButton(ImportWizard);
        _back->setObjectName(QString::fromUtf8("_back"));

        hboxLayout1->addWidget(_back);

        _next = new QPushButton(ImportWizard);
        _next->setObjectName(QString::fromUtf8("_next"));

        hboxLayout1->addWidget(_next);

        _cancel = new QPushButton(ImportWizard);
        _cancel->setObjectName(QString::fromUtf8("_cancel"));

        hboxLayout1->addWidget(_cancel);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(ImportWizard);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ImportWizard);
    } // setupUi

    void retranslateUi(QDialog *ImportWizard)
    {
        ImportWizard->setWindowTitle(QApplication::translate("ImportWizard", "Dialog", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("ImportWizard", "Select object type", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("ImportWizard", "File preview", 0, QApplication::UnicodeUTF8));
        _back->setText(QApplication::translate("ImportWizard", "< Back", 0, QApplication::UnicodeUTF8));
        _next->setText(QApplication::translate("ImportWizard", "Next >", 0, QApplication::UnicodeUTF8));
        _cancel->setText(QApplication::translate("ImportWizard", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ImportWizard);
    } // retranslateUi

};

namespace Ui {
    class ImportWizard: public Ui_ImportWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTWIZARD_H
