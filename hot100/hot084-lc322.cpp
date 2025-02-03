#include <bits/stdc++.h>
using namespace std;

// 322. 零钱兑换
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size(), m = amount;
        vector<int> f(amount + 1, amount + 1);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = coins[i - 1]; j <= amount; j++) {
                f[j] = min(f[j], f[j - coins[i - 1]] + 1);
            }
        }
        return f[amount] > amount ? -1 : f[amount];
    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size(),m=amount;
//         vector<vector<int>> f(n+1,vector<int>(amount+1,amount+1));
//         f[0][0]=0;
//         for(int i=1;i<=n;i++){
//             for(int j=0;j<=amount;j++){
//                 f[i][j]=f[i-1][j];
//                 if(j>=coins[i-1]) f[i][j]=min(f[i][j],f[i][j-coins[i-1]]+1);
//             }
//         }
//         return f[n][amount]>amount? -1:f[n][amount];
//     }
// };

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int m = coins.size(), n = amount;
//         int f[m + 1][n + 1];
//         memset(f, 0x3f, sizeof(f));
//         f[0][0] = 0;
//         for (int i = 1; i <= m; ++i) {
//             for (int j = 0; j <= n; ++j) {
//                 f[i][j] = f[i - 1][j];
//                 if (j >= coins[i - 1]) {
//                     f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
//                 }
//             }
//         }
//         return f[m][n] > n ? -1 : f[m][n];
//     }
// };