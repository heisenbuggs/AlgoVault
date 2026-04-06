#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int f(vector<int>& arr, int i, int j) {
        if (i == j) return 0;
        int mini = INT_MAX;

        for (int k = i; k <= j - 1; k++) {
            int ans = f(arr, i, k) + f(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, ans);
        }
        return mini;
    }

    int matrixMultiplication(vector<int>& arr, int n) {
        int i = 1, j = n - 1;
        return f(arr, i, j);
    }
};

class MemoSolution {
    int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j - 1; k++) {
            int ans = f(arr, i, k, dp) + f(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, ans);
        }
        return mini;
    }

    int matrixMultiplication(vector<int>& arr, int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int i = 1, j = n - 1;
        return f(arr, i, j, dp);
    }
};