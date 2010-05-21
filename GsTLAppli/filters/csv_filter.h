#ifndef __GSTLAPPLI_CSV_FILTERS_H__ 
#define __GSTLAPPLI_CSV_FILTERS_H__ 
 
 
#include <GsTLAppli/filters/common.h>
#include <GsTLAppli/filters/filter.h> 
#include <GsTLAppli/filters/csv_filter_qt_dialogs.h>
#include <vector>

class GsTLGridProperty;
class Gslib_infilter_dialog; 
class Gslib_input_grid_dialog; 
class Gslib_input_pointset_dialog; 
class QWidget; 
class Reduced_grid;
class Csv_input_pointset_dialog;


class FILTERS_DECL Csv_infilter :
  public Input_filter
{
 public: 
  static Named_interface* create_new_interface( std::string& ); 
  
public:
  Csv_infilter(void);
  virtual ~Csv_infilter(void);

  virtual std::string filter_name() const { return "csv" ; }
  virtual std::string file_extensions() const { return "*.csv"; }

  virtual bool can_handle( const std::string& filename );
  virtual Geostat_grid* read( const std::string& filename, 
                              std::string* errors = 0 ); 

 protected: 
  Csv_infilter_dialog* wizard_; 
};


/** This class defines the common interface of all gslib filters capable 
 * or parsing a given type of file. 
 * The "file" can be either read from an actual file or a string 
 */ 
class FILTERS_DECL Csv_specialized_infilter : public Input_filter { 
 public: 
  virtual ~Csv_specialized_infilter() {}; 
 
  virtual QWidget* init_dialog( std::ifstream& infile ) = 0; 
  virtual std::string filter_name() const { return "csv specialized" ; } 
  virtual Geostat_grid* read( const std::string& filename, 
                              std::string* errors = 0 ); 
  virtual Geostat_grid* read( std::ifstream& infile ) = 0; 

  virtual std::string object_filtered() { return ""; } 
 
  virtual bool has_valid_parameters() const = 0;
}; 

 
/** This class defines a filter capable of parsing a csv point-set file. 
 */ 

class FILTERS_DECL Csv_poinset_infilter : public Csv_specialized_infilter { 
 public: 
  static Named_interface* create_new_interface( std::string& ); 
   
 public: 
  Csv_poinset_infilter(); 
  virtual ~Csv_poinset_infilter(); 
   
  virtual QWidget* init_dialog( std::ifstream& infile ); 
  virtual std::string object_filtered() { return "point set" ; } 
  virtual Geostat_grid* read( std::ifstream& infile ); 
 
  virtual bool has_valid_parameters() const;

 protected: 
  Csv_input_pointset_dialog* dialog_; 

 private: 
  Csv_poinset_infilter( const Csv_poinset_infilter& ); 
  Csv_poinset_infilter& operator=( const Csv_poinset_infilter& ); 
}; 




/** This class defines a filter capable of parsing a csv grid file. 
 * The grid it will create from the file will be a cartesian grid.  
 */ 
class FILTERS_DECL Csv_grid_infilter : public Csv_specialized_infilter { 
 public: 
  static Named_interface* create_new_interface( std::string& ); 
   
 public: 
  Csv_grid_infilter(); 
  virtual ~Csv_grid_infilter(); 
   
  virtual QWidget* init_dialog( std::ifstream& infile ); 
  virtual std::string object_filtered() { return "cartesian grid" ; } 
  virtual Geostat_grid* read( std::ifstream& infile ); 
  virtual bool has_valid_parameters() const;


 protected: 
  Csv_input_grid_dialog* dialog_; 

 private: 
  Csv_grid_infilter( const Csv_grid_infilter& ); 
  Csv_grid_infilter& operator=( const Csv_grid_infilter& ); 

}; 
 
class FILTERS_DECL Csv_mgrid_infilter : public Csv_specialized_infilter { 
 public: 
  static Named_interface* create_new_interface( std::string& ); 
   
 public: 
  Csv_mgrid_infilter(); 
  virtual ~Csv_mgrid_infilter(); 
   
  virtual QWidget* init_dialog( std::ifstream& infile ); 
  virtual std::string object_filtered() { return "masked grid" ; } 
  virtual Geostat_grid* read( std::ifstream& infile ); 
  virtual bool has_valid_parameters() const;

 protected: 
  Csv_input_mgrid_dialog* dialog_; 

 private: 
  Csv_mgrid_infilter( const Csv_mgrid_infilter& ); 
  Csv_mgrid_infilter& operator=( const Csv_mgrid_infilter& ); 

  Geostat_grid * readRegularGridFormat(std::ifstream& infile,Reduced_grid *);
  Geostat_grid * readPointsetFormat(std::ifstream& infile,Reduced_grid *);

  bool get_mgrid_xyz_dimensions(
    std::ifstream& infile, Reduced_grid* grid, 
    int X_col_id, int Y_col_id, int Z_col_id,
    float x_size, float y_size, float z_size);

  bool get_mgrid_ijk_dimensions(
    std::ifstream& infile, Reduced_grid* grid, 
    int X_col_id, int Y_col_id, int Z_col_id,
    float x_size, float y_size, float z_size);
};  
 

#endif