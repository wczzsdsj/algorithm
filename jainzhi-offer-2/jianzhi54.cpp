
#include<iostream>
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
// 二叉搜索树的第 k 大节点
class Solution {
  public:
    int res = -1;
    void dfs(TreeNode *cur, int &cnt) {
        if (cur == nullptr || cnt <= 0)
            return;
        dfs(cur->right, cnt);
        cnt--;
        if (cnt == 0) {
            res = cur->val;
            return;
        }
        dfs(cur->left, cnt);
    }

    int findTargetNode(TreeNode *root, int cnt) {
        dfs(root, cnt);
        return res;
    }
};