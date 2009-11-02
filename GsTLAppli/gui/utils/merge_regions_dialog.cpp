/**********************************************************************
** Author: Alexandre Boucher
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
** All rights reserved.
**
** This file is part of the "gui" module of the Geostatistical Earth
** Modeling Software (GEMS)
**
** This file may be distributed and/or modified under the terms of the 
** license defined by the Stanford Center for Reservoir Forecasting and 
** appearing in the file LICENSE.XFREE included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.gnu.org/copyleft/gpl.html for GPL licensing information.
**
** Contact the Stanford Center for Reservoir Forecasting, Stanford University
** if any conditions of this licensing are not clear to you.
**
**********************************************************************/

#include <GsTLAppli/gui/utils/merge_regions_dialog.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/utils/gstl_messages.h>

#include <qpushbutton.h>
#include <qstringlist.h>
#include <qlistwidget.h>
#include <qlayout.h>
#include <qlabel.h>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>








Merge_regions_dialog::
Merge_regions_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ) {

  if (name)
    setObjectName(name);
  
  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  QGroupBox* grid_box = new QGroupBox( this);
  QGroupBox* new_region_box = new QGroupBox( this);
  QGroupBox* regions_selector_box = new QGroupBox( this);
  
  QVBoxLayout *vg = new QVBoxLayout(grid_box);
  QVBoxLayout *vr = new QVBoxLayout(new_region_box);
  QVBoxLayout *vrs = new QVBoxLayout(regions_selector_box);

  vg->addWidget(new QLabel("Select grid",grid_box) );
  grid_selector_ = new GridSelectorBasic(grid_box, "grid", proj );
  vg->addWidget(grid_selector_ );
  grid_box->setLayout( vg );

  vr->addWidget(new QLabel("New region name",new_region_box) );
  merged_region_ = new QLineEdit(new_region_box);
  vr->addWidget(merged_region_ );
  new_region_box->setLayout( vr );


  vrs->addWidget(new QLabel("Regions to merge",regions_selector_box) );
  choice_list_ = new MultiRegionSelector(regions_selector_box, "regions" );
  vrs->addWidget(choice_list_ );
  regions_selector_box->setLayout( vrs );



  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* ok = new QPushButton( "Create", this);  
  QPushButton* cancel = new QPushButton( "Cancel", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( ok );
  bottom_layout->addWidget( cancel );

  main_layout->addWidget( grid_box );
  main_layout->addStretch();
  main_layout->addWidget( new_region_box );
  main_layout->addStretch();
  main_layout->addWidget( regions_selector_box );
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );


  QObject::connect( grid_selector_, SIGNAL( activated( const QString& ) ),
                    choice_list_, SLOT( show_regions( const QString& ) ) );
    
  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );




/*

  setupUi(this);

  grid_selector_ = new GridSelector( grid_selector_box_, "grid_selector", proj );

  QVBoxLayout * v = new QVBoxLayout();
  grid_selector_box_->setLayout(v);
  grid_selector_box_->layout()->addWidget(grid_selector_);

  choice_list_ = new MultiRegionSelector( regions_selector_box_);

  QVBoxLayout * v1 = new QVBoxLayout();
  
  regions_selector_box_->setLayout(v1);
  regions_selector_box_->layout()->addWidget(choice_list_);
  
  QObject::connect( grid_selector_, SIGNAL( activated( const QString& ) ),
                    choice_list_, SLOT( show_regions( const QString& ) ) );
    
  QObject::connect( ok_button_, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( cancel_button_, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );

*/
}


QString Merge_regions_dialog::selected_grid() const {
  return grid_selector_->currentText();
}

QStringList Merge_regions_dialog::selected_items() {
  QStringList list;
  for( unsigned int i = 0; i < choice_list_->count() ; i++ ) {
    if( choice_list_->item(i)->isSelected() && !choice_list_->item(i)->text().isEmpty() ) 
      list << choice_list_->item(i)->text( );
  }

  return list;
}

QString Merge_regions_dialog::new_region_name() {
  return merged_region_->text();
  //return name;
}

