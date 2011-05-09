/**********************************************************************
** Author: Alexandre Boucher
** Copyright (C) 2002-2004 Advanced Resources and Risk Technology, LLC
** All rights reserved.
**
** This file is part of the "extra" module of the Stanford Geostatistical Earth
** Modeling Software (SGEMS)
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
** Contact Advanced Resources and Risk Technology, LLC
** if any conditions of this licensing are not clear to you.
**
**********************************************************************/


#include <GsTLAppli/gui/utils/group_property_dialog.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/extra/qtplugins/group_selectors.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_categorical_property.h>
#include <GsTLAppli/actions/defines.h>

#include <set>

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
#include <QtGui/QRadioButton>
#include <QTextBrowser>
#include <QTextEdit>



View_group_property_dialog::
View_group_property_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ) {

  if (name)
    setObjectName(name);

  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);

  main_layout->addWidget(new QLabel("Select Grid",this) );
  grid_selector_ = new GridSelectorBasic(this,"GridSelector", proj);
  group_selector_ = new SinglePropertyGroupSelector(this,"GroupSelector");


  properties_viewer_ = new QTextBrowser(this);
  properties_viewer_->setReadOnly(true);
//  properties_viewer_->setAutoFormatting(QTextEdit::AutoBulletList);
  properties_viewer_->setUndoRedoEnabled(false);
//  properties_viewer_->setMaximumHeight(50);
  
  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* close = new QPushButton( "Close", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( close );
  
  main_layout->addWidget(grid_selector_);
  main_layout->addStretch();
  main_layout->addWidget(group_selector_);
  main_layout->addStretch();
  main_layout->addWidget( new QLabel("Associated properties") );
  main_layout->addWidget(properties_viewer_);
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );


  QObject::connect( grid_selector_, SIGNAL( activated( const QString& ) ),
                    group_selector_, SLOT( show_property_groups( const QString& ) ) );
    
  QObject::connect( group_selector_, SIGNAL( activated( const QString& ) ),
                    this, SLOT( display_properties( const QString& ) ) );

  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
//  QObject::connect( close, SIGNAL( clicked() ),
//                    this, SLOT( reject() ) );

}


void View_group_property_dialog::display_properties(const QString& group_name){
  
  if( grid_selector_->currentText() ==  GridSelectorBasic::no_selection ) return;
  std::string grid_name = grid_selector_->currentText().toStdString();

  if(current_group_ == group_name) return;
  current_group_ = group_name;

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + grid_name );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr()) ;

  if(grid == 0) return;

  GsTLGridPropertyGroup* group = grid->get_group( group_name.toStdString() );
  if(group == 0) return;

  std::vector<std::string> prop_names = group->property_names();


  properties_viewer_->document()->clear();


	std::vector<std::string>::const_iterator it = prop_names.begin();
	for( ; it != prop_names.end(); ++it) {
			properties_viewer_->append(QString(it->c_str()));
	}

}

/* ----------------------------------------------------- */



