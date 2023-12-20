"""
Insertion Sort Algorithm
------------------------
Time complexity:
    Best: O(n)
    Average: O(n^2)
    Worst: O(n^2)
Space complexity: O(1)
Stable: Yes
In-place: Yes
Description: Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. At each iteration, insertion sort removes an
element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
"""

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def insertion_sort(arr):
    for i in range(1, len(arr)):
        # Store the current element in a temporary variable
        key = arr[i]
        # Start comparing the current element with the elements before it
        j = i-1
        # Loop as long as J is greater than or equal to 0 and the current element is less than the element before it
        while j >= 0 and key < arr[j]:
            # Shift the elements to the right to make room for the new element
            arr[j+1] = arr[j] 
            j -= 1
        arr[j+1] = key
    return arr

if __name__ == "__main__":
    arr = [10, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(insertion_sort(arr))
    print(is_sorted(arr))