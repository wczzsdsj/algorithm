#include<iostream>
#include<vector>
using namespace std;
// 数组中出现次数超过一半的数字
// 摩尔投票法
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int major = 0;
        for (int i = 0; i < nums.size();i++)
        {
            if(cnt==0)
                major = nums[i];
            if(nums[i]==major)
                cnt++;
            else
                cnt--;
        }
        return major;
    }
};