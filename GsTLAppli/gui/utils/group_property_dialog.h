/**********************************************************************
** Author: Alexandre Boucher
** Copyright (C) Advanced Resources and Risk Technology, LLC
** All rights reserved.
**
** This file is part of the "gui" module of the Geostatistical Earth
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
** ContactAdvanced Resources and Risk Technology, LLC
** if any conditions of this licensing are not clear to you.
**
**********************************************************************/

#ifndef __GSTLAPPLI_GUI_UTILS_GROUP_PROPERTY_DIALOG_H__
#define __GSTLAPPLI_GUI_UTILS_GROUP_PROPERTY_DIALOG_H__

#include <GsTLAppli/gui/common.h>

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>

#include <QtGui/qlineedit.h>

#include <qdialog.h>


class QRadioButton;
class QTextBrowser;
class QTextEdit;
class SinglePropertyGroupSelector;
class MultiPropertyGroupSelector;
class GridSelectorBasic;
class OrderedPropertySelector;
class GsTL_project;


QT_BEGIN_NAMESPACE

class GUI_DECL View_group_property_dialog : public QDialog {

  Q_OBJECT

public:

  View_group_property_dialog( GsTL_project* proj,QWidget* parent = 0, const char* name = 0 );
  virtual ~View_group_property_dialog() {}

public slots:
  void display_properties(const QString& group_name);

  /*
signals:
  void selected_definition(QString& cat_def_name);
*/
protected:
  GridSelectorBasic* grid_selector_;
  SinglePropertyGroupSelector* group_selector_;
  QTextBrowser* properties_viewer_;

  QString current_group_;
};


class GUI_DECL New_group_property_dialog : public QDialog {

  Q_OBJECT

public:

  New_group_property_dialog( GsTL_project* proj,QWidget* parent = 0, const char* name = 0 );
  virtual ~New_group_property_dialog() {}

protected slots:
  void clear();
  void create_group();
  void create_group_close();
  

protected:
  GridSelectorBasic* grid_selector_;
  QLineEdit* group_name_line_;
  OrderedPropertySelector*  prop_selector_;
  GsTL_project* project_;
  
};


class GUI_DECL Modify_group_property_dialog : public QDialog {

  Q_OBJECT

public:

  Modify_group_property_dialog( GsTL_project* proj,QWidget* parent = 0, const char* name = 0 );
  virtual ~Modify_group_property_dialog() {}

public slots:
  void display_properties(const QString& group_name);
  void modify_group_property();
  void modify_group_property_close();
  

  /*
signals:
  void selected_definition(QString& cat_def_name);
*/
protected:
  GridSelectorBasic* grid_selector_;
  SinglePropertyGroupSelector* group_selector_;
  OrderedPropertySelector*  prop_selector_;

  GsTL_project* project_;

};


class GUI_DECL Delete_group_property_dialog : public QDialog {

  Q_OBJECT

public:

  Delete_group_property_dialog( GsTL_project* proj,QWidget* parent = 0, const char* name = 0 );
  virtual ~Delete_group_property_dialog() {}

public slots:
  void Delete_group_property();
  void Delete_group_property_close();
  

  /*
signals:
  void selected_definition(QString& cat_def_name);
*/
protected:
  GridSelectorBasic* grid_selector_;
  MultiPropertyGroupSelector* groups_selector_;

  GsTL_project* project_;

};


QT_END_NAMESPACE
#endif


