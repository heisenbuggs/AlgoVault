/**
 * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
 * return the k closest points to the origin (0, 0).
 * The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
 * You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
 * 
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (vector<int> &point : points) {
            pq.push(point);
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};
