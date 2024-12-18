#include <iostream>
#include <vector>
using namespace std;
// 和为 s 的连续正数序列
class Solution {
  public:
    vector<vector<int>> fileCombination(int target) {
        int mid=(target+1)>>1;
        vector<vector<int>> ans;
        int l = 1, r = 2;
        int cursum = l + r;
        while(l<mid){
            while(cursum>=target){
                if(cursum==target){
                    vector<int> cur;
                    for (int i = l; i <= r;i++) {
                        cur.emplace_back(i);
                    }
                    ans.emplace_back(cur);
                }
                cursum -= l;
                l++;
            }
            r++;
            cursum += r;
        }
        return ans;
    }
};