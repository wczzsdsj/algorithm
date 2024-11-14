#include<iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        int result[2]={0,1};
        if(n==0||n==1)
            return result[n];
        long long a = 0, b = 1;
        long long ans = 0;
        for (int i = 2; i <= n;i++)
        {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};