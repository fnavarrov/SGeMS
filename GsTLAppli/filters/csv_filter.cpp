#include <GsTLAppli/utils/gstl_messages.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/filters/csv_filter.h>
#include <GsTLAppli/filters/csv_filter_qt_dialogs.h>
#include <GsTLAppli/grid/grid_model/cartesian_grid.h>
#include <GsTLAppli/grid/grid_model/point_set.h>
#include <GsTLAppli/utils/string_manipulation.h>
#include <GsTLAppli/grid/grid_model/reduced_grid.h>


#include <qdialog.h>
#include <qapplication.h>
#include <qtextstream.h>
#include <qfile.h>
#include <qstringlist.h>
#include <qcursor.h>

#include <string>
#include <cctype>


Named_interface* Csv_infilter::create_new_interface( std::string& ){
  return new Csv_infilter;
}


Csv_infilter::Csv_infilter() 
  : wizard_( new Csv_infilter_dialog( qApp->activeWindow() ) ) {
}

Csv_infilter::~Csv_infilter(void)
{
}


bool Csv_infilter::can_handle( const std::string& filename ){
  // To figure out if a file is a csv formatted file we do:
  //   - read the first line, and store the nuber of comma delimieted entries
  //   - Read the next 10 lines to ensure that the same number of entries than the first line

  QString qfilename(filename.c_str());
  if( !qfilename.endsWith(".csv",Qt::CaseInsensitive) )return false;
  QFile file( filename.c_str() );
  if( !file.open( QIODevice::ReadOnly ) ) return false;

  QTextStream stream( &file );
  stream.readLine();
  if( stream.atEnd() ) return false;

  QString str;
  stream >> str;
  stream.readLine();
  int nProperties = str.split(",").size();
//  int nPropertiesSpace = str.split(" ").size();
  bool ok;
  int test = str.toInt(&ok);
  if( ok ) return false;
 
  for( int i= 0; i < 10; i++ ) {
    if(stream.atEnd()) return true;
    stream.readLine();
    if( nProperties != str.split(",").size() ) return false;
  }
  return true;
}

Geostat_grid* Csv_infilter::read( const std::string& filename, 
                                 std::string* errors ){
  std::ifstream infile( filename.c_str() );
  if( !infile ) {
    if( errors ) 
      errors->append( "can't open file: " + filename );
  }

// This is where extra check could be done to automatically load the file
// based on user preferences stored in a (XML) file

  wizard_->set_file( infile );

  QApplication::setOverrideCursor( QCursor(Qt::ArrowCursor) );
    
  if( wizard_->exec() == QDialog::Rejected ) {
    QApplication::restoreOverrideCursor();
    return 0;
  }

  QApplication::restoreOverrideCursor();

  Csv_specialized_infilter* filter = wizard_->filter();
  return filter->read( infile ) ;
}

//========================================================


Geostat_grid* Csv_specialized_infilter::read( const std::string& filename, 
                                                std::string* errors ) {
  std::ifstream in( filename.c_str() );
  if( !in ) {
    if( errors )
      errors->append( "can't open file: " + filename );
    return 0;
  }

  return this->read( in );
}

//==============================================================
Named_interface* Csv_poinset_infilter::create_new_interface( std::string& ) {
  return new Csv_poinset_infilter();
}

Csv_poinset_infilter::Csv_poinset_infilter() 
 : dialog_( new Csv_input_pointset_dialog( qApp->activeWindow() ) ) {
}

Csv_poinset_infilter::~Csv_poinset_infilter() {
  dialog_ = 0;
}

QWidget* Csv_poinset_infilter::init_dialog( std::ifstream& infile ) {
  dialog_ = new Csv_input_pointset_dialog( infile, qApp->activeWindow() );
  return dialog_;
}

bool Csv_poinset_infilter::has_valid_parameters() const {
  return !dialog_->name().isEmpty();
}

