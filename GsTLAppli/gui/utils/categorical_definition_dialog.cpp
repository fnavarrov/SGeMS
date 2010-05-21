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

#include <GsTLAppli/gui/utils/categorical_definition_dialog.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/extra/qtplugins/categorical_selectors.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/appli/manager_repository.h>
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


View_category_definition_dialog::
View_category_definition_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ) {

  if (name)
    setObjectName(name);

  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);

  main_layout->addWidget(new QLabel("Select definition",this) );
  def_selector_ = new CategoricalDefinitionSelector(this,"Categorical_definition");
  

  
  def_viewer_ = new CategoricalDefinitionViewer(this,"Definition_viewer");


  
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
  
  main_layout->addWidget(def_selector_);
  main_layout->addStretch();
  main_layout->addWidget( new QLabel("Code and name of values") );
  main_layout->addWidget(def_viewer_);
  main_layout->addStretch();
  main_layout->addWidget( new QLabel("Associated properties") );
  main_layout->addWidget(properties_viewer_);
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );


  QObject::connect( def_selector_, SIGNAL( activated( const QString& ) ),
                    def_viewer_, SLOT( show_definition( const QString& ) ) );
    
  QObject::connect( def_selector_, SIGNAL( activated( const QString& ) ),
                    this, SLOT( display_properties( const QString& ) ) );

  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
//  QObject::connect( close, SIGNAL( clicked() ),
//                    this, SLOT( reject() ) );

}


void View_category_definition_dialog::display_properties(const QString& def_name){
  if(current_definition_ == def_name) return;
  current_definition_ = def_name;

  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager+"/"+def_name.toStdString() );
  appli_assert( ni );

  properties_viewer_->document()->clear();
	CategoricalPropertyDefinitionName* cat_def = 
    dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());
  if( cat_def ) {
    CategoricalPropertyDefinition::property_set::const_iterator it = cat_def->begin_property();
    for( ; it != cat_def->end_property(); ++it) {
//        QTextLine line = properties_viewer_->createLine();
        properties_viewer_->append(QString((*it)->name().c_str()));
    }
  } 
  else {
//    QTextLine line = properties_viewer_->createLine();
    properties_viewer_->setText("Default naming convention");
  }

}



New_category_definition_dialog::
New_category_definition_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ) {

  if (name)
    setObjectName(name);

  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  cat_def_name_ = new QLineEdit(this);
  cat_names_text_ = new QTextEdit(this);
  cat_names_text_->setReadOnly(false);
  cat_names_text_->setUndoRedoEnabled(true);
//  properties_viewer_->setMaximumHeight(50);
  
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

  main_layout->addWidget(new QLabel("New definition name",this) );
  main_layout->addWidget(cat_def_name_);
  main_layout->addStretch();
  main_layout->addWidget( new QLabel("Enter category names") );
  main_layout->addWidget(cat_names_text_);
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );



  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( create_definition() ) );
  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( create_definition_close() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );
  QObject::connect( clear, SIGNAL( clicked() ),
                    this, SLOT( clear() ) );

}


void New_category_definition_dialog::clear(){
  cat_def_name_->clear();
  cat_names_text_->clear();
}


void New_category_definition_dialog::create_definition(){
    
  QStringList list  = cat_names_text_->toPlainText().split("\n");
//  QStringList parameters  = names.split("\n");
  list.prepend(cat_def_name_->text());

  QString sep = Actions::separator.c_str();
  std::string parameters = list.join( sep ).toStdString();

  QApplication::setOverrideCursor( Qt::WaitCursor );
 
  // call the CopyProperty action
  Error_messages_handler error_messages;

  std::string command( "NewCategoricalDefinition" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }

  QApplication::restoreOverrideCursor();

}

void New_category_definition_dialog::create_definition_close(){
  create_definition();
  accept();
}



/*
-------------------------------
*/


Assign_category_definition_dialog::
Assign_category_definition_dialog( GsTL_project* proj, QWidget* parent, const char* name )
  : QDialog( parent ), project_(proj) {

  if (name)
    setObjectName(name);

  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
 
  def_selector_ = new CategoricalDefinitionSelector(this,"Categorical_definition");
  grid_selector_ = new GridSelectorBasic(this,"grid selector",proj);
  props_selector_ = new MultiCategoricalPropertySelector(this,"Prop");

  
  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* assign_close = new QPushButton( "Assign and Close", this);
  QPushButton* assign = new QPushButton( "Assign", this);
  QPushButton* close = new QPushButton( "Close", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( assign ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( assign_close ); 
  bottom_layout->addStretch();
  bottom_layout->addWidget( close ); 
  bottom_layout->addStretch();

  main_layout->addWidget(new QLabel("Select definition to assign",this) );
  main_layout->addWidget(def_selector_);
  main_layout->addStretch();
  main_layout->addWidget( new QLabel("Select grid and properties") );
  main_layout->addWidget(grid_selector_);
  main_layout->addWidget( props_selector_ );
  main_layout->addStretch();
  main_layout->addLayout(bottom_layout);

  QObject::connect( grid_selector_, SIGNAL( activated(QString&) ),
                    props_selector_, SLOT( show_properties(const QString&) ) );


  QObject::connect( assign, SIGNAL( clicked() ),
                    this, SLOT( assign_definition() ) );
  QObject::connect( close, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( assign_close, SIGNAL( clicked() ),
                    this, SLOT( assign_definition() ) );
  QObject::connect( assign_close, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );

}



void Assign_category_definition_dialog::assign_definition(){

  Error_messages_handler error_messages;
  QString def_name = def_selector_->currentText();
  if(def_name.isEmpty()) {
    GsTLcerr << "A definition must be selected\n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
    return;
  }

  QString grid_name = grid_selector_->currentText();
  if(grid_name.isEmpty())  {
    GsTLcerr << "A grid must be selected\n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
    return;
  }

  QList<QListWidgetItem*> listWidget = props_selector_->selectedItems();
  if(listWidget.isEmpty())  {
    GsTLcerr << "At least one property must be selected\n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
    return;
  }
  QStringList list;
  for (int i = 0; i < listWidget.size(); ++i)
    list.append(listWidget.at(i)->text());

  list.prepend(grid_name);

  QString sep = Actions::separator.c_str();
  std::string parameters = list.join( sep ).toStdString();

  QApplication::setOverrideCursor( Qt::WaitCursor );
 
  std::string command( "AssignCategoricalDefinition" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
//update the property field
  props_selector_->show_properties(grid_name);
  QApplication::restoreOverrideCursor();

}