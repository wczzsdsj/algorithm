#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
using namespace std;

// 基于阻塞队列的生产者消费者模型
const int BUFFER_SIZE = 10;
const int num_producers = 3;
const int num_consumers = 2;

template<typename T>
class BlockQueue{
private:
    queue<T> q;
    size_t maxSize;
    mutex mtx;
    condition_variable full;
    condition_variable empty;

public:
    BlockQueue(size_t _max_size):maxSize(_max_size){}
    size_t size(){
        return q.size();
    }
    void push(T value){
        unique_lock<mutex> lock(mtx);
        full.wait(lock, [this]
                  { return q.size() < maxSize; });
        q.push(value);
        empty.notify_one();
    }
    T pop(){
        unique_lock<mutex> lock(mtx);
        empty.wait(lock, [this]
                   { return !q.empty();}); 
        T value=q.front();
        q.pop();
        full.notify_one();
        return value;
    }
};

void producer(BlockQueue<int>& bq,int threadid)
{
    for (int i = 0; i < 20; ++i)
    { // 每个生产者生产 20 个产品
        bq.push(i);
        // cout << "生产者 " << threadid << " 生产产品 " << i << endl;
        printf("生产者 %d 生产产品 %d\n", threadid, i);
        this_thread::sleep_for(chrono::milliseconds(100)); // 模拟生产时间
    }
}

void consumer(BlockQueue<int> &bq,int threadid){
    while(bq.size()!=0)
    { 
        int value = bq.pop();
        // cout << "消费者 " << threadid << " 消费产品 " << value << endl;
        printf("消费者 %d 消费产品 %d\n", threadid, value);
        this_thread::sleep_for(chrono::milliseconds(150)); // 模拟消费时间
    }
}



int main(){
    BlockQueue<int> bq(10);
    vector<thread> producers, consumers;

    // 创建生产者线程
    for (int i = 0; i < num_producers; ++i)
    {
        // 不仅仅是在使用bind时，在使用thread进行编程时，也会发生这样的问题，thread的方法传递引用的时候，必须外层用ref来进行引用传递，否则会编译出错。
        producers.emplace_back(thread(producer,ref(bq), i));//需要加ref实现引用传递
    }

    // 创建消费者线程
    for (int i = 0; i < num_consumers; ++i)
    {
        consumers.emplace_back(thread(consumer,ref(bq), i));
    }

    // 等待线程结束
    for (auto &p : producers)
    {
        p.join();
    }
    for (auto &c : consumers)
    {
        c.join();
    }

    return 0;
}
