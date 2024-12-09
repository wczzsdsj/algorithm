#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
// 把数字翻译成字符串
class Solution
{
public:
    bool isright(char a,char b){
        if(a=='1')
            return true;
        if (a == '2'&&b>='0'&&b<='5')
            return true;
        return false;
    }
    int crackNumber(int ciphertext)
    {
        string nums = to_string(ciphertext);
        int size = nums.size();
        if(size==0)
            return 0;
        int dp[15];
        memset(dp,0,sizeof(dp));
        dp[size - 1] = 1;

        for (int i = size - 2; i >= 0;i--)
        {
            if(i+1<size&&(isright(nums[i],nums[i+1]))){
                if(i+2<size)
                    dp[i] += dp[i+2];
                else
                    dp[i] += 1;
            }
            dp[i]+=dp[i + 1];
        }
        return dp[0];
    }
};
