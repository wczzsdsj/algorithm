#include <bits/stdc++.h>
using namespace std;

// 33. 搜索旋转排序数组
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[0]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else
                    r = mid - 1;
            }
        }
        return -1;
    }
};

// 81. 搜索旋转排序数组 II （nums有重复的数字）
class Solution {
  public:
    bool search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) {
                l++;
                r--;
            } else if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else
                    r = mid - 1;
            }
        }
        return false;
    }
};