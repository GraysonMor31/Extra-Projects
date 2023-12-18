"""
Quick Sort Algorithm
--------------------
Time complexity:
    Best: O(n log(n))
    Average: O(n log(n))
    Worst: O(n^2)
Space complexity: O(log(n))
Stable: No
In-place: Yes
Description: A divide and conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different ways 
to pick a pivot, but this implementation uses the last element as the pivot. The key process in quickSort is partition(). Target of partitions is, given an
array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all 
greater elements (greater than x) after x. All this should be done in linear time.
"""

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def partition(arr, low, high):
    i = low - 1
    pivot = arr[high]
    # iterate through the array and swap elements that are less than the pivot with the element at the index i
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            # swap elements
            arr[i], arr[j] = arr[j], arr[i]
    # swap pivot with the element at index i+1
    arr[i+1], arr[high] = arr[high], arr[i+1] 
    return i+1

def quick_sort(arr, low, high):
    if low < high:
        # partition the array and get the index of the pivot element
        pivot = partition(arr, low, high)
        # recursively call quick_sort on the left and right sides of the pivot until subarrays of size 1 are reached
        quick_sort(arr, low, pivot-1)
        quick_sort(arr, pivot+1, high)
    return arr

if __name__ == "__main__":
    arr = [1, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(quick_sort(arr, 0, len(arr)-1))
    print(is_sorted(arr))