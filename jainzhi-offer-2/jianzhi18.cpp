#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *p = head;
        if (p->val == val)
            return p->next;
        while (p->next && p->next->val != val)
        {
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};