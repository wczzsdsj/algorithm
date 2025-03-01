#include <bits/stdc++.h>
using namespace std;

// 416. 分割等和子集
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (auto &val : nums) {
            sum += val;
        }
        if (sum % 2 != 0)
            return false;
        int m = sum >> 1;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            int val = nums[i - 1];
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= val)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - val];
            }
        }
        return dp[nums.size()][m];
    }
};
