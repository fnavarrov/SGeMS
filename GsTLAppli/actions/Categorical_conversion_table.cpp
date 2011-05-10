#include "Categorical_conversion_table.h"

#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_property_set.h>
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/geostat/utilities.h>


Named_interface* Build_categorical_conversion_table::
create_new_interface( std::string& ){
  return new Build_categorical_conversion_table;
}

bool Build_categorical_conversion_table::init(std::string& parameters, GsTL_project* proj,
                         Error_messages_handler* errors) {

  std::vector< std::string > params = 
    String_Op::decompose_string( parameters, Actions::separator,
                      				   Actions::unique );

  if( params.size() < 3 ) {
    errors->report( "some parameters are missing" );  
    return false;
  }

  proj_ = proj;
	std::string grid_name = params[0];
  if(grid_name.empty()) errors->report( "No grid selected" );

  std::string input_prop_name = params[1];
	if(input_prop_name.empty()) errors->report( "No input property name specified" );

  table_filename_ = params[2];
  if(table_filename_.empty()) {
    errors->report( "No output filename name specified" );
    return false;
  }


  if( grid_name.empty() ) {
	  errors->report("No grid was specified" );
	  if(!errors->empty()) return false;
  }
  // get the grid from the grid manager
  SmartPtr<Named_interface> grid_ni =
  Root::instance()->interface( gridModels_manager + "/" + grid_name );
  grid_ = dynamic_cast<Geostat_grid*>( grid_ni.raw_ptr() );

  if( !grid_ ) {
	  errors->report("Grid does not exist" );
    return false;
  }
	
	input_prop_ = grid_->property(input_prop_name);
	if( !input_prop_ ) {
		errors->report( "Input_Property_Name", "The input property does not exist" );
		return false;
	}

  return errors->empty();

}

/*
The file structure is   OriginalCode SGeMSCode
*/

bool Build_categorical_conversion_table::exec() {
  GsTLGridProperty::iterator it = input_prop_->begin();
  std::set<int> table;
  for(; it!=input_prop_->end(); ++it ) {
    table.insert(*it);
  }

  std::ofstream outfile;
  outfile.open( table_filename_.c_str());
  if(outfile.fail()) return NULL;
  
  std::set<int>::iterator it_c = table.begin();
  for(; it_c != table.end() ; ++it_c) {
    outfile<<*it_c<<" "<<std::distance(table.begin(),it_c)<<std::endl;
  }

  outfile.close();
}




/*
  GridName::fileName::propName[::propName2:: ... ]
*/

Named_interface* Conversion_to_sgems_category_in_place::
create_new_interface( std::string& ){
  return new Conversion_to_sgems_category_in_place;
}

bool Conversion_to_sgems_category_in_place::init(std::string& parameters, GsTL_project* proj,
                         Error_messages_handler* errors) {

  std::vector< std::string > params = 
    String_Op::decompose_string( parameters, Actions::separator,
                      				   Actions::unique );

  if( params.size() < 3 ) {
    errors->report( "some parameters are missing" );  
    return false;
  }

  proj_ = proj;
	std::string grid_name = params[0];
  if(grid_name.empty()) {
    errors->report( "No grid selected" );
    return false;
  }
/*
	bool ok = geostat_utils::create( grid_, grid_name,
				 "Grid_Name", errors );
	if(!ok) errors->report("Grid does not exist" );
*/

  // get the grid from the grid manager
  SmartPtr<Named_interface> grid_ni =
  Root::instance()->interface( gridModels_manager + "/" + grid_name );
  grid_ = dynamic_cast<Geostat_grid*>( grid_ni.raw_ptr() );

  if( !grid_ ) {
	  errors->report("Grid does not exist" );
    return false;
  }

	if(!errors->empty()) return false;


  std::string table_filename = params[1];
  if(table_filename.empty()) {
    errors->report( "No output filename name specified" );
    return false;
  }

  std::ifstream infile;
  infile.open( table_filename.c_str());
  if(infile.fail()) return NULL;

  while(!infile.eof()) {
    int code_from, code_to;
    infile>>code_from>>code_to;
    table_[code_from] = code_to;
  }
  infile.close();

  for(int i = 2; i<params.size(); ++i) {
    GsTLGridProperty* prop = grid_->property(params[i]);
	  if( !prop ) {
		  errors->report( "Input_Property_Name", "The input property "+params[i]+" does not exist" );
		  return false;
	  }
    input_props_.push_back(prop);
  }


  return errors->empty();

}

