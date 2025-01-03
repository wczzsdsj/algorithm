#include <bits/stdc++.h>
using namespace std;

// 54. 螺旋矩阵
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        int flag = 0;
        int x_add[4] = {0, 1, 0, -1};
        int y_add[4] = {1, 0, -1, 0};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visit(m, vector(n, false));
        int x_cur = 0, y_cur = 0;
        for (int i = 0; i < m * n; i++) {
            ans.emplace_back(matrix[x_cur][y_cur]);
            visit[x_cur][y_cur] = 1;
            int x_next = x_cur + x_add[flag];
            int y_next = y_cur + y_add[flag];
            if (x_next < 0 || x_next >= m || y_next < 0 || y_next >= n ||
                visit[x_next][y_next] == 1) {
                flag = (flag + 1) % 4;
                x_next = x_cur + x_add[flag];
                y_next = y_cur + y_add[flag];
            }
            x_cur = x_next;
            y_cur = y_next;
        }
        return ans;
    }
};