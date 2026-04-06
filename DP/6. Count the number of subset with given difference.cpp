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

    int countSubsetsWithDiffK(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int targetSum = (totalSum + diff) / 2;
        if ((totalSum + diff) % 2) return 0;
        return countSubsetsWithSum(arr, n, totalSum);
    }
};

class TabulationSolution {
    int countSubsetsWithDiffK(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        int targetSum = (totalSum + diff) / 2;
        if ((totalSum + diff) % 2) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= targetSum; j++) {
                if (arr[i] <= j) {
                    dp[i + 1][j] = dp[i][j] + dp[i][j - arr[i]];
                } else {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }
        return dp[n][targetSum];
    }
};
