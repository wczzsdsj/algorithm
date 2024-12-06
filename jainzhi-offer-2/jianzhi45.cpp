#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//把数组排成最小的数
class Solution
{
public:
    static bool cmp(int a,int b){
        string aa = to_string(a);
        string bb = to_string(b);
        string ab = aa + bb;
        string ba = bb + aa;
        return ab < ba;
    }

    string crackPassword(vector<int> &password)
    {
        if(password.size()==0)
            return "";
        // cmp 函数应当是一个静态成员函数或全局函数。因为 std::sort 需要一个不依赖于对象状态的函数。
        sort(password.begin(), password.end(),cmp);
        string ans;
        for(int val:password){
            ans += to_string(val);
        }
        return ans;
    }
};
