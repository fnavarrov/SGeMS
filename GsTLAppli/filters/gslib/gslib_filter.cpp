/**********************************************************************
** Author: Nicolas Remy
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
** All rights reserved.
**
** This file is part of the "filters" module of the Geostatistical Earth
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

#include <GsTLAppli/filters/gslib/gslib_filter.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/filters/gslib/filter_qt_dialogs.h>
#include <GsTLAppli/grid/grid_model/cartesian_grid.h>
#include <GsTLAppli/grid/grid_model/point_set.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/grid/grid_model/reduced_grid.h>

#include <qdialog.h>
#include <qapplication.h>
#include <qtextstream.h>
#include <qfile.h>
#include <qstringlist.h>
#include <qcursor.h>

#include <string>
#include <cctype>


//temporary
#include <algorithm>


Named_interface* Gslib_infilter::create_new_interface( std::string& ) {
  return new Gslib_infilter();
}

Named_interface* Gslib_grid_infilter::create_new_interface( std::string& ) {
  return new Gslib_grid_infilter();
}

Named_interface* Gslib_mgrid_infilter::create_new_interface( std::string& ) {
  return new Gslib_mgrid_infilter();
}

Named_interface* Gslib_outfilter::create_new_interface( std::string& ) {
  return new Gslib_outfilter();
}

//===================================================================


Gslib_infilter::Gslib_infilter() 
  : wizard_( new Gslib_infilter_dialog( qApp->activeWindow() ) ) {
}

Gslib_infilter::~Gslib_infilter() {
  delete wizard_;
}


bool Gslib_infilter::can_handle( const std::string& filename ) {
  // To figure out if a file is a gslib file we do:
  //   - read the second line: it should be the number of properties in the
  //     data set.
  //   - skip as many lines as indicated on the second line (ie skip the
  //     property names). The next character should be a number.

  QFile file( filename.c_str() );
  if( !file.open( QIODevice::ReadOnly ) ) return false;

  QTextStream stream( &file );
  stream.readLine();
  if( stream.atEnd() ) return false;

  QString str;
  stream >> str;
  stream.readLine();
  bool is_number;
  int properties = str.toInt( &is_number );
  if( !is_number ) return false;
  if( properties <= 0 ) return false;
  
  for( int i= 0; i < properties; i++ )
    stream.readLine();

  // Read the (supposed) first line of property values. Count that there are 
  // as many columns as indicated in the second line, and that each columns 
  // contains a number
  QString line = stream.readLine();
  QStringList fields = line.simplified().split(" ", QString::SkipEmptyParts);
  if( fields.size() != properties ) return false;
  for( int j= 0; j < properties; j++ ) {
    fields[j].toFloat( &is_number );
    if( !is_number ) return false;
  }

  return true;
}


Geostat_grid* Gslib_infilter::read( const std::string& filename, 
                                    std::string* errors ) {
  std::ifstream infile( filename.c_str() );
  if( !infile ) {
    if( errors ) 
      errors->append( "can't open file: " + filename );
  }

  wizard_->set_file( infile );

  QApplication::setOverrideCursor( QCursor(Qt::ArrowCursor) );
    
  if( wizard_->exec() == QDialog::Rejected ) {
    QApplication::restoreOverrideCursor();
    return 0;
  }

  QApplication::restoreOverrideCursor();

  Gslib_specialized_infilter* filter = wizard_->filter();
  return filter->read( infile ) ;

}






//========================================================


Geostat_grid* Gslib_specialized_infilter::read( const std::string& filename, 
                                                std::string* errors ) {
  std::ifstream in( filename.c_str() );
  if( !in ) {
    if( errors )
      errors->append( "can't open file: " + filename );
    return 0;
  }

  return this->read( in );
}

//========================================================
Gslib_mgrid_infilter::Gslib_mgrid_infilter() : 
	dialog_(new Gslib_input_mgrid_dialog( qApp->activeWindow() ) )
{}

Gslib_mgrid_infilter::~Gslib_mgrid_infilter() {
  dialog_ = 0;
}

QWidget* Gslib_mgrid_infilter::init_dialog( std::ifstream& ) {
  dialog_ = new Gslib_input_mgrid_dialog( qApp->activeWindow() );
  return dialog_;
}

/*
bool Gslib_mgrid_infilter::get_mgrid_ijk_dimensions(
  std::ifstream& infile,Reduced_grid* grid, 
    int X_col_id, int Y_col_id, int Z_col_id,
    float x_size, float y_size, float z_size)
{

  std::string buffer;
	std::getline( infile, buffer, '\n');
	int property_count;
	infile >> property_count;
  for(int i=0;i<property_count; ++i) 
	  std::getline( infile, buffer, '\n');

  std::vector<GsTLGridNode> ijk;
  GsTLGridNode max_ijk(-1,-1,-1);

  int line_no=0;

  while( infile ) {
		GsTLGridNode node;
		std::getline( infile, buffer, '\n');
    std::vector<std::string> buf = String_Op::decompose_string( buffer, " ", false );
		if (buf.empty()) break;

		node[0] = String_Op::to_number<int>(buf[X_col_id]);
		node[1] = String_Op::to_number<int>(buf[Y_col_id]);
		node[2] = String_Op::to_number<int>(buf[Z_col_id]);
    if(node[0]< 0 || node[1]< 0 || node[2]< 0 ) {
      GsTLcerr << "Some ijk indices are negative, see entry number " << line_no << gstlIO::end;
      return false;
    }
    ijk.push_back(node);
    if(node[0] > max_ijk[0]) max_ijk[0] = node[0];
    if(node[1] > max_ijk[1]) max_ijk[1] = node[1];
    if(node[2] > max_ijk[2]) max_ijk[2] = node[2];
    line_no++;

  }
  max_ijk = max_ijk + GsTLGridNode(1,1,1);

  grid->set_dimensions(max_ijk[0],max_ijk[1],max_ijk[2],
         x_size, y_size, z_size,ijk);
	float Ox = dialog_->Ox();
	float Oy = dialog_->Oy();
	float Oz = dialog_->Oz();
  grid->origin( Geostat_grid::location_type( Ox,Oy,Oz) );
  infile.seekg(ios_base::beg);

  return true;

}
*/
bool Gslib_mgrid_infilter::get_mgrid_xyz_dimensions(
    std::ifstream& infile, Reduced_grid* grid, 
    int X_col_id, int Y_col_id, int Z_col_id,
    float x_size, float y_size, float z_size)
{
//  bool is_jk = dialog_->is_ijk();
  std::string buffer;
	std::getline( infile, buffer, '\n');
	int property_count;
	infile >> property_count;
  std::getline( infile, buffer, '\n');
  for(int i=0;i<property_count; ++i) 
	  std::getline( infile, buffer, '\n');

  std::vector<Geostat_grid::location_type> xyz;
  Geostat_grid::location_type max_xyz(-1,-1,-1);
  Geostat_grid::location_type origin(9e20,9e20,9e20);
  while( infile ) {
		Geostat_grid::location_type loc;
		std::getline( infile, buffer, '\n');
    if (buffer.empty()) break;
    QString qbuffer(buffer.c_str());
    QStringList buf = qbuffer.split(" ",QString::SkipEmptyParts);
//    if( buf.empty )

//    std::vector<std::string> buf
//		std::vector<std::string> buf = String_Op::decompose_string( buffer, " ", false );

    if (buf.empty()) break;

//		loc[0] = String_Op::to_number<float>(buf[X_col_id]);
//		loc[1] = String_Op::to_number<float>(buf[Y_col_id]);
//		loc[2] = String_Op::to_number<float>(buf[Z_col_id]);

    loc[0] = buf[X_col_id].toDouble();
		loc[1] = buf[Y_col_id].toDouble();
		loc[2] = buf[Z_col_id].toDouble();
    xyz.push_back(loc);

    if(loc[0] > max_xyz[0]) max_xyz[0] = loc[0];
    if(loc[1] > max_xyz[1]) max_xyz[1] = loc[1];
    if(loc[2] > max_xyz[2]) max_xyz[2] = loc[2];

    if(loc[0] < origin[0]) origin[0] = loc[0];
    if(loc[1] < origin[1]) origin[1] = loc[1];
    if(loc[2] < origin[2]) origin[2] = loc[2];

  }
  GsTLGridNode nxyz(int((max_xyz[0]-origin[0])/x_size)+1,
                    int((max_xyz[1]-origin[1])/y_size)+1,
                    int((max_xyz[2]-origin[2])/z_size)+1);


  grid->set_dimensions(nxyz[0],nxyz[1],nxyz[2],
         x_size, y_size, z_size, xyz, origin);

 // infile.seekg(0, ios::beg);

  return true;
}


