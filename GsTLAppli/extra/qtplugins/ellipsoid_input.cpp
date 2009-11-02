/**********************************************************************

** Author: Nicolas Remy

** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior

**   University

** All rights reserved.

**

** This file is part of the "extra" module of the Geostatistical Earth

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



#include <GsTLAppli/extra/qtplugins/ellipsoid_input.h>

#include <GsTLAppli/extra/qtplugins/gstl_table.h>



#include <qlayout.h>

#include <QResizeEvent>

#include <QVBoxLayout>

#include <QFrame>

#include <QScrollBar>

#include <iostream>



using namespace std;



EllipsoidInput::EllipsoidInput( QWidget *parent, const char *name ) 

  : QWidget( parent ) {



  if (name)

    setObjectName(name);



  QVBoxLayout* main_layout = new QVBoxLayout( this );



  ranges_table_ = new GsTLTable( this, "ranges" );

  angles_table_ = new GsTLTable( this, "angles" );

  main_layout->addWidget( ranges_table_ );

  main_layout->addSpacing( 4 );

  main_layout->addWidget( angles_table_ );



  ranges_table_->setMinimumWidth( 150 );

  angles_table_->setMinimumWidth( 150 );



  ranges_table_->setRowCount( 1 );

  ranges_table_->setColumnCount( 3 );

  angles_table_->setRowCount( 1 );

  angles_table_->setColumnCount( 3 );



  ranges_table_->setRowHeaders("Ranges");

  ranges_table_->setColHeaders("Max;Med;Min");



  angles_table_->setRowHeaders("Angles");

  angles_table_->setColHeaders("Azimuth;Dip;Rake");



  for( int i = 0; i < 3; i++ ) {

    ranges_table_->setColumnWidth( i, 65 );

    angles_table_->setColumnWidth( i, 65 );

  }



  ranges_table_->setMaximumHeight( 55 );

  ranges_table_->setFrameShape( QFrame::NoFrame );

  ranges_table_->setFrameShadow( QFrame::Plain );



  angles_table_->setMaximumHeight( 55 );

  angles_table_->setFrameShape( QFrame::NoFrame );

  angles_table_->setFrameShadow( QFrame::Plain );



  angles_table_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  angles_table_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  ranges_table_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  ranges_table_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  



}







EllipsoidInput::~EllipsoidInput() {}



void EllipsoidInput::ranges( double& r1, double& r2, double& r3 ) {

  if (ranges_table_->item(0,0))

    r1 = ranges_table_->item(0,0)->text().toDouble();

  else r1 = 0;

  

  if (ranges_table_->item(0,1))

    r2 = ranges_table_->item( 0,1 )->text().toDouble();

  else

    r2 = 0;



  if (ranges_table_->item(0,2))

    r3 = ranges_table_->item( 0,2 )->text().toDouble();

  else

    r3 = 0;

}

 



double EllipsoidInput::max_range() const {

  if (!ranges_table_->item(0,0))

    return 0;

  return ranges_table_->item(0,0)->text( ).toDouble();  

}

double EllipsoidInput::med_range() const {

  if (!ranges_table_->item(0,1))

    return 0;

  return ranges_table_->item(0,1)->text( ).toDouble();  

}

double EllipsoidInput::min_range() const{

  if (!ranges_table_->item(0,2))

    return 0;

  return ranges_table_->item(0,2)->text( ).toDouble();  

}



void EllipsoidInput::angles( double& a1, double& a2, double& a3 ) {

  if (angles_table_->item(0,0))

    a1 = angles_table_->item(0,0)->text( ).toDouble();

  else

    a1 = 0;



  if (angles_table_->item(0,1))

    a2 = angles_table_->item( 0,1 )->text().toDouble();

  else

    a2 = 0;



  if (angles_table_->item(0,2))

    a3 = angles_table_->item( 0,2 )->text().toDouble();

  else

    a3 = 0;

}



double EllipsoidInput::azimuth() const {

  if (!angles_table_->item(0,0))

    return 0;

  return angles_table_->item(0,0)->text( ).toDouble();  

}

double EllipsoidInput::dip() const {

  if (!angles_table_->item(0,1))

    return 0;

  

  return angles_table_->item( 0,1 )->text().toDouble();  

}

double EllipsoidInput::rake() const { 

  if (!angles_table_->item(0,2))

    return 0;

 

  return angles_table_->item( 0,2 )->text().toDouble();

  

}



void EllipsoidInput::set_ranges( double r1, double r2, double r3 ) {

  QString val;



  if (!ranges_table_->item(0,0))

    ranges_table_->setItem(0,0,new QTableWidgetItem(""));

  if (!ranges_table_->item(0,1))

    ranges_table_->setItem(0,1,new QTableWidgetItem(""));

  if (!ranges_table_->item(0,2))

    ranges_table_->setItem(0,2,new QTableWidgetItem(""));



  val.setNum( r1 );

  ranges_table_->item(0,0)->setText(  val );

  val.setNum( r2 );

  ranges_table_->item(0,1)->setText(  val );

  val.setNum( r3 );

  ranges_table_->item(0,2)->setText(  val );

}

void EllipsoidInput::set_angles( double r1, double r2, double r3 ) {

  QString val;

  val.setNum( r1 );



  if (!angles_table_->item(0,0))

    angles_table_->setItem(0,0,new QTableWidgetItem(""));

  if (!angles_table_->item(0,1))

    angles_table_->setItem(0,1,new QTableWidgetItem(""));

  if (!angles_table_->item(0,2))

    angles_table_->setItem(0,2,new QTableWidgetItem(""));

  

  angles_table_->item(0,0)->setText( val );

  val.setNum( r2 );

  angles_table_->item(0,1)->setText(  val );

  val.setNum( r3 );

  angles_table_->item(0,2)->setText(  val );

}





void EllipsoidInput::set_max_range( double a ) {

  QString val;

  val.setNum( a );

  

  if (!ranges_table_->item(0,0))

    ranges_table_->setItem(0,0,new QTableWidgetItem(""));

  

  ranges_table_->item(0,0)->setText( val ); 

}



void EllipsoidInput::set_med_range( double a ) {

  QString val;

  val.setNum( a );

  

  if (!ranges_table_->item(0,1))

    ranges_table_->setItem(0,1,new QTableWidgetItem(""));



  ranges_table_->item(0,1)->setText( val ); 

}

void EllipsoidInput::set_min_range( double a ) {

  QString val;

  val.setNum( a );



  if (!ranges_table_->item(0,2))

    ranges_table_->setItem(0,2,new QTableWidgetItem(""));



  ranges_table_->item(0,2)->setText( val ); 

}





void EllipsoidInput::set_azimuth( double a ) {

  QString val;

  val.setNum( a );



  if (!angles_table_->item(0,0))

    angles_table_->setItem(0,0,new QTableWidgetItem(""));



  angles_table_->item(0,0)->setText( val ); 

}

void EllipsoidInput::set_dip( double a ) {

  QString val;

  val.setNum( a );



  if (!angles_table_->item(0,1))

    angles_table_->setItem(0,1,new QTableWidgetItem(""));

  

  angles_table_->item(0,1)->setText( val ); 

}

void EllipsoidInput::set_rake( double a ) {

  QString val;

  val.setNum( a );



  if (!angles_table_->item(0,2))

    angles_table_->setItem(0,2,new QTableWidgetItem(""));



  angles_table_->item(0,2)->setText(  val ); 

}







void EllipsoidInput::resizeEvent( QResizeEvent * e ) {

  const int label_width = 70;

  int cell_width = ( ranges_table_->size().width() - label_width ) / 3 - 2;



  for( int i = 0; i < 3; i++ ) {

    ranges_table_->setColumnWidth( i, cell_width );

    angles_table_->setColumnWidth( i, cell_width );

  }

  QWidget::resizeEvent( e );

}



void EllipsoidInput::set_max_width( int w ) {

  ranges_table_->setMaximumWidth( w );

  angles_table_->setMaximumWidth( w ); 



  const int label_width = 70;

  int cell_width = ( ranges_table_->size().width() - label_width ) / 3 - 2;



  for( int i = 0; i < 3; i++ ) {

    ranges_table_->setColumnWidth( i, cell_width );

    angles_table_->setColumnWidth( i, cell_width );

  }



}

