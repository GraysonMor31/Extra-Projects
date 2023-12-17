"""
Merge Sort Algorithm
--------------------
Time complexity:
    Best: O(n log(n))
    Average: O(n log(n))
    Worst: O(n log(n))
Space complexity: O(n)
Stable: Yes
In-place: No
Description: Divide the array into two halves, sort each half recursively, and then merge the two halves back together. This is a very efficient sorting algorithm,
and is the basis for the more efficient quicksort algorithm.
"""

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def merge_sort(arr):
    if len(arr) == 0 or len(arr) == 1:
        return arr
    # Divide the array into two halves
    half = len(arr) // 2
    left = arr[:half]
    right = arr[half:]
    # Sort each half recursively
    left = merge_sort(left)
    right = merge_sort(right)
    # Merge the two halves back together
    merged_arr = []
    i = j = 0
    # Loop until both halves are empty
    while i < len(left) and j < len(right):
        # If the element in the left half is smaller, add it to the merged array
        if left[i] < right[j]:
            merged_arr.append(left[i])
            i += 1
        elif left[i] > right[j]:
            merged_arr.append(right[j])
            j += 1
    # Add remaining left half elements to the merged array
    while i < len(left):
        # If the element in the left half is smaller, add it to the merged array
        merged_arr.append(left[i])
        i += 1
    # Add remaining right half elements to the merged array
    while j < len(right):
        # If the element in the right half is smaller, add it to the merged array
        merged_arr.append(right[j])
        j += 1
    return merged_arr

if __name__ == "__main__":
    arr = [10, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(merge_sort(arr))
    print(is_sorted(arr))