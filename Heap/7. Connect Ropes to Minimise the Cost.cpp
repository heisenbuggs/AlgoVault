/**
 * Given an array, nums of rope lengths, connect all ropes into a single rope with the minimum total cost. 
 * The cost to connect two ropes is the sum of their lengths. 
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int minimiseCost(vector<int> nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int cost = 0;

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            cost = first + second;
            pq.push(cost);
        }
        return pq.top();
    }
};
