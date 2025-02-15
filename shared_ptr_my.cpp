#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

// 智能指针本身不是线程安全的，不过智能指针中引用计数++、–-是需要加锁的，也就是说引用计数的操作是线程安全的。
template <typename T>
class Shared_Ptr {
  private:
    int *_pRefCount;
    T *_pPtr;
    mutex *_pMutex;

  private:
    void Release() {
        bool deleteflag = false;
        _pMutex->lock();
        if (--(*_pRefCount) == 0) {
            delete _pRefCount;
            delete _pPtr;
            deleteflag = true;
        }
        _pMutex->unlock();
        if (deleteflag)
            delete _pMutex;
    }

  public:
    void AddRefCount() {
        _pMutex->lock();
        (*_pRefCount)++;
        _pMutex->unlock();
    }

    T &operator*() const { return *_pPtr; }
    T *operator->() const { return _pPtr; }
    int UseCount() const { return *_pRefCount; }
    T *Get() const { return _pPtr; }

    Shared_Ptr(T *ptr = nullptr)
        : _pPtr(ptr), _pRefCount(new int(1)), _pMutex(new mutex) {}
    ~Shared_Ptr() { Release(); }

    // 拷贝构造函数
    Shared_Ptr(const Shared_Ptr<T> &other)
        : _pPtr(other._pPtr), _pRefCount(other._pRefCount),
          _pMutex(other._pMutex) {
        AddRefCount();
    }
    // 移动构造函数
    Shared_Ptr(Shared_Ptr<T> &&other)
        : _pPtr(other._pPtr), _pRefCount(other._pRefCount),
          _pMutex(other._pMutex) {
        other._pPtr = nullptr;
        other._pRefCount = nullptr;
        other._pMutex = nullptr;
    }

    // 拷贝赋值运算符
    Shared_Ptr<T> &operator=(const Shared_Ptr<T> &other) {
        if (_pPtr != other._pPtr) {
            Release();
            _pPtr = other._pPtr;
            _pRefCount = other._pRefCount;
            _pMutex = other._pMutex;
            AddRefCount();
        }
        return *this;
    }
    // 移动赋值运算符
    Shared_Ptr<T> &operator=(Shared_Ptr<T> &&other) {
        if (_pPtr != other._pPtr) {
            Release();
            _pPtr = other._pPtr;
            _pRefCount = other._pRefCount;
            _pMutex = other._pMutex;
            other._pPtr = nullptr;
            other._pRefCount = nullptr;
            other._pMutex = nullptr;
        }
        return *this;
    }
};

int main(){
    Shared_Ptr<int> sp1(new int(10));
    cout << "value:" << *sp1 << " count:" << sp1.UseCount() << endl;

    {
        Shared_Ptr<int> sp2=sp1;
        cout << "value:" << *sp2 << " count:" << sp2.UseCount() << endl;
    } // sp2 超出作用域，sp2调用析构函数，引用计数减少
    cout << "value:" << *sp1 << " count:" << sp1.UseCount() << endl;
    return 0;
}