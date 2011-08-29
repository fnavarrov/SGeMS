 /*
 Author: Aboucher: ar2tech
 Copyright: ar2tech
*/


#include <GsTLAppli/gui/appli/about_sgems.h>

#include <QTextBrowser>
#include <QTextDocument>
#include <QTextImageFormat>
#include <QVBoxLayout>
#include <QUrl>
#include <QFont>
#include <QSizePolicy>


About_sgems::About_sgems(QWidget * p) : QDialog(p)
{

  

  QSizePolicy size_policy;
  size_policy.setHorizontalPolicy(QSizePolicy::Minimum);
  this->setSizePolicy(size_policy);
  //this->setMinimumHeight(1500);

  tab_ = new QTabWidget(this);
  tab_->setTabShape(QTabWidget::Triangular);
  QSizePolicy tab_policy;
  tab_policy.setVerticalPolicy(QSizePolicy::Maximum);
  tab_policy.setHorizontalPolicy(QSizePolicy::Expanding);
  tab_->setSizePolicy(tab_policy);
  tab_->setMinimumHeight(400);
  


  QVBoxLayout* vlayout = new QVBoxLayout( this );


  QTextBrowser * text_browser_image = new QTextBrowser(this);
  text_browser_image->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  text_browser_image->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  text_browser_image->setOpenExternalLinks(true);
  text_browser_image->setFrameStyle(QFrame::NoFrame);



  QTextDocument* document_header = text_browser_image->document();
  QTextCursor cursor(document_header);// = text_browser_image->cursorForPosition(); //= new QTextCursor(document);

  QImage image(":/icons/appli/Pixmaps/ar2tech-sgems.png");
  QUrl url(":/icons/appli/Pixmaps/ar2tech-sgems.png");

  document_header->addResource( QTextDocument::ImageResource, url, QVariant ( image ) );
  text_browser_image->setHtml("<a href=http://www.ar2tech.com><img src=\":/icons/appli/Pixmaps/ar2tech-sgems.png\"></a>");
  text_browser_image->setMinimumWidth(image.width());
  text_browser_image->setMinimumHeight(image.height());
  QSizePolicy image_policy;
  image_policy.setVerticalPolicy(QSizePolicy::Fixed);
  image_policy.setHorizontalPolicy(QSizePolicy::Fixed);
  text_browser_image->setSizePolicy(image_policy);    

  this->setMinimumWidth(image.width());

  text_browser_image->setReadOnly(true);

  vlayout->addWidget(text_browser_image);
  vlayout->addWidget(tab_);
  vlayout->insertStretch(-1);
  this->setLayout(vlayout);
  this->layout()->setSizeConstraint( QLayout::SetFixedSize );

  this->insert_about_page();
  this->insert_what_is_new_page();
  this->insert_python_page();
  this->insert_ar2tech_page();
  this->insert_SCRF_page();
  this->insert_help_page();

}

void About_sgems::insert_about_page(){

  QTextBrowser * text_browser = new QTextBrowser(this);
  text_browser->setOpenExternalLinks(true);
  QSizePolicy bowser_policy;
  bowser_policy.setVerticalPolicy(QSizePolicy::Expanding);
  text_browser->setSizePolicy(bowser_policy);
  tab_->addTab(text_browser, "About SGeMS");
 

  QFont font;
  font.setWeight(QFont::Normal);
  font.setPointSize(12);


  QTextDocument* document = text_browser->document();
  document->setTextWidth(300);
  document->setDefaultFont(font);
  QTextCursor cursor(document);

  cursor.insertBlock();
  cursor.insertHtml("<p>The Stanford Geostatistical Modeling Software (<a href=http://sgems.sourceforge.net>SGeMS</a>) is an open-source computer package for solving problems involving spatially related variables. It provides geostatistics practitioners with a user-friendly interface, an interactive 3-D visualization, and a wide selection of algorithms.</p><br>");
  cursor.insertBlock();   
  cursor.insertHtml("<h4>History</h4><p>SGeMS was created by Nicolas Remy during his doctoral thesis at Stanford University under the direction of Prof. Jef Caers and Andre Journel and funded by the Stanford Center for reservoir forecasting (<a href=http://scrf.stanford.edu/>SCRF</a>).  After Nicolas Remy departure Alexandre Boucher and Jianbing Wu continue to develop and maintain the platform in addition of co-writing a book, <a href=http://www.amazon.com/Applied-Geostatistics-SGeMS-Users-Guide/dp/0521514142>Applied Geostatistics with SGeMS</a>.  Others contributor includes Ting Li, Amisha Maharaja and Rahul Gupta.  Lately the software is being developed by Dr. Boucher at <a href=http://www.ar2tech.com>Advanced Resources & Risk Technology, LLC</a>.</p>");
  cursor.setPosition(0);
  text_browser->setTextCursor(cursor);
}


