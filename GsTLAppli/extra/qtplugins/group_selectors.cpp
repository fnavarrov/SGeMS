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


#include <GsTLAppli/extra/qtplugins/group_selectors.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/utils/gstl_messages.h>
//#include <GsTLAppli/extra/qtplugins/widgetfactory.h>
#include <QKeySequence>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/utils/string_manipulation.h>

#include <qstring.h>
#include <QGroupBox>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qobject.h>
#include <qlabel.h>
#include <qevent.h>
#include <qclipboard.h>
#include <qapplication.h>
#include <QtUiTools/QUiLoader>
#include <algorithm>




//===============================================


SinglePropertyGroupSelector::SinglePropertyGroupSelector( QWidget* parent, const char* name )
  : QComboBox( parent ) {
  if (name)
    setObjectName(name);
}

void SinglePropertyGroupSelector::show_property_groups( const QString& grid_name ) {
  QString current_text;
  if( grid_name == current_grid_ )
    current_text = currentText();  
  
  current_grid_ = grid_name;
  QComboBox::clear();

  if( grid_name.isEmpty() || grid_name == GridSelectorBasic::no_selection ) return;
  

  std::string name = grid_name.toStdString();

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + name );
  Geostat_grid* grid = (Geostat_grid*) ni.raw_ptr() ;
  // no dynamic_cast is used on the previous line because it makes 
  // designer and uic segfault when they try to load the plugin...
  // It used to work before, don't know what changed.  

  if( !grid ) return;

  int selected_item = 0;
  int i=0;
  std::list<std::string> groups = grid->get_group_names();
  
  std::list<std::string>::iterator begin = groups.begin();
  for( ; begin != groups.end() ; ++begin, i++ ) {
    QString group_name( begin->c_str() );
    addItem( group_name );

    if( current_text == group_name ) selected_item = i;
  }

  // a dirty hack to have the combobox resize itself to the size of 
  // its longest element
  setFont( font() );
  updateGeometry();
  
  setCurrentIndex( selected_item );


  emit activated( currentText() );
  // Don't know why "0". Should be "currentItem". remove if everything works fine
    emit activated( 0 );
//  emit activated( currentItem() );
}




//===============================================


//===============================================

MultiPropertyGroupSelector::MultiPropertyGroupSelector( QWidget* parent, const char* name )
  : QListWidget( parent ) {
  if (name)
    setObjectName(name);

  setSelectionMode( QAbstractItemView::ExtendedSelection );

  QObject::connect( this, SIGNAL( itemSelectionChanged() ),
		    this, SLOT( selection_size() ) );
}

void MultiPropertyGroupSelector::show_property_groups( const QString& grid_name ) {
  QListWidget::clear();

  if( grid_name.isEmpty() || grid_name == GridSelectorBasic::no_selection ) return;
  
  std::string name= grid_name.toStdString();

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + name );
  Geostat_grid* grid = (Geostat_grid*) ni.raw_ptr() ;
  // no dynamic_cast is used on the previous line because it makes 
  // designer and uic segfault when they try to load the plugin...
  // It used to work before, don't know what changed.  

  if( !grid ) return;

  std::list<std::string> groups = grid->get_group_names();
  std::list<std::string>::iterator begin = groups.begin();
  for( ; begin != groups.end() ; ++begin ) {
    QString group_name( begin->c_str() );
    addItem( group_name );
  }
  
}


void MultiPropertyGroupSelector::selection_size() {
  int size=0;
  for( unsigned int i = 0; i < count() ; i++ ) {
    QListWidgetItem * it = item(i);
    if( it->isSelected( ) && !it->text().isEmpty() ) {
      size++;
    }
  }
  emit( selected_count(size) );
}


//===============================================