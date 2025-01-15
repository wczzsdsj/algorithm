#include <bits/stdc++.h>
using namespace std;

// 51. N 皇后
class Solution {
  public:
    int num = 10;
    vector<vector<string>> result;
    vector<string> sol;
    vector<int> index;
    bool check(int n, int col, int row) {
        if (index[col] != -1)
            return false;
        for (int i = 0; i < n; i++) {
            if (index[i] != -1) {
                if (index[i] - row == i - col || index[i] - row == col - i ||
                    row == index[i])
                    return false;
            }
        }
        return true;
    }

    void dfs(int n, int col) {
        if (col == n) {
            result.push_back(sol);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(n, col, i) == 0)
                continue;
            sol[col][i] = 'Q';
            index[col] = i;
            dfs(n, col + 1);
            sol[col][i] = '.';
            index[col] = -1;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        sol.resize(n);
        index.resize(n);
        fill(index.begin(), index.end(), -1);
        string s;
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        for (int i = 0; i < n; i++) {
            sol[i] = s;
        }

        dfs(n, 0);

        return result;
    }
};

// 写法简练：
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n);
        vector<int> dg(n << 1);
        vector<int> udg(n << 1);
        vector<vector<string>> ans;
        vector<string> t(n, string(n, '.'));
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.push_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                    t[i][j] = 'Q';
                    col[j] = dg[i + j] = udg[n - i + j] = 1;
                    dfs(i + 1);
                    col[j] = dg[i + j] = udg[n - i + j] = 0;
                    t[i][j] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};