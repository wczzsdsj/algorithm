#include <bits/stdc++.h>
using namespace std;

// 合并区间
class Solution {
  public:
    // static bool cmp(vector<int> a,vector<int> b){
    //     if(a[0]!=b[0]) return a[0]<b[0];
    //     else return a[1]<b[1];
    // }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans.push_back(intervals[0]);
            else {
                int cursize = ans.size();
                if (intervals[i][0] > ans[cursize - 1][1]) {
                    ans.push_back(intervals[i]);
                } else {
                    ans[cursize - 1][1] =
                        max(intervals[i][1], ans[cursize - 1][1]);
                }
            }
        }
        return ans;
    }
};