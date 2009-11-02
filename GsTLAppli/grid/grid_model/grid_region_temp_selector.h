#ifndef __GSTLAPPLI_GRID_REGION_TEMP_SELECTOR_H__ 
#define __GSTLAPPLI_GRID_REGION_TEMP_SELECTOR_H__ 

#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/grid_region.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>

/* This class temporary set a new region as 
* active and region and revert back
* to the original region when the destructor is
* called
*/
class Temporary_gridRegion_Selector {
public :
  Temporary_gridRegion_Selector():region_name_(""), grid_(NULL){}

  Temporary_gridRegion_Selector(std::string new_region_name,
    Geostat_grid* grid) {
      set_temporary_region(new_region_name, grid);
  }

  bool set_temporary_region(std::string new_region_name,
    Geostat_grid* grid)  {
      grid_ = grid;
      GsTLGridRegion* reg = grid_->selected_region();
      if(!reg)
        region_name_ = "";
      else 
        region_name_ = reg->name();
      return grid_->select_region( new_region_name );
  }

  // If region_name_ is empty, the region will be unselected,
  // see region_manager
  ~Temporary_gridRegion_Selector() {
    if(grid_) grid_->select_region( region_name_ );
  }

protected:
  std::string region_name_;
  Geostat_grid* grid_;

};
 

class Temporary_propRegion_Selector {
public :
  Temporary_propRegion_Selector():region_(NULL), prop_(NULL){}

  Temporary_propRegion_Selector(const GsTLGridRegion* new_region,
    GsTLGridProperty* prop) {
      set_temporary_region(new_region, prop);
  }


  void set_temporary_region(const GsTLGridRegion* new_region,
    GsTLGridProperty* prop)  {
      prop_ = prop;
      region_ = prop_->get_region();
      prop_->set_region( new_region );
  }


  // If region_name_ is empty, the region will be unselected,
  // see region_manager
  ~Temporary_propRegion_Selector() {
    if(prop_) prop_->set_region( region_ );
  }

protected:
  const GsTLGridRegion* region_;
  GsTLGridProperty* prop_;

};

#endif