Geostat_grid* Csv_poinset_infilter::read( std::ifstream& infile ) {

	QByteArray tmp = dialog_->name().simplified().toLatin1();
	std::string name( tmp.constData() );

  int X_col_id = dialog_->X_column_index();
  int Y_col_id = dialog_->Y_column_index();
  int Z_col_id = dialog_->Z_column_index();

  if( X_col_id == Y_col_id || X_col_id == Z_col_id || Y_col_id == Z_col_id ) {
    GsTLcerr << "The same column was selected for multiple coordinates \n" << gstlIO::end;
    return 0;
  }

  bool use_no_data_value = dialog_->use_no_data_value();
  float no_data_value = GsTLGridProperty::no_data_value;
  if( dialog_->use_no_data_value() ) {
    no_data_value = dialog_->no_data_value();
  }


  std::string str;
  std::getline(infile, str);
  QString qstr(str.c_str());
  QStringList property_names = qstr.split(",");

  bool is_x_provided = dialog_->X_column_name() != "None";
  bool is_y_provided = dialog_->Y_column_name() != "None";
  bool is_z_provided = dialog_->Z_column_name() != "None";
  if(is_x_provided) property_names.removeOne(dialog_->X_column_name());
  if(is_y_provided) property_names.removeOne(dialog_->Y_column_name());
  if(is_z_provided) property_names.removeOne(dialog_->Z_column_name());


  std::vector< std::vector< QString > > property_values( property_names.size() );
  std::vector< Point_set::location_type > point_locations;

//  For a csv file no data value is indicated by an empty field e.g. {34,,5.5}
  while( std::getline(infile, str) ) {
    qstr = str.c_str();
    QStringList fields = qstr.split(",");

    Point_set::location_type loc;
    if(is_x_provided) loc[0] = fields[X_col_id].toDouble();
    if(is_y_provided) loc[1] = fields[Y_col_id].toDouble();
    if(is_z_provided) loc[2] = fields[Z_col_id].toDouble();
    point_locations.push_back(loc);

    unsigned int i=0;
   for(unsigned int j=0;j<fields.size();j++) {
      if(j==0) i=0;
      if(j != X_col_id && j != Y_col_id && j != Z_col_id) {
        property_values[i].push_back(fields[j]);
        i++;
      }
    }
  }
  
//   done reading file
//----------------------------

  int point_set_size = point_locations.size();
  appli_message( "read " << point_set_size << " points" );

  // We now have a vector containing all the locations and another one with
  // all the property values.
  // Create a pointset, initialize it with the data we collected, and we're done
 
  // ask manager to get a new pointset and initialize it
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager + "/" + name );

  if( ni.raw_ptr() != 0 ) {
    GsTLcerr << "object " << name << " already exists\n" << gstlIO::end;
    return 0;
  }

  std::string size_str = String_Op::to_string( point_set_size );
  ni = Root::instance()->new_interface( "point_set://" + size_str, 
				  gridModels_manager + "/" + name );
  Point_set* pset = dynamic_cast<Point_set*>( ni.raw_ptr() );
  appli_assert( pset != 0 );

  pset->point_locations( point_locations );


  for( unsigned int k= 0; k < property_names.size(); k++ ) {
  // Need to find out if property is categorical
    unsigned int check_size = std::min(30,static_cast<int>(property_values[k].size()));
    bool is_categ = false;
    for(unsigned int i=0; i<check_size ; i++ ) {
      bool ok;
      property_values[k][i].toFloat(&ok);
      if(!ok)  {
        is_categ = true;
        break;
      }
    }

    if(!is_categ) {
      GsTLGridProperty* prop = pset->add_property( property_names[k].toStdString() );
      for( int l=0; l < point_set_size; l++ ) {
        float val = property_values[k][l].toFloat();
        if(use_no_data_value && val == no_data_value) 
          val = GsTLGridProperty::no_data_value;
        prop->set_value( val, l );
      }
    }
    else {
      //Create categorical definition
      // by default it is named: grid-propertyName
      std::string catdef_name = name+"-"+property_names[k].toStdString();
       ni = Root::instance()->new_interface( "categoricaldefinition://"+catdef_name,categoricalDefinition_manager +"/"+catdef_name );
        CategoricalPropertyDefinitionName* cat_def = 
            dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());


      for( int i=0; i < point_set_size; i++ ) {
        cat_def->add_category(property_values[k][i].toStdString());
      }
      GsTLGridCategoricalProperty* prop = pset->add_categorical_property( property_names[k].toStdString(),cat_def->name() );
//      prop->set_category_definition(cat_def->name());
      QString no_data_value_str = QString().arg( no_data_value);
      for( int i=0; i < point_set_size; i++ ) {
        QString val =  property_values[k][i];
        if(use_no_data_value && val == no_data_value_str)  {
          prop->set_value( GsTLGridProperty::no_data_value, i );
        }
        else 
          prop->set_value( val.toStdString(), i );
      }
    }
  }


  return pset;
}

