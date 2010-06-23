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
**********************************************************************/

#ifndef __GSTLAPPLI_GRID_REGION_H__ 
#define __GSTLAPPLI_GRID_REGION_H__ 
 
#include <GsTLAppli/grid/common.h>
#include <GsTLAppli/utils/gstl_types.h> 
#include <GsTLAppli/utils/gstl_messages.h> 
 
#include <string> 
#include <fstream> 
#include <vector>



/** A GsTLGridRegion contains 3 types of information: 
 *    \li one flag to indicate if the node contains a data value 
 *    \li a data value 
 *    \li one flag to indicate if the data value is a "hard data" 
 */ 
class GRID_DECL GsTLGridRegion { 
 
 public: 
  typedef bool region_type; 
  typedef std::vector<region_type> region;

  typedef std::vector<region_type>::iterator iterator;
  typedef std::vector<region_type>::const_iterator const_iterator;
 
 public: 
  GsTLGridRegion( GsTLInt size, std::string name, 
    region_type default_value = false ):name_(name) {
      accessor_.assign(size,default_value);
  }
  ~GsTLGridRegion(){}; 
     
// Direct acces to the region
  inline std::vector<region_type>& data();
  inline const std::vector<region_type>& data() const; 

  /** Tells whether the ith element of the region array is informed,
  * ie contains a value.
  */
  inline bool is_inside_region( GsTLInt i ) const ;

  /** Changes the value of the ith element to \a val.
  */
  inline void set_region_value( region_type val, GsTLInt id );


  /** Returns the total number of values in the region array
  */
  inline GsTLInt size() const {return accessor_.size();} 

  /** Returns the total number of active values in the region array
  */
  inline GsTLInt active_size() const {
    region::const_iterator it = accessor_.begin();
    int n_active = 0;
    for( ; it != accessor_.begin(); ++it) {
      if(*it) n_active++;
    }
    return n_active;
  }
 
  /** Returns the name of the region
  */
  inline std::string name() const { return name_; } 
  inline void rename( const std::string& new_name ) { name_ = new_name; } 


  iterator begin( ) { return accessor_.begin(); } 
  iterator end() { return accessor_.end(); } 
  const_iterator begin() const { return accessor_.begin(); }
  const_iterator end() const { return accessor_.end(); }


 protected: 
  std::string name_; 
  region accessor_;

   
 private: 
  GsTLGridRegion( const GsTLGridRegion& rhs ); 
  GsTLGridRegion& operator = ( const GsTLGridRegion& rhs ); 

 
}; 
 
inline bool GsTLGridRegion::is_inside_region( GsTLInt i ) const {
  if( i<0 || i >= accessor_.size() ) return false;
  return accessor_[i];
} 

/** Changes the value of the ith element to \a val.
*/
inline void GsTLGridRegion::set_region_value( region_type val, GsTLInt id ){
  appli_assert(id>=0 && id<accessor_.size());
  accessor_[id] = val;
}

inline 
std::vector<GsTLGridRegion::region_type>& GsTLGridRegion::data() {
  return accessor_;
} 

inline 
const std::vector<GsTLGridRegion::region_type>& GsTLGridRegion::data() const{
  return accessor_;
} 

#endif