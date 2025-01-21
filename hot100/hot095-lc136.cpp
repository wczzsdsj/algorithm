#include <bits/stdc++.h>
using namespace std;

// 136. 只出现一次的数字
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int ret = 0;
        for (auto &val : nums) {
            ret = ret ^ val;
        }
        return ret;
    }
};