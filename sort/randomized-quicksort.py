import random

'''first see quicksort.py
the main issue with pivot selection is in the worst case if the partition divides the array such that all the elements are based either at left or right
and none on the other side, then quicksort function will run O(n) times hence making the complexity O(n2)
so to mitigate this we randomize the pivot selection which does not gurantee but improves the chances of not picking the worst case pivot
this making the worst case complexity O(nlogn)
'''

# O(n), O(1)
def partition(arr, start, end):
    pivotidx = random.randint(start, end)
    arr[pivotidx], arr[end] = arr[end], arr[pivotidx]

    pivot = arr[end]
    left = start
    
    for right in range(start, end):
        if arr[right] <= pivot:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
        
    arr[left], arr[end] = arr[end], arr[left]

    return left


# O(logn), O(1)
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