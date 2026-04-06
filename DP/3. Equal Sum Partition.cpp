#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    bool subsetSum(vector<int>& arr, int n, int sum) {
        // Base case: if sum is 0, return true
        if (sum == 0)
            return true;
        // If no elements left and sum is not 0, return false
        if (n == 0)
            return false;
        // If last element is greater than sum, ignore it
        if (arr[n - 1] > sum)
            return subsetSum(arr, n - 1, sum);
        // Check if sum can be obtained by either including or excluding the last element
        return subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        // If sum is odd, we cannot partition it into two equal subsets
        if (sum % 2 != 0) return false;
        // Check if there is a subset with sum equal to half of the total sum
        return subsetSum(arr, n, sum / 2);
    }
};

class TabulationSolution {
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2 != 0) return false;
        sum /= 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
