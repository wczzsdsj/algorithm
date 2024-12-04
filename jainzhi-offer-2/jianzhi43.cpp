#include<iostream>
using namespace std;
typedef long long ll;
//1 ～ n 整数中 1 出现的次数 
class Solution
{
public:
    int countDigitOne(int n)
    {
        ll bit = 1;
        int sum = 0;
        while(bit<=n){
            int cur = (n / bit) % 10;
            int high = n / bit / 10;
            int low = n % bit;
            if(cur>1){
                sum += (high + 1) * bit;
            }else if(cur==1){
                sum += high * bit + 1 + low;
            }else{
                sum += high * bit;
            }
            bit *= 10;
        }
        return sum;
    }
};