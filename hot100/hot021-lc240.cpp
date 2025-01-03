#include <bits/stdc++.h>
using namespace std;

// 240. 搜索二维矩阵 II
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int curx = 0, cury = n - 1;
        while (curx < m && cury >= 0) {
            if (matrix[curx][cury] == target)
                return true;
            if (matrix[curx][cury] > target)
                cury--;
            else
                curx++;
        }
        return false;
    }
};

// 每一行二分查找，超时，练手
class Solution {
  public:
    int binarysort(vector<int> vi, int target, int l, int r) {
        if (l > r)
            return -1;
        int mid = (l + r) / 2;
        if (vi[mid] == target) {
            return mid;
        } else if (vi[mid] > target) {
            return binarysort(vi, target, l, mid - 1);
        } else
            return binarysort(vi, target, mid + 1, r);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (binarysort(matrix[i], target, 0, n - 1) != -1) {
                return true;
            }
        }
        return false;
    }
};