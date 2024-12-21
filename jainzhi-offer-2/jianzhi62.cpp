#include<bits/stdc++.h>
using namespace std;
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
// 模拟超时
class Solution_moni {
  public:
    int iceBreakingGame(int num, int target) {
        vector<int> vi(num,0);
        bool remain[num];
        memset(remain,1,sizeof(remain));
        for (int i = 0; i < num;i++) {
            vi[i] = i;
        }
        int index_del = -1;
        int round = 1;
        while(round<=num-1){
            for (int i = 1; i <= target;i++) {
                int k = 1;
                while (remain[(index_del + k) % num] == 0) {
                    k++;
                }
                index_del = (index_del + k) % num;
            }
            remain[index_del] = 0;
            round++;
        }
        for (int i = 0; i < num; i++) {
            if (remain[i] == 1)
                return vi[i];
        }
        return -1;
    }
};

int main(){
    Solution_moni* obj=new Solution_moni();
    cout<<obj->iceBreakingGame(5,3)<<endl;
    return 0;
}