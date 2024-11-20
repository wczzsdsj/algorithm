#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class Singleton{
public:
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if (Singleton::instance)
            {
                delete Singleton::instance;
            }
        }
    };
    // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
    static CGarbo Garbo;
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            mtx.lock();
            if (instance == nullptr)
            {
                instance = new Singleton();
            }
            mtx.unlock();
        }
        return instance;
    }

private:
    Singleton() {};
    // Singleton(const Singleton &)= delete;c++11
    //只声明不定义
    Singleton(const Singleton &); //c++98
    Singleton &operator=(const Singleton &);
    static mutex mtx;
    static Singleton *instance;
};

Singleton::CGarbo Singleton::Garbo;
mutex Singleton::mtx;
Singleton* Singleton::instance=nullptr;

// int main(){
//     Singleton *instance1 = Singleton::getInstance();
//     Singleton *instance2 = Singleton::getInstance();
//     cout << instance1 << " " << instance2 << endl;
//     return 0;
// }

int main()
{
    // lambda表达式 auto f=[]()->returnType {};  []捕获列表，= 值捕获，& 引用捕获，()可选
    thread t1([]
              { cout << Singleton::getInstance() << endl; });
    thread t2([]
              { cout << Singleton::getInstance() << endl; });
    t1.join();
    t2.join();
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    return 0;
}