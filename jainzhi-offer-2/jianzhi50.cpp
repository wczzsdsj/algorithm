#include<string>
using namespace std;
// 第一个只出现一次的字符
class Solution{
public:
    char dismantlingAction(string arr)
    {
        int num[26]={0};
        for(auto val:arr){
            num[val - 'a']++;
        }
        char res = ' ';
        for(auto val:arr){
            if(num[val-'a']==1){
                res = val;
                break;
            }
        }
        return res;
    }
};