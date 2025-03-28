#include <bits/stdc++.h>
using namespace std;

vector<int> prevGreater(vector<int> &arr, int n) {
  stack<int> s;
  vector<int> ans;
  s.push(arr[0]);
  ans.push_back(-1);

  for (int i = 1; i < n; i++) {
    while (s.empty() == false && s.top() < arr[i]) {
      s.pop();
    }

    int x = s.empty() ? -1 : s.top();
    ans.push_back(s.top());
    s.push(arr[i]);
  }

  return ans;
}