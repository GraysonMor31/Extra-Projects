"""
Bogo Sort Algorithm
-------------------
Time complexity:
    Best: O(n)
    Average: O((n+1)!)
    Worst: O((n+1)!)
Space complexity: O(1)
Stable: No
In-place: Yes
Description: Shuffle the array until it is sorted using random permutations. This works as a Generate and Test algorithm meaning it works off of statisical 
probability, and is very inefficient, but theoretically possible to be faster than quicksort.
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
    print(is_sorted(arr))