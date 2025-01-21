#include <bits/stdc++.h>
using namespace std;

// 169. 多数元素
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int vote;
        int sum = 0;
        for (auto &val : nums) {
            if (sum <= 0)
                vote = val;
            if (val == vote)
                sum++;
            else
                sum--;
        }
        return vote;
    }
};