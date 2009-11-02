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

#include <GsTLAppli/gui/variogram2/variogram_controls.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/gui/utils/gstl_slider.h>
#include <GsTLAppli/math/angle_convention.h>

#include <GsTL/geometry/geometry_algorithms.h>

#include <QGridLayout>
#include <qfiledialog.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qdom.h>
//Added by qt3to4:
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

#include <fstream>



#include <qpushbutton.h>
#include <qlayout.h>

using namespace String_Op;

Variogram_controls::
Variogram_controls( Covariance<GsTLPoint>* model, 
                    QWidget* parent, const char* name,
                    double default_max_range )
  : QWidget( parent ), default_max_range_(default_max_range) {

  model_ = model ;

  if (name)
    setObjectName(name);
  
  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(12);
  main_layout->setSpacing(9);
  setLayout(main_layout);
  

  QLabel* title = new QLabel( "<b>Variogram Model</b>", this);
  title->setAlignment( Qt::AlignHCenter | Qt::AlignVCenter);
//  title_layout->addStretch();
//  title_layout->addWidget( title );
//  title_layout->addStretch();

  main_layout->addWidget( title );
  main_layout->addSpacing( 12 );

  QHBoxLayout* nugget_layout = 
    new QHBoxLayout( );
  main_layout->addLayout(nugget_layout);
  
  QLabel* nugget_label = new QLabel( "Nugget Effect", this);
  nugget_effect_edit_ = new QLineEdit( this);
  nugget_effect_edit_->setText("0");
  nugget_layout->addStretch();
  nugget_layout->addWidget( nugget_label );
  nugget_layout->addWidget( nugget_effect_edit_ );
  nugget_layout->addStretch();

  QHBoxLayout* struct_count_layout = 
    new QHBoxLayout( );
  main_layout->addLayout(struct_count_layout);
  QLabel* count_label = 
    new QLabel( "Nb. of Structures", this);
  structures_count_ = new QSpinBox( this);
  structures_count_->setValue( 1 );
  struct_count_layout->addStretch();
  struct_count_layout->addWidget( count_label );
  struct_count_layout->addWidget( structures_count_ );
  struct_count_layout->addStretch();
    
  //structures_frame_ = new QFrame( this);
  _structures_layout = new QVBoxLayout();
  //structures_frame_->setLayout(vbox);
  
  //structures_frame_->setFrameShape( QFrame::NoFrame );
  _structures_layout->setSpacing( 8 );
  _structures_layout->setMargin( 1 );

  main_layout->addLayout( _structures_layout );


  // Make one structure by default
  Line_separator* separator1 = 
    new Line_separator( "Structure 1",this, "struct_sep1" );
  Variogram_structure_controls* struct1 = 
    new Variogram_structure_controls( model,this, "struct1", 
                                      default_max_range_ );

  _structures_layout->addWidget(separator1);
  _structures_layout->addWidget(struct1);
  

  QObject::connect( struct1, SIGNAL( variogram_structure_changed() ),
	              		this, SIGNAL( variogram_changed() ) );

  std::vector<std::string> types=model_->available_types();

  int id = model_->add_structure(types[0]);
  double azh=0.0, dip=0.0, rake=0.0;
  convert_to_math_standard_angles_rad( azh, dip, rake );
  model_->set_angles( id, azh, dip, rake );

  struct1->set_id(id);

  structures_.push_back( std::make_pair( separator1, struct1 ) );
      

  QObject::connect( structures_count_, SIGNAL( valueChanged( int ) ),
            		    this, SLOT( update_structures_count( int ) ) );
  QObject::connect( nugget_effect_edit_, SIGNAL( textChanged(const QString & )),
			              this, SLOT( nugget_changed(const QString & ) ));
/*
  QObject::connect( load_button, SIGNAL( clicked() ),
			              this, SLOT( load_model() ) );
  QObject::connect( save_button, SIGNAL( clicked() ),
			              this, SLOT( save_model() ) );
*/
}


