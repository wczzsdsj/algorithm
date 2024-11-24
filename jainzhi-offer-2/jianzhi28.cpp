#include<iostream>
#include <functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {};
};
//二叉树是否对称
class Solution{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetricCore(root,root);
    }
    bool isSymmetricCore(TreeNode *root1, TreeNode *root2)
    {
        if(root1==nullptr&&root2==nullptr)
            return true;
        if(root1==nullptr||root2==nullptr)
            return false;
        if(root1->val!=root2->val)
            return false;
        return isSymmetricCore(root1->left,root2->right) && isSymmetricCore(root1->right,root2->left);
    }
};
//lambda表达式
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        function<bool(TreeNode *, TreeNode *)> dfs = [&](TreeNode *root1, TreeNode *root2) -> bool
        {
            if (root1 == nullptr&&root2==nullptr)
                return true;
            if(root1==nullptr||root2==nullptr)
                return false;
            if(root1->val!=root2->val)
                return false;
            return dfs(root1->left, root2->right) && dfs(root1->right,root2->left);
        };
        return dfs(root,root);
    }

};