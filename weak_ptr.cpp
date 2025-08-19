#include <iostream>

// weak_ptr又叫做弱指针，它是用来解决shared_ptr循环引用的问题。为啥叫弱呢？
// shared_ptr A被赋值给shared_ptr B时，A的引用计数加1,；shared_ptr A被赋值给weak_ptr C时，A的引用计数不变。
// weak_ptr在使用时，是与shared_ptr绑定的。基于SharedPtr实现来实现demo版的WeakPtr，并解决循环引用的问题，全部代码如下： 
template <typename T>
class SharedPtr {
  public:
    int *counter;
    int *weakref;
    T *resource;

    SharedPtr(T *resc = nullptr) {
        cout << __PRETTY_FUNCTION__ << endl;
        counter = new int(1);
        weakref = new int(0);
        resource = resc;
    }

    SharedPtr(const SharedPtr &rhs) {
        cout << __PRETTY_FUNCTION__ << endl;
        resource = rhs.resource;
        counter = rhs.counter;
        ++*counter;
    }

    SharedPtr &operator=(const SharedPtr &rhs) {
        cout << __PRETTY_FUNCTION__ << endl;
        --*counter;
        if (*counter == 0) {
            delete resource;
        }

        resource = rhs.resource;
        counter = rhs.counter;
        ++*counter;
    }

    ~SharedPtr() {
        cout << __PRETTY_FUNCTION__ << endl;
        --*counter;
        if (*counter == 0) {
            delete counter;
            delete resource;
        }
    }

    int use_count() { return *counter; }
};

template <typename T>
class WeakPtr {
  public:
    T *resource;

    WeakPtr(T *resc = nullptr) {
        cout << __PRETTY_FUNCTION__ << endl;
        resource = resc;
    }

    WeakPtr &operator=(SharedPtr<T> &ptr) {
        cout << __PRETTY_FUNCTION__ << endl;
        resource = ptr.resource;
        ++*ptr.weakref; // 赋值时引用计数counter不变，改变弱引用计数weakref
    }

    ~WeakPtr() { cout << __PRETTY_FUNCTION__ << endl; }
};
