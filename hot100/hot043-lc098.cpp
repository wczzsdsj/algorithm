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

// 98. 验证二叉搜索树
// 中序遍历递增序列，迭代实现
class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> stack;
        long long preval = INT_MIN - 1l;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (root->val <= preval)
                return false;
            preval = root->val;
            root = root->right;
        }
        return true;
    }
};