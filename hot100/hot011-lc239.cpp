#include <bits/stdc++.h>
using namespace std;

// 滑动窗口最大值
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> d;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (d.empty() == 0 && nums[i] >= nums[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
            if (i - k == d.front())
                d.pop_front();
            if (i >= k - 1) {
                ans.push_back(nums[d.front()]);
            }
        }
        return ans;
    }
};