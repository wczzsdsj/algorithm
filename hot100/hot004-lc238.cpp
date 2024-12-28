#include <bits/stdc++.h>
using namespace std;

// 移动零
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        for (int i = 0, j = 0; i < nums.size() && j < nums.size(); i++, j++) {
            while (j < nums.size() && nums[j] == 0) {
                j++;
            }
            if (j < nums.size())
                swap(nums[i], nums[j]);
        }
        return;
    }
};