//================================================================================


//========================================================

Named_interface* Csv_grid_infilter::create_new_interface( std::string& ) {
  return new Csv_grid_infilter();
}

Csv_grid_infilter::Csv_grid_infilter() 
: dialog_( new Csv_input_grid_dialog( qApp->activeWindow() ) ) {
}

Csv_grid_infilter::~Csv_grid_infilter() {
  // deleting dialog_ causes a segfault. See why.
  //  delete dialog_;
  dialog_ = 0;
}

QWidget* Csv_grid_infilter::init_dialog( std::ifstream& ) {
  dialog_ = new Csv_input_grid_dialog( qApp->activeWindow() );
  return dialog_;
}


Geostat_grid* Csv_grid_infilter::read( std::ifstream& infile ) {

  int nx = dialog_->nx();
  int ny = dialog_->ny();
  int nz = dialog_->nz();
  float x_size = dialog_->x_size();
  float y_size = dialog_->y_size();
  float z_size = dialog_->z_size();
  float Ox = dialog_->Ox();
  float Oy = dialog_->Oy();
  float Oz = dialog_->Oz();

  bool use_no_data_value = dialog_->use_no_data_value();
  float no_data_value = GsTLGridProperty::no_data_value;
  QString no_data_value_str = QString().arg(no_data_value);
  if( dialog_->use_no_data_value() ) {
    no_data_value = dialog_->no_data_value();
    no_data_value_str = QString::number(no_data_value);

  }


  QByteArray tmp = dialog_->name().simplified().toLatin1();
  std::string name( tmp.constData() );

  // ask manager to get a new grid and initialize it
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager + "/" + name );

  if( ni.raw_ptr() != 0 ) {
    GsTLcerr << "object " << name << " already exists\n" << gstlIO::end;
    return 0;
  }

  appli_message( "creating new grid '" << name << "'" 
		             << " of dimensions: " << nx << "x" << ny << "x" << nz);

  ni = Root::instance()->new_interface( "cgrid", 
                                        gridModels_manager + "/" + name );
  Cartesian_grid* grid = dynamic_cast<Cartesian_grid*>( ni.raw_ptr() );
  appli_assert( grid != 0 );

  grid->set_dimensions( nx, ny, nz,
			x_size, y_size, z_size);
  grid->origin( GsTLPoint( Ox,Oy,Oz) );
  appli_message( "grid resized to " << nx << "x" << ny << "x" << nz
		<< "  total=: " << grid->size() );

  std::string buffer;
  
  //-------------------------
  //   now, read the file

  std::getline( infile, buffer, '\n');
  QStringList property_names = QString(buffer.c_str()).split(",");

//Read one column at a time
  std::streampos start_data = infile.tellg();
  for(unsigned int j = 0; j< property_names.size(); j++) {
    infile.clear();
    infile.seekg( start_data );
    // Check if property j is categorical
    bool is_categ = false;
    for(unsigned int i=0; i<30 ; i++ ) {
      bool ok;
      if( std::getline(infile, buffer) ) break;
      QString qstr(buffer.c_str());
      QStringList values_str = qstr.split(",");
      values_str[j].toFloat(&ok);
      if(!ok)  {
        is_categ = true;
        break;
      }
    }
    infile.clear();
    infile.seekg( start_data );

    if(is_categ) {
      GsTLGridCategoricalProperty* prop = 
        grid->add_categorical_property(property_names[j].toStdString());
      
      ni = Root::instance()->new_interface( categoricalDefinition_manager, name+"-"+property_names[j].toStdString());
      CategoricalPropertyDefinitionName* cat_def = 
            dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());

      while( std::getline(infile, buffer) ) {
        QString qstr(buffer.c_str());
        QStringList values_qstr = qstr.split(",");
        cat_def->add_category(values_qstr[j].toStdString());
      }
      prop->set_category_definition(cat_def->name());
      infile.clear();
      infile.seekg( start_data );

      int node_id=0;
      while( std::getline(infile, buffer) ) {
        QString qstr(buffer.c_str());
        QStringList values_qstr = qstr.split(",");
        QString val = values_qstr[j];
        if(use_no_data_value && val == no_data_value_str)  {
          prop->set_value( GsTLGridProperty::no_data_value, node_id );
        }
        else {
          prop->set_value( val.toStdString(), node_id );
        }
        node_id++;
      }
    }
    else {
      GsTLGridProperty* prop = 
        grid->add_property(property_names[j].toStdString());
      int node_id=0;
      while( std::getline(infile, buffer) ) {
        QString qstr(buffer.c_str());
        QStringList values_qstr = qstr.split(",");
        if(!values_qstr[j].isEmpty()) {
          bool ok;
          float val = values_qstr[j].toFloat(&ok);
          if(ok  && val != no_data_value) prop->set_value(val,node_id);
        }
        node_id++;
      }
    }

  }
  return grid;
}



