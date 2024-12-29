#include <bits/stdc++.h>
using namespace std;

// 接雨水
// 双指针
class Solution {
  public:
    int trap(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while (l <= r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

// 单调栈
class Solution {
  public:
    int trap(vector<int> &height) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (st.empty())
                    break;
                int left = st.top();
                int hlen = min(height[left], height[i]) - height[mid];
                ans += hlen * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};