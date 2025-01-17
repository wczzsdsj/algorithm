#include <bits/stdc++.h>
using namespace std;

// 155. 最小栈
class MinStack {
  public:
    long long minnum;
    stack<long long> stk;
    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            stk.push(0);
            minnum = val;
        } else {
            if (val >= minnum) {
                stk.push(val - minnum);
            } else {
                stk.push(val - minnum);
                minnum = val;
            }
        }
    }

    void pop() {
        if (stk.empty())
            return;
        long long topnum = stk.top();
        if (topnum < 0) {
            minnum = minnum - topnum;
        }
        stk.pop();
    }
    // 注意这里，当 topnum<0 时，minnum就是栈顶的值
    int top() {
        if (stk.empty())
            return -1;
        long long topnum = stk.top();
        if (topnum > 0)
            return topnum + minnum;
        return minnum;
    }

    int getMin() { return (int)minnum; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */