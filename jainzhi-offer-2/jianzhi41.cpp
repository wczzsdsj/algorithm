#include<iostream>
#include<queue>
using namespace std;

// 数据流中的中位数
class MedianFinder
{
private:
    priority_queue<double, vector<double>, less<double>> maxq;
    priority_queue<double, vector<double>, greater<double>> minq;
    int len;

public:

    MedianFinder()
    {
        len = 0;
    }

    void addNum(int num)
    {
        if(len&1){
            if(!maxq.empty()&&num<maxq.top()){
                maxq.push(num);
                num = maxq.top();
                maxq.pop();
            }
            minq.push(num);
        }else{
            if(!minq.empty()&&num>minq.top()){
                minq.push(num);
                num = minq.top();
                minq.pop();
            }
            maxq.push(num);
        }
        len++;
    }

    double findMedian()
    {
        if(len&1)
            return maxq.top();
        else
            return (maxq.top() + minq.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */