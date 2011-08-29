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
/*
#ifdef _DEBUG
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif
*/

#include <Python.h>

#include <GsTLAppli/gui/utils/script_editor.h>
#include <GsTLAppli/gui/utils/script_syntax_highlighter.h>
#include <GsTLAppli/actions/python_wrapper.h>
#include <GsTLAppli/actions/python_commands.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/utils/error_messages_handler.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/gui/utils/qtbased_scribes.h>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/appli/manager_repository.h>

#include <qtextedit.h>
#include <qsplitter.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qpixmap.h>
#include <QAction>
#include <QMenu>
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qstatusbar.h>
#include <qfiledialog.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qevent.h>
#include <qmessagebox.h>
#include <qapplication.h>
#include <qcursor.h>
#include <qspinbox.h>
#include <qinputdialog.h>
//Added by qt3to4:
#include <QCloseEvent>
#include <QVBoxLayout>
#include <iostream>



//===========================================
//  Some embedded images

static const char* const image0_data[] = {
"22 22 7 1",
". c None",
"# c #000000",
"b c #2e2e2e",
"c c #5c5c5c",
"d c #878787",
"e c #c2c2c2",
"a c #ffffff",
"......................",
"....##########........",
"....#aaaaaaa#b#.......",
"....#aaaaaaa#cb#......",
"....#aaaaaaa#dcb#.....",
"....#aaaaaaa#edcb#....",
"....#aaaaaaa#aedcb#...",
"....#aaaaaaa#######...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....#aaaaaaaaaaaaa#...",
"....###############...",
"......................",
"......................"};

static const char* const image1_data[] = {
"22 22 5 1", 
". c None",
"# c #000000",
"c c #848200",
"a c #ffff00",
"b c #ffffff",
"......................",
"......................",
"......................",
"............####....#.",
"...........#....##.##.",
"..................###.",
".................####.",
".####...........#####.",
"#abab##########.......",
"#babababababab#.......",
"#ababababababa#.......",
"#babababababab#.......",
"#ababab###############",
"#babab##cccccccccccc##",
"#abab##cccccccccccc##.",
"#bab##cccccccccccc##..",
"#ab##cccccccccccc##...",
"#b##cccccccccccc##....",
"###cccccccccccc##.....",
"##cccccccccccc##......",
"###############.......",
"......................"};


static const char* const image2_data[] = {
"22 22 5 1",
". c None",
"# c #000000",
"a c #848200",
"b c #c1c1c1",
"c c #cab5d1",
"......................",
".####################.",
".#aa#bbbbbbbbbbbb#bb#.",
".#aa#bbbbbbbbbbbb#bb#.",
".#aa#bbbbbbbbbcbb####.",
".#aa#bbbccbbbbbbb#aa#.",
".#aa#bbbccbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aa#bbbbbbbbbbbb#aa#.",
".#aaa############aaa#.",
".#aaaaaaaaaaaaaaaaaa#.",
".#aaaaaaaaaaaaaaaaaa#.",
".#aaa#############aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
".#aaa#########bbb#aa#.",
"..##################..",
"......................"};


static const char* const image4_data[] = {
"22 22 3 1",
". c None",
"# c #000084",
"a c #848284",
"......................",
"......................",
"......................",
"......................",
"......................",
"...........######a....",
"..#......##########...",
"..##...####......##a..",
"..###.###.........##..",
"..######..........##..",
"..#####...........##..",
"..######..........##..",
"..#######.........##..",
"..########.......##a..",
"...............a###...",
"...............###....",
"......................",
"......................",
"......................",
"......................",
"......................",
"......................"};

static const char* const image5_data[] = {
"22 22 3 1",
". c None",
"a c #000084",
"# c #848284",
"......................",
"......................",
"......................",
"......................",
"......................",
"....#aaaaaa...........",
"...aaaaaaaaaa......a..",
"..#aa......aaaa...aa..",
"..aa.........aaa.aaa..",
"..aa..........aaaaaa..",
"..aa...........aaaaa..",
"..aa..........aaaaaa..",
"..aa.........aaaaaaa..",
"..#aa.......aaaaaaaa..",
"...aaa#...............",
"....aaa...............",
"......................",
"......................",
"......................",
"......................",
"......................",
"......................"};


static const char* const image6_data[] = {
"22 22 3 1",
". c None",
"# c #000000",
"a c #000082",
"......................",
".......#.....#........",
".......#.....#........",
".......#.....#........",
".......#....##........",
".......##...#.........",
"........#...#.........",
"........##.##.........",
".........###..........",
".........###..........",
"..........#...........",
".........a#a..........",
"........aa.aaa........",
".......a.a.a..a.......",
"......a..a.a...a......",
".....a...a.a....a.....",
"....a....a.a....a.....",
"....a....a..a...a.....",
"....a....a..a..a......",
"....a...a....aa.......",
".....aaa..............",
"......................"};

