#include <bits/stdc++.h>
using namespace std;

// 构建乘积数组
class Solution {
  public:
    vector<int> statisticalResult(vector<int> &arrayA) {
        int size = arrayA.size();
        vector<int> ans(size);
        int left = 1;
        for (int i = 0; i < arrayA.size(); i++) {
            if (i - 1 >= 0)
                left = left * arrayA[i - 1];
            ans[i] = left;
        }
        int right = 1;
        for (int i = size - 1; i >= 0; i--) {
            if (i + 1 <= size - 1)
                right = right * arrayA[i + 1];
            ans[i] *= right;
        }
        return ans;
    }
};