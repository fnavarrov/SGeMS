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
modified from delete_properties_dialog (N. Remy)
**********************************************************************/

#include <GsTLAppli/gui/utils/delete_regions_dialog.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/utils/gstl_messages.h>

#include <qpushbutton.h>
#include <qstringlist.h>
#include <qlistwidget.h>
#include <qlayout.h>
#include <qlabel.h>
#include <QHBoxLayout>
#include <QGroupBox>

Delete_regions_dialog::
Delete_regions_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ) {

  setupUi(this);

  grid_selector_ = new GridSelectorBasic( grid_selector_box_, "grid_selector", proj );

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


}


QString Delete_regions_dialog::selected_grid() const {
  return grid_selector_->currentText();
}

QStringList Delete_regions_dialog::selected_items() {
  QStringList list;
  for( unsigned int i = 0; i < choice_list_->count() ; i++ ) {
    if( choice_list_->item(i)->isSelected() && !choice_list_->item(i)->text().isEmpty() ) 
      list << choice_list_->item(i)->text( );
  }

  return list;
}
