#include <bits/stdc++.h>
using namespace std;

// 287. 寻找重复数
// 每个位置 i 连一条 i→nums[i] 的边由于存在的重复的数字 target，因此 target
// 这个位置一定有起码两条指向它的边，因此整张图一定存在环，且我们要找到的 target
// 就是这个环的入口，那么整个问题就等价于 142. 环形链表 II。
class
      Solution {
  public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[nums[fast]],slow=nums[slow];;
        while(fast!=slow){
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        fast=0;
        while(fast!=slow){
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i+1){
                if(nums[i]==nums[nums[i]-1]) return nums[i];
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        return -1;
    }
};


class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return l;
    }
};