void About_sgems::insert_python_page(){

  QTextBrowser * text_browser = new QTextBrowser(this);
  text_browser->setOpenExternalLinks(true);
  QSizePolicy bowser_policy;
  bowser_policy.setVerticalPolicy(QSizePolicy::Expanding);
  text_browser->setSizePolicy(bowser_policy);
  tab_->addTab(text_browser, "Python scripting");
  
  QFont font;
  font.setWeight(QFont::Normal);
  font.setPointSize(12);


   QTextDocument* document = text_browser->document();
   document->setTextWidth(300);
   document->setDefaultFont(font);
   QTextCursor cursor(document);// =  text_browser->cursorForPosition(); //= new QTextCursor(document);

   cursor.insertBlock();
   cursor.insertHtml("<p>Users can perform complex tasks using the embedded <a href=http://www.python.org>python</a> scripting language.   Python is an easy to learn yet powerful language.  Coupled with Python, SGeMS provides a powerful and adaptable geostatistical platform for geomodeling.</p><p> SGeMS comes  with a basic Python library.  The advanced user should install the complete Python binaries in addition to a suite of scientific libraries such as scipy and matplotlib.</p>");
   cursor.insertBlock();   
   cursor.insertHtml("<DL><DT> <a href=http://www.python.org >Python</a><DD>The Python language<br><DT> <a href=http://www.scipy.org >Scipy</a> (see <a href=http://www.lfd.uci.edu/~gohlke/pythonlibs/#numpy>here</a> and <a href=http://www.lfd.uci.edu/~gohlke/pythonlibs/#scipy>here</a> for 64 bits binaries)<DD>  Library for scientific computing<br><DT> <a href=http://matplotlib.sourceforge.net >Matplotlib</a> (see <a href=http://www.lfd.uci.edu/~gohlke/pythonlibs/#matplotlib>here</a> for 64 bits binaries)<DD> Library for data visualization<br></DL>");
   cursor.insertBlock();   
   cursor.insertHtml("<p>This SGeMS version has been compiled with python 2.7.  See this <a href=http://sgems.sourceforge.net/?q=node/13>tutorial</a> to get started on using python with SGeMS.</p>");
   cursor.setPosition(0);
   text_browser->setTextCursor(cursor);
}


void About_sgems::insert_ar2tech_page(){

  
  QTextBrowser * text_browser = new QTextBrowser(this);
  text_browser->setOpenExternalLinks(true);
  QSizePolicy bowser_policy;
  bowser_policy.setVerticalPolicy(QSizePolicy::Expanding);
  text_browser->setSizePolicy(bowser_policy);
  tab_->addTab(text_browser, "AR2Tech");

  QFont font;
  font.setWeight(QFont::Normal);
  font.setPointSize(12);


  QTextDocument* document = text_browser->document();
  document->setTextWidth(300);
  document->setDefaultFont(font);
  QTextCursor cursor(document);// =  text_browser->cursorForPosition(); //= new QTextCursor(document);

  cursor.insertBlock();
  cursor.insertHtml("<p>AR2Tech is a consulting and software firm that provides geostatistical solutions and training with both novel and classical geostatistical techniques. AR2Tech has been  developing SGeMS plugins for complex data set and script for automating workflows for clients in the <a href=http://ar2tech.com/mining>mining</a>, <a href=http://ar2tech.com/energy>energy</a> and <a href=http://ar2tech.com/environment >environment </a> sectors.  It also offers <a href=http://ar2tech.com/training>training</a> on geostatistics and SGeMS; see the website at <a href=http://ar2tech.com/training >ar2tech.com/training</a> for more detailed on upcoming shortcourses.  For more information please contact us at <a href=http://ar2tech.com/contact>ar2tech.com/contact</a></p>");
  cursor.setPosition(0);
  text_browser->setTextCursor(cursor);
}

void About_sgems::insert_help_page(){

  
  QTextBrowser * text_browser = new QTextBrowser(this);
  text_browser->setOpenExternalLinks(true);
  QSizePolicy bowser_policy;
  bowser_policy.setVerticalPolicy(QSizePolicy::Expanding);
  text_browser->setSizePolicy(bowser_policy);
  tab_->addTab(text_browser, "Help");

  QFont font;
  font.setWeight(QFont::Normal);
  font.setPointSize(12);

  QTextDocument* document = text_browser->document();
  document->setTextWidth(300);
  document->setDefaultFont(font);
  QTextCursor cursor(document);// =  text_browser->cursorForPosition(); //= new QTextCursor(document);

  cursor.insertBlock();
  cursor.insertHtml("Sources for help:<DL><DT><a href=http://www.amazon.com/Applied-Geostatistics-SGeMS-Users-Guide/dp/0521514142>Book</a>: Applied Geostatistics with SGeMS<DD> Contains description of the algorithms and a brief recall of theory.  Do not include the addition to this beta version such as the region.<DT><a href=http://sgems.sourceforge.net/?q=node/18>SGeMS Website</a><DD>This section aims at complementing the book <i>Applied Geostatistics with SGeMS</i> published by Cambridge University Press. The user can find additional resources regarding Python scripting and overall use of SGeMS.<DT> <a href=http://sgems.sourceforge.net/?q=forum/10>Forums</a><DD> A forum where users and developers can help each others.<DT><a href=http://ar2tech.com/contact>AR2Tech</a><DD> Contact AR2Tech for professional help and/or training.<DT><a href=http://www.linkedin.com>linkedin</a><DD>Connect ot the SGeMS group on linkedIn to keep informed on the latest news</DL></p>");
  cursor.setPosition(0);
  text_browser->setTextCursor(cursor);
}




