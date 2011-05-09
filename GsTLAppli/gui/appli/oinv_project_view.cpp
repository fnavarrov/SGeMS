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

#include <GsTLAppli/gui/appli/oinv_project_view.h>
#include <GsTLAppli/gui/oinv_description/gstl_SoNode.h>
#include <GsTLAppli/gui/oinv_description/oinv_cgrid.h>
#include <GsTLAppli/gui/appli/display_pref_panel.h>
#include <GsTLAppli/gui/appli/general_display_pref_panel.h>
#include <GsTLAppli/gui/appli/SoQtGsTLViewer.h>
#include <GsTLAppli/gui/appli/snapshot_dialog.h>
#include <GsTLAppli/gui/appli/qt_grid_summary.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/cartesian_grid.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/actions/unary_action.h>
#include <GsTLAppli/gui/utils/gstl_qlistviewitem.h>
#include <GsTLAppli/extra/qtplugins/selectors.h>
#include <GsTLAppli/actions/python_script.h>
#include <GsTLAppli/actions/python_group_script.h>

#include <Inventor/nodes/SoSelection.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoCamera.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/SoOffscreenRenderer.h>
#include <Inventor/SbViewportRegion.h>
#include <Inventor/actions/SoWriteAction.h>

//TL modified
#include <Inventor/Qt/SoQtRenderArea.h>
#include <Inventor/events/SoKeyboardEvent.h>
#include <GsTLAppli/grid/grid_model/reduced_grid.h>
#include <GsTLAppli/gui/appli/object_tree_context_menu.h>

#include <QStringList>
#include <QListWidget>
#include <QVBoxLayout>
#include <qstring.h>
#include <qcombobox.h>
#include <qlayout.h>

#include <qtabwidget.h>
#include <QScrollArea>
#include <qsplitter.h>
#include <qfiledialog.h>
#include <QMimeData>
#include <qapplication.h>
#include <qmessagebox.h>
#include <QUrl>
#include <QDragLeaveEvent>
#include <QFrame>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QQueue>

#include <vector>
#include <list>
#include <string>
#include <utility>
#include <algorithm>
#include <fstream>

using namespace String_Op;

Named_interface* Create_oinv_view(std::string&)
{
	return new Oinv_view();
}

//TL modified
SbBool eventHandler(void * data, SoEvent * e)
{
	return true;
}

ObjectTree::ObjectTree(QWidget* parent) :
	QTreeWidget(parent)
{
	QObject::connect(this, SIGNAL(itemClicked(QTreeWidgetItem *,int)), this, SLOT(slotItemSelected(QTreeWidgetItem*,int)));
	rename_in_progress_ = false;
	mouse_event_ = 0;
}

void ObjectTree::mousePressEvent(QMouseEvent* event)
{
	if (rename_in_progress_)
	{
		return;
	}

	if (mouse_event_)
	{
		delete mouse_event_;
		mouse_event_ = 0;
	}

	mouse_event_ = new QMouseEvent(*event);

	QTreeWidget::mousePressEvent(event);
}

void ObjectTree::slotItemSelected(QTreeWidgetItem* _item, int _col)
{

	BaseTreeItem* baseItem = dynamic_cast<BaseTreeItem*> (_item);

	if ((rename_in_progress_) || (baseItem == 0))
	{
		return;
	}

	if (!baseItem->selectionEnabled())
	{
		selected_items_.clear();
		switch_selected_items();
		return;
	}

	// see if we need to remove clicked item from the menu list
	if (mouse_event_->button() != Qt::RightButton)
	{
		if ((mouse_event_->modifiers() & Qt::ControlModifier) && selected_items_.contains(baseItem))
		{
			selected_items_.remove(selected_items_.indexOf(baseItem));
		}

		// handle control+click combination
		else if ((mouse_event_->modifiers() & Qt::ControlModifier) && baseItem->multipleSelectionEnabled())
		{
			// clear current selection if incompatible item was clicked
			if ((selected_items_.size() != 0) && (!baseItem->isCompatibleItem(selected_items_.at(0))))
			{
				selected_items_.clear();
			}

			// also need to check that parents of items are same
			for (int i = 0; i < selected_items_.size(); ++i)
			{
				if (getGridName(baseItem) != getGridName(selected_items_.at(i)))
				{
					selected_items_.clear();
					break;
				}
			}

			selected_items_.push_back(baseItem);
		}

		// otherwise, only a single item can be selected one
		else
		{
			selected_items_.clear();
			selected_items_.push_back(baseItem);
			emit swap_display(baseItem);
		}
	}

	// handle right click
	else
	{
		if ((selected_items_.size() != 0) && (!baseItem->isCompatibleItem(selected_items_.at(0))))
		{
			selected_items_.clear();
		}

		if (selected_items_.size() == 0)
		{
			selected_items_.push_back(baseItem);
		}

		switch_selected_items();

		bool multiple = selected_items_.size() > 1;
		BaseTreeItemMenu* menu = baseItem->getMenu(this, multiple);

		if (menu)
		{
			if (dynamic_cast<PropertyTreeItemMenu_Single*> (menu))
			{
				// enable/disable appropriate swap actions
				std::string grid_name = getGridName(selected_items_.at(0)).toStdString();
				std::string prop_name = selected_items_.at(0)->text(0).toStdString();

				// get reference to the grid, grid will always exist as this is executed from the object tree
				SmartPtr<Named_interface> grid_ni = Root::instance()->interface(gridModels_manager + "/" + grid_name);
				Geostat_grid* grid = dynamic_cast<Geostat_grid*> (grid_ni.raw_ptr());
				GsTLGridProperty* property = grid->property(prop_name);

				menu->setMenuItemEnable("Swap to RAM", !property->is_in_memory());
				menu->setMenuItemEnable("Swap to disk", property->is_in_memory());
			}

			menu->exec(mouse_event_->globalPos());
		}
	}

	switch_selected_items();
}

QString ObjectTree::getGridName(QTreeWidgetItem* _item)
{
	QTreeWidgetItem* parent = getGridItem(_item);
	if (parent)
	{
		return parent->text(0);
	}
	return "";
}

BaseTreeItem* ObjectTree::getGridItem(QTreeWidgetItem* _item)
{
	QTreeWidgetItem* parent = _item;
	QTreeWidgetItem* root = topLevelItem(0);

	if ((parent == 0) || (parent == root))
	{
		return 0;
	}

	while (parent->parent() != root)
	{
		parent = parent->parent();
	}

	return dynamic_cast<BaseTreeItem*> (parent);
}

