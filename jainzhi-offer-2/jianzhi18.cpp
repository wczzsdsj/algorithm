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
//LC83，删除已排序链表中重复的元素，保留一个
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* prenode=head,*curnode=head->next;
        while(curnode){
            while(curnode && prenode->val==curnode->val) {
                curnode=curnode->next;
            }
            prenode->next = curnode;
            if(curnode){
                prenode = curnode; // 或者prenode=prenode->next;
                curnode = curnode->next;
            }
        }
        return head;
    }
};
// LC83，同上
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val == cur->next->val)
            {
                int x = cur->val;
                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else
                cur = cur->next;
        }
        return head;
    }
};

// LC82，删除有序链表中重复的元素，全部删除
class Solution3
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *newhead = new ListNode(-1, head);
        ListNode *cur = newhead;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return newhead->next;
    }
};
int main(){
    ListNode a(1), b(2), c(2);
    ListNode *head = &a,*p=&b,*q=&c;
    a.next = p;
    b.next = q;

    Solution2 *obj = new Solution2();
    obj->deleteDuplicates(head);
    return 0;
}