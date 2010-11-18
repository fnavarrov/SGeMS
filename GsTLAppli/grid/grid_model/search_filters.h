/**********************************************************************
** Author: Alexandre Boucher
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
** All rights reserved.
**
** This file is part of the "grid" module of the Stanford Geostatistical Earth
** Modeling Software (SGEMS)
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

#ifndef __GSTLAPPLI_OCTANT_SEARCH_TRACKER_H__ 
#define __GSTLAPPLI_OCTANT_SEARCH_TRACKER_H__ 
 
#include <GsTLAppli/grid/common.h>
#include <GsTLAppli/grid/grid_model/geovalue.h> 
#include <map>
#include <GsTLAppli/math/gstlpoint.h>
#include <GsTL/geometry/geometry_algorithms.h>

class less_than_triplet {
public :
template<typename T>
  bool operator()(const T t1, const T t2) const {
    if( t1[2] < t2[2] ) return true;
    else if(t1[2] > t2[2]) return false;

    else if( t1[1] < t2[1] ) return true;
    else if(t1[1] > t2[1]) return false;

    else if( t1[0] < t2[0] ) return true;
    else return false;
  }
};


class less_than_ocant_id {
public :
  bool operator()(const GsTLTripletTmpl< bool > t1, 
                  const GsTLTripletTmpl< bool > t2) const {
    if( t1[2] != t2[2] ) return t1[2];
    else if( t1[1] != t2[1] ) return t1[1];
    return t1[0];
  }
};

class Search_filter {
public:
    Search_filter(){}
    virtual ~Search_filter(){}
    virtual bool is_admissible( const Geovalue& neigh, const Geovalue& center){return true;}
    virtual bool is_neighborhood_valid() {return true;}
    virtual void clear(){}
    virtual std::string class_name(){return "Search_filter";} 
    virtual Search_filter* clone() {return new Search_filter(*this);}

};



class Octant_search_filter : public Search_filter{
  public :
    
    Octant_search_filter():min_octant_(0), 
      min_per_octant_(0),max_per_octant_(10e10){};

    Octant_search_filter(unsigned int min_octant,
                           unsigned int min_per_octant,
                           unsigned int max_per_octant,
                           float alpha = 0., float beta=0., float theta=0.)
      :min_octant_(min_octant),min_per_octant_(min_per_octant),
      max_per_octant_(max_per_octant) 
    {
      if(alpha!=0. || beta!=0. || theta!=0.)
       coord_transform_ = new CoordTransform(1.,1.,1.,alpha,beta,theta);
      else coord_transform_  = NULL;
      octant_registrar_.clear();
      octant_registrar_.insert(octant_registrar_.begin(),8,0);
    }

    Octant_search_filter(const Octant_search_filter& o) {
      if(o.coord_transform_ == NULL)
        coord_transform_ = NULL;
      else
        coord_transform_ = new CoordTransform(*o.coord_transform_);
      min_octant_ = o.min_octant_;
      min_per_octant_ = o.min_per_octant_;
      max_per_octant_ = o.max_per_octant_;
    }

    ~Octant_search_filter(){delete coord_transform_;}

    virtual Search_filter* clone() {return new Octant_search_filter(*this);}
/*
    void set_orientation(float alpha = 0., float beta=0., float theta=0.) {
      coord_transform_ = new CoordTransform(1.,1.,1.,alpha,beta,theta);
    }
*/
    virtual std::string class_name(){return "Octant_search_filter";} 

    virtual bool is_admissible( const Geovalue& gval, const Geovalue& center) {
      Vector3D delta_d = gval.location() - center.location();
      if(coord_transform_) delta_d  = (*coord_transform_)(delta_d);
      
      octant_id octant(delta_d[0] >= 0.,delta_d[1] >= 0.,delta_d[2] >= 0.);

      //Find the index in the array
      int id = int(octant[0]) + int(octant[1])*2 +int(octant[2])*4;
      if(octant_registrar_[id] >= max_per_octant_) return false;
      octant_registrar_[id]++;

      /*
      octant_iterator it  = octant_registrar_.find( octant );
      if(it == octant_registrar_.end()) 
        octant_registrar_[octant] = 1;
      else if(it->second >= max_per_octant_) return false;
      else it->second++;
      */
      return true;
    }

    virtual bool is_neighborhood_valid() {
      int non_zero = 0;
      int greater_min_per_oct=0;
      for(int i=0; i < 8; i++) {
        non_zero += int(octant_registrar_[i]>0);
        greater_min_per_oct += int(octant_registrar_[i]>= min_per_octant_);
      }
      if( non_zero < min_octant_ ) return false;
      if( greater_min_per_oct < min_per_octant_ ) return false;


      /*
      if( octant_registrar_.size() < min_octant_ ) return false;
      octant_iterator it = octant_registrar_.begin();
      int i=0;
      for(; it != octant_registrar_.end(); ++it )
        if(it->second >= min_per_octant_) i++;
     
      if( i < min_octant_ ) return false;
 */
      return true;
    }

    virtual void clear() { 
      octant_registrar_.clear(); 
      octant_registrar_.insert(octant_registrar_.begin(),8,0);
    }
    

