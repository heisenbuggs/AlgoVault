#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int subsetSum(vector<int>& arr, int n, int sum) {
        // Base case: if sum is 0, return true
        if (sum == 0)
            return 1;
        // If no elements left and sum is not 0, return false
        if (n == 0)
            return 0;
        // If last element is greater than sum, ignore it
        if (arr[n - 1] > sum)
            return subsetSum(arr, n - 1, sum);
        // Check if sum can be obtained by either including or excluding the last element
        return subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
    }
};

class TabulationSolution {
    int subsetSum(vector<int>& arr, int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
        return dp[n][sum];
    }
};
