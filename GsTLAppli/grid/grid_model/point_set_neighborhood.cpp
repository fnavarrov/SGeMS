/**********************************************************************
** Author: Nicolas Remy
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
/*
#define _SECURE_SCL 0 
#ifdef _DEBUG
#define _HAS_ITERATOR_DEBUGGING 0
#endif
*/

#include <GsTL/geometry/geometry_algorithms.h>
#include <GsTLAppli/grid/grid_model/point_set_neighborhood.h>
#include <GsTLAppli/grid/common.h>

#include <GsTL/geometry/covariance.h>
//#include <GsTL/utils/ann_kd.h>

#include <algorithm>


// Comparison of 2 geovalues g1 and g2 at locations u1 and u2:
// g1 < g2 iff cov(u1,u) < cov(u2,u)  for a given location u.
// Covariance_distance_( g1, g2 ) is true if g1 > g2
class GRID_DECL Covariance_distance_ {
public:
  Covariance_distance_( const GsTLPoint& center,
			const Covariance<GsTLPoint>& cov )
    : center_(center ),
      cov_( cov ) {}

  bool operator () ( const Geovalue& P1, const Geovalue& P2 ) {
    return cov_(P1.location(),center_) > cov_(P2.location(),center_);
  }
  
private:
  GsTLPoint center_;
  Covariance<GsTLPoint> cov_;
};



#ifdef USE_ANN_KDTREE
/* This function selects those points of the point set that are informed
* (for the current property). The locations are stored in locs_, and the
* node id in node_ids_. 
*/
void Point_set_neighborhood::select_informed_pset_locations() {
  if( !pset_ || !property_ ) return;

  locs_.clear();
  node_ids_.clear();

  const std::vector<GsTLPoint>& all_points = pset_->point_locations();
  for( unsigned int i=0 ; i < all_points.size() ; i++ ) {
    if( !property_->is_informed( i ) ) continue;

    locs_.push_back( all_points[i] );
    node_ids_.push_back( i );
  }
}
#endif


Point_set_neighborhood::Point_set_neighborhood( double x,double y,double z,
						double ang1,double ang2,double ang3,
						int max_neighbors,
						Point_set* pset,
						GsTLGridProperty* property,
						const Covariance<location_type>* cov, bool only_harddata )
  : pset_( pset ),
    property_( property ),
    max_neighbors_( max_neighbors ),
    norm_( x,y,z, ang1, ang2, ang3 ),
    only_harddata_(only_harddata),
    use_n_closest_(only_harddata){

   // use_only_informed_node_ = false;
    
    appli_assert((x>=y)&&(y>=z)&&(x>=z));
    appli_assert((x>0)&&(y>0)&&(z>0));
    
    a_=x; b_=y; c_=z;
    ang1_=ang1; ang2_=ang2; ang3_=ang3;

    //cov_ = 0;
	// cov_ must be initiated
	if( cov ) 
      cov_ = new Covariance<location_type>( *cov );
    else
      cov_ = 0;

	coord_transform_ = new CoordTransform(a_,b_,c_,ang1_,ang2_,ang3_);


/* super block */
#ifdef USE_SUPERBLOCKS
 // #warning "using superblocks"
    // Rationale to define the total number of superblocks we want:
    // on average, each block should contain 3 points, assuming the
    // points are evenly distributed in space
    const int max_blocks = 120;
    int total_sblocks = std::min( GsTL::round(pset_->size() / 3), max_blocks );
    sblock_ = new Superblock( pset, x,y,z, ang1,ang2,ang3, total_sblocks );
    

    if( cov ) 
      cov_ = new Covariance<location_type>( *cov );
    else
      cov_ = 0;
#endif
/* end super block */

#ifdef USE_KDTREE 
//#warning "USE_KDTREE decrepated!!!!!!!  use USE_ANN_KDTREE instead!!!!!!!"
    if( pset_ ) {
	  location_type loc;
      const std::vector<GsTLPoint>& locs = pset_->point_locations();
	  for( int i=0; i < locs.size() ; i++ ) {
		loc = (*coord_transform_)(locs[i]);
        kdtree_.insert( loc, i );
	  }
    }

    kdtree_.build();
#endif

#ifdef USE_KDTREE2

  //use_only_informed_node_ =  pset_->selected_property() == property_;
  //use_only_informed_node_ = true;
  if( (use_n_closest_)) {
    int nInformed = 0;
    for(int i=0; i<pset_->size(); ++i) {
      if(property_->is_informed(i)) nInformed++;
    }
    coords_ = new boost::multi_array<GsTLCoord,2>(boost::extents[nInformed][3]);
    idx_.reserve( nInformed );
  }
  else {
    coords_ = new boost::multi_array<GsTLCoord,2>(boost::extents[pset_->size()][3]);
    idx_.reserve( pset_->size() );
  }

  const std::vector<GsTLPoint>& locs = pset_->point_locations();
  if( use_n_closest_ ) {
    index ii = 0;
    for( int i=0; i < locs.size() ; i++ ) {
      if( !property_->is_informed(i) ) continue;
		    location_type loc = (*coord_transform_)(locs[i]);
        (*coords_)[ii][0] = loc[0];
        (*coords_)[ii][1] = loc[1];
        (*coords_)[ii][2] = loc[2];
        ii++;
        idx_.push_back(i);
//          coords[i][3] = i;
	  }
  } else  {
      for( int i=0; i < locs.size() ; i++ ) {
		      location_type loc = (*coord_transform_)(locs[i]);
          (*coords_)[i][0] = loc[0];
          (*coords_)[i][1] = loc[1];
          (*coords_)[i][2] = loc[2];
          idx_.push_back(i);
      }
	}
  kdtree_ = new kdtree2(*coords_, property_, &idx_, true, 3 );
  kdtree_->sort_results = true;
  //kdtree_->set_informatation_property(property_, &idx_);


#endif

#ifdef USE_ANN_KDTREE
    select_informed_pset_locations();

    p_coords_ = new CoordT* [ locs_.size() ];
    for( int i=0; i < locs_.size() ; i++ ) {
      // do anisotropic transformation of the data
      locs_[i] = (*coord_transform_)( locs_[i] );
      p_coords_[i] = locs_[i].raw_access();
    }
    kdtree_ = new KDTree_type( p_coords_, locs_.size(), GsTLPoint::dimension );

    neigh_ids_ = new int[max_neighbors_];
    dists_ = new float[max_neighbors_];
#endif

}


