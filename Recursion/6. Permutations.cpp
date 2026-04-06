/*
 * Given an array nums of distinct integers, return all the possible permutations.
 * 
 * You can return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Time Complexity : O(n! x n)
 * Space Complexity : O(n)
 */
class Solution1 {
    void solver(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                freq[i] = true;
                ds.push_back(nums[i]);
                solver(nums, ds, ans, freq);
                ds.pop_back();
                freq[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(n, false);
        solver(nums, ds, ans, freq);
        return ans;
    }
};

/*
 * Time Complexity : O(n! x n)
 * Space Complexity : O(n)
 */
class Solution2 {
    void solver(int index, vector<int> &nums, vector<vector<int>> &ans, int n) {
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++) {
            swap(nums[i], nums[index]);
            solver(index + 1, nums, ans, n);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int> nums) {
        vector<vector<int>> ans;
        solver(0, nums, ans, nums.size());
        return ans;
    }
};