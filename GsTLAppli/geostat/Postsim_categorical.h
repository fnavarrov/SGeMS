/**********************************************************************
** Author: Alexndre Boucher
** Copyright (C) Advanced Resources and Risk Technology, LLC
**
** This file is part of the "geostat" module of the Geostatistical Earth
** Modeling Software (GEMS)
**
** This file may be distributed and/or modified under the terms of the 
** license defined by the Stanford Center for Reservoir Forecasting and 
** appearing in the file LICENSE.XFREE included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.gnu.org/copyleft/gpl.html for GPL licensing information.
**
**
**********************************************************************/
#ifndef __GSTLAPPLI_GEOSTAT_PLUGIN_POSTSIM_CATEGORICAL_H__
#define __GSTLAPPLI_GEOSTAT_PLUGIN_POSTSIM_CATEGORICAL_H__

#include <GsTL/utils/smartptr.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/math/gstlpoint.h>

#include <GsTLAppli/grid/grid_model/point_set.h>
#include <GsTLAppli/grid/grid_model/rgrid.h>
#include <GsTLAppli/grid/grid_model/neighborhood.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_categorical_property.h>
#include <GsTLAppli/grid/grid_model/grid_region_temp_selector.h> 

#include <GsTLAppli/geostat/geostat_algo.h>
#include <GsTLAppli/geostat/parameters_handler.h>




class Geostat_grid;
 
class  Postsim_categorical : public Geostat_algo {
 public:
  static Named_interface* create_new_interface(std::string&);

 public:
	 Postsim_categorical();
	virtual bool initialize( const Parameters_handler* parameters,
			   Error_messages_handler* errors );

  /** Runs the algorithm. 
   * @return 0 if the run was successful
   */
  
	virtual int execute( GsTL_project* proj=0 );
  /** Tells the name of the algorithm
   */
	virtual std::string name() const { return "Postsim_categorical"; }
   
  private:

    int execute_continous();
    int execute_categorical();

private :
	typedef std::vector< GsTLGridCategoricalProperty* > cat_prop_vecT;
  typedef std::vector< GsTLGridProperty* > prop_vecT;
  
  int ncat_;

	Geostat_grid* grid_;
	cat_prop_vecT props_;
  prop_vecT etype_props_;


  const CategoricalPropertyDefinition* cat_def_;

  Temporary_gridRegion_Selector gridTempRegionSelector_;

};

#endif