Point_set_neighborhood::~Point_set_neighborhood() {
  delete cov_;

#ifdef USE_SUPERBLOCKS
  delete sblock_;
#endif

#ifdef USE_ANN_KDTREE
  delete [] p_coords_;
  delete [] neigh_ids_;
  delete [] dists_;
#endif

#ifdef USE_KDTREE2
  delete kdtree_;
  delete coords_;

#endif

}

void Point_set_neighborhood::max_size( int s ) {
  max_neighbors_ = std::min( s, pset_->size() );

#ifdef USE_ANN_KDTREE
  delete [] neigh_ids_;
  delete [] dists_;
  neigh_ids_ = new int[max_neighbors_];
  dists_ = new float[max_neighbors_];
#endif
} 



bool Point_set_neighborhood::
select_property( const std::string& prop_name ) {
  if(property_ && prop_name == property_->name()) return true;
  property_ = pset_->property( prop_name );

#ifdef USE_ANN_KDTREE
  select_informed_pset_locations();

#endif

#ifdef USE_KDTREE2

  if(!use_n_closest_) kdtree_->set_property(property_);
  
  else {
    delete kdtree_;
    delete coords_;
    idx_.clear();
    int nInformed = 0;
    for(int i=0; i<pset_->size(); ++i) {
      if(property_->is_informed(i)) nInformed++;
    }
    coords_ = new boost::multi_array<GsTLCoord,2>(boost::extents[nInformed][3]);
    idx_.reserve( nInformed );
    index ii = 0;
    const std::vector<GsTLPoint>& locs = pset_->point_locations();
    for( int i=0; i < locs.size() ; i++ ) {
      if( !property_->is_informed(i) ) continue;
		    location_type loc = (*coord_transform_)(locs[i]);
        (*coords_)[ii][0] = loc[0];
        (*coords_)[ii][1] = loc[1];
        (*coords_)[ii][2] = loc[2];
        ii++;
        idx_.push_back(i);
    }
    kdtree_ = new kdtree2(*coords_, property_, &idx_, true, 3 );
    kdtree_->sort_results = true;
  }


#endif

  return ( property_ != 0 );
}



