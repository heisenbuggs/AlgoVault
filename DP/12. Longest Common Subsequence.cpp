#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    int lcsHelper(string& text1, string& text2, int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (text1[m - 1] == text2[n - 1]) {
            return 1 + lcsHelper(text1, text2, m - 1, n - 1);
        } else {
            return max(lcsHelper(text1, text2, m - 1, n), lcsHelper(text1, text2, m, n - 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        return lcsHelper(text1, text2, text1.size(), text2.size());
    }
};

class TabulationSolution {
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};