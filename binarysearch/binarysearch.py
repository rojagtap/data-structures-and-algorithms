"""
a general template for binary search
this template can be modified for variations as required
"""


def search(array, element):
    """
    binary search for exact match
    O(log(n)) in time, O(1) in space

    :param array: sorted array
    :param element: element to find
    :return: index of x if found in arr, else -1
    """

    left, right = 0, len(array) - 1
    while left < right:
        # this decides whether we want left = mid + 1 or right = mid - 1
        # basically in the case of left = i and right = i + 1, mid will always be i + 0 = i
        # so to break the loop, we need left = mid + 1
        # but if you want right = mid - 1 and left = mid, do mid = right - (right - left) // 2
        # it is very intuitive to understand why it is that way
        mid = left + (right - left) // 2

        if element < array[mid]:
            right = mid
        elif element > array[mid]:
            left = mid + 1
        else:
            return mid

    return left if array[left] == element else -1


if __name__ == "__main__":
    arr = [-3, -1, 0, 1, 3, 4, 6, 7, 9]
    print(search(arr, -3))
    print(search(arr, 9))
    print(search(arr, -2))
    print(search(arr, 8))
    print(search(arr, 2))
    print(search(arr, 100))
