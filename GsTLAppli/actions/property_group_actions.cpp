#include <GsTLAppli/actions/property_group_actions.h>
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h> 
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_property_set.h>


/**
* New_property_group
*/

Named_interface* New_property_group::create_new_interface( std::string& ){
  return new New_property_group;
}
   

bool New_property_group::init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ){

  std::vector< std::string > params = 
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() < 2 ) {
    errors->report( "Must have at least 2 parameters, name of the grid and name the group" );
    return false;
  }

  // Get the grid
  std::string grid_name = params[0];
  SmartPtr<Named_interface> ni = Root::instance()->interface( gridModels_manager + "/" + grid_name);
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( ni.raw_ptr() );
  if(!grid)  {
    errors->report( "The grid "+params[0]+" does not exist" );
    return false;
  }

  GsTLGridPropertyGroup* group = grid->get_group(params[1]);
  if(group)  {
    errors->report( "The goup "+params[1]+" already exist; hence cannot be created" );
    return false;
  }

  std::string type = "";
  if( params.size() == 3 ) {
    if( params[2] == "General" ) type = "";
    else type = params[2];
  }

  group = grid->add_group(params[1],type);
  if(!group)  {
    errors->report( "The goup "+params[1]+" could no be created; possibly type undefined" );
    return false;
  }

  for(int i=3; i< params.size(); i++) {
    GsTLGridProperty* prop = grid->property(params[i]);
    if(prop == NULL)  {
      errors->report( "The property "+params[i]+" does not exist" );
      return false;
    }
  }

  for(int i=3; i< params.size(); i++) {
    group->add_property(grid->property(params[i]));
  }

  proj->update();

  return true;
}

bool New_property_group::exec(){
  return true;
}
 

/**
* Add_properties_to_group::
*/
Named_interface* Add_properties_to_group::create_new_interface( std::string& ){
  return new Add_properties_to_group;
}

 
bool Add_properties_to_group::init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ){

  std::vector< std::string > params = 
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() < 3 ) {
    errors->report( "Must have at least 3 parameters, name of the grid and name the group and at least one property" );
    return false;
  }

  // Get the grid
  SmartPtr<Named_interface> ni = Root::instance()->interface( gridModels_manager + "/" + params[0] );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( ni.raw_ptr() );
  if(!grid)  {
    errors->report( "The grid "+params[0]+" does not exist" );
    return false;
  }

  GsTLGridPropertyGroup* group = grid->get_group(params[1]);
  if(!group)  {
    errors->report( "The goup "+params[1]+" does not exist" );
    return false;
  }

  for(int i=2; i< params.size(); i++) {
    GsTLGridProperty* prop = grid->property(params[i]);
    if(prop == NULL)  {
      errors->report( "The property "+params[i]+" does not exist" );
      return false;
    }
  }

  for(int i=2; i< params.size(); i++) {
    if( !group->is_member_property( params[i] ) )
      group->add_property(grid->property(params[i]));
  }

  return true;
}
bool Add_properties_to_group::exec(){

  return true;
}


/*---------------------------*/

/**
* Add_properties_to_group::
*/
Named_interface* Remove_properties_from_group::create_new_interface( std::string& ){
  return new Remove_properties_from_group;
}

 
bool Remove_properties_from_group::init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ){

  std::vector< std::string > params = 
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() < 3 ) {
    errors->report( "Must have at least 3 parameters, name of the grid and name the group and at least one property" );
    return false;
  }

  // Get the grid
  SmartPtr<Named_interface> ni = Root::instance()->interface( gridModels_manager + "/" + params[0] );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( ni.raw_ptr() );
  if(!grid)  {
    errors->report( "The grid "+params[0]+" does not exist" );
    return false;
  }

  GsTLGridPropertyGroup* group = grid->get_group(params[1]);
  if(!group)  {
    errors->report( "The goup "+params[1]+" does not exist" );
    return false;
  }

  for(int i=2; i< params.size(); i++) {
    GsTLGridProperty* prop = grid->property(params[i]);
    if(prop == NULL)  {
      errors->report( "The property "+params[i]+" does not exist" );
      return false;
    }
  }

  for(int i=2; i< params.size(); i++) {
    if( group->is_member_property( params[i] ) )
      group->remove_property(grid->property(params[i]));
  }

  return true;
}
bool Remove_properties_from_group::exec(){

  return true;
}


/*-------------------*/



Named_interface*
Delete_property_in_group::create_new_interface( std::string& ){
	return new Delete_property_in_group;
}

bool Delete_property_in_group::init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ){
  std::vector< std::string > params =
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() != 2 ) {
    errors->report( "Must have 2 parameters, name of the grid and name the group to be deleted" );
    return false;
  }

  // Get the grid
  SmartPtr<Named_interface> ni = Root::instance()->interface( gridModels_manager + "/" + params[0] );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( ni.raw_ptr() );
  if(!grid)  {
    errors->report( "The grid "+params[0]+" does not exist" );
    return false;
  }

  GsTLGridPropertyGroup* group = grid->get_group(params[1]);
  if(!group)  {
    errors->report( "The goup "+params[1]+" does not exist" );
    return false;
  }

  //GsTLGridPropertyGroup::property_map::iterator it = group->begin_property();
  std::vector<std::string>  names = group->property_names();
  std::vector<std::string>::const_iterator it = names.begin();
  for(; it != names.end(); ++it){
  	grid->remove_property(*it);
  }
  grid->remove_group(params[1]);
  return true;
}

bool Delete_property_in_group::exec(){
	return true;

}

/*
 *  --------------------------------
 */


Named_interface*
Remove_group::create_new_interface( std::string& ){
	return new Remove_group;
}

bool Remove_group::init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ){
  std::vector< std::string > params =
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() != 2 ) {
    errors->report( "Must have 2 parameters, name of the grid and name the group to be removed" );
    return false;
  }

  // Get the grid
  SmartPtr<Named_interface> ni = Root::instance()->interface( gridModels_manager + "/" + params[0] );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( ni.raw_ptr() );
  if(!grid)  {
    errors->report( "The grid "+params[0]+" does not exist" );
    return false;
  }

  GsTLGridPropertyGroup* group = grid->get_group(params[1]);
  if(!group)  {
    errors->report( "The group "+params[1]+" does not exist" );
    return false;
  }

  grid->remove_group(params[1]);
  return true;
}

bool Remove_group::exec(){
	return true;

}

