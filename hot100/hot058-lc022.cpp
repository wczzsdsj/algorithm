#include <bits/stdc++.h>
using namespace std;

// 22. 括号生成
class Solution {
  public:
    vector<string> ret;
    string s;
    void dfs(int n, int leftnum, int index) {
        if (leftnum < 0)
            return;
        if (index == 2 * n) {
            if (leftnum == 0) {
                ret.push_back(s);
            }
            return;
        }

        s += '(';
        dfs(n, leftnum + 1, index + 1);
        s.pop_back();

        s += ')';
        dfs(n, leftnum - 1, index + 1);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ret;
    }
};