#include <functional>
#include <iostream>
#include <vector>
using namespace std;
// 在排序数组中查找数字 I
class Solution {
  public:

    vector<int> searchRange(vector<int> &nums, int target) {
        int firstindex = -1, lastindex = -1;
        function<int(int,int)> getFirst = [&](int l,int r) -> int {
            if(l>r)
                return firstindex;
            int mid = (l+r) / 2;
            if(target<nums[mid])
                getFirst(l,mid-1);
            else if(target>nums[mid])
                getFirst(mid+1,r);
            else{
                if(mid-1>=0&&nums[mid-1]==target){
                    getFirst(l,mid-1);
                } else if (mid - 1 >= 0 && nums[mid - 1] != target) {
                    firstindex = mid;
                }else{
                    firstindex = 0;
                }
            }
            return firstindex;
        };
        function<int(int, int)> getLast = [&](int l, int r) -> int {
            if (l > r)
                return lastindex;
            int mid = (l + r) / 2;
            if (target < nums[mid])
                getLast(l, mid - 1);
            else if (target > nums[mid])
                getLast(mid + 1, r);
            else {
                if (mid +1 <= nums.size()-1 && nums[mid + 1] == target) {
                    getLast(mid+1,r);
                } else if (mid + 1 <= nums.size() - 1 &&
                           nums[mid + 1] != target) {
                    lastindex = mid;
                } else {
                    lastindex = nums.size() - 1;
                }
            }
            return lastindex;
        };
        getFirst(0,nums.size()-1);
        getLast(0,nums.size()-1);
        return {firstindex,lastindex};
    }
};

class Solution {
  public:
    int binarysearcch(vector<int> &nums, int target,int flag) {
        int i = 0, j = nums.size() - 1;
        int res = -1;
        while(i<=j){
            int mid = (i + j) / 2;
            if(nums[mid]>target){
                j = mid - 1;
            }else if(nums[mid]<target){
                i = mid + 1;
            }else{
                res = mid;
                if(flag)
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        return {binarysearcch(nums, target, 0), binarysearcch(nums, target, 1)};
    }
};