#include<iostream>
#include<stack>
using namespace std;
//包含最小值的栈
class MinStack
{
public:
    stack<int> st;
    stack<int> minst;
    MinStack()
    {
        minst.push(INT_MAX);
    }

    void push(int val)
    {
        st.push(val);
        if(val<=minst.top())
            minst.push(val);
        else
            minst.push(minst.top());
    }

    void pop()
    {
        if(!st.empty())
            st.pop();
        else
            throw "stack is empty";
        if(!minst.empty())
            minst.pop();
        else
            throw "stack is empty";
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minst.top();
    }
};
//不使用辅助空间
class MinStack {
public:
    //s_min也需要为ll
    ll s_min;
    stack<ll> s;
    MinStack() {
        s_min=INT64_MAX;
    }
    
    void push(int val) {
        //当val为首个元素时，特殊处理，栈存放0
        if(s.empty()==1){
            s_min=val;
            s.push(0);
        }else{
            ll sub=val-s_min;
            if(sub<0){
                s_min=val;
            }
            s.push(sub);
        }
    }
    
    void pop() {
        if(s.top()<0){
            s_min=s_min-s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<0){
            return s_min;
        }
        return s_min+s.top();
    }
    
    int getMin() {
        return s_min;
    }
};
int main(){
    MinStack *obj = new MinStack();

    return 0;
}
