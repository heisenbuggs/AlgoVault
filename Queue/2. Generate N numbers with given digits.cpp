/**
 * Given two digits 5 and 6, generate N numbers such that all the numbers are in sorted order.
 * The generated numbers should only contain digits 5 and 6.
 * For example, if N = 10, then the output should be 5, 6, 55, 56, 65, 66, 555, 556, 565, 566.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> firstN(int n) {
        queue<string> q;
        q.push("5");
        q.push("6");
        vector<string> ans;

        for (int count = 0; count < n; count++) {
            string curr = q.front();
            ans.push_back(curr);
            q.pop();
            q.push(curr + "5");
            q.push(curr + "6");
        }
        return ans;
    }
};