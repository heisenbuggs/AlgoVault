#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int countSubsetsWithSum(vector<int>& arr, int n, int sum) {
        // Base case: if sum is 0, return 1 (one way to achieve sum 0)
        if (sum == 0) return 1;
        // If no elements left and sum is not 0, return 0 (no way to achieve sum)
        if (n == 0) return 0;
        // If last element is greater than sum, ignore it
        if (arr[n - 1] > sum) return countSubsetsWithSum(arr, n - 1, sum);
        // Count subsets with and without the last element
        return countSubsetsWithSum(arr, n - 1, sum) + countSubsetsWithSum(arr, n - 1, sum - arr[n - 1]);
    }

    int countSubsetsWithSumK(vector<int>& arr, int sum) {
        int n = arr.size();
        return countSubsetsWithSum(arr, n, sum);
    }
};

class MemoizationSolution {
    int countSubsetsWithSum(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return 1;
        if (n == 0) return 0;
        if (dp[n][sum] != -1) return dp[n][sum];

        if (arr[n - 1] > sum) return dp[n][sum] = countSubsetsWithSum(arr, n - 1, sum, dp);
        return dp[n][sum] = countSubsetsWithSum(arr, n - 1, sum, dp) + countSubsetsWithSum(arr, n - 1, sum - arr[n - 1], dp);
    }

    int countSubsetsWithSumK(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return countSubsetsWithSum(arr, n, sum, dp);
    }
};

class TabulationSolution {
    int countSubsetsWithSumK(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (arr[i] <= j) {
                    dp[i + 1][j] = dp[i][j] + dp[i][j - arr[i]];
                } else {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }
        return dp[n][sum];
    }
};

class SpaceOptimizedSolution {
    int countSubsetsWithSumK(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

        prev[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (arr[i] <= j) {
                    curr[j] = prev[j] + prev[j - arr[i]];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[sum];
    }
};
