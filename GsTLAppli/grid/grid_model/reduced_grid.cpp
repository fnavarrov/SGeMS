/**********************************************************************
** Author: Ting Li
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
** All rights reserved.
**
** This file is part of the "grid" module of the Geostatistical Earth
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

#include <GsTLAppli/grid/grid_model/reduced_grid.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/mgrid_neighborhood.h>
//#include <GsTLAppli/grid/maskedgridcursor.h>

Named_interface* create_reduced_grid( std::string& size_str){
  return new Reduced_grid();

	if( size_str.empty() )
		return new Reduced_grid();
	else {
		int size = String_Op::to_number<int>( size_str );
		appli_assert( size >= 0 );
		return new Reduced_grid( size );
	}

}

Reduced_grid::Reduced_grid(int size) : active_size_(size) {
	property_manager_.set_prop_size( size );
  region_manager_.set_region_size( size );
}

Reduced_grid::Reduced_grid() : active_size_(0)  {}



Neighborhood* Reduced_grid::neighborhood( double x, double y, double z,
				   double ang1, double ang2, double ang3,
				   const Covariance<location_type>* cov,
				   bool only_harddata ) {

  // The constructor of Rgrid_ellips_neighborhood expects the dimensions
  // of the search ellipsoid to be in "number of cells", and the covariance
  // ranges to be expressed in term of "number of cells".

  int nx = GsTL::round( x /geometry_->cell_dims()[0] );
  int ny = GsTL::round( y /geometry_->cell_dims()[1] );
  int nz = GsTL::round( z /geometry_->cell_dims()[2] );

  // The ranges of the covariance of a Neighborhood must be expressed
  // in "number of cells", while they are supplied to the rgrid in 
  // "actual" unit. So do the convertion. 
  Covariance<location_type>* cov_copy = 0;

  if( cov ) {
    cov_copy = new Covariance<location_type>( *cov );
    for( int i=0; i < cov_copy->structures_count() ; i++ ) {
      double R1,R2,R3;
      cov_copy->get_ranges( i, R1,R2,R3 );
      cov_copy->set_ranges( i,
		       R1/geometry_->cell_dims()[0],
		       R2/geometry_->cell_dims()[1],
		       R3/geometry_->cell_dims()[2] );
    }
  }

  if( only_harddata )
    return new MgridNeighborhood_hd( this, 
					     property_manager_.selected_property(),
					     nx,ny,nz, ang1,ang2,ang3,
					     20, cov_copy );
  else
    return new MgridNeighborhood( this, 
					  property_manager_.selected_property(),
					  nx,ny,nz, ang1,ang2,ang3,
					  20, cov_copy );

  delete cov_copy;
}



Neighborhood* Reduced_grid::neighborhood( const GsTLTripletTmpl<double>& dim,
				   const GsTLTripletTmpl<double>& angles,
				   const Covariance<location_type>* cov,
				   bool only_harddata ) {
  int nx = GsTL::round( dim[0] /geometry_->cell_dims()[0] );
  int ny = GsTL::round( dim[1] /geometry_->cell_dims()[1] );
  int nz = GsTL::round( dim[2] /geometry_->cell_dims()[2] );

  Covariance<location_type>* cov_copy = 0;

  if( cov ) {
    cov_copy = new Covariance<location_type>( *cov );
    for( int i=0; i < cov_copy->structures_count() ; i++ ) {
      double R1,R2,R3;
      cov_copy->get_ranges( i, R1,R2,R3 );
      cov_copy->set_ranges( i,
		       R1/geometry_->cell_dims()[0],
		       R2/geometry_->cell_dims()[1],
		       R3/geometry_->cell_dims()[2] );
    }
  }

  if( only_harddata )
    return new MgridNeighborhood_hd( this, 
					     property_manager_.selected_property(),
					     nx,ny,nz,
					     angles[0], angles[1], angles[2],
					     20, cov_copy );
  else
    return new MgridNeighborhood( this, 
					  property_manager_.selected_property(),
					  nx,ny,nz,
					  angles[0], angles[1], angles[2],
					  20, cov_copy );
}

Window_neighborhood* Reduced_grid::window_neighborhood( const Grid_template& templ) {
  return new MgridWindowNeighborhood( templ, this,
					property_manager_.selected_property() );
}
  

// new methods
//====================================
void Reduced_grid::copyStructure(const Reduced_grid * from)
{
	GsTLCoordVector v = from->cell_dimensions();
//	set_dimensions(from->nx(), from->ny(), from->nz(), v.x(), v.y(), v.z());
	origin(from->origin());

	reduced2original_ = from->reduced2original_;
	original2reduced_ = from->original2reduced_;
	active_coords_ = from->active_coords_;
	_maskColumn = from->_maskColumn;
	grid_cursor_ = from->grid_cursor_;
	active_size_ = from->active_size_;

	mask_ = from->mask_;
}


bool Reduced_grid::populate(QDataStream& stream, std::vector< char* > & prop_names)
{
	int i,j;

	for (i = 0; i < geometry_->size(); ++i)
		mask_[i] = false;

	int nxy = geometry_->dim(0)*geometry_->dim(1);
	for (i = 0; i < active_size_; ++i) {
		int x,y,z,index;
		stream >> x >> y >> z; // these are really i,j,k values
		index = z*nxy+y*geometry_->dim(0)+x;

		mask_[index] = true;
		reduced2original_[i] = index;
		original2reduced_[index] = i;
		active_coords_.push_back(GsTLGridNode(x,y,z));	
	}

	grid_cursor_ = new MaskedGridCursor(geometry_->dim(0),geometry_->dim(1),geometry_->dim(2),
                                      &original2reduced_, &reduced2original_, &mask_);

	for (i = 0; i < prop_names.size(); ++i) {
		std::string prop_name = prop_names[i];
		GsTLGridProperty * d = property_manager_.add_property(prop_name);

		if (!d) return false;

		for (j = 0; j < active_size_; ++j) {
			float buf;
			stream >> buf;
			d->set_value(buf,j);
		}
	}
	return true;
}


// returns nx*ny*nz
GsTLInt Reduced_grid::rgrid_size() const {
	return RGrid::size();
}

/*
void Reduced_grid::buildIJK()
{
	int i;
	if (mask_.empty()) return;
	active_coords_.clear();
	for (i = 0; i < active_size_; ++i) 
		active_coords_.push_back(Reduced_grid::ijkValue(i));	
}
*/
/*
const std::vector<GsTLGridNode> & Reduced_grid::psIJK() const { 
	return active_coords_;
}
*/
/*
void Reduced_grid::initMaskedGrid(bool regular) {
	long int count = 0;
	for (int i = 0; i < mask_.size(); ++i)
		if (mask_[i] == true)
			++count;
	appli_assert(count);
	active_size_ = count;
	property_manager_.set_prop_size( active_size_ );
	grid_cursor_ = new MaskedGridCursor(geometry_->dim(0),geometry_->dim(1),geometry_->dim(2),
                                      &original2reduced_, &reduced2original_, &mask_);
	if (regular)
		buildIJK();
}
*/