New_group_property_dialog::
New_group_property_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ), project_(proj) {

  if (name)
    setObjectName(name);

  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  grid_selector_ = new GridSelectorBasic(this,"GridSelector", proj);
  group_name_line_ = new QLineEdit(this);
  prop_selector_ = new OrderedPropertySelector(this);

  
  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* close = new QPushButton( "Create and Close", this);
  QPushButton* ok = new QPushButton( "Create", this);
  QPushButton* clear = new QPushButton( "Clear", this);
  QPushButton* cancel = new QPushButton( "Exit", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( clear ); 
  bottom_layout->addStretch();
   bottom_layout->addWidget( ok ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( close ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( cancel ); 
  bottom_layout->addStretch();

  main_layout->addWidget(new QLabel("Select Grid",this) );
  main_layout->addWidget(grid_selector_);
  main_layout->addStretch();

  main_layout->addWidget(new QLabel("New group name",this) );
  main_layout->addWidget(group_name_line_);
  main_layout->addStretch();
  main_layout->addWidget( new QLabel("Select Properties") );
  main_layout->addWidget(prop_selector_);
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );


  QObject::connect( grid_selector_, SIGNAL( activated( const QString& ) ),
                    prop_selector_, SLOT( show_properties( const QString& ) ) );

  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( create_group() ) );
  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( create_group_close() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );
//  QObject::connect( clear, SIGNAL( clicked() ),
//                    this, SLOT( clear() ) );

}


void New_group_property_dialog::clear(){
  grid_selector_->setCurrentIndex(0);
  group_name_line_->clear();
}


void New_group_property_dialog::create_group(){
  
  if(group_name_line_->text().isEmpty()) return;
  std::string group_name = group_name_line_->text().toStdString();

  if( grid_selector_->currentText() ==  GridSelectorBasic::no_selection ) return;
  std::string grid_name = grid_selector_->currentText().toStdString();

 
  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + grid_name );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr()) ;

  if(grid == 0) return;

  if( grid->get_group( group_name ) != 0 ) {
    GsTLcerr << "The group name " << group_name << " already exist.";
    GsTLcerr << gstlIO::end;
    return;
  }

  QStringList parameterList = prop_selector_->selected_properties();
  if(parameterList.isEmpty()) return;

  // Assume that the group is of type general
  parameterList.prepend("General");
  parameterList.prepend(group_name.c_str());
  parameterList.prepend(grid_name.c_str());

  QString parameters = parameterList.join("::");

 
  // call the CopyProperty action
  Error_messages_handler error_messages;

  std::string command( "NewPropertyGroup" );
  bool ok = project_->execute( command, parameters.toStdString(), &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }

  QApplication::restoreOverrideCursor();

}

void New_group_property_dialog::create_group_close(){
  create_group();
  accept();
}



/* ----------------------------------------------------- */



Modify_group_property_dialog::
Modify_group_property_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ), project_(proj) {

  if (name)
    setObjectName(name);

  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  grid_selector_ = new GridSelectorBasic(this,"GridSelector", proj);
  group_selector_ = new SinglePropertyGroupSelector(this);
  prop_selector_ = new OrderedPropertySelector(this);

  
  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* close = new QPushButton( "Create and Close", this);
  QPushButton* ok = new QPushButton( "Create", this);
  QPushButton* clear = new QPushButton( "Clear", this);
  QPushButton* cancel = new QPushButton( "Exit", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( clear ); 
  bottom_layout->addStretch();
   bottom_layout->addWidget( ok ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( close ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( cancel ); 
  bottom_layout->addStretch();

  main_layout->addWidget(new QLabel("Select Grid",this) );
  main_layout->addWidget(grid_selector_);
  main_layout->addStretch();

  main_layout->addWidget(new QLabel("Group to modify",this) );
  main_layout->addWidget(group_selector_);
  main_layout->addStretch();
  main_layout->addWidget( new QLabel("Properties") );
  main_layout->addWidget(prop_selector_);
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );


  QObject::connect( grid_selector_, SIGNAL( activated( const QString& ) ),
                    group_selector_, SLOT( show_property_groups( const QString& ) ) );
    
  QObject::connect( group_selector_, SIGNAL( activated( const QString& ) ),
                    this, SLOT( display_properties( const QString& ) ) );

  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( modify_group_property() ) );
  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( modify_group_property_close() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );
  /*QObject::connect( clear, SIGNAL( clicked() ),
                    this, SLOT( clear() ) );
*/
}


void Modify_group_property_dialog::
display_properties(const QString& group_name) {


  if( grid_selector_->currentText() ==  GridSelectorBasic::no_selection ) return;
  std::string grid_name = grid_selector_->currentText().toStdString();

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + grid_name );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr()) ;

  if(grid == 0) return;

  GsTLGridPropertyGroup* group = grid->get_group( group_name.toStdString() );
  if(group == 0) return;

  std::vector< std::string> props_in_group = group->property_names();

  QStringList propList;
  for(int i=0; i<props_in_group.size(); i++ ) propList.append( props_in_group[i].c_str() );

  prop_selector_->show_properties(QString( grid_name.c_str() ) );
  prop_selector_->set_selected_properties(propList );

}


