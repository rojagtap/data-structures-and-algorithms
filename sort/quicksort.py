# O(n) worst case, O(1)
# partition array into two halves given a pivot
# where the all the elements to the left of the pivot will be smaller than the pivot and vice versa
# swaps values in-place
def partition(arr, start, end):
    pivot = arr[end]
    left = start
    
    for right in range(start, end):
        if arr[right] <= pivot:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
        
    arr[left], arr[end] = arr[end], arr[left]

    return left


# O(logn) average case and O(n) worst case, O(1)
# divide and conquer
def quicksort(arr, start, end):
    if start < end:
        mid = partition(arr, start, end)
        quicksort(arr, start, mid - 1)
        quicksort(arr, mid + 1, end)


if __name__ == "__main__":
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3]
    quicksort(arr, 0, len(arr) - 1)
    print(arr)

    arr = [-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    quicksort(arr, 0, len(arr) - 1)
    print(arr)

    arr = [12, 11, 13, 5, 6, 7]
    quicksort(arr, 0, len(arr) - 1)
    print(arr)