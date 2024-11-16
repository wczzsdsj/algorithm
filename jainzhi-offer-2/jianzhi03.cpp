#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0;; ++i)
        {
            while (nums[i] != i)
            {
                int j = nums[i];
                if (nums[j] == j)
                {
                    return j;
                }
                swap(nums[i], nums[j]);
            }
        }
    }
};
//找到重复的数字
class Solution
{
public:
    vector<int> findRepeatNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n;i++){
            while(nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n;i++){
            if(nums[i]!=i) ans.emplace_back();
        }
        return ans;
    }
};