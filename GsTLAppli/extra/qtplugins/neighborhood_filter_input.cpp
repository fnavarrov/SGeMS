#include <GsTLAppli/extra/qtplugins/neighborhood_filter_input.h>

#include <qlabel.h>
#include <qspinbox.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>

OctantSearchInput::OctantSearchInput( QWidget *parent, const char *name)
  : QWidget( parent ){
  
  if (name)
    setObjectName(name);
  
  QVBoxLayout *main_layout = new QVBoxLayout( this );
  QGroupBox *octant_box = new QGroupBox( this);
  QHBoxLayout *ho = new QHBoxLayout(octant_box);
  ho->setContentsMargins(1,1,1,1);


  QVBoxLayout *v_min_octant = new QVBoxLayout( octant_box );
  QVBoxLayout *v_min_per_octant = new QVBoxLayout( octant_box );
  QVBoxLayout *v_max_per_octant = new QVBoxLayout( octant_box );


  v_min_octant->addWidget(new QLabel("Min Non-empty Octant",octant_box));
  v_min_per_octant->addWidget(new QLabel("Min per Octant",octant_box));
  v_max_per_octant->addWidget(new QLabel("Max per Octant",octant_box));

  min_octant_  = new QSpinBox(octant_box);
  min_per_octant_  = new QSpinBox(octant_box);
  max_per_octant_  = new QSpinBox(octant_box);

  min_octant_->setMinimum( 0 );
  min_per_octant_->setMinimum( 0 );
  max_per_octant_->setMinimum( 0 );

  v_min_octant->addWidget(min_octant_);
  v_min_per_octant->addWidget(min_per_octant_);
  v_max_per_octant->addWidget(max_per_octant_);

  ho->addLayout( v_min_octant );
  ho->addLayout( v_min_per_octant );
  ho->addLayout( v_max_per_octant );

  octant_box->setLayout( ho );
  octant_box->setTitle("Octant Search");


  main_layout->addWidget( octant_box );

}

OctantSearchInput::~OctantSearchInput(){}


void OctantSearchInput::set_min_octant( int min_octant) {
  min_octant_->setValue( min_octant );
}

void OctantSearchInput::set_min_per_octant( int min_per_octant ){
  min_per_octant_->setValue( min_per_octant );
}

void OctantSearchInput::set_max_per_octant( int max_per_octant ){
  max_per_octant_->setValue( max_per_octant );
}  
 
int OctantSearchInput::min_octant() const{
  return min_octant_->value();
}
int OctantSearchInput::min_per_octant() const{
  return min_per_octant_->value();
}
int OctantSearchInput::max_per_octant() const{
  return max_per_octant_->value();
}


/* ------------------------------
* AdvanceNeighborhoodInput
* -------------------------------
*/

AdvancedNeighborhoodInput::AdvancedNeighborhoodInput( 
  QWidget *parent, const char *name): QWidget( parent ){

  if (name)
    setObjectName(name);

  QVBoxLayout *main_layout = new QVBoxLayout( this );
  use_advanced_options_ = new QCheckBox("Advanced search options", this);

  QGroupBox *advanced_box = new QGroupBox( this);
  advanced_box->setHidden( true );
  QVBoxLayout *va = new QVBoxLayout(advanced_box);
  va->setContentsMargins(0,0,0,0);


  use_octant_search_ = new QCheckBox("Use octant Search", this);
  use_octant_search_->setText("Use octant Search");

  use_selected_region_ = new QCheckBox("Use selected region for neighborhood search", this);
  octant_input_ = new OctantSearchInput(this,"OctantParameters");
  octant_input_->setDisabled( true );
  octant_input_->setContentsMargins(1,1,1,1);

  va->addWidget(use_selected_region_);
  va->addWidget(use_octant_search_);
  va->addWidget(octant_input_);
  advanced_box->setLayout(va);

  main_layout->addWidget(use_advanced_options_);
  main_layout->addWidget(advanced_box);
  
  QObject::connect( use_advanced_options_, SIGNAL( toggled(bool) ),
		    advanced_box, SLOT( setVisible(bool) ) );

  QObject::connect( use_octant_search_, SIGNAL( toggled(bool) ),
		    octant_input_, SLOT( setEnabled(bool) ) );
 /*
  QCheckBox* use_selected_region_;  

  QGroupBox *octant_box = new QGroupBox( this);
  QHBoxLayout *ho = new QHBoxLayout(octant_box);

  main_layout->addWidget(use_selected_region);
  main_layout->addWidget(use_octant_search_);
  */

}


AdvancedNeighborhoodInput::~AdvancedNeighborhoodInput(){}

void AdvancedNeighborhoodInput::set_min_octant( int min_non_empty_octant){
  octant_input_->set_min_octant(min_non_empty_octant);
}

void AdvancedNeighborhoodInput::set_min_per_octant( int min_neigh_per_octant ){
  octant_input_->set_min_per_octant(min_neigh_per_octant);
}

void AdvancedNeighborhoodInput::set_max_per_octant( int max_neigh_per_octant ){
  octant_input_->set_max_per_octant(max_neigh_per_octant);
} 

void AdvancedNeighborhoodInput::set_octant_search( OctantSearchInput* octant ){
  octant_input_ = octant;
}

void AdvancedNeighborhoodInput::set_use_selected_region(bool ok){
  if(ok) use_selected_region_->setChecked(Qt::Checked);
  else use_selected_region_->setChecked(Qt::Unchecked);
}

void AdvancedNeighborhoodInput::set_use_advanced_options(bool ok) {
  if(ok) use_advanced_options_->setChecked(Qt::Checked);
  else use_advanced_options_->setChecked(Qt::Unchecked);
}

void AdvancedNeighborhoodInput::set_use_octant_search(bool ok){
  if(ok) use_octant_search_->setChecked(Qt::Checked);
  else use_octant_search_->setChecked(Qt::Unchecked);
}
 
int AdvancedNeighborhoodInput::min_octant() const{
  return octant_input_->min_octant();
}

int AdvancedNeighborhoodInput::min_per_octant() const{
  return octant_input_->min_per_octant();
}

int AdvancedNeighborhoodInput::max_per_octant() const{
  return octant_input_->max_per_octant();
} 

OctantSearchInput* AdvancedNeighborhoodInput::octant() const{
  return octant_input_;
}

bool AdvancedNeighborhoodInput::use_selected_region() const{
  return use_selected_region_->isChecked();
}
bool AdvancedNeighborhoodInput::use_octant_search() const{
  return use_octant_search_->isChecked();
}

bool AdvancedNeighborhoodInput::use_advanced_options() const{
  return use_advanced_options_->isChecked();
}