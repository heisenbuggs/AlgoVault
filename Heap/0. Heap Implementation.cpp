#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        // Time Complexity : O(logn)
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] >= heap[index])
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        // Time Complexity : O(logn)
        int n = heap.size();

        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        // Time Complexity : O(logn)
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void extractMax() {
        // Time Complexity : O(logn)
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    int top() {
        // Time Complexity : O(1)
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool isEmpty() {
        // Time Complexity : O(1)
        return heap.empty();
    }

    void print() {
        // Time Complexity : O(n)
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(30);
    h.insert(15);

    cout << "Heap: ";
    h.print();

    cout << "Top = " << h.top() << endl;

    h.extractMax();

    cout << "After deleting max:\n";
    h.print();

    cout << "Top = " << h.top() << endl;

    return 0;
}