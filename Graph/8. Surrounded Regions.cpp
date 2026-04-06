#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>> &mat, int m, int n, int r, int c, int dr[], int dc[], vector<vector<int>> &vis) {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && mat[nr][nc]=='O') {
                dfs(mat, m, n, nr, nc, dr, dc, vis);
            }
        }
    }

    vector<vector<char>> regions(vector<vector<char>> &mat, int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(mat, m, n, i, 0, dr, dc, vis);
            }

            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(mat, m, n, i, m - 1, dr, dc, vis);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && mat[0][i] == 'O') {
                dfs(mat, m, n, 0, i, dr, dc, vis);
            }

            if (!vis[n - 1][i] && mat[n - 1][i] == 'O') {
                dfs(mat, m, n, n - 1, i, dr, dc, vis);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};