const int Reduced_grid::full2reduced(int idInFullGrid)	const {
	std::map<int,int>::const_iterator itr = original2reduced_.find(idInFullGrid);
	if (itr == original2reduced_.end()) return -1;
	return itr->second;
}

const int Reduced_grid::reduced2full(int idInReducedGrid) const{
	std::map<int,int>::const_iterator itr = reduced2original_.find(idInReducedGrid);
	if (itr == reduced2original_.end()) return -1;
	return itr->second;
}


inline Geostat_grid::location_type Reduced_grid::location( int node_id ) const { 
	std::map<int,int>::const_iterator itr = reduced2original_.find(node_id);
	node_id = itr->second;
	GsTLInt max_nxy = geometry_->dim(0)*geometry_->dim(1);
	GsTLInt inxy = node_id % max_nxy; 
	GsTLInt k = (node_id - inxy)/max_nxy; 
	GsTLInt j = (inxy - node_id%geometry_->dim(0))/geometry_->dim(0); 
	GsTLInt i = inxy%geometry_->dim(0);

	return geometry_->coordinates( i,j,k ); 
} 

//==============================================

//==============================================
// The following override the functions inherited
void Reduced_grid::set_geometry(RGrid_geometry* geom) {
	if( geom_ != geom ) {
		delete geom_;
		geom_ = geom->clone();
		topology_is_updated_ = false;
	}

  geometry_ = dynamic_cast<Simple_RGrid_geometry*>( geom_ );

}