// assumes that only properties were selected
void ObjectTree::onPropertyContextMenuClick(QAction* _action)
{
	if (selected_items_.empty())
	{
		return;
	}

	// all selected items SHOULD have the same parent grid
	QString grid_name = getGridName(selected_items_.at(0));

	QString action_name = _action->text();

	// handle Rename
	if ("Rename" == action_name)
	{
		// must have only one item selected
		if (selected_items_.size() != 1)
		{
			return;
		}
		QTreeWidgetItem* item = selected_items_.at(0);
		old_name_ = item->text(0);
		item->setFlags(item->flags() | Qt::ItemIsEditable);
		openPersistentEditor(item, 0);
		rename_in_progress_ = true;
	}

	// handle Delete
	else if ("Delete" == action_name)
	{
		for (int i = 0; i < selected_items_.size(); ++i)
		{
			QString prop_name = selected_items_.at(i)->text(0);
			if (!delete_property(grid_name, prop_name))
			{
				QMessageBox::critical(this, "Cannot perform deletion", "Unable to delete property", QMessageBox::Ok, Qt::NoButton);
			} else
			{
				this->removeItemWidget(selected_items_.at(i), 0);
				emit delete_property_finished(grid_name, prop_name);
			}
			emit project_modified();
		}
		selected_items_.clear();
	}

	// handle ShowHistogram
	else if ("Histogram" == action_name)
	{
		// must have only one item selected
		if (selected_items_.size() != 1)
		{
			return;
		}
		QTreeWidgetItem* item = selected_items_.at(0);
		QString params = grid_name + QString(Actions::separator.c_str()) + item->text(0);
		emit action("ShowHistogram", params);
		selected_items_.clear();
	}

	// handle Swap To Disk
	else if ("Swap to disk" == action_name)
	{
		// must have only one item selected
		if (selected_items_.size() != 1)
		{
			return;
		}
		QTreeWidgetItem* item = selected_items_.at(0);
		QString params = grid_name + QString(Actions::separator.c_str()) + item->text(0);
		emit action("SwapPropertyToDisk", params);
		selected_items_.clear();
	}

	// handle Swap To RAM
	else if ("Swap to RAM" == action_name)
	{
		// must have only one item selected
		if (selected_items_.size() != 1)
		{
			return;
		}
		QTreeWidgetItem* item = selected_items_.at(0);
		QString params = grid_name + QString(Actions::separator.c_str()) + item->text(0);
		emit action("SwapPropertyToRAM", params);
		selected_items_.clear();
	}

}

// assumes that only ONE property were selected
void ObjectTree::onUnaryActionClick(QAction* _action)
{
	// must have only one item selected
	if (selected_items_.size() != 1)
	{
		return;
	}

	QString action_name = _action->text();

	QTreeWidgetItem* item = selected_items_.at(0);
	QString grid_name = getGridName(item);

	QString prop_name = item->text(0);
	QString new_prop_name = action_name + "(" + prop_name + ")";
	QString params = grid_name + QString(Actions::separator.c_str()) + prop_name + QString(Actions::separator.c_str()) + new_prop_name;
	emit action(action_name, params);
	selected_items_.clear();
}

// assumes that only ONE property were selected
void ObjectTree::onUnaryGroupActionClick(QAction* _action)
{
	// must have only one item selected
	if (selected_items_.size() != 1)
	{
		return;
	}

	QString action_name = _action->text();

	QTreeWidgetItem* item = selected_items_.at(0);
	QString grid_name = getGridName(item);

	QString group_name = item->text(0);
	QString params = grid_name + QString(Actions::separator.c_str()) + group_name;
	emit action(action_name, params);
	selected_items_.clear();
}


void ObjectTree::onPythonScriptClick(QAction* _action)
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(python_script_manager + "/" + String_Op::qstring2string(_action->text()));
	Python_script* script = dynamic_cast<Python_script*> (ni.raw_ptr());
	appli_assert( script );

	QTreeWidgetItem* item = selected_items_.at(0);
	std::string grid_name = getGridName(item).toStdString();

	std::vector<std::string> properties;
	for (int i = 0; i < selected_items_.size(); ++i)
	{
		properties.push_back(selected_items_.at(i)->text(0).toStdString());
	}

	script->execute(grid_name, properties);

	emit project_modified();
}

void ObjectTree::onPythonGroupScriptClick(QAction* _action)
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(python_group_script_manager + "/" + String_Op::qstring2string(_action->text()));
	Python_group_script* script = dynamic_cast<Python_group_script*> (ni.raw_ptr());
	appli_assert( script );

	QTreeWidgetItem* item = selected_items_.at(0);
	std::string grid_name = getGridName(item).toStdString();

	script->execute(grid_name, item->text(0).toStdString());

	emit project_modified();
}

// assumes only OBJECT was selected
void ObjectTree::onTrendActionClick(QAction* _action)
{
	// must have only one item selected
	if (selected_items_.size() != 1)
	{
		return;
	}

	QString action_name("CreateTrend");
	QString trend_id = _action->text();

	QString grid_name = getGridName(selected_items_.at(0));

	//	QString new_prop_name = action_name + "(" + prop_name + ")";
	QString params = grid_name + QString(Actions::separator.c_str()) + trend_id;
	emit action(action_name, params);
	selected_items_.clear();
}

// assumes only OBJECT was selected
void ObjectTree::onObjectContextMenuClick(QAction* _action)
{
	if (selected_items_.empty())
	{
		return;
	}

	QString action_name = _action->text();
	if ("Delete" == action_name)
	{
		QString grid_name = getGridName(selected_items_.at(0));
		if (!delete_object(grid_name))
		{
			QMessageBox::critical(this, "Cannot perform deletion", "Unable to delete object", QMessageBox::Ok, Qt::NoButton);
		} else
		{
			selected_items_.clear();
			emit delete_object_finished(grid_name);
		}
	}
	selected_items_.clear();
}

bool ObjectTree::rename_property(QString grid_name, QString old, QString n)
{
	std::string obj_name(qstring2string(grid_name));

	SmartPtr<Named_interface> grid_ni = Root::instance()->interface(gridModels_manager + "/" + obj_name);
	Geostat_grid* grid = dynamic_cast<Geostat_grid*> (grid_ni.raw_ptr());
	appli_assert(grid);

	QByteArray n1 = old_name_.toLatin1();
	QByteArray n2 = n.toLatin1();

	if (!grid->reNameProperty(n1.constData(), n2.constData()))
	{
		return false;
	}

	emit rename_finished(obj_name, old_name_, n);

	return true;
}

bool ObjectTree::delete_property(QString _grid_name, QString _prop_name)
{

	std::string obj_name(qstring2string(_grid_name));

	SmartPtr<Named_interface> grid_ni = Root::instance()->interface(gridModels_manager + "/" + obj_name);
	Geostat_grid* grid = dynamic_cast<Geostat_grid*> (grid_ni.raw_ptr());
	appli_assert(grid);

	std::string prop_name(qstring2string(_prop_name));
	if (!grid->remove_property(prop_name))
	{
		return false;
	}

	emit delete_property_finished(_grid_name, _prop_name);

	return true;
}

bool ObjectTree::delete_object(QString _grid_name)
{
	std::string obj_name(qstring2string(_grid_name));
	bool ok = Root::instance()->delete_interface(gridModels_manager + "/" + obj_name);
	if (ok)
	{
		SmartPtr<Named_interface> ni = Root::instance()->interface(projects_manager + "/" + "project");
		GsTL_project* proj = dynamic_cast<GsTL_project*> (ni.raw_ptr());
		proj->deleted_object(obj_name);
	}
	return ok;
}

void ObjectTree::keyPressEvent(QKeyEvent* event)
{
	if (rename_in_progress_)
	{
		switch (event->key())
		{

		case Qt::Key_Escape:
		{
			rename_in_progress_ = false;
			closePersistentEditor(selected_items_.at(0), 0);
			selected_items_.at(0)->setText(0, old_name_);
			emit
			project_modified();
			break;
		}

		case Qt::Key_Return:
		{
			rename_in_progress_ = false;
			QString n = dynamic_cast<QLineEdit*> (itemWidget(selected_items_.at(0), 0))->text();
			QString o = getGridName(selected_items_.at(0));

			if (old_name_ != n)
			{
				if (!rename_property(o, old_name_, n))
					QMessageBox::critical(this, "Cannot perform renaming", "Unable to rename property", QMessageBox::Ok, Qt::NoButton);
				else
				{
					selected_items_.at(0)->setText(0, n);
				}
			}
			closePersistentEditor(selected_items_.at(0), 0);
			break;
		}

		default:
		{
			break;
		}
		}

	}

	QTreeWidget::keyPressEvent(event);
}