void Modify_group_property_dialog::
modify_group_property( )  {

  if( grid_selector_->currentText() ==  GridSelectorBasic::no_selection ) return;
  std::string grid_name = grid_selector_->currentText().toStdString();

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + grid_name );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr()) ;

  if(grid == 0) return;


  QString group_name = group_selector_->currentText();
  if(group_name.isEmpty()) return;

  GsTLGridPropertyGroup* group = grid->get_group( group_name.toStdString() );
  if(group == 0) return;

  QStringList new_props = prop_selector_->selected_properties();

  std::vector< std::string> current_props_in_group = group->property_names();

  QStringList current_props;
  for(int i=0; i<current_props_in_group .size(); i++ ) 
    current_props.append( current_props_in_group [i].c_str() );

  current_props.sort();

  QStringList props_to_be_removed( current_props );

// Get the property to be remove
  for( int i=0; i<new_props.size() ; i++  ) {
    props_to_be_removed.removeOne( new_props.at( i ) );
  }
// Get the property to be added
  for( int i=0; i<current_props.size() ; i++  ) {
    new_props.removeOne( current_props.at( i ) );
  }

// Remove the properties
  for( int i=0; i<props_to_be_removed.size() ; i++  ) {
    group->remove_property(  grid->property( props_to_be_removed.at(i).toStdString() ) );
  }

// Add the properties
  for( int i=0; i<new_props.size() ; i++  ) {
    group->add_property(  grid->property( new_props.at(i).toStdString() ) );
  }

  project_->update(grid_name);
  
  return;


}


void Modify_group_property_dialog::
modify_group_property_close(){

  modify_group_property();
  accept();

}


/* ---------------------------- */

Delete_group_property_dialog::
Delete_group_property_dialog( GsTL_project* proj,QWidget* parent, const char* name )
  : QDialog( parent ), project_(proj) {

  if (name)
    setObjectName(name);

  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  grid_selector_ = new GridSelectorBasic(this,"GridSelector", proj);
  groups_selector_ = new MultiPropertyGroupSelector(this);
  
  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* close = new QPushButton( "Create and Close", this);
  QPushButton* ok = new QPushButton( "Create", this);
  QPushButton* clear = new QPushButton( "Clear", this);
  QPushButton* cancel = new QPushButton( "Exit", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( clear ); 
  bottom_layout->addStretch();
   bottom_layout->addWidget( ok ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( close ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( cancel ); 
  bottom_layout->addStretch();

  main_layout->addWidget(new QLabel("Select Grid",this) );
  main_layout->addWidget(grid_selector_);
  main_layout->addStretch();

  main_layout->addWidget(new QLabel("Group to remove",this) );
  main_layout->addWidget(groups_selector_);
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );


  QObject::connect( grid_selector_, SIGNAL( activated( const QString& ) ),
                    groups_selector_, SLOT( show_property_groups( const QString& ) ) );
    
  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( Delete_group_property() ) );
  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( Delete_group_property_close() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );
}
 

void Delete_group_property_dialog::
Delete_group_property(){

  if( grid_selector_->currentText() ==  GridSelectorBasic::no_selection ) return;
  std::string grid_name = grid_selector_->currentText().toStdString();

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + grid_name );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>(ni.raw_ptr()) ;

  if(grid == 0) return;

  QList<QListWidgetItem*>	groups =  groups_selector_->selectedItems();

  for(int i=0; i< groups.size(); i++) {
    grid->remove_group( groups.at(i)->text().toStdString() );
  }

  project_->update(grid_name);

}


void Delete_group_property_dialog::
Delete_group_property_close(){
  Delete_group_property();
  accept();
}