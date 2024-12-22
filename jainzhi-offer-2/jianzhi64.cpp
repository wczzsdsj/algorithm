#include <bits/stdc++.h>
using namespace std;
// 求 1+2+…+n
class Solution {
  public:
    int mechanicalAccumulator(int target) {
        target && (target += mechanicalAccumulator(target - 1));
        return target;
    }
};

// 利用构造函数
class Solution_constructor {
  private:
    static int n;
    static int add;

  public:
    Solution_constructor() { 
        n += add;
        add++;
    }
    static int getnum() {
        return n;
    }
};
int Solution_constructor::n = 0;
int Solution_constructor::add = 1;

// 利用虚函数求解

class A {
  public:
    virtual int getnum(int n){
      return 0;
    }
};
// 下面不用指针会出错，原因如下
A* A_arr[2];

class B:public A {
  public:
    virtual int getnum(int n){
      return A_arr[!!n]->getnum(n-1)+n;
    }
};

int main(){
    Solution obj;
    cout << obj.mechanicalAccumulator(100)<<endl;

    Solution_constructor arr[100];
    cout << arr[0].getnum() << endl;

    A a;
    B b;
    A_arr[0] = &a;
    A_arr[1] = &b;
    cout << A_arr[1]->getnum(100)<<endl;

    return 0;
}

// 对象数组：
// 使用对象的方式直接调用类的方法，不支持多态性（除非使用基类指针或引用）。
// A A_arr[2];
// A_arr[0].getnum(1); // 直接调用
// 对象指针数组：
// 可以利用多态性，允许通过基类指针访问派生类的方法。
// 需要使用->运算符来访问指针指向的对象的方法。
// A *A_arr[2];
// A_arr[1] = new B();  // B 是 A 的派生类
// A_arr[1]->getnum(1); // 使用指针调用