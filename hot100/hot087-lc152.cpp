#include <bits/stdc++.h>
using namespace std;

// 152. 乘积最大子数组
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        vector<int> dp_max(nums.size());
        vector<int> dp_min(nums.size());
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp_max[i] = max(
                {dp_max[i - 1] * nums[i], nums[i], dp_min[i - 1] * nums[i]});
            dp_min[i] = min(
                {dp_max[i - 1] * nums[i], nums[i], dp_min[i - 1] * nums[i]});
            ret = max(ret, dp_max[i]);
        }
        return ret;
    }
};