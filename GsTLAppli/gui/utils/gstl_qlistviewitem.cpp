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

#include <GsTLAppli/gui/utils/gstl_qlistviewitem.h>

#include <QPixmap>
#include <QListWidget>
#include <QIcon>

#include <GsTLAppli/gui/appli/object_tree_context_menu.h>

//=====================================
//  Two inlined pixmaps...
static const char* const image1_data[] =
	{ "24 15 3 1", "# c None", ". c #000000", "a c #ffffff", "..................######", "..................######", "..aaaaaaaaaaaaaa..######",
			"..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######",
			"..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######", "..aaaaaaaaaaaaaa..######",
			"..................######", "..................######" };

static const char* const image0_data[] =
	{ "24 15 156 2", ".# c None", "Qt c #000000", "#c c #29483f", "#n c #2b2f31", ".X c #2c332d", ".V c #2c3f3b", ".8 c #2c4345", "#a c #2d322b",
			"## c #2d3234", "#o c #2d3930", ".U c #2e3834", "#k c #2e5a56", "#D c #2f615b", "#z c #30685a", "#q c #315447", "#l c #326053", "#p c #335445",
			".Y c #343f35", ".9 c #385a53", ".Z c #394339", "#m c #3a504b", "#b c #3a5547", ".W c #3d4b43", "#C c #446352", "#A c #496a5c", ".I c #4a4135",
			"#O c #4a6f61", ".5 c #4c4336", "#Q c #4c6e63", "#R c #4d7062", "#B c #4e5949", ".0 c #4f4a3b", "#E c #50655d", "#P c #506e60", ".H c #51423a",
			".T c #534f45", "#N c #56756c", ".J c #574b3c", ".S c #5e4a3a", ".4 c #655140", ".K c #655341", "#y c #668883", ".G c #6b5749", "#d c #6e6c5d",
			"#g c #725e49", ".6 c #797d72", "#4 c #88887e", "#3 c #8b8e83", ".7 c #8ea4a0", ".L c #8f735d", ".R c #937763", ".F c #937867", "#h c #968777",
			"#r c #99958d", "#5 c #9a988f", "#2 c #9ba199", "#S c #9da39d", ".1 c #9e7b60", "#e c #a17e68", "#t c #a8826c", ".M c #ae8d76", "#H c #b08e7b",
			"#s c #b29d8d", "#u c #be967c", "#i c #c1b9af", "#G c #c2aa9d", ".N c #c39986", "#V c #c3a191", "#U c #c3aca1", "#1 c #c3c0b8", ".z c #c4a08a",
			".y c #c4a08b", "#F c #c4b9b1", "#M c #c4cac4", ".Q c #c5a18f", "#j c #c5ccca", ".b c #c69e8b", ".w c #c6a593", ".v c #c6aa98", ".x c #c7a492",
			".i c #c7a58f", "#v c #c7a897", ".j c #c8a592", "#. c #c8dad8", ".2 c #c99981", ".c c #c9a08d", ".k c #c9a897", "#8 c #caac9d", ".O c #cb9d88",
			".u c #cbb3a3", "#6 c #cbb8af", ".A c #cca894", ".h c #ccaa9b", "#7 c #cdb4a8", ".d c #cea594", ".a c #cea897", "#T c #cfc0ba", "#f c #d0a185",
			".3 c #d0a289", ".o c #d0a495", ".g c #d1b0a2", ".l c #d1b4a3", ".P c #d2aa97", ".t c #d2bcb1", ".E c #d6aa9b", ".e c #d6b3a3", "#9 c #d8b9ab",
			"#w c #d9cec6", ".f c #dab8a7", "#I c #dbbdb2", ".p c #deb3a3", "#Z c #dfc4be", ".C c #e0b8a7", ".s c #e0c9be", ".B c #e1c3b4", "#K c #e1c6be",
			"#0 c #e1cdc6", "#x c #e1e0e2", ".q c #e2b4a6", ".D c #e3b9a8", "ah c #e4c3b8", "ag c #e4c5b9", ".m c #e4c8b9", "#L c #e4d7d3", "#J c #e6c1b7",
			"ai c #e7c0b4", "af c #e7ccbf", ".r c #e9c5b9", "ad c #ead4c9", "aj c #ebc7bc", "ae c #ecd4ca", "#Y c #eed3cd", ".n c #eed8cc", "av c #f0d4cd",
			"au c #f0d5ce", "at c #f1dad5", "aw c #f3d5cf", "#X c #f4dad4", "ax c #f4dbd5", "ak c #f5d4cb", "ac c #f5dfd8", "as c #f5e1dc", "ay c #f6e3db",
			"ab c #f7e6df", "aa c #fae9e3", "az c #faece4", "al c #fbe2db", "ar c #fbeae3", "#W c #fde7e0", "a# c #fdede9", "an c #fdf9f4", "aq c #feefec",
			"a. c #fef2ee", "ap c #fef4f0", "ao c #fef5f0", "am c #fefdf8", "QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt.#.#.#.#.#.#",
			"QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt.#.#.#.#.#.#", "QtQt.a.b.c.d.e.f.g.h.i.j.k.l.m.nQtQt.#.#.#.#.#.#",
			"QtQt.o.p.q.r.s.t.u.v.w.x.y.z.A.BQtQt.#.#.#.#.#.#", "QtQt.C.D.E.F.G.H.I.J.K.L.M.N.O.PQtQt.#.#.#.#.#.#",
			"QtQt.Q.R.S.T.U.V.W.X.Y.Z.0.1.2.3QtQt.#.#.#.#.#.#", "QtQt.4.5.6.7.8.9#.###a#b#c#d#e#fQtQt.#.#.#.#.#.#",
			"QtQt#g#h#i#j#k#l#m#n#o#p#q#r#s#tQtQt.#.#.#.#.#.#", "QtQt#u#v#w#x#y#z#A#B#C#D#E#F#G#HQtQt.#.#.#.#.#.#",
			"QtQt#I#J#K#L#M#N#O#P#Q#R#S#T#U#VQtQt.#.#.#.#.#.#", "QtQt#W#X#Y#Z#0#1#2#3#4#5#6#7#8#9QtQt.#.#.#.#.#.#",
			"QtQta.a#aaabacadaeafagahaiajakalQtQt.#.#.#.#.#.#", "QtQtamanaoapaqarasatauavawaxayazQtQt.#.#.#.#.#.#",
			"QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt.#.#.#.#.#.#", "QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt.#.#.#.#.#.#" };

