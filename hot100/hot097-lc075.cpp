#include <bits/stdc++.h>
using namespace std;

// 75. 颜色分类
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int l = 0;
        int mid = 0;
        int r = nums.size() - 1;
        while (mid <= r) {
            if (nums[mid] == 0) {
                swap(nums[l++], nums[mid]);
                mid++;
            } else if (nums[mid] == 2) {
                // 当我们和右边交换时（处理2的情况），不能立即移动mid指针即不能让mid++，因为交换过来的数字还没有被处理过。
                swap(nums[r--], nums[mid]);
            } else {
                mid++;
            }
        }
    }
};