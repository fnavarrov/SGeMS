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

#include <GsTLAppli/gui/utils/new_region_from_property_dialog.h>
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


New_region_from_property_dialog::
New_region_from_property_dialog( GsTL_project* proj,
                    QWidget* parent, const char* name ){
  if (name)
    setObjectName(name);
  
  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  QGroupBox* grid_box = new QGroupBox( this);
  QGroupBox* new_region_box = new QGroupBox( this);
  QGroupBox* prop_box = new QGroupBox( this);
  
  QVBoxLayout *vg = new QVBoxLayout(grid_box);
  QVBoxLayout *vr = new QVBoxLayout(new_region_box);
  QVBoxLayout *vp = new QVBoxLayout(prop_box);

  vg->addWidget(new QLabel("Select grid",grid_box) );
  gridSelector_ = new GridSelectorBasic(grid_box, "grid", proj );
  vg->addWidget(gridSelector_ );
  grid_box->setLayout( vg );

  vr->addWidget(new QLabel("New region name",new_region_box) );
  new_region_ = new QLineEdit(new_region_box);
  vr->addWidget(new_region_ );
  new_region_box->setLayout( vr );

  vp->addWidget(new QLabel("Source property",prop_box) );
  propSelector_ = new SinglePropertySelector(prop_box, "property" );
  QHBoxLayout *h_min_max = new QHBoxLayout( prop_box );
  

  QGroupBox* min_max_box = new QGroupBox( prop_box );
  QVBoxLayout *v_min = new QVBoxLayout( prop_box );
  QVBoxLayout *v_max = new QVBoxLayout( prop_box );

  v_min->addWidget(new QLabel("Min",prop_box));
  v_max->addWidget(new QLabel("Max",prop_box));
  minFilter_  = new QLineEdit(prop_box);
  maxFilter_  = new QLineEdit(prop_box);
  v_min->addWidget( minFilter_ );
  v_max->addWidget( maxFilter_ );

  h_min_max->addLayout(v_min);
  h_min_max->addLayout(v_max);
  min_max_box->setLayout( h_min_max);
  min_max_box->setTitle("Values between Min and Max will be inside the region");

  vp->addWidget( propSelector_ );
  vp->addWidget( min_max_box );


  grid_box->setLayout(vg);
  new_region_box->setLayout(vr);
  prop_box->setLayout(vp);


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
  main_layout->addWidget( prop_box );
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );

  
  QObject::connect( gridSelector_, SIGNAL( activated( const QString& ) ),
                    propSelector_, SLOT( show_properties( const QString& ) ) );

  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );

  setSizeGripEnabled( true );
}

QString 
New_region_from_property_dialog::selected_grid() const {
  return gridSelector_->currentText();
}

QString 
New_region_from_property_dialog::selected_property() const{
  return propSelector_->currentText();
}

QString 
New_region_from_property_dialog::new_region_name() const {
  return new_region_->text();
}


QString 
New_region_from_property_dialog::get_min_filter_value() const{
  return minFilter_->text();
}
QString 
New_region_from_property_dialog::get_max_filter_value() const {
  return maxFilter_->text();
}