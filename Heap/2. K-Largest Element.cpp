/**
 * Given an integer array nums and an integer k, return the k largest element in the array.
 * Note that it is the kth largest elements in the sorted order, not the kth distinct element.
 * 
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> KLargest(vector<int> nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
