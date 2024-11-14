#include<iostream>
#include<stack>
#include<stdexcept>
#include<exception>
#include<queue>
using namespace std;

//用栈模拟队列
class CQueue{
public:
    CQueue(){

    }

    void appendTail(int value){
        s1.push(value);
    }

    int deleteHead(){
        int ans=-1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        if(!s2.empty()){
            ans = s2.top();
            s2.pop();
        }
        return ans;
    }

private:
    stack<int> s1, s2;
};

// 模板写法  注意：不能重复定义typename T
template <typename T>
class CQueueTemplate 
{
public:
    CQueueTemplate(T t)
    {
        this.t = t;
    }
    T& get(){
        return t;
    }
    void apendTail(const T &element);
    // void apendTail(const T &element)
    // {
    //     s1.push(element);
    // }

    template <typename U>
    U deleteHead()
    {
        U ans;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty())
        {
            ans = s2.top();
            s2.pop();
        }
        else
            throw exception();
        return ans;

    }

private:
    stack<T> s1, s2;
    T t;
};

template <typename Y>
void CQueueTemplate<Y>::apendTail(const Y &element)
{
    s1.push(element);
}

int main(int argc,char* argv[]){
    CQueue *obj = new CQueue();
    queue<int> q;
}