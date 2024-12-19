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
        while(!d.empty()&&value>=d.back()){
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

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */