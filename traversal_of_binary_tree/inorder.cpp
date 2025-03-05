#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right)
        : val(_val), left(_right), right(_right) {}
};

// 二叉树遍历题解： https://leetcode.cn/problems/binary-tree-preorder-traversal/solutions/87526/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2
// 中序遍历，左中右
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> vi;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        // 不需要对root先压进栈
        while (cur != nullptr || !stk.empty()) {
            while (cur) {
                // root在这里进栈
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            vi.emplace_back(cur->val);
            cur = cur->right;
        }
        return vi;
    }
};