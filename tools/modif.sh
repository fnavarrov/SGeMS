#! /bin/sh
# look for all .h .cpp and .cc files and replace GeoRand with GeoRand

for i in `find $GEORANDHOME -name "*.*" -o -iname "*make*"`
do 
  sed -e s/GeoRand/GeoRand/ $i | sed -e s/GEORAND/GEORAND/ > tmp.txt
  mv tmp.txt $i
done

