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

#include <GsTLAppli/filters/simulacre_filter.h>
#include <GsTLAppli/grid/grid_model/cartesian_grid.h>
#include <GsTLAppli/grid/grid_model/point_set.h>
#include <GsTLAppli/grid/grid_model/reduced_grid.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_region.h>
#include <GsTLAppli/appli/manager_repository.h>

#include <qfile.h>
#include <qdatastream.h>


Named_interface* Simulacre_input_filter::create_new_interface( std::string& ) {
  return new Simulacre_input_filter();
}


Simulacre_input_filter::Simulacre_input_filter() {}

Simulacre_input_filter::~Simulacre_input_filter() {}

bool Simulacre_input_filter::can_handle( const std::string& filename ) { 
  QFile file( filename.c_str() );
  if( !file.open( QIODevice::ReadOnly ) ) return false;

  QDataStream stream( &file );
  quint32 magic_nb;
  stream >> magic_nb;
  if( magic_nb == 0xB211175D ) 
    return true;
  
  return false;
}

//!!There's memory leak in this code when reading a string from the stream under 
// debug mode
Geostat_grid* Simulacre_input_filter::read( const std::string& filename, 
                                           std::string* errors ) {
  QFile file( filename.c_str() );
  if( !file.open( QIODevice::ReadOnly ) ) {
    if( errors ) 
      errors->append( "can't open file: " + filename);
    return false;
  }

  QDataStream stream( &file );
#if QT_VERSION >= 0x040600
	stream.setFloatingPointPrecision(QDataStream::SinglePrecision);
#endif
  quint32 magic_nb;
  stream >> magic_nb;
  if( magic_nb != 0xB211175D ) {
    if( errors )
      errors->append( "wrong file format" );
    return 0;
  }


  char * type;
  stream >> type;
  QString o_type( type );
  QByteArray tmp = o_type.toLatin1();
  std::string object_type(tmp.constData());
#ifndef _DEBUG
  delete []type;
#endif

  //TL modified
  if (object_type == Reduced_grid().classname())
	  return read_reduced_grid(stream, errors);
  if( object_type == Cartesian_grid().classname() ) 
    return read_cartesian_grid( stream, errors );
  if( object_type == Point_set().classname() ) 
    return read_pointset( stream, errors );

  return 0;
}

Geostat_grid* 
Simulacre_input_filter::read_reduced_grid( QDataStream& stream, std::string* errors ) 
{
	char* name;
	qint32 numActive;
	stream >> name;
	QString q_name(name);
	QByteArray tmp = q_name.toLatin1();
	std::string grid_name( tmp.constData() );

	qint32 version;
	stream >> version;
	if( version < 100 ) {
		errors->append( "file too old" );
		return 0;
	}

	stream >> numActive;  //# of active cells

	quint32 nx, ny, nz;
	stream >> nx >> ny >> nz;
	float xsize, ysize, zsize;
	float ox,oy,oz;
	stream >> xsize >> ysize >> zsize >> ox >> oy >> oz;

	std::ostringstream ostr;
	ostr << numActive;

// Read the mask
  std::vector<bool> mask;
  mask.reserve(nx*ny*nz);
  int mask_size = 0;
  for( GsTLInt k = 0; k < nx*ny*nz ; k++ ) {
    bool val;
    stream >> val;
    mask.push_back( val );
    if(val) mask_size++;
  }  
  
  std::string final_grid_name;
	SmartPtr<Named_interface> ni = 
		Root::instance()->new_interface( "reduced_grid://" + ostr.str(),
		gridModels_manager + "/" + grid_name,
		&final_grid_name );
	Reduced_grid* grid = dynamic_cast<Reduced_grid*>( ni.raw_ptr() );

	if (!grid) return false;


	grid->set_dimensions( nx, ny, nz, xsize, ysize, zsize, mask );
	grid->origin( Cartesian_grid::location_type( ox,oy,oz ) );

	quint32 properties_count;
	stream >> properties_count;

	std::vector< char* > prop_names( properties_count );
	for( unsigned int i = 0; i < properties_count; i++ ) 
		stream >> prop_names[i];

  
  for( unsigned int j = 0; j < properties_count; j++ ) {
    std::string prop_name( prop_names[j] );
    GsTLGridProperty* prop = grid->add_property( prop_name );
    for( GsTLInt k = 0; k < numActive ; k++ ) {
      float val;
      stream >> val;
      prop->set_value( val, k );
    }
  }
  read_region_and_goup(stream,errors,grid);
	// clean up
#ifndef _DEBUG	
	for( unsigned int k = 0; k < properties_count; k++ ) {
		delete [] prop_names[k];
	}
	delete [] name;
#endif	

	return grid;

}
 
