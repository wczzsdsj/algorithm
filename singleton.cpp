#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class Singleton {
    public:
        class GC {
        public:
            ~GC() {
                if (ptr != nullptr)
                    delete ptr;
            }
        };
        static Singleton::GC g;
        // 静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符::就可以访问。静态成员函数没有this指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
        static Singleton* getInstance(){
            if(ptr==nullptr){
                mtu.lock();
                if(ptr==nullptr){
                    ptr = new Singleton();
                }
                mtu.unlock();
            }
            return ptr;
        }

    private:
        static Singleton *ptr;
        static mutex mtu;
        Singleton() {};
        Singleton(const Singleton&) = delete;
        Singleton &operator=(const Singleton&) = delete;
};

Singleton* Singleton::ptr=nullptr;
mutex Singleton::mtu;
Singleton::GC g;

int main(){
    thread t1([] { cout << Singleton::getInstance() << endl; });
    thread t2([] { cout << Singleton::getInstance() << endl; });
    t1.join();
    t2.join();
    cout << Singleton::getInstance() << endl;
    return 0;
}