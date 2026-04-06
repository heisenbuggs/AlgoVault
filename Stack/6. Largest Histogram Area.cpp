/**
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
 * return the area of the largest rectangle in the histogram.
 */

#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    int top, curr, res = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            int top = s.top();
            s.pop();

            int width = s.empty() ? i : i - s.top() - 1;
            res = max(res, arr[top] * width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        top = s.top();
        s.pop();
        curr = arr[top] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;
}