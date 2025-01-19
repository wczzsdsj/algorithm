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

// 124. 二叉树中的最大路径和
/* 核心是注意当前节点的最大路径，与当前节点作为子节点时的贡献是两个不同的值
当前节点的最大路径： max(自己，自己+左边，自己+右边，自己 + 左边 + 右边）
当前节点作为子节点时的贡献：max(自己，自己+左边，自己+右边）
后者相对前者，少了左右都存在的情况。因为作为子节点时，一条路如果同时包含左右，根就被包含了2次，不符合题目只出现一次的限制了。
*/
class Solution {
  public:
    int maxPathSum(TreeNode *root) {
        int ret = INT_MIN;
        // 这里不能用auto，因为函数内部调用了自身
        function<int(TreeNode *)> dfs = [&](TreeNode *cur) -> int {
            if (cur == nullptr)
                return 0;
            int curmaxsum = cur->val;
            int l = dfs(cur->left);
            int r = dfs(cur->right);
            if (l < 0)
                l = 0;
            if (r < 0)
                r = 0;
            // 左右经过cur节点的最大路径和
            ret = max(ret, curmaxsum + l + r);
            // 注意这里返回值，向上返回，需经过cur，所以加cur->val.到这一步l,r都>=0，向上返回上下经过cur节点的最大路径和
            return cur->val + max(l, r);
        };
        dfs(root);
        return ret;
    }
};