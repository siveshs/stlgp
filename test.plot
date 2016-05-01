#Gnuplot file for testing 3D plots
set title "3D test plot"
set xlabel "X-axis"
set ylabel "Y-axis"
set zlabel "Z-axis"

#Try to do palette mapped 3D
#set pm3d
#set dgrid3d
set surface

splot "2datafile.dat" with linespoints linecolor "blue" linewidth 2

#Force GNUplot to wait for keyboard input prior to exiting
pause -1
