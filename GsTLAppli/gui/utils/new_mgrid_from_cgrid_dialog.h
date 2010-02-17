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

#ifndef __GSTLAPPLI_NEW_MGRID_FROM_CGRID_H__ 
#define __GSTLAPPLI_NEW_MGRID_FROM_CGRID_H__ 

#include <GsTLAppli/gui/common.h>

#include <QtGui/QApplication>
#include <QtGui/QDialog>
#include <QtGui/qlineedit.h>

class GridSelectorBasic;
class MultiRegionSelector;
class GsTL_project;

class New_mgrid_from_cgrid_dialog : public QDialog {
  Q_OBJECT

public:
  New_mgrid_from_cgrid_dialog( GsTL_project* proj,
                        QWidget* parent = 0, const char* name = 0 );
  QString selected_grid() const;
  QStringList selected_regions() const ;
  QString new_mgrid_name() const;


protected:
  GridSelectorBasic* gridSelector_;
  MultiRegionSelector* regionsSelector_;

  QLineEdit *new_mgrid_;

};

 
#endif 