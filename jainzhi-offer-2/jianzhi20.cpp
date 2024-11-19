#include<iostream>
using namespace std;
//有效数字，无空格
class Solution
{
public:
    int m;
    bool scanUInt(const string &s, int &index)
    {
        int temp = index;
        while (index < m)
        {
            if (s[index] >= '0' && s[index] <= '9')
                index++;
            else
                break;
        }
        return index > temp;
    }
    bool scanInt(const string &s, int &index)
    {
        if (s[index] == '+' || s[index] == '-')
            index++;
        return scanUInt(s, index);
    }
    bool validNumber(string s)
    {
        m = s.size();
        bool ret;
        int index = 0;
        ret = scanInt(s, index);
        if (s[index] == '.')
        {
            ret |= scanUInt(s, ++index);
        }
        if (s[index] == 'e' || s[index] == 'E')
        {
            index++;
            ret &= scanInt(s, index);
        }
        return ret;
    }
};

//有空格
class Solution
{
public:
    int m;
    void scanSpace(const string&s,int &index){
        while(index<m&&s[index]==' '){
            index++;
        }
    }
    bool scanUInt(const string &s, int& index)
    {
        int temp = index;
        while(index<m){
            if(s[index]>='0'&&s[index]<='9')
                index++;
            else
                break;
        }
        return index > temp;
    }
    bool scanInt(const string& s,int& index){
        if(s[index]=='+'||s[index]=='-')
            index++;
        return scanUInt(s,index);
    }
    bool validNumber(string s)
    {
        m = s.size();
        bool ret=false;
        int index = 0;
        scanSpace(s,index);
        ret = scanInt(s,index);
        if(s[index]=='.'){
            ret |= scanUInt(s,++index);
        }
        if(s[index]=='e'||s[index]=='E'){
            index++;
            ret&=scanInt(s,index);
        }
        scanSpace(s, index);
        return ret&&(index==m);
    }
};