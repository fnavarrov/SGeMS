
#include <GsTLAppli/grid/grid_model/grid_property_set.h>
#include <GsTLAppli/grid/grid_model/grid_property.h> 
#include <GsTLAppli/grid/grid_model/grid_categorical_property.h> 
#include <GsTLAppli/appli/manager_repository.h> 
//#include <QtXml/QDomElement>

GsTLGridPropertyGroup*
Create_new_property_group(const std::string& name, const std::string& type) {
	if(type == "" || type == "General") return new GsTLGridPropertyGroup(name);
	else if(type == "Simulation") return new SimulationPropertyGroup(name);
  else if(type == "Categorical") return new CategoricalPropertyGroup(name);
	else if(type == "CategoricalIndicator") return new IndicatorCategoricalPropertyGroup(name);
	else if(type == "CategoricalProbability") return new CategoricalProbabilityPropertyGroup(name);
  else if(type == "ContinuousIndicator") return new IndicatorContinuousPropertyGroup(name);
	else return 0;

}


Named_interface* GsTLGridPropertyGroup::create_new_interface( std::string& name) {
  return new GsTLGridPropertyGroup(name);
}

GsTLGridPropertyGroup::GsTLGridPropertyGroup(std::string name){
  name_ = name;
  type_ = "General";
//  root_ = meta_data_.createElement(type_.c_str());
//  meta_data_.appendChild(root_);
}


bool GsTLGridPropertyGroup::is_member_property(std::string prop_name) const {
  return( properties_.find( prop_name) != properties_.end() );
}

GsTLGridProperty* GsTLGridPropertyGroup::get_property(std::string prop_name) {
  property_map::iterator it = properties_.find( prop_name);
  if( it == properties_.end() ) return 0;
  return it->second;
}

bool GsTLGridPropertyGroup::add_property(GsTLGridProperty* prop) {
  if(prop == 0) return false;
  properties_[prop->name()] = prop;
  prop->add_group_membership( this );
  return true;
}

bool GsTLGridPropertyGroup::remove_property(GsTLGridProperty* prop){
  unsigned int ok = properties_.erase( prop->name() );
  if(ok) prop->remove_group_membership( this );
  return ok != 0;
}

std::vector<std::string> GsTLGridPropertyGroup::property_names() const{
  std::vector<std::string> names;
  names.reserve(properties_.size());
  property_map::const_iterator  it = properties_.begin();
  for(; it != properties_.end(); ++it) {
    names.push_back(it->first);
  }
  return names;
}

std::vector<GsTLGridProperty::property_type> 
GsTLGridPropertyGroup::get_vector_data( int node_id ) const{
  property_map::const_iterator it = properties_.begin();
  std::vector<GsTLGridProperty::property_type> values;
  values.reserve(properties_.size() );
  for( ; it!= properties_.end(); ++it) {
    if( it->second->is_informed(node_id) ) values.push_back( it->second->get_value(node_id) );
  }
  return values;
}


void GsTLGridPropertyGroup::set_group_info(const std::string& info_str) {
  info_["Info"] = info_str;
//  QDomElement ele = meta_data_.createElement("Info");
//  root_.appendChild(ele);
//  ele.setAttribute("Info",info_str.c_str());
}


std::string GsTLGridPropertyGroup::get_group_info() const{
  std::map<std::string, std::string>::const_iterator it = info_.find("Info");
  if(it == info_.end()) return "";
  return it->second;
//  QDomElement ele = root_.firstChildElement("Info");
//  if(ele.isNull()) return "";
//  return ele.attribute("text").toStdString();
}

/***
*  ------------------------
*/


GsTLGridPropertyGroup* Grid_property_group_manager::add_group(const std::string& name, const std::string& type) {
  group_map::iterator it_group = groups_.find(name);
  if(it_group != groups_.end()) return 0;
  // The group does not already exist
  GsTLGridPropertyGroup* group = Create_new_property_group(name, type);
 // GsTLGridPropertyGroup* group = new GsTLGridPropertyGroup(name);  // Need to get it from the manager
  if(group == 0) return 0; //failed to initialize maybe unknown type
  groups_[name] = group;
 
// Add the group type to the list (or to the count is type already present)
  group_type_map::iterator it_type = group_type_.find(type);
  if(it_type == group_type_.end()) 
    group_type_[type] = 1;
  else
    it_type->second++;

  return group;
}

