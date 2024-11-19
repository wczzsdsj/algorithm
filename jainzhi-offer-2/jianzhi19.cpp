#include<iostream>
#include<string>
#include<string.h>

using namespace std;

//正则表达式匹配
//动态规划
class Solution{
public:
    bool isMatch(string s,string p){
        int m = s.size(), n = p.size();

        bool ismatch[m+1][n+1];//前m个字符和前n个字符是否匹配
        memset(ismatch,0,sizeof(ismatch));
        ismatch[0][0] = 1;
        for (int i = 0; i <= m;i++){
            for (int j = 1; j <= n;j++){
                if (p[j - 1] == '*'){
                    ismatch[i][j] |= ismatch[i][j-2];
                    if (i&&(p[j-2] == '.' || s[i-1] == p[j-2]))
                        ismatch[i][j] |= ismatch[i-1][j];
                }
                else if (i && (p[j - 1] == '.' || s[i - 1] == p[j - 1]))
                    ismatch[i][j] = ismatch[i - 1][j - 1];
            }
        }
        return ismatch[m][n];
    }
};
//记忆化搜索
class Solution{
    public:
    int m ,n;
    bool f[25][25];
    bool dfs(int i, int j, string& s, string& p)
    {
        if(j>=n)
            return i == m;
        if(f[i][j])
            return f[i][j];

        int res = 0;
        if(p[j+1]=='*'){
            res|=dfs(i,j+2,s,p);
            if(i<m&&(p[j]=='.'||s[i]==p[j]))
                res |= dfs(i+1,j,s,p);
        }
        else{
            if (i<m&&(p[j] == '.' || s[i] == p[j]))
                res |= dfs(i + 1, j+1, s, p);
        }
        return res;
    }

    bool isMatch(string s,string p){
        m = s.size(), n = p.size();
        memset(f, 0, sizeof(f));
        return dfs(0,0,s,p);
    }
};