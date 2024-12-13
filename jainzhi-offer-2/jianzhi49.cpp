#include<iostream>
#include<vector>
#include <queue>
#include<set>
using namespace std;
// 丑数 II:丑数是只包含质因数 2、3 和/或 5 的正整数；1 是丑数。
// 时间复杂度 n
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n,0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n;i++)
        {
            dp[i] = min(min(dp[p2]*2,dp[p3]*3),dp[p5]*5);
            if (dp[i] == dp[p2] * 2)
                p2++;
            if(dp[i] == dp[p3] * 3)
                p3++;
            if (dp[i] == dp[p5] * 5)
                p5++;
        }
        return dp[n-1];
    }
};
// 时间复杂度 nlogn 
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        set<long long> st;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        st.insert(1);
        q.push(1);
        int mul[3] = {2, 3, 5};
        for (int i = 1; i < n; i++)
        {
            long long top = q.top();
            q.pop();
            for (int j = 0; j < 3; j++)
            {
                if (st.count(top * mul[j]) == 0)
                {
                    q.push(top * mul[j]);
                    st.insert(top * mul[j]);
                }
            }
        }
        return q.top();
    }
};