void Variogram_controls::update_structures_count(int val ) {
  int current_count = structures_.size();
  QString tmp;
  
  if( current_count < val ) {
    
    // add one (or more) new structure(s)
    for( int i=0; i < val - current_count; i ++ ) {
      QString count_str;
      count_str.setNum( current_count + i + 1 );
      tmp = "struct_sep" + count_str;
      
      Line_separator* separator =
      	new Line_separator( "Structure " + count_str,
			    this, qstring2string(tmp).c_str() );
      Variogram_structure_controls* structure = 
	      new Variogram_structure_controls( model_,this, 
						qstring2string(tmp).c_str(), 
						default_max_range_ );

      _structures_layout->addWidget(separator);
      _structures_layout->addWidget(structure);
      
      QObject::connect( structure, SIGNAL( variogram_structure_changed() ),
			this, SIGNAL( variogram_changed() ) );

      std::vector<std::string> types=model_->available_types(); 
      int id=model_->add_structure(types[0]);
      structure->set_id(id);
      double azh=0.0, dip=0.0, rake=0.0;
      convert_to_math_standard_angles_rad( azh, dip, rake );
      model_->set_angles( id, azh, dip, rake );

      
      // Tell variogram function to add new structure
      //....
      
      structure->show();
      separator->show();
      structures_.push_back( std::make_pair( separator, structure ) );
    }
  }
  else {
    // remove one (or more) structure(s)
    for( int j = current_count-1; j >= val  ; j -- ) {
      delete structures_[ j ].first;
      delete structures_[ j ].second;
      structures_.pop_back();
      model_->remove_structure(j);
      
    }
  }
  emit variogram_changed();
}


void Variogram_controls:: nugget_changed(const QString &s)
{
    
    model_->nugget(s.toFloat());
    emit variogram_changed();
}
	  

float Variogram_controls::nugget() const {
  QString val = nugget_effect_edit_->text();
  return val.toFloat();
}


int Variogram_controls::structures_count() const {
  return structures_count_->value();
}

const Variogram_structure_controls* Variogram_controls::structure( int id ) const {
  if( id >= int( structures_.size() ) ) return 0;

  return structures_[id].second;
}

Variogram_structure_controls* Variogram_controls::structure( int id ) {
  if( id >= int( structures_.size() ) ) return 0;

  return structures_[id].second;
}


void Variogram_controls::load_model() {
  QString filename = 
    QFileDialog::getOpenFileName( this,"Load Variogram Model");

  
  if( filename == QString::null ) return;

  // Open the file and put the content into a string (using a stringstream)
  QFile file( filename );
  if ( !file.open( QIODevice::ReadOnly ) ) {
    GsTLcerr << "Can't open file " << qstring2string(filename) << "\n" << gstlIO::end;
    return;
  }

  QTextStream stream( &file );
  QString qstr = stream.readAll();
  
  QDomDocument doc;
  bool parsed = doc.setContent( qstr );
  appli_assert( parsed );

  QDomElement root_element = doc.documentElement();
  
  // Get the nugget value and the number of structures
  QString val = root_element.attribute( "nugget" );
  nugget_effect_edit_->setText( val );
  val = root_element.attribute( "structures_count" );
  structures_count_->setValue( val.toInt() );

//  QDomElement elem = root_element;

  // work on each structure
  for( unsigned int i=0; i < structures_.size() ; i++ ) {
    Variogram_structure_controls* structure = structures_[i].second;
    double r1,r2,r3;
    double a1, a2, a3;
    double sill;
    QString type;

    // Get the node describing the structure and initialize the contribution
    // and variogram type values
    QString id;
    id.setNum( i+1 );
    QString structure_tagname = "structure_" + id;
    QDomNodeList nodes = root_element.elementsByTagName( structure_tagname );
    if( nodes.count() == 0 ) {
      appli_warning( "No element called \"" <<  qstring2string(structure_tagname) << "\"" << std::endl
		    << "Aborting" );
      return;
    }
    QDomNode structure_node = nodes.item(0);
    appli_assert( structure_node.isElement() );
    QDomElement structure_elem = structure_node.toElement();

    val = structure_elem.attribute( "contribution" );
    sill = val.toFloat();
    type = structure_elem.attribute( "type" );


    // Get the ranges
    QDomNodeList ranges_node_list = structure_elem.elementsByTagName( "ranges" );
    if( ranges_node_list.count() == 0 ) {
      appli_warning( "No element called \"ranges\"" << std::endl
		    << "Aborting" );
      return;
    }
    QDomNode ranges_node = ranges_node_list.item(0);
    appli_assert( ranges_node.isElement() );
    QDomElement ranges_elem = ranges_node.toElement();
    
    val = ranges_elem.attribute( "max" );
    r1 = val.toFloat();
    val = ranges_elem.attribute( "medium" );
    r2 = val.toFloat();
    val = ranges_elem.attribute( "min" );
    r3 = val.toFloat();

    
    // Get the angles
    QDomNodeList angles_node_list = structure_elem.elementsByTagName( "angles" );
    if( angles_node_list.count() == 0 ) {
      appli_warning( "No element called \"angles\"" << std::endl
		    << "Aborting" );
      return;
    }
    QDomNode angles_node = angles_node_list.item(0);
    appli_assert( angles_node.isElement() );
    QDomElement angles_elem = angles_node.toElement();
    
    val = angles_elem.attribute( "x" );
    a1 = val.toFloat();
    val = angles_elem.attribute( "y" );
    a2 = val.toFloat();
    val = angles_elem.attribute( "z" );
    a3 = val.toFloat();

    structure->set_structure( sill, type, r1, r2, r3, a1, a2, a3 );
  }

}



