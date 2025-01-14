#include <bits/stdc++.h>
using namespace std;

// 131. 分割回文串
// 非最优解
class Solution {
  public:
    bool check(string s) {
        // if(s=="")return false;
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> ret;
    vector<string> vi;

    void dfs(string s, int index, int l) {
        if (index == s.length()) {
            if (l < s.length())
                return;
            for (auto &val : vi) {
                if (check(val) == false)
                    return;
            }
            ret.push_back(vi);
            return;
        }
        dfs(s, index + 1, l);

        string str = s.substr(l, index - l + 1);
        if (check(str) == false)
            return;
        vi.push_back(str);
        dfs(s, index + 1, index + 1);
        vi.pop_back();
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0, 0);
        return ret;
    }
};