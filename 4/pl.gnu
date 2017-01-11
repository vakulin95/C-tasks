set terminal png size 900, 900
set xtics auto
set ytics auto
set mxtics
set mytics
set grid
set style line 1 lc rgb 'blue' lt 1 lw 2 pt 7 ps 1.5
set style line 2 lc rgb 'red' lt 1 lw 2 pt 7 ps 1.5

plotfile1 = "data/input.dat"
plotfile2 = "data/out.dat"

title1 = "Input sequence"
title2 = "Output sequence"

set output "data/seq_out.png"

set title ""
plot plotfile1 title title1 with linespoints ls 1, plotfile2 u 1:2 title title2 with linespoints ls 2

unset out
