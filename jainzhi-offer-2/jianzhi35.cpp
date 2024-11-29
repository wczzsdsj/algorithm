#include<iostream>
#include<unordered_map>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//复杂链表的复制
//不使用额外空间
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(head==nullptr)
            return nullptr;
        Node *node=head;
        while(node){
            Node *copynode = new Node(node->val);
            copynode->next = node->next;
            node->next = copynode;
            node = node->next->next;
        }
        node = head;
        while(node){
            if(node->random){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        //拆分原链表和copy链表，注意保存next的值
        Node *ans = head->next;
        node = head;
        while(node){
            Node *nxt=node->next;
            if(nxt) node->next = nxt->next;
            node = nxt;
        }
        return ans;
    }
};

//hash存储
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(head==nullptr)
            return nullptr;
        unordered_map<Node*,Node *> mp;
        Node *dummy = new Node(-1);
        Node *tail = dummy;
        Node *cur = head;
        while(cur){
            Node *curcopy = new Node(cur->val);
            mp[cur] = curcopy;
            tail->next = curcopy;
            tail = tail->next;
            cur = cur->next;
        }
        tail = dummy->next;
        for (cur = head; cur; cur = cur->next){
            tail->random = mp[cur->random];
            tail = tail->next;
        }
        return dummy->next;
    }
};
