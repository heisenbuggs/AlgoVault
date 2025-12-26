/**
 * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
 * The result should also be sorted in ascending order.

 * An integer a is closer to x than an integer b if:
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 * 
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> kClosest(vector<int> nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({abs(nums[i] - x), nums[i]});

            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()) {
            auto x = pq.top();
            ans.push_back(x.second);
            pq.pop();
        }
        return ans;
    }
};
