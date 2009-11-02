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

#include <GsTLAppli/gui/appli/scatterplot_control_panel.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_region.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/utils/string_manipulation.h>

#include <qgroupbox.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <QVBoxLayout>

using namespace String_Op;

Scatterplot_control_panel::
Scatterplot_control_panel( GsTL_project* proj,
                           QWidget* parent, const char* name ) 
  : QWidget( parent ) {

  if (name)
    setObjectName(name);
  
  setupUi(this);

  QVBoxLayout * v = new QVBoxLayout();
  grid_selector_box_->setLayout(v);
  v->setMargin( 0 );
  v->setSpacing( 0 );
  object_selector_ = new GridSelector( grid_selector_box_, "object_selector_" );
  v->addWidget(object_selector_);
  
  // set-up the 2 property selectors
  QVBoxLayout * v1 = new QVBoxLayout();  
  property_selector_box_1_->setLayout(v1);
  v1->setMargin( 0 );
  v1->setSpacing( 0 );
  prop_selector_var1_ = 
    new SinglePropertySelector( property_selector_box_1_, "prop_selector_1" );
  v1->addWidget(prop_selector_var1_);

  QVBoxLayout * v2 = new QVBoxLayout();    
  property_selector_box_2_->setLayout(v2);
  v2->setMargin( 0 );
  v2->setSpacing( 0 );
  prop_selector_var2_ = 
    new SinglePropertySelector( property_selector_box_2_, "prop_selector_2" );
  v2->addWidget(prop_selector_var2_);
  
  init( proj );

  // forward signals
  QObject::connect( lsfit_checkbox_,
                    SIGNAL( toggled( bool ) ),
                    SIGNAL( show_ls_fit( bool ) ) );

  QObject::connect( object_selector_,
                    SIGNAL( activated( const QString& ) ),
                    prop_selector_var1_,
                    SLOT( show_properties( const QString& ) ) );
  QObject::connect( object_selector_,
                    SIGNAL( activated( const QString& ) ),
                    prop_selector_var2_,
                    SLOT( show_properties( const QString& ) ) );


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

  QObject::connect( prop_selector_var1_,
                    SIGNAL( activated( const QString& ) ),
                    this,
                    SLOT( forward_var1_changed( const QString& ) ) );

  QObject::connect( prop_selector_var2_,
                    SIGNAL( activated( const QString& ) ),
                    this,
                    SLOT( forward_var2_changed( const QString& ) ) );

   QObject::connect( object_selector_,
                    SIGNAL( region_changed( const QString& ) ),
                    this,
                    SLOT( forward_var1_changed( const QString& ) ) );

   QObject::connect( object_selector_,
                    SIGNAL( region_changed( const QString& ) ),
                    this,
                    SLOT( forward_var2_changed( const QString& ) ) );

}




Scatterplot_control_panel::~Scatterplot_control_panel() {
}

void Scatterplot_control_panel::init( GsTL_project* project ) {
  object_selector_->init( project );
}


bool Scatterplot_control_panel::ls_fit_shown() const {
  return lsfit_checkbox_->isChecked(); 
}


void Scatterplot_control_panel::set_var1_clipping_values( float low, float high ) {
  QString val;
  val.setNum( low );
  minval_edit_1_->setText( val );
  val.setNum( high );
  maxval_edit_1_->setText( val );
}

void Scatterplot_control_panel::set_var2_clipping_values( float low, float high ) {
  QString val;
  val.setNum( low );
  minval_edit_2_->setText( val );
  val.setNum( high );
  maxval_edit_2_->setText( val );
}



GsTLGridProperty*
Scatterplot_control_panel::get_property( const SinglePropertySelector* prop_selector ) {
  //std::string grid_name( qstring2string(object_selector_->currentText()) );
  std::string grid_name( qstring2string( object_selector_->selectedGrid()) );
  if( grid_name.empty() ) return 0;

  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(
                Root::instance()->interface(
                                            gridModels_manager + "/" + grid_name
                                            ).raw_ptr()
                );

  appli_assert( grid );

  if( prop_selector->currentText().isEmpty() ) return 0;

  std::string prop_name = std::string( qstring2string(prop_selector->currentText()) );
  GsTLGridProperty* prop = grid->property( prop_name );
  appli_assert( prop );
  return prop;
}
 
GsTLGridRegion*
Scatterplot_control_panel::get_region( const GridSelector* object_selector ) {
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

/*
void Scatterplot_control_panel::forward_var1_changed( const QString& ) {
  emit var1_changed( get_property( prop_selector_var1_ ) );
}

void Scatterplot_control_panel::forward_var2_changed( const QString& ) {
  emit var2_changed( get_property( prop_selector_var2_ ) );
}
*/
void Scatterplot_control_panel::forward_var1_changed( const QString& ) {
  emit var1_changed( get_property( prop_selector_var1_ ), get_region( object_selector_ ) );
}

void Scatterplot_control_panel::forward_var2_changed( const QString& ) {
  emit var2_changed( get_property( prop_selector_var2_ ), get_region( object_selector_ ) );
}


void Scatterplot_control_panel::forward_var1_low_clip_changed() {
  emit var1_low_clip_changed( minval_edit_1_->text().toFloat() );
}
void Scatterplot_control_panel::forward_var1_high_clip_changed() {
  emit var1_high_clip_changed( maxval_edit_1_->text().toFloat() );
}

void Scatterplot_control_panel::forward_var2_low_clip_changed() {
  emit var2_low_clip_changed( minval_edit_2_->text().toFloat() );
}
void Scatterplot_control_panel::forward_var2_high_clip_changed() {
  emit var2_high_clip_changed( maxval_edit_2_->text().toFloat() );
}



void Scatterplot_control_panel::show_lsfit_coeffs( float slope, float intercp ) {
  slope_label_->setNum( slope );
  intercept_label_->setNum( intercp );
}


void Scatterplot_control_panel::
enable_lsfit( bool on ) {
  if( !on ) {
    lsfit_checkbox_->setChecked( false );
  }
  lsfit_groupbox_->setEnabled( on );
}
