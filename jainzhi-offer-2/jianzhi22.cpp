#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* trainingPlan(ListNode* head, int cnt) {
        if(head==nullptr) return nullptr;
        ListNode*p=head;
        for(int i=1;i<=cnt;i++){
            if(p!=nullptr)p=p->next;
            else return nullptr;
        }
        ListNode* q=head;
        while(p!=nullptr){
            p=p->next;
            q=q->next;
        }
        return q;
    }
};