#include <bits/stdc++.h>
using namespace std;

// 盛最多水的容器
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int cur = min(height[l], height[r]) * (r - l);
            ans = max(ans, cur);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};