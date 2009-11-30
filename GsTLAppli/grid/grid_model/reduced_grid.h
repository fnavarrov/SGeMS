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

#ifndef REDUCED_GRID_H
#define REDUCED_GRID_H


#include <GsTLAppli/grid/grid_model/cartesian_grid.h>
#include <GsTLAppli/grid/grid_model/rgrid.h>
#include <GsTLAppli/grid/maskedgridcursor.h>

#include <GsTLAppli/math/gstlvector.h>
#include <GsTLAppli/grid/grid_model/neighborhood.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/grid/grid_model/point_set.h>
#include <GsTLAppli/math/gstlpoint.h>

#include <qdatastream.h>

#include <string>
#include <map>
#include <vector>

#define DIV 5.0  /* neighbor search radius = dim/DIV */


Named_interface* create_reduced_grid( std::string& size_str);

class GRID_DECL Reduced_grid : public Cartesian_grid
{
public:
	Reduced_grid(int size); 
	Reduced_grid();   
  virtual ~Reduced_grid(){} 

	virtual std::string classname() const { return "Masked_grid"; } 

	//====================================
	// new methods
	// this is based on point set read function


	void insertLocation(GsTLGridNode loc){
		active_coords_.push_back(loc);
	}

	void copyStructure(const Reduced_grid *);


	// returns nx*ny*nz
	GsTLInt rgrid_size() const;

	inline bool is_inside_mask(int idInFullGrid) const ;

	// given a node id in full grid, return the corresponding id in masked grid
	// returns -1 if not applicable.
	const int full2reduced(int idInFullGrid) const ;
	const int reduced2full(int idInReducedGrid) const;


	virtual Neighborhood* neighborhood( double x, double y, double z, 
		double ang1, double ang2, double ang3, 
		const Covariance<location_type>* cov=0, 
		bool only_harddata = false  ); 

	virtual Neighborhood* neighborhood( const GsTLTripletTmpl<double>& dim, 
		const GsTLTripletTmpl<double>& angles, 
		const Covariance<location_type>* cov=0, 
		bool only_harddata = false  ); 

	virtual Window_neighborhood* window_neighborhood( const Grid_template& templ ); 

  inline location_type location( int node_id ) const ;

  bool add_location(int i, int j, int k);
  bool add_location(GsTLCoord x, GsTLCoord y, GsTLCoord z);
  bool add_location(int CartesianGridNodeId);


  const std::vector<bool>& mask() const;
  void mask(const std::vector<bool>& mask);
  void mask(const std::vector<GsTLGridNode>& ijkCoords);
  void mask(const std::vector<location_type>& xyzCoords);


//  void set_dimensions( int nx, int ny, int nz);

  void set_dimensions( int nx, int ny, int nz, 
		       float xsize, float ysize, float zsize);

  void set_dimensions( int nx, int ny, int nz, 
		       float xsize, float ysize, float zsize, 
           std::vector<bool> mask ); 

  void set_dimensions( int nx, int ny, int nz,
    float xsize, float ysize, float zsize,
    const std::vector<GsTLGridNode>& ijkCoords);

  void set_dimensions( int nx, int ny, int nz, 
    float xsize, float ysize, float zsize,
    const std::vector<location_type>& xyzCoords,
    Geostat_grid::location_type origin);


	//==============================================
	// The following override the functions inherited from rgrid
	void set_geometry(RGrid_geometry* geom) ;
	GsTLInt size() const ;

  virtual const SGrid_cursor* cursor() const; 
  virtual SGrid_cursor* cursor(); 


	//===============================================

protected:
	
	// translates from an id in reduced grid to an id in the full grid
	std::map<int,int> reduced2original_;

	// the other direction
	std::map<int,int> original2reduced_;

	// stores coordinates of active cells
	std::vector<GsTLGridNode> active_coords_;

	// mask for active cells
	std::vector<bool> mask_;

	// number of active cells
	GsTLInt active_size_;

  MaskedGridCursor* mgrid_cursor_;

  protected :

  void build_ijkmap_from_mask();
  void build_mask_from_ijk(
     const std::vector<GsTLGridNode>& iCoords);


  void build_mask_from_xyz(
    const std::vector<location_type>& xyzCoords);

};


/*
inline GsTLGridNode Reduced_grid::ijkValue(int node_id) const {
	std::map<int,int>::const_iterator itr = reduced2original_.find(node_id);
	node_id = itr->second;
	GsTLInt max_nxy = geom_->dim(0)*geom_->dim(1);
	GsTLInt inxy = node_id % max_nxy; 
	GsTLInt k = (node_id - inxy)/max_nxy; 
	GsTLInt j = (inxy - node_id%geom_->dim(0))/geom_->dim(0); 
	GsTLInt i = inxy%geom_->dim(0);
	return GsTLGridNode(i,j,k);
}
*/
inline bool Reduced_grid::is_inside_mask(int idInFullGrid) const {
  return mask_[idInFullGrid];
}


#endif
