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
#ifdef _DEBUG
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif

#include <GsTLAppli/sgems_version.h>
#include <GsTLAppli/gui/utils/qtprogress_notifier.h>
#include <GsTLAppli/gui/utils/multichoice_dialog.h>
#include <GsTLAppli/gui/utils/delete_properties_dialog.h>
#include <GsTLAppli/gui/utils/delete_regions_dialog.h>
#include <GsTLAppli/gui/utils/merge_regions_dialog.h>
#include <GsTLAppli/gui/utils/new_region_from_property_dialog.h>
#include <GsTLAppli/gui/utils/new_mgrid_from_cgrid_dialog.h>
#include <GsTLAppli/gui/utils/categorical_definition_dialog.h>
#include <GsTLAppli/gui/utils/script_editor.h>
#include <GsTLAppli/gui/utils/qdirdialog.h>
#include <GsTLAppli/gui/appli/qt_sp_application.h>
#include <GsTLAppli/gui/appli/histogram_gui.h>
#include <GsTLAppli/gui/appli/qpplot_gui.h>
#include <GsTLAppli/gui/appli/qt_algo_control_panel.h>
#include <GsTLAppli/gui/appli/new_cartesian_grid_dialog.h>
#include <GsTLAppli/gui/appli/scatterplot_gui.h>
#include <GsTLAppli/gui/appli/oinv_project_view.h>
#include <GsTLAppli/gui/appli/cli_commands_panel.h>
#include <GsTLAppli/gui/variogram2/variogram_modeler_gui.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/actions/defines.h>
#include <GsTLAppli/filters/filter.h>
#include <GsTLAppli/grid/grid_model/gval_iterator.h>
#include <GsTLAppli/grid/grid_model/reduced_grid.h>
#include <QKeySequence>
#include <qmenubar.h>
#include <qlayout.h>
#include <qdockwidget.h>
#include <qspinbox.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qmessagebox.h>
#include <qapplication.h>
#include <qfiledialog.h>
#include <qdir.h>
#include <qpushbutton.h>
#include <qdatetime.h>
//Added by qt3to4:
#include <QHBoxLayout>
#include <QPixmap>
#include <QFrame>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMenu>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <cstdio>
#include <qsettings.h>
#include <qlistwidget.h>
#include <qcheckbox.h>

//--------------------------------------------------


QSP_application::QSP_application( QWidget* parent ) 
  : QMainWindow( parent ) {

  // Use a Qt-based progress notifier to report on progress of long tasks
  Root::instance()->factory( "progress_notifier", 
                             QtProgress_notifier::create_new_interface );
}


QSP_application::~QSP_application() {
  appli_warning( "destructor for QSP_application not implemented yet" );

  /*
  // tell the managers to delete all the objects they manage
  Manager::interface_iterator it = Root::instance()->begin_interfaces();
  for( ; it != Root::instance()->end_interfaces() ; ++it ) {
    std::string name = Root::instance()->name( it->raw_ptr() );
    Root::instance()->delete_interface( "/" + name );
  }

  // temporary
  Root::instance()->list_all( std::cout );
*/
}


void QSP_application::init() {
  
  // create a default project
  SmartPtr<Named_interface> ni = 
    Root::instance()->new_interface( "project", projects_manager + "/" + "project" );
  project_ = dynamic_cast<GsTL_project*>( ni.raw_ptr() );
  appli_assert( project_ );
  

  //-----------
  // set up the algorithm panel as a dockable window

  dock_controls_ = new QDockWidget(this );
  dock_controls_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  //dock_controls_->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
  
  //revisit - TL
  //dock_controls_->setFixedExtentWidth( 250 );

  
  algo_panel_ = new Algo_control_panel( project_, dock_controls_, "algo_panel" );
  dock_controls_->setWidget( algo_panel_ );
  dock_controls_->layout()->setContentsMargins( 0,0,0,0 );
  dock_controls_->layout()->setSpacing( 0 );

  addDockWidget(Qt::LeftDockWidgetArea, dock_controls_);
  dock_controls_->setWindowTitle("Algorithms");

  //revisit - TL
  //setAppropriate( dock_controls_, true );

  QObject::connect( dock_controls_, SIGNAL( visibilityChanged ( bool ) ),
                    this, SLOT( show_algo_panel( bool ) ) );


  //-----------
  // set up the cli panel as a dockable window

  dock_cli_ = new QDockWidget(this );
  dock_cli_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  dock_cli_->setFeatures(QDockWidget::AllDockWidgetFeatures);

  cli_panel_ = new CLI_commands_panel( project_, dock_cli_, "cli_panel" );
  dock_cli_->setWidget( cli_panel_ );
  
  addDockWidget( Qt::BottomDockWidgetArea , dock_cli_); 
  dock_cli_->setWindowTitle("Commands");

  //dock_cli_->setFixedExtentHeight( 20 );  //seems useless

  //revisit - TL
  //setAppropriate( dock_cli_, true );
  
  dock_cli_->hide();


  QObject::connect( dock_cli_, SIGNAL( visibilityChanged ( bool ) ),
                    this, SLOT( show_commands_panel( bool ) ) );

  
  //-----------
  // create a view of the project

  SmartPtr<Named_interface> view_ni = 
    Root::instance()->new_interface( "oinv_view", projectViews_manager + "/main_view" );
  default_3dview_ = dynamic_cast<Oinv_view*>( view_ni.raw_ptr() );
  appli_assert( default_3dview_ );
  default_3dview_->initialize( project_, this );
  

  // Old code - remove if everything works ok...
  // default_3dview_ = new Oinv_view( project_, this );
  // project_->add_view( default_3dview_ );
  
  setCentralWidget( default_3dview_ );
  

  // drag and drop
  setAcceptDrops( true );

  //----------------------
  // Temporary
  init_menu_bar();
  //----------------

}



void QSP_application::dragEnterEvent( QDragEnterEvent* event ) {
 // event->accept( QIconDrag::canDecode( event ) );
}
void QSP_application::dropEvent ( QDropEvent * ) {

}



//===============================

