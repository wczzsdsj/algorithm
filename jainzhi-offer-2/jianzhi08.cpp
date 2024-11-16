#include<iostream>
using namespace std;
struct TreeLinkNode{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *parent;
    TreeLinkNode(int _val) :val(_val),left(nullptr),right(nullptr) {}
};
class Solution{
public:
    TreeLinkNode* getNextNode(TreeLinkNode* pNode){
        if(pNode==nullptr)
            return nullptr;
        TreeLinkNode *pNext;
        if(pNode->right!=nullptr){
            TreeLinkNode* p = pNode->right;
            while(p->left){
                p = p->left;
            }
            pNext = p;
        }
        else if(pNode->parent!=nullptr){
            TreeLinkNode *pParent = pNode->parent;
            TreeLinkNode *current =pNode;
            while (pParent != nullptr && pParent->right == current)
            {
                current = pParent;
                pParent = pParent->parent;
            }
            pNext = pParent;
        }
        return pNext;
    }
};

class Solution2
{
public:
    TreeLinkNode *getNextNode(TreeLinkNode *pNode)
    {
        Solution *solu = new Solution;
        Solution *solu2 = new Solution();
        Solution solu3 = Solution();
        Solution solu4;
        int* a = new int;
        int* b = new int();
        void *p = malloc(sizeof(int));
        
    }
};