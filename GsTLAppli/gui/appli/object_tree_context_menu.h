#ifndef OBJECT_TREE_CONTEXT_MENU_H_
#define OBJECT_TREE_CONTEXT_MENU_H_

#include <GsTLAppli/gui/common.h>
#include <QMenu>
#include <GsTLAppli/gui/appli/oinv_project_view.h>

class ObjectTree;

class GUI_DECL ObjectTreeContextMenu: public QMenu {
Q_OBJECT

public:
	ObjectTreeContextMenu(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~ObjectTreeContextMenu();

public:
	void setMenuItemEnable(QString _action_name, bool _enable);

protected:
	ObjectTree* object_tree_;
	std::vector<QAction*> action_;

signals:
	void action(QString _action_name, QString _params);

public slots:
	void onContextMenuClick(QAction* _action);

protected:
	virtual void handleContextMenuClick(QAction* _action) = 0;
};

/**
 *
 */
class GUI_DECL MultiPropertyContextMenu: public ObjectTreeContextMenu {
Q_OBJECT

public:
	MultiPropertyContextMenu(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~MultiPropertyContextMenu();

protected:
	void handleContextMenuClick(QAction* _action);
};

/**
 *
 */
class GUI_DECL SinglePropertyContextMenu: public ObjectTreeContextMenu {
Q_OBJECT

public:
	SinglePropertyContextMenu(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~SinglePropertyContextMenu();

protected:
	void handleContextMenuClick(QAction* _action);

public slots:
	void onUnaryActionClick(QAction* _action);

protected:
	std::vector<QMenu*> nested_menu_;
};

/**
 *
 */
class GUI_DECL SingleObjectContextMenu: public ObjectTreeContextMenu {
Q_OBJECT

public:
	SingleObjectContextMenu(ObjectTree* _object_tree, QWidget* _parent);
	virtual ~SingleObjectContextMenu();

public slots:
	void onTrendActionClick(QAction* _action);

protected:
	void handleContextMenuClick(QAction* _action);

protected:
	std::vector<QMenu*> nested_menu_;
};

#endif /* OBJECT_TREE_CONTEXT_MENU_H_ */
