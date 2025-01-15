#include <bits/stdc++.h>
using namespace std;

// 34.在排序数组中查找元素的第一个和最后一个位置
class Solution {
  public:
    //注意是double类型
    int search(vector<int> &nums, double target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        int left = search(nums, target - 0.5);
        int right = search(nums, target + 0.5) - 1;

        if (left >= 0 && left < n && right >= 0 && right < n &&
            nums[left] == target && nums[right] == target) {
            return {left, right};
        }
        return {-1, -1};
    }
};

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        int leftidx=-1, rightidx=-1;
        int l = 0, r = nums.size() - 1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(nums[mid]==target){
                leftidx = mid;
                r = mid - 1;
            }else if(nums[mid]<target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                rightidx = mid;
                l = mid + 1;
            } else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return {leftidx, rightidx};
        // if (leftidx >= 0 && leftidx < n && rightidx >= 0 && rightidx < n &&
        //     nums[leftidx] == target && nums[rightidx] == target) {
        //     return {leftidx, rightidx};
        // }
        // return {-1, -1};
    }
};