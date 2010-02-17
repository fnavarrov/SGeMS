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

#include <GsTLAppli/gui/utils/new_mgrid_from_cgrid_dialog.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/utils/gstl_messages.h>

#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QButtonGroup>


New_mgrid_from_cgrid_dialog::
New_mgrid_from_cgrid_dialog( GsTL_project* proj,
                    QWidget* parent, const char* name ){
  if (name)
    setObjectName(name);
  
  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  QGroupBox* grid_box = new QGroupBox( this);
  QGroupBox* new_mgrid_box = new QGroupBox( this);
  QGroupBox* regions_box = new QGroupBox( this);
  
  QVBoxLayout *vg = new QVBoxLayout(grid_box);
  QVBoxLayout *vr = new QVBoxLayout(regions_box);
  QVBoxLayout *vm = new QVBoxLayout(new_mgrid_box);

  vg->addWidget(new QLabel("Select grid",grid_box) );
  gridSelector_ = new GridSelectorBasic(grid_box, "grid", proj );
  vg->addWidget(gridSelector_ );
  grid_box->setLayout( vg );

  vm->addWidget(new QLabel("New Masked Grid name",regions_box) );
  new_mgrid_ = new QLineEdit(new_mgrid_box);
  vm->addWidget(new_mgrid_ );
  new_mgrid_box->setLayout( vm );

  vr->addWidget(new QLabel("Regions to define the grid (Union)",regions_box) );
  regionsSelector_ = new MultiRegionSelector(regions_box, "regions" );

  vr->addWidget( regionsSelector_ );


  grid_box->setLayout(vg);
  new_mgrid_box->setLayout(vm);
  regions_box->setLayout(vr);

  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* ok = new QPushButton( "Create", this);  
  QPushButton* cancel = new QPushButton( "Cancel", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( ok );
  bottom_layout->addWidget( cancel );

  main_layout->addWidget( grid_box );
  main_layout->addStretch();
  main_layout->addWidget( new_mgrid_box );
  main_layout->addStretch();
  main_layout->addWidget( regions_box );
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );

  
  QObject::connect( gridSelector_, SIGNAL( activated( const QString& ) ),
                    regionsSelector_, SLOT( show_regions( const QString& ) ) );

  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );

  setSizeGripEnabled( true );
}

QString 
New_mgrid_from_cgrid_dialog::selected_grid() const {
  return gridSelector_->currentText();
}

QStringList 
New_mgrid_from_cgrid_dialog::selected_regions() const{
  QStringList list;
  for( unsigned int i = 0; i < regionsSelector_->count() ; i++ ) {
    if( regionsSelector_->item(i)->isSelected() && !regionsSelector_->item(i)->text().isEmpty() ) 
      list << regionsSelector_->item(i)->text( );
  }
  return list;
}

QString 
New_mgrid_from_cgrid_dialog::new_mgrid_name() const {
  return new_mgrid_->text();
}

