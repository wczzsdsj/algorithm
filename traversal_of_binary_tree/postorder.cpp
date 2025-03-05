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

// 后序遍历，左右中，可由中右左翻转得到，类似先序遍历
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> vi;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *top = stk.top();
            stk.pop();
            vi.emplace_back(top->val);
            if (top->left)
                stk.push(top->left);
            if (top->right)
                stk.push(top->right);
        }
        reverse(vi.begin(), vi.end());
        return vi;
    }
};