/*
void Merge_regions_dialog::setupUi(QDialog *Merge_regions_dialog)
{
    if (Merge_regions_dialog->objectName().isEmpty())
        Merge_regions_dialog->setObjectName(QString::fromUtf8("Merge_regions_dialog"));
    Merge_regions_dialog->resize(200, 328);
    Merge_regions_dialog->setSizeGripEnabled(true);
    vboxLayout = new QVBoxLayout(Merge_regions_dialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(11);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));

    textLabel2 = new QLabel(Merge_regions_dialog);
    textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(textLabel2->sizePolicy().hasHeightForWidth());
    textLabel2->setSizePolicy(sizePolicy);
    textLabel2->setWordWrap(false);

    vboxLayout->addWidget(textLabel2);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    grid_selector_box_ = new QGroupBox(Merge_regions_dialog);
    grid_selector_box_->setObjectName(QString::fromUtf8("grid_selector_box_"));
    sizePolicy.setHeightForWidth(grid_selector_box_->sizePolicy().hasHeightForWidth());
    grid_selector_box_->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(grid_selector_box_);
    vboxLayout->addLayout(hboxLayout);

// Widget for new region name

    textLabel_newRegion_ = new QLabel(Merge_regions_dialog);
    textLabel_newRegion_->setObjectName(QString::fromUtf8("textLabel_newRegion_"));
    sizePolicy.setHeightForWidth(textLabel_newRegion_->sizePolicy().hasHeightForWidth());
    textLabel_newRegion_->setSizePolicy(sizePolicy);
    textLabel_newRegion_->setWordWrap(false);

    vboxLayout->addWidget(textLabel_newRegion_);

    newRegion_box_ = new QGroupBox(Merge_regions_dialog);
    newRegion_box_->setObjectName(QString::fromUtf8("newRegion_box_"));
    sizePolicy.setHeightForWidth(newRegion_box_->sizePolicy().hasHeightForWidth());
    newRegion_box_->setSizePolicy(sizePolicy);


    merged_region_ = new QLineEdit();
    QVBoxLayout* vl = new QVBoxLayout();
    newRegion_box_->setLayout(vl);
    newRegion_box_->layout()->addWidget( merged_region_ );
    vboxLayout->addWidget(newRegion_box_);


    textLabel3 = new QLabel(Merge_regions_dialog);
    textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
    sizePolicy.setHeightForWidth(textLabel3->sizePolicy().hasHeightForWidth());
    textLabel3->setSizePolicy(sizePolicy);
    textLabel3->setWordWrap(false);

    vboxLayout->addWidget(textLabel3);

    regions_selector_box_ = new QGroupBox(Merge_regions_dialog);
    regions_selector_box_->setObjectName(QString::fromUtf8("regions_selector_box_"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(regions_selector_box_->sizePolicy().hasHeightForWidth());
    regions_selector_box_->setSizePolicy(sizePolicy1);

    vboxLayout->addWidget(regions_selector_box_);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem = new QSpacerItem(42, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);

    ok_button_ = new QPushButton(Merge_regions_dialog);
    ok_button_->setObjectName(QString::fromUtf8("ok_button_"));

    hboxLayout1->addWidget(ok_button_);

    spacerItem1 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);

    cancel_button_ = new QPushButton(Merge_regions_dialog);
    cancel_button_->setObjectName(QString::fromUtf8("cancel_button_"));

    hboxLayout1->addWidget(cancel_button_);

    spacerItem2 = new QSpacerItem(42, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem2);


    vboxLayout->addLayout(hboxLayout1);


    retranslateUi(Merge_regions_dialog);

    QMetaObject::connectSlotsByName(Merge_regions_dialog);
} // setupUi

void Merge_regions_dialog::retranslateUi(QDialog *Merge_regions_dialog)
{
    Merge_regions_dialog->setWindowTitle(QApplication::translate("Merge_regions_dialog", "Merge Regions", 0, QApplication::UnicodeUTF8));
    textLabel2->setText(QApplication::translate("Merge_regions_dialog", "Merge regions from object:", 0, QApplication::UnicodeUTF8));
    grid_selector_box_->setTitle(QString());
    textLabel3->setText(QApplication::translate("Merge_regions_dialog", "Regions to merge:", 0, QApplication::UnicodeUTF8));
    regions_selector_box_->setTitle(QString());
    textLabel_newRegion_->setText(QApplication::translate("Merge_regions_dialog", "New region name:", 0, QApplication::UnicodeUTF8));
    newRegion_box_->setTitle(QString());
    ok_button_->setText(QApplication::translate("Merge_regions_dialog", "&Merge", 0, QApplication::UnicodeUTF8));
    cancel_button_->setText(QApplication::translate("Merge_regions_dialog", "&Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Merge_regions_dialog);
} // retranslateUi
*/