Geostat_grid* 
Simulacre_input_filter::read_cartesian_grid( QDataStream& stream, 
                                            std::string* errors ) {
  char* name;
  stream >> name;
  QString q_name(name);
  QByteArray tmp = q_name.toLatin1();
  std::string grid_name( tmp.constData() );


  qint32 version;
  stream >> version;
  if( version < 100 ) {
    errors->append( "file too old" );
    return 0;
  }

  quint32 nx, ny, nz;
  stream >> nx >> ny >> nz;
  float xsize, ysize, zsize;
  float ox,oy,oz;
  stream >> xsize >> ysize >> zsize >> ox >> oy >> oz;

  std::string final_grid_name;
  SmartPtr<Named_interface> ni = 
    Root::instance()->new_interface( "cgrid", gridModels_manager + "/" + grid_name,
                                     &final_grid_name );
  Cartesian_grid* grid = dynamic_cast<Cartesian_grid*>( ni.raw_ptr() );
  
  grid->set_dimensions( nx, ny, nz, xsize, ysize, zsize );
  grid->origin( Cartesian_grid::location_type( ox,oy,oz ) );

  quint32 properties_count;
  stream >> properties_count;

  std::vector< char* > prop_names( properties_count );
  for( unsigned int i = 0; i < properties_count; i++ ) 
    stream >> prop_names[i];
  
  for( unsigned int j = 0; j < properties_count; j++ ) {
    std::string prop_name( prop_names[j] );
    GsTLGridProperty* prop = grid->add_property( prop_name );
    for( GsTLInt k = 0; k < nx*ny*nz ; k++ ) {
      float val;
      stream >> val;
      prop->set_value( val, k );
    }
  }
  read_region_and_goup(stream,errors,grid);

#ifndef _DEBUG
  // clean up
  for( unsigned int k = 0; k < properties_count; k++ ) {
    delete [] prop_names[k];
  }
  delete [] name;
#endif

  return grid;
}



Geostat_grid*
Simulacre_input_filter::read_pointset( QDataStream& stream, 
                                      std::string* errors ) {
  
  char* name;
  stream >> name;
  QString q_name(name);
  QByteArray tmp = q_name.toLatin1();
  std::string grid_name( tmp.constData() );


  qint32 version;
  stream >> version;
  if( version < 100 ) {
    errors->append( "file too old" );
    return 0;
  }

  quint32 size;
  stream >> size;
  
  // create a new point set of the correct size
  std::ostringstream ostr;
  ostr << size;
  std::string final_grid_name;
  SmartPtr<Named_interface> ni = 
    Root::instance()->new_interface( "point_set://" + ostr.str(),
                                     gridModels_manager + "/" + grid_name,
                                     &final_grid_name );
  Point_set* grid = dynamic_cast<Point_set*>( ni.raw_ptr() );

  // get the property names
  quint32 properties_count;
  stream >> properties_count;

  std::vector< char* > prop_names( properties_count );
  for( unsigned int i = 0; i < properties_count; i++ ) 
    stream >> prop_names[i];
  
  // read the coordinates of the points
  std::vector<Point_set::location_type > coords;
  for( unsigned int k = 0; k < size; k ++ ) {
    float x,y,z;
    stream >> x >> y >> z;
    coords.push_back( Point_set::location_type( x,y,z) );
  }
  grid->point_locations( coords );


  // read all the properties
  for( unsigned int j = 0; j < properties_count; j++ ) {
    std::string prop_name( prop_names[j] );
    GsTLGridProperty* prop = grid->add_property( prop_name );
    for( GsTLInt k = 0; k < size ; k++ ) {
      float val;
      stream >> val;
      prop->set_value( val, k );
    }
  }

  read_region_and_goup(stream,errors,grid);
#ifndef _DEBUG
  for( unsigned int l = 0; l < properties_count; l++ ) {
    delete [] prop_names[l];
  }
  delete [] name;
#endif
  return grid;
}