void Point_set_neighborhood::find_neighbors(const Geovalue& center) {
  neighbors_.clear();
  candidates_.clear();
  neigh_filter_->clear();
  if( !property_ ) return;

  center_ = center;
  center_.set_property_array( property_ );



#ifdef USE_SUPERBLOCKS
  // use superblocks 
  sblock_->get_candidates( candidates_, center.location() );
  
  int candidates_count = candidates_.size();

  // keep only those candidates that are inside the search ellipsoid
  for( int i = 0; i < candidates_count ; i++ ) {

    if( !property_->is_informed( candidates_[i] ) ) continue;
    GsTLPoint p = pset_->location( candidates_[i] );
    double dist = norm_( pset_->location( candidates_[i] ) - center.location() );
    if( dist <= a_ ) {
      neighbors_.push_back( Geovalue( pset_, property_, candidates_[i] ) );
      //neighbors_.push_back( pset_->geovalue( candidates_[i] ) );
    }
  }

  // If we found more than max_neighbors_ neighbors, only keep the 
  // max_neighbors_ closest (using the covariance distance).
  if( int( neighbors_.size() ) >  max_neighbors_ && cov_ != 0 ) {
    std::partial_sort( neighbors_.begin(), neighbors_.begin() + max_neighbors_,
		       neighbors_.end(), 
		       Covariance_distance_( center.location(), *cov_ ) );
    neighbors_.erase(neighbors_.begin() + max_neighbors_, neighbors_.end() );
  }
#endif


#ifdef USE_KDTREE
  location_type loc = (*coord_transform_)(center.location());
  bool keep_searching = true;
  int i=1;
  const int max_iteration = 2;
  while( keep_searching ) { 
    int n = kdtree_.in_sphere( loc, float( a_*i/max_iteration ), candidates_ );
    for( int j=0; j < candidates_.size() ; j++ ) {
	    //First check if that node is informed
	    if( property_->is_informed(candidates_[j])  )
            neighbors_.push_back( Geovalue( pset_, property_, candidates_[j] ) );
    }
    if(neighbors_.size() >= max_neighbors_ || i ==max_iteration ) keep_searching=false;
    else {
      neighbors_.clear();
      candidates_.clear();
      i++;
    }
  }
   
  // If we found more than max_neighbors_ neighbors, only keep the 
  // max_neighbors_ closest (using the covariance distance).
  if( int( neighbors_.size() ) >  max_neighbors_ && cov_ != 0 ) {
    std::partial_sort( neighbors_.begin(), neighbors_.begin() + max_neighbors_,
		       neighbors_.end(), 
		       Covariance_distance_( center.location(), *cov_ ) );
    neighbors_.erase(neighbors_.begin() + max_neighbors_, neighbors_.end() );
  }
#endif


#ifdef USE_ANN_KDTREE

  GsTLPoint loc = center.location();
  kdtree_->annkSearch( loc.raw_access(), max_neighbors_,
                       neigh_ids_, dists_ );

  for( int j=0; j < max_neighbors_ ; j++ ) {
    unsigned int node_id = node_ids_[ neigh_ids_[j] ];
    if( property_->is_informed( node_id ) )
      neighbors_.push_back( Geovalue( pset_, property_, node_id ) );
  }
#endif


#ifdef USE_KDTREE2
  location_type loc = (*coord_transform_)(center.location());
  double a2 = a_*a_;
  std::vector<GsTLCoord> center_node;
  center_node.push_back(loc[0]);
  center_node.push_back(loc[1]);
  center_node.push_back(loc[2]);

  kdtree2_result_vector nearest;

  if(use_n_closest_) {
 
    kdtree_->n_nearest(center_node, max_neighbors_, nearest);

    for (unsigned int i=0; i<nearest.size(); i++) {
      if(nearest[i].dis < a2 ) 
         neighbors_.push_back( Geovalue( pset_, property_, idx_[nearest[i].idx] ) );
    }
  }
  else {

    kdtree_->r_nearest(center_node, a2, nearest);
    int n_neigh = 0;
    for (unsigned int i=0; i<nearest.size()&& n_neigh < max_neighbors_; i++) {
      int node_id = idx_[nearest[i].idx];
  //    if(property_->is_informed(id) ) {
        Geovalue gval( pset_, property_, node_id );
        if(neigh_filter_->is_admissible(gval, center)) {
          neighbors_.push_back( gval );
          n_neigh++;
        }
   //     neighbors_.push_back( Geovalue( pset_, property_, node_id ) );
   //     n_neigh++;
    //  }
    }
  }

  std::sort(neighbors_.begin(), neighbors_.end(),
          Covariance_distance_( center.location(), *cov_ ) );
/*  
  if( neigh_filter_->is_neighborhood_valid() ) 
    std::sort(neighbors_.begin(), neighbors_.end(),
          Covariance_distance_( center.location(), *cov_ ) );
  else
    neighbors_.clear();
*/
#endif

}




void Point_set_neighborhood::
set_neighbors( const_iterator begin, const_iterator end ) {
  neighbors_.clear();
  const_iterator it = begin;
  for( int i =0 ; it != end ; ++it, ++i ) {
    const Geostat_grid* g_grid = it->grid();
    if( g_grid != pset_ ) continue;

    neighbors_.push_back( *it );
    neighbors_[i].set_property_array( property_ );
  }
}


