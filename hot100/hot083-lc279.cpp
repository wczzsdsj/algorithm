#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int numSquares(int n) {
//         int m=sqrt(n);
//         vector<vector<int>> dp(m+1,vector(n+1,0x3f));
//         dp[0][0]=0;
//         for(int i=1;i<=m;i++){
//             for(int j=0;j<=n;j++){
//                 dp[i][j]=dp[i-1][j];
//                 if(j>=i*i) dp[i][j]=min(dp[i-1][j],dp[i][j-i*i]+1);
//             }
//         }
//         return dp[m][n];
//     }
// };

// 279. 完全平方数
class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0x3f);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
