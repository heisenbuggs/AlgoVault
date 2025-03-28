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