/**
 * Given an array arr[] of integers, the task is to find the Next Greater Element for each element of the array 
 * in order of their appearance in the array.
 * The Next Greater Element for an element x is the first greater element on the right side of x in the array.
 *  Elements for which no greater element exist, consider the next greater element as -1. 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> stk;

    result.push_back(-1);

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        int x = stk.empty() ? -1 : stk.top();
        result.push_back(x);
        stk.push(arr[i]);
    }

    return result;
}