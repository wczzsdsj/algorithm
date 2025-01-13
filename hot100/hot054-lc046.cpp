#include <bits/stdc++.h>
using namespace std;

// 46. 全排列
class Solution {
  public:
    vector<int> nextpermute(vector<int> &nums) {
        if (nums.size() == 1)
            return nums;
        int index = nums.size() - 2;
        while (index >= 0 && nums[index] > nums[index + 1]) {
            index--;
        }
        int right = nums.size() - 1;
        while (index >= 0 && right > index && nums[index] > nums[right]) {
            right--;
        }
        if (index >= 0)
            swap(nums[index], nums[right]);
        reverse(nums.begin() + index + 1, nums.end());
        return nums;
    }

    vector<vector<int>> permute(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> nums_first = nums;
        vector<vector<int>> res;
        res.emplace_back(nums_first);
        while (nextpermute(nums) != nums_first) {
            res.emplace_back(nums);
        }
        return res;
    }
};