#include<iostream>
#include<semaphore.h>
#include <pthread.h> //POSIX 线程库使用函数（如 pthread_create, pthread_join）
#include<vector>
#include <thread> //C++11 线程库使用类（如 std::thread）,<thread> 库是 C++ 标准库的一部分
#include<chrono>
#include<mutex>
using namespace std;
//多生产者 多消费者
const int NUM = 8;
const int threadNum = 5;

void P(sem_t &s){
    sem_wait(&s);
}

void V(sem_t &s){
    sem_post(&s);
}

vector<int> nums(NUM,0);

int p_index = 0;
int c_index = 0;
int value=0;
sem_t blank_sem;
sem_t data_sem;

// 多生产者 多消费者需要对index加锁实现生产者之间的互斥，消费者之间的互斥
mutex p_lock;
mutex c_lock;

void produce(int threadid){
    P(blank_sem);
    p_lock.lock();
    nums[p_index] = value;
    printf("生产者%d在%d的位置创建%d\n",threadid,p_index,value);
    value++;
    p_index = (p_index+1) % NUM;
    p_lock.unlock();
    V(data_sem);
}

void consume(int threadid){
    P(data_sem);
    c_lock.lock();
    int ret = nums[c_index];
    printf("消费者%d在%d的位置消耗%d\n", threadid,c_index, ret);
    c_index = (c_index+1) % NUM;
    c_lock.unlock();
    V(blank_sem);
}

void producer(int threadid){
    for (int i = 0; ;i++)
        produce(threadid);
}
void consumer(int threadid)
{
    for (int i = 0; ;i++)
        consume(threadid);
}

int main(){
    sem_init(&blank_sem,0,NUM);
    sem_init(&data_sem,0,0);

    vector<thread> consumerThread;
    vector<thread> producerThread;
    for (int i = 0; i < threadNum;i++){
        consumerThread.emplace_back(thread(consumer,i));
        producerThread.emplace_back(thread(producer,i));
    }
    for (int i = 0; i < threadNum;i++){
        producerThread[i].join();
        consumerThread[i].join();
    }

    sem_destroy(&blank_sem);
    sem_destroy(&data_sem);
    return 0;
}

// 小林coding 精简版
// #define N 100
// semaphore mutex = 1;        // 互斥信号量，用于保护缓冲区的互斥访问
// semaphore emptyBuffers = N; // 表示空的缓冲区的数量
// semaphore fullBuffers = 0;  // 表示满的缓冲区的数量
// void producer() {
//     while (TRUE) {
//         P(emptyBuffers); // 等待空缓冲区
//         P(mutex);        // 进入临界区

//         // 生产一个产品并放入缓冲区
//         // ...

//         V(mutex);       // 离开临界区
//         V(fullBuffers); // 增加满缓冲区的数量
//     }
// }
// void consumer() {
//     while (TRUE) {
//         P(fullBuffers); // 等待满缓冲区
//         P(mutex);       // 进入临界区

//         // 从缓冲区中取出一个产品
//         // ...

//         V(mutex);        // 离开临界区
//         V(emptyBuffers); // 增加空缓冲区的数量
//     }
// }