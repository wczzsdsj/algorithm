#include <bits/stdc++.h>
using namespace std;

// 994. 腐烂的橘子
class Solution {
  public:
    bool check(vector<vector<int>> &grid, int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
            return true;
        else
            return false;
    }

    int orangesRotting(vector<vector<int>> &grid) {
        int x_add[4] = {0, 1, 0, -1};
        int y_add[4] = {-1, 0, 1, 0};
        int m = grid.size();
        int n = grid[0].size();
        int numofgood = 0;
        int res = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    numofgood++;
                }
            }
        }
        while (numofgood != 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    if (check(grid, x + x_add[k], y + y_add[k], m, n)) {
                        numofgood--;
                        grid[x + x_add[k]][y + y_add[k]] = 2;
                        q.push({x + x_add[k], y + y_add[k]});
                    }
                }
            }
            res++;
        }

        return numofgood == 0 ? res : -1;
    }
};