#include <bits/stdc++.h>
using namespace std;

// 无重复字符的最长子串
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int lastindex[128];
        memset(lastindex, -1, sizeof(lastindex));
        int ans = 0;
        int i = 0, j = 0;
        while (j < s.length()) {
            if (lastindex[s[j]] != -1 && lastindex[s[j]] >= i) {
                i = lastindex[s[j]] + 1;
            }
            ans = max(ans, j - i + 1);
            lastindex[s[j]] = j;
            j++;
        }
        return ans;
    }
};