#include <iostream>
#include <vector>
using namespace std;

// 26. 删除有序数组中的重复项
// nums[k-1] 为上一个应该被保留的元素所移动到的指定位置。
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        for (int &val : nums) {
            if (k == 0 || val != nums[k - 1]) {
                nums[k++] = val;
            }
        }
        return k;
    }
};