static const char* const image7_data[] = {
"22 22 6 1",
". c None",
"# c #000000",
"b c #000082",
"c c #3c3cfd",
"d c #8b8bfd",
"a c #ffffff",
"......................",
"......................",
"########..............",
"#aaaaaa##.............",
"#a####a#a#............",
"#aaaaaa#aa#...........",
"#a####a#bbbbbbbb......",
"#aaaaaa#baaaaaabb.....",
"#a#####aba####abcb....",
"#aaaaaaabaaaaaabdcb...",
"#a#####aba####abadcb..",
"#aaaaaaabaaaaaabbbbbb.",
"#a#####aba####aaaaaab.",
"#aaaaaaabaaaaaaaaaaab.",
"#a#####aba#########ab.",
"#aaaaaaabaaaaaaaaaaab.",
"########ba#########ab.",
"........baaaaaaaaaaab.",
"........ba#########ab.",
"........baaaaaaaaaaab.",
"........bbbbbbbbbbbbb.",
"......................"};

static const char* const image8_data[] = {
"22 22 8 1",
". c None",
"# c #000000",
"e c #000084",
"c c #848200",
"b c #848284",
"d c #c6c3c6",
"a c #ffff00",
"f c #ffffff",
"......................",
".......#####..........",
"..######aaa######.....",
".######aaaaa######....",
"##bcb##a###a##bcb##...",
"#bcb#ddddddddd#bcb#...",
"#cbc#ddddddddd#cbc#...",
"#bcb###########bcb#...",
"#cbcbcbcbcbcbcbcbc#...",
"#bcbcbcbcbcbcbcbcb#...",
"#cbcbcbceeeeeeeeee#...",
"#bcbcbcbefffffffefe...",
"#cbcbcbcefeeeeefeffe..",
"#bcbcbcbefffffffefffe.",
"#cbcbcbcefeeeeefeffffe",
"#bcbcbcbefffffffeeeeee",
"#cbcbcbcefeeeeeffffffe",
"#bcbcbcbeffffffffffffe",
"#cbcbcbcefeeeeeeeeeefe",
".#######effffffffffffe",
"........eeeeeeeeeeeeee",
"......................"};



//========================================================


Script_editor::Script_editor( GsTL_project* project, 
                              QWidget* parent, const char* name )
  : QMainWindow( parent, Qt::Window),
  project_( 0 ) { 
  
  setWindowTitle( "SGeMS Script Editor" );

  project_ = project;
  filename_ = "";
  accept_close_ = true;

  if (name)
    setObjectName(name);
  
  //-----------------------------

  QFrame* main_widget = new QFrame( this );
  QVBoxLayout* main_layout = new QVBoxLayout(  );
  main_widget->setLayout(main_layout);
  
  QSplitter* split = new QSplitter( Qt::Vertical, main_widget);
  
  script_in_ = new QTextEdit( split);
  split->addWidget(script_in_);
  script_in_->setFont( QFont( "Courier", 10, QFont::Normal ) );
  script_in_->setTabStopWidth( 40 );
  script_in_->setUndoRedoEnabled( true );

  
  QFrame* bottom_frame = new QFrame( split );
  split->addWidget(bottom_frame);
  
  QVBoxLayout* bottom_layout = new QVBoxLayout( bottom_frame );
  bottom_frame->setLayout(bottom_layout);
  script_out_ = new QTextEdit( bottom_frame);
  
  script_out_->setReadOnly( true );
  QLabel* label = new QLabel( "Script Output Messages", bottom_frame );
  bottom_layout->addSpacing( 10 );
  bottom_layout->addWidget( label );
  bottom_layout->addWidget( script_out_ );

  QList<int> splitter_sizes;
  splitter_sizes << 400 << 200;
  split->setSizes( splitter_sizes );


  QPushButton* run_button = new QPushButton( "Run", main_widget );

  main_layout->addWidget( split );
  main_layout->addSpacing( 8 );
  main_layout->addWidget( run_button );

  QObject::connect( run_button, SIGNAL( clicked() ),
                    this, SLOT( run_script() ) );

  menu_setup();
  setCentralWidget( main_widget );
  statusBar()->showMessage( "Ready", 2000 );
  resize( 450, 600 );

  new Script_syntax_highlighter( script_in_ );

  script_messages_scribe_ = 
    SmartPtr<QTextedit_scribe>( new QTextedit_scribe( script_out_ ) );
  script_messages_scribe_->subscribe( *GsTLAppli_Python_cout::instance() );
  script_errors_scribe_ = 
    SmartPtr<QTextedit_scribe>( new QTextedit_scribe( script_out_, "red" ) );
  script_errors_scribe_->subscribe( *GsTLAppli_Python_cerr::instance() );


  if( !project_ ) {
    run_button->hide();
    bottom_frame->hide();
  }

  //initialize Python project
  Python_project_wrapper::set_project( project_ );
} 