void ObjectTree::switch_selected_items()
{
	QBrush blackBrush(Qt::black);
	QBrush redBrush(Qt::red);

	// set foreground color of all objects to black
	QTreeWidgetItem* root = topLevelItem(0);

	QQueue<QTreeWidgetItem*> queue;
	queue.enqueue(root);

	while (!queue.isEmpty())
	{
		QTreeWidgetItem* item = queue.dequeue();
		item->setForeground(0, blackBrush);
		for (int i = 0; i < item->childCount(); ++i)
		{
			queue.enqueue(item->child(i));
		}
	}

	// set selected item foreground color to red
	for (int i = 0; i < selected_items_.size(); ++i)
	{
		selected_items_.at(i)->setForeground(0, redBrush);
	}
}

QList<BaseTreeItem*> ObjectTree::getAllChildItems(QTreeWidgetItem* parent)
{
	QList<BaseTreeItem*> children;

	QQueue<QTreeWidgetItem*> queue;
	for (int i = 0; i < parent->childCount(); ++i)
	{
		queue.enqueue(parent->child(i));
	}

	while (!queue.empty())
	{
		BaseTreeItem* item = dynamic_cast<BaseTreeItem*> (queue.dequeue());
		children.push_back(item);
		for (int i = 0; i < item->childCount(); ++i)
		{
			queue.enqueue(item->child(i));
		}
	}

	return children;
}

void Oinv_view::object_rename_slot(string obj, QString old, QString n)
{
	Oinv_description_map::pair desc_pair = displayed_objects_.description(obj);
	if (desc_pair.second != 0)
	{
		desc_pair.second->update_desc(old, n);
	}
	update_project();
}

const QString Project_view_gui::general_pref_panel_name_("< General >");

Project_view_gui::Project_view_gui(QWidget* parent) :
	QWidget(parent), current_pref_panel_(0), current_info_panel_(0), _pref_scroll(NULL)
{

	setupUi(this);
	//--------------
	// Set up the Open Inventor components
	SoSeparator* root = new SoSeparator;

	//  scene_root_ = new SoSelection;
	scene_root_ = new SoSeparator;
	root->addChild(scene_root_);

	oinv_viewer_ = new SoQtGsTLViewer((QWidget*) ViewerFrame, "camera");
	oinv_viewer_->setSceneGraph(root);

	colormap_root_node_ = new SoSeparator;
	root->addChild(colormap_root_node_);

	// Initialize the map of displayed objects
	displayed_objects_.scene_graph(scene_root_);

	//--------------
	// Set up the frame for the preference panels

	pref_object_selector_ = new GridSelectorBasic(_pref_group_sel, "pref_object_selector");
	//QHBoxLayout * prefh = new QHBoxLayout();
	//_pref_group_sel->setLayout(prefh);
	_pref_group_sel->layout()->addWidget(pref_object_selector_);

	QFont cur_font = pref_object_selector_->font();
	cur_font.setBold(false);
	pref_object_selector_->setFont(cur_font);

	_pref_scroll = new QScrollArea(_pref_group);

	/*
	 QFrame * pref_panel_frame_ = new QFrame(scroll_view->viewport());
	 QVBoxLayout * vbox = new QVBoxLayout();
	 vbox->setSpacing(2);
	 vbox->setMargin(1);
	 pref_panel_frame_->setFrameShape(QFrame::NoFrame);
	 pref_panel_frame_->setLayout(vbox);
	 pref_panel_frame_->setFrameShadow(QFrame::Plain);
	 pref_panel_frame_->setFrameShape(QFrame::NoFrame);
	 //pref_panel_frame_->setContentsMargins(4,4,4,4);
	 */

	//_pref_scroll->setWidget( pref_panel_frame_ );
	_pref_scroll->setWidgetResizable(true);

	QVBoxLayout * pv = new QVBoxLayout();
	_pref_group->setLayout(pv);
	pv->setMargin(1);
	pv->addWidget(_pref_scroll);

	ControlPanel->widget(1)->layout()->addItem(new QSpacerItem(10, 16, QSizePolicy::Minimum, QSizePolicy::Minimum));
	_pref_scroll->show();

	//--------------
	// Set up the frame for the info panel

	/*
	 info_object_selector_ = new GridSelector( InfoGroupBox, "info_object_selector" );
	 QHBoxLayout * h = new QHBoxLayout(InfoGroupBox);
	 InfoGroupBox->setLayout(h);
	 h->addWidget(info_object_selector_);
	 */

	info_object_selector_ = new GridSelectorBasic(InfoGroupBox, "info_object_selector");
	QHBoxLayout * infoh = new QHBoxLayout();
	InfoGroupBox->setLayout(infoh);
	InfoGroupBox->layout()->addWidget(info_object_selector_);

	cur_font = info_object_selector_->font();
	cur_font.setBold(false);
	info_object_selector_->setFont(cur_font);

	QScrollArea* info_scroll_view = new QScrollArea(_info_group);

	info_panel_frame_ = new QFrame(info_scroll_view->viewport());
	QVBoxLayout * vboxinfo = new QVBoxLayout(info_panel_frame_);
	vboxinfo->setSpacing(2);
	vboxinfo->setMargin(1);
	info_panel_frame_->setFrameShape(QFrame::NoFrame);
	info_panel_frame_->setLayout(vboxinfo);
	info_panel_frame_->setFrameShadow(QFrame::Plain);
	info_panel_frame_->setFrameShape(QFrame::NoFrame);
	//info_panel_frame_->setContentsMargins(4,4,4,4);

	info_scroll_view->setWidget(info_panel_frame_);
	info_scroll_view->setWidgetResizable(true);

	QVBoxLayout * iv = new QVBoxLayout();
	iv->setMargin(1);
	_info_group->setLayout(iv);
	iv->addWidget(info_scroll_view);

	ControlPanel->widget(2)->layout()->addItem(new QSpacerItem(10, 16, QSizePolicy::Minimum, QSizePolicy::Minimum));

	//--------------
	// set up the "general" preference panel

	// first remove the "<- none ->" option from the list:
	pref_object_selector_->clear();

	/*
	 general_pref_panel_ =
	 new General_display_pref_panel( oinv_viewer_, colormap_root_node_,
	 &displayed_objects_,
	 pref_panel_frame_, 0 );
	 */
	general_pref_panel_ = new General_display_pref_panel(oinv_viewer_, colormap_root_node_, &displayed_objects_, _pref_scroll->viewport(), 0);
	_pref_scroll->setWidget(general_pref_panel_);
	general_pref_panel_->setGeometry(0, 0, 250, _pref_scroll->height());
	_pref_scroll->show();

	//--------------
	// initialize the other elements of the interface

	// revisit - TL
	//main_splitter_->setResizeMode( ControlPanel, QSplitter::KeepSize );

	Object_tree = new ObjectTree(this);
	Object_tree->setColumnCount(1);

	QStringList headers;
	headers << "Objects";

	Object_tree->setHeaderLabels(headers);
	Object_tree->setRootIsDecorated(true);

	objects_page->layout()->addWidget(Object_tree);

	init_objects_selector();
	Object_tree->setSelectionMode(QAbstractItemView::NoSelection);

	pref_object_selector_->addItem(general_pref_panel_name_);

	//--------------
	// Set up the connections between the different widgets


	QObject::connect(Object_tree, SIGNAL(swap_display(BaseTreeItem*)), this, SLOT(object_clicked_slot(BaseTreeItem*)));

	QObject::connect(pref_object_selector_, SIGNAL( activated( const QString& ) ), (QObject*) this, SLOT( show_preference_panel( const QString& ) ));

	QObject::connect(info_object_selector_, SIGNAL( activated( const QString& ) ), (QObject*) this, SLOT( show_info_panel( const QString& ) ));

	QObject::connect((QObject*) view_all_button_, SIGNAL(clicked()), (QObject*) this, SLOT(view_all()));
	QObject::connect((QObject*) set_home_view_button_, SIGNAL(clicked()), (QObject*) this, SLOT(set_home_view()));
	QObject::connect((QObject*) home_view_button_, SIGNAL(clicked()), (QObject*) this, SLOT(home_view()));
	QObject::connect((QObject*) face_view_button_, SIGNAL(clicked()), (QObject*) this, SLOT(face_view()));
	QObject::connect((QObject*) side_view_button_, SIGNAL(clicked()), (QObject*) this, SLOT(side_view()));
	QObject::connect((QObject*) top_view_button_, SIGNAL(clicked()), (QObject*) this, SLOT(top_view()));
	QObject::connect((QObject*) snapshot_button_, SIGNAL(clicked()), (QObject*) this, SLOT(snapshot()));

	// accept drag and drop
	setAcceptDrops(true);

}

