#include <bits/stdc++.h>
using namespace std;

// 最大子数组和
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int cur = 0, maxsum = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                cur = nums[i];
            else {
                cur = max(cur + nums[i], nums[i]);
            }
            maxsum = max(cur, maxsum);
        }
        return maxsum;
    }
};