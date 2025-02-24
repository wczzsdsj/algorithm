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
        ListNode *fast = head, *slow = head; //都从head开始
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *res = head; // 都从head开始
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

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *fast = head->next; // 如果为head->next，则认为链表增加了头节点
        ListNode *slow = head;       
        do {
            if (fast == NULL || fast->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        fast = head;        //这里需要要么新建虚拟头节点，让fast从dummy开始，要么下面判断条件变为slow->next
        while (fast != slow->next) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};