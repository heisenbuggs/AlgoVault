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