void Project_view_gui::set_parent(QWidget* parent)
{
	QPoint p(0, 0);
	setParent(parent);
}

Project_view_gui::~Project_view_gui()
{
	if (oinv_viewer_)
	{
		delete oinv_viewer_;
	}
}

void Project_view_gui::object_clicked_slot(BaseTreeItem* item)
{
	update_display(item);
}

void Project_view_gui::init_objects_selector()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(gridModels_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert(mng);

	QTreeWidgetItem* root = Object_tree->topLevelItem(0);
	if (!root)
	{
		root = new HeaderTreeItem(Object_tree, "Objects");
		Object_tree->insertTopLevelItem(0, root);
	}

	root->setFlags(Qt::ItemIsDropEnabled); // cannot be selected

	Manager::interface_iterator begin = mng->begin_interfaces();
	Manager::interface_iterator end = mng->end_interfaces();

	for (; begin != end; ++begin)
	{
		// Add the grid-object to the list
		std::string name = mng->name(begin->raw_ptr());
		add_object(name);
	}
}

void Project_view_gui::add_object(std::string obj_name)
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(gridModels_manager + "/" + obj_name);
	Geostat_grid* grid = dynamic_cast<Geostat_grid*> (ni.raw_ptr());
	if (!grid)
	{
		appli_warning("invalid object name (object does not exist): " << obj_name);
		return;
	}

	QTreeWidgetItem* root = Object_tree->topLevelItem(0);
	appli_assert(root != 0);

	// Add the grid-object to the list
	ObjectTreeItem* gridItem = new ObjectTreeItem(root, QString(obj_name.c_str()));

	// Add the properties of the grid-object to the list
	std::list<std::string> property_names = grid->property_list();
	typedef std::list<std::string>::const_iterator iterator;
	iterator prop_end = property_names.end();
	for (iterator it = property_names.begin(); it != prop_end; ++it)
	{
		GsTLGridProperty* property = grid->property(*it);
		QVector<BaseTreeItem*> parentItems = get_property_parent_items(gridItem, property);

		for (int i = 0; i < parentItems.size(); ++i)
		{
			new PropertyTreeItem(parentItems.at(i), QString(it->c_str()));
		}
	}

	// Add the regions of the grid-object to the list
	HeaderTreeItem* regionRoot = new HeaderTreeItem(gridItem, "Regions");
	std::list<std::string> region_names = grid->region_list();
	typedef std::list<std::string>::const_iterator iterator;
	iterator region_end = region_names.end();
	for (iterator it = region_names.begin(); it != region_end; ++it)
	{
		new RegionTreeItem(regionRoot, QString(it->c_str()));
	}

}

//------------------
void Project_view_gui::set_object_displayed(const QString& obj)
{
	QTreeWidgetItem* grid_item = get_grid_listitem(obj);
	if (!grid_item)
		return;

	grid_item->setSelected(true);
	display_object(obj);
}

void Project_view_gui::set_object_undisplayed(const QString& obj)
{
	QTreeWidgetItem* grid_item = get_grid_listitem(obj);
	if (!grid_item)
		return;

	grid_item->setSelected(false);
	undisplay_object(obj);
}

void Project_view_gui::set_property_displayed(const QString& grid, const QString& prop)
{
	QTreeWidgetItem* prop_item = get_property_listitem(grid, prop);
	if (!prop_item)
		return;

	prop_item->setSelected(true);
	display_property(grid, prop);
}

void Project_view_gui::set_property_undisplayed(const QString& grid, const QString& prop)
{
	QTreeWidgetItem* prop_item = get_property_listitem(grid, prop);
	if (!prop_item)
		return;

	prop_item->setSelected(false);
	undisplay_property(grid, prop);
}
//------------------


void Project_view_gui::update_display(BaseTreeItem* item)
{
	if (!item)
		return;

	QString obj_name = item->text(0);

	// object clicked
	if (dynamic_cast<ObjectTreeItem*> (item))
	{
		item->setVisible(!item->visible());
		if (item->visible())
		{
			appli_message("displaying " << qstring2string(obj_name));
			display_object(obj_name);
		} else
		{
			appli_message("un-displaying " << qstring2string(obj_name));
			undisplay_object(obj_name);
		}
	}

	// The user clicked on a property name
	else if (dynamic_cast<PropertyTreeItem*> (item))
	{
		bool isVisible = item->visible();
		// set all properties to not visible
		BaseTreeItem* grid_item = Object_tree->getGridItem(item);
		QList<BaseTreeItem*> allChildren = grid_item->children();
		while(!allChildren.isEmpty()) {

			BaseTreeItem* child = allChildren.front();
			allChildren.pop_front();
			//allChildren.append(child->children());
			child->setVisible(false);

		}

		item->setVisible(!isVisible);
		// Move up the parent up to the grid level
		BaseTreeItem* parent = dynamic_cast<BaseTreeItem*> (item->parent());
		while(dynamic_cast<ObjectTreeItem*> (parent) == 0 ) {
			parent->setVisible(item->visible());
			parent = dynamic_cast<BaseTreeItem*> (parent->parent());
		}

		// tell the grid to change the displayed property
		QString grid_name = Object_tree->getGridName(item);
		if (item->visible())
		{
			display_property(grid_name, obj_name);
		} else
		{
			undisplay_property(grid_name, obj_name);
		}

		// find if there is a display preference panel for grid_name and
		// notify it of the changes
		Pref_Panel_Map::const_iterator panel_it = display_pref_panels_.find(std::string(qstring2string(grid_name)));
		if (panel_it != display_pref_panels_.end())
		{
			panel_it->second->change_selected_property(obj_name);
			panel_it->second->toggle_paint_property(item->visible());
		}
	}

	// The user clicked on a group name
	else if (dynamic_cast<SimulationSetTreeItem*> (item))
	{
		BaseTreeItem* firstChild = dynamic_cast<BaseTreeItem*> (item->child(0));
		firstChild->setVisible(item->visible());

		item->setVisible(!item->visible());
		update_display(firstChild);
	}
}