GsTLInt Reduced_grid::size() const { 
	return active_size_; 
} 


inline  
const SGrid_cursor* Reduced_grid::cursor() const { 
  return dynamic_cast<const SGrid_cursor*>(grid_cursor_); 
} 

inline  
SGrid_cursor* Reduced_grid::cursor() { 
  return dynamic_cast<SGrid_cursor*>(grid_cursor_); 
} 


/*
void Reduced_grid::set_dimensions( int nx, int ny, int nz ) {
  // set up a new geometry and pass it to the rgrid
  Simple_RGrid_geometry* geometry = new Simple_RGrid_geometry();
  geometry->set_size(0, nx);
  geometry->set_size(1, ny);
  geometry->set_size(2, nz);

  set_geometry(geometry);


  geometry_ = dynamic_cast<Simple_RGrid_geometry*>( RGrid::geom_ );
}


*/


void Reduced_grid::set_dimensions( int nx, int ny, int nz,
				     float xsize, float ysize, float zsize,
             std::vector<bool> mask ) 
{

  Cartesian_grid::set_dimensions( nx, ny, nz );
  GsTLCoordVector dims( xsize, ysize, zsize );
  geometry_->set_cell_dims( dims );

  mask_ = mask;
  build_ijkmap_from_mask();

  grid_cursor_ = new MaskedGridCursor(nx, ny, nz,
                  &original2reduced_, &reduced2original_, &mask_ );
  
  active_size_ == grid_cursor_->max_index();
	property_manager_.set_prop_size( grid_cursor_->max_index() );
  region_manager_.set_region_size( grid_cursor_->max_index() );
}



void Reduced_grid::set_dimensions( int nx, int ny, int nz,
    float xsize, float ysize, float zsize)
{

  Cartesian_grid::set_dimensions( nx, ny, nz );
  GsTLCoordVector dims( xsize, ysize, zsize );
  geometry_->set_cell_dims( dims );
  grid_cursor_ = new MaskedGridCursor(nx, ny, nz);

}

void Reduced_grid::mask( const std::vector<GsTLGridNode>& ijkCoords)
{

  build_mask_from_ijk(ijkCoords);
  grid_cursor_->set_mask(&original2reduced_, &reduced2original_, &mask_ );

  active_size_ == grid_cursor_->max_index();
	property_manager_.set_prop_size( grid_cursor_->max_index() );
  region_manager_.set_region_size( grid_cursor_->max_index() );
}

void Reduced_grid::mask( const std::vector<location_type>& xyzCoords)
{
  build_mask_from_xyz(xyzCoords);
  grid_cursor_->set_mask(&original2reduced_, &reduced2original_, &mask_ );

  active_size_ == grid_cursor_->max_index(); 
	property_manager_.set_prop_size( grid_cursor_->max_index() );
  region_manager_.set_region_size( grid_cursor_->max_index() );
}