Geostat_grid* Gslib_mgrid_infilter::readRegularGridFormat(std::ifstream& infile,Reduced_grid * grid)
{
	std::vector<std::string> nums;

	int nx = dialog_->nx();
	int ny = dialog_->ny();
	int nz = dialog_->nz();
	float x_size = dialog_->x_size();
	float y_size = dialog_->y_size();
	float z_size = dialog_->z_size();
	float Ox = dialog_->Ox();
	float Oy = dialog_->Oy();
	float Oz = dialog_->Oz();

	grid->set_dimensions( nx, ny, nz,
		x_size, y_size, z_size);
	grid->origin( GsTLPoint( Ox,Oy,Oz) );

	std::string buffer;

  int maskColNumber = dialog_->mask_column()-1;

	//-------------------------
	//   now, read the file

	// read title
	std::getline( infile, buffer, '\n');

	// read nb of properties
	int total_columns;
	infile >> total_columns;
	std::getline( infile, buffer, '\n');

	if (maskColNumber > total_columns) {
	    GsTLcerr << "Invalid mask column" << gstlIO::end;
		return NULL;
	}

  bool has_multi_real = false;
//	std::vector<GsTLGridProperty*> properties;
	for( int i=0; i<total_columns; i++ ) {
		std::getline( infile, buffer, '\n');
		QString prop_name( buffer.c_str() );
//		if( i != maskColNumber ) {
//      GsTLGridProperty* prop = grid->add_property(prop_name.toStdString());
//      properties.push_back( prop );
//		}
	}

  int beg_data_pos = infile.tellg();
  std::vector<bool> mask;
  mask.reserve(grid->rgrid_size());
  int size_active=0;

// Read Mask

  for( int i=0; i < grid->rgrid_size() ; i++ ) {
		std::getline( infile, buffer, '\n');
    QString qbuffer(buffer.c_str());
    QStringList buf = qbuffer.split(" ",QString::SkipEmptyParts);

		//std::vector<std::string> buf = String_Op::decompose_string(buffer, " ", false);
    if(buf.size() < total_columns) {
	    GsTLcerr << "Invalid file format\n Line " <<i<<" does not have " <<total_columns<<" columns"<< gstlIO::end;
		  return NULL;
    }
    bool is_active = buf[maskColNumber].toFloat() == 1. ;
    mask.push_back( is_active );
	}
  grid->mask( mask );


// We are at the end of the file, if more data are present,
// it is another realizations
	float val;
	if( infile >> val ) has_multi_real = true;

	// reposition the stream
	infile.clear();
	infile.seekg( 0 );
	std::getline( infile, buffer, '\n');
	std::getline( infile, buffer, '\n');

	if( has_multi_real ) {
		std::vector<MultiRealization_property*> properties;
		for( int i=0; i<total_columns; i++ ) {
			std::getline( infile, buffer, '\n');
			QString prop_name( buffer.c_str() );
			MultiRealization_property* prop;

			if (i != maskColNumber ) {
//				QByteArray tmp = prop_name.simplified().toAscii();
        prop = grid->add_multi_realization_property( prop_name.toStdString() );
				if( !prop ) {
					GsTLcerr << "Several properties share the same name " << gstlIO::end;
					return 0;
				}
				properties.push_back( prop );
			}
		}

		while( infile ) {
			if( !infile ) break;
      char c = infile.peek();
      if( !std::isdigit(c) ) break;

			std::vector<GsTLGridProperty*> props;
      std::vector<MultiRealization_property*>::iterator multi_prop_it = properties.begin();
			for( unsigned int ii=0; ii < total_columns; ii++) {	
        if (ii != maskColNumber) {
				  GsTLGridProperty* prop = (*multi_prop_it)->new_realization();
          multi_prop_it++;
				  props.push_back( prop );
        }
			}
      if( props.size() > 0 )  // If onyl the mask was present in the file
			  read_one_realization( infile, props, grid );
		}
	}

	else {
		std::vector<GsTLGridProperty*> properties;
		for( int i=0; i<total_columns; i++ ) {
			std::getline( infile, buffer, '\n');
			QString prop_name( buffer.c_str() );
    
			if (i != maskColNumber) {
				GsTLGridProperty* prop = 
          grid->add_property( prop_name.toStdString() );
				properties.push_back( prop );
			}
		} 
    if( properties.size() > 0 )  // If onyl the mask was present in the file
		  read_one_realization( infile, properties, grid);
  }
	return grid;
}


