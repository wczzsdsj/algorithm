#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

//全排列不含重复元素
//回溯+哈希
class Solution
{
public:
    bool vis[10]={0};
    int size;
    vector<string> ans;
    void dfs(string goods,string cur,int index){
        if(index>=size){
            ans.emplace_back(cur);
            return;
        }
        for (int i = 0; i < size;i++)
        {
            //防止重复,a的位置a1，a2，当vis[a1]为0时，a2不能出现，即保证a1在前，a2在后，不重复
            if(vis[i]==1||(i>0&&goods[i]==goods[i-1]&&vis[i-1]==0)){
                continue;
            }
            if(vis[i]==0){
                cur += goods[i];
                vis[i] = 1;
                dfs(goods, cur, index+1);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<string> goodsOrder(string goods)
    {
        memset(vis,0,sizeof(vis));
        size = goods.size();
        sort(goods.begin(),goods.end());
        dfs(goods,"",0);
        return ans;
    }
};

//下一个排列
class Solution
{
public:
    int size;
    vector<string> ans;
    bool nextPermutation(string& cur)
    {
        int i = size - 2;
        while (i >= 0 && cur[i] >= cur[i + 1]){
            i--;
        }
        if(i<0)
            return false;
        int j = size - 1;
        while (j >= 0 && cur[j] <= cur[i]){
            j--;
        }
        swap(cur[i],cur[j]);
        reverse(cur.begin()+i+1,cur.end());
        return true;
    }
    vector<string> goodsOrder(string goods)
    {
        size=goods.size();
        sort(goods.begin(), goods.end());
        string next=goods;
        do{
            ans.push_back(next);
        } while (nextPermutation(next));
        return ans;
    }
};