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

// 230. 二叉搜索树中第 K 小的元素
class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> st;
        int ans;
        while (root != nullptr || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            k--;
            if (k == 0)
                return root->val;
            root = root->right;
        }
        return -1;
    }
};