void About_sgems::insert_what_is_new_page(){

  
  QTextBrowser * text_browser = new QTextBrowser(this);
  text_browser->setOpenExternalLinks(true);
  QSizePolicy bowser_policy;
  bowser_policy.setVerticalPolicy(QSizePolicy::Expanding);
  text_browser->setSizePolicy(bowser_policy);
  tab_->addTab(text_browser, "What's new");

  QFont font;
  font.setWeight(QFont::Normal);
  font.setPointSize(12);

  QTextDocument* document = text_browser->document();
  document->setTextWidth(300);
  document->setDefaultFont(font);
  QTextCursor cursor(document);// =  text_browser->cursorForPosition(); //= new QTextCursor(document);

  cursor.insertBlock();
  cursor.insertHtml("<p>This beta version includes several new features compared to the previous version (the one distributed with the book). Some of these features are well tested others not as well or not fully implemeted.<h4>Improvements</h4><DL><DT>Regions<DD>All geostatical algorihtms can be constrained within a sub-space of a grid.  This sub-space is defined by a region.  The region is well implemented within the algorithms but had not been implemented for the visualization.  This feature will be available in the next version (likely January 2012).<DT>Python commands<DD>Several python commands had been added to provide better control from python scripts.  See <a href=http://sgems.sourceforge.net/>here</a> for a list.<DT>CSV file format<DD> SGeMS can now load data from comma separated file (csv).  The first line containes the names of the variable with the variables in following lines.<DT>Alpha numeric field<DD>SGeMS can now load alpha numeric field when imported from a csv file format.  There is now a structure called a categorical definition that will provide the mapping between a alpha-numeric field and its corresponding numerical values.<DT>Groups<DD>Property can be grouped together for a cleaner display.  For instance a set of simulations ort indicators will be inside one group.  Python commands had been added to use that functionality.<DT>Right clicking actions<DD>Right clicking on a grid, a group or a property name provides some options such as creating indicator data or taking the log of each value within a property.<DT>Pyhton plugins<DD>You can have access to user-defined python script when right-clicking on either a property or a group of properties.<DT>Quadrant Search<DD>Specification of search strategy for the variogram-based algorithms.<DT>Masked Grid<DD>A type of grid that is build by applying a mask on a cartesian grid.  The advantage is that if only 50% of the blocks are actually active, the array necessary to store the values will be 50% smaller than the one use for the full grid.  This is mostly useful on very large grid.  A masked grid could be mimicked by using a cartesian grid with a region defining the mask.<DT>64 bits<DD>Eanble the use of very large grids and better performace of the SNESIM algorihtm.</DL><h4>Regressions</h4><DL><DT>Volume rendering<DD>The volume rendering is now only possible on NVIDIA video card.  This will not be fixed on this version since the next SGeMS release will have a completely new (and improved) visualization features that includes the visualization of the regions.<DT>Variogram modeling<DD>The regions had not been implemented in the variogram modeling tool.  This part of the software is unchanged hence has fallen behind in this version.<DT>Kriging from blocks<DD>The algorithms BKRIG, BESIM and BSSIM have been removed, they were too unstable and I do not have the time to maintain them.  Contact me if you were interested in these algorithms.</DL></p>");
  cursor.setPosition(0);
  text_browser->setTextCursor(cursor);
}



void About_sgems::insert_SCRF_page(){

  
  QTextBrowser * text_browser = new QTextBrowser(this);
  text_browser->setOpenExternalLinks(true);
  QSizePolicy bowser_policy;
  bowser_policy.setVerticalPolicy(QSizePolicy::Expanding);
  text_browser->setSizePolicy(bowser_policy);
  tab_->addTab(text_browser, "SCRF");

  QFont font;
  font.setWeight(QFont::Normal);
  font.setPointSize(12);

  QTextDocument* document = text_browser->document();
  document->setTextWidth(300);
  document->setDefaultFont(font);
  QTextCursor cursor(document);// =  text_browser->cursorForPosition(); //= new QTextCursor(document);

  cursor.insertBlock();
  cursor.insertHtml("<p>The Stanford Center for Reservoir Forecasting (<a href=http://scrf.stanford.edu>SCRF</a>) is an industrial affiliates program in the Energy Resources Engineering department of the School of Earth Sciences at Stanford University. SCRF was initiated in 1988 to further the development and integration of geological, geophysical and reservoir engineering data and techniques for forecasting reservoir performance. This program is widely open to energy companies, geophysical services companies, research institutes and consultants who wish to support and benefit from the interdisciplinary research team of SCRF.</p>");
  cursor.setPosition(0);
  text_browser->setTextCursor(cursor);
}



