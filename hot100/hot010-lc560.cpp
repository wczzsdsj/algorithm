#include <bits/stdc++.h>
using namespace std;

// 和为 K 的子数组
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pre_sum(n, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                pre_sum[i] = nums[i];
            else
                pre_sum[i] = nums[i] + pre_sum[i - 1];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (pre_sum[i] == k)
                cnt++;
            cnt += mp[pre_sum[i] - k];
            mp[pre_sum[i]]++;
        }
        return cnt;
    }
};