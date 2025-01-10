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

// 437. 路径总和 III    类似题目： 560. 和为 K 的子数组
class Solution {
  public:
    int cnt = 0;
    unordered_map<long long, int> mp;
    void pathSumCore(TreeNode *root, int targetSum, long long sum) {
        if (root == nullptr)
            return;
        sum = sum + root->val;
        // 注意不要直接 += cnt[s-targetSum]，如果 s-targetSum 不在cnt
        // 中，这会插入 s-targetSum 在 C++ 中，使用 std::map时，访问一个不存在的键会插入该键，并将其值初始化为类型的默认值（例如 0 对于整型）
        if (mp.count(sum - targetSum) != 0) {
            cnt += mp[sum - targetSum];
        }
        mp[sum]++;
        pathSumCore(root->left, targetSum, sum);
        pathSumCore(root->right, targetSum, sum);
        mp[sum]--;
    }

    int pathSum(TreeNode *root, int targetSum) {
        mp[0] = 1;
        pathSumCore(root, targetSum, 0);
        return cnt;
    }
};