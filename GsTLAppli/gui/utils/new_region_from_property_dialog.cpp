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
#include <GsTLAppli/extra/qtplugins/categorical_selectors.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/actions/common.h>
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/grid_categorical_property.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/appli/project.h>

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
  project_ = proj;
  
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
  

  min_max_box_ = new QGroupBox( prop_box );
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
  min_max_box_->setLayout( h_min_max);
  min_max_box_->setTitle("Values between Min and Max will be inside the region");

  vp->addWidget( propSelector_ );
  vp->addWidget( min_max_box_ );
  min_max_box_->setHidden(true);


  category_box_ = new QGroupBox(prop_box);
  category_box_->setTitle("Select categories that define the region");
  QVBoxLayout *v_cat = new QVBoxLayout( prop_box );

  cat_selector_ = new MultipleCategorySelector();
  v_cat->addWidget(cat_selector_);
  category_box_->setLayout(v_cat);
  category_box_->setHidden(true);
  vp->addWidget( category_box_ );



  grid_box->setLayout(vg);
  new_region_box->setLayout(vr);
  prop_box->setLayout(vp);


  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* ok = new QPushButton( "Create", this);
  QPushButton* close = new QPushButton( "Create and Close", this);
  QPushButton* cancel = new QPushButton( "Cancel", this);

  bottom_layout->addStretch();
  bottom_layout->addWidget( ok );
  bottom_layout->addWidget( close );
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

  QObject::connect( propSelector_, SIGNAL( activated( const QString& ) ),
                    this, SLOT( set_filter_type(  ) ) );

  QObject::connect( propSelector_, SIGNAL( activated( const QString& ) ),
                    this, SLOT( populate_categories( ) ) );


  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( create_region() ) );
  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( create_region_and_close() ) );
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

QStringList New_region_from_property_dialog::get_selected_categories() const{
  QStringList current_selection;
  for( int i = 0; i < cat_selector_->count() ; i++ ) {
	if( !cat_selector_->item(i)->isSelected() ) continue;
	current_selection.push_back( cat_selector_->item(i)->text() );
  }
  return current_selection;
}


void New_region_from_property_dialog::set_filter_type(){
  QString grid_name = selected_grid();
  QString prop_name = selected_property();
  if(grid_name.isEmpty() || prop_name.isEmpty()) return;
  SmartPtr< Named_interface > ni =
	Root::instance()->interface( gridModels_manager + "/" + grid_name.toStdString() );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr());
  GsTLGridCategoricalProperty *prop = grid->categorical_property(prop_name.toStdString());
  if(prop) {
	  min_max_box_->setHidden(true);
	  category_box_->setVisible(true);
	  isCategorical_ = true;
  } else {
	  category_box_->setHidden(true);
	  min_max_box_->setVisible(true);
	  isCategorical_ = false;
  }

}

void New_region_from_property_dialog::populate_categories(){
  if( !isCategorical_ ) return;

  QString grid_name = selected_grid();
  QString prop_name = selected_property();
  if(grid_name.isEmpty() || prop_name.isEmpty()) return;
  SmartPtr< Named_interface > ni =
	Root::instance()->interface( gridModels_manager + "/" + grid_name.toStdString() );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr());
  GsTLGridCategoricalProperty *prop = grid->categorical_property(prop_name.toStdString());

  if(!prop) return;

  const CategoricalPropertyDefinition* cat_def = prop->get_category_definition();
  CategoricalPropertyDefinitionName* cat_def_name =
	  dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());

  if( cat_def_name ) {
    cat_selector_->show_categories( cat_def_name->name().c_str() );
  }
  else {
    cat_selector_->show_default_categories( prop->get_number_of_category() );
  }

}


bool New_region_from_property_dialog::isCategorical() const{
	return isCategorical_;
}

void New_region_from_property_dialog::create_region(){
	  QString grid_name = selected_grid();
	  QString prop_name = selected_property();
	  QString region_name = new_region_name();

	  if( grid_name.isEmpty() || region_name.isEmpty() || prop_name.isEmpty()) return;


	  QApplication::setOverrideCursor( Qt::WaitCursor );

	  QString sep = Actions::separator.c_str();
	  QStringList list;
	  list.append( grid_name );
	  list.append(region_name);
	  list.append( prop_name );

	  std::string command;
	  if(this->isCategorical()) {
		 list.append(this->get_selected_categories());
		 command = "SetRegionFromCategoricalPropertyIf";
	  }
	  else	{
		list.append( this->get_min_filter_value() );
		list.append( this->get_max_filter_value() );
		command = "SetRegionFromPropertyIf";
	  }
	  std::string parameters = list.join( sep ).toStdString();
	  if( parameters.empty() ) return;

	  // call the DeleteObjectProperties action
	  Error_messages_handler error_messages;



	  bool ok = project_->execute( command, parameters, &error_messages );

	  if( !ok ) {
	    GsTLcerr << "Command " << command << " could not be performed. \n";
	    if( !error_messages.empty() ) {
	      GsTLcerr << error_messages.errors();
	    }
	    GsTLcerr << gstlIO::end;
	  }

	  QApplication::restoreOverrideCursor();
	  project_->update();

}

void New_region_from_property_dialog::create_region_and_close(){
	create_region();
	accept();
}
