"""
Bubble Sort Algorithm
---------------------
Time complexity:
    Best: O(n)
    Average: O(n^2)
    Worst: O(n^2)
Space complexity: O(1)
Stable: Yes
In-place: Yes
Description: Repeatedly swap two adjacent elements if they are in wrong order, until the array is sorted. This is a very simple sorting algorithm, but is very
inefficient for large data sets or close to sorted data sets. 
"""

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def bubble_sort(arr):
    while not is_sorted(arr):
        for i in range(1, len(arr)):
            if arr[i] < arr[i-1]:
                arr[i], arr[i-1] = arr[i-1], arr[i]
    return arr

if __name__ == "__main__":
    arr = [1, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(bubble_sort(arr))
    print(is_sorted(arr))