#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// O(n), O(1)
int partition(int array[], int from, int to) {
    // for randomized quicksort
    // take a random value between from and to
    // swap this value with end and do the same
    int pivot = to;

    // take all elements < pivot to one side and greater to another
    // at the end of this paritition, left of pivot will have all numbers < pivot
    // and right of the pivot wull have all the numbers > pivot (not necessarily sorted)
    // effectively, pivot will be at its correct position in the sorted array
    // hence this can also be used to find the kth smallest or largest element in an array
    int left = from;
    for (int right = from; right < to; ++right) {
        if (array[right] < array[pivot]) {
            swap(array[left++], array[right]);
        }
    }

    swap(array[left], array[pivot]);
    return left;
}

// O(logn), O(1) + O(logn) recursion space 
void sort(int array[], int from, int to) {
    if (from >= to) {
        return;
    }

    int pivot = partition(array, from, to);
    sort(array, from, pivot - 1);
    sort(array, pivot + 1, to);
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