Script_editor::~Script_editor() {
  script_messages_scribe_->unsubscribe( *GsTLAppli_Python_cout::instance() );
  script_errors_scribe_->unsubscribe( *GsTLAppli_Python_cerr::instance() );

  appli_message( "script editor deleted" );
}



void Script_editor::new_script() {
  script_in_->clear();
  filename_ = "";
}

void Script_editor::load_script() {
  QString fn =
    QFileDialog::getOpenFileName( this, QString(), QString(), "Python scripts (*.py);;All (*)" );
  if( fn.isEmpty() ) {
    statusBar()->showMessage( "Loading aborted", 2000 );
    return;
  }

  
  script_in_->clear();
  
  QFile file( fn );
  if ( !file.open( QIODevice::ReadOnly ) ) return;

  
  filename_ = fn;
  QTextStream stream( &file );
  script_in_->setText( stream.readAll() );


  setWindowTitle( filename_ );
  
  QString s;
  string tmp = String_Op::qstring2string(filename_);
  s.sprintf( "Loaded document %s",  tmp.c_str());

  statusBar()->showMessage( s, 2000 );

}


void Script_editor::save_script() {
  if ( filename_.isEmpty() ) {
    save_script_as();
    return;
  }

  QFile file( filename_ ); // Write the text to a file
  if( !file.open( QIODevice::WriteOnly ) ) return;

  QTextStream stream( &file );
  stream << script_in_->toPlainText();
  script_in_->document()->setModified( FALSE );
  
  setWindowTitle( filename_ );
  statusBar()->showMessage( QString( "File %1 saved" ).arg( filename_ ), 2000 );
}


void Script_editor::save_script_as() {
  QString fn = 
    QFileDialog::getSaveFileName( this);
  if ( !fn.isEmpty() ) {
    filename_ = fn;
    save_script();
  } 
  else {
    statusBar()->showMessage( "Saving aborted", 2000 );
  }
}
  



