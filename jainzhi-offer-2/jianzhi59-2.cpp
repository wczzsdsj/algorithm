#include<iostream>
#include<queue>
#include<deque>
using namespace std;
// 队列的最大值
class Checkout {
  private:
    queue<int> q;
    deque<int> d;

  public:
    Checkout() {}

    int get_max() { return d.empty() ? -1 : d.front(); }

    void add(int value) {
        // while(!d.empty()&&value>=d.back()){ //这种情况，有相等value时会报错
        while(!d.empty()&&value>d.back()){
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int remove() {
        if(q.empty())
            return -1;
        int num=q.front();
        if(num==d.front()){
            d.pop_front();
        }
        q.pop();
        return num;
    }
};
// 上面的代码没考虑value值可能存在相等的情况（虽然也能通过leetcode样例），应该存储关于index的额外信息
// 或者把上面单调队列的判断条件改为 value>d.back()
class Checkout {
  private:
    //value index
    queue<pair<int,int>> q;
    deque<pair<int,int>> d;
    int index=0;

  public:
    Checkout() {}

    int get_max() { return !q.empty() ? d.front().first : -1; }

    void add(int value) {
        while(!d.empty()&&d.back().first<value){
            d.pop_back();
        }
        d.push_back(pair{value,index});
        q.push(pair{value, index});
        index++;
    }

    int remove() {
        if(q.empty())
            return -1;
        if(q.front().second==d.front().second)
            d.pop_front();
        int res = q.front().first;
        q.pop();
        return res;
    }
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */