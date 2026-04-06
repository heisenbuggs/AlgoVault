#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int minSubsetSumDiff(vector<int>& arr, int n, int sum1, int sum2) {
        // Base case: if no elements left, return the absolute difference
        if (n == 0) return abs(sum1 - sum2);
        // Include the current element in the first subset
        int include = minSubsetSumDiff(arr, n - 1, sum1 + arr[n - 1], sum2);
        // Exclude the current element from the first subset
        int exclude = minSubsetSumDiff(arr, n - 1, sum1, sum2 + arr[n - 1]);
        // Return the minimum of both cases
        return min(include, exclude);
    }

    int minSubsetSumDiff(vector<int>& arr) {
        int n = arr.size();
        return minSubsetSumDiff(arr, n - 1, 0, 0);
    }
};

class MemoizationSolution {
    int minSubsetSumDiff(vector<int>& arr, int n, int sum1, int sum2, vector<vector<int>>& dp) {
        if (n == 0) return abs(sum1 - sum2);
        if (dp[n][sum1] != -1) return dp[n][sum1];

        int include = minSubsetSumDiff(arr, n - 1, sum1 + arr[n - 1], sum2, dp);
        int exclude = minSubsetSumDiff(arr, n - 1, sum1, sum2 + arr[n - 1], dp);

        return dp[n][sum1] = min(include, exclude);
    }

    int minSubsetSumDiff(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, -1));
        return minSubsetSumDiff(arr, n, 0, 0, dp);
    }
};

class TabulationSolution {
    int minSubsetSumDiff(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= totalSum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        int minDiff = INT_MAX;
        for (int j = 0; j <= totalSum / 2; j++) {
            if (dp[n][j]) {
                minDiff = min(minDiff, totalSum - 2 * j);
            }
        }
        return minDiff;
    }
};

class SpaceOptimizedSolution {
    int minSubsetSumDiff(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        vector<bool> prev(totalSum + 1, false);
        prev[0] = true;

        for (int i = 1; i <= n; i++) {
            vector<bool> curr(totalSum + 1, false);
            curr[0] = true;
            for (int j = 0; j <= totalSum; j++) {
                curr[j] = prev[j];
                if (j >= arr[i - 1]) {
                    curr[j] = curr[j] || prev[j - arr[i - 1]];
                }
            }
            prev = curr;
        }
        int minDiff = INT_MAX;
        for (int j = 0; j <= totalSum / 2; j++) {
            if (prev[j]) {
                minDiff = min(minDiff, totalSum - 2 * j);
            }
        }
        return minDiff;
    }
};