bool Gslib_mgrid_infilter::
read_one_realization( std::ifstream& infile, 
                      const std::vector<GsTLGridProperty*>& properties,
                      Reduced_grid * grid) 
{

  // read the property values
  int property_count = properties.size()+1;  //with mask
  long int index = 0, mask_index = 0;
  std::string buffer;
  float val;
  std::vector< std::string > nums;
  float no_data_value;
  int maskColumnNum = dialog_->mask_column();
  bool  use_no_data_value = dialog_->use_no_data_value();

  if( dialog_->use_no_data_value() ) 
    no_data_value = dialog_->no_data_value();

  while( infile && (index < grid->rgrid_size()) ) {
	  std::getline( infile, buffer, '\n');
	  // if inactive
	  if (!grid->is_inside_mask(index)) {
      index++;
		  continue;
	  }
    QString qbuffer(buffer.c_str());
    QStringList nums = qbuffer.split(" ",QString::SkipEmptyParts);

//	  nums = String_Op::decompose_string( buffer, " ", false );

// Mask presents
	  int prop_index = 0;
    
	  for (int i = 0; i < property_count; ++i){
      if (nums.size() == property_count && i == maskColumnNum-1) {
        continue;
      }
		 // val = String_Op::to_number<float>(nums[i]);
      val = nums[i].toFloat();
		  if ( use_no_data_value && val == no_data_value) {
			  prop_index++;
  			continue;
		  }
		  properties[prop_index]->set_value(val,mask_index);
		  prop_index++;
	  }
  	mask_index++;
    index++;

  }  

  return true;
}


