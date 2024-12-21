#include<bits/stdc++.h>
// 圆圈中最后剩下的数字(约瑟夫环问题)
class Solution {
  public:
    int iceBreakingGame(int num, int target) {
        if(num==1)
            return 0;
        int res = 0;
        for (int i = 2; i <= num;i++) {
            res = (res + target) % i;
        }
        return res;
    }
};