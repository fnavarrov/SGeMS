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

#include <GsTLAppli/gui/variogram2/rgrid_params.h>
#include <GsTLAppli/gui/utils/qwidget_value_collector.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/extra/qtplugins/gstl_table.h>
#include <GsTLAppli/math/correlation_measure.h>

#include <qfiledialog.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <QVBoxLayout>
#include <fstream>

using namespace String_Op;

RGrid_params::
RGrid_params( QWidget* parent, const char* name )
  : QWidget( parent )
{
  setupUi(this);
  if (name)
    setObjectName(name);
  
  // disable the standardize option because it doesn't work as expected 
  // in the case of indicator variograms
  standardize_options_box_->hide();

  
  QVBoxLayout * v = new QVBoxLayout();
  table_frame_->setLayout(v);

  vector_table_ = new GsTLTable( table_frame_, "vector_table_" );
  vector_table_->setRowCount( 1 );
  vector_table_->setColumnCount( 6 );


  v->addWidget(vector_table_);
  
  QStringList headers;
  headers += "x";
  headers += "y";
  headers += "z";
  headers += "measure type";
  headers += " head indic. cutoff";
  headers += " tail indic. cutoff";
  vector_table_->setHorizontalHeaderLabels( headers );
  
//  for( int i=0; i < 4; i++ ) {
//    vector_table_->setColumnWidth( i, 70 );
//  }

  //--------------------
  // signal forwarding
  QObject::connect(num_lags_,SIGNAL(valueChanged(int)),
                   this,SIGNAL(parameterChanged()));
  QObject::connect(num_lags_,SIGNAL(valueChanged(const QString &)),
                   this,SIGNAL(parameterChanged()));
  QObject::connect(vector_table_,SIGNAL(cellChanged(int,int)),
                   this,SIGNAL(parameterChanged()));
  QObject::connect(variance_scale_,SIGNAL(toggled(bool)),
                   this,SIGNAL(parameterChanged()));

  //--------------------
  // signal-slot connections
  QObject::connect(load_button_, SIGNAL( clicked() ),
                   this, SLOT( load_parameters() ));
  QObject::connect(save_button_, SIGNAL( clicked() ),
                   this, SLOT( save_parameters() ));
  QObject::connect(directions_count_, SIGNAL(valueChanged(int)),
          		     this, SLOT( set_directions_count(int) ));


  directions_count_->setValue( 1 );

  std::vector<std::string> correl_methods =
    Correlation_measure_factory::available_methods();
  
  for( unsigned int i=0; i < correl_methods.size() ; i++ ) {
    methods_list_.append( correl_methods[i].c_str() );
  }

  for ( int row = 0; row < vector_table_->rowCount(); row++ ) {
    for (int col = 0; col < vector_table_->columnCount(); col++)
      if (col != 3)
	vector_table_->setItem(row,col,new QTableWidgetItem(""));
    QModelIndex index = vector_table_->model()->index(row,3,QModelIndex());
    QComboBox* item = new QComboBox(vector_table_);
    item->addItems(methods_list_);
    vector_table_->setIndexWidget(index,item);
  }

  QWidget::setTabOrder( num_lags_, directions_count_ );
  QWidget::setTabOrder( directions_count_, vector_table_ );
  QWidget::setTabOrder( vector_table_, variance_scale_ );
  QWidget::setTabOrder( variance_scale_, load_button_ );
  QWidget::setTabOrder( load_button_, save_button_ );
}


void RGrid_params::set_directions_count( int n ) {
  int old_count = vector_table_->rowCount();
  vector_table_->setRowCount( n );
  for( int row = old_count ; row < n ; row++ ) {
    for (int col = 0; col < vector_table_->columnCount(); col++)
      if (!vector_table_->item(row,col) && col != 3)
	vector_table_->setItem(row,col,new QTableWidgetItem(""));

    QModelIndex index = vector_table_->model()->index(row,3,QModelIndex());
    QComboBox * item = new QComboBox(vector_table_);
    item->addItems(methods_list_);
    vector_table_->setIndexWidget(index,item);
  }
}


const QTableWidget * RGrid_params::vector_table()
{
    return static_cast<const QTableWidget*>(vector_table_);
}



int RGrid_params::num_lags()
{
    return num_lags_->value();
}

bool RGrid_params::scale_with_variance()
{
    return variance_scale_->isChecked();
}


void RGrid_params::
all_parameters( std::vector<GsTLVector<double> > & d,
                std::vector<std::string > & mod_type,
                std::vector< std::pair<double, double> > &mod_param )
{
  for( int i=0 ; i < vector_table_->rowCount() ; i++ ) {
    if( !vector_table_->item(i,0)->text().isEmpty() ) {
      GsTLVector<int> v( vector_table_->item(i,0)->text().toInt(),
                         vector_table_->item(i,1)->text().toInt(),
                         vector_table_->item(i,2)->text().toInt() );

      d.push_back(v);
      QComboBox * combo_item =
	(QComboBox *)vector_table_->indexWidget(vector_table_->model()->index(i,3,QModelIndex()));
      mod_type.push_back( qstring2string(combo_item->currentText()) );
	     
      double thresh1, thresh2;
      bool ok;
      thresh1 = vector_table_->item(i,4)->text().toDouble( &ok );
      if( !ok ) thresh1 = 0;
      thresh2 = vector_table_->item(i,5)->text().toDouble( &ok );
      if( !ok ) thresh2 = 0;
      mod_param.push_back( std::make_pair( thresh1, thresh2 ) );
     
    }
  }
}
		    



void RGrid_params::load_parameters() {
  QString filename = 
    QFileDialog::getOpenFileName( this, "Load Parameters");

  
  if( filename == QString::null ) return;

  // Open the file and put the content into a string (using a stringstream)
  std::ifstream infile( qstring2string(filename).c_str() );
  if( !infile ) {
    GsTLcerr << "Can't open file " << qstring2string(filename) << "\n" << gstlIO::end;
    return;
  }

  std::ostringstream file_content;
  char ch;
  while( file_content && infile.get( ch ) )
    file_content.put( ch );


  QWidgets_values_collector_xml collector;
  collector.set_widgets_values( file_content.str(), this );  
}
 


void RGrid_params::save_parameters() {
  QString filename = 
    QFileDialog::getSaveFileName( this, "Save Parameters");

  
  if( filename == QString::null ) return;

  QWidgets_values_collector_xml collector;
  std::string params = collector.widgets_values( this, "regular_grid_variogram" );

  std::ofstream outfile( qstring2string(filename).c_str() );
  if( !outfile ) {
    GsTLcerr << "Can't create file " << qstring2string(filename) << "\n" << gstlIO::end;
    return;
  }

  outfile << params << std::endl;
}
