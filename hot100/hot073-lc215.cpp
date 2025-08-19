#include <bits/stdc++.h>
using namespace std;

// 215. 数组中的第K个最大元素

// 快速排序
class Solution {
  public:
    int quicksort(vector<int>&nums,int l,int r,int target){
        int mid = l + (r-l) / 2;
        swap(nums[mid],nums[r]);
        int j = l;
        for (int i = l; i <= r;i++) {
            if(nums[i]<nums[r]){
                swap(nums[j],nums[i]);
                j++;
            }
        }
        swap(nums[j],nums[r]);
        if(target==j)
            return nums[j];
        else if(target<j){
            return quicksort(nums,l,j-1,target);
        }else
            return quicksort(nums,j+1,r,target);
    }

    int findKthLargest(vector<int> &nums, int k) {
        int target=nums.size()-k;
        return quicksort(nums, 0, nums.size() - 1, target);
    }
};

// 小顶堆 nlogk, greater是小顶堆
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            q.push(nums[i]);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};

// 桶排序
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        int mi = INT_MAX, ma = INT_MIN;
        for (auto val : nums) {
            ma = max(ma, val);
            mi = min(mi, val);
        }
        int num_bucket = (ma - mi) / 100 + 1;
        vector<vector<int>> vi(num_bucket);
        for (int i = 0; i < nums.size(); i++) {
            int index = (nums[i] - mi) / 100;
            vi[index].push_back(nums[i]);
        }
        // for(int i=0;i<num_bucket;i++){
        //     sort(vi[i].begin(),vi[i].end());
        // }
        for (int i = num_bucket - 1; i >= 0; i--) {
            int sub = k - vi[i].size();
            // ！！！特别注意：vi[i].size()返回值是uint，与k相加减，k会隐式转变为uint，返回值也是uint，导致判断条件错误
            if (sub <= 0) {
                sort(vi[i].begin(), vi[i].end());
                return vi[i][vi[i].size() - k];
            } else
                k = k - vi[i].size();
        }
        return -1;
    }
};