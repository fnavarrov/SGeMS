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

#include <GsTLAppli/extra/qtplugins/gstl_table.h>

#include <qevent.h>
#include <qclipboard.h>
#include <qapplication.h>
#include <QKeyEvent>
#include <QTableWidgetItem>

GsTLTable::GsTLTable( QWidget *parent, const char *name )
  : QTableWidget(parent) {
  if (name)
    setObjectName(name);

  QString num;
  
  for (int i=0; i<3; ++i) {
    col_labels_ << num.setNum(i);
    row_labels_ << num.setNum(i);
    for (int j=0; j<3; ++j) {
      setItem(i,j, new QTableWidgetItem(""));
    }
  }


  default_colsize_ = 60;
}

GsTLTable::~GsTLTable() {
}


bool GsTLTable::eventFilter(QObject *o, QEvent *e) {
  //if( hasEditFocus() ) return QTableWidget::eventFilter(o, e);

	if (e->type() == QEvent::KeyPress) {
	    QKeyEvent *ke = (QKeyEvent*)e;
      
	    if (ke->modifiers() == Qt::ControlModifier) {
    		if (ke->key() == Qt::Key_C) {
		      copy();
		      return true;
		    } 
        else if (ke->key() == Qt::Key_V) {
		      paste();
		      return true;
		    }
      }
      else if (ke->key() == Qt::Key_Delete || ke->key() == Qt::Key_Backspace ) {
        delete_cells();
        return true;
      }
  }

  return QTableWidget::eventFilter(o, e);
}


void GsTLTable::copy() {
  QList<QTableWidgetSelectionRange> L = selectedRanges();
  if (L.empty()) return;
  QTableWidgetSelectionRange select = L[0];
  
  QString val;
  for( int row = select.topRow() ; row <= select.bottomRow() ; row++ ) {
    for( int col = select.leftColumn() ; col <= select.rightColumn(); col++ ) {
      val.append(item(row,col)->text());
      val.append(";;");
    }
  }
  
  //clipboard = val;
  QClipboard *cb = QApplication::clipboard();
  cb->setText( val, QClipboard::Clipboard );
}



void GsTLTable::paste() {
  QClipboard *cb = QApplication::clipboard();
  QString clipboard = cb->text();
  if( clipboard.isEmpty() ) return;

  QStringList rows = clipboard.split( "\n",QString::SkipEmptyParts );
  int start_row = currentRow();
  int start_col = currentColumn();
  for( int i = 0; i < rowCount() ; i++ ) {
    QStringList cols = rows[i].split( ";;");
    for( int j = 0 ; j < columnCount() ; j++ ) {
      if( (!cols[j].isEmpty()) && item(start_row+i,start_col+j))
	item(start_row+i,start_col+j)->setText(cols[j]);
    }
  }
}


void GsTLTable::delete_cells() {
  QList<QTableWidgetSelectionRange> L = selectedRanges();
  if (L.empty()) return;
  QTableWidgetSelectionRange select = L[0];
  
  for( int row = select.topRow() ; row <= select.bottomRow() ; row++ ) {
    for( int col = select.leftColumn() ; col <= select.rightColumn(); col++ ) {
      this->item( row, col )->setText("");
    }
  }
}


void GsTLTable::setDefaultColsize( int s ) {
  default_colsize_ = s;
  for( int i=0; i < columnCount() ; i++ )
    setColumnWidth( i, s );
}


QString GsTLTable::rowHeaders() const {
  return row_labels_.join( ";" );
  //  return headerLabels( verticalHeader() );
}

QString GsTLTable::colHeaders() const {
  return col_labels_.join( ";" );
//  return headerLabels( horizontalHeader() );
}

void GsTLTable::setRowHeaders( const QString& headers ) {
  row_labels_ = headers.split( ";");
  setVerticalHeaderLabels( row_labels_ );
}

void GsTLTable::setColHeaders( const QString& headers ) {
  col_labels_ = headers.split( ";");
  setHorizontalHeaderLabels(  col_labels_ );
}


/*
QString GsTLTable::headerLabels( bool horiz ) const {  
  QStringList labels;
  for( int i = 0; i < numRows() ; i++ )
    labels << header->label( i );

  return labels.join( ";" );
}
*/
/*
void GsTLTable::setHeaderLabels( QHeaderView* header, const QStringList& labels ) {
  for( int i = 0 ; i < labels.size() ; i++ )
    header->setLabel( i, labels[i] );

  header->adjustHeaderSize();
}
*/
