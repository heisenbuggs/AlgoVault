#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int helper(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = helper(coins, amount - coin);
            if (res != INT_MAX) {
                minCoins = min(minCoins, res + 1);
            }
        }
        return minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        int result = helper(coins, amount);
        return result == INT_MAX ? -1 : result;
    }
};

class TabulationSolution {
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

class SpaceOptimisedSolution {
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, INT_MAX);
        vector<int> curr(amount + 1, INT_MAX);
        prev[0] = 0;

        for (int coin : coins) {
            for (int i = 0; i <= amount; ++i) {
                if (i - coin >= 0 && prev[i - coin] != INT_MAX) {
                    curr[i] = min(curr[i], prev[i - coin] + 1);
                } else {
                    curr[i] = prev[i];
                }
            }
            swap(prev, curr);
            fill(curr.begin(), curr.end(), INT_MAX);
        }
        return prev[amount] == INT_MAX ? -1 : prev[amount];
    }
};