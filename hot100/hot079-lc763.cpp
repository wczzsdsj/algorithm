#include <bits/stdc++.h>
using namespace std;

// 763. 划分字母区间
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        map<char, int> index;
        for (int i = 0; i < s.size(); i++) {
            index[s[i]] = i;
        }
        vector<int> ret;
        int j = 0;
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            last = max(last, index[s[i]]);
            if (i == last) {
                ret.push_back(i - j + 1);
                j = i + 1;
            }
        }
        return ret;
    }
};