#include <bits/stdc++.h>
using namespace std;

// 64. 最小路径和
class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
        }
        for (int j = 1; j <= n; j++) {
            dp[1][j] = dp[1][j - 1] + grid[0][j - 1];
        }

        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

// DFS超时
class Solution {
  public:
    int ret = INT_MAX;
    int nowsum = 0;
    int m, n;
    void dfs(int x, int y, vector<vector<int>> &grid,
             vector<vector<int>> &visit) {
        if (x == m - 1 && y == n - 1) {
            ret = min(ret, grid[m - 1][n - 1] + nowsum);
            return;
        }
        if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y] == 1 ||
            nowsum >= ret)
            return;
        nowsum += grid[x][y];
        visit[x][y] = 1;
        dfs(x, y + 1, grid, visit);
        dfs(x + 1, y, grid, visit);
        visit[x][y] = 0;
        nowsum -= grid[x][y];
    }

    int minPathSum(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visit(m, vector(n, 0));
        dfs(0, 0, grid, visit);
        return ret;
    }
};