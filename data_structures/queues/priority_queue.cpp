#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/*
assuming min heap
*/
class Heap {
public:
    // O(logn), O(n)
    void heapify_top_down(int from) {
        int left = 2 * from + 1, right = 2 * from + 2;

        int smaller = from;
        if (left < size && heap[smaller] > heap[left]) {
            smaller = left;
        }
        
        if (right < size && heap[smaller] > heap[right]) {
            smaller = right;
        }

        if (smaller != from) {
            swap(heap[from], heap[smaller]);
            heapify_top_down(smaller);
        }
    }

    // O(logn), O(n)
    void heapify_bottom_up(int from) {
        int parent = from & 1 ? (from - 1) / 2 : (from - 2) / 2;
        if (parent >= 0 && heap[from] < heap[parent]) {
            swap(heap[from], heap[parent]);
            heapify_bottom_up(parent);
        }
    }

    // O(logn), O(1)
    void push(int value) {
        ++size;
        heap.push_back(value);
        heapify_bottom_up(size - 1);
    }

    // O(logn), O(1)
    int pop() {
        int top = heap[0];
        swap(heap[0], heap[size - 1]);

        --size;
        heap.pop_back();

        heapify_top_down(0);

        return top;
    }

    // O(1), O(1)
    int top() {
        return heap[0];
    }

    // O(1), O(1)
    bool empty() {
        return size == 0;
    }

    // O(n), O(1)
    void print() {
        for (auto& node : heap) {
            cout << node << " ";
        }
        cout << endl;
    }

private:
    int size = 0;
    vector<int> heap;
};


// int main() {
//     Heap heap;

//     for (int i = 10; i >= 0; --i) {
//         heap.push(i);
//     }
//     heap.print();

//     heap.pop();
//     heap.print();
//     heap.pop();
//     heap.print();

//     heap.push(-1);
//     heap.print();

//     cout << "top: " << heap.top() << endl;

//     while (!heap.empty()) {
//         cout << heap.pop() << " ";
//     }
//     cout << endl;

//     return 0;
// }

/*
                        0
            1                       5
    4               2       9               6
10      7       8       3


                        2
            8                       5
    4               3       9               6
10      7


                        2
            4                       5
    7               3      9                6
10      8


                        -1
            2                       5
    7               4       9               6
10      8       3
*/