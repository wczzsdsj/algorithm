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

// 199. 二叉树的右视图
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (i == 0) {
                    ans.push_back(node->val);
                }
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
        }
        return ans;
    }
};