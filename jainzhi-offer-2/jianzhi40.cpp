#include<bits/stdc++.h>
using namespace std;
// 最小的 k 个数
// 快速排序
class Solution
{
public:

    vector<int> inventoryManagement(vector<int> &stock, int cnt)
    {
        function<void(int, int)> quicksort = [&](int l, int r)
        {
            if (l >= r)
                return;
            int pivot = stock[r];
            int left = l,right = l;
            while(right<r)
            {
                if(stock[right]<pivot)
                {
                    swap(stock[left],stock[right]);
                    left++;
                }
                right++;
            }
            swap(stock[left],stock[r]);
            if(left==cnt)
                return;
            if(left>cnt)
                quicksort(l,left-1);
            else
                quicksort(left+1,r);
        };
        vector<int> ans;
        quicksort(0,stock.size()-1);
        for (int i = 0; i < cnt;i++)
        {
            ans.push_back(stock[i]);
        }
        return ans;
    }
};
//优先队列
class Solution
{
public:
    vector<int> inventoryManagement(vector<int> &stock, int cnt)
    {
        // priority_queue<int, vector<int>, less<int>> q_less;
        priority_queue<int> q;
        vector<int> ans;
        for (int i = 0; i < stock.size();i++)
        {
            q.push(stock[i]);
            if(q.size()>cnt){
                q.pop();
            }
        }
        while(!q.empty()){
            ans.emplace_back(q.top());
            q.pop();
        }
        return ans;
    }
};