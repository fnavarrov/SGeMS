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

	/** Changes the value of the ith element to \a val.
	*/
	inline void set_value( property_type val, GsTLInt id );

	/** Changes the value of the ith element to \a val.
  */
  inline void set_value( std::string val, GsTLInt id );

  /** Get the coding definition for the categories
  */
  inline const CategoricalPropertyDefinition* get_category_definition() const;

  /** Set the coding definition for the categories
  */
  bool set_category_definition( std::string cat_definition_name);
  bool set_category_definition( CategoricalPropertyDefinition* cat_definition);


protected :
	  CategoricalPropertyDefinition* cat_definitions_;
};

inline std::string
GsTLGridCategoricalProperty::get_category_name( GsTLInt id ) const {
  appli_assert( accessor_->get_property_value( id ) != no_data_value );
  property_type val = accessor_->get_property_value( id );
  return cat_definitions_->get_category_name(val);
}


inline
void GsTLGridCategoricalProperty::set_value( property_type val, GsTLInt id ) {
  accessor_->set_property_value( val, id );
}


inline
void GsTLGridCategoricalProperty::set_value( std::string val, GsTLInt id ) {
  int code = cat_definitions_->category_id(val);
  if( code >= 0 )
	  accessor_->set_property_value( code, id );
}


inline
const CategoricalPropertyDefinition*
	GsTLGridCategoricalProperty::get_category_definition( ) const {
	return cat_definitions_;
}


#endif /* GSTLGRIDCATEGORICALPROPERTY_H_ */
