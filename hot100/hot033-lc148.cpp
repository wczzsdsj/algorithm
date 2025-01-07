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
        //fast初始化为next，当为偶数时，slow在中间值偏左。此题初始化为head，会导致最后两个节点时不断开一直在循环
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead = slow->next;
        // 注意这里的含义，断开。两个节点时需要中间值偏左
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