Geostat_grid* Gslib_mgrid_infilter::readPointsetFormat(std::ifstream& infile, Reduced_grid * grid)
{
  
	int X_col_id = dialog_->X_column()-1;
	int Y_col_id = dialog_->Y_column()-1;
	int Z_col_id = dialog_->Z_column()-1;	
	if( X_col_id == Y_col_id || X_col_id == Z_col_id || Y_col_id == Z_col_id ) {
		GsTLcerr << "The same column number was selected for multiple coordinates \n" << gstlIO::end;
		return 0;
	}
	float x_size = dialog_->x_size();
	float y_size = dialog_->y_size();
	float z_size = dialog_->z_size();

  if(x_size< 0. || y_size< 0. || z_size< 0. ) {
    GsTLcerr << "Pixel size must be positive "<< gstlIO::end;
    return NULL;
  }

  get_mgrid_xyz_dimensions(infile,grid,X_col_id,Y_col_id,Z_col_id,
                             x_size,y_size,z_size);

  infile.clear();
  infile.seekg(0, ios::beg);

  this->read_data(infile,grid,X_col_id,Y_col_id,Z_col_id,
                             x_size,y_size,z_size);
/*
	std::string buffer;
	// read title
	std::getline( infile, buffer, '\n');
  std::cout<<buffer<<std::endl;


	// read nb of columns
	int columns_count;  
	infile >> columns_count;
  std::cout<<columns_count;
	std::getline( infile, buffer, '\n');

	// read property names 
	std::vector<GsTLGridProperty*> properties;
	for( int i=0; i<columns_count; i++ ) {
		std::getline( infile, buffer, '\n');
		if( i != X_col_id && i != Y_col_id && i != Z_col_id ) {
      GsTLGridProperty* prop = grid->add_property( buffer);
      properties.push_back( prop );
		}
	}

	// read the property values
	float val;
	int count = 0;
	bool use_no_data_value = dialog_->use_no_data_value();
	float no_data_value = dialog_->no_data_value();

	while( infile ) {
		std::getline( infile, buffer, '\n');
    if (buffer.empty()) break;

    QString qbuffer(buffer.c_str());
    QStringList buf = qbuffer.split(" ",QString::SkipEmptyParts);


   // std::vector<std::string> buf = String_Op::decompose_string( buffer, " ", false );
    

    int node_id;
    Geostat_grid::location_type loc;
    loc[0] = buf[X_col_id].toDouble();
		loc[1] = buf[Y_col_id].toDouble();
		loc[2] = buf[Z_col_id].toDouble();
	  //loc[0] = String_Op::to_number<GsTLCoord>(buf[X_col_id]);
	  //loc[1] = String_Op::to_number<GsTLCoord>(buf[Y_col_id]);
	  //loc[2] = String_Op::to_number<GsTLCoord>(buf[Z_col_id]);
    GsTLGridNode ijk;
    grid->geometry()->grid_coordinates(ijk,loc);
    node_id = grid->cursor()->node_id(ijk[0],ijk[1],ijk[2]);

    if(node_id < 0) continue;
    int property_index = 0;
		for( int j=0; j< columns_count; j++ ) {
			if (j != X_col_id && j != Y_col_id && j != Z_col_id){	
				//val = String_Op::to_number<float>(buf[j]);
        val = buf[j].toFloat();
				if( use_no_data_value ) {
					if( val == no_data_value )
						val = GsTLGridProperty::no_data_value;          
				}
        properties[ property_index ]->set_value(val,node_id);
				property_index++;
			}

		}
	}
  infile.close();
  */
  std::cout<<"Finished reading mgrid as pointset"<<std::endl;


	return grid;
}

