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

#include <GsTLAppli/gui/utils/multichoice_dialog.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>

#include <qpushbutton.h>
#include <qstringlist.h>
#include <qlabel.h>
#include <QHBoxLayout>

Multichoice_dialog::Multichoice_dialog( QWidget* parent, const char* name )
  : QDialog( parent ) {

  setupUi(this);
  if (name)
    setObjectName(name);

  QHBoxLayout * h = new QHBoxLayout();
  choice_list_box_->setLayout(h);
  choice_list_ = new MultiPropertySelector( choice_list_box_);

  //revisit - TL
  //choice_list_->setRowMode( Q3ListBox::FitToHeight );
  
  h->addWidget(choice_list_);
  
  QObject::connect( ok_button_, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( cancel_button_, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );
}


void Multichoice_dialog::set_label( const QString& label ) {
  label_->setText( label );
}

void Multichoice_dialog::set_okbutton_caption( const QString& label ) {
  ok_button_->setText( label );
}


void Multichoice_dialog::set_choice( const QStringList& list ) {
  choice_list_->addItems( list );
}

void Multichoice_dialog::add_choice_item( const QString& item ) {
  choice_list_->addItem( item );
}

QStringList Multichoice_dialog::selected_items() {
  QStringList list;
  for( unsigned int i = 0; i < choice_list_->count() ; i++ ) {
    if( choice_list_->item(i)->isSelected() && !choice_list_->item(i)->text().isEmpty() ) 
      list << choice_list_->item(i)->text( );
  }

  return list;
}
