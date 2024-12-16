#include <iostream>
#include<algorithm>
#include<cmath>
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
// 平衡二叉树 自底向上时间复杂度O(n)，避免重复子问题
class Solution {
  public:
    bool isBalancedCore(TreeNode *cur, int &depth) {
        if(cur==nullptr){
            depth = 0;
            return true;
        }
        int ldepth, rdepth;
        if(isBalancedCore(cur->left, ldepth)==0||isBalancedCore(cur->right, rdepth)==0)
            return false;
        if(abs(ldepth-rdepth)>1)
            return false;
        depth = max(ldepth, rdepth) + 1;
        return true;
    }

    bool isBalanced(TreeNode *root) {
        int depth = 0; // int depth;
        return isBalancedCore(root,depth);
    }
};