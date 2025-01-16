#include <bits/stdc++.h>
using namespace std;

// 4. 寻找两个正序数组的中位数
class Solution {
  public:
    int dfs(vector<int> &nums1, vector<int> &nums2, int i, int j, int k) {
        if (i >= nums1.size())
            return nums2[j + k - 1];
        if (j >= nums2.size())
            return nums1[i + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int ret;
        int p = k / 2;
        int x = i + p - 1 < nums1.size() ? nums1[i + p - 1] : 1 << 30;
        int y = j + p - 1 < nums2.size() ? nums2[j + p - 1] : 1 << 30;
        // 注意这里k-k/2
        if (x > y)
            ret = dfs(nums1, nums2, i, j + k / 2, k - k / 2);
        else
            ret = dfs(nums1, nums2, i + k / 2, j, k - k / 2);
        return ret;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        int a = dfs(nums1, nums2, 0, 0, (m + n + 1) / 2);
        int b = dfs(nums1, nums2, 0, 0, (m + n + 2) / 2);
        return (a + b) / 2.0;
    }
};