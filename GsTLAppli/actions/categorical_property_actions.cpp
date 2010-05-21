/*
 * categorical_property_actions.cpp
 *
 *  Created on: Apr 3, 2010
 *      Author: aboucher
 */

#include "categorical_property_actions.h"

create_categorical_definiton_action::create_categorical_definiton_action() {
	// TODO Auto-generated constructor stub

}

create_categorical_definiton_action::~create_categorical_definiton_action() {
	// TODO Auto-generated destructor stub
}

virtual bool create_categorical_definiton_action::init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ){

	  proj_ = proj ;

	  std::vector< std::string > params =
	      String_Op::decompose_string( parameters, Actions::separator,
					   Actions::unique );

	  if( params.size() <3 ) {
		errors->report("A categorical definition must have at least two category names");
		return false;
	  }

	  // Check to see if another cdefintion exists with the same name
	  // use the manager, if exist return false

	  std::vector<std::string> cat_names(params.begin()+1,params.end() );
//	  create the new catdef

	  proj->update();


	  return true;
}

virtual bool create_categorical_definiton_action::exec(){
	return true;
}



virtual bool assign_categorical_def_to_properties_action::init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ){

	  proj_ = proj ;

	  std::vector< std::string > params =
	      String_Op::decompose_string( parameters, Actions::separator,
					   Actions::unique );

	  if( params.size() <3 ) {
		errors->report("Must at least contains the name of the grid, the name of ONE property and the name of the categorical definition");
		return false;
	  }

	  std::string grid_name;

	  SmartPtr<Named_interface> ni =
	    Root::instance()->interface( gridModels_manager + "/" + grid_name );
	  if( ni.raw_ptr() == 0 ) {
	    errors_->report( "Object " + grid_name + " does not exist." );
	    return false;
	  }

	  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( ni.raw_ptr() );
	  if( grid == 0) {
	    errors_->report( "The grid " + grid_name + " does not exist." );
	    return false;
	  }

	  // Check to see if another cdefinition exists with the same name
	  // use the manager, if exist return false


	  for(int i=1; i<params.size()-1; ++i) {
		  GsTLGridCategoricalProperty* cprop = grid->categorical_property(params[i]);
		  if(!cprop) {
			  errors_->report( "Property " + params[i] + " does not exist or is not a categorical property." );
			  return false;
		  }
	  }

	  for(int i=1; i<params.size()-1; ++i) {
		  GsTLGridCategoricalProperty* cprop = grid->categorical_property(params[i]);
		  cprop->set_category_definition(cdefinition);
	  }

	  proj->update();

	  return true;
}

virtual bool assign_categorical_def_to_properties_action::exec(){
	return true;
}
