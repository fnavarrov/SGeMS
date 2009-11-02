#!/bin/sh

APPLIDIR=/home/nremy/SCRF/GsTLAppli
BASENAME=`basename $APPLIDIR`
CURDIR=`pwd`
cd $APPLIDIR; cd ..;

find $BASENAME -name "*.tgz" -o -name "*.txt" -o -name "*.dat" -o -name "*.tmp" -o -name "tmp" -o -name "*.tar*" -o -name "*.so*" -o -name "moc_*.cpp" -o -name "moc_*.h" -o -name "*.old*" -o -name "*.sav*" -o -name "Makefile" -o -name "*.out" -o -name "*.log" -o -name "*~" -o -name "*.dbg" -o -name "*.sh" -o -name "*.pl" -o -name "CVS" > exclude.lst
echo "$BASENAME/bin/linux" >> exclude.lst
echo "$BASENAME/lib/linux" >> exclude.lst

tar czvfX GsTLAppli.tgz exclude.lst $BASENAME
#rm exclude.lst
mv GsTLAppli.tgz $CURDIR
cd $CURDIR
