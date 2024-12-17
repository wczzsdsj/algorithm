#include <iostream>
#include <vector>
using namespace std;

// 数组中只出现一次的数字
class Solution {
  public:
    int trainingPlan(vector<int> &nums) {
        int cnt[32] = {0};
        for (auto val : nums) {
            int k = 1;
            for (int i = 1; i < 32; i++) {
                if (val & k) {
                    cnt[i]++;
                }
                k = k << 1;
            }
        }
        int ans = 0;
        for (int i = 1; i < 32; i++) {
            // cout << cnt[i] << ' ';
            if (cnt[i] % 3 != 0) {
                ans = ans | (1 << (i - 1));
            }
        }
        return ans;
    }
};