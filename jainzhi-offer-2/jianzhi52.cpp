#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
// 相交链表的第一个公共节点
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while ((a!=nullptr||b!=nullptr)&&a != b) {
            a = a == nullptr ? headB: a->next;
            b = b == nullptr ? headA: b->next;
        }
        return a;
    }
};