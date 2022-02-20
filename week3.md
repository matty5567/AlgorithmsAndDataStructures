# Week 3 Notes from week 2 of Coursera Introduction to Algorithms 

<B>Course link</B>: https://www.coursera.org/learn/algorithms-part1/home/week/3


# MergeSort

<B>Top Down Approach</B>: Recursively split the array, sort each half, then merge.

<br>

<img src = "./assets/Merge_sort_algorithm_diagram.png" width = "300"/>

<br>

<B>Bottom Up Approach</B>: Pass through the array, merging subarrays of size 1, 2, 4, 8, 16

<br>

<img src = "./assets/Merge_sort_bottom_up.png" width = "300"/>

<br>

<B>Algorithm Characteristics</B>:
- NlogN time complexity
- Mergesort uses extra space proportional to N (need to build auxilliary array)
- It is possible to do this algorithm in place, but not practical so not used

<br>

<B>Improvements on Mergesort</B>:
- For small arrays, use insertion sort
- Stop if the array is sorted (ie if the biggest element in first half < smallest element in second half)
- Save time by switching the role of input and aux array in each recursive call


# Quicksort

<br>

<b>Approach</b>: Shuffle the array, then recursively partition the array with one element i such that all elements to the left are less than i and all the elements to the right are greater than i, then repeat for the two subarrays.

<br>

<img src = "./assets/QuickSort.png" width = "300"/>

<br>

<b>Why is the Shuffle needed?</b>: To ensure that partitioning will produce subarrays that are as balanced as possible, with half of the subarray greater than the partition element, and half less than. The NlogN average time complexity of quicksort relies on this, otherwise the algorithm would have quadratic time complexity.

<br>

<B>Algorithm Characteristics</B>:
- In place sorting (advantage over mergesort)
- Faster in general than mergesort, because it doesn't move data between two arrays
- NlogN average time complexity (assuming random sort)
- Depth of recursion logarithmic

<br>

<b>Improvements on Quicksort</b>:
- If the array is small, use insertion sort
- Estimate the partition element to be in the middle, e.g. use the median of 3 random items

<br>

<b>Quicksort with 3-way partitioning</b>:

If the array has duplicates and all items equal to the partitioning element are put on one side, then time complexity can degrade to $\frac{1}{2}$ N <sup>2</sup> 

The solution is to partition the array into 3 parts:
- Entries less than the partition element
- Entries greater than the partition element
- Entries equal to the partition element

<br>

<img src = "./assets/3wayquicksort.png" width = "300"/>



<br>

# Stability
A <b>stable</b> sort preserves the relative order of items with equal keys.

Stable sorting algorithms:
- Mergesort
- Insertion sort

Unstable sorting algorithms:
- Shellsort
- Quicksort