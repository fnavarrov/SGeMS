/*
 * categorical_property_actions.h
 *
 *  Created on: Apr 3, 2010
 *      Author: aboucher
 */

#ifndef CATEGORICAL_PROPERTY_ACTIONS_H_
#define CATEGORICAL_PROPERTY_ACTIONS_H_

#include "action.h"

class create_categorical_definiton_action: public Action {
public:
	create_categorical_definiton_action();
	virtual ~create_categorical_definiton_action();
	virtual bool init( std::string& parameters, GsTL_project* proj,
	                     Error_messages_handler* errors );
	virtual bool exec();

};

class assign_categorical_def_to_properties_action: public Action {
public:
	assign_categorical_def_to_properties_action(){}
	virtual ~assign_categorical_def_to_properties_action(){}
	virtual bool init( std::string& parameters, GsTL_project* proj,
	                     Error_messages_handler* errors );
	virtual bool exec();

};

#endif /* CATEGORICAL_PROPERTY_ACTIONS_H_ */
