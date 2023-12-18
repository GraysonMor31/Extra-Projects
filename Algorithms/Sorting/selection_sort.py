"""
Selection Sort Algorithm
------------------------
Time complexity:
    Best: O(n^2)
    Average: O(n^2)
    Worst: O(n^2)
Space complexity: O(1)
Stable: No
In-place: Yes
Description: The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting
it at the beginning. The algorithm maintains two subarrays in a given array. The subarray which is already sorted and the remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
"""

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def selection_sort(arr):
    # iterate through the array
    for i in range(len(arr)):
        # find the minimum element in the unsorted array
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
        # swap the minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

if __name__ == "__main__":
    arr = [1, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(selection_sort(arr))
    print(is_sorted(arr))