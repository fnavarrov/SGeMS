/**********************************************************************
** Author: Alexandre Boucher
** Copyright (C) 2010  Advanced Resources and Risk Technology
** All rights reserved.
**
** This file is part of the "geostat" module of the Geostatistical Earth
** Modeling Software (SGeMS)
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
#ifndef __GSTLAPPLI_GEOSTAT_PLUGIN_DIFFBASE_H__
#define __GSTLAPPLI_GEOSTAT_PLUGIN_DIFFBASE_H__



#include <GsTL/utils/smartptr.h>
#include <GsTLAppli/utils/error_messages_handler.h>

#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/grid_region_temp_selector.h>

#include <GsTLAppli/geostat/geostat_algo.h>
#include <GsTLAppli/geostat/parameters_handler.h>





class Geostat_grid;
 
class  DiffProperties : public Geostat_algo {
 public:
  static Named_interface* create_new_interface(std::string&);

 public:
   DiffProperties() {}
	virtual bool initialize( const Parameters_handler* parameters,
			   Error_messages_handler* errors );

  /** Runs the algorithm. 
   * @return 0 if the run was successful
   */
  
	virtual int execute( GsTL_project* proj=0 );
  /** Tells the name of the algorithm
   */
	virtual std::string name() const { return "DifferenceWithBase"; }
   
  private:

  Geostat_grid* grid_;

	std::vector< GsTLGridProperty* > props_;
  GsTLGridProperty* prop_base_;

  std::string prop_name_diff_;

  Temporary_gridRegion_Selector grid_region_;

};



#endif