#include <maskedgrid_actions.h>
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/filters/filter.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/cartesian_grid.h>
#include <GsTLAppli/grid/grid_model/reduced_grid.h> 

Named_interface* Create_mgrid_from_cgrid::create_new_interface( std::string& ) {
  return new Create_mgrid_from_cgrid();
}

  /** The parameters for this function are: 
   * - the name of the new grid 
   * - the name of the existing cgrid
   * - the name of the region
   */ 
bool 
Create_mgrid_from_cgrid::init( std::string& parameters, GsTL_project* proj,
                                     Error_messages_handler* errors ){
  proj_ = proj ;
  errors_ = errors;

  std::vector< std::string > params = 
      String_Op::decompose_string( parameters, Actions::separator,
				   Actions::unique );

  if( params.size() <3 )
    return false;
  
  cgrid_name_ = params[0];
  mgrid_name_ = params[1];
  region_names_.insert(region_names_.begin(),params.begin()+2,params.end());

  return true;

}
bool Create_mgrid_from_cgrid::exec(){
  // Get the grid from the manager
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager + "/" + cgrid_name_ );
  if( ni.raw_ptr() == 0 ) {
    errors_->report( "Object " + cgrid_name_ + " does not exist." );
    return false;
  }

  Cartesian_grid* cgrid = dynamic_cast<Cartesian_grid*>( ni.raw_ptr() );
  if( cgrid == 0) {
    errors_->report( "Object " + cgrid_name_ + " is not a cartesian grid." );
    return false;
  }    
 // Get the region
  std::vector<GsTLGridRegion*> regions;
  std::vector<std::string>::iterator it =  region_names_.begin();
  for( ; it!= region_names_.end(); ++it) {
    GsTLGridRegion* region = cgrid->region( *it );
    if(!region) {
      errors_->report( "Region " + (*it) + " does not exist."  );
      return false;
    }
    regions.push_back(region);
  }
  
// Create the new masked_grid
//	std::ostringstream ostr;
//	ostr << ;
//  std::string final_grid_name;
//	ni = 
//		Root::instance()->new_interface( "reduced_grid",
//		gridModels_manager + "/" + grid_name,
//		&final_grid_name );

  std::string final_mgrid_name;
//  std::string mgrid_full_name( "/GridObject/Model/" + mgrid_name_, &final_mgrid_name );
  ni = 
      Root::instance()->new_interface("reduced_grid", 
      gridModels_manager + "/" + mgrid_name_,
      &final_mgrid_name);

  mgrid_name_ = final_mgrid_name;
  
  if( ni.raw_ptr() == 0 ) {
    errors_->report( "Object " + mgrid_name_ + " already exists. Use a different name." );
    return false;
  }
  
  Reduced_grid* grid = dynamic_cast<Reduced_grid*>( ni.raw_ptr() );

  //Create the grid
  if( regions.size() == 1 ) {  //avoid a copy of the region array
    grid->set_dimensions( 
      cgrid->geometry()->dim(0), 
      cgrid->geometry()->dim(1), 
      cgrid->geometry()->dim(2),
      cgrid->cell_dimensions()[0], 
      cgrid->cell_dimensions()[1], 
      cgrid->cell_dimensions()[2], 
      regions[0]->data());
  } else {
    int mask_size = regions[0]->size();
    std::vector<bool> mask( mask_size );
    for( int i=0; i< mask_size; ++i ) {
      bool ok = false;
      for( int j = 0; j<regions.size(); j++ ) {
        ok == ok || regions[j]->is_inside_region(i);
      }
      mask[i] = ok;
    }
    grid->set_dimensions( 
      cgrid->geometry()->dim(0), 
      cgrid->geometry()->dim(1), 
      cgrid->geometry()->dim(2),
      cgrid->cell_dimensions()[0], 
      cgrid->cell_dimensions()[1], 
      cgrid->cell_dimensions()[2], 
      mask);
  }

  grid->origin( cgrid->origin() );

  proj_->new_object( mgrid_name_ );
  return true;
}