void Variogram_controls::save_model() {
  QString filename = 
    QFileDialog::getSaveFileName( this, "Save Variogram Model");

  
  if( filename == QString::null ) return;

  // Open the file and put the content into a string (using a stringstream)
  std::ofstream out( qstring2string(filename).c_str() );
  if( !out ) {
    GsTLcerr << "Can't open file " << qstring2string(filename) << "\n" << gstlIO::end;
    return;
  }
 
  // Write the nugget effect and the number of structures
  out << "<variogram_model  "
      << "nugget=\"" <<  qstring2string(nugget_effect_edit_->text()) << "\" "
      << "structures_count=\"" << structures_count_->value() << "\"  >"
	 << std::endl;
  
  // Write the info about each structure
  for( unsigned int i=0; i < structures_.size() ; i++ ) {
    Variogram_structure_controls* structure = structures_[i].second;
    double r1,r2,r3;
    structure->ranges( r1, r2, r3 );

    double a1, a2, a3;
    structure->angles( a1, a2, a3 );

    out << "  <structure_" << i+1 << "  "
	   << "contribution=\"" << structure->sill() << "\"  " 
	<< "type=\"" << qstring2string(structure->type()) << "\"   >" 
	   << std::endl
	   << "    <ranges max=\"" << r1 << "\"  "
	   << "medium=\"" << r2 << "\"  "
	   << "min=\"" << r3 << "\"   />"
	   << std::endl
	   << "    <angles x=\"" << a1 << "\"  "
	   << "y=\"" << a2 << "\"  "
	   << "z=\"" << a3 << "\"   />"
	   << std::endl
	   << "  </structure_" << i+1 << ">"
	   << std::endl; 
  }
  
  out << "</variogram_model>" << std::endl;
}







//====================================================

