#include<iostream>
using namespace std;

//数字二进制中一的个数
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int x = 1;
        int count = 0;
        while (x)
        {
            if(n&x)
                count++;
            x = x << 1;
        }
        return count;
    }
};