bool Csv_grid_infilter::has_valid_parameters() const {
  return !dialog_->name().isEmpty();
}





//========================================================

Named_interface* Csv_mgrid_infilter::create_new_interface( std::string& ) {
  return new Csv_mgrid_infilter();
}

Csv_mgrid_infilter::Csv_mgrid_infilter() : 
	dialog_(new Csv_input_mgrid_dialog( qApp->activeWindow() ) )
{}

Csv_mgrid_infilter::~Csv_mgrid_infilter() {
  dialog_ = 0;
}

QWidget* Csv_mgrid_infilter::init_dialog( std::ifstream& infile) {
  dialog_ = new Csv_input_mgrid_dialog(infile, qApp->activeWindow() );
  return dialog_;
}




bool Csv_mgrid_infilter::get_mgrid_xyz_dimensions(
    std::ifstream& infile, Reduced_grid* grid, 
    int X_col_id, int Y_col_id, int Z_col_id,
    float x_size, float y_size, float z_size)
{

  // Read the first line with property name
  std::string buffer;
  std::getline( infile, buffer, '\n');

  std::vector<Geostat_grid::location_type> xyz;
  Geostat_grid::location_type max_xyz(-1,-1,-1);
  Geostat_grid::location_type origin(9e20,9e20,9e20);
  while( infile ) {
		Geostat_grid::location_type loc;
		std::getline( infile, buffer, '\n');
    if (buffer.empty()) break;
		std::vector<std::string> buf = String_Op::decompose_string( buffer, ",", false );
		if (buf.empty()) break;

		loc[0] = String_Op::to_number<float>(buf[X_col_id]);
		loc[1] = String_Op::to_number<float>(buf[Y_col_id]);
		loc[2] = String_Op::to_number<float>(buf[Z_col_id]);
    xyz.push_back(loc);

    if(loc[0] > max_xyz[0]) max_xyz[0] = loc[0];
    if(loc[1] > max_xyz[1]) max_xyz[1] = loc[1];
    if(loc[2] > max_xyz[2]) max_xyz[2] = loc[2];

    if(loc[0] < origin[0]) origin[0] = loc[0];
    if(loc[1] < origin[1]) origin[1] = loc[1];
    if(loc[2] < origin[2]) origin[2] = loc[2];

  }
  GsTLGridNode nxyz(int((max_xyz[0]-origin[0])/x_size)+1,
                    int((max_xyz[1]-origin[1])/y_size)+1,
                    int((max_xyz[2]-origin[2])/z_size)+1);


  grid->set_dimensions(nxyz[0],nxyz[1],nxyz[2],
         x_size, y_size, z_size, xyz, origin);
  

  return true;
}


