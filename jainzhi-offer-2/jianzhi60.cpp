#include<iostream>
#include<vector>
#include<cmath>
#include<string.h>
using namespace std;
// n 个骰子的点数
class Solution {
  public:
    vector<double> statisticsProbability(int num) {
        const int cnt = 6;
        vector<vector<int>> dp(num+1,vector<int>(cnt*num+1,0));

        for (int i = 1; i <= cnt;i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= num;i++) {
            for (int j = i; j <= cnt * i;j++) {
                for (int k = 1; k <= cnt;k++) {
                    if(j>k)
                        dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        vector<double> res;
        double all = pow(cnt,num);
        for (int i = num; i <= cnt * num;i++) {
            res.push_back(dp[num][i]/all);
        }
        return res;
    }
};

// 滚动数组优化空间
class Solution {
  public:
    vector<double> statisticsProbability(int num) {
        const int cnt = 6;
        // vector<vector<int>> dp(num + 1, vector<int>(cnt * num + 1, 0));
        vector<vector<int>> dp(2,vector<int>(cnt*num+1,0));
        int flag = 0;
        for (int i = 1; i <= cnt;i++) {
            dp[flag][i] = 1;
        }
        flag = (flag + 1) % 2;
        for (int i = 2; i <= num; i++) {
            // memset(&dp[flag][0],0,sizeof(int)*dp[flag].size());
            fill(dp[flag].begin(),dp[flag].end(),0);
            for (int j = i; j <= i * cnt;j++){
                for (int k = 1; k <= cnt;k++) {
                    if(j-k>0)
                        dp[flag][j] += dp[1 - flag][j-k];
                }
            }
            flag=(flag+1)%2;
        }
        vector<double> res;
        double all = pow(cnt, num);
        for (int i = num; i <= cnt * num; i++) {
            res.push_back(dp[1-flag][i] / all);
        }
        return res;
    }
};