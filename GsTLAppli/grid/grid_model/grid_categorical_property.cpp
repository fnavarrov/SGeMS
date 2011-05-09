/*
 * GsTLGridCategoricalProperty.cpp
 *
 *  Created on: Mar 29, 2010
 *      Author: aboucher
 */

#include <GsTLAppli/grid/grid_model/grid_categorical_property.h>
#include <GsTLAppli/appli/manager_repository.h> 
#include <sstream>


Named_interface* create_new_categorical_definition( std::string& name){
if(name == "Default") return new CategoricalPropertyDefinitionDefault;
else 
  return new CategoricalPropertyDefinitionName(name);
}



void CategoricalPropertyDefinition::register_property(const GsTLGridProperty* prop) {
  props_.insert(prop);
}

void CategoricalPropertyDefinition::unregister_property(const GsTLGridProperty* prop) {
  props_.erase(prop);
}

CategoricalPropertyDefinition::property_set::const_iterator 
CategoricalPropertyDefinition::begin_property() const {
  return props_.begin();
}

CategoricalPropertyDefinition::property_set::const_iterator 
CategoricalPropertyDefinition::end_property() const {
  return props_.end();
}



CategoricalPropertyDefinitionName::CategoricalPropertyDefinitionName() {
	// TODO Auto-generated constructor stub

}

CategoricalPropertyDefinitionName::~CategoricalPropertyDefinitionName() {
	// TODO Auto-generated destructor stub
}

CategoricalPropertyDefinitionName::CategoricalPropertyDefinitionName(
		const std::string& name ){
  name_ = name;
}


void CategoricalPropertyDefinitionName::load_from_file(const std::string& filename){
  std::ifstream infile( filename.c_str() );
  if( !infile ) {
	appli_warning( "Cannot open file " << filename );
	return;
  }

  name_ = filename;

  while(!infile.eof()) {
	  std::string name;
	  std::getline(infile, name);
	  if( name.empty() ) break;
	  cat_names_.push_back(name);
  }
  infile.close();
}

std::string CategoricalPropertyDefinitionName::get_category_name(unsigned int id) const{
	if(id < cat_names_.size()  )
		return cat_names_[id];
	else
		return "";
}

std::string CategoricalPropertyDefinitionName::name() const {
  return name_;
}

void CategoricalPropertyDefinitionName::set_definiton_name(std::string name){
  name_ = name;
}


void CategoricalPropertyDefinitionName::set_category_names(std::vector<std::string> names) {
	cat_names_ = names;
}

int CategoricalPropertyDefinitionName::add_category(std::string name){
	bool ok = is_category_exist( name );
	if(ok) return -1;
	cat_names_.push_back(name);
	return cat_names_.size()-1;
}

int CategoricalPropertyDefinitionName::category_id(std::string name) const{
	std::vector<std::string>::const_iterator it = cat_names_.begin();
	for(unsigned int i=0 ; i < cat_names_.size(); ++i) {
		if(cat_names_[i] == name) return i;
	}
	return -1;
}

bool CategoricalPropertyDefinitionName::is_category_exist(std::string name) const {
	return category_id(name) >= 0;
}

int CategoricalPropertyDefinitionName::number_of_category() const{
	return cat_names_.size();
}

bool CategoricalPropertyDefinitionName::rename(int id, std::string new_name){
	bool ok = false;
	if(id < cat_names_.size()  ) {
		cat_names_[id] = new_name;
		ok = true;
	}
	return ok;

}

std::vector<std::string>::const_iterator 
CategoricalPropertyDefinitionName::begin_category_name() const{
  return cat_names_.begin();
}

std::vector<std::string>::const_iterator 
CategoricalPropertyDefinitionName::end_category_name()const{
  return cat_names_.end();
}


/*
 * Default Categorical definition: no user-defined name
 * The name are of type "category_0"
 */