Geostat_grid* Csv_mgrid_infilter::readRegularGridFormat(std::ifstream& infile,Reduced_grid * grid)
{

  infile.clear();
  infile.seekg(0, ios::beg);
	std::vector<std::string> nums;

	int nx = dialog_->nx();
	int ny = dialog_->ny();
	int nz = dialog_->nz();
	float x_size = dialog_->x_size();
	float y_size = dialog_->y_size();
	float z_size = dialog_->z_size();
	float Ox = dialog_->Ox();
	float Oy = dialog_->Oy();
	float Oz = dialog_->Oz();

	grid->set_dimensions( nx, ny, nz,
		x_size, y_size, z_size);
	grid->origin( GsTLPoint( Ox,Oy,Oz) );

	std::string buffer;

  int maskColNumber = dialog_->mask_column_index();
  int X_col_id = dialog_->X_column_index();
  int Y_col_id = dialog_->Y_column_index();
  int Z_col_id = dialog_->Z_column_index();


  bool use_no_data_value = dialog_->use_no_data_value();
  float no_data_value = GsTLGridProperty::no_data_value;
  QString no_data_value_str = QString().arg(no_data_value);
  if( dialog_->use_no_data_value() ) {
    no_data_value = dialog_->no_data_value();
    no_data_value_str = QString::number(no_data_value);
  }

	//-------------------------
	//   now, read the file
	std::getline( infile, buffer, '\n');
	std::vector<std::string> property_names = String_Op::decompose_string( buffer, ",", false );


  int beg_data_pos = infile.tellg();
  std::vector<bool> mask;
  mask.reserve(grid->rgrid_size());
  int size_active=0;

// Read Mask
  for( int i=0; i < grid->rgrid_size() ; i++ ) {
		std::getline( infile, buffer, '\n');
		std::vector<std::string> buf = String_Op::decompose_string(buffer, ",", false);
    if(buf.size() < property_names.size()) {
	    GsTLcerr << "Invalid file format\n Line " <<i<<" does not have " <<static_cast<int>(property_names.size())<<" columns"<< gstlIO::end;
		  return NULL;
    }
    mask.push_back( buf[maskColNumber] == "1" );
	}
  grid->mask( mask );


	// reposition the stream
	infile.clear();
	infile.seekg( 0 );
	std::getline( infile, buffer, '\n');

//Read one column at a time
  std::streampos start_data = infile.tellg();
  for(unsigned int j = 0; j< property_names.size(); j++) {
    infile.clear();
    infile.seekg( start_data );
    // Check if property j is categorical
    bool is_categ = false;
    for(unsigned int i=0; i<30 ; i++ ) {
      if( std::getline(infile, buffer) ) break;
      std::vector<std::string> values_str = String_Op::decompose_string(buffer, ",", false);
      is_categ = !String_Op::is_number(values_str[j]);
      if(is_categ) break;
    }
    infile.clear();
    infile.seekg( start_data );

    if(is_categ) {
      GsTLGridCategoricalProperty* prop = 
        grid->add_categorical_property(property_names[j]);

      // Set the category definition
      SmartPtr<Named_interface> ni = 
        Root::instance()->new_interface( categoricalDefinition_manager, 
                                         dialog_->name().toStdString()+"-"+property_names[j]);
      CategoricalPropertyDefinitionName* cat_def = 
            dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());

      while( std::getline(infile, buffer) ) {
        QString qstr(buffer.c_str());
        QStringList values_qstr = qstr.split(",");
        cat_def->add_category(values_qstr[j].toStdString());
      }
      prop->set_category_definition(cat_def->name());
      infile.clear();
      infile.seekg( start_data );

      // Read the data
      int node_id=0;
      int index = 0;
      while( std::getline(infile, buffer) ) {
        if( mask[index] ) {
          QString qstr(buffer.c_str());
          QStringList values_qstr = qstr.split(",");
          QString val = values_qstr[j];
          if(!val.isEmpty() && val != no_data_value_str ) {
            prop->set_value(values_qstr[j].toStdString(),node_id);
          }
          node_id++;
        }
        index++;
      }
    }
    else {
      GsTLGridProperty* prop = 
        grid->add_property(property_names[j]);
      int node_id=0;
      int index = 0;
      while( std::getline(infile, buffer) ) {
        if(mask[index]) {
          QString qstr(buffer.c_str());
          QStringList values_qstr = qstr.split(",");
          if(!values_qstr[j].isEmpty()) {
            bool ok;
            float val = values_qstr[j].toFloat(&ok);
            if(ok && val != no_data_value ) prop->set_value(val,node_id);
          }
          node_id++;
        }
        index++;
      }
      
    }
  }
	return grid;
}