// Runs a Python script
void Script_editor::run_script() {
  script_out_->clear();
  QApplication::setOverrideCursor( QCursor(Qt::WaitCursor) );

  PyRun_SimpleString(""
   "import redirect     # a module interface created by C application\n"
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
  QString q_script_text = script_in_->toPlainText();
  q_script_text += "\n";
  std::string script_text( String_Op::qstring2string(q_script_text) );
   
  PyRun_SimpleString( (char*) script_text.c_str() );

  if( Python_project_wrapper::is_project_modified() ) {
    Python_project_wrapper::project()->update();
  }

  QApplication::restoreOverrideCursor();

}

  
void Script_editor::close_slot() {
  this->close(  );
}

void Script_editor::closeEvent( QCloseEvent* e ) {

  if( script_in_->document()->isModified() ) {
    switch( QMessageBox::information( this, "SGeMS",
                  "The current script has been modified since last saved\n" 
                  "Do you want to save the changes before exiting?",
				  QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel ) ) {
	case QMessageBox::Save :
      //save the changes
      save_script();
      break;

	case QMessageBox::Discard :
      // don't save, and exit
		//std::cout << "discard" << std::endl;
		e->accept();

      return;

	case QMessageBox::Cancel :
      // don't exit
      accept_close_ = false;
	  //std::cout << " cancel" << std::endl;
	  e->ignore();
      return;
    }
  }
  
  if( accept_close_ ) 
    e->accept();
  else {
    accept_close_ = true;
    e->ignore();
  }
}



QString Script_editor::find_tmp_filename( const QString& filename ) {
  QString tmp_base_filename = filename + ".sgems_tmp";
  QFile file( tmp_base_filename );
  if( !file.exists() ) return tmp_base_filename ;

  int id = 0;
  do {
    QString id_str;
    id_str.setNum( id );
    file.setFileName( tmp_base_filename + id_str );
    ++id;
  }
  while( file.exists() );

  return file.fileName();
}


void Script_editor::go_to_line() {
  bool ok ;
  int res = QInputDialog::getInteger(this, "GotoLine", "Enter the line to go:",
                                     0,0, script_in_->document()->blockCount(), 1,&ok);

  // revisit - TL
  /*
  if(ok) {
    script_in_->setCursorPosition(res-1,0) ;
  }
  */
}


void Script_editor::set_point_size( int s ) {
  script_in_->selectAll();
  script_in_->setFontPointSize( s );
  script_in_->selectAll();
  script_in_->setFontPointSize( s );
}


void Script_editor::menu_setup() {

  QAction *fileNewAction, *fileOpenAction, *fileSaveAction, *fileSaveAsAction, *fileQuitAction,
    *editUndoAction, *editRedoAction, *editCutAction, *editCopyAction, *editPasteAction,
    *editGoToLine, *runScriptAction;


  //-------------------
  // file actions

  fileNewAction = new QAction(QIcon(QPixmap( (const char **) image0_data )),
			      "&New Script", this);
  fileNewAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_N));
  connect( fileNewAction, SIGNAL( activated() ) , this, SLOT( new_script() ) );

  fileOpenAction = new QAction( QIcon(QPixmap( (const char **) image1_data )), 
				"&Open file", this);
  fileOpenAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_O));
  connect( fileOpenAction, SIGNAL( activated() ) , this, SLOT( load_script() ) );

  fileSaveAction = new QAction(QIcon(QPixmap( (const char **) image2_data )),
			       "&Save File", this);
  fileSaveAction->setShortcut(QKeySequence( Qt::CTRL+Qt::Key_S));
  connect( fileSaveAction, SIGNAL( activated() ) , this, SLOT( save_script() ) );


  fileSaveAsAction = new QAction("&Save File As", this);
  connect( fileSaveAsAction, SIGNAL( activated() ) , this, SLOT( save_script_as() ) );


  fileQuitAction = new QAction("&Close Editor", this);
  fileQuitAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Q));
  connect( fileQuitAction, SIGNAL( activated() ) , 
           this, SLOT( close_slot() ) );


  //-------------------
  // edit actions

  
  editUndoAction = new QAction(QIcon(QPixmap( (const char **) image4_data )),
			       "&Undo",this);
  editUndoAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z));
  connect( editUndoAction, SIGNAL( activated() ) , script_in_, SLOT( undo() ) );

  editRedoAction = new QAction(QIcon(QPixmap( (const char **) image5_data )),
			       "&Redo",this);
  editRedoAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_R));
  connect( editRedoAction, SIGNAL( activated() ) , script_in_, SLOT( redo() ) );

  
  editCutAction = new QAction(QIcon(QPixmap( (const char **) image6_data )),
			      "Cut",this);
  editCutAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_X));
  connect( editCutAction, SIGNAL( activated() ) , script_in_, SLOT( cut() ) );

  
  editCopyAction = new QAction(QIcon(QPixmap( (const char **) image7_data )),
			       "&Copy", this);
  editCopyAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_C));
  connect( editCopyAction, SIGNAL( activated() ) , script_in_, SLOT( copy() ) );

  
  editPasteAction = new QAction(QIcon(QPixmap( (const char **) image8_data )),
				"Paste",this);
  editPasteAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_V));
  connect( editPasteAction, SIGNAL( activated() ) , script_in_, SLOT( paste() ) );

  editGoToLine =  new QAction( "Go To Line...", this);
  editGoToLine->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_G));
  connect( editGoToLine, SIGNAL( activated() ) , this, SLOT( go_to_line() ) );



  //-------------------

  runScriptAction = new QAction( "Run",this);
  runScriptAction->setShortcut(QKeySequence(Qt::Key_F5));
  connect( runScriptAction, SIGNAL( activated() ) , this, SLOT( run_script() ) );

  QToolBar * fileTools = addToolBar("File");
  fileTools->addAction(fileNewAction);
  fileTools->addAction(fileOpenAction);
  fileTools->addAction(fileSaveAction);

  QToolBar * editTools = addToolBar("Edit");
  editTools->addAction(editUndoAction);
  editTools->addAction(editRedoAction);
  editTools->addAction(editCutAction);
  editTools->addAction(editPasteAction);
  

  QToolBar * runTools = addToolBar("Run script");
  runTools->addAction(runScriptAction);

  QMenu * file = menuBar()->addMenu(tr("&File"));
  file->addAction(fileNewAction);
  file->addAction(fileOpenAction);
  file->addAction(fileSaveAction);
  file->addAction(fileSaveAsAction);
  file->addSeparator();
  file->addAction(fileQuitAction);

  QMenu * edit = menuBar()->addMenu(tr("&Edit"));
  edit->setTearOffEnabled(true);
  edit->addAction(editUndoAction);
  edit->addAction(editRedoAction);
  edit->addSeparator();
  edit->addAction(editCutAction);
  edit->addAction(editCopyAction);
  edit->addAction(editPasteAction);
  edit->addAction(editGoToLine);


  QMenu * run = menuBar()->addMenu(tr("&Script"));
  run->setTearOffEnabled(true);
  run->addAction(runScriptAction);

}