bool Gslib_mgrid_infilter::read_data(
    std::ifstream& infile, Reduced_grid* grid, 
    int X_col_id, int Y_col_id, int Z_col_id,
    float x_size, float y_size, float z_size){


	std::string buffer;
	// read title
	std::getline( infile, buffer, '\n');
  std::cout<<buffer<<std::endl;


	// read nb of columns
	int columns_count;  
	infile >> columns_count;
  std::cout<<columns_count;
	std::getline( infile, buffer, '\n');

	// read property names 
	std::vector<GsTLGridProperty*> properties;
	for( int i=0; i<columns_count; i++ ) {
		std::getline( infile, buffer, '\n');
		if( i != X_col_id && i != Y_col_id && i != Z_col_id ) {
      GsTLGridProperty* prop = grid->add_property( buffer);
      properties.push_back( prop );
		}
	}

	// read the property values
	float val;
	int count = 0;
	bool use_no_data_value = dialog_->use_no_data_value();
	float no_data_value = dialog_->no_data_value();

	while( infile ) {
		std::getline( infile, buffer, '\n');
    if (buffer.empty()) break;

    QString qbuffer(buffer.c_str());
    QStringList buf = qbuffer.split(" ",QString::SkipEmptyParts);

    int node_id;
    Geostat_grid::location_type loc;
    loc[0] = buf[X_col_id].toDouble();
		loc[1] = buf[Y_col_id].toDouble();
		loc[2] = buf[Z_col_id].toDouble();

    GsTLGridNode ijk;
    grid->geometry()->grid_coordinates(ijk,loc);
    node_id = grid->cursor()->node_id(ijk[0],ijk[1],ijk[2]);

    if(node_id < 0) continue;
    int property_index = 0;
		for( int j=0; j< columns_count; j++ ) {
			if (j != X_col_id && j != Y_col_id && j != Z_col_id){	
				//val = String_Op::to_number<float>(buf[j]);
        val = buf[j].toFloat();
				if( use_no_data_value ) {
					if( val == no_data_value )
						val = GsTLGridProperty::no_data_value;          
				}
        properties[ property_index ]->set_value(val,node_id);
				property_index++;
			}

		}
	}
  return true;

}



Geostat_grid* Gslib_mgrid_infilter::read( std::ifstream& infile ) 
{
//	QByteArray tmp  =dialog_->name().simplified().toLatin1();
	//std::string name( tmp.constData() );
  std::string name = dialog_->name().toStdString();

  // ask manager to get a new grid and initialize it
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager + "/" + name );

  if( ni.raw_ptr() != 0 ) {
    GsTLcerr << "object " << name << " already exists\n" << gstlIO::end;
    return 0;
  }

  ni = Root::instance()->new_interface( "reduced_grid", 
                                        gridModels_manager + "/" + name );
  Reduced_grid* grid = dynamic_cast<Reduced_grid*>( ni.raw_ptr() );
  appli_assert( grid != 0 );

  if (dialog_->is_xyz_file())
    return readPointsetFormat(infile, grid);
  else
	  return readRegularGridFormat(infile, grid);	  
}

bool Gslib_mgrid_infilter::has_valid_parameters() const{
  bool ok = true;
  ok = ok && dialog_->x_size() > 0.;
  ok = ok && dialog_->y_size() > 0.;
  ok = ok && dialog_->z_size() > 0.;
  ok = ok && !dialog_->name().isEmpty();
  return ok;
}

//========================================================


Gslib_grid_infilter::Gslib_grid_infilter() 
: dialog_( new Gslib_input_grid_dialog( qApp->activeWindow() ) ) {
}

Gslib_grid_infilter::~Gslib_grid_infilter() {
  // deleting dialog_ causes a segfault. See why.
  //  delete dialog_;
  dialog_ = 0;
}

QWidget* Gslib_grid_infilter::init_dialog( std::ifstream& ) {
  dialog_ = new Gslib_input_grid_dialog( qApp->activeWindow() );
  return dialog_;
}


