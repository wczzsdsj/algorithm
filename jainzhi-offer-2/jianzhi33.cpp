#include<iostream>
#include<vector>
#include<functional>
#include<stack>
using namespace std;

//判断是否是二叉搜索树的后序遍历
class Solution
{
public:
    bool verifyTreeOrder(vector<int> &postorder)
    {
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if(i>=j)
                return true;
            int lastnum = postorder[j];
            int index = i;
            while(index<j&&postorder[index]<lastnum){
                index++;
            }
            for (int k = index; k < j;k++){
                if(postorder[k]<lastnum)
                    return false;
            }
            return dfs(i,index-1) && dfs(index,j-1);
        };
       
        return dfs(0,postorder.size()-1);
    }
};
//单调栈
class Solution
{
public:
    bool verifyTreeOrder(vector<int> &postorder)
    {
        int root = INT_MAX;
        stack<int> s;
        reverse(postorder.begin(),postorder.end());
        for(int val:postorder){
            if(val>root)
                return false;
            while(!s.empty()&&s.top()>val){
                root = s.top();
                s.pop();
            }
            s.push(val);
        }
        return true;
    }
};