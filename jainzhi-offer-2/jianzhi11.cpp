#include<iostream>
#include<vector>
using namespace std;

//翻转数组的最小值
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size()-1;
        int mid ;
        int ans = nums[0];
        while(l<r){
            mid = (l+r) / 2;
            if(nums[mid]<nums[r])
                r = mid;
            else if(nums[mid]>nums[r])
                l = mid+1;  //注意+1，要不然在最后两个相邻时会死循环
            else
                r--;
        }
        ans = nums[l];
        return ans;
    }
};