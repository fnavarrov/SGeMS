/*
 * GsTLGridCategoricalProperty.h
 *
 *  Created on: Mar 29, 2010
 *      Author: aboucher
 */

#ifndef GSTLGRIDCATEGORICALPROPERTY_H_
#define GSTLGRIDCATEGORICALPROPERTY_H_

#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_property_set.h>
#include <GsTLAppli/utils/named_interface.h>
#include <set>

Named_interface* create_new_categorical_definition( std::string& );

class GRID_DECL CategoricalPropertyDefinition :public Named_interface {
public:
  typedef std::set<const GsTLGridProperty*, compareGsTLGridProperty > property_set;
	CategoricalPropertyDefinition(){}
	virtual ~CategoricalPropertyDefinition(){}

	virtual std::string get_category_name(unsigned int id) const = 0;

	virtual bool is_category_exist(std::string name) const = 0;

	virtual int category_id(std::string name) const = 0;
  
  virtual std::string name() const = 0;

  void register_property(const GsTLGridProperty* prop);

  void unregister_property(const GsTLGridProperty* prop);

  property_set::const_iterator begin_property() const;
  property_set::const_iterator end_property() const;

protected :
  property_set props_;


};


class GRID_DECL CategoricalPropertyDefinitionName :public CategoricalPropertyDefinition {

public:
	CategoricalPropertyDefinitionName();
	CategoricalPropertyDefinitionName( const std::string& filename );
//  CategoricalPropertyDefinitionName(std::vector<std::string> names);

	virtual ~CategoricalPropertyDefinitionName();

	virtual std::string get_category_name(unsigned int id) const;

	virtual bool is_category_exist(std::string name) const;

	virtual int category_id(std::string name) const;

  virtual std::string name() const;

	virtual int number_of_category() const;

	bool rename(int id, std::string name);

  void load_from_file(const std::string& filename);

	void set_category_names(std::vector<std::string> names);

	int add_category(std::string name);

  void set_definiton_name(std::string name);

  std::vector<std::string>::const_iterator begin_category_name() const;
  std::vector<std::string>::const_iterator end_category_name() const;

protected :
  std::vector<std::string> cat_names_;
  std::string name_;

};

class GRID_DECL CategoricalPropertyDefinitionDefault :public CategoricalPropertyDefinition {

public:
  CategoricalPropertyDefinitionDefault(){}
	virtual ~CategoricalPropertyDefinitionDefault(){}

	virtual std::string get_category_name(unsigned int id) const;

	virtual bool is_category_exist(std::string name) const;

	virtual int category_id(std::string name) const;

  virtual std::string name() const;

};


class GRID_DECL GsTLGridCategoricalProperty: public GsTLGridProperty {
public:
	GsTLGridCategoricalProperty( GsTLInt size, const std::string& name,
				const std::string cat_definition_name = "Default",
				property_type default_value = no_data_value );
	GsTLGridCategoricalProperty(const std::string& in_filename, GsTLInt size, const std::string& name,
				const std::string cat_definition_name = "Default",
				property_type default_value = no_data_value );
/*
	GsTLGridCategoricalProperty( GsTLGridProperty* cont_prop,
				const std::string cat_definition_name = "Default",
				property_type default_value = no_data_value );
*/
	virtual ~GsTLGridCategoricalProperty();

	  /** Returns the category name value of the ith element.
	  */
	inline std::string get_category_name( GsTLInt id ) const;

	/** Returns the an indicator (0-1) for a given category. 
  * Return -1, if the category does not exist
	*/
	inline int get_indicator_value( GsTLInt id, int category ) const;

	/** Returns the an indicator (0-1) for a given category.
  * Return -1, if the category does not exist
	*/
  inline int get_indicator_value( GsTLInt id, std::string category_name ) const;

	/** Changes the value of the ith element to \a val.
	*/
	inline void set_value( property_type val, GsTLInt id );

	/** Changes the value of the ith element to \a val.
  */
  inline void set_value( std::string val, GsTLInt id );

  /** Get the coding definition for the categories
  */
  inline const CategoricalPropertyDefinition* get_category_definition() const;


  /** Get the number of category
  */
  inline int get_number_of_category() const;

  /** Set the coding definition for the categories
  */
  bool set_category_definition( std::string cat_definition_name);
  bool set_category_definition( CategoricalPropertyDefinition* cat_definition);


protected :
	  CategoricalPropertyDefinition* cat_definitions_;
    unsigned int number_of_categories_;
};

inline std::string
GsTLGridCategoricalProperty::get_category_name( GsTLInt id ) const {
  appli_assert( accessor_->get_property_value( id ) != no_data_value );
  property_type val = accessor_->get_property_value( id );
  return cat_definitions_->get_category_name(val);
}

inline int 
GsTLGridCategoricalProperty::get_indicator_value( GsTLInt id, int category ) const{
  return this->get_value(id)==category?1:0;
}

	/** Returns the an indicator (0-1) for a given category.
	*/
inline int 
GsTLGridCategoricalProperty::get_indicator_value( GsTLInt id, std::string category_name ) const{
  int code = cat_definitions_->category_id(category_name);
  if( code <0 ) return -1;
  return this->get_indicator_value(id,code);
}


inline
void GsTLGridCategoricalProperty::set_value( property_type val, GsTLInt id ) {
  unsigned int cat = static_cast<unsigned int>(val);
  if( cat > number_of_categories_) number_of_categories_ = cat;
  accessor_->set_property_value( cat, id );
}


inline
void GsTLGridCategoricalProperty::set_value( std::string val, GsTLInt id ) {
  int code = cat_definitions_->category_id(val);
  if( code > number_of_categories_) number_of_categories_ = code;
  if( code >= 0 )
	  accessor_->set_property_value( code, id );
}


inline
const CategoricalPropertyDefinition*
	GsTLGridCategoricalProperty::get_category_definition( ) const {
	return cat_definitions_;
}

inline 
int GsTLGridCategoricalProperty::get_number_of_category() const{
	const CategoricalPropertyDefinitionName* cat_def = 
		dynamic_cast<const CategoricalPropertyDefinitionName*>(cat_definitions_);
	if(cat_def) {
		return cat_def->number_of_category();
	}
	else {
		int max_cat = -1e8;
		const_iterator it = this->begin();
		for( ; it != this->end(); ++it) {
			if(*it > max_cat) max_cat = *it;
		}
		return max_cat+1;
	}

}


#endif /* GSTLGRIDCATEGORICALPROPERTY_H_ */
