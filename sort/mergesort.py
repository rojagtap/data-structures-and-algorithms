# O(n), O(n)
# this method is called O(logn) times, hence O(nlogn)
# buffer copied to original array for in-place sorting
def merge(arr, start, mid, end):
    left = arr[start: mid + 1]
    right = arr[mid + 1: end + 1]

    index = start
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[index] = left[i]
            index += 1
            i += 1
        else:
            arr[index] = right[j]
            index += 1
            j += 1
    
    while i < len(left):
        arr[index] = left[i]
        index += 1
        i += 1

    while j < len(right):
        arr[index] = right[j]
        index += 1
        j += 1


# O(logn), O(1)
def mergesort(arr, start, end):
    if start == end:
        return

    mid = (start + end) // 2
    mergesort(arr, start, mid)
    mergesort(arr, mid + 1, end)

    merge(arr, start, mid, end)


if __name__ == "__main__":
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3]
    mergesort(arr, 0, len(arr) - 1)
    print(arr)

    arr = [-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    mergesort(arr, 0, len(arr) - 1)
    print(arr)

    arr = [12, 11, 13, 5, 6, 7]
    mergesort(arr, 0, len(arr) - 1)
    print(arr)
