Project name: Five-Number Summary

Given an input file of integer values, this program will compute all the statistics included in a five-number summary: the minimum value, the 25th, 50th, and 75th percentiles, and the maximum value,
using 4 methods; std::sort, using quickselect 3 times, then calculate the min and max separately, using modifed quickselect to recurse if any of the 5 values are in the subrange, and using 
a modified counting sort that uses hashes.
