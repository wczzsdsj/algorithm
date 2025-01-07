#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 148. 排序链表
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead = slow->next;
        slow->next = nullptr;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(newhead);

        return merge(l1, l2);
    }
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == nullptr ? l2 : l1;
        return dummy->next;
    }
};