/**
 *
 */
BaseTreeItem::BaseTreeItem(QTreeWidget* parent, QString label, bool showIcon) :
	QTreeWidgetItem(parent), visible_(false), showIcon_(showIcon)
{
	setText(0, label);
	if (showIcon_)
	{
		QPixmap pix_not_visible((const char**) image1_data);
		setIcon(0, QIcon(pix_not_visible));
	}
}

BaseTreeItem::BaseTreeItem(QTreeWidgetItem* parent, QString label, bool showIcon) :
	QTreeWidgetItem(parent), visible_(false), showIcon_(showIcon)
{
	setText(0, label);
	if (showIcon_)
	{
		QPixmap pix_not_visible((const char**) image1_data);
		setIcon(0, QIcon(pix_not_visible));
	}
}

BaseTreeItem::~BaseTreeItem()
{
}

void BaseTreeItem::setVisible(bool _visible)
{
	if (showIcon_)
	{
		if (_visible != visible_)
		{
			visible_ = _visible;
			if (visible_)
			{
				QPixmap pix_visible((const char**) image0_data);
				setIcon(0, QIcon(pix_visible));
			} else
			{
				QPixmap pix_not_visible((const char**) image1_data);
				setIcon(0, QIcon(pix_not_visible));
			}
		}
	}
}

bool BaseTreeItem::visible() const
{
	return visible_;
}

void BaseTreeItem::setSelected(bool _select)
{
	if (_select == visible_)
	{
		return;
	}

	if (visible_)
	{
		setVisible(false);
	} else
	{
		setVisible(true);
		// TODO
		// Look if one of the siblings is visible and turn it off before turning on the current item
		//		QTreeWidgetItem* up = parent();
		//		for (int i = 0; i < up->childCount(); ++i)
		//		{
		//			SingleSel_QListViewItem* ss_child = (SingleSel_QListViewItem*) up->child(i);
		//			if (ss_child->is_visible())
		//			{
		//				ss_child->set_unvisible();
		//				break;
		//			}
		//		}
	}
}

/**
 *
 */
HeaderTreeItem::HeaderTreeItem(QTreeWidget* parent, QString label) :
	BaseTreeItem(parent, label, false)
{
}

HeaderTreeItem::HeaderTreeItem(QTreeWidgetItem* parent, QString label) :
	BaseTreeItem(parent, label, false)
{
}

HeaderTreeItem::~HeaderTreeItem()
{
}

bool HeaderTreeItem::selectionEnabled()
{
	return false;
}

bool HeaderTreeItem::multipleSelectionEnabled()
{
	return false;
}

bool HeaderTreeItem::selectAllChildrenEnabled()
{
	return false;
}

