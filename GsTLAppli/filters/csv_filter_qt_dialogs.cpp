/**********************************************************************
** Author: Nicolas Remy
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
** All rights reserved.
**
** This file is part of the "filters" module of the Geostatistical Earth
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

#include <GsTLAppli/filters/csv_filter_qt_dialogs.h>
#include <GsTLAppli/filters/csv_filter.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/appli/manager_repository.h>

#include <qpushbutton.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qmessagebox.h>
#include <QTextStream>


#include <iostream>



Csv_infilter_dialog::Csv_infilter_dialog( QWidget* parent, const char* name )
: QDialog(parent),
  filter_( 0 ), 
  file_stream_( 0 ) {

  setupUi(this);
  SmartPtr<Named_interface> ni = 
      Root::instance()->interface( gslibInputFilters_manager );
  Manager* mng = dynamic_cast<Manager*>( ni.raw_ptr() );
  appli_assert( mng );

  Manager::type_iterator begin = mng->begin();
  Manager::type_iterator end = mng->end();
  for( ; begin != end ; ++begin ) {
    ObjectType->addItem( QString( begin->c_str() ) );
  }

  create_specialized_filter( ObjectType->currentText() );
  _back->setEnabled(false);
  
  ObjectType->setFocus();

  QObject::connect( ObjectType, SIGNAL(activated( const QString& )), 
		    this, SLOT( create_specialized_filter( const QString& ) ) );
  QObject::connect( _next, SIGNAL(clicked()), this, SLOT(nextClicked()));
  QObject::connect( _back, SIGNAL(clicked()), this, SLOT(backClicked()));
  QObject::connect( _cancel, SIGNAL(clicked()), this, SLOT(reject()));

}


Csv_infilter_dialog::~Csv_infilter_dialog(){
}

void Csv_infilter_dialog::nextClicked()
{
  if (_next->text() == "Finish")
    accept();
  else {
    _back->setEnabled(true);
    _next->setText("Finish");
    stackedWidget->setCurrentIndex(1);
  }
}

void Csv_infilter_dialog::backClicked()
{
  _next->setText("Next>");
  stackedWidget->setCurrentIndex(0);
  _back->setEnabled(false);
}

void Csv_infilter_dialog::set_file( std::ifstream& infile ) {
  file_stream_ = &infile;

  std::streampos mark = infile.tellg();

  QString text;
  std::string line;

  int count = 0;
  const int limit = 50;
 
  // Read up to "limit" lines
  while( std::getline( infile, line ) && count < limit ) {
    line += "\n";
    text.append( line.c_str() );
    count ++;
  } 
    
  text_preview_->setPlainText( text );
  
  // set the stream back to where it was
  infile.clear();
  infile.seekg( mark );
}


void 
Csv_infilter_dialog::create_specialized_filter( const QString& obj_type ) {
  if( obj_type.isEmpty() ) return;

  QByteArray tmp = obj_type.toLatin1();
  std::string type( tmp.constData() );

  if( filter_ ) {
    if( filter_->object_filtered() == type ) return;
  }


  _next->setFocus();

  SmartPtr<Named_interface> ni = 
      Root::instance()->interface( csvInputFilters_manager + "/" + type );
  
  if( ni.raw_ptr() == 0 ) {
    ni = Root::instance()->new_interface( type,
					  csvInputFilters_manager + "/" + type );
  }

  filter_ = dynamic_cast<Csv_specialized_infilter*>( ni.raw_ptr() );
  appli_assert( filter_ );

  // If a filter previously added a new page to the wizard, remove that page
  if( stackedWidget->count() > 1 )
    stackedWidget->removeWidget( stackedWidget->widget(1) );

  // ask the specialized filter to give its page widget. If widget is 0, 
  // enable Finish (ie there is no need for additional information).
  // if != 0, enable Next. 

  QWidget* page1_ = filter_->init_dialog( *file_stream_ );
  stackedWidget->addWidget(page1_);

  
}


void Csv_infilter_dialog::accept() {
  if( !filter_->has_valid_parameters() ) {
    QMessageBox::warning( this, "Missing parameters", 
                          "A name for the new object must be provided",
                          QMessageBox::Ok, Qt::NoButton,
                          Qt::NoButton );
  }
  else {
    QDialog::accept();
  }

}



//==============================================================
Csv_input_mgrid_dialog::Csv_input_mgrid_dialog( QWidget* parent, 
												   const char* name ) 
 : QWidget( parent )
{
        setupUi(this);



	name_->setFocus();
}


Csv_input_mgrid_dialog::Csv_input_mgrid_dialog(std::ifstream& infile, QWidget* parent, 
												   const char* name ) 
 : QWidget( parent )
{
        setupUi(this);



  std::streampos mark = infile.tellg();
  std::string str;
  std::getline(infile, str);
  QString qstr(str.c_str());

  QStringList property_names = qstr.split(",");

  X_col_name_->addItems(property_names);
  X_col_name_->addItem("None");
  Y_col_name_->addItems(property_names);
  Y_col_name_->addItem("None");
  Z_col_name_->addItems(property_names);
  Z_col_name_->addItem("None");


  //Set default selection
  X_col_name_->setCurrentIndex(0);
  Y_col_name_->setCurrentIndex(std::min(1,property_names.size()));
  Z_col_name_->setCurrentIndex(std::min(2,property_names.size())); 

  mask_col_name_->addItems(property_names);

	name_->setFocus();
} 

float Csv_input_mgrid_dialog::x_size() const {
  QString val = x_size_->text();
  return val.toFloat();
}
float Csv_input_mgrid_dialog::y_size() const{
  QString val = y_size_->text();
  return val.toFloat();
}
float Csv_input_mgrid_dialog::z_size() const{
  QString val = z_size_->text();
  return val.toFloat();
}
float Csv_input_mgrid_dialog::Ox() const{
  QString val = xmn_->text();
  return val.toFloat();
}
float Csv_input_mgrid_dialog::Oy() const{
  QString val = ymn_->text();
  return val.toFloat();
}
float Csv_input_mgrid_dialog::Oz() const{
  QString val = zmn_->text();
  return val.toFloat();
}

float Csv_input_mgrid_dialog::nx() const{
  return nx_->value();
}
float Csv_input_mgrid_dialog::ny() const{
  return ny_->value();
}
float Csv_input_mgrid_dialog::nz() const{
  return nz_->value();
}

QString Csv_input_mgrid_dialog::name() const {
  return name_->text();
}

QString Csv_input_mgrid_dialog::X_column_name() const {
  return X_col_name_->currentText();
}
QString Csv_input_mgrid_dialog::Y_column_name() const {
  return Y_col_name_->currentText();
}
QString Csv_input_mgrid_dialog::Z_column_name() const {
  return Z_col_name_->currentText();
}

QString Csv_input_mgrid_dialog::mask_column_name() const {
  return mask_col_name_->currentText();
}

int Csv_input_mgrid_dialog::X_column_index() const {
  return X_col_name_->currentIndex();
}
int Csv_input_mgrid_dialog::Y_column_index() const {
  return Y_col_name_->currentIndex();
}
int Csv_input_mgrid_dialog::Z_column_index() const {
  return Z_col_name_->currentIndex();
}

int Csv_input_mgrid_dialog::mask_column_index() const {
  return mask_col_name_->currentIndex();
}


bool Csv_input_mgrid_dialog::use_no_data_value() const {
  return use_no_data_value_->isChecked();
}

float Csv_input_mgrid_dialog::no_data_value() const {
  QString val = no_data_value_edit_->text();
  return val.toFloat();
}

//==============================================================

Csv_input_grid_dialog::Csv_input_grid_dialog( QWidget* parent, 
						  const char* name )
  : QWidget( parent ) {
  setupUi(this);
  name_->setFocus();
}

int Csv_input_grid_dialog::nx() const {
  return nx_->value();
}

int Csv_input_grid_dialog::ny() const {
  return ny_->value();
}

int Csv_input_grid_dialog::nz() const {
  return nz_->value();
}


float Csv_input_grid_dialog::x_size() const {
  QString val = x_size_->text();
  return val.toFloat();
}
float Csv_input_grid_dialog::y_size() const{
  QString val = y_size_->text();
  return val.toFloat();
}
float Csv_input_grid_dialog::z_size() const{
  QString val = z_size_->text();
  return val.toFloat();
}
float Csv_input_grid_dialog::Ox() const{
  QString val = xmn_->text();
  return val.toFloat();
}
float Csv_input_grid_dialog::Oy() const{
  QString val = ymn_->text();
  return val.toFloat();
}
float Csv_input_grid_dialog::Oz() const{
  QString val = zmn_->text();
  return val.toFloat();
}

QString Csv_input_grid_dialog::name() const {
  return name_->text();
}


bool Csv_input_grid_dialog::use_no_data_value() const {
  return use_no_data_value_->isChecked();
}

float Csv_input_grid_dialog::no_data_value() const {
  QString val = no_data_value_edit_->text();
  return val.toFloat();
}


//==========================================================

Csv_input_pointset_dialog::Csv_input_pointset_dialog( QWidget* parent , 
							  const char* name ) 
  : QWidget( parent ) {
  setupUi(this);
  name_->setFocus();
}
  
Csv_input_pointset_dialog::Csv_input_pointset_dialog( std::ifstream& infile,
							  QWidget* parent , 
							  const char* name ) 
  : QWidget( parent) {

  setupUi(this);

  std::streampos mark = infile.tellg();
  std::string str;
  std::getline(infile, str);
  QString qstr(str.c_str());

//  QTextStream inFileStream(infile,QIODevice::ReadWrite);
//  QString str;
//  inFileStream >> str;
//  inFileStream.readLine();
  QStringList property_names = qstr.split(",");


  X_col_name_->addItems(property_names);
  X_col_name_->addItem("None");
  Y_col_name_->addItems(property_names);
  Y_col_name_->addItem("None");
  Z_col_name_->addItems(property_names);
  Z_col_name_->addItem("None");


  //Set default selection
  X_col_name_->setCurrentIndex(0);
  Y_col_name_->setCurrentIndex(std::min(1,property_names.size()));
  Z_col_name_->setCurrentIndex(std::min(2,property_names.size()));  
  // make a preview of the file

  QString text;
  std::string line;

  int count = 0;
  const int limit = 50;

  // Read up to "limit" lines
  while( std::getline( infile, line ) && count < limit ) {
    line += "\n";
    text.append( line.c_str() );
    count ++;
  } 
    
  text_preview_->setPlainText( text );
  
  // set the stream back to where it was
  infile.clear();
  infile.seekg( mark );

  name_->setFocus();
}
  

QString Csv_input_pointset_dialog::name() const {
  return name_->text();
}
QString Csv_input_pointset_dialog::X_column_name() const {
  return X_col_name_->currentText();
}
QString Csv_input_pointset_dialog::Y_column_name() const {
  return Y_col_name_->currentText();
}
QString Csv_input_pointset_dialog::Z_column_name() const {
  return Z_col_name_->currentText();
}

int Csv_input_pointset_dialog::X_column_index() const {
  return X_col_name_->currentIndex();
}
int Csv_input_pointset_dialog::Y_column_index() const {
  return Y_col_name_->currentIndex();
}
int Csv_input_pointset_dialog::Z_column_index() const {
  return Z_col_name_->currentIndex();
}

bool Csv_input_pointset_dialog::use_no_data_value() const {
  return use_no_data_value_->isChecked();
}

float Csv_input_pointset_dialog::no_data_value() const {
  QString val = no_data_value_edit_->text();
  return val.toFloat();
}


