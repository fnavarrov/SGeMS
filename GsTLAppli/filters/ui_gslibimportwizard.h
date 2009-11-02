/********************************************************************************
** Form generated from reading ui file 'gslibimportwizard.ui'
**
** Created: Sun Nov 1 16:46:56 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GSLIBIMPORTWIZARD_H
#define UI_GSLIBIMPORTWIZARD_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <Qt3Support/Q3TextEdit>
#include <Qt3Support/Q3Wizard>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GslibImportWizard
{
public:
    QWidget *object_type;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabel1;
    QComboBox *ObjectType;
    QSpacerItem *Spacer1;
    QLabel *TextLabel2;
    Q3TextEdit *TextPreview;

    void setupUi(Q3Wizard *GslibImportWizard)
    {
        if (GslibImportWizard->objectName().isEmpty())
            GslibImportWizard->setObjectName(QString::fromUtf8("GslibImportWizard"));
        GslibImportWizard->resize(460, 387);
        object_type = new QWidget(GslibImportWizard);
        object_type->setObjectName(QString::fromUtf8("object_type"));
        hboxLayout = new QHBoxLayout(object_type);
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        TextLabel1 = new QLabel(object_type);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy);
        TextLabel1->setWordWrap(false);

        hboxLayout1->addWidget(TextLabel1);

        ObjectType = new QComboBox(object_type);
        ObjectType->setObjectName(QString::fromUtf8("ObjectType"));

        hboxLayout1->addWidget(ObjectType);


        vboxLayout->addLayout(hboxLayout1);

        Spacer1 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(Spacer1);

        TextLabel2 = new QLabel(object_type);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
        TextLabel2->setWordWrap(false);

        vboxLayout->addWidget(TextLabel2);

        TextPreview = new Q3TextEdit(object_type);
        TextPreview->setObjectName(QString::fromUtf8("TextPreview"));
        TextPreview->setTextFormat(Qt::PlainText);
        TextPreview->setReadOnly(true);
        TextPreview->setUndoRedoEnabled(false);

        vboxLayout->addWidget(TextPreview);


        hboxLayout->addLayout(vboxLayout);

        GslibImportWizard->addPage(object_type, QString::fromUtf8("Object Type"));

        retranslateUi(GslibImportWizard);

        QMetaObject::connectSlotsByName(GslibImportWizard);
    } // setupUi

    void retranslateUi(Q3Wizard *GslibImportWizard)
    {
        GslibImportWizard->setCaption(QApplication::translate("GslibImportWizard", "Import from Gslib", 0, QApplication::UnicodeUTF8));
        TextLabel1->setText(QApplication::translate("GslibImportWizard", "Select object type", 0, QApplication::UnicodeUTF8));
        TextLabel2->setText(QApplication::translate("GslibImportWizard", "File preview", 0, QApplication::UnicodeUTF8));
        GslibImportWizard->setTitle(object_type, QApplication::translate("GslibImportWizard", "Object Type", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GslibImportWizard);
    } // retranslateUi

};

namespace Ui {
    class GslibImportWizard: public Ui_GslibImportWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GSLIBIMPORTWIZARD_H