void Project_view_gui::display_object(const QString& obj)
{
	std::string obj_name(qstring2string(obj));
	//Desc_Map::iterator it = displayed_objects_.find( obj_name );
	Oinv_description_map::pair desc_pair = displayed_objects_.description(obj_name);
	if (!desc_pair.second)
		return;

	/* This is already done by Oinv_description_map::description( QString ), hence
	 * is commented out. I did not delete it because I am not sure
	 * Oinv_description_map should add the description to the scene...
	 if( desc_pair.first == false ) {
	 scene_root_->addChild( (SoNode*) desc_pair.second->oinv_node() );
	 }
	 */

	desc_pair.second->oinv_node()->visible = true;

	// If there is only 1 object displayed, do a viewAll.
	if (scene_root_->getNumChildren() == 1)
		oinv_viewer_->viewAll();

#ifdef OINV_DEBUG
	// Write the scene to "scene.iv"
	FILE* file = fopen("scene.iv", "w");
	SoWriteAction writer;

	writer.getOutput()->setFilePointer(file);
	writer.apply( oinv_viewer_->getSceneGraph() );
	fclose( file );
#endif

}

void Project_view_gui::undisplay_object(const QString& obj)
{
	appli_message("un-displaying " << qstring2string(obj));

	std::string obj_name(qstring2string(obj));
	//Desc_Map::iterator it = displayed_objects_.find( obj_name );
	//appli_assert( it != displayed_objects_.end() );
	Oinv_description_map::pair desc_pair = displayed_objects_.description(obj_name);

	if (!desc_pair.second)
		return;

	desc_pair.second->oinv_node()->visible = false;

}

void Project_view_gui::display_property(const QString& grid, const QString& prop)
{
	appli_message("displaying property " << qstring2string(prop) << " of object " << qstring2string(grid));

	std::string obj_name(qstring2string(grid));

	Oinv_description_map::pair desc_pair = displayed_objects_.description(obj_name);
	if (desc_pair.second == 0)
		return;

	//TL modified
	SmartPtr<Named_interface> grid_ni = Root::instance()->interface(gridModels_manager + "/" + obj_name);
	Geostat_grid* gr = dynamic_cast<Geostat_grid*> (grid_ni.raw_ptr());
	appli_assert(gr);
	Reduced_grid temp;

	if (desc_pair.first == false)
		scene_root_->addChild((SoNode*) desc_pair.second->oinv_node());

	if (gr->classname() == temp.classname())
	{
		Oinv_strati_grid * g = dynamic_cast<Oinv_strati_grid*> (desc_pair.second);
//		g->display_mode(Oinv_strati_grid::RENDERING);
	}

	QApplication::setOverrideCursor(Qt::WaitCursor);

	desc_pair.second->set_property(std::string(qstring2string(prop)));
	desc_pair.second->property_display_mode(Oinv::PAINTED);
	QApplication::restoreOverrideCursor();

/*
 * AB: I do not know why this was restricted to windows system.  It is also needed
 * for Linux to get the display to change once clicked.  When commented we need to
 * force an update to have the display updated.
 */

//#if defined(_WIN32) || defined(WIN32)
	desc_pair.second->oinv_node()->touch();
//#endif

}

void Project_view_gui::undisplay_property(const QString& grid, const QString&)
{
	Oinv_description_map::pair desc_pair = displayed_objects_.description(std::string(qstring2string(grid)));

	appli_assert(desc_pair.first == true);
	desc_pair.second->property_display_mode(Oinv::NOT_PAINTED);

//#if defined(_WIN32) || defined(WIN32)
	desc_pair.second->oinv_node()->touch();
//#endif

}

void Project_view_gui::show_preference_panel(const QString& obj)
{

	// set up the frame where the preference panel will be displayed,
	// if that has not been done yet
	if (!_pref_scroll)
	{
		_pref_scroll = new QScrollArea(_pref_group);
		_pref_scroll->setWidgetResizable(true);

		_pref_group->layout()->addWidget(_pref_scroll);
		ControlPanel->widget(1)->layout()->addItem(new QSpacerItem(10, 16, QSizePolicy::Minimum, QSizePolicy::Minimum));

		_pref_scroll->show();
	}

	// If the user wants to see the "general preferences panel"
	if (obj == general_pref_panel_name_)
	{
		if (!general_pref_panel_)
		{
			general_pref_panel_ = new General_display_pref_panel(oinv_viewer_, colormap_root_node_, &displayed_objects_, _pref_scroll->viewport(), NULL);
		}

		/* !! qscrollarea->setWidget() deletes the previous widget */
		QWidget * tmp = _pref_scroll->takeWidget();
		tmp->hide();

		_pref_scroll->setWidget(general_pref_panel_);
		_pref_scroll->show();
		return;
	}

	// The user wants to see the preference panel of an object:
	//  - get the panel from the panel map
	//  - initialize the panel and set it as the current one

	std::string obj_name(qstring2string(obj));
	Pref_Panel_Map::iterator it = display_pref_panels_.find(obj_name);

	if (it == display_pref_panels_.end())
	{
		Oinv_description_map::pair desc_pair = displayed_objects_.description(obj_name);
		if (desc_pair.first == false)
			scene_root_->addChild((SoNode*) desc_pair.second->oinv_node());

		Oinv_description* description = desc_pair.second;

		std::pair<Pref_Panel_Map::iterator, bool> inserted = display_pref_panels_.insert(std::make_pair(obj_name, new Display_pref_panel(description,
				_pref_scroll->viewport(), 0)));
		appli_assert(inserted.second == true);
		it = inserted.first;

		Display_pref_panel* pref_panel = it->second;

		QObject::connect(pref_panel, SIGNAL( displayed_property_changed( const QString&,
								const QString& ) ), this, SLOT( toggle_grid_property( const QString&,
								const QString& ) ));

		QObject::connect(pref_panel, SIGNAL( property_painted_toggled( const QString&,
								const QString& ) ), this, SLOT( toggle_grid_property( const QString&,
								const QString& ) ));

		QObject::connect(pref_panel, SIGNAL(renderRequest()), this, SLOT(reRender()));

		if (general_pref_panel_)
		{
QObject		::connect(pref_panel, SIGNAL( colormap_changed( const Colormap* ) ), general_pref_panel_, SLOT( update_colorbar() ));
	}

}

// set it->second as the currently displayed panel, and show() it
QWidget * tmp = _pref_scroll->takeWidget();
tmp->hide();

_pref_scroll->setWidget(it->second);
_pref_scroll->show();

SmartPtr<Named_interface> grid_ni = Root::instance()->interface(gridModels_manager + "/" + obj_name);
Geostat_grid* grid = dynamic_cast<Geostat_grid*> (grid_ni.raw_ptr());
appli_assert( grid );

/*
 Display_pref_panel* p = dynamic_cast<Display_pref_panel*>(current_pref_panel_);
 if (rgrid) {
 p->volume_explorer_checkbox_->setDisabled(true);
 }
 else
 p->volume_explorer_checkbox_->setDisabled(false);
 */

//current_pref_panel_->setMaximumWidth( 250 );
/*
 current_pref_panel_->setGeometry( 0,0, 250,
 _pref_scroll->height() );
 current_pref_panel_->show();
 */

}