Variogram_structure_controls::
Variogram_structure_controls( Covariance<GsTLPoint>* model,QWidget* parent, const char* name,
                              double default_max_range ) 
  : QWidget( parent ) {

  setupUi(this);
  if (name)
    setObjectName(name);
  
  model_=model;

  sill_value_->setText("1");

  ang1_->setText("0");
  ang2_->setText("0");
  ang3_->setText("0");

  QGridLayout * g = new QGridLayout();
  ranges_box_->setLayout( g);


  g->addWidget(new QLabel( "Max", ranges_box_ ), 0, 0);
  g->addWidget(new QLabel( "Med", ranges_box_ ), 1, 0);
  g->addWidget(new QLabel( "Min", ranges_box_ ), 2, 0);
 
  range_slider_1_ = new GsTL_slider( 0.0, default_max_range, 0.0, default_max_range, 
                                     "", ranges_box_, "slider1" );
  range_slider_2_ = new GsTL_slider( 0.0, default_max_range, 0.0, default_max_range, 
                                     "", ranges_box_, "slider2" );
  range_slider_3_ = new GsTL_slider( 0, default_max_range, 0, default_max_range, 
                                     "", ranges_box_, "slider3" );

  g->addWidget(range_slider_1_, 0,1);
  g->addWidget(range_slider_2_, 1,1);
  g->addWidget(range_slider_3_, 2,1);


  QObject::connect( range_slider_1_, SIGNAL( maxValueChanged( double ) ),
                    range_slider_2_, SLOT( setMaxValue( double ) ) );
  QObject::connect( range_slider_2_, SIGNAL( maxValueChanged( double ) ),
                    range_slider_3_, SLOT( setMaxValue( double ) ) );
  QObject::connect( range_slider_3_, SIGNAL( maxValueChanged( double ) ),
                    range_slider_1_, SLOT( setMaxValue( double ) ) );

  
/*
  QObject::connect( range_slider_1_,SIGNAL( valueChanged(int) ),
	   this,SLOT(range_changed(int ) ) );
  QObject::connect( range_slider_2_,SIGNAL( valueChanged(int) ),
		   this,SLOT(range_changed(int ) ) );
  QObject::connect( range_slider_3_,SIGNAL( valueChanged(int) ),
		   this,SLOT(range_changed(int ) ) );
*/
  QObject::connect( range_slider_1_,SIGNAL( valueChanged(double) ),
	   this,SLOT(range1_changed(double ) ) );
  QObject::connect( range_slider_2_,SIGNAL( valueChanged(double) ),
		   this,SLOT(range2_changed(double ) ) );
  QObject::connect( range_slider_3_,SIGNAL( valueChanged(double) ),
		   this,SLOT(range3_changed(double ) ) );

   
  QObject::connect( ang1_,SIGNAL( textChanged(const QString& ) ),
	   this,SLOT(angle_changed(const QString&  ) ) );
  QObject::connect( ang2_,SIGNAL( textChanged(const QString& ) ),
	   this,SLOT(angle_changed(const QString&  ) ) );
  QObject::connect( ang3_,SIGNAL( textChanged(const QString&) ),
	   this,SLOT(angle_changed( const QString&) ) );


  QObject::connect( sill_value_,SIGNAL( textChanged(const QString& ) ),
	   this,SLOT(sill_changed( const QString& ) ) );


  QObject::connect( model_type_,SIGNAL( activated(const QString& ) ),
	   this,SLOT(type_changed( const QString& ) ) );

}
 



void Variogram_structure_controls::set_id(int id)
{
    id_=id;
}



void Variogram_structure_controls::range_changed(double d)
{
    
  if( range_slider_3_->value() > range_slider_2_->value() )
  	range_slider_3_->setValue( range_slider_2_->value() );
    
  if( range_slider_2_->value() > range_slider_1_->value() )
  	range_slider_2_->setValue( range_slider_1_->value() );
    
  model_->set_ranges(id_, range_slider_1_->value(),
	          	       range_slider_2_->value(),
	                   range_slider_3_->value() );

  emit variogram_structure_changed();
}



//------------------------------------
// trying...

void Variogram_structure_controls::range1_changed( double )
{   
  if( range_slider_2_->value() > range_slider_1_->value() )
  	range_slider_2_->setValue( range_slider_1_->value() );

  if( range_slider_3_->value() > range_slider_2_->value() )
  	range_slider_3_->setValue( range_slider_2_->value() );
    
    
  model_->set_ranges(id_, range_slider_1_->value(),
	          	       range_slider_2_->value(),
	                   range_slider_3_->value() );

//  double a,b,c;
//  model_->get_ranges(id_,a,b,c);

  emit variogram_structure_changed();
}

void Variogram_structure_controls::range2_changed( double )
{    
  if( range_slider_3_->value() > range_slider_2_->value() )
  	range_slider_3_->setValue( range_slider_2_->value() );
    
  if( range_slider_2_->value() > range_slider_1_->value() )
  	range_slider_1_->setValue( range_slider_2_->value() );
    
  model_->set_ranges(id_, range_slider_1_->value(),
	          	       range_slider_2_->value(),
	                   range_slider_3_->value() );

//  double a,b,c;
//  model_->get_ranges(id_,a,b,c);

  emit variogram_structure_changed();
}