QList<BaseTreeItem*> HeaderTreeItem::children()
{
	QList<BaseTreeItem*> allChildren;
	for (int i = 0; i < childCount(); ++i)
	{
		allChildren.append(dynamic_cast<BaseTreeItem*> (child(i))->children());
	}
	return allChildren;
}

bool HeaderTreeItem::isCompatibleItem(BaseTreeItem* _item)
{
	return false;
}

BaseTreeItemMenu* HeaderTreeItem::getMenu(ObjectTree* _object_tree, bool _multiple)
{
	return 0;
}

/**
 *
 */
ObjectTreeItem::ObjectTreeItem(QTreeWidgetItem* parent, QString label) :
	BaseTreeItem(parent, label)
{
}

ObjectTreeItem::~ObjectTreeItem()
{
}

bool ObjectTreeItem::selectionEnabled()
{
	return true;
}

bool ObjectTreeItem::multipleSelectionEnabled()
{
	return false;
}

bool ObjectTreeItem::selectAllChildrenEnabled()
{
	return false;
}

QList<BaseTreeItem*> ObjectTreeItem::children()
{
	QList<BaseTreeItem*> allChildren;
	for (int i = 0; i < childCount(); ++i)
	{
		allChildren.append(dynamic_cast<BaseTreeItem*> (child(i))->children());
	}
	return allChildren;
}

bool ObjectTreeItem::isCompatibleItem(BaseTreeItem* _item)
{
	return false;
}

BaseTreeItemMenu* ObjectTreeItem::getMenu(ObjectTree* _object_tree, bool _multiple)
{
	static BaseTreeItemMenu* _instance = 0;

	if (_instance == 0)
	{
		_instance = new ObjectTreeItemMenu(_object_tree, _object_tree);
	}

	_instance->setObjectTree(_object_tree);

	return _multiple ? 0 : _instance;
}

/**
 *
 */
PropertyTreeItem::PropertyTreeItem(QTreeWidgetItem* parent, QString label) :
	BaseTreeItem(parent, label)
{
}

PropertyTreeItem::~PropertyTreeItem()
{
}

bool PropertyTreeItem::selectionEnabled()
{
	return true;
}

bool PropertyTreeItem::multipleSelectionEnabled()
{
	return true;
}

bool PropertyTreeItem::selectAllChildrenEnabled()
{
	return false;
}

QList<BaseTreeItem*> PropertyTreeItem::children()
{
	QList<BaseTreeItem*> allChildren;
	allChildren.append(this);
	return allChildren;
}

bool PropertyTreeItem::isCompatibleItem(BaseTreeItem* _item)
{
	if (dynamic_cast<PropertyTreeItem*> (_item))
	{
		return true;
	}
	return false;
}

BaseTreeItemMenu* PropertyTreeItem::getMenu(ObjectTree* _object_tree, bool _multiple)
{
	static BaseTreeItemMenu* _singleInstance = 0;
	static BaseTreeItemMenu* _multipleInstance = 0;

	if (_singleInstance == 0)
	{
		_singleInstance = new PropertyTreeItemMenu_Single(_object_tree, _object_tree);
	}

	if (_multipleInstance == 0)
	{
		_multipleInstance = new PropertyTreeItemMenu_Multiple(_object_tree, _object_tree);
	}

	_singleInstance->setObjectTree(_object_tree);
	_multipleInstance->setObjectTree(_object_tree);

	return _multiple ? _multipleInstance : _singleInstance;
}

/**
 *
 */
SimulationSetTreeItem::SimulationSetTreeItem(QTreeWidgetItem* parent, QString label) :
	BaseTreeItem(parent, label)
{
}

SimulationSetTreeItem::~SimulationSetTreeItem()
{
}

bool SimulationSetTreeItem::selectionEnabled()
{
	return true;
}

bool SimulationSetTreeItem::multipleSelectionEnabled()
{
	return false;
}

bool SimulationSetTreeItem::selectAllChildrenEnabled()
{
	return true;
}

QList<BaseTreeItem*> SimulationSetTreeItem::children()
{
	QList<BaseTreeItem*> allChildren;
	for (int i = 0; i < childCount(); ++i)
	{
		allChildren.append(this);
		allChildren.append(dynamic_cast<BaseTreeItem*> (child(i))->children());
	}
	return allChildren;
}

bool SimulationSetTreeItem::isCompatibleItem(BaseTreeItem* _item)
{
	return false;
}

BaseTreeItemMenu* SimulationSetTreeItem::getMenu(ObjectTree* _object_tree, bool _multiple)
{
	static BaseTreeItemMenu* _singleInstance = 0;

	if (_singleInstance == 0)
	{
		_singleInstance = new SimulationSetTreeItemMenu(_object_tree, _object_tree);
	}

	_singleInstance->setObjectTree(_object_tree);

	return _multiple ? 0 : _singleInstance;
}

