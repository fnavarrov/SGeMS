/**********************************************************************
 ** Author: Nicolas Remy
 ** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
 **   University
 ** All rights reserved.
 **
 ** This file is part of the "gui" module of the Geostatistical Earth
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

#ifndef __GSTLAPPLI_GSTL_QLISTVIEWITEM_H__ 
#define __GSTLAPPLI_GSTL_QLISTVIEWITEM_H__ 

#include <GsTLAppli/gui/common.h>
#include <QTreeWidget>

class BaseTreeItemMenu;
class ObjectTree;

class GUI_DECL BaseTreeItem: public QTreeWidgetItem
{
public:
	BaseTreeItem(QTreeWidget* parent, QString label, bool showIcon = true);
	BaseTreeItem(QTreeWidgetItem* parent, QString label, bool showIcon = true);
	virtual ~BaseTreeItem();

public:
	void setVisible(bool _visible);
	bool visible() const;
	virtual void setSelected(bool _select);

public:
	virtual bool selectionEnabled() = 0;
	virtual bool multipleSelectionEnabled() = 0;
	virtual bool selectAllChildrenEnabled() = 0;
	virtual QList<BaseTreeItem*> children() = 0;
	virtual bool isCompatibleItem(BaseTreeItem* _item) = 0;
	virtual BaseTreeItemMenu* getMenu(ObjectTree* _object_tree, bool _multiple) = 0;

protected:
	bool visible_;
	bool showIcon_;
};

/**
 *
 */
class GUI_DECL HeaderTreeItem: public BaseTreeItem
{
public:
	HeaderTreeItem(QTreeWidget* parent, QString label);
	HeaderTreeItem(QTreeWidgetItem* parent, QString label);
	virtual ~HeaderTreeItem();

public:
	virtual bool selectionEnabled();
	virtual bool multipleSelectionEnabled();
	virtual bool selectAllChildrenEnabled();
	virtual QList<BaseTreeItem*> children();
	virtual bool isCompatibleItem(BaseTreeItem* _item);
	virtual BaseTreeItemMenu* getMenu(ObjectTree* _object_tree, bool _multiple);
};

/**
 *
 */
class GUI_DECL ObjectTreeItem: public BaseTreeItem
{
public:
	ObjectTreeItem(QTreeWidgetItem* parent, QString label);
	virtual ~ObjectTreeItem();

public:
	virtual bool selectionEnabled();
	virtual bool multipleSelectionEnabled();
	virtual bool selectAllChildrenEnabled();
	virtual QList<BaseTreeItem*> children();
	virtual bool isCompatibleItem(BaseTreeItem* _item);
	virtual BaseTreeItemMenu* getMenu(ObjectTree* _object_tree, bool _multiple);
};

/**
 *
 */
class GUI_DECL PropertyTreeItem: public BaseTreeItem
{
public:
	PropertyTreeItem(QTreeWidgetItem* parent, QString label);
	virtual ~PropertyTreeItem();

public:
	virtual bool selectionEnabled();
	virtual bool multipleSelectionEnabled();
	virtual bool selectAllChildrenEnabled();
	virtual QList<BaseTreeItem*> children();
	virtual bool isCompatibleItem(BaseTreeItem* _item);
	virtual BaseTreeItemMenu* getMenu(ObjectTree* _object_tree, bool _multiple);
};

/**
 *
 */
class GUI_DECL SimulationSetTreeItem: public BaseTreeItem
{
public:
	SimulationSetTreeItem(QTreeWidgetItem* parent, QString label);
	virtual ~SimulationSetTreeItem();

public:
	virtual bool selectionEnabled();
	virtual bool multipleSelectionEnabled();
	virtual bool selectAllChildrenEnabled();
	virtual QList<BaseTreeItem*> children();
	virtual bool isCompatibleItem(BaseTreeItem* _item);
	virtual BaseTreeItemMenu* getMenu(ObjectTree* _object_tree, bool _multiple);
};

/**
 *
 */
class GUI_DECL RegionTreeItem: public BaseTreeItem
{
public:
	RegionTreeItem(QTreeWidget* parent, QString label);
	RegionTreeItem(QTreeWidgetItem* parent, QString label);
	virtual ~RegionTreeItem();

public:
	virtual bool selectionEnabled();
	virtual bool multipleSelectionEnabled();
	virtual bool selectAllChildrenEnabled();
	virtual QList<BaseTreeItem*> children();
	virtual bool isCompatibleItem(BaseTreeItem* _item);
	virtual BaseTreeItemMenu* getMenu(ObjectTree* _object_tree, bool _multiple);
};

//class GUI_DECL MultiSel_QListViewItem: public QTreeWidgetItem
//{
//
//public:
//	MultiSel_QListViewItem(QTreeWidget* parent);
//	MultiSel_QListViewItem(QTreeWidget* parent, QString label);
//	MultiSel_QListViewItem(QTreeWidgetItem* parent);
//	MultiSel_QListViewItem(QTreeWidgetItem* parent, QString label);
//	virtual ~MultiSel_QListViewItem()
//	{
//	}
//
//	bool is_visible() const
//	{
//		return is_visible_;
//	}
//	void switch_state();
//
//	virtual void setSelected(bool ok);
//
//	/*
//	 virtual int rtti() const { return MultiSel_QListViewItem::RTTI; }
//	 static const int RTTI=211175;
//	 */
//
//protected:
//	bool is_visible_;
//};

//class GUI_DECL SingleSel_QListViewItem: public QTreeWidgetItem
//{
//
//public:
//	SingleSel_QListViewItem(QTreeWidget* parent);
//	SingleSel_QListViewItem(QTreeWidget* parent, QString label);
//	SingleSel_QListViewItem(QTreeWidgetItem* parent);
//	SingleSel_QListViewItem(QTreeWidgetItem* parent, QString label);
//	virtual ~SingleSel_QListViewItem()
//	{
//	}
//
//	bool is_visible() const
//	{
//		return is_visible_;
//	}
//	virtual void switch_state();
//	virtual void setSelected(bool ok);
//
//	/*
//	 virtual int rtti() const { return SingleSel_QListViewItem::RTTI; }
//	 static const int RTTI=211176;
//	 */
//
//protected:
//	bool is_visible_;
//
//	virtual void set_visible();
//	virtual void set_unvisible();
//};

#endif 