Geostat_grid* Gslib_grid_infilter::read( std::ifstream& infile ) {

  int nx = dialog_->nx();
  int ny = dialog_->ny();
  int nz = dialog_->nz();
  float x_size = dialog_->x_size();
  float y_size = dialog_->y_size();
  float z_size = dialog_->z_size();
  float Ox = dialog_->Ox();
  float Oy = dialog_->Oy();
  float Oz = dialog_->Oz();

  QByteArray tmp = dialog_->name().simplified().toLatin1();
  std::string name( tmp.constData() );

  // ask manager to get a new grid and initialize it
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager + "/" + name );

  if( ni.raw_ptr() != 0 ) {
    GsTLcerr << "object " << name << " already exists\n" << gstlIO::end;
    return 0;
  }

  appli_message( "creating new grid '" << name << "'" 
		             << " of dimensions: " << nx << "x" << ny << "x" << nz);

  ni = Root::instance()->new_interface( "cgrid", 
                                        gridModels_manager + "/" + name );
  Cartesian_grid* grid = dynamic_cast<Cartesian_grid*>( ni.raw_ptr() );
  appli_assert( grid != 0 );

  grid->set_dimensions( nx, ny, nz,
			x_size, y_size, z_size);
  grid->origin( GsTLPoint( Ox,Oy,Oz) );
  appli_message( "grid resized to " << nx << "x" << ny << "x" << nz
		<< "  total=: " << grid->size() );

  std::string buffer;
  
  //-------------------------
  //   now, read the file

  // read title
  std::getline( infile, buffer, '\n');

  // read nb of properties
  int property_count;
  infile >> property_count;
  std::getline( infile, buffer, '\n');

  
  // check whether the file contains multiple realizations
  bool has_multi_real = false;

  int lines_to_skip = grid->size() + property_count;
  for( int pos=0; pos < lines_to_skip ; pos++ )
    std::getline( infile, buffer, '\n');
  float val;
  if( infile >> val ) has_multi_real = true;
  
  // reposition the stream
  infile.clear();
  infile.seekg( 0 );
  std::getline( infile, buffer, '\n');
  std::getline( infile, buffer, '\n');

  if( has_multi_real ) {
    std::vector<MultiRealization_property*> properties;
    for( int i=0; i<property_count; i++ ) {
	  std::getline( infile, buffer, '\n');
      QString prop_name( buffer.c_str() );
      MultiRealization_property* prop;
	  QByteArray tmp = prop_name.simplified().toAscii();
	  prop = grid->add_multi_realization_property( tmp.constData() );
	  if( !prop ) {
		  GsTLcerr << "Several properties share the same name " << gstlIO::end;
		  return 0;
	  }

	  properties.push_back( prop );

	}


    while( infile ) {
      if( !infile ) break;
      char c = infile.peek();
      if( !std::isdigit(c) ) break;

      std::vector<GsTLGridProperty*> props;
	  int index = 0;
      for( unsigned int ii=0; ii < property_count; ii++) {
		 
		  GsTLGridProperty* prop = properties[index]->new_realization();
		  props.push_back( prop );
		  ++index;

      }
      read_one_realization( infile, props, grid->size() );
    }
  }

  else {
    std::vector<GsTLGridProperty*> properties;
    for( int i=0; i<property_count; i++ ) {
	  std::getline( infile, buffer, '\n');
      QString prop_name( buffer.c_str() );
	 
	  QByteArray tmp  =prop_name.simplified().toAscii();
      GsTLGridProperty* prop = 
		  grid->add_property( tmp.constData() );
      properties.push_back( prop );
	}    
    read_one_realization( infile, properties, grid->size() );

  }
  
  return grid;
}


bool Gslib_grid_infilter::
read_one_realization( std::ifstream& infile, 
                      const std::vector<GsTLGridProperty*>& properties,
                      long int grid_size) {
  // read the property values
  int property_count = properties.size();
  long int count = 0;
  long int max_read = properties.size() * grid_size;
  float val;

  if( dialog_->use_no_data_value() ) {
    float no_data_value = dialog_->no_data_value();

    while( infile && count < max_read ) {
      infile >> val;
      int prop_id = count % property_count;
      int node_id = count / property_count;
      if( val != no_data_value )
        properties[prop_id]->set_value( val, node_id );
  
      count ++;
    }
    
  }
  else {
    // there is no "no-data-value"
    while( infile && count < max_read ) {
      infile >> val;
      int prop_id = count % property_count;
      int node_id = count / property_count;
      properties[prop_id]->set_value( val, node_id );
      count ++;
    }
  }

  std::string buffer;
  std::getline( infile, buffer, '\n' );
  return true;
}



bool Gslib_grid_infilter::has_valid_parameters() const {
  return !dialog_->name().isEmpty();
}





