/**********************************************************************
** Author: Alexandre Bocuher
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
** All rights reserved.
**
** This file is part of the "grid" module of the Stanford Geostatistical Earth
** Modeling Software (SGeMS)
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

#ifndef __GSTLAPPLI_GRID_PROPERTY_SET_H__ 
#define __GSTLAPPLI_GRID_PROPERTY_SET_H__ 
 
#include <GsTLAppli/utils/named_interface.h>
#include <GsTLAppli/utils/gstl_types.h> 
#include <GsTLAppli/utils/gstl_messages.h> 
#include <GsTLAppli/grid/common.h>
#include <GsTLAppli/grid/grid_model/grid_property.h> 

#include <GsTL/cdf/categ_non_param_cdf.h>
#include <GsTL/cdf/non_param_cdf.h>

#include <string> 
#include <map>
#include <set>
//#include <QtXml/QDomDocument>



 
class GRID_DECL GsTLGridPropertyGroup :public Named_interface {
public:

  static Named_interface* create_new_interface( std::string& name);

  typedef std::map<std::string, GsTLGridProperty*> property_map;
  GsTLGridPropertyGroup(){}
  GsTLGridPropertyGroup(std::string name);
  virtual ~GsTLGridPropertyGroup(){}

  virtual std::string name() const {return name_;}
  virtual std::string type() const {return type_;}
  

  bool is_member_property(std::string prop_name) const;
  GsTLGridProperty* get_property(std::string prop_name);
  int size() const {return properties_.size();}

  bool add_property(GsTLGridProperty*);
  bool remove_property(GsTLGridProperty*);

  std::vector<GsTLGridProperty::property_type> get_vector_data( int node_id ) const;

  property_map::iterator begin_property(){ return properties_.begin(); }
  property_map::iterator end_property() {  return properties_.end(); }
  std::vector<std::string> property_names() const;

  std::string get_group_info();
  void set_group_info(const std::string& info_str);



protected :
  property_map properties_;
  std::string name_;
  std::string type_;
  
 // QDomElement root_;
//  QDomDocument meta_data_;

  std::map<std::string, std::string> info_;
};



class GRID_DECL Grid_property_group_manager {
public :
  Grid_property_group_manager(){}
  virtual ~Grid_property_group_manager(){}

  GsTLGridPropertyGroup* add_group(const std::string& name, const std::string& type);

  void remove_group(const std::string& name);

  GsTLGridPropertyGroup* get_group(const std::string& name);
  const GsTLGridPropertyGroup* get_group(const std::string& name) const;

  bool add_property_to_group(GsTLGridProperty* prop, const std::string& group_name);

  bool remove_property_from_group(GsTLGridProperty* prop, const std::string& group_name);

  std::list<std::string> group_types() const;

  std::list<std::string> group_names(const std::string& type="") const;

  unsigned int size() const;

protected :
  typedef std::map<std::string, GsTLGridPropertyGroup*> group_map;
  typedef std::map<std::string, int> group_type_map;
  group_map groups_;
  group_type_map group_type_;



};




class GRID_DECL SimulationPropertyGroup : public GsTLGridPropertyGroup {
public:

  static Named_interface* create_new_interface( std::string& name);

  SimulationPropertyGroup();
  SimulationPropertyGroup(std::string name);
  virtual ~SimulationPropertyGroup(){}

  bool is_categorical();

   
  void set_algo_command(const std::string& algo_str);
  std::string get_algo_command();

protected :

  std::string simulation_base_name_;
  std::string grid_name_;

};


class CategoricalPropertyDefinition;

//indicator for categorical attribute
// note: the indicator property are continuous values modeling
// a categorical attributes
class GRID_DECL IndicatorCategoricalPropertyGroup : public GsTLGridPropertyGroup {
public:

  static Named_interface* create_new_interface( std::string& name);

  IndicatorCategoricalPropertyGroup();
  IndicatorCategoricalPropertyGroup(std::string name);
  virtual ~IndicatorCategoricalPropertyGroup (){}

  std::string get_categorical_definition_name() const;
  const CategoricalPropertyDefinition* get_categorical_definition() const;

  Categ_non_param_cdf<int>  get_distribution(int node_id) const;


protected :

};


//indicator for categorical attribute
// note: the indicator property are continuous values modeling
// a categorical attributes
class GRID_DECL IndicatorContinuousPropertyGroup : public GsTLGridPropertyGroup {
public:

  static Named_interface* create_new_interface( std::string& name);

  IndicatorContinuousPropertyGroup();
  IndicatorContinuousPropertyGroup(std::string name);
  virtual ~IndicatorContinuousPropertyGroup (){}

  void set_thresholds(std::vector<float>);
  std::vector<float> get_thresholds() const;

  Non_param_cdf<>  get_distribution(int node_id) const;


protected :
  std::vector<float> thresholds_;

};


#endif