/**
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * Time Complexity: O(n log k)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> topKFrequent(vector<int> nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto x : mp) {
            pq.push({x.second, x.first});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (pq.size()) {
            auto x = pq.top();
            ans.push_back(x.second);
            pq.pop();
        }
        return ans;
    }
};