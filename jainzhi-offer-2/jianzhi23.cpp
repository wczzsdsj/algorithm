#include<iostream>
using namespace std;

//环形聊表入口节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    //判断是否有环
    ListNode* isloop(ListNode* head){
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast!=nullptr){
            if(fast->next==nullptr)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                return fast;
        }
        return nullptr;
    }
    ListNode *entryNodeOfLoop(ListNode *head)
    {
        if(!head)
            return nullptr;
        ListNode *loopNode = isloop(head);
        if(!loopNode)
            return nullptr;
        //环节点个数
        int n = 1;
        ListNode *temp = loopNode->next;
        while(temp!=loopNode){
            temp = temp->next;
            n++;
        }

        ListNode *fast = head,*slow=head;
        for (int i = 1; i <= n;i++){
            fast = fast->next;
        }
        while (fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        // 另法
        // 当两指针相遇后，再创建一个指针指向头结点，和指向当前相遇结点的指针一起往后移动，
        // 每次移动一个结点指针两结点相遇，再次相遇的结点就是该链表的入口结点。
        //  ListNode *fast = head;
        //  while(fast!=loopNode){
        //      fast = fast->next;
        //      loopNode = loopNode->next;
        //  }
        return fast;
    }
};
