/**********************************************************************
** Author: Alexandre Boucher
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
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
** Contact the Stanford Center for Reservoir Forecasting, Stanford University
** if any conditions of this licensing are not clear to you.
**
**********************************************************************/

#ifndef __GSTLAPPLI_QTPLUGINS_CATEGORICALSELECTORS_H__
#define __GSTLAPPLI_QTPLUGINS_CATEGORICALSELECTORS_H__


#include <GsTLAppli/extra/qtplugins/common.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/appli/project.h>

#include <qcombobox.h>
#include <QListWidget>
#include <QGroupBox>
#include <qdialog.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QKeyEvent>

#include <vector>
#include <set>

class QString;
class QLabel;
class QKeyEvent;

class QTPLUGINS_DECL  SingleCategoricalPropertySelector : public SinglePropertySelector {

  Q_OBJECT

 public:
  SingleCategoricalPropertySelector( QWidget* parent = 0, const char* name = 0 );
  virtual ~SingleCategoricalPropertySelector() {}
  
  public slots:
    virtual void show_properties( const QString& grid_name );

};


/** A widget to choose multiple properties from a grid
 */ 
class QTPLUGINS_DECL  MultiCategoricalPropertySelector : public MultiPropertySelector {

  Q_OBJECT

 public:
  MultiCategoricalPropertySelector( QWidget* parent = 0, const char* name = 0 );
  virtual ~MultiCategoricalPropertySelector() {}
  
  public slots:
    void show_properties( const QString& grid_name );

};



class QTPLUGINS_DECL  Ordered_categorical_property_selector_dialog
    : public Ordered_property_selector_dialog {

  Q_OBJECT

public:
  Ordered_categorical_property_selector_dialog( QWidget* parent = 0, const char* name = 0 );
  virtual ~Ordered_categorical_property_selector_dialog() {}

public slots:
  void show_properties( const QString& grid_name );

protected:
  MultiCategoricalPropertySelector* property_selector_;
};


class QTPLUGINS_DECL  OrderedCategoricalPropertySelector 
    : public OrderedPropertySelector {

  Q_OBJECT

public:
  OrderedCategoricalPropertySelector( QWidget* parent = 0, const char* name = 0 );
  virtual ~OrderedCategoricalPropertySelector() {}
  void set_selected_properties( QStringList list );

public slots:
//  void show_properties( const QString& grid_name );
  void show_selection_dialog();

protected:
  MultiCategoricalPropertySelector* selected_properties_;
};



/** Enables to choose a categorical property definition
 */ 
class QTPLUGINS_DECL CategoricalDefinitionSelector : public QComboBox {

  Q_OBJECT

 public:
  CategoricalDefinitionSelector( QWidget* parent = 0, const char* name = 0 );
  virtual ~CategoricalDefinitionSelector() {}
  
  public slots:
    virtual void show_definitons( );
};


/** A widget to choose multiple categorical property definition
 */ 
class QTPLUGINS_DECL  MultiCategoricalDefinitionSelector : public QListWidget {

  Q_OBJECT

 public:
  MultiCategoricalDefinitionSelector( QWidget* parent = 0, const char* name = 0 );
  virtual ~MultiCategoricalDefinitionSelector() {}
  
  public slots:
    void show_definitions( );

  protected slots:
    void selection_size();

 signals:
  void selected_count( int );
};


/** A widget to choose multiple categorical property definition
 */ 
class QTPLUGINS_DECL  CategoricalDefinitionViewer : public QGroupBox {

  Q_OBJECT

 public:
  CategoricalDefinitionViewer( QWidget* parent = 0, const char* name = 0 );
  virtual ~CategoricalDefinitionViewer() {}
  
  public slots:
    void show_definition( QString );

protected: 
  QVBoxLayout* baseLayout_;
  QString current_definition_;

};


/** A widget to choose multiple categories from a property
 */
class QTPLUGINS_DECL  MultipleCategorySelector : public QListWidget {

  Q_OBJECT

 public:
  MultipleCategorySelector( QWidget* parent = 0, const char* name = 0 );
  virtual ~MultipleCategorySelector() {}

  public slots:
    void show_categories( const QString& cat_def_name);

  protected slots:
    void selection_size();

    signals:
     void selected_count( int );

protected:


};




#endif