/**
 *
 */

RegionTreeItem::RegionTreeItem(QTreeWidget* parent, QString label) :
	BaseTreeItem(parent, label)
{
}

RegionTreeItem::RegionTreeItem(QTreeWidgetItem* parent, QString label) :
	BaseTreeItem(parent, label)
{
}

RegionTreeItem::~RegionTreeItem()
{
}

bool RegionTreeItem::selectionEnabled()
{
	return true;
}

bool RegionTreeItem::multipleSelectionEnabled()
{
	return true;
}

bool RegionTreeItem::selectAllChildrenEnabled()
{
	return false;
}

QList<BaseTreeItem*> RegionTreeItem::children()
{
	QList<BaseTreeItem*> allChildren;
	allChildren.append(this);
	return allChildren;
}

bool RegionTreeItem::isCompatibleItem(BaseTreeItem* _item)
{
	if (dynamic_cast<RegionTreeItem*> (_item))
	{
		return true;
	}
	return false;
}

BaseTreeItemMenu* RegionTreeItem::getMenu(ObjectTree* _object_tree, bool _multiple)
{
	return 0;
}

//=====================================================


//MultiSel_QListViewItem::MultiSel_QListViewItem(QTreeWidget* parent) :
//	QTreeWidgetItem(parent)
//{
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//MultiSel_QListViewItem::MultiSel_QListViewItem(QTreeWidget* parent, QString label) :
//	QTreeWidgetItem(parent)
//{
//	setText(0, label);
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//MultiSel_QListViewItem::MultiSel_QListViewItem(QTreeWidgetItem* parent) :
//	QTreeWidgetItem(parent)
//{
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//MultiSel_QListViewItem::MultiSel_QListViewItem(QTreeWidgetItem* parent, QString label) :
//	QTreeWidgetItem(parent)
//{
//	setText(0, label);
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//void MultiSel_QListViewItem::switch_state()
//{
//	if (is_visible_)
//	{
//		is_visible_ = false;
//		QPixmap pix_not_visible((const char**) image1_data);
//		setIcon(0, QIcon(pix_not_visible));
//	} else
//	{
//		is_visible_ = true;
//		QPixmap pix_visible((const char**) image0_data);
//		setIcon(0, QIcon(pix_visible));
//	}
//
//}
//
//void MultiSel_QListViewItem::setSelected(bool ok)
//{
//	if (ok && is_visible_)
//		return;
//	if (!ok && !is_visible_)
//		return;
//
//	switch_state();
//}

//--------------------------------

//SingleSel_QListViewItem::SingleSel_QListViewItem(QTreeWidget* parent) :
//	QTreeWidgetItem(parent)
//{
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//SingleSel_QListViewItem::SingleSel_QListViewItem(QTreeWidget* parent, QString label) :
//	QTreeWidgetItem(parent)
//{
//	setText(0, label);
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//SingleSel_QListViewItem::SingleSel_QListViewItem(QTreeWidgetItem* parent) :
//	QTreeWidgetItem(parent)
//{
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//SingleSel_QListViewItem::SingleSel_QListViewItem(QTreeWidgetItem* parent, QString label) :
//	QTreeWidgetItem(parent)
//{
//
//	setText(0, label);
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//	is_visible_ = false;
//}
//
//void SingleSel_QListViewItem::set_visible()
//{
//	is_visible_ = true;
//	QPixmap pix_visible((const char**) image0_data);
//	setIcon(0, QIcon(pix_visible));
//}
//
//void SingleSel_QListViewItem::set_unvisible()
//{
//	is_visible_ = false;
//	QPixmap pix_not_visible((const char**) image1_data);
//	setIcon(0, QIcon(pix_not_visible));
//}
//
//void SingleSel_QListViewItem::switch_state()
//{
//	if (is_visible_)
//	{
//		set_unvisible();
//	} else
//	{
//		// Look if one of the siblings is visible and turn it off
//		// before turning on the current item
//		QTreeWidgetItem* up = parent();
//		for (int i = 0; i < up->childCount(); ++i)
//		{
//			SingleSel_QListViewItem* ss_child = (SingleSel_QListViewItem*) up->child(i);
//			if (ss_child->is_visible())
//			{
//				ss_child->set_unvisible();
//				break;
//			}
//		}
//		set_visible();
//	}
//
//}
//
//void SingleSel_QListViewItem::setSelected(bool ok)
//{
//	if (ok && is_visible_)
//		return;
//	if (!ok && !is_visible_)
//		return;
//
//	switch_state();
//}

