#ifndef CATEGORICAL_CONVERSION_H_
#define CATEGORICAL_CONVERSION_H_

#include <GsTLAppli/actions/common.h>
#include <GsTLAppli/actions/action.h> 

#include <vector>
#include <map>

class GsTL_project; 
class Geostat_grid;
class GsTLGridProperty;

class ACTIONS_DECL Build_categorical_conversion_table :  public Action
{
public: 
  static Named_interface* create_new_interface( std::string& ); 

public:
  Build_categorical_conversion_table() {}
  virtual ~Build_categorical_conversion_table() {}

  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ); 
  virtual bool exec( void );

protected :
	GsTLGridProperty* input_prop_;
    std::string table_filename_;
	Geostat_grid* grid_;
    GsTL_project* proj_;
};

class ACTIONS_DECL Conversion_to_sgems_category_in_place :  public Action
{
public: 
  static Named_interface* create_new_interface( std::string& ); 

public:
  Conversion_to_sgems_category_in_place() {}
  virtual ~Conversion_to_sgems_category_in_place() {}

  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ); 
  virtual bool exec( void );

protected :
    std::vector<GsTLGridProperty*> input_props_;
	  Geostat_grid* grid_;
    GsTL_project* proj_;
    std::map<int,int> table_;
};

class ACTIONS_DECL Conversion_from_sgems_category_group_in_place :  public Action
{
public: 
  static Named_interface* create_new_interface( std::string& ); 

public:
  Conversion_from_sgems_category_group_in_place() {}
  virtual ~Conversion_from_sgems_category_group_in_place() {}

  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ); 
  virtual bool exec( void );

protected :
	  std::vector<GsTLGridProperty*> input_props_;
	  Geostat_grid* grid_;
    GsTL_project* proj_;
    std::map<int,int> table_;
};

#endif