protected :
  typedef GsTLTripletTmpl< bool > octant_id;
  //typedef std::map< octant_id, int, less_than_triplet > octant_map;
  //typedef std::map< octant_id, int, less_than_ocant_id > octant_map;
  
  //typedef octant_map::iterator octant_iterator;

  unsigned int min_octant_;
  unsigned int min_per_octant_;
  unsigned int max_per_octant_;

  //octant_map octant_registrar_;
  std::vector<int> octant_registrar_;
  typedef Geostat_grid::location_type::difference_type Vector3D;
  typedef Anisotropic_transform_3d<Vector3D>  CoordTransform;
  CoordTransform* coord_transform_;
};


class harddata_filter : public Search_filter {
public:
    virtual ~harddata_filter(){}
    virtual bool is_admissible(const Geovalue& gval){return gval.is_harddata();}
    virtual bool is_neighborhood_valid() {return true;}
    virtual void clear(){}
    virtual std::string class_name(){return "harddata_filter";} 
    virtual Search_filter* clone() {return new harddata_filter(*this);}
};

class min_number_neighborhs : public Search_filter {
public:
  min_number_neighborhs(int min_neigh = 0):min_neigh_(min_neigh),count_(0){}
  virtual Search_filter* clone() {return new min_number_neighborhs(*this);}
  virtual ~min_number_neighborhs(){}
    virtual bool is_admissible(const Geovalue& gval, const Geovalue& center){ 
      count_++;
      return true;
    }
    virtual bool is_neighborhood_valid() {return count_ >= min_neigh_;}
    virtual void clear(){count_=0;}
    virtual std::string class_name(){return "min_number_neighborhs";} 

protected :
  int min_neigh_;
  int count_;
};

class region_neighborhood_filter : public Search_filter {
public:
  region_neighborhood_filter(){}
  virtual ~region_neighborhood_filter(){}
  virtual Search_filter* clone() {return new region_neighborhood_filter(*this);}
    virtual bool is_admissible(const Geovalue& gval, const Geovalue& center){ 
      return gval.is_inside_selected_region();
    }
    virtual bool is_neighborhood_valid() {return true;}
    virtual void clear(){}
    virtual std::string class_name(){return "region_neighborhood_filter";}

};

class combined_neighborhood_filter : public Search_filter {
public:
  combined_neighborhood_filter(){}
  
  combined_neighborhood_filter(const combined_neighborhood_filter& o){
    for(int i=0;i<o.filters_.size();++i)
      filters_.push_back( o.filters_[i]->clone() );
  }


  template<class Filter_iterator>
  combined_neighborhood_filter(Filter_iterator begin, Filter_iterator end){
    filters_.insert(begin,end, filters_.begin());  
  }
  virtual Search_filter* clone() {return new combined_neighborhood_filter(*this);}
  virtual ~combined_neighborhood_filter(){}

  virtual bool is_admissible(const Geovalue& gval, const Geovalue& center){ 
    for(Filters::iterator it = filters_.begin() ; 
      it != filters_.end(); ++it) {
        if(!(*it)->is_admissible(gval,center) ) return false;
    }
    return true;
   }

  void add_filter(Search_filter* filter) {
    filters_.push_back(filter);
  }

  virtual bool is_neighborhood_valid() {
    for(Filters::iterator it = filters_.begin() ; 
      it != filters_.end(); ++it) {
        if(!(*it)->is_neighborhood_valid() ) return false;
    }
    return true;
  }

  virtual void clear() {
    for(Filters::iterator it = filters_.begin() ; 
      it != filters_.end(); ++it)
      (*it)->clear();
   }
  virtual std::string class_name(){return "combined_neighborhood_filter";}

protected :
  typedef std::vector<Search_filter*> Filters;
  Filters filters_;
};

#endif
