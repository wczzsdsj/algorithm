#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
    TreeNode(int _val,TreeNode* _left,TreeNode* _right):val(_val),left(_right),right(_right){}
};

// 先序遍历，中左右，用栈模拟，左先访问，所以左后进栈
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr)
            return {};
        stack<TreeNode *> stk;
        vector<int> vi;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *top = stk.top();
            stk.pop();
            vi.emplace_back(top->val);
            if (top->right)
                stk.push(top->right);
            if (top->left)
                stk.push(top->left);
        }
        return vi;
    }
};