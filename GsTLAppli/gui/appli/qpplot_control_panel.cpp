/**********************************************************************
** Author: Nicolas Remy
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

#include <GsTLAppli/gui/appli/qpplot_control_panel.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_region.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>

#include <qgroupbox.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <QVBoxLayout>

using namespace String_Op;

QPplot_control_panel::QPplot_control_panel( GsTL_project* proj,
                     QWidget* parent, const char* name ) 
  : QWidget( parent ) {

  setupUi(this);

  // set-up the 2 property selectors
  QVBoxLayout * vbox = new QVBoxLayout();

  vbox->setSpacing( 0 );
  
  property_selector_box_1_->setLayout(vbox);
  object_selector_var1_ = new PropertySelector( property_selector_box_1_, "object_selector_1" );
  vbox->addWidget(object_selector_var1_);


  QVBoxLayout * v = new QVBoxLayout();

  v->setSpacing( 0 );
  
  property_selector_box_2_->setLayout(v);
  object_selector_var2_ = new PropertySelector( property_selector_box_2_, "object_selector_2" );
  v->addWidget(object_selector_var2_);
  
  init( proj );

  // forward signals

  QObject::connect( (QObject*) minval_edit_1_, SIGNAL( returnPressed() ),
                    this, SLOT( forward_var1_low_clip_changed() ) );
  QObject::connect( (QObject*) maxval_edit_1_, SIGNAL( returnPressed() ),
                    this, SLOT( forward_var1_high_clip_changed() ) );
  QObject::connect( (QObject*) reset_clips_button_1_, SIGNAL( clicked() ),
                    SIGNAL( reset_var1_clipping_values_clicked() ) );

  QObject::connect( (QObject*) minval_edit_2_, SIGNAL( returnPressed() ),
                    this, SLOT( forward_var2_low_clip_changed() ) );
  QObject::connect( (QObject*) maxval_edit_2_, SIGNAL( returnPressed() ),
                    this, SLOT( forward_var2_high_clip_changed() ) );
  QObject::connect( (QObject*) reset_clips_button_2_, SIGNAL( clicked() ),
                    SIGNAL( reset_var2_clipping_values_clicked() ) );

  QObject::connect( (QObject*) analysis_combobox_,
                    SIGNAL( activated( const QString& ) ),
                    SIGNAL( analysis_type_changed( const QString& ) ) );

  QObject::connect( object_selector_var1_,
                    SIGNAL( property_changed( const QString& ) ),
                    this,
                    SLOT( forward_var1_changed( const QString& ) ) );

  QObject::connect( object_selector_var2_,
                    SIGNAL( property_changed( const QString& ) ),
                    this,
                    SLOT( forward_var2_changed( const QString& ) ) );

  QObject::connect( object_selector_var1_,
                    SIGNAL( region_changed( const QString& ) ),
                    this,
                    SLOT( forward_var1_changed( const QString& ) ) );

   QObject::connect( object_selector_var2_,
                    SIGNAL( region_changed( const QString& ) ),
                    this,
                    SLOT( forward_var2_changed( const QString& ) ) );

}







QPplot_control_panel::~QPplot_control_panel() {
}

void QPplot_control_panel::init( GsTL_project* project ) {
  object_selector_var1_->init( project );
  object_selector_var2_->init( project );
}

void QPplot_control_panel::set_var1_clipping_values( float low, float high ) {
  QString val;
  val.setNum( low );
  minval_edit_1_->setText( val );
  val.setNum( high );
  maxval_edit_1_->setText( val );
}

void QPplot_control_panel::set_var2_clipping_values( float low, float high ) {
  QString val;
  val.setNum( low );
  minval_edit_2_->setText( val );
  val.setNum( high );
  maxval_edit_2_->setText( val );
}

 

GsTLGridProperty*
QPplot_control_panel::get_property( const PropertySelector* object_selector ) {
  std::string grid_name( qstring2string(object_selector->selectedGrid()) );
  if( grid_name.empty() ) return 0;

  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(
                Root::instance()->interface(
                                            gridModels_manager + "/" + grid_name
                                            ).raw_ptr()
                );

  appli_assert( grid );

  std::string prop_name( qstring2string(object_selector->selectedProperty()) );
  GsTLGridProperty* prop = grid->property( prop_name );
  appli_assert( prop );
  return prop;
}
 
GsTLGridRegion*
QPplot_control_panel::get_region( const PropertySelector* object_selector ) {
  std::string grid_name(  object_selector->selectedGrid().toStdString() );
  std::string region_name( object_selector->selectedRegion().toStdString() );
  if( grid_name.empty() || region_name.empty() ) return 0;

  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(
                Root::instance()->interface(
                                            gridModels_manager + "/" + grid_name
                                            ).raw_ptr()
                );

  appli_assert( grid );

  GsTLGridRegion* region = grid->region( region_name );
  appli_assert( region );
  return region;
}



void QPplot_control_panel::forward_var1_changed( const QString& ) {
  //emit var1_changed( get_property( object_selector_var1_ ) );
  emit var1_changed( get_property( object_selector_var1_ ), get_region( object_selector_var1_ ) );
}

void QPplot_control_panel::forward_var2_changed( const QString& ) {
  //emit var2_changed( get_property( object_selector_var2_ ) );
  emit var2_changed( get_property( object_selector_var2_ ), get_region( object_selector_var2_ ));
}

void QPplot_control_panel::forward_var1_low_clip_changed() {
  emit var1_low_clip_changed( minval_edit_1_->text().toFloat() );
}
void QPplot_control_panel::forward_var1_high_clip_changed() {
  emit var1_high_clip_changed( maxval_edit_1_->text().toFloat() );
}

void QPplot_control_panel::forward_var2_low_clip_changed() {
  emit var2_low_clip_changed( minval_edit_2_->text().toFloat() );
}
void QPplot_control_panel::forward_var2_high_clip_changed() {
  emit var2_high_clip_changed( maxval_edit_2_->text().toFloat() );
}
