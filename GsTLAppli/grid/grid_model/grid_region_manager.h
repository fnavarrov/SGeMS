/**********************************************************************
** Author: Alexandre Boucher
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

Modified from grid_property_manager.h and .cpp
**********************************************************************/

#ifndef __GSTLAPPLI_GRID_REGION_MANAGER_H__ 
#define __GSTLAPPLI_GRID_REGION_MANAGER_H__ 
 
#include <GsTLAppli/grid/common.h>
#include <GsTLAppli/utils/gstl_types.h> 
#include <GsTLAppli/utils/gstl_messages.h> 
 
#include <GsTLAppli/grid/grid_model/grid_region.h>

#include <string> 
#include <vector> 
#include <map> 
#include <iostream> 
 

 
//class GsTLGridRegion; 

 
 
//========================================== 
 
/** A Grid_region_manager keeps track of multiple properties, possibly 
 * of different type. 
 * Each region is identified by an integer id and a name. Knowing the id  
 * allows faster access to the region. The id's are automatically assigned, 
 * starting from 0 for the first region. 
 */ 
class GRID_DECL Grid_region_manager { 
 public: 
  
//   typedef std::vector<bool> GsTLGridRegion;

  Grid_region_manager( GsTLInt size = 0 ); 
  void set_region_size( GsTLInt size ) { size_ = size; } 
  ~Grid_region_manager(); 
 
  /** Adds a new region 
   * @return a pointer to the new region. The pointer is 0 if add_region  
   * failed (most probably  because a region with the same name already  
   * existed ).  
   */ 
  GsTLGridRegion* add_region( const std::string& name ); 


  /** Removes a region, but does not change the properties' id: 
   * if there are 3 properties, "prop0", "prop1", and "prop2", with id 
   * respectively 0,1,2, when "prop1" is deleted, "prop0" still has id 0, 
   * and "prop2" id 2. No new region will ever have id 1. 
   */ 
  bool remove_region( const std::string& name ); 
 
  /** Retrieve a region 
   * @return 0 if the region can not be retrived 
   */ 
  inline GsTLGridRegion* get_region( const std::string& name ); 
  inline const GsTLGridRegion* get_region( const std::string& name ) const; 
  /** Retrieve a region. Overloaded to enable faster access. 
   * @return 0 if the region can not be retrived 
   */ 
  inline GsTLGridRegion* get_region( int prop_id ); 
  inline const GsTLGridRegion* get_region( int prop_id ) const; 
 
  /** Selects a region. That region becomes the default region 
   * @return 0 if the region can not be retrived 
   */ 
  inline GsTLGridRegion* select_region( const std::string& name ); 
  inline GsTLGridRegion* select_region( int prop_id ); 
  inline GsTLGridRegion* selected_region(); 
  inline const GsTLGridRegion* selected_region() const; 

  /** Unselects a region. 
   */ 
  inline void unselect_region();

  class Region_name_iterator; 
  Region_name_iterator names_begin() const ; 
  Region_name_iterator names_end() const ; 
   
   
 //TL modified
  bool reNameRegion(std::string&, std::string&);

protected:
  bool could_conflict( const std::string& name ); 

 protected: 
  typedef std::map< std::string, int > Region_map; 
 
  GsTLInt size_; 
  std::map< std::string, int > regions_map_; 
  std::vector< GsTLGridRegion* > regions_; 
  int selected_region_; 
  std::vector< int > selected_regions_;
 
 private: 
  Grid_region_manager( const Grid_region_manager& rhs ); 
  Grid_region_manager& operator = ( const Grid_region_manager& rhs ); 

}; 
 
 
 
class GRID_DECL Grid_region_manager::Region_name_iterator { 
private: 
  typedef std::map< std::string, int >::const_iterator const_iterator; 
 
 public: 
  Region_name_iterator( const_iterator it ) : curr_(it) {} 
  Region_name_iterator& operator++(int) { ++curr_; return *this; } 
  Region_name_iterator& operator++()    { curr_++; return *this; } 
  Region_name_iterator& operator--(int) { --curr_; return *this; } 
  Region_name_iterator& operator--()    { curr_--; return *this; } 
  bool operator!=(const Region_name_iterator& rhs) { return rhs.curr_ != curr_; } 
  bool operator==(const Region_name_iterator& rhs) { return rhs.curr_ == curr_; } 
  const std::string& operator*() { return curr_->first; } 
  const std::string* operator->() { return &curr_->first; } 
 
 private: 
  const_iterator curr_; 
}; 
 
//================================================= 
//   Definition of inline functions 
 
 
inline GsTLGridRegion*  
Grid_region_manager::get_region( const std::string& name ) { 
  Region_map::iterator it = regions_map_.find(name); 
  if( it != regions_map_.end() )  
    return regions_[ it->second ]; 
  else 
    return 0; 
} 
 
inline const GsTLGridRegion*  
Grid_region_manager::get_region( const std::string& name ) const { 
  if( name.empty() ) return 0; 
 
  Region_map::const_iterator it = regions_map_.find(name); 
  if( it != regions_map_.end() )  
    return regions_[ it->second ]; 
  else 
    return 0; 
} 
 
inline GsTLGridRegion*  
Grid_region_manager::get_region( int prop_id ) { 
  appli_assert( prop_id < (int) regions_.size() ); 
  return regions_[prop_id]; 
} 
 
inline const GsTLGridRegion*  
Grid_region_manager::get_region( int prop_id ) const { 
  appli_assert( prop_id < (int) regions_.size() ); 
  return regions_[prop_id]; 
} 
 
inline GsTLGridRegion*  
Grid_region_manager::select_region( const std::string& name ) { 
  if( name.empty() ) {
    unselect_region();
    return 0; 
  }
  Region_map::iterator it = regions_map_.find(name); 
  if( it != regions_map_.end() ) { 
    selected_region_ = it->second; 
    return regions_[ it->second ]; 
  } 
  else 
    return 0; 
} 
 
inline GsTLGridRegion*  
Grid_region_manager::select_region( int prop_id ) { 
  appli_assert( prop_id < (int) regions_.size() ); 
  selected_region_ = prop_id; 
  return regions_[prop_id]; 
} 
 
inline void Grid_region_manager::unselect_region() {
  selected_region_ = -1;
}

inline GsTLGridRegion*  
Grid_region_manager::selected_region() { 
  if( selected_region_ >=0 ) 
    return regions_[ selected_region_ ] ; 
  else 
    return 0; 
} 
 
inline const GsTLGridRegion*  
Grid_region_manager::selected_region() const { 
  if( selected_region_ >=0 ) 
    return regions_[ selected_region_ ] ; 
  else 
    return 0; 
} 
 
inline  
Grid_region_manager::Region_name_iterator 
Grid_region_manager::names_begin() const { 
  return Region_name_iterator( regions_map_.begin() ); 
} 
 
inline   
Grid_region_manager::Region_name_iterator 
Grid_region_manager::names_end() const { 
  return Region_name_iterator( regions_map_.end() ); 
} 
   
 
#endif 