void Variogram_structure_controls::range3_changed( double )
{
    
  if( range_slider_3_->value() > range_slider_2_->value() )
  	range_slider_2_->setValue( range_slider_3_->value() );
    
  if( range_slider_2_->value() > range_slider_1_->value() )
  	range_slider_1_->setValue( range_slider_2_->value() );
    
  model_->set_ranges(id_, range_slider_1_->value(),
	          	       range_slider_2_->value(),
	                   range_slider_3_->value() );

//  double a,b,c;
//  model_->get_ranges(id_,a,b,c);

  emit variogram_structure_changed();
}

//------------------------------------




void Variogram_structure_controls::sill_changed(const QString &s)
{
//    cout<<"SILL CHANGED "<< s.toDouble()<<endl;
    model_->sill(id_,s.toDouble());
    emit variogram_structure_changed();
    
   
}



void Variogram_structure_controls::angle_changed(const QString &s)
{
  double a1 = degree_to_radian( ang1_->text().toDouble() );
  double a2 = degree_to_radian( ang2_->text().toDouble() );
  double a3 = degree_to_radian( ang3_->text().toDouble() );
  convert_to_math_standard_angles_rad( a1, a2, a3 );

  model_->set_angles(id_, a1, a2, a3 );
    
  emit variogram_structure_changed();
}


void Variogram_structure_controls::type_changed(const QString &s)
{    
    std::string str(qstring2string(s));
    model_->set_type(id_,str);  
    emit variogram_structure_changed();
}



void Variogram_structure_controls::
set_structure( double sill, const QString& type,
               double range1, double range2, double range3,
               double angle1, double angle2, double angle3 ) {
  QString str;
  str.setNum( sill );
  sill_value_->setText( str );

  int i = 0;
  for( ; i < model_type_->count() ; i++ ) {
    if( model_type_->itemText( i ) == type ) break;
  }
  model_type_->setCurrentIndex( i );
  
  str.setNum( angle1 );
  ang1_->setText( str );
  str.setNum( angle2 );
  ang2_->setText( str );
  str.setNum( angle3 );
  ang3_->setText( str );

  range_slider_1_->setValue( int( range1 ) );
  range_slider_2_->setValue( int( range2 ) );
  range_slider_3_->setValue( int( range3 ) );

  model_->set_type( id_, qstring2string(type) );
  model_->sill(id_, sill );
  model_->set_ranges( id_, range1, range2, range3 );

  convert_to_math_standard_angles_degree( angle1, angle2, angle3 );
  model_->set_angles( id_, degree_to_radian( angle1 ), 
                           degree_to_radian( angle2 ),
                           degree_to_radian( angle3 ) );

  emit variogram_structure_changed();
}


double Variogram_structure_controls::sill() const {
  return sill_value_->text().toDouble();
}

void Variogram_structure_controls::
ranges( double& range1, double& range2, double& range3 ) {
  range1 = range_slider_1_->value();
  range2 = range_slider_2_->value();
  range3 = range_slider_3_->value();
}

void Variogram_structure_controls::
angles( double& angle1, double& angle2, double& angle3 ) {
  angle1 = ang1_->text().toDouble();
  angle2 = ang2_->text().toDouble();
  angle3 = ang3_->text().toDouble();
}



QString Variogram_structure_controls::type() const {
  return model_type_->currentText();
}








