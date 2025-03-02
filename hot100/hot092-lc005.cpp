#include <bits/stdc++.h>
using namespace std;

// 5. 最长回文子串
// 动态规划
class Solution {
  public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int maxlen = 0;
        string ret;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                int l = j - i + 1;
                if (l == 1 || (l == 2 && s[i] == s[j]))
                    dp[i][j] = 1;
                else {
                    if (s[i] == s[j])
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && l > maxlen) {
                    maxlen = max(maxlen, l);
                    ret = s.substr(i, l);
                }
            }
        }
        return ret;
    }
};

// 中心扩展算法，力扣耗时更短
class Solution {
  public:
    string ret;
    string longestPalindrome(string s) {
        int len = 1;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            extendfromcenter(s, i, i);
            extendfromcenter(s, i, i + 1);
        }

        return ret;
    }

    void extendfromcenter(string &s, int x, int y) {
        while (x >= 0 && y < s.size() && s[x] == s[y]) {
            x--;
            y++;
        }
        if (y - x - 1 > ret.size()) {
            ret = s.substr(x + 1, y - x - 1);
        }
    }
};