void Reduced_grid::set_dimensions( int nx, int ny, int nz,
    float xsize, float ysize, float zsize,
    const std::vector<GsTLGridNode>& ijkCoords)
{

  Cartesian_grid::set_dimensions( nx, ny, nz );
  GsTLCoordVector dims( xsize, ysize, zsize );
  geometry_->set_cell_dims( dims );
  grid_cursor_ = new MaskedGridCursor(nx, ny, nz);

  build_mask_from_ijk(ijkCoords);
	grid_cursor_->set_mask(&original2reduced_, &reduced2original_, &mask_ );

  active_size_ == grid_cursor_->max_index();
	property_manager_.set_prop_size( grid_cursor_->max_index() );
  region_manager_.set_region_size( grid_cursor_->max_index() );
}

void Reduced_grid::set_dimensions( int nx, int ny, int nz,
    float xsize, float ysize, float zsize,
    const std::vector<location_type>& xyzCoords,
    Geostat_grid::location_type origin)
{

  Cartesian_grid::set_dimensions( nx, ny, nz );
  GsTLCoordVector dims( xsize, ysize, zsize );
  geometry_->set_cell_dims( dims );
  this->origin( origin);
  grid_cursor_ = new MaskedGridCursor(nx, ny, nz);


  build_mask_from_xyz(xyzCoords);
	grid_cursor_->set_mask(&original2reduced_, &reduced2original_, &mask_ );

  active_size_ = grid_cursor_->max_index(); 
	property_manager_.set_prop_size( grid_cursor_->max_index() );
  region_manager_.set_region_size( grid_cursor_->max_index() );
}


void Reduced_grid::build_ijkmap_from_mask() {
	int i,j,k;
  int index = 0;
  int m_index = 0;

  std::vector<bool>::const_iterator it = mask_.begin();

  for( ; it!= mask_.end(); ++it, ++index) {
    if(!(*it) ) continue;
    grid_cursor_->cartesian_coords(index,i,j,k);
    reduced2original_[m_index] = index;
    original2reduced_[index] = m_index;
    m_index++;

  }
}

void Reduced_grid::build_mask_from_ijk(
    const std::vector<GsTLGridNode>& ijkCoords)
{

  std::vector<GsTLGridNode>::const_iterator it = ijkCoords.begin();
  mask_.clear();
  mask_.insert(mask_.begin(),geometry_->size(),false);
  for( ; it != ijkCoords.end() ; ++it ) {
    int index = grid_cursor_->cartesian_node_id(it->x(),it->y(),it->z());
    if(index >= 0) mask_[index] = true;
  }
  build_ijkmap_from_mask();
}

void Reduced_grid::build_mask_from_xyz(
    const std::vector<location_type>& xyzCoords)
{
  std::vector<location_type>::const_iterator it = xyzCoords.begin();
  mask_.clear();
  mask_.insert(mask_.begin(),geometry_->size(),false);

  GsTLGridNode ijk;
  for( ; it != xyzCoords.end() ; ++it ) {
    geometry_->grid_coordinates(ijk,*it);
    int index = grid_cursor_->cartesian_node_id(ijk[0],ijk[1],ijk[2]);
    if(index >= 0) mask_[index] = true;
  }
  build_ijkmap_from_mask();
}

bool Reduced_grid::add_location(int i, int j, int k)
{
  if(active_size_ >= this->size()) return false;
  const SGrid_cursor* cursor = RGrid::cursor();
  int index = cursor->node_id(i,j,k);
  if(index < 0) return false ;
  mask_[index] = true;
  active_size_++;
  return true;
}

bool Reduced_grid::add_location(GsTLCoord x, GsTLCoord y, GsTLCoord z)
{
  if(active_size_ >= this->size()) return false;
  const SGrid_cursor* cursor = RGrid::cursor();
  int i = x/geometry_->dim(0);
  int j = y/geometry_->dim(1);
  int k = z/geometry_->dim(2);
  int index = cursor->node_id(i,j,k);
  if(index < 0) return false; 
  mask_[index] = true;
  active_size_++;
  return true;
}


const std::vector<bool>& Reduced_grid::mask() const{
  return mask_;
}