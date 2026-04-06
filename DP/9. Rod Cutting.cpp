#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int rodCutting(int n, vector<int> price) {
        // Base case: if no length, return 0
        if (n <= 0)
            return 0;

        int max_val = INT_MIN;

        // Try every possible cut
        for (int i = 1; i <= n; i++) {
            max_val = max(max_val, price[i - 1] + rodCutting(n - i, price));
        }
        return max_val;
    }
};

class TabulationSolution {
    int rodCutting(int n, vector<int> price) {
        vector<int> dp(n + 1,   0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        return dp[n];
    }
};