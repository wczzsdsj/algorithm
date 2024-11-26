#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//栈的压入弹出序列
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int m = pushed.size();
        int j = 0;
        for (int i = 0; i < m; i++){
            s.push(pushed[i]);
            //把下面的j++ 写成 popped[j++]会出错，是因为在判断不成立的时候j也会自增。
            //建议别把++写在判断里，即不容易理解也容易出错。判断 || && 可能会存在短路，导致后续表达式不被执行
            while (!s.empty() && popped[j] == s.top()){
                s.pop();
                j++;
            }
        }
        return j == m;
    }
};

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int j = 0;
        for(int val: pushed){
            s.push(val);
            while(!s.empty()&&s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};