#ifndef OBJECT_TREE_CONTEXT_MENU_H_
#define OBJECT_TREE_CONTEXT_MENU_H_

#include <GsTLAppli/gui/common.h>
#include <QMenu>
#include <GsTLAppli/gui/appli/oinv_project_view.h>

class ObjectTree;

class GUI_DECL BaseTreeItemMenu: public QMenu
{
Q_OBJECT

public:
	BaseTreeItemMenu(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~BaseTreeItemMenu();

public:
	void setMenuItemEnable(QString _action_name, bool _enable);
	void setObjectTree(ObjectTree* _object_tree);

protected:
	ObjectTree* object_tree_;
	std::vector<QAction*> action_;

public slots:
	void onContextMenuClick(QAction* _action);

protected:
	virtual void handleContextMenuClick(QAction* _action);
};

/**
 *
 */
class GUI_DECL ObjectTreeItemMenu: public BaseTreeItemMenu
{
Q_OBJECT

public:
	ObjectTreeItemMenu(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~ObjectTreeItemMenu();

protected:
	void handleContextMenuClick(QAction* _action);

public slots:
	void onTrendActionClick(QAction* _action);

protected:
	std::vector<QMenu*> nested_menu_;
};

/**
 *
 */
class GUI_DECL PropertyTreeItemMenu_Single: public BaseTreeItemMenu
{
Q_OBJECT

public:
	PropertyTreeItemMenu_Single(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~PropertyTreeItemMenu_Single();

protected:
	void handleContextMenuClick(QAction* _action);

public slots:
	void onUnaryActionClick(QAction* _action);
	void onPythonScriptAction(QAction* _action);

protected:
	std::vector<QMenu*> nested_menu_;
};

/**
 *
 */
class GUI_DECL PropertyTreeItemMenu_Multiple: public BaseTreeItemMenu
{
Q_OBJECT

public:
	PropertyTreeItemMenu_Multiple(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~PropertyTreeItemMenu_Multiple();

protected:
	void handleContextMenuClick(QAction* _action);

public slots:
	void onPythonScriptAction(QAction* _action);

protected:
	std::vector<QMenu*> nested_menu_;
};

/**
 *
 */
class GUI_DECL PropertyGroupTreeItemMenu: public BaseTreeItemMenu
{
Q_OBJECT

public:
	PropertyGroupTreeItemMenu(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~PropertyGroupTreeItemMenu();

protected:
	void handleContextMenuClick(QAction* _action);

public slots:
	void onPythonScriptAction(QAction* _action);
	void onUnaryGroupActionClick(QAction* _action);

protected:
	std::vector<QMenu*> nested_menu_;
};

#endif /* OBJECT_TREE_CONTEXT_MENU_H_ */
