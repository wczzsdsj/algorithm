#include <bits/stdc++.h>
using namespace std;

// 78. 子集
class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> vi;
    void dfs(vector<int> &nums, int i) {
        if (i == nums.size()) {
            ans.push_back(vi);
            return;
        }
        dfs(nums, i + 1);
        vi.push_back(nums[i]);
        dfs(nums, i + 1);
        vi.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(nums, 0);
        return ans;
    }
};