#include <bits/stdc++.h>
using namespace std;

class RecursiveKnapsack {
    int knapsack(int W, vector<int> wt, vector<int> val, int n) {
        // Base case: if no items or no capacity, return 0
        if (n == 0 || W == 0)
            return 0;

        // If the weight of the nth item is more than the capacity W,
        // we cannot include it in the optimal solution
        if (wt[n - 1] > W)
            return knapsack(W, wt, val, n - 1);

        // Return the maximum of two cases:
        // 1. nth item included
        // 2. nth item not included
        else
            return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
                       knapsack(W, wt, val, n - 1));
    }
};

class MemoizationKnapsack {
    int knapsack(int W, vector<int> wt, vector<int> val, int n, vector<vector<int>>& dp) {
        if (n == 0 || W == 0)
            return 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wt[n - 1] > W)
            return dp[n][W] = knapsack(W, wt, val, n - 1, dp);
        else
            return dp[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, dp),
                                  knapsack(W, wt, val, n - 1, dp));
    }
};

class TabulationKnapsack {
    int knapsack(int W, vector<int> wt, vector<int> val, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    dp[i][w] = 0;
                else if (wt[i - 1] > w)
                    dp[i][w] = dp[i - 1][w];
                else
                    dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                                   dp[i - 1][w]);
            }
        }
        return dp[n][W];
    }
};
