# Task 4

## Monotonic sequence

### Problem

There are some lines of decimal numbers in the text file, separated by spaces. Find the minimal number of decimals after the removal of which the numerical sequence becomes monotonous.

### Run

* Run `make` to launch the progect
* Run `make fill` to generate input sequence
* Run 'make plot' to plot the sequenses

If you want to change quantity of generated decimals change **N** value in [fill.c](https://github.com/vakulin95/C-tasks/blob/master/4/fill.c) file.

```C
#define N 10
```

### Info

In [data](https://github.com/vakulin95/C-tasks/tree/master/4/data) folder located files with input and output sequences. This files generated automaticaly as a part of progect. Also in file *seq_out.png* you can find plotted sequenses to control the result.

This project used the algorithm presented [here](https://en.wikipedia.org/wiki/Longest_increasing_subsequence).
