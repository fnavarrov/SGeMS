#!/bin/sh

USAGE="Usage: $PROG [-a] dirname"


DO_MAKEMAKE=0

case $1 in
   -a|-app)
       DO_MAKEMAKE=1
       shift 1
       ;;
   -*)
       echo "** $PROG: unrecognized option: $1"
       echo $USAGE
       exit 1
       ;;
esac


if [ ! -d $1 ]; then  
  echo "$1 is not a directory"; 
  exit 1 
fi


cd $1;
APPLIDIR=`pwd`;
if [ ! -d $APPLIDIR/src ]; then
  echo "$APPLIDIR/src is not a valid directory"
  exit 1
fi

cd $APPLIDIR/src;
 
for i in actions appli filters geostat grid gui math utils
do 
  if [ -d $APPLIDIR/src/$i ];
  then 
    cd $APPLIDIR/src/$i;
    echo "generating vc++ project for library $i"
    if [ $DO_MAKEMAKE -eq 1 ]; then
      Makemake -l;
    fi
    qmake -t vclib -o $i.dsp $i.pro;
  else
    echo "$APPLIDIR/src/$i is not a directory"
  fi
done



# Special cases:

cd $APPLIDIR/src/extra/gui
echo "generating vc++ project for library extragui"
if [ $DO_MAKEMAKE -eq 1 ]; then
  Makemake -l;
fi
qmake -t vclib -o extragui.dsp gui.pro;

cd $APPLIDIR/src/extra/
for i in qtplugins qwt
do 
  if [ -d $APPLIDIR/src/extra/$i ];
  then  
    cd $APPLIDIR/src/extra/$i;
    echo "generating vc++ project for library $i"
    if [ $DO_MAKEMAKE -eq 1 ]; then
      Makemake -l;
    fi
    qmake -t vclib -o $i.dsp $i.pro;
  else
    echo "$i is not a directory"
  fi 
done


cd $APPLIDIR/src/main
if [ $DO_MAKEMAKE -eq 1 ]; then
  Makemake -a;
fi
qmake -t vcapp -o main.dsp main.pro
 

