#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int coinChange(int n, vector<int> coins, int amount) {
        // Base case: if amount is 0, return 1 (one way to make change)
        if (amount == 0)
            return 1;
        // If no coins left or amount becomes negative, return 0
        if (n == 0 || amount < 0)
            return 0;

        // Include the last coin and exclude it
        return coinChange(n, coins, amount - coins[n - 1]) +
               coinChange(n - 1, coins, amount);
    }
};  

class TabulationSolution {
    int coinChange(int n, vector<int> coins, int amount) {
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            }
        }

        return dp[n][amount];
    }
};

class SpaceOptimizedSolution {
    int coinChange(int n, vector<int> coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};