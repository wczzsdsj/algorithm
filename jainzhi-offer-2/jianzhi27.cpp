
#include <iostream>
#include <algorithm>
#include<queue>
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
//翻转(镜像)二叉树
//递归
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if(root==nullptr)
            return nullptr;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//循环
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if(root==nullptr)
            return root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *frontNode = q.front();
            swap(frontNode->left,frontNode->right);
            if(frontNode->left)
                q.emplace(frontNode->left);
            if(frontNode->right)
                q.emplace(frontNode->right);
            q.pop();
        }
        return root;
    }
};