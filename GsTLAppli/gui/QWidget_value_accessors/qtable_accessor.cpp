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

#include <GsTLAppli/gui/QWidget_value_accessors/qtable_accessor.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/string_manipulation.h>

#include <qstring.h>
#include <qdom.h>
#include <QModelIndex>
#include <QComboBox>

std::string QTable_accessor::row_sep = "\n";
std::string QTable_accessor::col_sep = " ";

QTable_accessor::QTable_accessor( QWidget* widget ) 
    : table_(dynamic_cast<QTableWidget*>(widget) ) {}

    
bool QTable_accessor::initialize( QWidget* widget ) {

  table_ = dynamic_cast<QTableWidget*>(widget);
  if( table_ == 0 )
    return false;
  
  return true;
}


std::string QTable_accessor::value() const {
  appli_assert( table_ );

  /* Scan the table line by line. Stop scanning a line
   * as soon as an empty cell is encountered.
   */
  std::string widget_name = String_Op::qstring2string(table_->objectName());
  std::string val;

  for( int row = 0 ; row < table_->rowCount(); row++) {
    int col=0;
    while( col < table_->columnCount() && table_->item( row, col )) {

      if (table_->item( row, col )->text().isEmpty()) break;
      
      QString text( table_->item( row, col )->text() );
      std::string std_text;
      QByteArray tmp = text.toLatin1();
      std_text = tmp.constData() ;
	
      val += std_text + col_sep ;
      col++;
    }
    if( row != table_->rowCount() - 1 )
      val += row_sep;
  }

  return "<" + widget_name + "  value=\"" + val + "\" /> \n";
}


bool QTable_accessor::set_value( const std::string& str ) {
  QString qstr( str.c_str() );
  
  // str is just an element of an xml file, hence can not be parsed
  // by QDomDocument. We need to add a root element.
  qstr = "<root>" + qstr + "</root>";
  QDomDocument doc;
  bool parsed = doc.setContent( qstr );
  appli_assert( parsed );

  QDomElement root_element = doc.documentElement();
  QDomElement elem = root_element.firstChild().toElement();
  //  QDomNode node = doc.firstChild();
  //  QDomElement elem = node.toElement();
  
  // In string "value", each row is separated by a new line and each
  // element of a row is separated by a tab
  QByteArray tmp = elem.attribute( "value" ).toLatin1();
  //appli_message( "value= " << tmp.constData() );

  std::string value( tmp.constData() ) ;
  String_Op::string_vector rows = 
    String_Op::decompose_string( value, row_sep, false );


  for( int i=0; i < rows.size() ; i++ ) {
    String_Op::string_vector row_elements = 
      String_Op::decompose_string( rows[i], col_sep, false );
    for( int j=0; j < row_elements.size(); j++ ) {
      QWidget * w = table_->indexWidget(table_->model()->index(i,j,QModelIndex()));

      if( w ) {
	QComboBox * item = dynamic_cast<QComboBox*>(w);
	if (item)
	  item->setItemText(item->currentIndex(), row_elements[j].c_str());
      }
      else {
	if (!table_->item(i,j))
	  table_->setItem(i,j,new QTableWidgetItem(""));
        table_->item(i,j)->setText( row_elements[j].c_str() );
      }
    }
  }
  return true;
}


void QTable_accessor::clear() {
  for( int i = 0; i < table_->rowCount() ; i++ ) {
    for( int j = 0; j < table_->columnCount() ; j++ ) {
      if (!table_->item(i,j)) continue;
      table_->item( i, j )->setText(QString());
    }
  }
}

Named_interface* QTable_accessor::create_new_interface(std::string&) {
  return new QTable_accessor(0);
}


