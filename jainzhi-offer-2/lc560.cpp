
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 和为 K 的子数组
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if(nums.size()==0)
            return 0;
        int n = nums.size();
        int pre=0;
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0]++;

        for (int i = 0; i < n;i++)
        {
            pre = pre + nums[i];
            ans += mp[pre-k];
            mp[pre]++;
        }

        return ans;
    }
};