/**********************************************************************
** Author: Ting Li
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

/* CVS version control block - do not edit manually
 *  $RCSfile: simpleps.h,v $
 *  $Revision: 1.1.1.1 $
 *  $Date: 2007/10/30 18:14:22 $
 *  $Source: /cvsroot/sgems/GsTLAppli-qt4/GsTLAppli/utils/simpleps.h,v $ */

#ifndef SIMPLEPS_H
#define SIMPLEPS_H

#include <fstream>
#include <string>
#include <QVector>
#include <vector>

class QwtPlot;
class QwtData;

typedef std::vector< std::pair<std::string,std::string> > Stat;

// A simple toolset for writing a plot into postscript format
class SimplePs 
{
public:
	SimplePs(std::string, QwtPlot *, Stat &, bool);
	SimplePs(std::string, QwtPlot *);
	~SimplePs() { _o.close(); }
	void init();
	bool isopen();
	void drawYRightAxis(std::string l);
	void drawAxis(std::string, std::string, std::string, bool);
	void drawCurve(QwtData &, int);
	void drawCurve(QwtData & , int, bool);
private:
	void drawLine(int x1, int y1, int x2, int y2, float linewidth);
	void drawText(int x, int y, std::string font, int scale, int rotate,std::string);

	void drawTic(int, int, bool, bool,bool);
	void draw_stats();
	std::ofstream _o;
	QwtPlot * _plot;
	Stat _stats;
	bool _drawStats;
};

#endif
