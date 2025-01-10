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

// 105. 从前序与中序遍历序列构造二叉树
class Solution {
  public:
    unordered_map<int, int> mp;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int pl,
                        int pr, int il, int ir) {
        if (pl > pr || il > ir)
            return nullptr;
        int rootval = preorder[pl];
        int index = mp[rootval];
        TreeNode *root = new TreeNode(rootval);

        root->left = buildTree(preorder, inorder, pl + 1, pl + index - il, il,
                               index - 1);
        root->right = buildTree(preorder, inorder, pl + index - il + 1, pr,
                                index + 1, ir);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0,
                         inorder.size() - 1);
    }
};