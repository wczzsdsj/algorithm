#include <bits/stdc++.h>
using namespace std;

// 739. 每日温度
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                ret[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ret;
    }
};