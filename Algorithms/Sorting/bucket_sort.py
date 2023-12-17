"""
Bucket Sort Algorithm
---------------------
Time complexity:
    Best: O(n+k)
    Average: O(n+k)
    Worst: O(n^2)
Space complexity: O(n+k)
Stable: Yes
In-place: No
Description: Distribute elements of an array into a number of buckets. Each bucket is then sorted individually, either using a different sorting algorithm, or by 
recursively applying the bucket sorting algorithm. This is a very efficient sorting algorithm, but requires a lot of memory.
"""

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j] # Shift the elements to the right
            j -= 1
        arr[j+1] = key
    return arr

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True

def bucket_sort(arr):
    if len(arr) == 0 or len(arr) == 1:
        return arr
    # Find minimum and maximum values
    min_val = min(arr)
    max_val = max(arr)
    # Normalize the values to ensure an even distribution
    bucket_range = (max_val - min_val) / len(arr)
    # Create buckets (Lists within a list)
    buckets = [[] for _ in range(len(arr))]
    # Distribute the elements into the buckets (each bucket has a range of values assigned to it)
    for i in range(len(arr)):
        j = int((arr[i] - min_val) / bucket_range)
        if j != len(arr):
            buckets[j].append(arr[i])
        else:
            buckets[len(arr)-1].append(arr[i])
    # Sort each bucket using insertion sort
    for i in range(len(arr)):
        buckets[i] = insertion_sort(buckets[i])
    # Concatenate the buckets into the original array
    k = 0
    for i in range(len(arr)):
        for j in range(len(buckets[i])):
            arr[k] = buckets[i][j]
            k += 1
    return arr

if __name__ == "__main__":
    arr = [1, 11, 14, 297, 13, 15, 17, 12, 11, 6, 298, 36, 2, 9]
    print(bucket_sort(arr))
    print(is_sorted(arr))