void QSP_application::init_menu_bar() {

  QMenu* file = menuBar()->addMenu(tr("&File"));
  file->addAction( "Open Project", this, SLOT( load_project() ), Qt::CTRL+Qt::Key_O );
  file->addAction( "Close Project", this, SLOT( close_project() ), Qt::CTRL+Qt::Key_W );
  file->addSeparator();
  file->addAction( "Save Project", this, SLOT( save_project() ), Qt::CTRL+Qt::Key_S );
  file->addAction( "Save Project As...", this, SLOT( save_project_as() ) );
  file->addSeparator();
  file->addAction( "Quit", this, SLOT(quit_slot()), Qt::CTRL+Qt::Key_Q );



  QMenu* objects = menuBar()->addMenu(tr("&Objects"));
  objects->addAction( "New Cartesian Grid", this, 
		                   SLOT( new_cartesian_grid() ), Qt::CTRL+Qt::Key_N );
  objects->addAction( "New Masked Grid From Cartesian Grid", this, 
		                   SLOT( new_mgrid_from_cgrid() ), Qt::CTRL+Qt::Key_M );
  objects->addAction( "Load Object", this, SLOT( load_object() ), Qt::CTRL+Qt::Key_L );
  objects->addSeparator();
  objects->addAction( "Save Object", this, SLOT( save_object() ) );
  objects->addSeparator();
  objects->addAction( "Delete Objects", this, SLOT( delete_geostat_objects() ) );
  objects->addAction( "Delete Properties", this, SLOT( delete_object_properties() ) );
  objects->addSeparator();
  objects->addAction( "Copy Property", this, SLOT( copy_property() ) );  
  objects->addSeparator();

  QMenu* definitions = objects->addMenu(tr("&Categorical Definition"));
  definitions->addAction( "New Categorical definition", this, SLOT( new_categorical_definition() ) );  
  definitions->addAction( "Show Categorical definition", this, SLOT( show_categorical_definition() ) );  
  definitions->addAction( "Assign Categorical definition", this, SLOT( assign_categorical_definition() ) );  

/*  Add a menu for regions operations
* Alexandre Boucher
*/
  QMenu* region =   menuBar()->addMenu( "&Regions" );
  region->addAction( "New region", this, SLOT( new_region_from_property() ), Qt::CTRL+Qt::Key_R );
  region->addAction( "Merge Regions", this, SLOT( merge_object_regions() ), Qt::CTRL+Qt::Key_M );
  region->addSeparator();
  region->addAction( "Delete Regions", this, SLOT( delete_object_regions() ), Qt::CTRL+Qt::Key_D );
  

 
  QMenu* data_analysis =   menuBar()->addMenu( "&Data Analysis" );
  data_analysis->addAction( "Histogram", this, SLOT(show_histogram_dialog() ), Qt::CTRL+Qt::Key_H );
  data_analysis->addSeparator();
  data_analysis->addAction( "QQ/PP -plot", this,
                             SLOT(show_qpplot_dialog() ) );
  data_analysis->addAction( "Scatter-plot", this,
                             SLOT(show_scatterplot_dialog() ) );
  data_analysis->addSeparator();
  data_analysis->addAction( "Variogram", this,
                             SLOT(show_variogram_analyser() ) );


  view_menu_ = menuBar()->addMenu( "&View" );

  view_menu_->addAction( "New 3D-Camera", this, SLOT(new_camera() ) );
  view_menu_->addSeparator();
  ap_ = view_menu_->addAction( "Algorithms Panel", this, SLOT(show_algo_panel() ), Qt::CTRL+Qt::Key_P);
  ap_->setCheckable(true);
  ap_->setChecked(true);
  cli_panel_id_ =
    view_menu_->addAction( "Commands Panel", this, SLOT(show_commands_panel() ) );
  cli_panel_id_->setCheckable(true);
  cli_panel_id_->setChecked(false);


  QMenu* scripts_menu = menuBar()->addMenu("&Scripts");
  scripts_menu->addAction( "Show Scripts Editor", this , SLOT(show_script_editor()) );
  scripts_menu->addAction( "Run Script...", this, SLOT(run_script() ) );



  QMenu* help_menu = menuBar()->addMenu("&Help");
  help_menu->addAction( "What's &This", this , SLOT(about_qt()), Qt::SHIFT+Qt::Key_F1);
  help_menu->addAction( "About SGeMS", this, SLOT(about_slot() ) );



#ifndef GSTLAPPLI_NDEBUG
  QMenu* debug_menu = menuBar()->addMenu("&Debug");
  debug_menu->addAction( "Save Scene-Graph", this, SLOT( save_scenegraph() ) );
  debug_menu->addAction( "Show managers", this, SLOT( list_managers() ), Qt::CTRL+Qt::Key_M );
  debug_menu->addAction( "Show Prop Values", this, SLOT(show_prop_val() ) );

#endif

}





//===============================

bool QSP_application::close_project() {
  if( !project_->has_changed() ) {
    project_->clear();
    return true;
  }

  switch( QMessageBox::information( this, "SGeMS",
                "The current project has been modified since last saved\n" 
                "Do you want to save the changes before exiting?",
                "&Save", "&Don't Save", "Cancel", 0, 2 ) ) {
    case 0:
      //save the changes
      save_project();
      break;

    case 1:
      // don't save
      break;

    case 2:
      // cancel
      return false;
  }

  project_->clear();
  return true;
}



