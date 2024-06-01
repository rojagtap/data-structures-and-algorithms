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


"""
variants of binary search for max element less than and
min element greater than the element to find if not found
"""


def search_closest_smaller(array, element):
    """
    binary search for closest smaller match
    O(log(n)) in time, O(1) in space

    :param array: sorted array
    :param element: element to find
    :return: index of element if found, else largest element less than given in the array
    """

    left, right = 0, len(array) - 1
    while left < right:
        mid = left + (right - left) // 2

        if element > array[mid]:
            left = mid + 1
        else:
            right = mid

    # after the entire iteration (log(n)), there are 2 possibilities
    # 1. if the element is between i and i + 1, then left will be always the mid (binarysearch.py)
    # and left will go to i + 1 (i.e., mid + 1) and hence the closest smaller will be at left - 1
    # 2. if the element is at left (mid) then the same logic as binarysearch.py applies
    # the thing to note here is, right is NEVER going to be mid
    return left if array[left] == element else max(0, left - 1)


def search_closest_larger(array, element):
    """
    binary search for closest larger match
    O(log(n)) in time, O(1) in space

    :param array: sorted array
    :param element: element to find
    :return: index of element if found, else smallest element greater than given in the array
    """

    left, right = 0, len(array) - 1
    while left < right:
        mid = left + (right - left) // 2

        if element > array[mid]:
            left = mid + 1
        else:
            right = mid

    # after the entire iteration (log(n)), there are 2 possibilities
    # 1. if the element is between i and i + 1, then left will be always the mid (binarysearch.py)
    # and left will go to i + 1 (i.e., mid + 1) and hence the closest larger will be at left
    # 2. if the element is at left (mid) then the same logic as binarysearch.py applies
    # the thing to note here is, right is NEVER going to be mid
    return left



if __name__ == "__main__":
    arr = [-3, -1, 0, 1, 3, 4, 6, 7, 9]
    print(search(arr, -3))
    print(search(arr, 9))
    print(search(arr, -2))
    print(search(arr, 8))
    print(search(arr, 2))
    print(search(arr, 100))

    arr = [-10, -5, 0, 5, 10]
    print(search_closest_smaller(arr, -3), search_closest_larger(arr, -3))
    print(search_closest_smaller(arr, 9), search_closest_larger(arr, 9))
    print(search_closest_smaller(arr, -2), search_closest_larger(arr, -2))
    print(search_closest_smaller(arr, 8), search_closest_larger(arr, 8))
    print(search_closest_smaller(arr, 2), search_closest_larger(arr, 2))
    print(search_closest_smaller(arr, -100), search_closest_larger(arr, -100))
    print(search_closest_smaller(arr, 100), search_closest_larger(arr, 100))
