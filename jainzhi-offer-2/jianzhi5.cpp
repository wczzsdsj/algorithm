#include<string>
#include<iostream>
using namespace std;

//替换空格 字符串复制
class Solution5
{
public:
    string replaceSpace(string s)
    {
        
        int n = s.length(),numOfBlank=0;
        if(n==0)
            return s;
        for (auto str:s)
        {
            if(str==' ')
                numOfBlank++;
        }
        s.resize(n+2*numOfBlank);
        int p1 = n - 1, p2 = s.length() - 1;
        while(p1>=0&&p1!=p2){
            if(s[p1]!=' '){
                s[p2] = s[p1];
                p1--;
                p2--;
            }
            else{
                s[p2--] = '0';
                s[p2--] = '2';
                s[p2--] = '%';
                p1--;
            }

        }
        return s;
    }
};
int main(){

    string s = " abc ";
    Solution5* sol = new Solution5();
    cout<<sol->replaceSpace(s)<<endl;
    return 0;
}