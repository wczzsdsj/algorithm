#include<iostream>
#include<semaphore.h>
#include <pthread.h> //POSIX 线程库使用函数（如 pthread_create, pthread_join）
#include<vector>
#include <thread> //C++11 线程库使用类（如 std::thread）,<thread> 库是 C++ 标准库的一部分
#include<chrono>
using namespace std;
//单生产者 单消费者
const int NUM = 8;

void P(sem_t &s){
    sem_wait(&s);
}

void V(sem_t &s){
    sem_post(&s);
}

vector<int> nums(NUM,0);

int p_index = 0;
int c_index = 0;
sem_t blank_sem;
sem_t data_sem;

void produce(int value){
    P(blank_sem);
    nums[p_index] = value;
    printf("在%d的位置创建%d\n",p_index,value);
    V(data_sem);
    p_index++;
    p_index %= NUM;
}

void consume(int &value){
    P(data_sem);
    value = nums[c_index];
    printf("在%d的位置消耗%d\n",c_index,value);
    V(blank_sem);
    c_index++;
    c_index %= NUM;
}


void producer(int num){
    for (int i = 0; ;i++)
        produce(i);
}
void consumer(int num)
{
    int value;
    for (int i = 0; ;i++)
        consume(value);
}

int main(){
    sem_init(&blank_sem,0,NUM);
    sem_init(&data_sem,0,0);

    thread produceThead(producer, 10);
    thread consumeThread(consumer,10);

    consumeThread.join();
    produceThead.join();

    sem_destroy(&blank_sem);
    sem_destroy(&data_sem);
    return 0;
}