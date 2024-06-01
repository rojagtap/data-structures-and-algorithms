#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// O(n), O(n)
void merge(int array[], int start, int mid, int end) {
    int buffer[end - start + 1];
    int iterator_first = start, iterator_second = mid + 1;

    int iterator_buffer = 0;
    while (iterator_first <= mid && iterator_second <= end) {
        if (array[iterator_first] <= array[iterator_second]) {
            buffer[iterator_buffer++] = array[iterator_first++];
        } else {
            buffer[iterator_buffer++] = array[iterator_second++];
        }
    }

    while (iterator_first <= mid) {
        buffer[iterator_buffer++] = array[iterator_first++];
    }

    while (iterator_second <= end) {
        buffer[iterator_buffer++] = array[iterator_second++];
    }

    memcpy(array + start, buffer, sizeof(buffer));
}


// O(logn), O(1) + O(logn) recursion stack
void sort(int array[], int from, int to) {
    if (from >= to) {
        return;
    }

    int mid = from + (to - from) / 2;

    sort(array, from, mid);
    sort(array, mid + 1, to);

    merge(array, from, mid, to);
}


int main() {
    int array_even[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(array_even, 0, 9);

    cout << "even size:" << endl;
    for (int number : array_even) {
        cout << number << " ";
    }
    cout << endl;

    int array_odd[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(array_odd, 0, 10);

    cout << "odd size:" << endl;
    for (int number : array_odd) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}