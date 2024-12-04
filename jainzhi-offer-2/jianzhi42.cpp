#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int maxsum = -1e9;
        int cursum = -1;
        for (auto val : nums)
        {
            if (cursum <= 0)
                cursum = val;
            else
                cursum = cursum + val;
            maxsum = max(maxsum, cursum);
        }
        return maxsum;
    }
};