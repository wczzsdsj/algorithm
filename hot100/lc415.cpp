#include<string>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

//大数相加减
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string ans;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();
        int carry = 0;
        for (int i = 0; i < m || i < n;i++)
        {
            int temp=carry;
            if(i<m)
                temp += num1[i] - '0';
            if(i<n)
                temp += num2[i] - '0';
            if(temp>9){
                carry = 1;
                temp -= 10;
            } else carry = 0;
            ans.push_back(temp+'0');
        }
        if(carry!=0)
            ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string subStrings(string num1,string num2){
        string ans;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();
        for (int i = 0; i < m || i < n;i++)
        {
            int temp = 0;
            if(i<m)
                temp += num1[i]-'0';
            if(i<n)
                temp -= num2[i]-'0';
            if (temp<0 && i < m - 1){
                num1[i + 1]--;
                temp += 10;
            }
            ans.push_back(temp+'0');
        }
        reverse(ans.begin(), ans.end());
        //删除前导0
        int pos;
        for (pos = 0; pos < ans.size() - 1;pos++)
        {
            if(ans[pos]!=0) break;
        }
        cout << ans;
        return ans.substr(pos);
    }
};

int main(){
    string a = "123", b = "120";
    Solution *obj = new Solution();
    obj->subStrings(a,b);

    return 0;
}