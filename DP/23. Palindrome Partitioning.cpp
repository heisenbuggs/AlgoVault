#include <bits/stdc++.h>
using namespace std;

class RecursiveSolution {
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int palPartitionRec(string& s, int i, int j) {
        // Base case: If the substring is empty or
        // a palindrome, no cuts needed
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        int res = INT_MAX, cuts;

        // Iterate through all possible partitions and
        // find the minimum cuts needed
        for (int k = i; k < j; k++) {
            cuts = 1 + palPartitionRec(s, i, k) + palPartitionRec(s, k + 1, j);
            res = min(res, cuts);
        }

        return res;
    }

    int palindromePartition(string& s) {
        return palPartitionRec(s, 0, s.size() - 1);
    }
};

class MemoizationSolution {
    vector<vector<int>> dp;
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int palPartitionRec(string& s, int i, int j) {
        // Base case: If the substring is empty or
        // a palindrome, no cuts needed
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX, cuts;

        // Iterate through all possible partitions and
        // find the minimum cuts needed
        for (int k = i; k < j; k++) {
            cuts = 1 + palPartitionRec(s, i, k) + palPartitionRec(s, k + 1, j);
            res = min(res, cuts);
        }

        return dp[i][j] = res;
    }

    int palindromePartition(string& s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return palPartitionRec(s, 0, n - 1);
    }
};

class TabulationSolution {
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int palindromePartition(string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the table in a bottom-up manner
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    dp[i][j] = 0;
                } else {
                    int res = INT_MAX;
                    for (int k = i; k < j; k++) {
                        res = min(res, 1 + dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = res;
                }
            }
        }
        return dp[0][n - 1];
    }
};