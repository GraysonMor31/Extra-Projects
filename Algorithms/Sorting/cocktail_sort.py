"""
Cocktail Sort Algorithm
-----------------------
Time complexity:
    Best: O(n)
    Average: O(n^2)
    Worst: O(n^2)
Space complexity: O(1)
Stable: Yes
In-place: Yes
Description: Cocktail sort is a variation of bubble sort. The bubble sort algorithm always traverses elements from left and moves the largest element to its
correct position in first iteration and second largest in second iteration and so on. Cocktail Sort traverses through a given array in both directions
alternately. In every iteration of cocktail sort, one iteration of bubble sort is performed in both directions. The first iteration traverses from left to right,
and the second iteration traverses from right to left. This process continues while the array is unsorted.
"""

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def cocktail_sort(arr):
    # set swapped to True to begin the loop
    swapped = True
    start = 0
    end = len(arr) - 1
    while swapped:
        # reset swapped to False
        swapped = False
        # loop from left to right
        for i in range(start, end):
            # swap if the element found is greater than the next element
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                # set swapped to True to continue the loop
                swapped = True
        # if nothing was swapped, the array is sorted
        if not swapped:
            break
        # otherwise, reset swapped to False to continue the loop
        swapped = False
        # move the end point back by one because the item at the end is in its correct position
        end -= 1
        # loop from right to left
        for i in range(end-1, start-1, -1):
            # swap if the element found is greater than the next element
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                # set swapped to True to continue the loop
                swapped = True
        # move the start point up by one because the item at the start is in its correct position
        start += 1
    return arr

if __name__ == "__main__":
    arr = [1, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(cocktail_sort(arr))
    print(is_sorted(arr))