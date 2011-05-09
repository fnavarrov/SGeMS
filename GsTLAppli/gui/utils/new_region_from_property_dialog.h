/**********************************************************************
** Author: Alexandre Boucher
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

#ifndef __GSTLAPPLI_NEW_REGION_FROM_PROPERTY_H__ 
#define __GSTLAPPLI_NEW_REGION_FROM_PROPERTY_H__ 

#include <GsTLAppli/gui/common.h>

#include <QtGui/QApplication>
#include <QtGui/QDialog>
#include <QtGui/qlineedit.h>

class GridSelectorBasic;
class SinglePropertySelector;
class MultipleCategorySelector;
class QGroupBox;

class GsTL_project;



class New_region_from_property_dialog : public QDialog {
  Q_OBJECT

public:
  New_region_from_property_dialog( GsTL_project* proj,
                        QWidget* parent = 0, const char* name = 0 );
  QString selected_grid() const;
  QString selected_property() const ;
  QString new_region_name() const;
  QString get_min_filter_value() const;
  QString get_max_filter_value() const;
  QStringList get_selected_categories() const;

  bool isCategorical() const;

protected slots:
  void populate_categories();
  void set_filter_type();
  void create_region();
  void create_region_and_close();

protected:
  GsTL_project* project_;
  GridSelectorBasic* gridSelector_;
  SinglePropertySelector* propSelector_;

  bool isCategorical_;

  QLineEdit *new_region_;

  QGroupBox* min_max_box_;
  QLineEdit *minFilter_, *maxFilter_;

  QGroupBox* category_box_;
  MultipleCategorySelector *cat_selector_;


};

 
#endif 
