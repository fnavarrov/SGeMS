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

#ifndef __GSTLAPPLI_GUI_UTILS_MERGE_REGIONS_DIALOG_H__
#define __GSTLAPPLI_GUI_UTILS_MERGE_REGIONS_DIALOG_H__

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



class MultiRegionSelector;
class GridSelectorBasic;
class GsTL_project;

QT_BEGIN_NAMESPACE

class GUI_DECL Merge_regions_dialog : public QDialog {

  Q_OBJECT

public:

  Merge_regions_dialog( GsTL_project* proj,QWidget* parent = 0, const char* name = 0 );
  virtual ~Merge_regions_dialog() {}

  QString selected_grid() const;
  QStringList selected_items();
  QString new_region_name();
  
protected:
  GridSelectorBasic* grid_selector_;
  MultiRegionSelector* choice_list_;
  QLineEdit *merged_region_;
};
QT_END_NAMESPACE
#endif


/*


class GridSelector;
class SinglePropertySelector;
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

protected:
  GridSelector* gridSelector_;
  SinglePropertySelector* propSelector_;

  QLineEdit *new_region_;
  QLineEdit *minFilter_, *maxFilter_;

};
*/