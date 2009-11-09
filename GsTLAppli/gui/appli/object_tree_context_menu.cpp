#include <GsTLAppli/gui/appli/object_tree_context_menu.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/actions/unary_action.h>

ObjectTreeContextMenu::ObjectTreeContextMenu(ObjectTree* _object_tree, QWidget* _parent) :
	object_tree_(_object_tree), QMenu(_parent) {
	QObject::connect(this, SIGNAL(triggered(QAction*)), this, SLOT(onContextMenuClick(QAction*)));
}

ObjectTreeContextMenu::~ObjectTreeContextMenu() {
	for (std::vector<QAction*>::iterator iter = action_.begin(); iter != action_.end(); ++iter) {
		delete (*iter);
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

/**
 *
 */

SingleObjectContextMenu::SingleObjectContextMenu(ObjectTree* _object_tree, QWidget* _parent) :
	ObjectTreeContextMenu(_object_tree, _parent) {
	action_.push_back(addAction("Delete"));
}

SingleObjectContextMenu::~SingleObjectContextMenu() {
}

void SingleObjectContextMenu::handleContextMenuClick(QAction* _action) {
	object_tree_->onObjectContextMenuClick(_action);
}