void Project_view_gui::show_info_panel(const QString& obj)
{

	appli_assert( info_panel_frame_);
	std::cout << "showing " << qstring2string(obj) << std::endl;

	SmartPtr<Named_interface> model = Root::instance()->interface(gridModels_manager + "/" + qstring2string(obj));

	Geostat_grid* grid_obj = dynamic_cast<Geostat_grid*> (model.raw_ptr());
	if (!grid_obj)
	{
		if (current_info_panel_)
			current_info_panel_->close();
		return;
	}

	SmartPtr<Named_interface> desc_ni = Root::instance()->new_interface(grid_obj->classname(), QtSummaryDescription_manager + "/");

	QtGrid_summary* desc = dynamic_cast<QtGrid_summary*> (desc_ni.raw_ptr());
	appli_assert(desc != 0);

	desc->init(grid_obj);
	if (current_info_panel_)
		current_info_panel_->close();

	current_info_panel_ = desc->description();
	//current_info_panel_->reparent( info_panel_frame_, QPoint(0,0), true  );
	current_info_panel_->setParent(info_panel_frame_);
	info_panel_frame_->layout()->addWidget(current_info_panel_);

}

void Project_view_gui::toggle_grid_property(const QString& grid, const QString& prop)
{
	/*
	 QListViewItem* root = Object_tree->firstChild();
	 appli_assert( root != 0);

	 // search for the listview item corresponding to grid
	 QListViewItem* grid_item = root->firstChild();
	 while( grid_item ) {
	 if( grid_item->text( 0 ) == grid )
	 break;
	 grid_item = grid_item->nextSibling();
	 }
	 appli_assert( grid_item );

	 // search for the child listview item of grid_item corresponding to prop
	 QListViewItem* prop_item = grid_item->firstChild();
	 while( prop_item ) {
	 if( prop_item->text( 0 ) == prop )
	 break;
	 prop_item = prop_item->nextSibling();
	 }
	 appli_assert( prop_item );
	 */
	BaseTreeItem* prop_item = get_property_listitem(grid, prop);
	appli_assert(prop_item);

	// Select that item as the new visible property
	prop_item->setVisible(!prop_item->visible());
}

void Project_view_gui::view_all()
{
	oinv_viewer_->viewAll();
}

void Project_view_gui::set_home_view()
{
	oinv_viewer_->saveHomePosition();
}

void Project_view_gui::home_view()
{
	oinv_viewer_->resetToHomePosition();
}

void Project_view_gui::face_view()
{
	SbVec3f newNormal(1, 0, 0);
	SbVec3f newRight(0, 1, 0);

	set_view_plane(newNormal, newRight);
}

void Project_view_gui::side_view()
{
	SbVec3f newNormal(0, 1, 0);
	SbVec3f newRight(-1, 0, 0);

	set_view_plane(newNormal, newRight);
}

void Project_view_gui::top_view()
{
	SbVec3f newNormal(0, 0, 1);
	SbVec3f newRight(1, 0, 0);

	set_view_plane(newNormal, newRight);
}

void Project_view_gui::snapshot()
{
	Snapshot_dialog* dialog = new Snapshot_dialog(oinv_viewer_, this);
	dialog->show();
}

void Project_view_gui::set_view_plane(const SbVec3f& newNormal, const SbVec3f& newRight)
{

	SoCamera* camera = oinv_viewer_->getCamera();

	// get center of rotation
	SbRotation camRot = camera->orientation.getValue();
	float radius = camera->focalDistance.getValue();
	SbMatrix mx;
	mx = camRot;
	SbVec3f forward(-mx[2][0], -mx[2][1], -mx[2][2]);
	SbVec3f center = camera->position.getValue() + radius * forward;

	// rotate the camera to be aligned with the new plane normal
	SbRotation rot(-forward, newNormal);
	camRot = camRot * rot;

	// rotate the camera to be aligned with new right direction
	mx = camRot;
	SbVec3f right(mx[0][0], mx[0][1], mx[0][2]);
	rot.setValue(right, newRight);
	camRot = camRot * rot;
	camera->orientation = camRot;

	// reposition camera to look at pt of interest
	mx = camRot;
	forward.setValue(-mx[2][0], -mx[2][1], -mx[2][2]);
	camera->position = center - radius * forward;

}

void Project_view_gui::save_scenegraph_to_file(const QString& filename)
{
	FILE* file = fopen(qstring2string(filename).c_str(), "w");
	if (!file)
		return;

	SoWriteAction writer;
	writer.getOutput()->setFilePointer(file);
	writer.apply(scene_root_);

	fclose(file);
}

BaseTreeItem* Project_view_gui::get_grid_listitem(const QString& grid)
{
	QTreeWidgetItem* root = Object_tree->topLevelItem(0);
	appli_assert(root != 0);

	// search for the listview item corresponding to grid
	for (int i = 0; i < root->childCount(); ++i)
	{
		if (root->child(i)->text(0) == grid)
		{
			return (BaseTreeItem*) root->child(i);;
		}
	}

	return NULL;
}

BaseTreeItem* Project_view_gui::get_property_listitem(const QString& grid, const QString& prop)
{
	QTreeWidgetItem* root = Object_tree->topLevelItem(0);
	appli_assert(root != 0);

	BaseTreeItem* grid_item = NULL;
	BaseTreeItem* prop_item = NULL;

	// search for the listview item corresponding to grid
	for (int i = 0; i < root->childCount(); ++i)
	{
		if (root->child(i)->text(0) == grid)
		{
			grid_item = dynamic_cast<BaseTreeItem*> (root->child(i));
			break;
		}
	}

	if (grid_item == NULL)
	{
		return NULL;
	}

	QList<BaseTreeItem*> children = grid_item->children();
	// search for the child listview item of grid_item corresponding to prop
	for (int i = 0; i < children.count(); ++i)
	{
		if (children.at(i)->text(0) == prop)
		{
			prop_item = dynamic_cast<BaseTreeItem*> (children.at(i));
			break;
		}
	}

	return prop_item;
}

QVector<BaseTreeItem*> Project_view_gui::get_property_parent_items(BaseTreeItem* gridItem, GsTLGridProperty* property)
{
	QVector<BaseTreeItem*> parents;

	if (property->has_group_membership())
	{
		std::vector<std::string> groupNames = property->group_names();
		for (std::vector<std::string>::iterator iter = groupNames.begin(); iter != groupNames.end(); ++iter)
		{
			QString groupName = iter->c_str();
			BaseTreeItem* matchingChild = treeItemChildByName(gridItem, groupName);
			if (matchingChild == NULL)
			{
				matchingChild = new SimulationSetTreeItem(gridItem, groupName);
			}
			parents.push_back(matchingChild);
		}
	}
	// property does not belong to any group
	else
	{
		parents.push_back(gridItem);
	}

	return parents;
}

QVector<QString> Project_view_gui::get_property_group_names(BaseTreeItem* gridItem, GsTLGridProperty* property)
{
	QVector<QString> group_names;

	if (property == 0)
	{
		return group_names;
	}

	if (property->has_group_membership())
	{
		std::vector<std::string> groupNames = property->group_names();
		for (std::vector<std::string>::iterator iter = groupNames.begin(); iter != groupNames.end(); ++iter)
		{
			QString groupName = iter->c_str();
			group_names.push_back(groupName);
		}
	}
	// property does not belong to any group
	else
	{
		group_names.push_back(gridItem->text(0));
	}

	return group_names;
}

