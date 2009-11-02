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

#include <GsTLAppli/gui/variogram2/plot_settings_dialog.h>

#include <qgroupbox.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <GsTLAppli/extra/qwt/qwt_plot_curve.h>

PlotSettingsDialog::
PlotSettingsDialog( const std::vector<QwtPlot*>& plot_widgets, 
                    QWidget* parent, const char* name, 
                    bool modal ) 
  : QDialog( parent ), plots_( plot_widgets ) {

  setupUi(this);
  if(name)
    setObjectName(name);
  setModal(modal);
  
  plots_list_->setSelectionMode( QAbstractItemView::ExtendedSelection );
  plots_list_->setHidden( true );
  xgroupbox_->setHidden( true );
  ygroupbox_->setHidden( true );

  for( unsigned int plot_id = 0 ; plot_id < plots_.size() ; plot_id++ ) {
    plots_list_->addItem( plots_[plot_id]->title().text() );
  }

  QObject::connect( ok_button_, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( cancel_button_, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );

  setSizeGripEnabled( true );
}


void PlotSettingsDialog::accept() {
  std::vector<QwtPlot*> plots_to_modify;
  if( all_plots_button_->isChecked() ) 
    plots_to_modify = plots_;
  else {
    for( unsigned int i=0; i < plots_list_->count() ; i++ ) {
      if( plots_list_->item(i)->isSelected( ) )
        plots_to_modify.push_back( plots_[i] );
    }
  }

  if( !x_leave_unchanged_->isChecked() ) {
    if( x_autoscale_->isChecked() ) {
      setAutoScale( plots_to_modify, QwtPlot::xBottom );
    }
    else {
      setScale( plots_to_modify, QwtPlot::xBottom, 
                xmin_->text(), xmax_->text() );
    }
  }

  if( !y_leave_unchanged_->isChecked() ) {
    if( y_autoscale_->isChecked() ) {
      setAutoScale( plots_to_modify, QwtPlot::yLeft );
    }
    else {
      setScale( plots_to_modify, QwtPlot::yLeft, 
                ymin_->text(), ymax_->text() );
    }
  }

  QDialog::accept();
}



void PlotSettingsDialog::
setAutoScale( const std::vector<QwtPlot*>& plots, QwtPlot::Axis axis ) {
  const double margin = 1.05;

  for( unsigned int i=0 ; i < plots.size() ; i++ ) {
    double max = -9e99;
    double min =  9e99;
    QwtPlotItemList L = plots[i]->itemList();
    for (int id = 0; id < L.size(); ++id){
      if (L[id]->rtti() != QwtPlotItem::Rtti_PlotCurve)
	continue;

      QwtPlotCurve *curve = dynamic_cast<QwtPlotCurve*>(L[i]);
      if( axis == QwtPlot::xBottom ) {
        max = std::max( max, curve->maxXValue() );
        min = std::min( min, curve->minXValue() );
      }
      else {
        max = std::max( max, curve->maxYValue() );
        min = std::min( min, curve->minYValue() );
      }
    }
    plots[i]->setAxisScale( axis, min*(2-margin), max*margin );
    plots[i]->replot();
  }
}



void PlotSettingsDialog::
setScale( const std::vector<QwtPlot*>& plots, QwtPlot::Axis axis, 
          QString min_str, QString max_str ) {

  double min = min_str.toDouble();
  double max = max_str.toDouble();

  for( unsigned int i=0 ; i < plots.size() ; i++ ) {
    plots[i]->setAxisScale( axis, min, max );
    plots[i]->replot();
  }
}

