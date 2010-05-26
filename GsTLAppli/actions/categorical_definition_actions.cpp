#include <GsTLAppli/actions/categorical_definition_actions.h> 
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h> 
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_categorical_property.h> 

Named_interface* New_categorical_definition::create_new_interface( std::string& ) {
  return new New_categorical_definition;
}

bool New_categorical_definition::init( std::string& parameters, GsTL_project* proj,
                                      Error_messages_handler* errors ) {

  std::vector< std::string > params = 
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() < 3 ) {
    errors->report( "Must have at least 3 parameters, name of the definition and at least two categories" );
    return false;
  }

  std::string def_name = params[0];
  int n_cat = params.size()-1;
// Check if the definition already exist
   SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager+"/"+def_name );
  if( ni ) {
    errors->report("There is already a definition named "+def_name );
    return false;
  }
  ni = Root::instance()->new_interface( "categoricaldefinition://"+def_name,
                                         categoricalDefinition_manager +"/"+def_name );
  CategoricalPropertyDefinitionName* cat_def = 
            dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());

  for(int i=1; i<params.size(); i++ ) {
    cat_def->add_category(params[i]);
  }
  
  return true;

}

bool New_categorical_definition::exec()  {
  return true;
}


/*
        -------------------------------
*/

Named_interface* Assign_categorical_definition::create_new_interface( std::string& ) {
  return new Assign_categorical_definition;
}

bool Assign_categorical_definition::init( std::string& parameters, GsTL_project* proj,
                                      Error_messages_handler* errors ) {

  std::vector< std::string > params = 
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() < 2 ) {
    errors->report( "Must have at least 3 parameters, name of the definition, the grid  and at least one property" );
    return false;
  }

// Check if the categorical definition exist
  SmartPtr<Named_interface> ni = Root::instance()->interface( categoricalDefinition_manager+"/"+params[0] );

  CategoricalPropertyDefinitionName* cat_def = 
            dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());
  if( cat_def ) {
    errors->report("No definition named "+params[0] );
    return false;
  }

// Check if the grid exist
  ni = Root::instance()->interface( gridModels_manager + "/" + params[1] );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( ni.raw_ptr() );
  if( cat_def ) {
    errors->report("No grid named "+params[1] );
    return false;
  }

  for(int i=2;i<params.size(); ++i) {
    GsTLGridCategoricalProperty* prop = grid->categorical_property(params[i]);
    if(!prop) continue;
    prop->set_category_definition( cat_def );
  }
  return true;
}
 

bool Assign_categorical_definition::exec()  {
  return true;
}