#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

//矩阵中的路径
//注意全局变量和局部变量重名的问题
class Solution
{
public:
    int n, m;
    bool vis[10][10]={0};
    int x_[4] = {-1,1,0,0};
    int y_[4] = {0,0,-1,1};
    bool dfs(vector<vector<char>> &board, string word,int x,int y,int k)
    {
        if(k==word.size())
            return true;
        if(x<0||x>=n||y<0||y>=m||vis[x][y]==1||board[x][y]!=word[k])
            return false;
        int ans = 0;
        vis[x][y] = 1;
        if(dfs(board,word,x-1,y,k+1)
            || dfs(board, word, x, y - 1, k + 1) || dfs(board, word, x, y + 1, k + 1) || dfs(board, word, x+1, y , k + 1))
            ans=1;
        vis[x][y] = 0;
        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size(), m = board[0].size();
        if(n==0||m==0)
            return false;
        for (int i = 0; i < n; i++)
        {
            memset(vis,0,sizeof(vis));
            for (int j = 0; j < m;j++)
            {
                if(board[i][j]==word[0]&&dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};

int main(){

    return 0;
}