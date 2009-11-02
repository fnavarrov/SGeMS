#! /bin/sh
# add dll_export macro for each class declaration
# The script has to be run from src/

GSTLAPPLI_HOME=/home/nremy/SCRF/GsTLAppli

help()
{
    cat<<EOF
Add the dll_export keyword where needed. The script must be run from src/

USAGE: dll_export -h|-a|-c

OPTIONS:
  -h: write this help message
  -a: do it for all subdirectories in src/
  -c: do it only for the current directory

EOF
    exit 0
}


add_dll_keyword() {
  HERE=`/bin/sh -c pwd`
  LOWER_CASE_BASENAME=`basename $HERE`
  BASENAME=`echo $LOWER_CASE_BASENAME | tr 'a-z' 'A-Z'`

  for i in `find . -name "*.h" -o -name "*.cpp"`
  do
    sed -e "/\{/s/class/class "$BASENAME"_DECL/" $i  > tmp.txt
    mv tmp.txt $i
  done
}

full_setup() {
  echo "working on $1"
  cd $1
  add_dll_keyword
  perl $GSTLAPPLI_HOME/tools/include.pl >> .include.pl.log
  cd ..
}

# the main program

[ "$#" -eq 0 ] && help

while [ -n "$1" ]; do
case $1 in
    -h) help;; # function help is called
    -a) all=1; shift 1;; 
    -c) all=0; shift 1;;
    --) shift;break;; # end of options
    -*) echo "error: no such option $1. -h for help";exit 1;;
    *)  break;;
esac
done

if [ "$all" -eq 1 ]; then
  for dir in actions appli filters utils math grid geostat gui
  do
    full_setup $dir
  done
else
  full_setup .
fi
