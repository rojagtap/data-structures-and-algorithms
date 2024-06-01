# O(n2), O(1)
# in-place sorting
def insertionsort(arr):
    for i in range(1, len(arr)):
        j = i
        while j > 0 and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1


if __name__ == "__main__":
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3]
    insertionsort(arr)
    print(arr)

    arr = [-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    insertionsort(arr)
    print(arr)

    arr = [12, 11, 13, 5, 6, 7]
    insertionsort(arr)
    print(arr)
