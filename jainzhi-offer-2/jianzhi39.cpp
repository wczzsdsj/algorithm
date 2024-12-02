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

// 快速排序

// 时间复杂度：期望为 O(n) ，由于证明过程很繁琐，所以不在这里展开讲。具体证明可以参考《算法导论》第 9 章第 2 小节。
// 最坏情况下的时间复杂度为 O(n^2)。情况最差时，每次的划分点都是最大值或最小值，一共需要划分 n−1 次，
//而一次划分需要线性的时间复杂度，所以最坏情况下时间复杂度为 O(n^2)。
class Solution
{
public:
    void quicksort(vector<int>& nums,int l,int r,int target){
        if(l>=r)
            return ;
        int pivot = nums[r];
        int left = l, right = l;
        while(right<r){
            if(nums[right]<pivot){
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
        swap(nums[left],nums[r]);
        if(left==target)
            return;
        if(left>target)
            quicksort(nums,l,left-1,target);
        else
           quicksort(nums,left+1,r,target);
    }

    int majorityElement(vector<int> &nums)
    {
        quicksort(nums,0,nums.size()-1,nums.size()/2);
        return nums[nums.size() / 2];
    }
};