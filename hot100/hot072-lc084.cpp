#include <bits/stdc++.h>
using namespace std;

// 84. 柱状图中最大的矩形
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        int ret = INT_MIN;
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty())
                left[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < heights.size(); i++) {
            ret = max(ret, (right[i] - left[i] - 1) * heights[i]);
        }
        return ret;
    }
};