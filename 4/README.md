# Task 4

## Monotonic sequence

### Problem

There are some lines of decimal numbers in the text file, separated by spaces. Find the minimal number of decimals after the removal of which the numerical sequence becomes monotonous.

### Run

* Run `make` to launch the project
* Run `make fill` to generate input sequence
* Run 'make plot' to plot the sequences

If you want to change quantity of generated decimals change **N** value in [fill.c](https://github.com/vakulin95/C-tasks/blob/master/4/fill.c) file.

```C
#define N 10
```

### Info

In [data](https://github.com/vakulin95/C-tasks/tree/master/4/data) folder located files with input and output sequences. These files generated automatically as a part of project. Also in file *seq_out.png* you can find plotted sequences to control the result.

This project used the algorithm presented [here](https://en.wikipedia.org/wiki/Longest_increasing_subsequence).
