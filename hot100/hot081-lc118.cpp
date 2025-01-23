#include <bits/stdc++.h>
using namespace std;

// 118. 杨辉三角
class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return {{1}, {1, 1}};
        vector<vector<int>> ret(numRows);
        ret[0].push_back(1);
        ret[1].push_back(1);
        ret[1].push_back(1);

        for (int i = 2; i < numRows; i++) {
            ret[i].push_back(1);
            for (int j = 1; j < i; j++) {
                ret[i].push_back(ret[i - 1][j] + ret[i - 1][j - 1]);
            }
            ret[i].push_back(1);
        }
        return ret;
    }
};