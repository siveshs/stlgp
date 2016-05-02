### Command-line based STL viewer
### Created by Sivesh Selvakumar Copyright 2016
### This command-line based STL viewer only works on ASCII STL files. It
### utilizes awk and GNUplot. GNUplot must've already been set to use x11
### as the terminal.

#!/bin/bash

#Create a temporary file to hold pre-processed STL data
touch tmp-stl

#Create a temporary file to hold GNUplot code
touch tmp-gnuplot-code

awk '
/vertex/ { print $2, $3, $4}
/endloop/ {print ""}
' $1 > tmp-stl

echo "Parsing of ASCII STL file complete"
echo
echo "Running GNUPlot"
echo

echo "
  set view equal xyz
  set xyplane at 0
  set xlabel \"X Axis\"
  set ylabel \"Y Axis\"
  set zlabel \"Z Axis\"
  splot \"tmp-stl\" with lines 
  pause -1 \"Press any key to end the program\"
" > tmp-gnuplot-code

gnuplot tmp-gnuplot-code

rm tmp-stl
rm tmp-gnuplot-code
