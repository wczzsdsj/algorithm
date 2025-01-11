#include <bits/stdc++.h>
using namespace std;

// 200. 岛屿数量
class Solution {
  public:
    bool visit[305][305] = {false};
    int x_add[4] = {0, -1, 0, 1};
    int y_add[4] = {-1, 0, 1, 0};
    void dfs(vector<vector<char>> &grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, x + x_add[i], y + y_add[i], n, m);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    res++;
                    cout << res << endl;
                }
            }
        }
        return res;
    }
};