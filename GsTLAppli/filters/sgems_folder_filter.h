/*
 * sgems_input_filter.h
 *
 *  Created on: Jun 16, 2010
 *      Author: aboucher
 */

#ifndef SGEMS_INPUT_FILTER_H_
#define SGEMS_INPUT_FILTER_H_

#include <GsTLAppli/filters/common.h>
#include <GsTLAppli/filters/filter.h>
#include <QtXml>
#include <QDir>
#include <QDomDocument>

class Geostat_grid;
class CategoricalPropertyDefinitionName;

class Sgems_folder_input_filter: public Input_filter {
public:
  static Named_interface* create_new_interface( std::string& );
public:
	Sgems_folder_input_filter();
	virtual ~Sgems_folder_input_filter();

  virtual std::string filter_name() const { return "sgems_beta" ; }
  virtual std::string file_extensions() const { return "*.grid"; }

  virtual bool can_handle( const std::string& filename );
  virtual Geostat_grid* read( const std::string& filename,
                              std::string* errors = 0 );

protected :
  Geostat_grid* read_cartesian_grid(QDir dir,const QDomElement& elem, std::string* errors);
  Geostat_grid* read_masked_grid(QDir dir,const QDomElement& elem, std::string* errors);
  Geostat_grid* read_point_set(QDir dir,const QDomElement& elem, std::string* errors);

  bool read_properties(QDir dir,const QDomElement& dom, Geostat_grid* grid, std::string* errors);
  bool read_regions(QDir dir,const QDomElement& dom, Geostat_grid* grid, std::string* errors);
  bool read_group(const QDomElement& dom, Geostat_grid* grid, std::string* errors);
  bool read_category_definition(const QDomElement& root, Geostat_grid* grid, std::string* errors);

  bool check_for_conflict(CategoricalPropertyDefinitionName* def, const QStringList& cat_names);
  bool create_categorial_definition( QString& name, QStringList& cat_names);
};

class Sgems_folder_output_filter: public Output_filter {
public:
  static Named_interface* create_new_interface( std::string& );
public:
  Sgems_folder_output_filter();
  virtual ~Sgems_folder_output_filter();

  virtual std::string filter_name() const { return "sgems_beta" ; }
  virtual std::string file_extensions() const { return "*.sgems"; }

  virtual bool write( std::string outfile, const Geostat_grid* grid,
                      std::string* errors = 0 );

protected :

  bool removeDir(const QString &dirName);

  QDomElement write_grid_geometry(QDir dir,QDomDocument& dom, const Geostat_grid* grid);
  QDomElement write_masked_grid_geometry( QDir dir, QDomDocument& dom, const  Geostat_grid* grid);
  QDomElement write_pointset_geometry( QDir dir,  QDomDocument& dom, const Geostat_grid* grid );
  QDomElement write_cartesian_grid_geometry( QDir dir, QDomDocument& dom, const Geostat_grid* grid );

  QDomElement write_properties(QDir dir, QDomDocument& dom, const Geostat_grid* grid);
  QDomElement write_regions(QDir dir, QDomDocument& dom, const Geostat_grid* grid);
  QDomElement write_group(QDomDocument& dom, const Geostat_grid* grid);
  QDomElement write_category_definition(QDomDocument& dom, const Geostat_grid* grid);

	std::string get_grid_name(const Geostat_grid* grid);
};

#endif /* SGEMS_INPUT_FILTER_H_ */