void Grid_property_group_manager::remove_group(const std::string& name) {
  group_map::iterator it_group = groups_.find(name);
  if(it_group == groups_.end()) return;
  GsTLGridPropertyGroup* group = it_group->second;

// remove the group type to the list (or to the decrease the count is type already present)
  std::string type = group->type();
  int count = group_type_[type];
  if(count == 1) 
    group_type_.erase(type);
  else
    group_type_[type]--;

// remove property membership from group
  GsTLGridPropertyGroup::property_map::iterator it = group->begin_property();
  std::vector<GsTLGridProperty*> props;
  for( ; it != group->end_property(); ++it) {
  	props.push_back(it->second);
  }
  std::vector<GsTLGridProperty*>::iterator it_props = props.begin();
  for( ; it_props != props.end(); ++it_props) {
  	group->remove_property(*it_props);
  }

// Remove the group from the manager
  delete (group);
  groups_.erase(it_group);


}

GsTLGridPropertyGroup* Grid_property_group_manager::get_group(const std::string& name) {
  group_map::iterator it = groups_.find(name);
  if(it != groups_.end()) 
    return it->second;
  else
    return 0;
}


const GsTLGridPropertyGroup* 
Grid_property_group_manager::get_group(const std::string& name) const{
  group_map::const_iterator it = groups_.find(name);
  if(it != groups_.end()) 
    return it->second;
  else
    return 0;
}

bool Grid_property_group_manager::
add_property_to_group(GsTLGridProperty* prop, const std::string& name) {
  group_map::iterator it = groups_.find(name);
  if(it != groups_.end()) return false;
  it->second->add_property(prop);
  return true;
}

bool Grid_property_group_manager::
remove_property_from_group(GsTLGridProperty* prop, const std::string& name) {
  group_map::iterator it = groups_.find(name);
  if(it != groups_.end()) return false;
  it->second->remove_property(prop);
  return true;
}

std::list<std::string> Grid_property_group_manager::group_types() const{
  group_type_map::const_iterator it = group_type_.begin();
  std::list<std::string> group_type;
  for(; it!= group_type_.begin(); ++it) 
    group_type.push_back(it->first);
  return group_type;
}

std::list<std::string> 
Grid_property_group_manager::group_names(const std::string& type) const{
  group_map::const_iterator it = groups_.begin();
  std::list<std::string> group_name;
  for(; it!= groups_.end(); ++it) {
    if( type == "") group_name.push_back(it->first);
    else if( it->second->type() == type) group_name.push_back(it->first);
  }
  return group_name;
}


unsigned int Grid_property_group_manager::size() const{
  return groups_.size();
}




/* 
*         -----------------------
*/

Named_interface* SimulationPropertyGroup::create_new_interface( std::string& name) {
  return new SimulationPropertyGroup(name);
}

SimulationPropertyGroup::SimulationPropertyGroup() {
  type_ = "Simulation";
//  root_ = meta_data_.createElement(type_.c_str());
//  meta_data_.appendChild(root_);

}

SimulationPropertyGroup::SimulationPropertyGroup(std::string name) {
  name_ = name;
  type_ = "Simulation";
//  root_ = meta_data_.createElement(type_.c_str());
//  meta_data_.appendChild(root_);
}


void SimulationPropertyGroup::set_algo_command(const std::string& algo_str){
  info_["Algo"] = algo_str;
//  QDomDocument doc_algo;
//  doc_algo.setContent( QString(algo_str.c_str() ) );
//  root_.appendChild( doc_algo.firstChild() );

}

std::string SimulationPropertyGroup::get_algo_command(){
  std::map<std::string, std::string>::const_iterator it = info_.find("Algo");
  if(it == info_.end()) return "";
  return it->second;
 //QDomDocument doc_algo;
 //doc_algo.appendChild(root_.firstChildElement("parameters"));
 //return doc_algo.toString().toStdString();

}

/* Categorical Property group 
*
*/

Named_interface* CategoricalPropertyGroup::create_new_interface( std::string& name) {
  return new CategoricalPropertyGroup(name);
}

CategoricalPropertyGroup::CategoricalPropertyGroup()
{
  type_ = "Categorical";
  cat_def_ = 0;
//  root_ = meta_data_.createElement(type_.c_str());
//  meta_data_.appendChild(root_);

}

CategoricalPropertyGroup::CategoricalPropertyGroup(std::string name)
{
  name_ = name;
  cat_def_ = 0;
  type_ = "Categorical";
//  root_ = meta_data_.createElement("type_.c_str()");
//  meta_data_.appendChild(root_);
}


