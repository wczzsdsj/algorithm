#include <bits/stdc++.h>
using namespace std;

// 198. 打家劫舍
class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int ret = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            for (int j = 0; j <= i - 2; j++) {
                dp[i] = max(dp[i], nums[i] + dp[j]);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};