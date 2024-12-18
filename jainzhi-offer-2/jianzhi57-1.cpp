#include<vector>
#include<iostream>
using namespace std;

// 和为 s 的两个数字
class Solution {
  public:
    vector<int> twoSum(vector<int> &price, int target) {
        int l = 0, r = price.size() - 1;
        int sum;
        while (l < r) {
            sum = price[l] + price[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else
                break;
        }
        if (l >= r)
            return {};
        return {price[l], price[r]};
    }
};