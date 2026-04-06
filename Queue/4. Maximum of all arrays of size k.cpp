/**
 * Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> kMaximum(vector<int> &arr, int n, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < n; i++) {
        ans.push_back(arr[dq.front()]);

        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();

        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    return ans;
}