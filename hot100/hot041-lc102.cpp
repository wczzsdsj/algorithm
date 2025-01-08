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

// 102. 二叉树的层序遍历
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vi;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *front = q.front();
                vi.emplace_back(front->val);
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ans.push_back(vi);
        }
        return ans;
    }
};