/*

void Variogram_structure_controls::set_ranges( float max, float medium, float min ) {
  QString val;

  val.setNum( max );
  anisotropy_table_->setText( 0,0,val );

  val.setNum( medium );
  anisotropy_table_->setText( 0,1,val );

  val.setNum( min );
  anisotropy_table_->setText( 0,2,val );

  emit anisotropy_value_changed();
}

void Variogram_structure_controls::ranges( float& max, 
					float& medium, float& min ) const {
  QString val = anisotropy_table_->text( 0,0 );
  max = val.toFloat();
  
  val = anisotropy_table_->text( 0,1 );
  medium = val.toFloat();
  
  val = anisotropy_table_->text( 0,2 );
  min = val.toFloat();
}


void Variogram_structure_controls::max_range( float a ) {
  QString val;
  val.setNum( a );
  anisotropy_table_->setText( 0,0,val );

  emit anisotropy_value_changed();
}


float Variogram_structure_controls:: max_range() const {
  QString val = anisotropy_table_->text( 0,0 );
  return val.toFloat();
}

void Variogram_structure_controls::medium_range( float a ) {
  QString val;
  val.setNum( a );
  anisotropy_table_->setText( 0,1,val );

  emit anisotropy_value_changed();
}

float Variogram_structure_controls::medium_range() const {
  QString val = anisotropy_table_->text( 0,1 );
  return val.toFloat();
}


void Variogram_structure_controls::min_range( float a ) {
  QString val;
  val.setNum( a );
  anisotropy_table_->setText( 0,2,val );

  emit anisotropy_value_changed();
}

float Variogram_structure_controls::min_range() const {
  QString val = anisotropy_table_->text( 0,2 );
  return val.toFloat();
}




void Variogram_structure_controls::set_angles( float max, float medium, float min ) {
  QString val;

  val.setNum( max );
  anisotropy_table_->setText( 1,0,val );

  val.setNum( medium );
  anisotropy_table_->setText( 1,1,val );

  val.setNum( min );
  anisotropy_table_->setText( 1,2,val );

  emit anisotropy_value_changed();
}

void Variogram_structure_controls::angles( float& max,
					float& medium, float& min ) const {
  QString val = anisotropy_table_->text( 1,0 );
  max = val.toFloat();
  
  val = anisotropy_table_->text( 1,1 );
  medium = val.toFloat();
  
  val = anisotropy_table_->text( 1,2 );
  min = val.toFloat();
}

void Variogram_structure_controls::x_angle( float a ) {
  QString val;
  val.setNum( a );
  anisotropy_table_->setText( 1,0,val );

  emit anisotropy_value_changed();
}

float Variogram_structure_controls::x_angle() const {
  QString val = anisotropy_table_->text( 1,0 );
  return val.toFloat();
}


void Variogram_structure_controls::y_angle( float a ) {
  QString val;
  val.setNum( a );
  anisotropy_table_->setText( 1,1,val );

  emit anisotropy_value_changed();
}

float Variogram_structure_controls::y_angle() const {
  QString val = anisotropy_table_->text( 1,1 );
  return val.toFloat();
}


void Variogram_structure_controls::z_angle( float a ) {
  QString val;
  val.setNum( a );
  anisotropy_table_->setText( 1,2,val );

  emit anisotropy_value_changed();
}

float Variogram_structure_controls::z_angle() const {
  QString val = anisotropy_table_->text( 1,2 );
  return val.toFloat();
}
  

void Variogram_structure_controls::contribution_change_slot( const QString& val ) {
  float c = val.toFloat();
  emit contribution_changed( c );
}


void Variogram_structure_controls::set_contribution( float c ) {
  QString val;
  val.setNum( c );
  contribution_edit_->setText( val );
}

float Variogram_structure_controls::contribution() const {
  QString val = contribution_edit_->text();
  return val.toFloat();
}


QString Variogram_structure_controls::variogram_type() const {
  return type_selector_->currentText().latin1(); 
}


void Variogram_structure_controls::set_variogram_type( const QString& type ) {
  type_selector_->setCurrentText( type );
} 
*/

//==============================================================

Line_separator::Line_separator( const QString& label, 
				QWidget* parent, const char* name ) 
  : QWidget( parent ) {

  if (name)
    setObjectName(name);
  
  QHBoxLayout* layout = new QHBoxLayout( this );
  setLayout(layout);
  
  QLabel* separator_label = new QLabel( label, this );
  QFont font;
  font.setBold( true );
  separator_label->setFont( font );

  QSizePolicy label_policy( QSizePolicy::Fixed, QSizePolicy::Fixed );
  separator_label->setSizePolicy( label_policy );
  
  QFrame* line = new QFrame( this);
  line->setFrameShape( QFrame::Box );
  line->setFrameShadow( QFrame::Raised );
  QSizePolicy line_policy( QSizePolicy::Expanding, QSizePolicy::Fixed );
  line->setSizePolicy( line_policy );
  
  layout->addWidget( separator_label );
  layout->addWidget( line );
  
}
