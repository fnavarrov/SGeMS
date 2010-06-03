/**********************************************************************
 ** Author: Nicolas Remy
 ** Copyright (C) 2002-2004 The Board of Trustees of the Leland Stanford Junior
 **   University
 ** All rights reserved.
 **
 ** This file is part of the "main" module of the Geostatistical Earth
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
#include <GsTLAppli/main/lib_initializer.h>
#include <GsTLAppli/actions/library_actions_init.h>
#include <GsTLAppli/appli/library_appli_init.h>
#include <GsTLAppli/filters/library_filters_init.h>
#include <GsTLAppli/geostat/library_geostat_init.h>
#include <GsTLAppli/grid/library_grid_init.h>
#include <GsTLAppli/gui/library_gui_init.h>
#include <GsTLAppli/extra/gui/library_extragui_init.h>
#include <GsTLAppli/utils/gstl_messages.h>

#include <qdir.h>
#include <qstring.h>
#include <qlibrary.h>
#include <qdir.h>

#include <string>
#include <cstdlib>

int Lib_initializer::ref_ = 0;

void Lib_initializer::init()
{

	// Initialize the root plugin path for the managers
	std::string path;
	char* env = getenv("GSTLAPPLIHOME");
	if (env)
	{
		path = std::string(env) + "/plugins/";
	} else
	{
		QDir current_dir;
		bool exists = current_dir.cd("plugins");
		if (!exists)
			GsTLcerr << "No plugin directory could be found.\n" << "Set environment variable GSTLAPPLIHOME to where SGeMS" << " was installed" << gstlIO::end;
		else
		{
			QByteArray tmp = current_dir.absolutePath().toLatin1();
			path = std::string(tmp.constData());
		}
	}

	Root::instance()->set_main_plugin_path(path);

	// initialize all the libraries
	libGsTLAppli_actions_init();
	libGsTLAppli_appli_init();
	libGsTLAppli_filters_init();
	libGsTLAppli_geostat_init();
	libGsTLAppli_grid_init();
	libGsTLAppli_gui_init();
	libGsTLAppli_extragui_init();
}

void Lib_initializer::minimal_init()
{
	// Initialize the root plugin path for the managers
	std::string path;
	char* env = getenv("GSTLAPPLIHOME");
	if (env)
	{
		path = std::string(env) + "/plugins/";
	} else
	{
		QDir current_dir;
		bool exists = current_dir.cd("plugins");
		if (!exists)
			GsTLcerr << "No plugin directory could be found.\n" << "Set environment variable GSTLAPPLIHOME to where SGeMS" << " was installed" << gstlIO::end;
		else
		{
			QByteArray tmp = current_dir.absolutePath().toLatin1();
			path = std::string(tmp.constData());
		}
	}

	Root::instance()->set_main_plugin_path(path);

	// initialize all non-gui libraries
	libGsTLAppli_actions_init();
	libGsTLAppli_appli_init();
	libGsTLAppli_filters_init();
	libGsTLAppli_geostat_init();
	libGsTLAppli_grid_init();
}

void Lib_initializer::release()
{
	Root::instance()->delete_interface(actions_manager);
	Root::instance()->delete_interface(python_script_manager);
	Root::instance()->delete_interface(python_group_script_manager);
	Root::instance()->delete_interface(infilters_manager);
	Root::instance()->delete_interface(outfilters_manager);
	Root::instance()->delete_interface(gridObject_manager);
	Root::instance()->delete_interface(geostatAlgo_manager);
	Root::instance()->delete_interface(qtWrapper_manager);
	Root::instance()->delete_interface(geostatParamUtils_manager);
	Root::instance()->delete_interface(colormap_manager);
	Root::instance()->delete_interface(projectViews_manager);
	Root::instance()->delete_interface(projects_manager);

}

void Lib_initializer::load_geostat_algos()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(geostatAlgo_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert( mng );

	std::string geostat_plugin_path(mng->plugin_path());
	QString path(geostat_plugin_path.c_str());

	// Loop on all the library files (.so or .dll) in directory "path"
	QDir dir(path);
	QStringList filters;
	filters << "*.so" << "*.dll";
	dir.setNameFilters(filters);
	dir.setFilter(QDir::Files);
	const QFileInfoList list = dir.entryInfoList();

	if (list.empty())
	{
		GsTLlog << "No geostatistics plugin could be found.\n" << "Check that environment variable GSTLAPPLIHOME is set to " << "where SGeMS was installed\n"
				<< "or that directory plugins/Geostat actually contains plugins\n" << gstlIO::end;
		return;
	}

	QFileInfoList::const_iterator it = list.begin();
	const QFileInfo* f_info;

	for (; it != list.end(); ++it)
	{
		f_info = &(*it);
		// QLibrary wants the absolute path
		QString abs_path(path + "/" + f_info->fileName());
		QByteArray tmp = abs_path.toAscii();
		GsTLlog << "Trying to load plug-in: " << tmp.constData() << "...\n";
		QLibrary lib(abs_path);
		//lib.setAutoUnload( false );
		lib.load();
		if (!lib.isLoaded())
		{
			GsTLlog << "The plug-in was not loaded: QLibrary::load failed. Aborting \n\n";
			continue;
		}

		typedef int (*Init_func_prototype)(void);

		//// The function must be called [filename]_init()
		//QString init_func_name( f_info->baseName() + "_init" );

		// The function must be called plugin_init()
		QString init_func_name = "plugin_init";
		QByteArray tmp1 = init_func_name.toLatin1();
		Init_func_prototype init_func = (Init_func_prototype) lib.resolve(tmp1.constData());

		if (init_func)
		{
			init_func();
			GsTLlog << "... OK\n\n";
		} else
		{
			QByteArray n = init_func_name.toAscii();
			GsTLlog << "unable to resolve symbol " << n.constData() << "\n\n";
		}
	}

	Root::instance()->list_all(GsTLlog);
}

void Lib_initializer::load_colormaps()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(colormap_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert( mng );

	std::string colormap_files_path(mng->plugin_path());
	QString path(colormap_files_path.c_str());

	// Loop on all the colormap definition files (*.cmap) in directory "path"
	QDir dir(path);
	QStringList filters;
	filters << "*.cmap";
	dir.setNameFilters(filters);
	dir.setFilter(QDir::Files);
	const QFileInfoList list = dir.entryInfoList();
	if (list.empty())
	{
		GsTLcerr << "No colormap could be found.\n" << "Check that environment variable GSTLAPPLIHOME is set to " << "where SGeMS was installed\n"
				<< "or that directory plugins/colormaps contains colormap " << "definitions \n" << gstlIO::end;
		return;
	}

	QFileInfoList::const_iterator it = list.begin();
	const QFileInfo* f_info = 0;

	for (; it != list.end(); ++it)
	{
		f_info = &(*it);
		// QLibrary wants the absolute path
		QString full_path = path + "/" + f_info->fileName();
		QByteArray s1 = full_path.toLatin1();
		QByteArray s2 = f_info->baseName().toLatin1();
		Root::instance()->new_interface("colormap://" + std::string(s1.constData()), colormap_manager + "/" + std::string(s2.constData()));
	}
}

void Lib_initializer::load_categorical_definition()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(categoricalDefinition_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert( mng );

	std::string colormap_files_path(mng->plugin_path());
	QString path(colormap_files_path.c_str());

	// Loop on all the categorical definition files (*.cdef) in directory "path"
	QDir dir(path);
	QStringList filters;
	filters << "*.cdef";
	dir.setNameFilters(filters);
	dir.setFilter(QDir::Files);
	const QFileInfoList list = dir.entryInfoList();
	if (list.empty())
	{
		GsTLcerr << "No categorical definition could be found.\n" << "Check that environment variable GSTLAPPLIHOME is set to "
				<< "where SGeMS was installed\n" << "or that directory plugins/catdefiniton contains categorical definition " << "definitions \n"
				<< gstlIO::end;
		return;
	}

	QFileInfoList::const_iterator it = list.begin();
	const QFileInfo* f_info = 0;

	for (; it != list.end(); ++it)
	{
		f_info = &(*it);
		// QLibrary wants the absolute path
		QString full_path = path + "/" + f_info->fileName();
		QByteArray s1 = full_path.toLatin1();
		QByteArray s2 = f_info->baseName().toLatin1();
		Root::instance()->new_interface("cdefintion://" + std::string(s1.constData()), categoricalDefinition_manager + "/" + std::string(s2.constData()));
	}
}

void Lib_initializer::load_filters_plugins()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(topLevelInputFilters_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert( mng );

	std::string filters_plugin_path(mng->plugin_path());
	QString path(filters_plugin_path.c_str());

	// Loop on all the library files (.so or .dll) in directory "path"
	QDir dir(path);
	if (!dir.exists())
		return;

	QStringList filters;
	filters << "*.so" << "*.dll";
	dir.setNameFilters(filters);
	dir.setFilter(QDir::Files);
	const QFileInfoList list = dir.entryInfoList();

	if (list.empty())
	{
		GsTLlog << "No filter plugins found.\n" << gstlIO::end;
		return;
	}

	QFileInfoList::const_iterator it = list.begin();
	const QFileInfo* f_info;

	for (; it != list.end(); ++it)
	{
		f_info = &(*it);
		// QLibrary wants the absolute path
		QString tmp = path + "/" + f_info->fileName();
		QByteArray tmps = tmp.toLatin1();
		appli_message( "loading file: " << tmps.constData());
		QLibrary lib(path + "/" + f_info->fileName());
		//lib.setAutoUnload( false );
		lib.load();
		if (!lib.isLoaded())
		{
			appli_warning( "library not loaded " << std::endl );
			continue;
		}

		typedef int (*Init_func_prototype)(void);

		// The function must be called [filename]_init()
		// QString init_func_name( f_info->baseName() + "_init" );

		// The function must be called plugin_init()
		QString init_func_name = "plugin_init";
		QByteArray tmp1 = init_func_name.toLatin1();
		Init_func_prototype init_func = (Init_func_prototype) lib.resolve(tmp1.constData());

		if (init_func)
			init_func();
		else
		{
			QByteArray s = init_func_name.toLatin1();
			appli_warning( "unable to resolve symbol " << s.constData() );
		}

	}

}

void Lib_initializer::load_action_plugins()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(actions_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert( mng );

	std::string action_plugin_path(mng->plugin_path());
	QString path(action_plugin_path.c_str());

	// Loop on all the library files (.so or .dll) in directory "path"
	QDir dir(path);
	QStringList filters;
	filters << "*.so" << "*.dll";
	dir.setNameFilters(filters);
	dir.setFilter(QDir::Files);
	const QFileInfoList list = dir.entryInfoList();

	if (list.empty())
	{
		//		GsTLlog << "No action plugin could be found.\n" << "Check that environment variable GSTLAPPLIHOME is set to " << "where SGeMS was installed\n"
		//				<< "or that directory plugins/actions actually contains plugins\n" << gstlIO::end;
		return;
	}

	QFileInfoList::const_iterator it = list.begin();
	const QFileInfo* f_info;

	for (; it != list.end(); ++it)
	{
		f_info = &(*it);
		// QLibrary wants the absolute path
		QString abs_path(path + "/" + f_info->fileName());
		QByteArray tmp = abs_path.toAscii();
		GsTLlog << "Trying to load plug-in: " << tmp.constData() << "...\n";
		QLibrary lib(abs_path);
		//lib.setAutoUnload( false );
		lib.load();
		if (!lib.isLoaded())
		{
			GsTLlog << "The plug-in was not loaded: QLibrary::load failed. Aborting \n\n";
			continue;
		}

		typedef int (*Init_func_prototype)(void);

		//// The function must be called [filename]_init()
		//QString init_func_name( f_info->baseName() + "_init" );

		// The function must be called plugin_init()
		QString init_func_name = "plugin_init";
		QByteArray tmp1 = init_func_name.toLatin1();
		Init_func_prototype init_func = (Init_func_prototype) lib.resolve(tmp1.constData());

		if (init_func)
		{
			init_func();
			GsTLlog << "... OK\n\n";
		} else
		{
			QByteArray n = init_func_name.toAscii();
			GsTLlog << "unable to resolve symbol " << n.constData() << "\n\n";
		}
	}

	Root::instance()->list_all(GsTLlog);
}

void Lib_initializer::load_python_scripts()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(python_script_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert( mng );

	std::string python_scripts_path(mng->plugin_path());
	QString path(python_scripts_path.c_str());

	// Loop on all the python scripts (*.py) in directory "path"
	QDir dir(path);
	QStringList filters;
	filters << "*.py";
	dir.setNameFilters(filters);
	dir.setFilter(QDir::Files);
	const QFileInfoList list = dir.entryInfoList();

	if (list.empty())
	{
		//		GsTLcerr << "No python scripts could be found.\n" << "Check that environment variable GSTLAPPLIHOME is set to " << "where SGeMS was installed\n"
		//				<< "or that directory plugins/ " + mng->plugin_path() + " contains python script files \n" << gstlIO::end;
		return;
	}

	QFileInfoList::const_iterator it = list.begin();
	const QFileInfo* f_info = 0;

	for (; it != list.end(); ++it)
	{
		f_info = &(*it);
		// QLibrary wants the absolute path
		QString full_path = path + "/" + f_info->fileName();
		QByteArray s1 = full_path.toLatin1();
		QByteArray s2 = f_info->baseName().toLatin1();
		Root::instance()->new_interface("pythonscript://" + std::string(s1.constData()), python_script_manager + "/" + std::string(s2.constData()));
	}
}

void Lib_initializer::load_python_group_scripts()
{
	SmartPtr<Named_interface> ni = Root::instance()->interface(python_group_script_manager);
	Manager* mng = dynamic_cast<Manager*> (ni.raw_ptr());
	appli_assert( mng );

	std::string python_scripts_path(mng->plugin_path());
	QString path(python_scripts_path.c_str());

	// Loop on all the python scripts (*.py) in directory "path"
	QDir dir(path);
	QStringList filters;
	filters << "*.py";
	dir.setNameFilters(filters);
	dir.setFilter(QDir::Files);
	const QFileInfoList list = dir.entryInfoList();

	if (list.empty())
	{
		//		GsTLcerr << "No python scripts could be found.\n" << "Check that environment variable GSTLAPPLIHOME is set to " << "where SGeMS was installed\n"
		//				<< "or that directory plugins/ " + mng->plugin_path() + " contains python script files \n" << gstlIO::end;
		return;
	}

	QFileInfoList::const_iterator it = list.begin();
	const QFileInfo* f_info = 0;

	for (; it != list.end(); ++it)
	{
		f_info = &(*it);
		// QLibrary wants the absolute path
		QString full_path = path + "/" + f_info->fileName();
		QByteArray s1 = full_path.toLatin1();
		QByteArray s2 = f_info->baseName().toLatin1();
		Root::instance()->new_interface("pythongroupscript://" + std::string(s1.constData()), python_group_script_manager + "/" + std::string(s2.constData()));
	}
}
