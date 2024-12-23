#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉树的最近公共祖先
// 力扣评论：我觉得吧。这就是一个后序遍历的模型，只不过是每个父节点都会接收子节点的状态（是否含有p、q）并把这个状态往上传递，直到该结点满足祖先节点的条件。这样一想就豁然开朗了。
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root==nullptr||p->val==root->val||q->val==root->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left!=nullptr&&right!=nullptr)
            return root;
        if(left==nullptr)
            return right;
        else
            return left;
    }
};