void QSP_application::load_project() {
  if( !project_->is_empty() ) {
    bool ok = close_project();
    if( !ok ) return;
  }

  GsTLcout << "Loading project..." << gstlIO::end;

  QString start_dir = QString::null;
  if( !preferences_.last_load_directory.isEmpty() ) 
    start_dir = preferences_.last_load_directory;

  QDirDialog* fd = new QDirDialog( ".prj", start_dir, this, 
                                     "Load Project" );
  fd->setWindowTitle( "Load Project - select a directory" );

  // show the dialog
  if( fd->exec() == QDialog::Rejected ) return;

  QStringList L = fd->selectedFiles();
  QString dirname = L[0];
  
//  preferences_.project_name = dirname;

  // Save the path to the directory which contained the project. The directory
  // returned by the dialog is one level too low (ie it is the project 
  // directory, instead of the directory that contained the project directory) 
  QDir dialog_dir = fd->directory();
  QDir updir( dialog_dir );
  updir.cdUp();
  preferences_.last_load_directory = updir.absolutePath();


  QApplication::setOverrideCursor( Qt::WaitCursor );

  Error_messages_handler error_messages;
  std::string param( std::string(qstring2string(dirname)) );
  std::string command( "LoadProject" );

  bool ok = project_->execute( command, param, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
	  if( !error_messages.empty() )
      GsTLcerr << error_messages.errors() << "\n"; 
    GsTLcerr << gstlIO::end;
    QApplication::restoreOverrideCursor();
    return;
  }
/*
  // Descend into the selected directory
  QDir* dir = new QDir( dirname );
  if( !dir->cd( dirname ) ) {
    GsTLcerr << "Could not load project " << dirname << gstlIO::end;
    return;
  }


  // Load all the files in the current directory using the default filter
  Error_messages_handler error_messages;

  const QFileInfoList* files_info = 
    dir->entryInfoList( QDir::Files | QDir::NoSymLinks );
  QFileInfoListIterator it( *files_info );
  QFileInfo* f_info = 0;

  while( (f_info = it.current()) != 0 ) {
    QString abspath = f_info->absFilePath();
    std::string param( std::string( abspath.latin1() ) + 
                       Actions::separator + "s-gems" );
    bool ok = project_->execute( "LoadObjectFromFile", param, &error_messages );
    if( !ok ) 
      error_messages.report( "... this error occurred while loading \"" + 
                             std::string( f_info->fileName().latin1() ) +"\"" );

    ++it;
  }
  delete dir;  
  

  // output reported errors
  if( !error_messages.empty() ) {
    GsTLcerr << "Some of the objects could not be loaded:\n" 
             << error_messages.errors() << gstlIO::end;
  }
*/

  project_->reset_change_monitor();

  GsTLcout << "Ready" << gstlIO::end;
  QApplication::restoreOverrideCursor();
}



void QSP_application::save_project() {
  if( project_->name() != "" ) {
    //save_project( preferences_.project_name );
    save_project( QString( project_->name().c_str() ) );
  }
  else {
    save_project_as();
  }
}


void QSP_application::save_project_as() {
  QString start_dir = QString::null;
  if( !preferences_.last_save_directory.isEmpty() ) 
    start_dir = preferences_.last_save_directory;

  QDirDialog* fd = new QDirDialog( ".prj", start_dir, this, 
                                  "Save Project", QFileDialog::AnyFile );
  fd->setWindowTitle( "Save Project" );

  // show the dialog
  if( fd->exec() == QDialog::Rejected ) return;

//  QString dirname = fd->selectedFile();
  QStringList L = fd->selectedFiles();
  QString dirname = L[0];
  save_project( dirname );
}


void QSP_application::save_project( const QString& dirName ) {

  QString dirname = dirName;
  if( !dirname.endsWith( ".prj" ) && !dirname.endsWith( ".prj/" ) ) 
    dirname.append( ".prj" );

//  preferences_.project_name = dirname;
  project_->name( std::string( qstring2string(dirname) ) ); 
  QDir* dir = new QDir( dirname );

  // If the directory already exists, erase all the files. 
  // Possible improvements: currently all the files are erased sequentially, and
  // if erasing fails, the functions is aborted. But that results in a partially
  // deleted project, and no new project saved. A better solution would be to 
  // check beforehand that we will be able to erase all the files (not difficult
  // with QFileInfo).
  if( dir->exists( dirname ) ) {
    bool ok = dir->cd( dirname );
    QStringList files = dir->entryList( QDir::Files );
    for( QStringList::iterator it = files.begin(); it != files.end(); ++it ) {
      QString tmp = *it;
      if (dir->isRelativePath(*it))
	tmp = dir->filePath(*it);

      if( !dir->remove( tmp ) )
        GsTLcerr << "Project " << qstring2string(dirname) << " already exists and can not be "
                 << "overwritten" << gstlIO::end; 
    }
  }
  else {
    bool created = dir->mkdir( dirname );
    if( !created ) {
      GsTLcerr << "Could not create project " << qstring2string(dirname) << gstlIO::end;
      return;
    }
  }
  

  if( !dir->cd( dirname ) ) {
    GsTLcerr << "Could not create project " << qstring2string(dirname) << gstlIO::end;
    return;
  }
  dir->cdUp();
  preferences_.last_save_directory = dir->absolutePath();
  dir->cd( dirname );


  QApplication::setOverrideCursor( Qt::WaitCursor );

  // Save all objects in the current directory using the default filter
  Error_messages_handler error_messages;

  const GsTL_project::String_list& grids = project_->objects_list();
  typedef GsTL_project::String_list::const_iterator const_iterator;
  for( const_iterator it = grids.begin(); it != grids.end(); ++it ) {
    QString qabs_file_path = dir->absoluteFilePath( QString( it->c_str() ) );
    std::string abs_file_path( qstring2string(qabs_file_path) ); 
    std::string param( *it + Actions::separator + 
	              	     abs_file_path + Actions::separator +
		                   "sgems" );
    bool ok = project_->execute( "SaveGeostatGrid", param, &error_messages );
    if( !ok ) 
      error_messages.report( "... this error occurred while saving " + *it );
  }

  if( !error_messages.empty() ) {
    GsTLcerr << "Some of the objects could not be saved:\n" 
             << error_messages.errors() << gstlIO::end;
  }

  project_->reset_change_monitor();
  delete dir;

  GsTLcout << "Project saved" << gstlIO::end;
  QApplication::restoreOverrideCursor();
}



void QSP_application::load_object() {
  
  QFileDialog* fd = new QFileDialog( this, "Load Object");
  fd->setWindowTitle( "Load object - select a file" );

  // Set the filters for the file dialog
  QStringList filters_list;
  filters_list.push_back( "All (*)" );

  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( topLevelInputFilters_manager );
  Manager* dir = dynamic_cast<Manager*>( ni.raw_ptr() );
  appli_assert( dir );

  Manager::type_iterator begin = dir->begin();
  Manager::type_iterator end = dir->end();
  for( ; begin != end ; ++begin ) {
    SmartPtr<Named_interface> filter_ni = 
      Root::instance()->new_interface( *begin, topLevelInputFilters_manager + "/" );
    Input_filter* filter = 
      dynamic_cast<Input_filter*>( filter_ni.raw_ptr() );  
    appli_assert( filter );
    
    std::string filt_stl = *begin + " (" + filter->file_extensions() + ")";
    QString filter_name( filt_stl.c_str() );
    filters_list.push_back( filter_name ) ;
  }

  // Use the previous value entered by the user to initialize the dialog
  fd->setFilters( filters_list );
  if( !preferences_.last_input_filter.isEmpty() ) 
    fd->setFilter( preferences_.last_input_filter );

  if( !preferences_.last_load_directory.isEmpty() ) 
    fd->setDirectory( preferences_.last_load_directory );

  // show the dialog
  if( fd->exec() == QDialog::Rejected ) return;


  // gather the info input by the user
  QDir current_dir = fd->directory();
  preferences_.last_load_directory = current_dir.absolutePath();


  QString file_name, qfilter;
  
  QStringList L = fd->selectedFiles();
  file_name = L[0];
  
  qfilter = fd->selectedFilter();
  preferences_.last_input_filter = qfilter;
  std::string full_name( qstring2string(qfilter) );
  String_Op::string_pair filter_name = 
      String_Op::split_string( full_name, " (" );
  
  QApplication::setOverrideCursor( Qt::WaitCursor );
  appli_message( "Loading file " << qstring2string(file_name)
		<< " with filter \'" << filter_name.first << "\'" );

  Error_messages_handler error_messages;

  std::string param( std::string(qstring2string(file_name)) + Actions::separator
		     + filter_name.first );
  std::string command( "LoadObjectFromFile" );

  bool ok = project_->execute( command, param, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
	  if( !error_messages.empty() )
      GsTLcerr << error_messages.errors() << "\n"; 
    GsTLcerr << gstlIO::end;
  }

  QApplication::restoreOverrideCursor();
}




