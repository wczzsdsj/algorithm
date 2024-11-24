#include<iostream>
#include<stack>
using namespace std;

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
int main(){
    MinStack *obj = new MinStack();

    return 0;
}