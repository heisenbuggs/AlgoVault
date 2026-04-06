#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>> image, int r, int c, int newColor, int oldColor, int dr[], int dc[]) {
        image[r][c] = newColor;

        int m = image.size(), n = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == oldColor) {
                dfs(image, nr, nc, newColor, oldColor, dr, dc);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        dfs(image, sr, sc, newColor, oldColor, dr, dc);
        return image;
    }
};