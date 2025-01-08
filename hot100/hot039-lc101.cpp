#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// 101. 对称二叉树
class Solution {
  public:
    bool isSymmetricCore(TreeNode *rl, TreeNode *rr) {
        if (rl == nullptr || rr == nullptr) {
            return rr == rl ? 1 : 0;
        }
        if (rl->val != rr->val)
            return false;
        return isSymmetricCore(rl->left, rr->right) &
               isSymmetricCore(rl->right, rr->left);
    }

    bool isSymmetric(TreeNode *root) {
        return isSymmetricCore(root->left, root->right);
    }
};