#include <bits/stdc++.h>
using namespace std;

// 41. 缺失的第一个正数
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] - 1l != i) {
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1])
                    break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1l != i)
                return i + 1;
        }
        return n + 1;
    }
};