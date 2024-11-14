#include<iostream>
#include<string.h>
using namespace std;


//机器人的运动范围
class Solution
{
public:
    bool vis[105][105];
    int x_add[4] = {-1,1,0,0};
    int y_add[4] = {0,0,-1,1};
    int getSum(int a){
        int ans = 0;
        while(a!=0){
            ans = ans + a % 10;
            a = a / 10; ////注意错误
        }
        return ans;
    }
    bool check(int m, int n, int x, int y,int cnt)
    {
        if (x < 0 || x >= m || y < 0 || y >= n||getSum(x)+getSum(y)>cnt||vis[x][y]==1)
            return 0;
        else
            return 1;
    }
    int movingCountCore(int m, int n,int x,int y,int cnt){
        if(check(m,n,x,y,cnt)==0)
            return 0;
        int ans = 1;
        vis[x][y] = 1;
        for (int i = 0; i < 4;i++)
        {
            int p = x + x_add[i];
            int q = y + y_add[i];
            if(check(m,n,p,q,cnt)){
                ans+=movingCountCore(m,n,p,q,cnt);
            }
        }
        return ans;
    }

    int movingCount(int m, int n, int cnt)
    {
        memset(vis,0,sizeof(vis));

        return movingCountCore(m,n,0,0,cnt);
    }
};

int main(){
    int m=4, n=7, cnt=5;
    Solution *obj = new Solution();
    cout<<obj->movingCount(m,n,cnt);
}