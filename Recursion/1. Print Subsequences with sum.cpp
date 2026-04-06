/*
 * Print all subsequences whose sum is `sum`.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void printS(int ind, vector<int> &ds, int s, int sum, vector<int> &arr, int n) {
        if (ind == n) {
            if (s == sum) {
                for (auto it: ds) cout << it << " ";
                cout << "/n";
            }
            return;
        }
        
        // pick the element
        ds.push_back(arr[ind]);
        s += arr[ind];
    
        printS(ind+1, ds, s, sum, arr, n);
        
        s -= arr[ind];
        ds.pop_back();
    
        // not pick the element
        printS(ind+1, ds, s, sum, arr, n);
    }
    
    void printSubsequences(vector<int> &arr, int n, int sum) {
        vector<int> ds;
        printS(0, ds, 0, sum, arr, n);
    }
};

// Time Complexity : O(2^n)