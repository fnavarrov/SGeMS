#include <GsTLAppli/gui/appli/object_tree_context_menu.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/actions/unary_action.h>
#include <GsTLAppli/actions/obj_manag_actions.h>
#include <GsTLAppli/utils/string_manipulation.h>

BaseTreeItemMenu::BaseTreeItemMenu(ObjectTree* _object_tree, QWidget* _parent) :
	object_tree_(_object_tree), QMenu(_parent)
{
	QObject::connect(this, SIGNAL(triggered(QAction*)), this, SLOT(onContextMenuClick(QAction*)));
}

BaseTreeItemMenu::~BaseTreeItemMenu()
{
}

void BaseTreeItemMenu::setMenuItemEnable(QString _action_name, bool _enable)
{
	for (std::vector<QAction*>::iterator iter = action_.begin(); iter != action_.end(); ++iter)
	{
		if ((*iter)->text() == _action_name)
		{
			(*iter)->setEnabled(_enable);
		}
	}
}

void BaseTreeItemMenu::setObjectTree(ObjectTree* _object_tree)
{
	object_tree_ = _object_tree;
}

void BaseTreeItemMenu::onContextMenuClick(QAction* _action)
{
	handleContextMenuClick(_action);
}

void BaseTreeItemMenu::handleContextMenuClick(QAction* _action)
{
}

/**
 *
 */
ObjectTreeItemMenu::ObjectTreeItemMenu(ObjectTree* _object_tree, QWidget* _parent) :
	BaseTreeItemMenu(_object_tree, _parent)
{
	action_.push_back(addAction("Delete"));

	action_.push_back(addSeparator());

	QMenu* trend_action_menu = addMenu("Create Trend");
	nested_menu_.push_back(trend_action_menu);
	QObject::connect(trend_action_menu, SIGNAL(triggered(QAction*)), this, SLOT(onTrendActionClick(QAction*)));

	// Create_trend trend_action();
	std::vector<std::string> trend_functions = Create_trend().get_trend_functions();

	std::vector<std::string>::iterator begin = trend_functions.begin();
	for (; begin != trend_functions.end(); ++begin)
	{
		QString menuItemName(begin->c_str());
		action_.push_back(trend_action_menu->addAction(menuItemName));
	}
}

ObjectTreeItemMenu::~ObjectTreeItemMenu()
{
}

void ObjectTreeItemMenu::handleContextMenuClick(QAction* _action)
{
	object_tree_->onObjectContextMenuClick(_action);
}

void ObjectTreeItemMenu::onTrendActionClick(QAction* _action)
{
	object_tree_->onTrendActionClick(_action);
}

/**
 *
 */

PropertyTreeItemMenu_Single::PropertyTreeItemMenu_Single(ObjectTree* _object_tree, QWidget* _parent) :
	BaseTreeItemMenu(_object_tree, _parent)
{
	action_.push_back(addAction("Rename"));
	action_.push_back(addAction("Delete"));

	action_.push_back(addSeparator());

	action_.push_back(addAction("Histogram"));

	action_.push_back(addSeparator());

	action_.push_back(addAction("Swap to disk"));
	action_.push_back(addAction("Swap to RAM"));

	// add unary actions
	{
		SmartPtr<Named_interface> ni = Root::instance()->interface(actions_manager);
		Manager* manager = dynamic_cast<Manager*> (ni.raw_ptr());
		if (manager)
		{
			action_.push_back(addSeparator());
			QMenu* unary_action_menu = addMenu("Data transform");
			nested_menu_.push_back(unary_action_menu);
			QObject::connect(unary_action_menu, SIGNAL(triggered(QAction*)), this, SLOT(onUnaryActionClick(QAction*)));

			Manager::type_iterator begin = manager->begin();
			Manager::type_iterator end = manager->end();
			for (; begin != end; ++begin)
			{
				std::string name = *begin;
				QString menuItemName(name.c_str());
				SmartPtr<Named_interface> instance = manager->new_interface(name, name, &name);
				PropertyNoParameterAction* uaction = dynamic_cast<PropertyNoParameterAction*> (instance.raw_ptr());
				if (uaction)
				{
					action_.push_back(unary_action_menu->addAction(menuItemName));
				}
				manager->delete_interface(name);
			}
		}
	}

	// add python scripts
	{
		SmartPtr<Named_interface> ni = Root::instance()->interface(python_script_manager);
		Manager* manager = dynamic_cast<Manager*> (ni.raw_ptr());
		if (manager)
		{
			action_.push_back(addSeparator());
			QMenu* python_script_menu = addMenu("Python Scripts");
			nested_menu_.push_back(python_script_menu);
			QObject::connect(python_script_menu, SIGNAL(triggered(QAction*)), this, SLOT(onPythonScriptAction(QAction*)));

			Manager::interface_iterator begin = manager->begin_interfaces();
			Manager::interface_iterator end = manager->end_interfaces();
			for (; begin != end; ++begin)
			{
				QString script_name(manager->name(begin->raw_ptr()).c_str());
				action_.push_back(python_script_menu->addAction(script_name));
			}
		}
	}
}

