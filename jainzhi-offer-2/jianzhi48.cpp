#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

// 最长不含重复字符的子字符串

// // 外层循环扩展右边界，内层循环扩展左边界
// for (int l = 0, r = 0; r < n; r++)
// {
//     // 当前考虑的元素
//     while (l <= r && check())
//     { // 区间[left,right]不符合题意
//         // 扩展左边界
//     }
//     // 区间[left,right]符合题意，统计相关信息
// }
// 滑动窗口
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        if(len==0)
            return 0;
        int maxLength = -1;
        unordered_map<char, int> mp;
        for (int i = 0, j = 0; i < len;i++)
        {
            while(mp.count(s[i])){
                mp.erase(s[j++]);
            }
            maxLength = max(maxLength,i-j+1);
            mp[s[i]]++;
        }
        return maxLength;
    }
};
//动态规划
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        if (len == 0)
            return 0;
        int maxLength = 0,cur=0;
        vector<int> existindex(128,-1);
        for (int i = 0; i < len;i++)
        {
            if(existindex[s[i]]!=-1){
                int d = i - existindex[s[i]];
                if (d <= cur)
                    cur = d;
                else
                    cur++;
            }else 
                cur += 1;
            maxLength = max(maxLength,cur);
            existindex[s[i]] = i;
        }

        return maxLength;
    }
};