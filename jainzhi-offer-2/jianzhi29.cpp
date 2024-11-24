#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

//顺时针打印矩阵

//模拟
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if(matrix.size()==0||matrix[0].size()==0)
            return {};
        int m = matrix.size(), n = matrix[0].size();
        int curx = 0, cury = 0,k=0;
        int dirs[5] = {0,1,0,-1,0};
        vector<int> vi(m*n);
        bool vis[m][n];
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < m * n;i++)
        {
            vi[i] = matrix[curx][cury];
            vis[curx][cury] = 1;
            int nextx = curx + dirs[k], nexty = cury + dirs[k + 1];
            if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || vis[nextx][nexty] == 1){
                k = (k+1) % 4;
                nextx = curx + dirs[k];
                nexty = cury + dirs[k + 1];
            }
            curx = nextx;
            cury = nexty;
        }
        return vi;
    }
};
//按层模拟
class Solution_level
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> vi;
        int leftx = 0, lefty = 0, rightx = m - 1, righty = n - 1;
        while (leftx <= rightx && lefty <= righty)
        {
            for (int i = lefty; i <= righty;i++)
            {
                vi.emplace_back(matrix[leftx][i]);
            }
            for (int i = leftx + 1; i <= rightx;i++)
            {
                vi.emplace_back(matrix[i][righty]);
            }
            if (leftx < rightx && lefty < righty){
                for (int i = righty - 1; i >= lefty; i--){
                    vi.emplace_back(matrix[rightx][i]);
                }
                for (int i = rightx - 1; i >= leftx + 1;i--){
                    vi.emplace_back(matrix[i][lefty]);
                }
            }
            leftx++;
            lefty++;
            rightx--;
            righty--;
        }
        return vi;
    }
};

int main(){
    vector<int> vi={1,2,3,4};
    vector<int>::iterator it;
    for (it = vi.begin(); it != vi.end();it++){
        printf("%d ",*it);
    }

    return 0;
}