#!/bin/sh

for i in `ls *.h *.cpp` 
do 
  sed "s:GsTLAppli/grid:GsTLAppli/grid/grid_model:" $i > .tmp 
  mv .tmp $i
done
