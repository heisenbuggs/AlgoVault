#include <bits/stdc++.h>
using namespace std;

class TabulationSolution {
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (target > totalSum || (totalSum + target) % 2 != 0) return 0;
        int targetSum = (totalSum + target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= targetSum; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            }
        }
        return dp[n][targetSum];  
    }
};