#include <bits/stdc++.h>
using namespace std;
class RecursiveSolution {
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
            return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n),
                       knapsack(W, wt, val, n - 1));
    }
};

class TabulationSolution {
    int knapsack(int W, vector<int> wt, vector<int> val, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i][w - wt[i - 1]]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        // The last cell of the dp array contains the maximum value
        return dp[n][W];
    }
};

class SpaceOptimizedSolution {
    int knapsack(int W, vector<int> wt, vector<int> val, int n) {
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                // Take the maximum of including or excluding the item
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        return dp[W];
    }
};