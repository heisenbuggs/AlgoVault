#include <bits/stdc++.h>
using namespace std;

vector<string> firstN(int n) {
  queue<string> q;
  q.push("5");
  q.push("6");
  vector<string> ans;

  for (int count = 0; count < n; count++) {
    string curr = q.front();
    ans.push_back(curr);
    q.pop();
    q.push(curr + "5");
    q.push(curr + "6");
  }
  return ans;
}