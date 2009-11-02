/**********************************************************************
** Author: Alexandre Boucher modified from Nicolas Remy
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
Modified from grid_property_manager.cpp
**********************************************************************/

#include <GsTLAppli/grid/grid_model/grid_region_manager.h>
#include <GsTLAppli/utils/string_manipulation.h> 

#include <stdlib.h>



//=================================================

bool Grid_region_manager::reNameRegion(std::string & oldName, std::string & newName)
{
	if( oldName.empty() ) return false; 

	Region_map::iterator it_new = regions_map_.find(newName); 	
	Region_map::iterator it = regions_map_.find(oldName); 

	if (it_new != regions_map_.end()) return false;

	if( it != regions_map_.end() )  {
		int id = it->second;
		regions_map_.erase(it);
		regions_map_[newName] = id;
		return true; 
	}
	else 
		return false; 
}

Grid_region_manager::Grid_region_manager( GsTLInt size ) {
  size_ = size;
  selected_region_ = -1;
}

Grid_region_manager::~Grid_region_manager() {
  std::vector< GsTLGridRegion* >::iterator it = regions_.begin();
  for( ; it != regions_.end() ; ++it )
    if( *it != 0 )
      delete *it;
}


GsTLGridRegion* 
Grid_region_manager::add_region( const std::string& name ) {

  appli_assert( size_ != 0 );
  Region_map::iterator it = regions_map_.find( name );
  if( it == regions_map_.end() ) {
    int new_prop_id = regions_.size();
    regions_map_[name] = new_prop_id;
    regions_.push_back( new GsTLGridRegion( size_, name ) );

    return regions_[ new_prop_id ];
  }
  else
    return 0 ; 
}



bool 
Grid_region_manager::remove_region( const std::string& name ) {
  Region_map::iterator it = regions_map_.find( name );
  if( it != regions_map_.end() ) {
    // delete the propery but don't modify the vector of region*
    // ex: if region 2 is deleted, region 3 does not become region 2,
    // but remains region 3.
    int ind = it->second;
    delete regions_[ind];
    regions_[ind] = 0;
    regions_map_.erase( it );
    return true;
  }
  else
    return false;
}


bool Grid_region_manager::could_conflict( const std::string& name ) {
  // loop through all the string keys and check if they contain "name" as
  // a sub-string
  std::map< std::string, int >::const_iterator it = regions_map_.begin();
  for( ; it != regions_map_.end() ; ++it ) {
    if( it->first.find( name ) != std::string::npos ) return true;
  }

  return false;
}


