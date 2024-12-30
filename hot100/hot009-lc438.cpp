#include <bits/stdc++.h>
using namespace std;

// 找到字符串中所有字母异位词
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;
        if (m < n) {
            return ans;
        }
        vector<int> snum(26, 0);
        vector<int> pnum(26, 0);
        for (int i = 0; i < n; i++) {
            pnum[p[i] - 'a']++;
            snum[s[i] - 'a']++;
        }
        if (pnum == snum)
            ans.push_back(0);
        for (int i = n; i < m; i++) {
            snum[s[i] - 'a']++;
            snum[s[i - n] - 'a']--;
            if (pnum == snum)
                ans.push_back(i - n + 1);
        }

        return ans;
    }
};