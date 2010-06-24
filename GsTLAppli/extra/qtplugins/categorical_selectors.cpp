#include <GsTLAppli/extra/qtplugins/categorical_selectors.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/utils/gstl_messages.h>
#include <QKeySequence>
#include <GsTLAppli/grid/grid_model/geostat_grid.h>
#include <GsTLAppli/grid/grid_model/grid_property.h>
#include <GsTLAppli/grid/grid_model/grid_categorical_property.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/utils/manager.h>

#include <qstring.h>
#include <QGroupBox>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qobject.h>
#include <qlabel.h>
#include <qevent.h>
#include <qclipboard.h>
#include <qapplication.h>
#include <QtUiTools/QUiLoader>
#include <algorithm>
#include <QTextBrowser>


SingleCategoricalPropertySelector::SingleCategoricalPropertySelector( QWidget* parent, const char* name )
  : SinglePropertySelector( parent, name ) {
}

void SingleCategoricalPropertySelector::show_properties( const QString& grid_name ) {
  QString current_text;
  if( grid_name == current_grid_ )
    current_text = currentText();  
  
  current_grid_ = grid_name;
  QComboBox::clear();

  if( grid_name.isEmpty() || grid_name == GridSelectorBasic::no_selection ) return;
  

  QByteArray tmp = grid_name.toLatin1();
  std::string name( tmp.constData() );

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + name );
  Geostat_grid* grid = (Geostat_grid*) ni.raw_ptr() ;
  // no dynamic_cast is used on the previous line because it makes 
  // designer and uic segfault when they try to load the plugin...
  // It used to work before, don't know what changed.  

  if( !grid ) return;

  int selected_item = 0;
  int i=0;
  std::list<std::string> properties = grid->categorical_property_list();
  std::list<std::string>::iterator begin = properties.begin();
  for( ; begin != properties.end() ; ++begin, i++ ) {
    QString prop_name( begin->c_str() );
    addItem( prop_name );

    if( current_text == prop_name ) selected_item = i;
  }

  // a dirty hack to have the combobox resize itself to the size of 
  // its longest element
  setFont( font() );
  updateGeometry();
  
  setCurrentIndex( selected_item );


  emit activated( currentText() );
  // Don't know why "0". Should be "currentItem". remove if everything works fine
    emit activated( 0 );
//  emit activated( currentItem() );
}


//==========================================================================

MultiCategoricalPropertySelector::MultiCategoricalPropertySelector(
  QWidget* parent, const char* name) : MultiPropertySelector(parent,name) {}

void MultiCategoricalPropertySelector::show_properties( const QString& grid_name ) {
  QListWidget::clear();

  if( grid_name.isEmpty() || grid_name == GridSelectorBasic::no_selection ) return;
  
  QByteArray tmp = grid_name.toLatin1();
  std::string name( tmp.constData() );

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + name );
  Geostat_grid* grid = (Geostat_grid*) ni.raw_ptr() ;
  // no dynamic_cast is used on the previous line because it makes 
  // designer and uic segfault when they try to load the plugin...
  // It used to work before, don't know what changed.  

  if( !grid ) return;

  std::list<std::string> properties = grid->categorical_property_list();
  std::list<std::string>::iterator begin = properties.begin();
  for( ; begin != properties.end() ; ++begin ) {
    QString prop_name( begin->c_str() );
     std::string name = *begin;
    //const CategoricalPropertyDefinition* cdef;// = grid->categorical_property(name)->get_category_definition();
//    const GsTLGridCategoricalProperty* prop = grid->categorical_property(name);
    const CategoricalPropertyDefinition* cdef = grid->categorical_property(name)->get_category_definition();
    QString def_name( cdef->name().c_str() );
    addItem( prop_name + "  ("+def_name+")" );
  }
  
}
//==========================================================================

Ordered_categorical_property_selector_dialog::
Ordered_categorical_property_selector_dialog( QWidget* parent, const char* name)
:Ordered_property_selector_dialog(parent, name){}


void Ordered_categorical_property_selector_dialog::
show_properties( const QString& grid_name ) {
  property_selector_->show_properties( grid_name );
}


//==========================================================================
OrderedCategoricalPropertySelector::
OrderedCategoricalPropertySelector( QWidget* parent, const char* name)
:OrderedPropertySelector(parent,name){}

void OrderedCategoricalPropertySelector::show_selection_dialog() {
  Ordered_property_selector_dialog* dialog =
    new Ordered_categorical_property_selector_dialog( this, "Choose" );
  dialog->setWindowTitle( "Select Properties" );
  dialog->show_properties( grid_name_ );

  if( selected_properties_->count() != 0 ) {
    QStringList current_selection;
    for( int i = 0; i < selected_properties_->count() ; i++ )
      current_selection.push_back( selected_properties_->item(i)->text() );
    dialog->set_current_selection( current_selection );
  }

  if( dialog->exec() == QDialog::Rejected ) return;
  
  QStringList selection = dialog->selection();
  selected_properties_->clear();
  selected_properties_->addItems( selection );

  emit selected_count( selected_properties_->count() );
}

void OrderedCategoricalPropertySelector::set_selected_properties( QStringList name_list ) {

  if( grid_name_.isEmpty() || grid_name_ == GridSelectorBasic::no_selection ) return;
  

  QByteArray tmp = grid_name_.toLatin1();
  std::string name( tmp.constData() );

  SmartPtr< Named_interface > ni = 
    Root::instance()->interface( gridModels_manager + "/" + name );
  Geostat_grid* grid = (Geostat_grid*) ni.raw_ptr() ;
  // no dynamic_cast is used on the previous line because it makes 
  // designer and uic segfault when they try to load the plugin...
  // It used to work before, don't know what changed.  

  if( !grid ) return;
    
  selected_properties_->clear();

  std::list<std::string> properties = grid->categorical_property_list();
  properties.sort();

  for( unsigned int i=0; i < name_list.size() ; i++ ) {
    if( name_list[i] == QString::null ) continue;

    QByteArray tt = name_list[i].toLatin1();
    bool found = std::binary_search( properties.begin(), properties.end(), 
                                     std::string( tt.constData() ) );
    if( found )
      selected_properties_->addItem( name_list[i] );
  }

}


