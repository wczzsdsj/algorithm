#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
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

// 138. 随机链表的复制
class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == NULL)
            return head;
        Node *cur = head;
        while (cur) {
            Node *newnode = new Node(cur->val);
            Node *nextnode = cur->next;
            cur->next = newnode;
            newnode->next = nextnode;
            cur = nextnode;
        }
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        Node *newhead = cur->next;
        Node *curcopy = newhead;
        while (cur) {
            Node *copynext = curcopy->next;
            if (copynext)
                curcopy->next = copynext->next;
            cur->next = copynext;
            cur = cur->next;
            if (cur)
                curcopy = cur->next;
        }

        return newhead;
    }
};