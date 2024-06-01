#include "../../data_structures/queues/priority_queue.cpp"

int main() {
    Heap heap;

    for (int i = 10; i >= 0; --i) {
        heap.push(i);
    }
    heap.print();

    vector<int> sorted;
    while (!heap.empty()) {
        sorted.push_back(heap.pop());
    }

    for (auto& element : sorted) {
        cout << element << " ";
    }
    cout << endl;
}