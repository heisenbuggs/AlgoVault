/**
 * Given an array arr and a number k. The array is sorted in a way that every element is at max k distance away from it 
 * sorted position.
 * It means if we completely sort the array, then the index of the element can go from i – k to i + k where i is index in 
 * the given array. Our task is to completely sort the array.
 * 
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> sortKSortedArray(vector<int>& arr, int k) {
        // Min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i <= k && i < n; i++) {
            pq.push(arr[i]);
        }

        for (int i = k + 1; i < n; i++) {
            ans.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
