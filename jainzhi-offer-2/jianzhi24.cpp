#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//反转链表
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(!head)
            return head;
        ListNode *pre = nullptr, *cur = head;
        while(cur){
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};