#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 25. K 个一组翻转链表
class Solution {
  public:
    ListNode *reverse(ListNode *head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy, *cur = dummy->next;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;
        while (cur != nullptr) {
            ListNode *tail = cur;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr)
                    return dummy->next;
            }
            ListNode *nxt = tail->next;
            tail->next = nullptr;
            ListNode *reversenode = cur->next;
            ListNode *newhead = reverse(reversenode);
            cur->next = newhead;
            reversenode->next = nxt;
            cur = reversenode;
        }
        return dummy->next;
    }
};