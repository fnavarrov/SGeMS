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

#include <GsTLAppli/gui/utils/indicator_property_dialog.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/extra/qtplugins/categorical_selectors.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/actions/common.h>
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
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


New_indicator_from_property_dialog::
New_indicator_from_property_dialog( GsTL_project* proj,
                    QWidget* parent, const char* name ){
  if (name)
    setObjectName(name);
  project_ = proj;
  
  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  

  main_layout->addWidget(new QLabel("Select grid",this) );
  gridSelector_ = new GridSelectorBasic(this, "grid", proj );
  main_layout->addWidget(gridSelector_ );

  main_layout->addWidget(new QLabel("Source property",this) );
  propSelector_ = new SinglePropertySelector(this, "property" );
  main_layout->addWidget(propSelector_);

  continuous_box_ = new QGroupBox(this);
  QVBoxLayout* continuous_layout = new QVBoxLayout( continuous_box_);

  threshold_type_ = new QComboBox(this);
  threshold_type_->addItem("User Defined");
  threshold_type_->addItem("Decile");
  threshold_type_->addItem("Quartile");
  threshold_type_->addItem("Quintile");
  threshold_type_->setCurrentIndex(0);


  thresold_line_ = new QLineEdit(this);
  continuous_layout->addWidget(threshold_type_);
  continuous_layout->addWidget(thresold_line_);

  continuous_box_->setLayout(continuous_layout);
  continuous_box_->setHidden(true);
  main_layout->addWidget( continuous_box_ );


  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* ok = new QPushButton( "Create", this);
  QPushButton* close = new QPushButton( "Create and Close", this);
  QPushButton* cancel = new QPushButton( "Cancel", this);

  bottom_layout->addStretch();
  bottom_layout->addWidget( ok );
  bottom_layout->addWidget( close );
  bottom_layout->addWidget( cancel );

  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );

  
  QObject::connect( gridSelector_, SIGNAL( activated( const QString& ) ),
                    propSelector_, SLOT( show_properties( const QString& ) ) );

  QObject::connect( propSelector_, SIGNAL( activated( const QString& ) ),
                    this, SLOT( show_continuous_input(  ) ) );

  QObject::connect( threshold_type_, SIGNAL( activated( const QString& ) ),
                    this, SLOT( show_threshold_input(  ) ) );

  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( create_indicator() ) );
  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( create_indicator_and_close() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );

  setSizeGripEnabled( true );
}

QString 
New_indicator_from_property_dialog::selected_grid() const {
  return gridSelector_->currentText();
}

QString 
New_indicator_from_property_dialog::selected_property() const{
  return propSelector_->currentText();
}

QString
New_indicator_from_property_dialog::selected_threhsold_type() const {
	return threshold_type_->currentText();
}

void
New_indicator_from_property_dialog::show_threshold_input() {
	thresold_line_->setVisible( selected_threhsold_type() == "User Defined" );
}

void
New_indicator_from_property_dialog::show_continuous_input() {
  QString grid_name = selected_grid();
  QString prop_name = selected_property();
  if(grid_name.isEmpty() || prop_name.isEmpty()) return;
  SmartPtr< Named_interface > ni =
	Root::instance()->interface( gridModels_manager + "/" + grid_name.toStdString() );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr());
  GsTLGridCategoricalProperty *prop = grid->categorical_property(prop_name.toStdString());
  if(prop) {
  	continuous_box_->setHidden(true);
  	isCategorical_ = true;
  } else {
	  continuous_box_->setVisible(true);
	  isCategorical_ = false;
  }
}


QStringList New_indicator_from_property_dialog::get_user_thresholds() const{

	QString thresh_str = thresold_line_->text();
	QStringList thresh_strlist = thresh_str.split(" ", QString::SkipEmptyParts);
	for(int i=0; i < thresh_strlist.size(); i++) {
		bool ok;
		float v = thresh_strlist.at(i).toFloat(&ok);
		if(!ok) thresh_strlist.removeAt(i);
	}

	return thresh_strlist;
}




bool New_indicator_from_property_dialog::isCategorical() const{
	return isCategorical_;
}

void New_indicator_from_property_dialog::create_indicator(){
	  QString grid_name = selected_grid();
	  QString prop_name = selected_property();


	  if( grid_name.isEmpty() || prop_name.isEmpty()) return;


	  QApplication::setOverrideCursor( Qt::WaitCursor );

	  QString sep = Actions::separator.c_str();
	  QStringList list;
	  list.append( grid_name );
	  list.append( prop_name );


	  if(this->isCategorical() == false) {
	   QString	type = selected_threhsold_type();
	   if(type == "User Defined") type == "UserDefined";
	   list.append(type);
	   if(type == "UserDefined") {
	  	 list.append(get_user_thresholds());
	   }
	  }

	  std::string parameters = list.join( sep ).toStdString();
	  if( parameters.empty() ) return;

	  // call the DeleteObjectProperties action
	  Error_messages_handler error_messages;

	  bool ok = project_->execute( "IndicatorCoding", parameters, &error_messages );

	  if( !ok ) {
	    GsTLcerr << "Command IndicatorCoding could not be performed. \n";
	    if( !error_messages.empty() ) {
	      GsTLcerr << error_messages.errors();
	    }
	    GsTLcerr << gstlIO::end;
	  }

	  QApplication::restoreOverrideCursor();
	  project_->update();

}

void New_indicator_from_property_dialog::create_indicator_and_close(){
	create_indicator();
	accept();
}
