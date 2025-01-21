#include <bits/stdc++.h>
using namespace std;

// 295. 数据流的中位数
class MedianFinder {
  private:
    int len = 0;
    priority_queue<int, vector<int>, less<int>> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;

  public:
    MedianFinder() { len = 0; }

    void addNum(int num) {
        maxq.push(num);
        int top = maxq.top();
        maxq.pop();
        minq.push(top);
        if (minq.size() - maxq.size() > 1) {
            maxq.push(minq.top());
            minq.pop();
        }
        len++;
    }

    double findMedian() {
        if (len & 1)
            return minq.top();
        else
            return (minq.top() + maxq.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */