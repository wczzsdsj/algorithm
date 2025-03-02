#include <bits/stdc++.h>
using namespace std;

// 32. 最长有效括号
// B站https://www.bilibili.com/video/BV1oF411V7Q5/?spm_id_from=333.337.search-card.all.click&vd_source=cc7adf58253bcac68d2ea96993678000
class Solution {
  public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int countleft = 0;
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                countleft++;
            } else {
                if (countleft > 0) {
                    int len = dp[i - 1] + 2;
                    int preindex = i - len;
                    if (preindex > 0)
                        len += dp[preindex];
                    dp[i] = len;
                    ret=max(ret,len);
                    countleft--;
                }
            }
        }

        return ret;
    }
};

// 栈
class Solution {
  public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                ans = max(ans, i - stk.top());
            }
        }
        return ans;
    }
};