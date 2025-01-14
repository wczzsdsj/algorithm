#include <bits/stdc++.h>
using namespace std;

// 79. 单词搜索
class Solution {
  public:
    int x_add[4] = {0, -1, 0, 1};
    int y_add[4] = {-1, 0, 1, 0};

    int visit[10][10];

    bool dfs(vector<vector<char>> &board, string word, int i, int j,
             int index) {
        if (index >= word.length())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            visit[i][j] == 1)
            return false;
        if (board[i][j] != word[index])
            return false;
        visit[i][j] = 1;
        int flag = false;
        for (int k = 0; k < 4; k++) {
            flag =
                flag || dfs(board, word, i + x_add[k], j + y_add[k], index + 1);
        }
        visit[i][j] = 0;
        return flag;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size();
        // vector<vector<bool>> visit(m,vector(n,false));
        int flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // memset(visit,0,sizeof(visit));
                // fill(visit.begin(),visit.end(),0);
                if (word[0] == board[i][j]) {
                    flag = flag || dfs(board, word, i, j, 0);
                }
            }
        }
        return flag;
    }
};