//==============================================================
Named_interface* Gslib_poinset_infilter::create_new_interface( std::string& ) {
  return new Gslib_poinset_infilter();
}

Gslib_poinset_infilter::Gslib_poinset_infilter() 
  : dialog_( new Gslib_input_pointset_dialog( qApp->activeWindow() ) ) {
}

Gslib_poinset_infilter::~Gslib_poinset_infilter() {
//  delete dialog_;
  dialog_ = 0;
}

QWidget* Gslib_poinset_infilter::init_dialog( std::ifstream& infile ) {
  dialog_ = new Gslib_input_pointset_dialog( infile, qApp->activeWindow() );
  return dialog_;
}

bool Gslib_poinset_infilter::has_valid_parameters() const {
  return !dialog_->name().isEmpty();
}

Geostat_grid* Gslib_poinset_infilter::read( std::ifstream& infile ) {

	QByteArray tmp = dialog_->name().simplified().toLatin1();
	std::string name( tmp.constData() );

  const int X_col_id = dialog_->X_column()-1;
  const int Y_col_id = dialog_->Y_column()-1;
  const int Z_col_id = dialog_->Z_column()-1;
  
  if( X_col_id == Y_col_id || X_col_id == Z_col_id || Y_col_id == Z_col_id ) {
    GsTLcerr << "The same column number was selected for multiple coordinates \n" << gstlIO::end;
    return 0;
  }

  std::string buffer;
  
  //-------------------------
  //   now, read the file

  // read title
  std::getline( infile, buffer, '\n');

  // read nb of columns
  int columns_count;
  infile >> columns_count;
  std::getline( infile, buffer, '\n');


  // read property names 
  std::vector<std::string> property_names;
  for( int i=0; i<columns_count; i++ ) {
    std::getline( infile, buffer, '\n');
    QString prop_name( buffer.c_str() );

    if( i != X_col_id && i != Y_col_id && i != Z_col_id ) {
		QByteArray tmp = prop_name.simplified().toAscii();
		property_names.push_back( tmp.constData() );
    }
  }

  std::vector< std::vector<float> > property_values( property_names.size() );
  std::vector< Point_set::location_type > point_locations;

  // read the property values
  // change to double for max precision
  double val;
  bool use_no_data_value = dialog_->use_no_data_value();

  while( infile ) {
    int property_index=0;
    Point_set::location_type loc;
    for( int j=0; j< columns_count; j++ ) {
      if( ! (infile >> val) ) {
	      break;
      }
      bool is_property_value = true;

      if( j == X_col_id ) {
	      loc[0] = val;
	      is_property_value = false;
      }
      if( j == Y_col_id ) {
	      loc[1] = val;
	      is_property_value = false;
      }
      if( j == Z_col_id ) {
	      loc[2] = val;
	      is_property_value = false;
      }
      if( is_property_value ) {
        if( use_no_data_value ) {
          float no_data_value = dialog_->no_data_value();
          if( val == no_data_value )
            val = GsTLGridProperty::no_data_value;          
        }
  	    property_values[ property_index ].push_back( val );
	      property_index++;
      }
	
    }
    if( infile )
      point_locations.push_back( loc );
  }
  //   done reading file
  //----------------------------

  int point_set_size = point_locations.size();
  appli_message( "read " << point_set_size << " points" );

  // We now have a vector containing all the locations and another one with
  // all the property values.
  // Create a pointset, initialize it with the data we collected, and we're done
 
  // ask manager to get a new pointset and initialize it
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager + "/" + name );

  if( ni.raw_ptr() != 0 ) {
    GsTLcerr << "object " << name << " already exists\n" << gstlIO::end;
    return 0;
  }

  std::string size_str = String_Op::to_string( point_set_size );
  ni = Root::instance()->new_interface( "point_set://" + size_str, 
					gridModels_manager + "/" + name );
  Point_set* pset = dynamic_cast<Point_set*>( ni.raw_ptr() );
  appli_assert( pset != 0 );

  pset->point_locations( point_locations );

  for( unsigned int k= 0; k < property_names.size(); k++ ) {
    GsTLGridProperty* prop = pset->add_property( property_names[k] );
    for( int l=0; l < point_set_size; l++ ) {
      prop->set_value( property_values[k][l], l );
    }
  }

  return pset;
}





//===========================================================
Gslib_outfilter::Gslib_outfilter()  {

}

Gslib_outfilter::~Gslib_outfilter() {

}

bool Gslib_outfilter::write( std::string outfile, const Geostat_grid* grid, 
                            std::string* errors ) 
{
  std::ofstream out( outfile.c_str() );
  out.precision(12);
  if( !out ) {
    if( errors )
      errors->append( "can't write to file: " + outfile );
    return false;
  }

  return this->write( out, grid );
}