//======================================================================
CategoricalDefinitionSelector::CategoricalDefinitionSelector( QWidget* parent, const char* name )
  : QComboBox( parent ) {
  if (name)
    setObjectName(name);
  show_definitons();
}

void CategoricalDefinitionSelector::show_definitons( ) {

  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager );
  if(!ni) return;
  appli_assert( ni );
  Manager* cat_manager = dynamic_cast<Manager*>(ni.raw_ptr());
  
  int selected_item = 0;
  int i=0;
  Manager::names_iterator begin = cat_manager->begin_names();
  for( ; begin != cat_manager->end_names() ; ++begin, i++ ) {
    QString catdef_name( begin->c_str() );
    addItem( catdef_name );
  }

  // a dirty hack to have the combobox resize itself to the size of 
  // its longest element
  setFont( font() );
  updateGeometry();
  
  setCurrentIndex( selected_item );


//  emit activated( currentText() );
  // Don't know why "0". Should be "currentItem". remove if everything works fine
//    emit activated( 0 );
//  emit activated( currentItem() );
}


//===============================================

MultiCategoricalDefinitionSelector::MultiCategoricalDefinitionSelector( QWidget* parent, const char* name )
  : QListWidget( parent ) {
  if (name)
    setObjectName(name);

  setSelectionMode( QAbstractItemView::ExtendedSelection );

  QObject::connect( this, SIGNAL( itemSelectionChanged() ),
		    this, SLOT( selection_size() ) );
}

void MultiCategoricalDefinitionSelector::show_definitions( ) {
  QListWidget::clear();
  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager );
  appli_assert( ni );
  Manager* cat_manager = dynamic_cast<Manager*>(ni.raw_ptr());
  
  int selected_item = 0;
  int i=0;
  Manager::names_iterator begin = cat_manager->begin_names();
  for( ; begin != cat_manager->end_names() ; ++begin, i++ ) {
    QString catdef_name( begin->c_str() );
    addItem( catdef_name );
  }

}


void MultiCategoricalDefinitionSelector::selection_size() {
  int size=0;
  for( unsigned int i = 0; i < count() ; i++ ) {
    QListWidgetItem * it = item(i);
    if( it->isSelected( ) && !it->text().isEmpty() ) {
      size++;
    }
  }
  emit( selected_count(size) );
}

//===============================================

CategoricalDefinitionViewer::CategoricalDefinitionViewer(QWidget *parent, const char *name)
: QGroupBox(parent), current_definition_(""), baseLayout_(0) {
}

void CategoricalDefinitionViewer::show_definition( QString cat_def_name) {
  if(current_definition_ == cat_def_name ) return;
  current_definition_ = cat_def_name ;

  delete baseLayout_;
  baseLayout_ = new QVBoxLayout(this);

  SmartPtr<Named_interface> ni = 
    Root::instance()->interface( categoricalDefinition_manager+"/"+cat_def_name.toStdString() );
  appli_assert( ni );

	CategoricalPropertyDefinitionName* cat_def = 
    dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());
  QTextBrowser* def_text = new QTextBrowser(this);
  def_text->setReadOnly(true);
//  def_text->setAutoFormatting(QTextEdit::AutoBulletList);
  def_text->setUndoRedoEnabled(false);
//  def_text->setMaximumHeight(50);
  baseLayout_->addWidget(def_text);

  if(cat_def != 0) {
    for(unsigned int i=0; i<cat_def->number_of_category(); i++) {
      std::ostringstream def_name;
      def_name<<i<<": "<<cat_def->get_category_name(i);
      def_text->append( def_name.str().c_str() );
//      QLabel* nameLabel = new QLabel(def_text.str().c_str(),this);
//      baseLayout_->addWidget(nameLabel);
    }
  } 
  else {
    def_text->append( "Default naming convention" );
//    QLabel* nameLabel = new QLabel("Default naming convention",this);
//    baseLayout_->addWidget(nameLabel);    
  }
}



//===============================================


//===============================================

MultipleCategorySelector::MultipleCategorySelector( QWidget* parent, const char* name )
  : QListWidget( parent ) {
  if (name)
    setObjectName(name);

  setSelectionMode( QAbstractItemView::ExtendedSelection );

  QObject::connect( this, SIGNAL( itemSelectionChanged() ),
		    this, SLOT( selection_size() ) );
}

void MultipleCategorySelector::show_categories( const QString& cat_def_name ) {
  QListWidget::clear();

  if( cat_def_name.isEmpty() || cat_def_name == GridSelectorBasic::no_selection ) return;

  SmartPtr<Named_interface> ni =
    Root::instance()->interface( categoricalDefinition_manager+"/"+cat_def_name.toStdString() );

	CategoricalPropertyDefinitionName* cat_def =
	  dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());


	if(cat_def != 0) {
	  for(unsigned int i=0; i<cat_def->number_of_category(); i++) {
		  addItem( cat_def->get_category_name(i).c_str() );
	  }
	}


}


void MultipleCategorySelector::selection_size() {
  int size=0;
  for( unsigned int i = 0; i < count() ; i++ ) {
    QListWidgetItem * it = item(i);
    if( it->isSelected( ) && !it->text().isEmpty() ) {
      size++;
    }
  }
  emit( selected_count(size) );
}