BaseTreeItem* Project_view_gui::treeItemChildByName(BaseTreeItem* treeItem, QString childName)
{
	BaseTreeItem* childItem = NULL;
	for (int i = 0; i < treeItem->childCount(); ++i)
	{
		if (treeItem->child(i)->text(0) == childName)
		{
			childItem = dynamic_cast<BaseTreeItem*> (treeItem->child(i));
			break;
		}
	}
	return childItem;
}

void Project_view_gui::reorderTreeItems()
{
	QTreeWidgetItem* root = Object_tree->topLevelItem(0);
	for (int i = 0; i < root->childCount(); ++i)
	{
		BaseTreeItem* gridItem = dynamic_cast<BaseTreeItem*> (root->child(i));
		QVector<BaseTreeItem*> childItems;
		while (gridItem->childCount() > 0)
		{
			BaseTreeItem* childItem = dynamic_cast<BaseTreeItem*> (gridItem->child(0));
			childItems.push_back(childItem);
			gridItem->removeChild(childItem);
		}

		// add properties first
		for (int index = 0; index < childItems.size(); ++index)
		{
			if (dynamic_cast<PropertyTreeItem*> (childItems.at(index)))
			{
				gridItem->addChild(childItems.at(index));
			}
		}

		// then simulation groups
		for (int index = 0; index < childItems.size(); ++index)
		{
			if (dynamic_cast<SimulationSetTreeItem*> (childItems.at(index)))
			{
				gridItem->addChild(childItems.at(index));
			}
		}

		// and finally the regions
		for (int index = 0; index < childItems.size(); ++index)
		{
			if (dynamic_cast<HeaderTreeItem*> (childItems.at(index)))
			{
				gridItem->addChild(childItems.at(index));
			}
		}
	}

}

//=======================================================


Oinv_view::Oinv_view(GsTL_project* project, QWidget* parent) :
	Project_view_gui(parent), Project_view(project)
{

	pref_object_selector_->init(project_);
	info_object_selector_->init(project_);
	general_pref_panel_->init(project_);

	QObject::connect(Object_tree, SIGNAL(rename_finished(string, QString, QString)), this, SLOT(object_rename_slot(string, QString, QString)));
	QObject::connect(Object_tree, SIGNAL(action(QString, QString)), this, SLOT(execute_action(QString, QString)));
	QObject::connect(Object_tree, SIGNAL(project_modified()), this, SLOT(update_project()));
	QObject::connect(Object_tree, SIGNAL(delete_object_finished(QString)), this, SLOT(slot_delete_object(QString)));
}

void Oinv_view::initialize(GsTL_project* project, QWidget* parent)
{
	Project_view::init(project);
	Project_view_gui::set_parent(parent);

	pref_object_selector_->init(project_);
	info_object_selector_->init(project_);
	general_pref_panel_->init(project_);
}

Oinv_view::~Oinv_view()
{
	appli_message("destroying Oinv_view");

	/* This is a dirty trick...
	 * Oinv_view is a QWidget, and as such is destroyed by its parent widget
	 * However, I would like the project to maintain smart-pointers to its views.
	 * If smart-pointers are used, they take care of the deletion.
	 * Finally the view gets deleted twice, once by the smart pointer, and another
	 * time by QT.
	 * The (dirty) trick is to artificially increment the number of references on
	 * the view so that the smart pointer does not trigger the deletion.
	 * Should find a better solution...
	 */
	//  Named_interface::new_ref();
}

void Oinv_view::update(std::string obj)
{

	// Some of the existing objects have been updated (ie a property
	// has been added, removed, etc, or a region has been added, etc)

	/* TODO:
	 *  - The current implementation ignores the hint "obj".
	 */

	QTreeWidgetItem* root = Object_tree->topLevelItem(0);
	appli_assert(root != 0);

	BaseTreeItem* grid_item;

	// Visit each grid object entry. For each, check that the property
	// list is up-to-date. If not, add/remove the properties that should be
	// added/removed
	for (int i = 0; i < root->childCount(); ++i)
	{
		grid_item = dynamic_cast<BaseTreeItem*> (root->child(i));
		appli_assert(grid_item != 0);
		std::string grid_name(qstring2string(grid_item->text(0)));
		appli_message("updating grid_name: \"" << grid_name << "\"");

		SmartPtr<Named_interface> grid_ni = Root::instance()->interface(gridModels_manager + "/" + grid_name);
		if (!grid_ni.raw_ptr())
		{
			appli_warning("no grid called \"" << grid_name << "\"");
			return;
		}
		Geostat_grid* grid = dynamic_cast<Geostat_grid*> (grid_ni.raw_ptr());
		appli_assert(grid != 0);

		// get the list of properties of the current grid
		std::list<std::string> property_names = grid->property_list();
		QList<QString> property_names_qstring;
		typedef std::list<std::string>::iterator iterator;
		iterator prop_end = property_names.end();

		// add newly added properties
		for (iterator it = property_names.begin(); it != prop_end; ++it)
		{
			property_names_qstring.push_back(QString(it->c_str()));

			GsTLGridProperty* property = grid->property(*it);
			QVector<BaseTreeItem*> parentItems = get_property_parent_items(grid_item, property);

			for (int i = 0; i < parentItems.size(); ++i)
			{
				if (NULL == treeItemChildByName(parentItems.at(i), QString(it->c_str())))
				{
					new PropertyTreeItem(parentItems.at(i), QString(it->c_str()));
				}
			}
		}

		// remove deleted properties
		std::vector<std::string> to_be_removed;
		QList<BaseTreeItem*> allChildren = grid_item->children();
		for (int i = 0; i < allChildren.size(); ++i)
		{
			BaseTreeItem* child = allChildren.at(i);
			if (dynamic_cast<PropertyTreeItem*> (child))
			{
				QVector<QString> group_names = get_property_group_names(grid_item, grid->property(child->text(0).toStdString()));
				if (false == group_names.contains(child->parent()->text(0)))
				{
					to_be_removed.push_back(child->text(0).toStdString());
					child->parent()->removeChild(child);
					delete child;
				}
			}
			// delete all region entries
			else if (dynamic_cast<RegionTreeItem*> (child))
			{
				child->parent()->removeChild(child);
				delete child;
			}
		}

		// remove grouping elements no longer needed
		property_names_qstring.push_back("Regions"); // done to avoid removing "Regions" entry
		for (int i = 0; i < grid_item->childCount();)
		{
			QTreeWidgetItem* child = grid_item->child(i);
			if ((false == property_names_qstring.contains(child->text(0))) && (child->childCount() == 0))
			{
				grid_item->removeChild(child);
				delete child;
			} else
			{
				++i;
			}
		}

		BaseTreeItem* regionRoot = treeItemChildByName(grid_item, "Regions");
		std::list<std::string> region_names = grid->region_list();
		iterator region_end = region_names.end();
		for (iterator it = region_names.begin(); it != region_end; ++it)
		{
			new RegionTreeItem(regionRoot, QString(it->c_str()));
		}

		// reorder
		reorderTreeItems();

		// If properties were removed, tell the oinv description
		// Remove the property names that should be removed
		Oinv_description_map::iterator desc_found = displayed_objects_.find(grid_name);
		if (desc_found != displayed_objects_.end())
		{
			Oinv_description* desc = desc_found->second.raw_ptr();
			desc->update(Oinv::PROPERTY_DELETED, &to_be_removed);
			//      for( String_iterator it3 = to_be_removed.begin(); it3!= removed_end; ++it3 ) {
			//        desc->update( Oinv::PROPERTY_DELETED, *it3 );
			//      }
		}

	}

	// Update the oinv descriptions, in case an existing property was modified
	for (Oinv_description_map::iterator it = displayed_objects_.begin(); it != displayed_objects_.end(); ++it)
	{
		it->second->update(Oinv::PROPERTY_CHANGED);
	}

	// Update the display preference panels
	for (Pref_Panel_Map::iterator it2 = display_pref_panels_.begin(); it2 != display_pref_panels_.end(); ++it2)
	{
		it2->second->update();
	}

	appli_warning("Oinv_view::update() NOT YET IMPLEMENTED");
	// check if objet obj is displayed. If yes, redraw
	// otherwise, ignore
}

