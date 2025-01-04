#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 142. 环形链表 II
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                cout << '1' << endl;
                ListNode *res = head;
                while (res != slow) {
                    res = res->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};