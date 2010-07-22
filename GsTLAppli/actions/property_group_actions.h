/**********************************************************************
** Author: Alexandre Boucher
** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
**   University
** All rights reserved.
**
** This file is part of the "actions" module of the Geostatistical Earth
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
** Contact the Stanford Center for Reservoir Forecasting, Stanford University
** if any conditions of this licensing are not clear to you.
**
**********************************************************************/

#ifndef __GSTLAPPLI_PROPERTY_GROUP_ACTIONS_H__ 
#define __GSTLAPPLI_PROPERTY_GROUP_ACTIONS_H__ 

#include <GsTLAppli/actions/common.h>
#include <GsTLAppli/actions/action.h> 


#include <qstring.h>
 
#include <string> 
#include <set>

class GsTL_project; 
class Error_messages_handler;

class ACTIONS_DECL New_property_group : public Action { 
 public: 
  static Named_interface* create_new_interface( std::string& ); 
 
 public: 
  New_property_group() {} 
  virtual ~New_property_group() {} 
   
  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ); 
  virtual bool exec(); 
 
 private: 

}; 

class ACTIONS_DECL Add_properties_to_group : public Action { 
 public: 
  static Named_interface* create_new_interface( std::string& ); 
 
 public: 
  Add_properties_to_group() {} 
  virtual ~Add_properties_to_group() {} 
   
  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ); 
  virtual bool exec(); 
 
 private: 

}; 

class ACTIONS_DECL Delete_property_in_group : public GroupNoParameterAction {
 public:
  static Named_interface* create_new_interface( std::string& );

 public:
  Delete_property_in_group():GroupNoParameterAction("RemoveAllPropertiesFromGroup") {}
  virtual ~Delete_property_in_group() {}

  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors );
  virtual bool exec();

 private:

};


class ACTIONS_DECL Remove_group : public GroupNoParameterAction {
 public:
  static Named_interface* create_new_interface( std::string& );

 public:
  Remove_group():GroupNoParameterAction("RemoveGroup") { }
  virtual ~Remove_group() {}

  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors );
  virtual bool exec();

 private:

};



#endif