std::string CategoricalPropertyDefinitionDefault::get_category_name(unsigned int id) const{
	std::stringstream name;
	name <<"category_"<<id;
	return name.str();
}

int CategoricalPropertyDefinitionDefault::category_id(std::string name) const{
	if( name.substr(0,9) != "category_" ) return -1;
	int id;
	std::istringstream name_istr(name);

	if (name_istr>>id)
		return id;
	else return -1;



}

bool CategoricalPropertyDefinitionDefault::is_category_exist(std::string name) const {
	return category_id(name) >= 0;
}


std::string CategoricalPropertyDefinitionDefault::name() const {
  return "Default";
}


/*
 *   GsTLGridCategoricalProperty
 */

GsTLGridCategoricalProperty::GsTLGridCategoricalProperty(
		GsTLInt size, const std::string& name,
    const std::string cat_definition_name,
		property_type default_value)
		: GsTLGridProperty(size,name,no_data_value),number_of_categories_(0)
{

  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager+"/"+cat_definition_name  );
  appli_assert( ni );

  cat_definitions_ = 
    dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr());
  if(cat_definitions_ == 0) {
    ni = Root::instance()->interface( categoricalDefinition_manager+"/Default" );
    cat_definitions_ = 
      dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr());
  }
  cat_definitions_->register_property(this);

}


GsTLGridCategoricalProperty::GsTLGridCategoricalProperty(
		const std::string& in_filename, GsTLInt size, const std::string& name,
    const std::string cat_definition_name,
		property_type default_value)
		: GsTLGridProperty(size,name,in_filename, no_data_value),number_of_categories_(0) 
{

  SmartPtr<Named_interface> ni =
    Root::instance()->interface( categoricalDefinition_manager+"/"+cat_definition_name  );
//  appli_assert( ni );

  cat_definitions_ =
    dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr());
  if(cat_definitions_ == 0) {
    ni = Root::instance()->interface( categoricalDefinition_manager+"/Default" );
    cat_definitions_ =
      dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr());
  }
  cat_definitions_->register_property(this);

}



/*
GsTLGridCategoricalProperty::GsTLGridCategoricalProperty( 
        GsTLGridProperty* cont_prop, const std::string& name,
				const std::string cat_definition_name = "Default",
        property_type default_value = no_data_value ) 
        :GsTLGridProperty(cont_prop->size(), cont_prop->name(), no_data_value)
{

  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager+"/"+cat_definition_name  );
  appli_assert( ni );

  cat_definitions_ = 
    dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr());
  if(cat_definitions_ == 0) {
    ni = Root::instance()->interface( categoricalDefinition_manager+"/Default" );
    cat_definitions_ = 
      dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr());
  }
  cat_definitions_->register_property(this);

}
*/



GsTLGridCategoricalProperty::~GsTLGridCategoricalProperty(){
    if(cat_definitions_)  cat_definitions_->unregister_property(this);
  }

bool GsTLGridCategoricalProperty::set_category_definition( std::string cat_definition_name){

  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager+"/"+cat_definition_name  );
//  Manager* cdef_manager = dynamic_cast<Manager*>( ni.raw_ptr() );
  appli_assert( ni );

	CategoricalPropertyDefinition* cat_def = 
    dynamic_cast<CategoricalPropertyDefinition*>(ni.raw_ptr());
  
  if(cat_definitions_ == cat_def) return true;
  if(cat_def == 0) return false;
  
  cat_definitions_->unregister_property(this);
  cat_definitions_ = cat_def;
  cat_definitions_->register_property(this);
  return true;
}

bool GsTLGridCategoricalProperty
::set_category_definition( CategoricalPropertyDefinition* cat_definition){
  if(cat_definition == 0) return false;
  if(cat_definitions_ == cat_definition) return true;

  cat_definitions_->unregister_property(this);
  cat_definitions_ = cat_definition;
  cat_definitions_->register_property(this);
  return true;
}
