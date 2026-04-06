/**
 * Given an integer array nums and an integer k, return the kth smallest element in the array.
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int kthSmallest(vector<int> nums, int k) {
        // create a max-heap
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

