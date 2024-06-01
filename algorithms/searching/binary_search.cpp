#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// O(logn), O(1)
int search(int array[], int size, int target) {
    int lower_bound = 0, upper_bound = size - 1;

    while (lower_bound <= upper_bound) {
        int mid = lower_bound + (upper_bound - lower_bound) / 2;

        if (target < array[mid]) {
            upper_bound = mid - 1;
        } else if (target > array[mid]) {
            lower_bound = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

// O(logn), O(1)
int search_or_lower(int array[], int size, int target) {
    int lower_bound = 0, upper_bound = size - 1;

    int just_smaller = 0;
    while (lower_bound <= upper_bound) {
        int mid = lower_bound + (upper_bound - lower_bound) / 2;

        if (target < array[mid]) {
            upper_bound = mid - 1;
        } else if (target > array[mid]) {
            just_smaller = mid;
            lower_bound = mid + 1;
        } else {
            return mid;
        }
    }

    return just_smaller;
}

// O(logn), O(1)
int search_or_higher(int array[], int size, int target) {
    int lower_bound = 0, upper_bound = size - 1;

    int just_larger = size - 1;
    while (lower_bound <= upper_bound) {
        int mid = lower_bound + (upper_bound - lower_bound) / 2;

        if (target < array[mid]) {
            just_larger = mid;
            upper_bound = mid - 1;
        } else if (target > array[mid]) {
            lower_bound = mid + 1;
        } else {
            return mid;
        }
    }

    return just_larger;
}


int main() {
    cout << "even sized: " << endl;
    int array_even[6] = {2, 7, 100, 107, 560, 991};
    cout << "search 991: " << search(array_even, 6, 991) << ", " << "lower: " << search_or_lower(array_even, 6, 991) << ", " << "higher: " << search_or_higher(array_even, 6, 991) << endl;
    cout << "search 25: " << search(array_even, 6, 25) << ", " << "lower: " << search_or_lower(array_even, 6, 25) << ", " << "higher: " << search_or_higher(array_even, 6, 25) << endl;
    cout << "search 600: " << search(array_even, 6, 600) << ", " << "lower: " << search_or_lower(array_even, 6, 600) << ", " << "higher: " << search_or_higher(array_even, 6, 600) << endl;
    cout << "search -100: " << search(array_even, 6, -100) << ", " << "lower: " << search_or_lower(array_even, 6, -100) << ", " << "higher: " << search_or_higher(array_even, 6, -100) << endl;
    cout << "search 1000: " << search(array_even, 6, 1000) << ", " << "lower: " << search_or_lower(array_even, 6, 1000) << ", " << "higher: " << search_or_higher(array_even, 6, 1000) << endl;

    cout << "odd sized: " << endl;
    int array_odd[7] = {-27, 2, 7, 100, 107, 560, 991};
    cout << "search 991: " << search(array_odd, 7, 991) << ", " << "lower: " << search_or_lower(array_odd, 7, 991) << ", " << "higher: " << search_or_higher(array_odd, 7, 991) << endl;
    cout << "search 25: " << search(array_odd, 7, 25) << ", " << "lower: " << search_or_lower(array_odd, 7, 25) << ", " << "higher: " << search_or_higher(array_odd, 7, 25) << endl;
    cout << "search 600: " << search(array_odd, 7, 600) << ", " << "lower: " << search_or_lower(array_odd, 7, 600) << ", " << "higher: " << search_or_higher(array_odd, 7, 600) << endl;
    cout << "search -100: " << search(array_odd, 7, -100) << ", " << "lower: " << search_or_lower(array_odd, 7, -100) << ", " << "higher: " << search_or_higher(array_odd, 7, -100) << endl;
    cout << "search 1000: " << search(array_odd, 7, 1000) << ", " << "lower: " << search_or_lower(array_odd, 7, 1000) << ", " << "higher: " << search_or_higher(array_odd, 7, 1000) << endl;

    return 0;
}