Geostat_grid* Csv_mgrid_infilter::readPointsetFormat(std::ifstream& infile, Reduced_grid * grid)
{
  
	int X_col_id = dialog_->X_column_index();
	int Y_col_id = dialog_->Y_column_index();
	int Z_col_id = dialog_->Z_column_index();	
	if( X_col_id == Y_col_id || X_col_id == Z_col_id || Y_col_id == Z_col_id ) {
		GsTLcerr << "The same column number was selected for multiple coordinates \n" << gstlIO::end;
		return 0;
	}
	float x_size = dialog_->x_size();
	float y_size = dialog_->y_size();
	float z_size = dialog_->z_size();

  if(x_size< 0. || y_size< 0. || z_size< 0. ) {
    GsTLcerr << "Pixel size must be positive "<< gstlIO::end;
    return NULL;
  }

  bool use_no_data_value = dialog_->use_no_data_value();
  float no_data_value = GsTLGridProperty::no_data_value;
  QString no_data_value_str = QString().arg(no_data_value);
  if( dialog_->use_no_data_value() ) {
    no_data_value = dialog_->no_data_value();
    no_data_value_str = QString::number(no_data_value);
  }

  get_mgrid_xyz_dimensions(infile,grid,X_col_id,Y_col_id,Z_col_id,
                             x_size,y_size,z_size);

  infile.clear();
  infile.seekg(0, ios::beg);

  std::string buffer;
  std::getline(infile, buffer);
  QString qstr(buffer.c_str());
  QStringList property_names = qstr.split(",");


//Read one column at a time
  std::streampos start_data = infile.tellg();
  for(unsigned int j = 0; j< property_names.size(); j++) {
    if(j == X_col_id || j == Y_col_id || j == Z_col_id) continue;
    infile.clear();
    infile.seekg( start_data );
    // Check if property j is categorical
    bool is_categ = false;
    for(unsigned int i=0; i<30 ; i++ ) {
      if( std::getline(infile, buffer) ) break;
      std::vector<std::string> values_str = String_Op::decompose_string(buffer, ",", false);
      is_categ = !String_Op::is_number(values_str[j]);
      if(is_categ) break;
    }
    infile.clear();
    infile.seekg( start_data );

    if(is_categ) {
      GsTLGridCategoricalProperty* prop = 
        grid->add_categorical_property(property_names[j].toStdString());

            // Set the category definition
      SmartPtr<Named_interface> ni = 
        Root::instance()->new_interface( categoricalDefinition_manager, 
                                         dialog_->name().toStdString()+"-"+property_names[j].toStdString());
      CategoricalPropertyDefinitionName* cat_def = 
            dynamic_cast<CategoricalPropertyDefinitionName*>(ni.raw_ptr());

      while( std::getline(infile, buffer) ) {
        QString qstr(buffer.c_str());
        QStringList values_qstr = qstr.split(",");
        cat_def->add_category(values_qstr[j].toStdString());
      }
      prop->set_category_definition(cat_def->name());
      infile.clear();
      infile.seekg( start_data );

      int node_id=0;
      while( std::getline(infile, buffer) ) {
        QString qstr(buffer.c_str());
        QStringList values_qstr = qstr.split(",");
        if(!values_qstr[j].isEmpty()) {
          GsTLGridNode ijk;
          Geostat_grid::location_type loc;
		      loc[0] = values_qstr[X_col_id].toDouble();
		      loc[1] = values_qstr[Y_col_id].toDouble();
		      loc[2] = values_qstr[Z_col_id].toDouble();
          grid->geometry()->grid_coordinates(ijk,loc);
          int node_id = grid->cursor()->node_id(ijk[0],ijk[1],ijk[2]);
          if( node_id < 0 ) continue;
          QString val = values_qstr[j];
          if( !val.isEmpty() && val != no_data_value_str)
            prop->set_value(values_qstr[j].toStdString(),node_id);
        }
        node_id++;
      }
    }
    else {
      GsTLGridProperty* prop = 
        grid->add_property(property_names[j].toStdString());
      int node_id=0;
      while( std::getline(infile, buffer) ) {
        QString qstr(buffer.c_str());
        QStringList values_qstr = qstr.split(",");
        if(!values_qstr[j].isEmpty()) {
          GsTLGridNode ijk;
          Geostat_grid::location_type loc;
		      loc[0] = values_qstr[X_col_id].toDouble();
		      loc[1] = values_qstr[Y_col_id].toDouble();
		      loc[2] = values_qstr[Z_col_id].toDouble();
          grid->geometry()->grid_coordinates(ijk,loc);
          int node_id = grid->cursor()->node_id(ijk[0],ijk[1],ijk[2]);
          if( node_id < 0 ) continue;
          bool ok;
          float val = values_qstr[j].toFloat(&ok);
          if(ok && val != no_data_value) prop->set_value(val,node_id);
        }
        node_id++;
      }
    }
  }

	return grid;
}

