#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 21. 合并两个有序链表
class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1 == nullptr)
            cur->next = list2;
        else
            cur->next = list1;

        return dummy->next;
    }
};