#ifndef __GSTLAPPLI_QTPLUGINS_NEIGH_FILTER_H__
#define __GSTLAPPLI_QTPLUGINS_NEIGH_FILTER_H__


#include <GsTLAppli/extra/qtplugins/common.h>
#include <qgroupbox.h>
#include <qstring.h>
#include <QResizeEvent>

class QSpinBox;
class QCheckBox;

class QTPLUGINS_DECL  OctantSearchInput : public QWidget {
  Q_OBJECT

public:
  OctantSearchInput( QWidget *parent = 0, const char *name = 0);
  virtual ~OctantSearchInput();

  void set_min_octant( int min_octant);
  void set_min_per_octant( int min_per_octant );
  void set_max_per_octant( int max_per_octant );  
 
  int min_octant() const;
  int min_per_octant() const;
  int max_per_octant() const;


private:
  QSpinBox *min_octant_;
  QSpinBox *min_per_octant_;
  QSpinBox *max_per_octant_;
   
};


class QTPLUGINS_DECL  AdvancedNeighborhoodInput : public QWidget {
  Q_OBJECT

public:
  AdvancedNeighborhoodInput( QWidget *parent = 0, const char *name = 0);
  virtual ~AdvancedNeighborhoodInput();

  void set_min_octant( int min_octant);
  void set_min_per_octant( int min_per_octant );
  void set_max_per_octant( int max_per_octant );  
  void set_octant_search( OctantSearchInput* octant );
  
  void set_use_advanced_options( bool ok);
  void set_use_selected_region(bool ok);
  void set_use_octant_search(bool ok);
 
  int min_octant() const;
  int min_per_octant() const;
  int max_per_octant() const;
  OctantSearchInput* octant() const;

  bool use_selected_region() const;
  bool use_octant_search() const;
  bool use_advanced_options() const;

private:
  OctantSearchInput *octant_input_;
  QCheckBox *use_advanced_options_;
  QCheckBox *use_octant_search_;
  QCheckBox *use_selected_region_;
   
};

#endif