PropertyTreeItemMenu_Single::~PropertyTreeItemMenu_Single()
{
	for (std::vector<QMenu*>::iterator iter = nested_menu_.begin(); iter != nested_menu_.end(); ++iter)
	{
		delete (*iter);
	}
}

void PropertyTreeItemMenu_Single::handleContextMenuClick(QAction* _action)
{
	object_tree_->onPropertyContextMenuClick(_action);
}

void PropertyTreeItemMenu_Single::onUnaryActionClick(QAction* _action)
{
	object_tree_->onUnaryActionClick(_action);
}

void PropertyTreeItemMenu_Single::onPythonScriptAction(QAction* _action)
{
	object_tree_->onPythonScriptClick(_action);
}

/**
 *
 */
PropertyTreeItemMenu_Multiple::PropertyTreeItemMenu_Multiple(ObjectTree* _object_tree, QWidget* _parent) :
	BaseTreeItemMenu(_object_tree, _parent)
{

	// add python scripts
	{
		SmartPtr<Named_interface> ni = Root::instance()->interface(python_script_manager);
		Manager* manager = dynamic_cast<Manager*> (ni.raw_ptr());
		if (manager)
		{
			action_.push_back(addSeparator());
			QMenu* python_script_menu = addMenu("Python Scripts");
			nested_menu_.push_back(python_script_menu);
			QObject::connect(python_script_menu, SIGNAL(triggered(QAction*)), this, SLOT(onPythonScriptAction(QAction*)));

			Manager::interface_iterator begin = manager->begin_interfaces();
			Manager::interface_iterator end = manager->end_interfaces();
			for (; begin != end; ++begin)
			{
				QString script_name(manager->name(begin->raw_ptr()).c_str());
				action_.push_back(python_script_menu->addAction(script_name));
			}
		}
	}
}

PropertyTreeItemMenu_Multiple::~PropertyTreeItemMenu_Multiple()
{
}

void PropertyTreeItemMenu_Multiple::handleContextMenuClick(QAction* _action)
{
	object_tree_->onPropertyContextMenuClick(_action);
}

void PropertyTreeItemMenu_Multiple::onPythonScriptAction(QAction* _action)
{
	object_tree_->onPythonScriptClick(_action);
}

/**
 *
 */
PropertyGroupTreeItemMenu::PropertyGroupTreeItemMenu(ObjectTree* _object_tree, QWidget* _parent) :
	BaseTreeItemMenu(_object_tree, _parent)
{
	// add unary actions
	{
		SmartPtr<Named_interface> ni = Root::instance()->interface(actions_manager);
		Manager* manager = dynamic_cast<Manager*> (ni.raw_ptr());
		if (manager)
		{
			QObject::connect(this, SIGNAL(triggered(QAction*)), this, SLOT(onUnaryGroupActionClick(QAction*)));

			Manager::type_iterator begin = manager->begin();
			Manager::type_iterator end = manager->end();
			for (; begin != end; ++begin)
			{
				std::string name = *begin;
				QString menuItemName(name.c_str());
				SmartPtr<Named_interface> instance = manager->new_interface(name, name, &name);
				GroupNoParameterAction* uaction = dynamic_cast<GroupNoParameterAction*> (instance.raw_ptr());
				if (uaction)
				{
					action_.push_back(addAction(menuItemName));
				}
				manager->delete_interface(name);
			}
		}
	}
	// add group python scripts
	{
		SmartPtr<Named_interface> ni = Root::instance()->interface(python_group_script_manager);
		Manager* manager = dynamic_cast<Manager*> (ni.raw_ptr());
		if (manager)
		{
			action_.push_back(addSeparator());
			QMenu* python_script_menu = addMenu("Python Scripts");
			nested_menu_.push_back(python_script_menu);
			QObject::connect(python_script_menu, SIGNAL(triggered(QAction*)), this, SLOT(onPythonScriptAction(QAction*)));

			Manager::interface_iterator begin = manager->begin_interfaces();
			Manager::interface_iterator end = manager->end_interfaces();
			for (; begin != end; ++begin)
			{
				QString script_name(manager->name(begin->raw_ptr()).c_str());
				action_.push_back(python_script_menu->addAction(script_name));
			}
		}
	}
}

PropertyGroupTreeItemMenu::~PropertyGroupTreeItemMenu()
{
	for (std::vector<QMenu*>::iterator iter = nested_menu_.begin(); iter != nested_menu_.end(); ++iter)
	{
		delete (*iter);
	}
}

void PropertyGroupTreeItemMenu::handleContextMenuClick(QAction* _action)
{
}

void PropertyGroupTreeItemMenu::onPythonScriptAction(QAction* _action)
{
	object_tree_->onPythonGroupScriptClick(_action);
}


void PropertyGroupTreeItemMenu::onUnaryGroupActionClick(QAction* _action)
{
	object_tree_->onUnaryGroupActionClick(_action);
}