bool Gslib_outfilter::writeReduced2Cartesian( std::ofstream& outfile, const Geostat_grid* grid ) 
{
	typedef std::list<std::string>::const_iterator string_iterator; 
	std::vector< const GsTLGridProperty* > properties;
    std::list<std::string> & property_names = _list_to_write;
	const Reduced_grid * rgrid = dynamic_cast<const Reduced_grid *>(grid);

	if (!rgrid) return false;

	int nb_properties = property_names.size();

	outfile << nb_properties << std::endl;

	for( string_iterator it = property_names.begin(); it != property_names.end();
		++ it ) 
	{
		outfile << *it << std::endl;
		properties.push_back( grid->property( *it ) );
	}
//	outfile << rgrid->maskColumn() << std::endl; //use saved name for the mask column

	int grid_size = rgrid->rgrid_size();

	// Write the property values
	for( int i=0; i < grid_size ; i++ ) {
		for( unsigned int j=0; j < property_names.size(); ++j ) {
      if (rgrid->is_inside_mask(i)) {
				appli_assert(rgrid->full2reduced(i) != -1);
				if (!properties[j]->is_informed(rgrid->full2reduced(i))) 
					cout << "-9999 ";
				
				outfile << properties[j]->get_value( rgrid->full2reduced(i) ) << " ";
			}
			else 
				outfile << "-9999 ";
		}

		if (rgrid->is_inside_mask(i)) {
			outfile << "1 ";
		}
		else
			outfile << "0 ";
		outfile << std::endl;
	}
	return true;
}

bool Gslib_outfilter::write( std::ofstream& outfile, const Geostat_grid* grid ) {
  /* Not all objects are saved the same way: if we are dealing with a 
   * stratigraphic grid, we don't need to save the point coordinates.
   */

  // write the name of the object
  std::string grid_name;
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager );
  Manager* dir = dynamic_cast<Manager*>( ni.raw_ptr() );
  appli_assert( dir );
  grid_name = dir->name( (Named_interface* ) grid );

  const RGrid * rgrid;
  if (rgrid = dynamic_cast<const RGrid*>(grid))
	outfile << grid_name << " " << "(" << rgrid->nx() << "x" << rgrid->ny() 
			<< "x" << rgrid->nz() << ")" << std::endl;
  else
	  outfile << grid_name << std::endl;
  
  typedef std::list<std::string>::const_iterator string_iterator; 
  std::list<std::string> & property_names = _list_to_write;
  //std::list<std::string> property_names = grid->property_list();
  std::vector< const GsTLGridProperty* > properties;

  bool output_locations = false;
  int nb_properties = property_names.size();

  //TL modified
  if( dynamic_cast<const Point_set*>( grid ) || dynamic_cast<const Reduced_grid*>(grid)) {
    output_locations = true;
    nb_properties += 3;
  }


  // write number of properties and property names 
  outfile << nb_properties << std::endl;
  if( output_locations )
    outfile << "X" << std::endl 
	    << "Y" << std::endl
	    << "Z" << std::endl;
  
  for( string_iterator it = property_names.begin(); it != property_names.end();
       ++ it ) {
    outfile << *it << std::endl;
    properties.push_back( grid->property( *it ) );
  }
  
  int grid_size;
  if( properties.empty() )
    grid_size = 0;
  else
    grid_size = properties[0]->size();

  // Write the property values
  for( int i=0; i < grid_size ; i++ ) {
    if( output_locations ) {

	  Geostat_grid::location_type loc = grid->location( i );
		std::stringstream ss_x, ss_y, ss_z;
		
		ss_x.precision(std::numeric_limits<GsTLCoord>::digits10);//override the default
    ss_y.precision(std::numeric_limits<GsTLCoord>::digits10);//override the default
    ss_z.precision(std::numeric_limits<GsTLCoord>::digits10);//override the default
		ss_x << loc.x();
    ss_y << loc.y();
    ss_z << loc.z();
       
    outfile << ss_x.str()<<" "<<ss_y.str() << " " << ss_z.str()<< " ";

	}
    for( unsigned int j=0; j < property_names.size(); ++j ) {
      if( properties[j]->is_informed( i ) )
        outfile << properties[j]->get_value( i ) << " ";
      else
        outfile << static_cast<int>(GsTLGridProperty::no_data_value)<<" ";
	
    }
	
    outfile << std::endl;
  }
  return true;
}