void QSP_application::save_object() {

  Save_grid_dialog* fd = new Save_grid_dialog( project_, this, "Save Grid" );
  fd->setWindowTitle( "Save object" );

  if( !preferences_.last_save_directory.isEmpty() ) 
    fd->setDirectory( preferences_.last_save_directory );

  if( fd->exec() == QDialog::Rejected ) return;
  
  QDir dir = fd->directory();
  preferences_.last_save_directory = dir.absolutePath();

  preferences_.last_output_filter = fd->selectedFilter();

  //TL modified
  const std::vector<QString> & p_list = fd->selected_p();

  std::string file_name, cluttered_filter_name, grid_name;
  QStringList L = fd->selectedFiles();
  file_name = qstring2string(L[0]);

  cluttered_filter_name = qstring2string(fd->selectedFilter());
  grid_name = qstring2string(fd->selected_grid());

  String_Op::string_pair filter_name = 
      String_Op::split_string( cluttered_filter_name, " (" );
  
  appli_message( "Saving grid " << grid_name << " to file " << file_name  
		<< " with filter \'" << filter_name.first << "\'" );

  QApplication::setOverrideCursor( Qt::WaitCursor );

  Error_messages_handler error_messages;

  std::string param( grid_name + Actions::separator + 
		     file_name + Actions::separator +
		     filter_name.first );

  //TL modified
  if (fd->maskToRegular())
	  param += Actions::separator+"1";
  else
	  param += Actions::separator+"0";
  for (std::vector<QString>::const_iterator it = p_list.begin(); it != p_list.end(); ++it)
    param += Actions::separator+qstring2string((*it));

  std::string command( "SaveGeostatGrid" );
  bool ok = project_->execute( command, param, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n" ;
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }

  QApplication::restoreOverrideCursor();
}



