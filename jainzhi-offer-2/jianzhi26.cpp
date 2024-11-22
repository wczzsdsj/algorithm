
#include <iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    double val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//树的子结构
class Solution
{
public:
    bool haveAllNode(TreeNode* a,TreeNode* b){
        if(a==nullptr&&b==nullptr)
            return true;
        if(a==nullptr&&b!=nullptr)
            return false;
        if (a != nullptr && b == nullptr)
            return true;
        bool result = 0;
        if (abs(a->val - b->val) < 1e-8) {
            result = haveAllNode(a->left,b->left)&&haveAllNode(a->right,b->right);
        }
        return result;
    }

    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if(A==nullptr||B==nullptr)
            return false;
        bool result = false;
        
        if(abs(A->val-B->val)<1e-8)
            result=haveAllNode(A,B);
        if(result==0)
            result=isSubStructure(A->left,B);
        if(result==0)
            result = isSubStructure(A->right,B);
        
        return result;
    }

};

int main(){
    return 0;
}