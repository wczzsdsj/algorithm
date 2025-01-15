#include <bits/stdc++.h>
using namespace std;

// 153.寻找旋转排序数组中的最小值
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int mid;
        int ans = nums[0];
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else if (nums[mid] > nums[r])
                l = mid + 1;
            // 如nums有相同的数字：
            // else
            //     r--;
        }
        ans = nums[l];
        return ans;
    }
};

// 154. 寻找旋转排序数组中的最小值 II （nums有相同的数字）
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[r])
                r--;
            else if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }

        return nums[l];
    }
};