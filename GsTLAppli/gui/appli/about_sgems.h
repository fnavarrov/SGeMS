
 /*
 Author: Aboucher: ar2tech
 Copyright: ar2tech
*/
//-----------------------------------------------
/** Dialog box to display about sgems 
 */

#ifndef ABOUT_SGEMS_H_
#define ABOUT_SGEMS_H_

#include <GsTLAppli/gui/common.h>
#include <QDialog>
#include <QTabWidget>

class GUI_DECL About_sgems : public QDialog
{
public:
  About_sgems(QWidget * parent = 0);


private:
  QTabWidget* tab_;

  void insert_about_page();
  void insert_what_is_new_page();
  void insert_python_page();
  void insert_ar2tech_page();
  void insert_SCRF_page();
  void insert_help_page();
  

  
  
};

#endif