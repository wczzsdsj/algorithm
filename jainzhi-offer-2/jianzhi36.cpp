#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
//将二叉搜索树转化为排序的双向链表
class Solution
{
private:
    Node *head=nullptr, *pre=nullptr;
    void dfs(Node* cur){
        if(cur==nullptr)
            return;
        dfs(cur->left);
        if(pre==nullptr)
            head = cur;
        else{
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
        dfs(cur->right);
    }
public:

    Node *treeToDoublyList(Node *root)
    {
        if(root==nullptr)
            return root;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};