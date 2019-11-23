# Step Numbers

PE 178

Task description:

Consider the number 45656.

It can be seen that each pair of consecutive digits of 45656 has a difference of one.
A number for which every pair of consecutive digits has a difference of one is called a step number.
A pandigital number contains every decimal digit from 0 to 9 at least once.
How many pandigital step numbers less than 10^40 are there? 

***

We can kind of think of this problem as counting the number of random walks X_n (10 <= n < 40) that begin on 1 <= X_1 = p <= 9, end on 0 <= q <= 9, and satisfying 

1) X_i = k, for all k, for some i.

2) 0 <= X_i <= 9, for all i

The easiest way to do this is to start at one end and walk to the other by the rule |X_(n-1) - X_n| = 1 (<= "random walk"), and 2). We then use a bitmask to check which digits we have used at the end of any given walk, and can use this to check condition 1). We then cut down the processing time massively by storing some of these values in an array.

Correct solution (126461847755) found in 10392 μs (2.4GHz processor, compiled with MSVC with O2 flag)
