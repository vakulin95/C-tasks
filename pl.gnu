cd "data"

set style data lines
set grid

plot "input.txt", "out.txt" u 1:2

cd ".."
