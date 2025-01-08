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

// 108. 将有序数组转换为二叉搜索树
class Solution {
  public:
    TreeNode *sortedArrayToBSTCore(vector<int> &nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        TreeNode *left = sortedArrayToBSTCore(nums, l, mid - 1);
        TreeNode *right = sortedArrayToBSTCore(nums, mid + 1, r);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
    }
};