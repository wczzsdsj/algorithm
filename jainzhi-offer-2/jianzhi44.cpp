#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n <= 9)
            return n;
        int k = 1;
        int cnt = 9;
        while (n > 1ll * k * cnt)
        {
            n = n - (k * cnt);
            k++;
            cnt = cnt * 10;
        }
        int num = pow(10, k - 1) + (n - 1) / k;
        int mod = (n - 1) % k;
        return to_string(num)[mod] - '0';
    }
};