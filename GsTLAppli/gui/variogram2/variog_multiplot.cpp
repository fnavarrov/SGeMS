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

#include <GsTLAppli/gui/variogram2/variog_multiplot.h>
#include <GsTLAppli/math/discrete_function.h>
#include <GsTL/math/math_functions.h>
#include <GsTLAppli/math/gstlpoint.h>
#include <GsTL/geometry/geometry_algorithms.h>
#include <GsTLAppli/extra/qwt/qwt_plot_grid.h>
#include <GsTLAppli/extra/qwt/qwt_symbol.h>
#include <GsTLAppli/extra/qwt/qwt_scale_engine.h>
#include <GsTLAppli/extra/qwt/qwt_plot_curve.h>
#include <GsTLAppli/extra/qwt/qwt_legend.h>
#include <qpen.h>
#include <qbrush.h>
#include <QVector>
#include <qpainter.h>

#include <algorithm>
#include <cmath>



Variog_multiplot::
Variog_multiplot( const std::vector<Discrete_function>& df_vec,
                  const QStringList& titles,
                  QWidget *parent, const char *name )
       : QwtPlot(parent)
{
  if (name)
    setObjectName(name);
  
  //this->setWindowFlags( Qt::SubWindow|Qt::MSWindowsFixedSizeDialogHint);

  //------------
  // configure the plotting area

  //use a light gray for the grid
  QwtPlotGrid * grid = new QwtPlotGrid();
  grid->enableX(true);
  grid->setPen( QPen( QColor(150,150,150), 0, Qt::DotLine ) );
  grid->attach(this);
    
  // configure the plot axis
  this->axisScaleEngine(QwtPlot::xBottom)->setReference(0);
  this->axisScaleEngine(QwtPlot::yLeft)->setReference(0);
  this->axisScaleEngine(QwtPlot::xBottom)->setMargins(0,0.5);
  this->axisScaleEngine(QwtPlot::yLeft)->setMargins(0,0.5);
  this->axisScaleEngine(QwtPlot::xBottom)->setAttributes(QwtScaleEngine::Floating |
							QwtScaleEngine::IncludeReference);
  this->axisScaleEngine(QwtPlot::yLeft)->setAttributes(QwtScaleEngine::Floating |
							QwtScaleEngine::IncludeReference);


  QFont axis_font =  this->axisFont( QwtPlot::xBottom );
  axis_font.setPointSize( 7 );

  QwtText title("distance");
  title.setFont(axis_font);
  this->setAxisTitle( QwtPlot::xBottom,title);


  //-------------
  this->setWindowTitle( "All Plots" );

  typedef enum QwtSymbol::Style QwtStyleEnum;
  typedef enum Qt::PenStyle QtPenStyleEnum;

  unsigned int dot_styles[8] = { QwtSymbol::Ellipse,
                                  QwtSymbol::Rect,
                                  QwtSymbol::Diamond,
                                  QwtSymbol::DTriangle,
                                  QwtSymbol::UTriangle,
                                  QwtSymbol::RTriangle,
                                  QwtSymbol::Cross,
                                  QwtSymbol::XCross };
  unsigned int line_styles[5] = {Qt::SolidLine, 
                                 Qt::DashLine, 
                                 Qt::DotLine,
                                 Qt::DashDotLine, 
                                 Qt::DashDotDotLine };
  /*
  if( !title.isEmpty() ) {
    QFont title_font;
    title_font.setPointSize( 8 );
    this->setTitle( title );
    this->setTitleFont( title_font );
    this->setCaption( title );
  }
  */
  const float ymargin = 1.05;
  const float xmargin = 1.06;

  float ymax = -9e99;
  float ymin = 9e99;
  float xmax = -9e99;
  for( unsigned int plot_id = 0; plot_id < df_vec.size() ; plot_id++ ) {
    std::vector<double> x_vals = df_vec[plot_id].x_values();
    std::vector<double> y_vals = df_vec[plot_id].y_values();

    double* x = new double[x_vals.size()];
    double* y = new double[x_vals.size()];

    int actual_size = 0;
    for( int i=0 ; i < x_vals.size() ; i++ ) {
      if( GsTL::equals( x_vals[i], df_vec[plot_id].no_data_value(), 0.001 ) ||
          GsTL::equals( y_vals[i], df_vec[plot_id].no_data_value(), 0.001 ) ) continue;

      x[actual_size] = x_vals[i];
      y[actual_size] = y_vals[i];

      actual_size++;
    }
    if( actual_size > 0 ) {
      float current_ymax = *(std::max_element( y, y+actual_size ));
      float current_ymin = *(std::min_element( y, y+actual_size ));
      float current_xmax = *(std::max_element( x, x+actual_size ));

      ymax = std::max(ymax, current_ymax );
      ymin = std::min(ymin, current_ymin );

      xmax = std::max(xmax, current_xmax );
    }

    QwtPlotCurve * curve_id = new QwtPlotCurve(titles[plot_id]);
    curve_id->attach(this);
    curve_id->setData( x, y, actual_size );
  
    QwtSymbol symbol;
    // The following line uses an awful cast from int to enum !!
    // Awful, but it will stay until I find a more elegant way of looping
    // through all the qwt styles.
    symbol.setStyle( static_cast<QwtStyleEnum>(dot_styles[plot_id%8]) ); 
    symbol.setPen( QPen(Qt::black, 1 ) );
    symbol.setSize(6);
      
    curve_id->setSymbol(symbol);
    curve_id->setStyle(QwtPlotCurve::Lines);
    curve_id->setPen( QPen(Qt::darkGray, 0, 
			   static_cast<QtPenStyleEnum>(line_styles[plot_id%5]) ) );

    delete [] x;
    delete [] y;
  }

  if( ymax == 0 && ymin == 0 ) 
    this->setAxisAutoScale( QwtPlot::yLeft );
  else
    this->setAxisScale( QwtPlot::yLeft, ymin*(2-ymargin), ymax*ymargin );

  if( xmax > 0 ) {
    this->setAxisScale( QwtPlot::xBottom, 0, xmax*xmargin );  
  }

  QwtLegend * legend = new QwtLegend();
  this->insertLegend(legend);
  this->replot();

}






