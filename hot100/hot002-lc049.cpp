#include<bits/stdc++.h>
using namespace std;

// 字母异位词分组
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        if (strs.size() == 0)
            return {{""}};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].emplace_back(strs[i]);
        }
        for (unordered_map<string, vector<string>>::iterator it = mp.begin();
             it != mp.end(); it++) {
            res.emplace_back(it->second);
        }
        return res;
    }
};