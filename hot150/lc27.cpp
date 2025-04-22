#include<iostream>
#include<vector>
using namespace std;

// 27. 移除元素
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int k = 0;
        for (auto &x : nums) {
            if (x != val) {
                nums[k] = x;
                k++;
            }
        }
        return k;
    }
};