void Simulacre_input_filter::
read_region_and_goup(QDataStream& stream, 
                     std::string* errors,
                     Geostat_grid* grid){
  // Read the regions if any
  int size = grid->size();
  while(!stream.atEnd()) {
    char* blockType;
    stream >>blockType;

    if(strcmp(blockType,"RegionBlock") == 0 ) {
      quint32 regions_count;
      stream >> regions_count;
      std::vector< char* > region_names( regions_count );
	    for( unsigned int i = 0; i < regions_count; i++ ) 
		    stream >> region_names[i];

      for( unsigned int j = 0; j < regions_count; j++ ) {
        std::string region_name( region_names[j] );
        GsTLGridRegion* region = grid->add_region( region_name );
        for( GsTLInt k = 0; k < size ; k++ ) {
          bool val;
          stream >> val;
          region->set_region_value( val, k );
        }
      }
    }
    else if(strcmp(blockType,"GroupBlock") == 0 ) {
      quint32 group_count;
      stream >> group_count;
      std::vector< char* > group_names( group_count );
      for( unsigned int i = 0; i < group_count; i++ ) {
        char* group_name;
        char* group_type;
		    stream >> group_name>>group_type;
        GsTLGridPropertyGroup* group = grid->add_group(group_name, group_type);
        quint32 group_size;
        stream>>group_size;
        for(int i=0; i<group_size;i++) {
          char* prop_name;
          stream>>prop_name;
          group->add_property(grid->property( std::string(prop_name) ));
        }
      }
    }
  }

}



//===============================================


Named_interface* Simulacre_output_filter::create_new_interface( std::string& ) {
  return new Simulacre_output_filter();
}


Simulacre_output_filter::Simulacre_output_filter() {
}

Simulacre_output_filter::~Simulacre_output_filter() {
} 


bool Simulacre_output_filter::write( std::string outfile, const Geostat_grid* grid, 
                                     std::string* errors ) {
  QFile file( outfile.c_str() );
  if( !file.open( QIODevice::WriteOnly ) ) {
    if( errors ) 
      errors->append( "can't write to file: " + outfile );
    return false;
  }

  QDataStream stream( &file );
#if QT_VERSION >= 0x040600
	stream.setFloatingPointPrecision(QDataStream::SinglePrecision);
#endif

  // Write a header with a "magic number" and the grid type
  stream << (quint32)0xB211175D;
  stream << grid->classname().c_str();
  
  // write the name of the object
  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( gridModels_manager );
  Manager* grid_manager = dynamic_cast<Manager*>( ni.raw_ptr() );
  appli_assert( grid_manager );
  std::string name = grid_manager->name( (Named_interface*) grid ).c_str();
  stream << name.c_str();


  if ( dynamic_cast<const Reduced_grid*>( grid ) ) 
  	return write_reduced_grid(stream, grid);
  if( dynamic_cast< const Point_set* >( grid ) )
    return write_pointset( stream, grid );
  if( dynamic_cast< const Cartesian_grid* >( grid ) )
    return write_cartesian_grid( stream, grid );

  return false;
}


// This is very much the same as saving a point set, except for the bounding box
// information.
bool Simulacre_output_filter::write_reduced_grid( QDataStream& stream, 
                                                    const Geostat_grid* gstat_grid )
{
	const Reduced_grid * grid = dynamic_cast< const Reduced_grid* >( gstat_grid );
	// write a version number
	stream << (qint32)100;

	// write the number of active cells in the point-set
	stream << (quint32) grid->size();

	// write the grid dimensions
	stream << (quint32) grid->nx() 
		<< (quint32) grid->ny()
		<< (quint32) grid->nz(); 

	// write the cell dimensions
	GsTLCoordVector cell_dims = grid->cell_dimensions();
	stream << (float) cell_dims[0] 
	<< (float) cell_dims[1]
	<< (float) cell_dims[2];

	// write the grid origin
	GsTLPoint origin = grid->origin();
	stream << (float) origin[0] 
	<< (float) origin[1]
	<< (float) origin[2];

// write the mask
  const std::vector<bool> mask = grid->mask();
  std::vector<bool>::const_iterator it_mask = mask.begin();
  for(; it_mask != mask.end(); ++it_mask) stream<< *it_mask;


	// Write the number of properties and the property names
    std::list<std::string> & prop_list = _list_to_write;
	stream << (quint32) prop_list.size();

	std::list<std::string>::iterator it = prop_list.begin();
	for( ; it != prop_list.end(); ++it ) {
		stream << it->c_str() ;
	}

	// write the property values, one property at a time
	it = prop_list.begin();
	for( ; it != prop_list.end(); ++it ) {
		const GsTLGridProperty* prop = grid->property( *it );
		appli_assert( prop );
		for( unsigned int i = 0; i < prop->size(); i++ ) { 
			if( prop->is_informed( i ) )
				stream << (float) prop->get_value( i );
			else
				stream << (float) GsTLGridProperty::no_data_value;
		}
	}
  write_region_and_goup(stream, grid);
	return true;
}

