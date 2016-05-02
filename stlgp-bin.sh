### Command-line based STL viewer
### Created by Sivesh Selvakumar Copyright 2016
### This command-line based STL viewer only works on Binary STL files. It
### utilizes a custom C-script and GNUplot.
### GNUplot must've already been set to use x11 as the terminal.

### No command-line parsing is being performed so the input filename
### cannot have spaces.


#!/bin/bash

./stl $1
echo "Parsing of binary STL file complete"
echo
echo "Running GNUPlot"
echo
echo "
  set view equal xyz
  set xyplane at 0
  set xlabel \"X Axis\"
  set ylabel \"Y Axis\"
  set zlabel \"Z Axis\"
  splot \"gnu_plot_output.dat\" with points
  pause -1 \"Press any key to end the program\"
" > tmp-gnuplot-code

gnuplot tmp-gnuplot-code

rm gnu_plot_output.dat
rm tmp-gnuplot-code
