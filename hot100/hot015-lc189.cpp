#include <bits/stdc++.h>
using namespace std;

// 轮转数组
class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() == 0)
            return;
        k = k % nums.size();
        // reverse(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k,nums.end());
        auto core = [&](int l, int r) {
            while (l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        };
        core(0, nums.size() - 1);
        core(0, k - 1);
        core(k, nums.size() - 1);
    }
};