bool Simulacre_output_filter::write_cartesian_grid( QDataStream& stream, 
                                                    const Geostat_grid* gstat_grid ) {

  const Cartesian_grid* grid = 
    dynamic_cast< const Cartesian_grid* >( gstat_grid );

  
  // write a version number
  stream << (qint32)100;

  // write the grid dimensions
  stream << (quint32) grid->nx() 
         << (quint32) grid->ny()
         << (quint32) grid->nz(); 

  // write the cell dimensions
  GsTLCoordVector cell_dims = grid->cell_dimensions();
  stream << (float) cell_dims[0] 
         << (float) cell_dims[1]
         << (float) cell_dims[2];

  // write the grid origin
  GsTLPoint origin = grid->origin();
  stream << (float) origin[0] 
         << (float) origin[1]
         << (float) origin[2];


  // Write the number of properties and the property names
  std::list<std::string> & prop_list = _list_to_write;
  stream << (quint32) prop_list.size();

  std::list<std::string>::iterator it = prop_list.begin();
  for( ; it != prop_list.end(); ++it ) {
    stream << it->c_str() ;
  }
  
  // write the property values, one property at a time
  it = prop_list.begin();
  for( ; it != prop_list.end(); ++it ) {
    const GsTLGridProperty* prop = grid->property( *it );
    appli_assert( prop );
    for( unsigned int i = 0; i < prop->size(); i++ ) { 
      if( prop->is_informed( i ) )
        stream << (float) prop->get_value( i );
      else
        stream << (float) GsTLGridProperty::no_data_value;
    }
  }
  write_region_and_goup(stream, grid);
  return true;
}


bool Simulacre_output_filter::write_pointset( QDataStream& stream, 
                                             const Geostat_grid* gstat_grid ) {
  
  const Point_set* grid = 
    dynamic_cast< const Point_set* >( gstat_grid );
  
  // write a version number
  stream << (qint32)100;

  // write the number of points in the point-set
  stream << (quint32) grid->size();

  // Write the number of properties and the property names
  std::list<std::string> & prop_list = _list_to_write;
  stream << (quint32) prop_list.size();

  std::list<std::string>::iterator it = prop_list.begin();
  for( ; it != prop_list.end(); ++it ) {
    stream << it->c_str() ;
  }


  // write the x,y,z coordinates of each point
  const std::vector<Point_set::location_type>& locs = grid->point_locations();
  std::vector<Point_set::location_type>::const_iterator vec_it = locs.begin();
  for( ; vec_it != locs.end(); ++vec_it ) {
    stream << (float) vec_it->x() << (float) vec_it->y() << (float) vec_it->z();
  }

  // write the property values, one property at a time
  it = prop_list.begin();
  for( ; it != prop_list.end(); ++it ) {
    const GsTLGridProperty* prop = grid->property( *it );
    appli_assert( prop );
    for( unsigned int i = 0; i < prop->size(); i++ ) { 
      if( prop->is_informed( i ) )
        stream << (float) prop->get_value( i );
      else
        stream << (float) GsTLGridProperty::no_data_value;
    }
  }
  write_region_and_goup(stream, grid);

  return true;
}


void Simulacre_output_filter::
write_region_and_goup( QDataStream& stream, const Geostat_grid* grid ) {

  std::list< std::string > region_names = grid->region_list();
  if(!region_names.empty()) {
    stream<<"RegionBlock";
    stream << (quint32)region_names.size();
    std::list< std::string >::iterator it_name  = region_names.begin();

    for( ; it_name != region_names.end(); ++it_name) 
      stream << it_name->c_str();
    
    for( it_name  = region_names.begin() ; it_name != region_names.end(); ++it_name) {
      const GsTLGridRegion* region = grid->region(*it_name);
      for(GsTLGridRegion::const_iterator it=region->begin(); it!=region->end(); ++it) 
        stream << (bool)(*it); 
    }
  }

  // Write the group names and membership
  std::list< std::string > group_names = grid->get_group_names();
  if(!group_names.empty()) {
    stream<<"GroupBlock";
    stream << (quint32)group_names.size();
    std::list< std::string >::iterator it_name  = group_names.begin();

    for( ; it_name != group_names.end(); ++it_name) {
      const GsTLGridPropertyGroup* group = grid->get_group(*it_name);
      stream << group->name().c_str()<<group->type().c_str();
      std::vector<std::string> group_prop_names = group->property_names();
      stream<< (quint32)group_prop_names.size();
      std::vector<std::string>::const_iterator it = group_prop_names.begin();
      for(; it!= group_prop_names.end(); ++it)
        stream<<it->c_str();
    }
  }
}