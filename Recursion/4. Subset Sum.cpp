/*
 * Given an array of n integers, print sum of all subsets of it.
 * Output should be in increasing order.
 * Time Complexity : O(2^n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solver(int ind, int sum, vector<int> arr, int n, vector<int> ans) {
        if (ind == n) {
            ans.push_back(sum);
            return;
        }
        // pick the element
        solver(ind + 1, sum + arr[ind], arr, n, ans);
        // not pick the element
        solver(ind + 1, sum, arr, n, ans);
    }

    vector<int> subsetSum(vector<int> arr, int n) {
        vector<int> ans;
        solver(0, 0, arr, n, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
