#include <bits/stdc++.h>
using namespace std;

// 300. 最长递增子序列
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int size = nums.size();
        vector<int> dp(size, 1);
        int ret = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
                ;
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};