void QSP_application::new_cartesian_grid() {
  NewCartesianGridDialog* dialog = 
    new NewCartesianGridDialog( this, "New Cartesian Grid" );
  dialog->setWindowTitle( "Create new cartesian grid" );

  if( dialog->exec() == QDialog::Rejected ) return;

  std::string parameters = dialog->grid_parameters();
  Error_messages_handler error_messages;

  std::string command( "NewCartesianGrid" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
}



void QSP_application::show_algo_panel() {
  if( !dock_controls_->isVisible() ) {
    dock_controls_->show();
    ap_->setChecked(true);
  }
  else {
    dock_controls_->hide();
    ap_->setChecked(false);

  }
}

void QSP_application::show_commands_panel() {
  if( !dock_cli_->isVisible() ) {
    dock_cli_->show();
    cli_panel_id_->setChecked(true);
  }
  else {
    dock_cli_->hide();
    cli_panel_id_->setChecked(false);
  }
}


void QSP_application::show_algo_panel( bool on ) {
  if( on ) {
    //dock_controls_->show();

    ap_->setChecked(true);

  }
  else {
    //dock_controls_->hide();

    ap_->setChecked(false);    
  }
}

void QSP_application::show_commands_panel( bool on ) {
  if( on ) {
    //dock_cli_->show();
    cli_panel_id_->setChecked(true);

  }
  else {
    //dock_cli_->hide();
    cli_panel_id_->setChecked(false);    

  }
}



void QSP_application::list_managers() {
  std::cerr << std::endl << std::endl 
	    << "-----------------------------------" << std::endl;
  Root::instance()->list_all( std::cerr );
  std::cerr << std::endl;
}



void QSP_application::show_prop_val() {
  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( gridModels_manager );
  Manager* mng = dynamic_cast<Manager*>( ni.raw_ptr() );
  appli_assert( mng );

  Manager::interface_iterator begin = mng->begin_interfaces();
  Manager::interface_iterator end = mng->end_interfaces();
  for( ; begin != end ; ++begin ) {
    Geostat_grid* grid = dynamic_cast<Geostat_grid*>(  begin->raw_ptr() );
    appli_assert( grid != 0 );
    Geostat_grid::iterator it = grid->begin();
    Geostat_grid::iterator grid_end = grid->end();
    for( ; it != grid_end ; ++it ){
      std::cerr << it->property_value() << std::endl;
    }
  }
  
}


void QSP_application::save_scenegraph() {
  default_3dview_->save_scenegraph_to_file( "scene.iv" );
}



void QSP_application::show_histogram_dialog() {
  Histogram_gui* histogram_dialog = new Histogram_gui( project_,
                                                       0, "histogram_gui" );
  histogram_dialog->show();
}   

void QSP_application::show_qpplot_dialog() {
  QPplot_gui* dialog = 
      new QPplot_gui( project_,
                      0, "Bivariate_analysis_gui" );
  dialog->show();
}  

void QSP_application::show_scatterplot_dialog() {
  Scatterplot_gui* dialog = 
      new Scatterplot_gui( project_,
                           0, "Bivariate_analysis_gui" );
  dialog->show();
} 



void QSP_application::delete_geostat_objects() {
  Multichoice_dialog* dialog = new Multichoice_dialog( this, "Delete Dialog" );
  dialog->setWindowTitle( "Delete Objects" );
  dialog->set_okbutton_caption( "&Delete" );  
  
  const GsTL_project::String_list& grids = project_->objects_list();
  typedef GsTL_project::String_list::const_iterator const_iterator;
  for( const_iterator it = grids.begin(); it != grids.end(); ++it ) {
    dialog->add_choice_item( QString( it->c_str() ) );
  }
  if( dialog->exec() == QDialog::Rejected ) return;

  QStringList names = dialog->selected_items();
  delete_geostat_objects( names );
}


void QSP_application::delete_geostat_objects( const QStringList& names ) {
/*  SmartPtr<Named_interface> ni_dir =
    Root::instance()->interface( gridModels_manager );
  Manager* mng = dynamic_cast<Manager*>( ni_dir.raw_ptr() );
  appli_assert( mng );
  
  for( QStringList::const_iterator it = names.begin(); it != names.end(); ++it ) {
    std::string obj_name( (*it).latin1() );

    mng->delete_interface( "/" + obj_name );
    project_->deleted_object( obj_name );
  }
*/

  if( names.isEmpty() ) return;

  QApplication::setOverrideCursor( Qt::WaitCursor );

  QString sep = Actions::separator.c_str();
  std::string parameters = std::string( qstring2string(names.join( sep )) );
  if( parameters.empty() ) return;

  // call the DeleteObjectProperties action
  Error_messages_handler error_messages;

  std::string command( "DeleteObjects" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
  
  QApplication::restoreOverrideCursor();
}



void QSP_application::delete_object_properties() {
  Delete_properties_dialog* dialog = 
    new Delete_properties_dialog( project_, this, "Delete Dialog" );
  dialog->setWindowTitle( "Delete Object Properties" );
  if( dialog->exec() == QDialog::Rejected ) return;

  QStringList names = dialog->selected_items();
  QString grid_name = dialog->selected_grid();
  delete_object_properties( grid_name, names );
}



void QSP_application::delete_object_properties( const QString& qgrid_name,
                                                const QStringList& prop_names ) {
  if( qgrid_name.isEmpty() || prop_names.empty() ) return;
/*
  std::string grid_name( qgrid_name.latin1() );
  
  // get a pointer to the grid
  SmartPtr<Named_interface> grid_ni =
    Root::instance()->interface( gridModels_manager + "/" + grid_name );
  Geostat_grid* grid = dynamic_cast<Geostat_grid*>( grid_ni.raw_ptr() );
  appli_assert( grid );
  
  QStringList::const_iterator it = prop_names.begin(); 
  for( ; it != prop_names.end(); ++it ) {
    std::string prop_name( (*it).latin1() );
    grid->remove_property( prop_name );
  }

  project_->update();
*/

  QApplication::setOverrideCursor( Qt::WaitCursor );

  QString sep = Actions::separator.c_str();
  QStringList list( prop_names );
  list.prepend( qgrid_name );
  std::string parameters = std::string( qstring2string(list.join( sep )) );
  if( parameters.empty() ) return;

  // call the DeleteObjectProperties action
  Error_messages_handler error_messages;

  std::string command( "DeleteObjectProperties" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
  
  QApplication::restoreOverrideCursor();
  project_->update();

}


void QSP_application::copy_property() {
  Copy_property_dialog* dialog = 
    new Copy_property_dialog( project_, this, "Copy Properties" );
  dialog->setWindowTitle( "Copy property" );
/*
  if( dialog->exec() == QDialog::Rejected ) return;

  std::string parameters = dialog->parameters();
  Error_messages_handler error_messages;

  std::string command( "CopyProperty" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
*/  
  dialog->show();
}





void QSP_application::show_script_editor() {
  Script_editor* editor = new Script_editor( project_ );
  editor->show();
}

void QSP_application::run_script() {
  QString filename = 
    QFileDialog::getOpenFileName( this, "Select script file", QString(), "Python scripts(*.py);;All (*)");

  if( filename.isNull() ) return;

  // redirect stdout and stderr to sgems output zones
  PyRun_SimpleString(""
   "import redirect\n"
   "class CoutLogger:\n"
   "    def __init__(self):\n"
   "        self.buf = []\n"
   "    def write(self, data):\n"
   "        self.buf.append(data)\n"
   "        if data.endswith('\\n'):\n"
   "            redirect.sgems_cout(''.join(self.buf))\n"
   "            self.buf = []\n"
   "\n"
   "class CerrLogger:\n"
   "    def __init__(self):\n"
   "        self.buf = []\n"
   "    def write(self, data):\n"
   "        self.buf.append(data)\n"
   "        if data.endswith('\\n'):\n"
   "            redirect.sgems_cerr(''.join(self.buf))\n"
   "            self.buf = []\n"
   "\n"
   "import sys\n"
   "sys.stdout = CoutLogger()\n"
   "sys.stderr = CerrLogger()\n"
   "");
  
  FILE* fp = fopen( qstring2string(filename).c_str(), "r" );
  if( !fp ) {
    GsTLcerr << "can't open file " << qstring2string(filename) << gstlIO::end;
    return;
  }

	PyObject* module = PyImport_AddModule("__main__");
  	PyObject* dictionary = PyModule_GetDict(module);
  	PyObject* dictionary_copy = PyDict_Copy(dictionary);

  	PyRun_File(fp, filename.toAscii().constData(), Py_file_input, dictionary_copy, dictionary_copy);
  	Py_XDECREF(dictionary_copy);

//  QByteArray tmp = filename.toAscii();
//  PyRun_SimpleFile( fp, tmp.constData());
  fclose( fp );
}






QString generate_build_number() {
//  QString date_str = QString( "Sat " ) + QString( __DATE__ );
//  QDate date = QDate::fromString( date_str );
//  return date.toString( "yyyyMMdd" );
  return QString( __DATE__ );
}


About_sgems::About_sgems(QWidget * p) : QDialog(p)
{
  QVBoxLayout* _vlayout = new QVBoxLayout( );
  _vlayout->addStretch();
  setLayout(_vlayout);
  _pixmap.load( "new_splash2.png" );
  
}

void About_sgems::paintEvent(QPaintEvent *)
{
  QPainter painter( this);
  painter.setFont(QFont("Times", 10, QFont::Bold) );
  painter.drawPixmap(QPoint(0,0),_pixmap);
  
  std::ostringstream version;
  version << "v" << GEMS_VERSION_STR << "\nBuild " 
          << qstring2string(generate_build_number());
  
  painter.setPen( Qt::black );
  QRect r = rect();
  r.setRect( r.x() + 350, r.y() +20, r.width() - 20, r.height() - 20 );
  painter.drawText( r, Qt::AlignLeft, version.str().c_str() );
  
}

void QSP_application::about_slot() {

  About_sgems* about_screen = new About_sgems( this);
  about_screen->setModal(true);

  about_screen->resize( about_screen->picSize());
  about_screen->setMinimumSize( about_screen->size() );
  about_screen->setMaximumSize( about_screen->size() );

  
  QHBoxLayout* button_layout = new QHBoxLayout( about_screen );
  QPushButton* close = new QPushButton( "&Close", about_screen);
  close->setSizePolicy( QSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed ) );
  button_layout->addStretch();
  button_layout->addWidget( close );
  button_layout->addStretch();
 
  about_screen->layout()->addItem( button_layout );

  QVBoxLayout * v = (QVBoxLayout*)about_screen->layout();
  v->addSpacing( 12 );
  
  QObject::connect( close, SIGNAL( clicked() ),
                    about_screen, SLOT( reject() ) );
  about_screen->exec();
}


void QSP_application::quit_slot() {
  if( project_->has_changed() ) {
    switch( QMessageBox::information( this, "SGeMS",
                          "The current project has been modified since last saved\n" 
                          "Do you want to save the changes before exiting?",
                          "&Save", "&Don't Save", "Cancel", 0, 2 ) ) {
    case 0:
      //save the changes
      save_project();
      break;

    case 1:
      // don't save, and exit
      break;

    case 2:
      // don't exit
      return;
    }
  }

  save_app_preferences();
  qApp->quit();
}


void QSP_application::save_app_preferences() {
  QSettings settings( "scrf.stanford.edu", "sgems" );

  // geometry
  int h = this->height();
  int w = this->width();
  settings.setValue( "/geometry/height", h );
  settings.setValue( "/geometry/width", w );

  // which panels are on?
  bool show_algo = dock_controls_->isVisible();
  bool show_cli = dock_cli_->isVisible();
  settings.setValue("/panels/algo", show_algo );
  settings.setValue("/panels/cli", show_cli );
}


void QSP_application::show_variogram_analyser() {
  Variogram_modeler_gui* p = new Variogram_modeler_gui( project_, 0 );
  p->show();
}




void QSP_application::new_camera() {
  // create a new view of the project 
//  std::string view_name( "camera" );
//  view_name.append( String_Op::to_string( additional_views_.size() + 1 ) );
  SmartPtr<Named_interface> view_ni = 
    Root::instance()->new_interface( "oinv_view", 
                                     projectViews_manager + "/"  );
  Oinv_view* new_view = dynamic_cast<Oinv_view*>( view_ni.raw_ptr() );
  appli_assert( new_view );
  new_view->initialize( project_, 0 );
  new_view->unref_no_delete();
//  additional_views_.push_back( new_view );

  
  const int offset = 30;
  int x = this->x() + offset;
  int y = this->y() + offset;
  new_view->setGeometry( x, y, 
                         default_3dview_->width(), default_3dview_->height() );

  new_view->show();
}




void QSP_application::closeEvent( QCloseEvent* e ) {
  quit_slot();
  e->ignore();
}





void QSP_application::delete_object_regions() {
  Delete_regions_dialog* dialog = 
    new Delete_regions_dialog( project_, this, "Delete Dialog" );
  dialog->setWindowTitle( "Delete Object Regions" );
  if( dialog->exec() == QDialog::Rejected ) return;

  QStringList names = dialog->selected_items();
  QString grid_name = dialog->selected_grid();
  delete_object_regions( grid_name, names );
}



void QSP_application::delete_object_regions( const QString& qgrid_name,
                                                const QStringList& region_names ) {
  if( qgrid_name.isEmpty() || region_names.empty() ) return;


  QApplication::setOverrideCursor( Qt::WaitCursor );

  QString sep = Actions::separator.c_str();
  QStringList list( region_names );
  list.prepend( qgrid_name );
  std::string parameters = std::string( qstring2string(list.join( sep )) );
  if( parameters.empty() ) return;

  // call the DeleteObjectProperties action
  Error_messages_handler error_messages;

  std::string command( "DeleteObjectRegions" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
  
  QApplication::restoreOverrideCursor();
  project_->update();

}




void QSP_application::merge_object_regions() {
  Merge_regions_dialog* dialog = 
    new Merge_regions_dialog( project_, this, "Merge Dialog" );
  dialog->setWindowTitle( "Merge Object Regions" );
  if( dialog->exec() == QDialog::Rejected ) return;

  QStringList names = dialog->selected_items();
  QString grid_name = dialog->selected_grid();
  QString new_region_name = dialog->new_region_name();
  merge_object_regions( grid_name, new_region_name, names, dialog->is_union() );
}



void QSP_application::merge_object_regions( const QString& qgrid_name,
                                           const QString& new_region_name,
                                           const QStringList& region_names,
                                           bool is_union) {
  if( qgrid_name.isEmpty() || region_names.empty() || new_region_name.isEmpty()) return;


  QApplication::setOverrideCursor( Qt::WaitCursor );

  QString sep = Actions::separator.c_str();
  QStringList list( region_names );
  list.prepend(new_region_name);
  list.prepend( qgrid_name );
  std::string parameters = std::string( qstring2string(list.join( sep )) );
  if( parameters.empty() ) return;

  // call the DeleteObjectProperties action
  Error_messages_handler error_messages;

  std::string command;
  if( is_union ) command = "MergeObjectRegionsUnion";
  else command = "MergeObjectRegionsIntersection";

  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
  
  QApplication::restoreOverrideCursor();
  project_->update();

}

void QSP_application::show_categorical_definition(){
  View_category_definition_dialog* dialog = 
    new View_category_definition_dialog( project_, this, "Categorical Definition Dialog" );
  dialog->setWindowTitle( "View Categorical Definition" );
  if( dialog->exec() == QDialog::Rejected ) return;
}


void QSP_application::new_categorical_definition(){
  New_category_definition_dialog* dialog = 
    new New_category_definition_dialog( project_, this, "New Categorical Definition Dialog" );
  dialog->setWindowTitle( "New Categorical Definition" );
  if( dialog->exec() == QDialog::Rejected ) return;
}


void QSP_application::assign_categorical_definition(){
  Assign_category_definition_dialog* dialog = 
    new Assign_category_definition_dialog( project_, this, "Assign Categorical Definition Dialog" );
  dialog->setWindowTitle( "Assign Categorical Definition" );
  if( dialog->exec() == QDialog::Rejected ) return;
}

void QSP_application::new_region_from_property(){
  New_region_from_property_dialog* dialog = 
    new New_region_from_property_dialog( project_, this, "Create region from property" );
  dialog->setWindowTitle( "Create New Region" );
  dialog->exec();
  delete dialog;
  //if( dialog->exec() == QDialog::Rejected ) return;
//  delete
/*
  QString grid_name = dialog->selected_grid();
  QString new_region_name = dialog->new_region_name();
  QString prop_name = dialog->selected_property();

  QStringList minmax;
  minmax.append( dialog->get_min_filter_value() );
  minmax.append( dialog->get_max_filter_value() );


  new_region_from_property( grid_name, new_region_name, prop_name, minmax );
  */
}

/*
void QSP_application::new_region_from_property( const QString& qgrid_name,
                             const QString& new_region_name,               
                             const QString& prop_name,
                             const QStringList& thresholds ){
  if( qgrid_name.isEmpty() || new_region_name.isEmpty() || prop_name.isEmpty()) return;
  if( thresholds.size() != 2 ) return;


  QApplication::setOverrideCursor( Qt::WaitCursor );

  QString sep = Actions::separator.c_str();
  QStringList list;
  list.append( qgrid_name );
  list.append(new_region_name);
  list.append( prop_name );
  list.append( thresholds[0] );
  list.append( thresholds[1] );
  std::string parameters = std::string( qstring2string(list.join( sep )) );
  if( parameters.empty() ) return;

  // call the DeleteObjectProperties action
  Error_messages_handler error_messages;

  std::string command( "SetRegionFromPropertyIf" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
  
  QApplication::restoreOverrideCursor();
  project_->update();


}
*/
//==========================================================

void QSP_application::new_mgrid_from_cgrid() {
  New_mgrid_from_cgrid_dialog* dialog = 
    new New_mgrid_from_cgrid_dialog( project_, this, "Create masked grid from cartesian grid" );
  dialog->setWindowTitle( "Create New Masked Grid" );
  if( dialog->exec() == QDialog::Rejected ) return;

  QString grid_name = dialog->selected_grid();
  QString new_mgrid_name = dialog->new_mgrid_name();
  QStringList regions_name = dialog->selected_regions();


  new_mgrid_from_cgrid( grid_name, regions_name, new_mgrid_name );
}


void QSP_application::new_mgrid_from_cgrid(const QString& cgrid_name,
                             const QStringList& region_names,
                             const QString& new_mgrid_name) {

  if( cgrid_name.isEmpty() || region_names.isEmpty() || new_mgrid_name.isEmpty()) return;
  
  QApplication::setOverrideCursor( Qt::WaitCursor );

  QString sep = Actions::separator.c_str();
  QStringList list;
  list.append( cgrid_name );
  list.append( new_mgrid_name );
  list.append( region_names );
  
  std::string parameters = std::string( qstring2string(list.join( sep )) );
  if( parameters.empty() ) return;

  // call the CreateMgridFromCgrid action
  Error_messages_handler error_messages;

  std::string command( "CreateMgridFromCgrid" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }
  
  QApplication::restoreOverrideCursor();
  project_->update();

}


//==========================================================

Save_grid_dialog::Save_grid_dialog( const GsTL_project* project,
				    QWidget * parent, const char * name) 
  : QFileDialog( parent ) {

  if (name)
    setObjectName(name);
  
  setModal(true);
  setFileMode( QFileDialog::AnyFile );
  setLabelText(QFileDialog::Accept, "Save");

  QGridLayout * lo = dynamic_cast<QGridLayout*>(this->layout());
  
  grid_selector_ = new QComboBox( this);
  QLabel* label = new QLabel( "Grid to save", this );
  lo->addWidget(label, 4,0,Qt::AlignLeft);
  lo->addWidget(grid_selector_,4,1,Qt::AlignLeft);



  //TL modified
  _propList = new QListWidget( this);
  _propList->setSelectionMode(QAbstractItemView::ExtendedSelection);
  QLabel* plabel = new QLabel( "Properties to save", this );
  lo->addWidget(plabel, 5,0,Qt::AlignLeft);
  lo->addWidget(_propList,5,1,Qt::AlignLeft);




  //TL modified
  _saveRegular = new QCheckBox(this);
  _saveRegular->setDisabled(true);
  QLabel* slabel = new QLabel( "Save masked grid as Cartesian", this );
  lo->addWidget(slabel, 6,0,Qt::AlignLeft);
  lo->addWidget(_saveRegular,6,1,Qt::AlignLeft);
  
  // search for available output filters

  QStringList filters;
  SmartPtr<Named_interface> ni_filter = 
    Root::instance()->interface( outfilters_manager );
  Manager* dir = dynamic_cast<Manager*>( ni_filter.raw_ptr() );
  appli_assert( dir );

  Manager::type_iterator begin = dir->begin();
  Manager::type_iterator end = dir->end();
  for( ; begin != end ; ++begin ) {
    QString filt( begin->c_str() );
    filt += " (*.*)";
    filters.push_back( filt ) ;
  }

  setFilters( filters );

  
  // search for available grids

  const GsTL_project::String_list& grids = project->objects_list();
  typedef GsTL_project::String_list::const_iterator const_iterator;
  for( const_iterator it = grids.begin(); it != grids.end(); ++it ) {
    grid_selector_->addItem( it->c_str() );
  }

  QObject::connect( grid_selector_, SIGNAL( activated(const QString &) ),
	  this, SLOT( gridChanged(const QString &) ) );

  if (!grid_selector_->currentText().isEmpty())
	gridChanged(grid_selector_->currentText());
}


void Save_grid_dialog::gridChanged(const QString & s)
{
	SmartPtr<Named_interface> grid_ni =
	  Root::instance()->interface( gridModels_manager + "/" + qstring2string(s) );
	Geostat_grid* grid = dynamic_cast<Geostat_grid*>( grid_ni.raw_ptr() );
	appli_assert( grid );

    std::list<std::string> pn = grid->property_list();
	_propList->clear();
	for (std::list<std::string>::iterator it = pn.begin(); it != pn.end(); ++it){
	        QListWidgetItem * nitem = new QListWidgetItem(it->c_str(), _propList);
		_propList->addItem(nitem);
		nitem->setSelected(true);
	}

	if (dynamic_cast<Reduced_grid*>(grid))
		_saveRegular->setDisabled(false);
	else
		_saveRegular->setDisabled(true);
}

QString Save_grid_dialog::selected_grid() const {
  return grid_selector_->currentText();
}


void Save_grid_dialog::accept() { 

  _selected.clear();
  for (int i = 0; i < _propList->count(); ++i)
    if (_propList->item(i)->isSelected())
      _selected.push_back(_propList->item(i)->text());

  if( grid_selector_->currentText().isEmpty() ) {
    QMessageBox::warning( this, "No Grid Selected",
			  " You must specify a grid to save" );
	done(Rejected);
  }
  if (_selected.empty())
    QMessageBox::warning( this, "No Properties Selected",
			  " WARNING! Saving empty grid" );
  
  done(Accepted);
}



//=========================================


Copy_property_dialog::
Copy_property_dialog( GsTL_project* proj,
                     QWidget* parent, const char* name ) 
                     : QDialog( parent ) {
  project_ = proj;

  if (name)
    setObjectName(name);
  
  QVBoxLayout* main_layout = new QVBoxLayout( this);
  main_layout->setMargin(9);
  main_layout->setSpacing(-1);
  
  QGroupBox* source_box = new QGroupBox( this);
  QGroupBox* dest_box = new QGroupBox( this);
  QGroupBox* options_box = new QGroupBox( this );

  QVBoxLayout * vs, * vd, * vo;
  vs = new QVBoxLayout(source_box);
  vd = new QVBoxLayout(dest_box);
  vo = new QVBoxLayout(options_box);
  
  source_box->setLayout(vs);
  dest_box->setLayout(vd);
  options_box->setLayout(vo);

  vs->addWidget(new QLabel( "Copy property from object:", source_box ));
  source_ = new GridSelectorBasic( source_box, "source", proj );
  vs->addWidget(source_);
  vs->addWidget(new QLabel( "Select property to copy:", source_box ));
  source_property_ = new SinglePropertySelector( source_box, "source_prop" );
  vs->addWidget(source_property_);

  vd->addWidget(new QLabel( "Copy to object:", dest_box ));
  destination_ = new GridSelectorBasic( dest_box, "dest", proj );
  vd->addWidget(destination_);
  vd->addWidget(new QLabel( "Select or type-in a destination\nproperty name", dest_box ));
  destination_property_ = new SinglePropertySelector( dest_box, "dest_prop" );
  vd->addWidget(destination_property_);
//  destination_property_ = new QComboBox( dest_box, "dest_prop" );
  destination_property_->setEditable( true );

  overwrite_ = new QCheckBox( "Overwrite", options_box );
  vo->addWidget(overwrite_);
  mark_as_hard_ = new QCheckBox( "Mark as Hard Data", options_box );
  vo->addWidget(mark_as_hard_);
  
  QHBoxLayout* bottom_layout = new QHBoxLayout( this);
  bottom_layout->setSpacing(9);
  QPushButton* ok = new QPushButton( "Copy", this);  
  QPushButton* cancel = new QPushButton( "Close", this);
  bottom_layout->addStretch();
  bottom_layout->addWidget( ok );
  bottom_layout->addWidget( cancel );

  main_layout->addWidget( source_box );
  main_layout->addStretch();
  main_layout->addWidget( dest_box );
  main_layout->addStretch();
  main_layout->addWidget( options_box );
  main_layout->addStretch();
  main_layout->addLayout( bottom_layout );

  
  QObject::connect( source_, SIGNAL( activated( const QString& ) ),
                    source_property_, SLOT( show_properties( const QString& ) ) );
  QObject::connect( destination_, SIGNAL( activated( const QString& ) ),
                    destination_property_, SLOT( show_properties( const QString& ) ) );
/*
  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( reject() ) );
*/
  QObject::connect( ok, SIGNAL( clicked() ),
                    this, SLOT( copy_property() ) );
  QObject::connect( cancel, SIGNAL( clicked() ),
                    this, SLOT( accept() ) );

  setSizeGripEnabled( true );
}


std::string Copy_property_dialog::parameters() const {
  QString overwrite_str;
  overwrite_str.setNum( overwrite_->isChecked() );
  QString mark_hard_str;
  mark_hard_str.setNum( mark_as_hard_->isChecked() );

  QString sep = Actions::separator.c_str();
  QStringList list;
  list << source_->currentText()
       << source_property_->currentText() 
       << destination_->currentText() 
       << destination_property_->currentText() 
       << overwrite_str << mark_hard_str;
  
  QString res = list.join( sep );
  if( res.isEmpty() ) return std::string( "" );

  return std::string( qstring2string(res) );
}

void Copy_property_dialog::copy_property() {
  if( !project_ ) return;

  QString overwrite_str;
  overwrite_str.setNum( overwrite_->isChecked() );
  QString mark_hard_str;
  mark_hard_str.setNum( mark_as_hard_->isChecked() );

  QString sep = Actions::separator.c_str();
  QStringList list;
  list << source_->currentText()
       << source_property_->currentText() 
       << destination_->currentText() 
       << destination_property_->currentText() 
       << overwrite_str << mark_hard_str;
  
  std::string parameters = std::string( qstring2string(list.join( sep )) );
  if( parameters.empty() ) return;


  QApplication::setOverrideCursor( Qt::WaitCursor );
 
  // call the CopyProperty action
  Error_messages_handler error_messages;

  std::string command( "CopyProperty" );
  bool ok = project_->execute( command, parameters, &error_messages );

  if( !ok ) {
    GsTLcerr << "Command " << command << " could not be performed. \n";
    if( !error_messages.empty() ) {
      GsTLcerr << error_messages.errors();
    }
    GsTLcerr << gstlIO::end;
  }

  QApplication::restoreOverrideCursor();
}


QString Copy_property_dialog::source() const { 
  return source_->currentText(); 
}
QString Copy_property_dialog::source_property() const { 
  return source_property_->currentText();
}
QString Copy_property_dialog::destination() const { 
  return destination_->currentText(); 
}
QString Copy_property_dialog::destination_property() const { 
  return destination_property_->currentText(); 
}
bool Copy_property_dialog::overwrite() const { 
  return overwrite_->isChecked(); 
}
bool Copy_property_dialog::mark_as_hard() const { 
  return mark_as_hard_->isChecked(); 
}
