#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    double val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//二叉树的层序遍历
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==nullptr)
            return {};
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int m = q.size();
            for (int i = 0; i < m;i++)
            {
                tmp.push_back(q.front()->val);
                TreeNode *front = q.front();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                q.pop();
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};