/**
 * Implement a stack using two queues.
 * The stack should support the following operations:
 * 1. push(x): Push element x onto stack.
 * 2. pop(): Removes the element on top of the stack.
 * 3. top(): Get the top element.
 * 4. size(): Return the size of the stack.
 *
 * Note: You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;

   public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop() {
        if (q1.empty()) return;
        q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    int size() { return q1.size(); }
};