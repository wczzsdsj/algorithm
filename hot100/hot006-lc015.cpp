#include <bits/stdc++.h>
using namespace std;

// 三数之和
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0)
                continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] > 0) {
                    k--;
                } else if (nums[j] + nums[k] + nums[i] < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return res;
    }
};