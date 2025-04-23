#include <iostream>
#include <vector>
using namespace std;

// 80. 删除有序数组中的重复项 II
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        for (int &val : nums) {
            if (k == 0 || k == 1 || val != nums[k - 2]) {
                nums[k++] = val;
            }
        }
        return k;
    }
};