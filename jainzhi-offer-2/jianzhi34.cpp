#include<iostream>
#include<vector>
#include<functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};
// 二叉树中和为某一值的路径
class Solution{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        vector<vector<int>> ans;

        function<void(TreeNode*,int)> dfs = [&](TreeNode* cur,int sum) {
            if(cur==nullptr)
                return;
            sum += cur->val;
            path.push_back(cur->val);
            if(cur->left==nullptr&&cur->right==nullptr&&sum==targetSum){
                ans.push_back(path);
            }
            dfs(cur->left,sum);
            dfs(cur->right,sum);
            path.pop_back();
            sum -= cur->val;
        };
        dfs(root,0);
        return ans;
    }
};

int main(){
    TreeNode *left = new TreeNode(5);//堆上创建，需要delete
    TreeNode *right = new TreeNode(6);
    TreeNode node1;//栈上创建，不需要delete
    TreeNode node2(5);
    TreeNode node3(5,left,right);
    printf("%d,%d,%d",node3.val,node3.left->val,node3.right->val);

    delete left;
    delete right;
    return 0;
}