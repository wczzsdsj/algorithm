#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 24. 两两交换链表中的节点 
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *node1 = head, *node2 = head->next;
        while (node1 && node2) {
            ListNode *node3 = node2->next;
            node1->next = node3;
            node2->next = node1;
            pre->next = node2;
            pre = node1;
            node1 = node3;
            if (node1)
                node2 = node3->next;
        }
        return dummy->next;
    }
};