void Oinv_view::new_object(std::string obj)
{
	add_object(obj);
}

void Oinv_view::deleted_object(std::string obj)
{
	/* 3 things have to be updated:
	 *   - remove "obj" from tree view of objects (Object_tree)
	 *   - undisplay "obj" if it was displayed
	 *   - remove the preference panel for "obj"
	 */

	QString gridname(obj.c_str());

	//--------------
	// Remove obj from the tree view
	/*
	 // search for the listview item corresponding to obj
	 QListViewItem* root = Object_tree->firstChild();
	 QListViewItem* grid_item = root->firstChild();
	 while( grid_item ) {
	 if( grid_item->text( 0 ) == gridname )
	 break;
	 grid_item = grid_item->nextSibling();
	 }
	 */
	QTreeWidgetItem* grid_item = get_grid_listitem(obj.c_str());
	if (!grid_item)
		return;

	delete grid_item;

	//--------------
	// undisplay obj

	displayed_objects_.delete_description(obj);

	//--------------
	// remove the preference panel
	Pref_Panel_Map::iterator pref_it = display_pref_panels_.find(obj);

	/*
	 if( current_pref_panel_ == pref_it->second ) {
	 //pref_object_selector_->setCurrentText( general_pref_panel_name_ );

	 pref_object_selector_->setItemText(pref_object_selector_->currentIndex(),
	 general_pref_panel_name_);

	 //pref_object_selector_->setCurrentIndex(0);
	 std::cout << "past set current" << std::endl;
	 //show_preference_panel( pref_object_selector_->currentText() );
	 }
	 */

	display_pref_panels_.erase(obj);

}

void Oinv_view::dragMoveEvent(QDragMoveEvent *)
{
}

void Oinv_view::dragEnterEvent(QDragEnterEvent * e)
{
	if (e->mimeData()->hasUrls())
		e->acceptProposedAction();

}

void Oinv_view::dragLeaveEvent(QDragLeaveEvent *)
{
}

void Oinv_view::dropEvent(QDropEvent * e)
{
	Error_messages_handler error_messages;
	bool ok = true;

	if (!e->mimeData()->hasUrls())
		return;
	QList<QUrl> urls = e->mimeData()->urls();

	for (int i = 0; i < urls.size(); ++i)
	{
		QString s = urls[i].toLocalFile();

		if (s.isEmpty())
			continue;

		appli_message("Loading file " << qstring2string(s));
		QFileInfo f_info(s);
		if (f_info.isDir() && (s.endsWith(".prj", Qt::CaseInsensitive) || s.endsWith(".prj/", Qt::CaseInsensitive)))
		{
			ok *= project_->execute("LoadProject", std::string(qstring2string(s)), &error_messages);
		} else
		{
			if (s.endsWith(".prt", Qt::CaseInsensitive))
			{
				ok *= project_->execute("LoadSimFromFile", qstring2string(s), &error_messages);
			} else
			{
				std::string param(std::string(qstring2string(s)) + Actions::separator + "All");
				ok *= project_->execute("LoadObjectFromFile", param, &error_messages);
			}
		}
	}
	if (!ok)
	{
		GsTLcerr << "All the selected files could not be loaded. \n";
		if (!error_messages.empty())
			GsTLcerr << error_messages.errors() << "\n";
		GsTLcerr << gstlIO::end;
	}

}

void Oinv_view::execute_action(QString _action_name, QString _params)
{
	Error_messages_handler error_messages;
	std::string action_name = qstring2string(_action_name);
	std::string params = qstring2string(_params);

	bool ok = project_->execute(action_name, params, &error_messages);

	if (!ok)
	{
		GsTLcerr << "Command " << action_name << " could not be performed: \n";
		if (!error_messages.empty())
			GsTLcerr << error_messages.errors() << "\n";
		GsTLcerr << gstlIO::end;
		return;
	}

	update_project();
}

void Oinv_view::update_project()
{
	if (project_)
	{
		project_->update();
	}
}

void Oinv_view::slot_delete_object(QString _grid_name)
{
	deleted_object(qstring2string(_grid_name));
	update_project();
}

//=========================================================

Oinv_description_map::Oinv_description_map(SoGroup* scene_root) :
	scene_root_(scene_root)
{

}

void Oinv_description_map::scene_graph(SoGroup* scene_root)
{
	scene_root_ = scene_root;
}

std::pair<bool, Oinv_description*> Oinv_description_map::description(const std::string& obj_name)
{
	bool already_there = true;
	Desc_Map::iterator it = available_descriptions_.find(obj_name);

	if (it == available_descriptions_.end())
	{
		already_there = false;

		SmartPtr<Named_interface> model = Root::instance()->interface(gridModels_manager + "/" + obj_name);

		Geostat_grid* grid_obj = dynamic_cast<Geostat_grid*> (model.raw_ptr());
		if (!grid_obj)
			return std::make_pair(false, (Oinv_description*) 0);

		SmartPtr<Named_interface> desc_ni = Root::instance()->new_interface(grid_obj->classname(), oinvDescription_manager + "/");

		Oinv_description* desc = dynamic_cast<Oinv_description*> (desc_ni.raw_ptr());
		appli_assert(desc != 0);

		desc->init(grid_obj);

		appli_assert( scene_root_);
		if (scene_root_)
			scene_root_->addChild(desc->oinv_node());

		std::pair<Desc_Map::iterator, bool> ins = available_descriptions_.insert(std::make_pair(obj_name, SmartPtr<Oinv_description> (desc)));

		appli_assert(ins.second == true);
		it = ins.first;
	}

	return std::make_pair(already_there, it->second.raw_ptr());
}

bool Oinv_description_map::delete_description(const std::string& obj_name)
{
	Desc_Map::iterator it = available_descriptions_.find(obj_name);

	if (it == available_descriptions_.end())
		return false;

	GsTL_SoNode* node = it->second->oinv_node();
	//  node->visible = false;
	int count = scene_root_->getNumChildren();
	int idx = scene_root_->findChild(node);
	scene_root_->removeChild(node);
	scene_root_->removeChild(node);
	idx = scene_root_->findChild(node);
	available_descriptions_.erase(it);

	return true;
}

Oinv_description_map::iterator Oinv_description_map::find(const std::string& obj_name)
{
	return available_descriptions_.find(obj_name);
}
