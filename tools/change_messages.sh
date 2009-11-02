#! /bin/sh
# look for all .h .cpp and .cc files and replace GeoRand with GeoRand

for i in `find $GSTLAPPLIHOME/src -name "*.h" -o -name "*.cpp"`
do 
  echo "working on $i"
  sed  s:gstl_message\(:appli_message\(: $i | sed s:gstl_warning\(:appli_warning\(: | sed s:gstl_assert\(:appli_assert\(:  > tmp.txt
  echo "done"
  mv tmp.txt $i
done

