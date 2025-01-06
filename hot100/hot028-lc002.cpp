#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2. 两数相加
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0;
        while (carry != 0 || l1 || l2) {
            int sum = carry;
            if (l1)
                sum += (l1->val);
            if (l2)
                sum += (l2->val);
            carry = sum / 10;
            ListNode *newnode = new ListNode(sum % 10);
            cur->next = newnode;
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return dummy->next;
    }
};