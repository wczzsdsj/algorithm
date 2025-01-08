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

// 543.二叉树的直径
class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        int ans = 0;
        function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int {
            if (root == nullptr)
                return 0;
            int ldepth = dfs(root->left);
            int rdepth = dfs(root->right);
            ans = max(ans, ldepth + rdepth);
            return max(ldepth, rdepth) + 1;
        };
        dfs(root);
        return ans;
    }
};