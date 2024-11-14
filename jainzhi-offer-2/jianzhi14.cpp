#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

typedef long long ll;
//切绳子1官方题解
class Solution
{
public:
    int cuttingBamboo(int bamboo_len)
    {
        int *dp = new int[bamboo_len + 1]; // 或者vector<int> dp(bamboo_len+1);
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        // dp[3]=2;
        for (int i = 3; i <= bamboo_len; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max({dp[i], dp[j] * (i - j), j * (i - j)});
            }
        }

        return dp[bamboo_len];
    }
};
//求幂，方法一快速幂 O(longn)，方法二循环累乘求余O(n)  
class Solution1
{
public:
    //返回值也需要为long long，因为后面还*4，或者*2，可能溢出
    long long qpow(long long base,long long exp,long long mod){

        base = base % mod;
        long long ans = 1;
        while(exp>0){
            if(exp%2==1)
                ans = ans * base%mod;
            exp = exp / 2;
            base = base * base%mod;
        }
        return ans;
    }
    int cuttingBamboo(int bamboo_len)
    {
        if(bamboo_len<4)
            return bamboo_len - 1;
        if(bamboo_len%3==0)
            return qpow(3,bamboo_len/3,1e9+7);
        if(bamboo_len%3==1)
            return qpow(3, bamboo_len / 3 - 1, 1e9 + 7) * 4 % 1000000007;
        // if(bamboo_len%3==2)
        return qpow(3, bamboo_len / 3, 1e9 + 7) * 2 % 1000000007;
    }
};


//剪绳子2 官方题解
class Solution2
{
public:
    int cuttingBamboo(int bamboo_len)
    {
        if (bamboo_len <= 3)
            return bamboo_len - 1;
        int b = bamboo_len % 3, p = 1000000007;
        long rem = 1, x = 3;
        for (int a = bamboo_len / 3 - 1; a > 0; a /= 2)
        {
            if (a % 2 == 1)
                rem = (rem * x) % p;
            x = (x * x) % p;
        }
        if (b == 0)
            return (int)(rem * 3 % p);
        if (b == 1)
            return (int)(rem * 4 % p);
        return (int)(rem * 6 % p);
    }
};
int main(int argc,char **argv){
    return 0;
}