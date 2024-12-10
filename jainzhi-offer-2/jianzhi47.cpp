#include<iostream>
#include<vector>
using namespace std;
// 礼物的最大价值
class Solution
{
public:
    int jewelleryValue(vector<vector<int>> &frame)
    {
        int n = frame.size();
        int m = frame[0].size();
        if(m==0||n==0)
            return 0;
        vector<vector<int>> dp(n+1, vector(m+1, 0));
        dp[1][1] = frame[0][0];
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + frame[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};
//空间优化
class Solution
{
public:
    int jewelleryValue(vector<vector<int>> &frame)
    {
        int n = frame.size();
        int m = frame[0].size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(2, vector(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i&1][j] = max(dp[i&1^1][j], dp[i&1][j - 1]) + frame[i - 1][j - 1];
            }
        }
        return dp[n&1][m];
    }
};