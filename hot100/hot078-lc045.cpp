#include <bits/stdc++.h>
using namespace std;

// 45. 跳跃游戏 II
class Solution {
  public:
    int jump(vector<int> &nums) {
        int last = 0;
        int mx = 0;
        int ret = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            mx = max(mx, i + nums[i]);
            if (i == last) {
                last = mx;
                ret++;
            }
        }
        return ret;
    }
};