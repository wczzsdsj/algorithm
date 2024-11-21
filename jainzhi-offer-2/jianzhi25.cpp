#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//合并链表，递归
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if(list1==nullptr)
            return list2;
        else if(list2==nullptr)
            return list1;
        ListNode *newHead;
        if (list1->val < list2->val){
            newHead = list1;
            newHead->next = mergeTwoLists(list1->next,list2);
        }
        else{
            newHead = list2;
            newHead->next = mergeTwoLists(list1,list2->next);
        }
        return newHead;
    }
};
//合并链表，迭代
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy=new ListNode(-1);
        ListNode *prev;
        prev=dummy;
        while(list1&&list2){
            if(list1->val<list2->val){
                prev->next = list1;
                list1 = list1->next;
            }else{
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return dummy->next;
    }
};