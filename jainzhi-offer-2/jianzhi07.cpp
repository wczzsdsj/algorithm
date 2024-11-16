#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    // string val;
    // Solution(string a) : val(a) {};

public:
    TreeNode *ConstructCore(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = new TreeNode();
        int m = preorder.size(), n = inorder.size();
        if(m==0||n==0)
            return nullptr;
        root->val = preorder[0];
        root->left = root->right = nullptr;
        if (m == 1 && n == 1)
            return root;
        int num_left = 0;
        for (auto num_order : inorder)
        {
            if (num_order == root->val)
                break;
            else
                num_left++;
        }
        int num_right = n - 1 - num_left;
        vector<int> leftchildpre, leftchildin, rightchildpre, rightchildin;
        // int temp_left = 0;
        // for (auto q : preorder)
        // {
        //     if (temp_left == 0)
        //     {
        //         temp_left++;
        //         continue;
        //     }
        //     else if (temp_left <= num_left)
        //     {
        //         leftchildpre.emplace_back(q);
        //         temp_left++;
        //     }
        //     else
        //         rightchildpre.emplace_back(q);
        // }
        // temp_left = 0;
        // for (auto q : inorder)
        // {
        //     if (temp_left < num_left)
        //     {
        //         leftchildin.emplace_back(q);
        //         temp_left++;
        //     }
        //     else if (temp_left == num_left)
        //     {
        //         temp_left++;
        //         continue;
        //     }
        //     else
        //         rightchildin.emplace_back(q);
        // }
        leftchildpre.assign(preorder.begin() + 1, preorder.begin() + num_left + 1);
        rightchildpre.assign(preorder.begin() + num_left + 1, preorder.end());
        leftchildin.assign(inorder.begin(), inorder.begin() + num_left);
        rightchildin.assign(inorder.begin() + num_left + 1, inorder.end());

        root->left = ConstructCore(leftchildpre, leftchildin);
        root->right = ConstructCore(rightchildpre, rightchildin);
        return root;
    }
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder)
    {
        int m = preorder.size(), n = inorder.size();

        return ConstructCore(preorder, inorder);
    }
};

//标答
class Solution2{

};

int main()
{

    vector<int> pre = { 1,2 };
    vector<int> in = {2,1};
    Solution *sol = new Solution();
    sol->deduceTree(pre,in);
    return 0;
}