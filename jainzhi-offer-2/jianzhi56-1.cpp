#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
// 数组中只出现一次的两个数字
class Solution {
  public:
    vector<int> sockCollocation(vector<int> &sockets) {
        int n = sockets.size();
        int res=0;
        for(auto val:sockets){
            res = res ^ val;
        }
        // lowbit ( n ) 定义为非负整数 n 在二进制表示下最低位的 1
        // 及其后面的所有的 0 ” 的二进制构成的数值。
        int lowbit = res & -res;
        vector<int> ans(2,0);
        for(auto val:sockets){
            if(val&lowbit)
                ans[0] = ans[0] ^ val;
            else
                ans[1] = ans[1] ^ val;
        }
        return ans;
    }
};