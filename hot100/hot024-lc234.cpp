#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 234. 回文链表
// 详解
class Solution {
    // 876. 链表的中间结点
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 206. 反转链表
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

  public:
    bool isPalindrome(ListNode *head) {
        ListNode *mid = middleNode(head);
        ListNode *head2 = reverseList(mid);
        while (head2) {
            if (head->val != head2->val) { // 不是回文链表
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};

// 没独立函数版
class Solution {
  public:
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = head, *cur = head->next;
        head->next = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    bool isPalindrome(ListNode *head) {
        if (head == nullptr) {
            return true;
        }
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        ListNode *newhead = reverse(slow);

        ListNode *a = head, *b = newhead;
        while (a && b) {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};