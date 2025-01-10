#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 默认使用 std::less 会构建一个大顶堆
// priority_queue<int, vector<int>, less<int>> q;

// 23. 合并 K 个升序链表

class Solution {
    // 1.重写仿函数
    // struct cmpstruct {
    //     bool operator()(ListNode *a, ListNode *b) const {
    //         return a->val > b->val;
    //     }
    // };

    // 2. bool cmp(ListNode *a, ListNode *b)  { return a->val > b->val; }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // 1. priority_queue<ListNode *, vector<ListNode *>, cmpstruct> q;

        // 2. priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode*,ListNode*)>> q(cmp);
        
        auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);


        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        for (auto val : lists) {
            if (val)
                q.push(val);
        }
        while (!q.empty()) {
            ListNode *top = q.top();
            q.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next != nullptr)
                q.push(top->next);
        }
        return dummy->next;
    }
};
int main() { return 0; }