#include <bits/stdc++.h>
using namespace std;

// 39. 组合总和
class Solution {
  public:
    vector<vector<int>> ret;
    vector<int> vi;
    void dfs(vector<int> &candidates, int target, int sum, int index) {
        if (sum == target) {
            ret.push_back(vi);
            return;
        }
        if (sum + candidates[index] > target)
            return;
        for (int i = index; i < candidates.size(); i++) {
            vi.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i);
            vi.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return ret;
    }
};