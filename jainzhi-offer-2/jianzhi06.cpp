#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//链表第一个相交的结点
class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA, *b = headB;
        while(a!=b){
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }
        return a;
    }
};

//从尾到头打印链表
class Solution
{
public:
    vector<int> reverseBookList(ListNode *head)
    {
        stack<int> s;
        while (head != nullptr)
        {
            s.push(head->val);
            head = head->next;
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.emplace_back(s.top());
            s.pop();
        }
        return ans;
    }
};