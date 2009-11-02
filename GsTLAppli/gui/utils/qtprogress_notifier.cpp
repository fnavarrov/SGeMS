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

#include <GsTLAppli/gui/utils/qtprogress_notifier.h>

#include <qprogressdialog.h>
#include <qnamespace.h>
//Added by qt3to4:
#include <QLabel>


Named_interface* QtProgress_notifier::create_new_interface( std::string& ) {
  return new QtProgress_notifier( 1, "no title" ); 
}

QtProgress_notifier::QtProgress_notifier( int total_steps,
                                          const std::string& title ) 
  : Progress_notifier( total_steps, title ),
    requested_( 0 ),
    steps_done_( 0 ) {
  
  frequency_ = 1;
  dialog_ = new QProgressDialog( "", "Abort", 0, total_steps, qApp->activeWindow());
  label_ = new Notifier_label( dialog_, 0, QString( title.c_str() ) );
  dialog_->setLabel( label_ );
  dialog_->setValue( 0 );
  dialog_->setMinimumDuration( 500 );
  QApplication::setOverrideCursor( Qt::WaitCursor );
}


QtProgress_notifier::~QtProgress_notifier() {
  dialog_->setValue( total_steps_ );
  delete dialog_;
  QApplication::restoreOverrideCursor();
  appli_message( "Notifier state: " << std::endl
		<< "total steps: " << total_steps_ << std::endl
		<< "requested: " << requested_ << std::endl
		<< "steps done: " << steps_done_ << std::endl );
}

void QtProgress_notifier::title( const std::string& str ) {
  label_->setHeader( QString( str.c_str() ) );
}

void QtProgress_notifier::total_steps( int count ) {
  total_steps_ = count;
  dialog_->setMaximum( count );
}
 
bool QtProgress_notifier::notify() {
//  if( ++requested_ % frequency_ != 0 ) return true;
  if( ++requested_ != frequency_ ) return true;

  requested_ = 0;
  dialog_->setValue( (++steps_done_)*frequency_ );
  qApp->processEvents();
  if( dialog_->wasCanceled() )
    return false;

  return true;
}


void QtProgress_notifier::write( const std::string& str, const Channel* ) {
  label_->setText( QString( str.c_str() ) );
}




//----------------------------

Notifier_label::Notifier_label( QWidget* parent, const char* name,
				const QString& header ) 
  : QLabel( parent ) {
  if(name)
    setObjectName(name);
  setTextFormat( Qt::RichText );
  header_ = "<b>" + header + "</b> <br>";
  QLabel::setText( header_ );
}


void Notifier_label::setText( const QString& text ) {
  QLabel::setText( header_ + text );
}

void Notifier_label::setHeader( const QString& text ) {
  header_ = "<b>" + text + "</b> <br>";
  QLabel::setText( header_ );
}
