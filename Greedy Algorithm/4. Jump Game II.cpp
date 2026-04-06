/*
You are given a **0-indexed** array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i],
you can jump to any nums[i + j] where:

- 0 <= j <= nums[i] and
- i + j < n

Return *the minimum number of jumps to reach* nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int ind, int jumps) {
    if (ind >= nums.size() - 1) return jumps;

    int mini = INT_MAX;
    for (int i = 1; i <= nums[ind]; i++) {
        mini = min(mini, solve(nums, ind + i, jumps + 1));
    }
    return mini;
}

int jump(vector<int>& nums) {
    return solve(nums, 0, 0);
}