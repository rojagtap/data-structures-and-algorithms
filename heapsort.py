'''
assuming a max heap (i.e., sort ascending)
'''

# O(logn), O(1)
# heapifies starting from the given node till the bottom
def heapify(heap, size, current):
    largest = current
    left, right = 2 * current + 1, 2 * current + 2

    if left < size and heap[left] > heap[largest]:
        largest = left
    
    if right < size and heap[right] > heap[largest]:
        largest = right

    if largest != current:
        heap[current], heap[largest] = heap[largest], heap[current]
        heapify(heap, size, largest)


# O(nlogn), O(1)
# reorder to array to a heap in-place such that for any index i, (2i + 1) and (2i + 2) are the left and the right children respectively
def build(arr):
    for i in range((len(arr) // 2) - 1, -1, -1):
        heapify(arr, len(arr), i)


# O(nlogn), O(1)
# sends the top (largest) element in the heap to the end and heapifies the rest of the heap for all elements 
# so that the n-largest elements of the array are in reverse order, i.e., sorted ascending
def heapsort(arr):
    build(arr)

    size = len(arr) - 1
    while size:
        arr[0], arr[size] = arr[size], arr[0]
        size -= 1
        heapify(arr, size + 1, 0)


if __name__ == "__main__":
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3]
    heapsort(arr)
    print(arr)

    arr = [-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    heapsort(arr)
    print(arr)

    arr = [12, 11, 13, 5, 6, 7]
    heapsort(arr)
    print(arr)