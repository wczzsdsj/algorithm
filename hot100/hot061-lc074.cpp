#include <bits/stdc++.h>
using namespace std;

// 74. 搜索二维矩阵
class Solution {
public:
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int up = 0, down = m - 1;
    while (up <= down) {
        int mid = (up + down) / 2;
        if (matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] < target)
            up = mid + 1;
        else
            down = mid - 1;
    }
    int col = up - 1;
    if (col < 0)
        return false;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (matrix[col][mid] == target)
            return true;
        else if (matrix[col][mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return false;
}
}
;