void 
CategoricalPropertyGroup::set_categorical_definition(std::string cat_def_name){
  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager+"/"+cat_def_name  );

  if(ni.raw_ptr() == 0) 
    cat_def_=0;
	else 
    cat_def_ = dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr()); 
}

void
CategoricalPropertyGroup::set_categorical_definition(const CategoricalPropertyDefinition* cat_def){
  cat_def_  = cat_def;
}


const CategoricalPropertyDefinition* 
CategoricalPropertyGroup::get_categorical_definition() const{
  return cat_def_;
}

std::string CategoricalPropertyGroup::get_categorical_definition_name() const {
  return cat_def_->name();
}



/* Categorical Probability Property group 
*
*/

Named_interface* CategoricalProbabilityPropertyGroup::create_new_interface( std::string& name) {
  return new CategoricalProbabilityPropertyGroup(name);
}

CategoricalProbabilityPropertyGroup::CategoricalProbabilityPropertyGroup()
:CategoricalPropertyGroup(){
  type_ = "CategoricalProbability";
  cat_def_ = 0;
//  root_ = meta_data_.createElement(type_.c_str());
//  meta_data_.appendChild(root_);

}

CategoricalProbabilityPropertyGroup::
CategoricalProbabilityPropertyGroup(std::string name)
:CategoricalPropertyGroup(name)
{
  name_ = name;
  cat_def_ = 0;
//  type_ = "CategoricalIndicator";
//  root_ = meta_data_.createElement("type_.c_str()");
//  meta_data_.appendChild(root_);
}


Categ_non_param_cdf<int>  
CategoricalProbabilityPropertyGroup::get_distribution(int node_id) const{
  std::vector<GsTLGridProperty::property_type> prob = get_vector_data( node_id );
  return Categ_non_param_cdf<int>(prob.size(), prob.begin());
}



/* Indicator Probability  group
*
*/


Named_interface* IndicatorCategoricalPropertyGroup::create_new_interface( std::string& name) {
  return new IndicatorCategoricalPropertyGroup(name);
}

IndicatorCategoricalPropertyGroup::IndicatorCategoricalPropertyGroup()
{
  type_ = "CategoricalIndicator";
//  root_ = meta_data_.createElement(type_.c_str());
//  meta_data_.appendChild(root_);

}

IndicatorCategoricalPropertyGroup::IndicatorCategoricalPropertyGroup(std::string name)
{
  name_ = name;
//  type_ = "CategoricalIndicator";
//  root_ = meta_data_.createElement("type_.c_str()");
//  meta_data_.appendChild(root_);
}




int IndicatorCategoricalPropertyGroup::get_category(int node_id) const{
  float cat;
  property_map::const_iterator it = properties_.begin();
  for( ; it!= properties_.end(); ++it) {
    if( it->second->get_value(node_id) == 1 ) {
      return std::distance(properties_.begin(),it );
    }
  }
  return -1;
}

std::string IndicatorCategoricalPropertyGroup::get_category_name(int node_id) const{
  int cat = this->get_category(node_id);
  return cat_def_->get_category_name(cat);
}



/* Group for indicator of continuous property
*
*/


Named_interface* IndicatorContinuousPropertyGroup::create_new_interface( std::string& name) {
  return new IndicatorContinuousPropertyGroup(name);
}

IndicatorContinuousPropertyGroup::IndicatorContinuousPropertyGroup()
{
  type_ = "ContinuousIndicator";
//  root_ = meta_data_.createElement(type_.c_str());
//  meta_data_.appendChild(root_);

}

IndicatorContinuousPropertyGroup::IndicatorContinuousPropertyGroup(std::string name)
{
  name_ = name;
  type_ = "ContinuousIndicator";
//  root_ = meta_data_.createElement("type_.c_str()");
//  meta_data_.appendChild(root_);
}

void IndicatorContinuousPropertyGroup::set_thresholds(std::vector<float> thresholds){
  thresholds_ = thresholds;
}

std::vector<float> IndicatorContinuousPropertyGroup::get_thresholds() const {
  return thresholds_;
}

Non_param_cdf<>
IndicatorContinuousPropertyGroup::get_distribution(int node_id) const{
  std::vector<GsTLGridProperty::property_type> prob = get_vector_data( node_id );
  return Non_param_cdf<>(thresholds_.begin(),thresholds_.end(), prob.begin() );
}

