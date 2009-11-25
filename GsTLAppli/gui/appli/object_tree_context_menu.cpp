#include <GsTLAppli/gui/appli/object_tree_context_menu.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/actions/unary_action.h>
#include <GsTLAppli/actions/python_script.h>
#include <GsTLAppli/actions/obj_manag_actions.h>
#include <GsTLAppli/utils/string_manipulation.h>

ObjectTreeContextMenu::ObjectTreeContextMenu(ObjectTree* _object_tree, QWidget* _parent) :
	object_tree_(_object_tree), QMenu(_parent) {
	QObject::connect(this, SIGNAL(triggered(QAction*)), this, SLOT(onContextMenuClick(QAction*)));
}

ObjectTreeContextMenu::~ObjectTreeContextMenu() {
	//	for (std::vector<QAction*>::iterator iter = action_.begin(); iter != action_.end(); ++iter) {
	//		delete (*iter);
	//	}
}

void ObjectTreeContextMenu::setMenuItemEnable(QString _action_name, bool _enable) {
	for (std::vector<QAction*>::iterator iter = action_.begin(); iter != action_.end(); ++iter) {
		if ((*iter)->text() == _action_name) {
			(*iter)->setEnabled(_enable);
		}
	}
}

void ObjectTreeContextMenu::onContextMenuClick(QAction* _action) {
	handleContextMenuClick(_action);
}

/**
 *
 */

MultiPropertyContextMenu::MultiPropertyContextMenu(ObjectTree* _object_tree, QWidget* _parent) :
	ObjectTreeContextMenu(_object_tree, _parent) {
	action_.push_back(addAction("Delete"));
}

MultiPropertyContextMenu::~MultiPropertyContextMenu() {
}

void MultiPropertyContextMenu::handleContextMenuClick(QAction* _action) {
	object_tree_->onPropertyContextMenuClick(_action);
}

/**
 *
 */

SinglePropertyContextMenu::SinglePropertyContextMenu(ObjectTree* _object_tree, QWidget* _parent) :
	ObjectTreeContextMenu(_object_tree, _parent) {

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
		if (manager) {
			action_.push_back(addSeparator());
			QMenu* unary_action_menu = addMenu("Data transform");
			nested_menu_.push_back(unary_action_menu);
			QObject::connect(unary_action_menu, SIGNAL(triggered(QAction*)), this, SLOT(onUnaryActionClick(QAction*)));

			Manager::type_iterator begin = manager->begin();
			Manager::type_iterator end = manager->end();
			for (; begin != end; ++begin) {
				std::string name = *begin;
				QString menuItemName(name.c_str());
				SmartPtr<Named_interface> instance = manager->new_interface(name, name, &name);
				Unary_action* uaction = dynamic_cast<Unary_action*> (instance.raw_ptr());
				if (uaction) {
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
		if (manager) {
			action_.push_back(addSeparator());
			QMenu* python_script_menu = addMenu("Python Scripts");
			nested_menu_.push_back(python_script_menu);
			QObject::connect(python_script_menu, SIGNAL(triggered(QAction*)), this, SLOT(onPythonSciptAction(QAction*)));

			Manager::interface_iterator begin = manager->begin_interfaces();
			Manager::interface_iterator end = manager->end_interfaces();
			for (; begin != end; ++begin) {
				QString script_name(manager->name(begin->raw_ptr()).c_str());
				action_.push_back(python_script_menu->addAction(script_name));
			}
		}
	}

}

SinglePropertyContextMenu::~SinglePropertyContextMenu() {
	for (std::vector<QMenu*>::iterator iter = nested_menu_.begin(); iter != nested_menu_.end(); ++iter) {
		delete (*iter);
	}
}

void SinglePropertyContextMenu::handleContextMenuClick(QAction* _action) {
	object_tree_->onPropertyContextMenuClick(_action);
}

void SinglePropertyContextMenu::onUnaryActionClick(QAction* _action) {
	object_tree_->onUnaryActionClick(_action);
}

void SinglePropertyContextMenu::onPythonSciptAction(QAction* _action) {
	SmartPtr<Named_interface> ni = Root::instance()->interface(python_script_manager + "/" + String_Op::qstring2string(_action->text()));
	Python_script* script = dynamic_cast<Python_script*> (ni.raw_ptr());
	appli_assert( script );
//  script->filename();
	script->execute();
}

/**
 *
 */

SingleObjectContextMenu::SingleObjectContextMenu(ObjectTree* _object_tree, QWidget* _parent) :
	ObjectTreeContextMenu(_object_tree, _parent) {
	action_.push_back(addAction("Delete"));

	action_.push_back(addSeparator());
	QMenu* trend_action_menu = addMenu("Create Trend");
	nested_menu_.push_back(trend_action_menu);
	QObject::connect(trend_action_menu, SIGNAL(triggered(QAction*)), this, SLOT(onTrendActionClick(QAction*)));

	// Create_trend trend_action();
	std::vector<std::string> trend_functions = Create_trend().get_trend_functions();

	std::vector<std::string>::iterator begin = trend_functions.begin();
	for (; begin != trend_functions.end(); ++begin) {
		QString menuItemName(begin->c_str());
		action_.push_back(trend_action_menu->addAction(menuItemName));
	}
}

SingleObjectContextMenu::~SingleObjectContextMenu() {
}

void SingleObjectContextMenu::handleContextMenuClick(QAction* _action) {
	object_tree_->onObjectContextMenuClick(_action);
}

void SingleObjectContextMenu::onTrendActionClick(QAction* _action) {
	object_tree_->onTrendActionClick(_action);
}
