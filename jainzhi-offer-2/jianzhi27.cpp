
#include <iostream>
#include <algorithm>
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