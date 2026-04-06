/**
 * The stock span problem is a financial problem where we have a series of daily price quotes for a stock denoted 
 * by an array arr[] and the task is to calculate the span of the stock's price for all days. 
 * 
 * The span of the stock's price on ith day represents the maximum number of consecutive days leading up to ith 
 * day (including the current day) where the stock's price was less than or equal to its price on day i.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    vector<int> span(n);
    stack<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.top()] <= arr[i]) {
            stk.pop();
        }
        span[i] = stk.empty() ? i + 1 : i - stk.top();
        stk.push(i);
    }

    return span;
}