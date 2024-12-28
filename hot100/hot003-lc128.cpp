#include <bits/stdc++.h>
using namespace std;

// 最长连续序列
// 正答：
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> st;
        for (auto &v : nums) {
            st.insert(v);
        }
        int res = 0;
        unordered_set<int>::iterator it;
        for (it = st.begin(); it != st.end(); it++) {
            int num = *it;
            int temp = num;
            if (st.count(num - 1) == 0) {
                while (st.count(num + 1) != 0) {
                    num += 1;
                }
                res = max(res, num - temp + 1);
            }
        }
        return res;
    }
};

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        map<int, int> mp;
        for (auto v : nums) {
            mp[v] = 1;
        }
        map<int, int>::iterator it;
        int res = 0;
        for (it = mp.begin(); it != mp.end(); it++) {
            if (mp[it->first] == 1) {
                int k = it->first;
                int temp = k;
                mp[k] = 0;
                while (mp.count(++k) != 0) {
                    mp[k] = 0;
                }
                res = max(res, k - temp);
            }
        }
        return res;
    }
};