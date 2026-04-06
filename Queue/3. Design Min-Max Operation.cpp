/**
 * Design a data structure that supports the following operations in O(1) time:
 * 1. insertMin(x): Inserts an element x to the front of the data structure.
 * 2. insertMax(x): Inserts an element x to the back of the data structure.
 * 3. getMin(): Returns the minimum element from the front of the data structure.
 * 4. getMax(): Returns the maximum element from the back of the data structure.
 * 5. extractMin(): Removes and returns the minimum element from the front of the data structure.
 * 6. extractMax(): Removes and returns the maximum element from the back of the data structure.
 */

#include <bits/stdc++.h>
using namespace std;

struct MinMaxOperations {
    deque<int> dq;

    void insertMin(int x) {
        dq.push_front(x);
    }

    void insertMax(int x) {
        dq.push_back(x);
    }

    int getMin() {
        return dq.front();
    }

    int getMax() {
        return dq.back();
    }

    int extractMin() {
        int x = dq.front();
        dq.pop_front();
        return x;
    }

    int extractMax() {
        int x = dq.back();
        dq.pop_back();
        return x;
    }
};