Geostat_grid* Csv_mgrid_infilter::read( std::ifstream& infile ) 
{
//	QByteArray tmp  =dialog_->name().simplified().toLatin1();
	//std::string name( tmp.constData() );
  std::string name = dialog_->name().toStdString();

  // ask manager to get a new grid and initialize it
  SmartPtr<Named_interface> ni =
    Root::instance()->interface( gridModels_manager + "/" + name );

  if( ni.raw_ptr() != 0 ) {
    GsTLcerr << "object " << name << " already exists\n" << gstlIO::end;
    return 0;
  }

  ni = Root::instance()->new_interface( "reduced_grid", 
                                        gridModels_manager + "/" + name );
  Reduced_grid* grid = dynamic_cast<Reduced_grid*>( ni.raw_ptr() );
  appli_assert( grid != 0 );

  if (dialog_->is_xyz_file())
    return readPointsetFormat(infile, grid);
  else
	  return readRegularGridFormat(infile, grid);	  
}

bool Csv_mgrid_infilter::has_valid_parameters() const{
  bool ok = true;
  ok = ok && dialog_->x_size() > 0.;
  ok = ok && dialog_->y_size() > 0.;
  ok = ok && dialog_->z_size() > 0.;
  ok = ok && !dialog_->name().isEmpty();
  return ok;
}

/*
 * csv outfilter
 */

Named_interface* Csv_outfilter::create_new_interface( std::string& ) {
	return new Csv_outfilter;
}

Csv_outfilter::Csv_outfilter() {}

Csv_outfilter::~Csv_outfilter() {}

bool Csv_outfilter::write( std::string outfile_name, const Geostat_grid* grid, std::string* errors ) {
  /* Not all objects are saved the same way: if we are dealing with a
   * stratigraphic grid, we don't need to save the point coordinates.
   */
  std::ofstream outfile( outfile_name.c_str() );
  if( !outfile ) {
    if( errors )
      errors->append( "can't write to file: " + outfile_name );
    return false;
  }

  typedef std::list<std::string>::const_iterator string_iterator;
  std::list<std::string> & property_names = _list_to_write;
  //std::list<std::string> property_names = grid->property_list();
  std::vector< const GsTLGridProperty* > properties;

  bool output_locations = false;
  int nb_properties = property_names.size();

  //TL modified
  if( dynamic_cast<const Point_set*>( grid ) || dynamic_cast<const Reduced_grid*>(grid)) {
    output_locations = true;
    nb_properties += 3;
  }


  // write property names
  if( output_locations )
    outfile << "X ,Y,Z, ";
  string_iterator it = property_names.begin();
  if(it != property_names.end()) {
  	outfile << *it;
  	properties.push_back( grid->property( *it ) );
  	it++;
  }
  for( ; it != property_names.end();
       ++ it ) {
    outfile <<","<< *it;
    properties.push_back( grid->property( *it ) );
  }
  outfile<<std::endl;

  int grid_size;
  if( properties.empty() )
    grid_size = 0;
  else
    grid_size = properties[0]->size();

  int nan = static_cast<int>(GsTLGridProperty::no_data_value);


  // Write the property values
  for( int i=0; i < grid_size ; i++ ) {
    if( output_locations ) {

	  Geostat_grid::location_type loc = grid->location( i );
		std::stringstream ss_x, ss_y, ss_z;

		ss_x.precision(std::numeric_limits<GsTLCoord>::digits10);//override the default
    ss_y.precision(std::numeric_limits<GsTLCoord>::digits10);//override the default
    ss_z.precision(std::numeric_limits<GsTLCoord>::digits10);//override the default
		ss_x << loc.x();
    ss_y << loc.y();
    ss_z << loc.z();

    outfile << ss_x.str()<<","<<ss_y.str() << "," << ss_z.str()<< ",";

		}

		for( unsigned int j=0; j < property_names.size(); ++j ) {
			if( properties[j]->is_informed( i ) ) {
				const GsTLGridCategoricalProperty* cprop =
						dynamic_cast<const GsTLGridCategoricalProperty*>(properties[j]);
				if(cprop)
					outfile << cprop->get_category_name(i);
				else
					outfile << properties[j]->get_value( i );
			}

//If nan print nothing (output ,,)
			else
				outfile << -999;
			if( j < property_names.size()-1 ) outfile<<",";
		}

		outfile << std::endl;
  }
  return true;
}



