"""
Heap Sort Algorithm
-------------------
Time complexity:
    Best: O(n log(n))
    Average: O(n log(n))
    Worst: O(n log(n))
Space complexity: O(1)
Stable: No
In-place: Yes
Description: Create a heap data structure and repeatedly remove the largest element from the heap and add it to the sorted array. This is an efficient sorting 
algorithm, but is not stable, due to the nature of the heap data structure.
"""

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def heapify(arr, n, i):
    # Find the largest element in the heap
    parent = i
    lc = 2*i + 1
    rc = (2*i) + 2
    
    # Check the heap property for subtrees in the heap
    if lc < n and arr[parent] < arr[lc]:
        parent = lc
    if rc < n and arr[parent] < arr[rc]:
        parent = rc
    # Swap the largest element with the root node of each subtree
    if parent != i:
        arr[i], arr[parent] = arr[parent], arr[i]
        heapify(arr, n, parent)
    
def build_heap(arr, n):
    for i in range(n//2 - 1, -1, -1): # Start at the last parent node go to the root node
        heapify(arr, n, i)
    
def heap_sort(arr):
    n = len(arr)
    build_heap(arr, n)
    for i in range(n-1, 0, -1): # Start at the last element go to the second element
        arr[i], arr[0] = arr[0], arr[i] # Swap the largest element with the last element
        heapify(arr, i, 0) # Heapify the remaining elements
    return arr
    
if __name__ == "__main__":
    arr = [1, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(heap_sort(arr))
    print(is_sorted(arr))