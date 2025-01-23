#include <bits/stdc++.h>
using namespace std;

// 31. 下一个排列
class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int k = n - 2;
        while (k >= 0 && nums[k] >= nums[k + 1]) {
            k--;
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = n - 1;
        while (l > k && nums[l] <= nums[k]) {
            l--;
        }
        cout << l << ' ' << k << endl;
        swap(nums[l], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};