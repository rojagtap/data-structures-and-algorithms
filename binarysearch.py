# O(logn), O(1)
def search(arr, x):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if x < arr[mid]:
            right = mid - 1
        elif x > arr[mid]:
            left = mid + 1
        else:
            return mid

    return -1


if __name__ == "__main__":
    arr = [-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    print(search(arr, -3))
    print(search(arr, 9))
    print(search(arr, -2))
    print(search(arr, 8))
    print(search(arr, 2))
    print(search(arr, 100))
