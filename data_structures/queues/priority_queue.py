'''
assuming a min heap
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


# O(logn), O(1)
# heapifies starting from the given node till the top
# using this for heappush is faster as we can append an item to the end and heapify till the top
def heapify_reverse(heap, current):
    while True:
        if current & 1:
            parent = (current - 1) // 2
        else:
            parent = (current - 2) // 2

        if parent < 0 or heap[current] <= heap[parent]:
            break

        heap[current], heap[parent] = heap[parent], heap[current]
        current = parent


# O(logn), O(1)
# append an element to the heap
def heappush(heap, item):
    heap.append(item)
    heapify_reverse(heap, len(heap) - 1)


# O(logn), O(1)
# pop the top of the heap
def heappop(heap):
    heap[0], heap[len(heap) - 1] = heap[len(heap) - 1], heap[0]
    popped = heap.pop()
    heapify(heap, len(heap), 0)
    return popped


# O(nlogn), O(1)
# reorder to array to a heap in-place such that for any index i, (2i + 1) and (2i + 2) are the left and the right children respectively
def build(arr):
    for i in range((len(arr) // 2) - 1, -1, -1):
        heapify(arr, len(arr), i)


if __name__ == "__main__":
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3]
    buildarr = arr
    build(buildarr)
    pusharr = []
    for a in arr:
        heappush(pusharr, a)
    
    assert buildarr == pusharr

    print(heappop(pusharr))
    print(pusharr)
    print(heappop(pusharr))
    print(pusharr)
    print(heappop(pusharr))
    print(pusharr)
    print(heappop(pusharr))
    print(pusharr)
