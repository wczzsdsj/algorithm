#include<iostream>
using namespace std;

//类的成员函数都是inline的
class Singleton{
private:
    //下面只是声明，不分配内存
    static Singleton instance;
    //构造函数私有
    Singleton() {};
    //防止拷贝赋值
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;   //返回类型 operator要重载的符号(参数列表) 
    

public:
    // 与静态成员变量不同，静态成员函数不需要在类外定义。它们在类内定义时就可以使用，因为它们不需要实例化对象来调用
    static Singleton* getInstance(){
        return &instance;
    }
};
// 在C++中，类的静态成员（static member）必须在类内声明，在类外初始化
// 静态成员在类外定义，分配内存。需要使用Singleton:: , 范围解析运算符::
Singleton Singleton::instance;

int main(){
    // 不需要实例化对象就可以调用getInstance()
    Singleton *obj = Singleton::getInstance();

    return 0;
}