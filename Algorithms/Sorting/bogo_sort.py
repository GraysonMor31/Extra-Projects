"""
Bogo Sort Algorithm
-------------------
Worst Case Performance: O(∞)
Best Case Performance: O(n)
Average Performance: O(n*n!)
Space Complexity: O(1)
Algorithm Paradigm: Brute Force (Permutation)
Sorting In Place: Yes
Stable: No
Description: Bogo sort is a highly inefficient sorting algorithm based on the generate and test paradigm. The function successively generates permutations 
of its input until it finds one that is sorted. It is not useful for sorting, but may be used for educational purposes, to contrast it with other more 
realistic algorithms.
"""
import random

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def bogo_sort(arr):
    while not is_sorted(arr):
        random.shuffle(arr)
    return arr

if __name__ == "__main__":
    arr = [1, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(bogo_sort(arr))