bool Conversion_to_sgems_category_in_place::exec() {
  for( int i=0; i< input_props_.size(); ++i) {
    GsTLGridProperty::iterator it = input_props_[i]->begin();
    for( ; it!= input_props_[i]->end(); ++it) {
      std::map<int,int>::iterator it_code = table_.find(*it);
      if(it_code == table_.end()) *it = GsTLGridProperty::no_data_value;
      else *it = it_code->second;
    }
  }
  return true;
}





/*
  GridName::fileName::groupName
*/

Named_interface* Conversion_from_sgems_category_group_in_place::
create_new_interface( std::string& ){
  return new Conversion_from_sgems_category_group_in_place;
}


bool Conversion_from_sgems_category_group_in_place::init(std::string& parameters, GsTL_project* proj,
                         Error_messages_handler* errors) {

  std::vector< std::string > params = 
    String_Op::decompose_string( parameters, Actions::separator,
                      				   Actions::unique );

  if( params.size() != 3 ) {
    errors->report( "some parameters are missing" );  
    return false;
  }

  proj_ = proj;
	std::string grid_name = params[0];
  if(grid_name.empty()) {
    errors->report( "No grid selected" );
    return false;
  }
/*
	bool ok = geostat_utils::create( grid_, grid_name,
				 "Grid_Name", errors );
	if(!ok) errors->report("Grid does not exist" );
	if(!errors->empty()) return false;
*/

  // get the grid from the grid manager
  SmartPtr<Named_interface> grid_ni =
  Root::instance()->interface( gridModels_manager + "/" + grid_name );
  grid_ = dynamic_cast<Geostat_grid*>( grid_ni.raw_ptr() );

  if( !grid_ ) {
	  errors->report("Grid does not exist" );
    return false;
  }



  std::string table_filename = params[1];
  if(table_filename.empty()) {
    errors->report( "No output filename name specified" );
    return false;
  }

  //The file structure is
  std::ifstream infile;
  infile.open( table_filename.c_str());
  if(infile.fail()) return NULL;

  while(!infile.eof()) {
    int code_from, code_to;
    infile>>code_from>>code_to;
    table_[code_to] = code_from;
  }
  infile.close();


  GsTLGridPropertyGroup* group = grid_->get_group( params[2] );
  if( !group ) {
		  errors->report( "Input_Group_Name", "The input group "+params[2]+" does not exist" );
		  return false;
  }

  std::vector<std::string> pnames = group->property_names();
  for(int i = 0; i<pnames.size(); ++i) {
    GsTLGridProperty* prop = grid_->property(pnames[i]);
	  if( !prop ) {
		  errors->report( "Input_Property_Name", "The input property "+pnames[i]+" does not exist" );
		  return false;
	  }
    input_props_.push_back(prop);
  }


  return errors->empty();

}

bool Conversion_from_sgems_category_group_in_place::exec() {

  for( int i=0; i< input_props_.size(); ++i) {
    GsTLGridProperty::iterator it = input_props_[i]->begin();
    for( ; it!= input_props_[i]->end(); ++it) {
      std::map<int,int>::iterator it_code = table_.find(*it);
      if(it_code == table_.end()) *it = GsTLGridProperty::no_data_value;
      else *it = it_code->second;
    }
  }

  return true;

}
