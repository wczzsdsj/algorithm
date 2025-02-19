#include <iostream>

template <typename T>
class UniquePtr {
  public:
    // 构造函数
    explicit UniquePtr(T *ptr = nullptr) : ptr_(ptr) {}

    // 移动构造函数
    UniquePtr(UniquePtr &&other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr; // 将原指针置空
    }

    // 禁用拷贝构造和拷贝赋值
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;

    // 移动赋值运算符
    UniquePtr &operator=(UniquePtr &&other) noexcept {
        if (this != &other) {
            delete ptr_;          // 释放当前资源
            ptr_ = other.ptr_;    // 转移所有权
            other.ptr_ = nullptr; // 将原指针置空
        }
        return *this;
    }

    // 析构函数
    ~UniquePtr() {
        delete ptr_; // 释放管理的对象
    }

    // 重载解引用操作符
    T &operator*() const { return *ptr_; }

    // 重载箭头操作符
    T *operator->() const { return ptr_; }

    // 获取原始指针
    T *get() const { return ptr_; }

    // 释放管理的对象
    void reset(T *ptr = nullptr) {
        delete ptr_; // 释放旧资源
        ptr_ = ptr;  // 更新为新指针
    }

    // 释放原始指针并返回
    T *release() {
        T *temp = ptr_;
        ptr_ = nullptr; // 将指针置空
        return temp;    // 返回原始指针
    }

  private:
    T *ptr_; // 原始指针
};

// 示例用法
int main() {
    UniquePtr<int> up1(new int(10));
    std::cout << "Value: " << *up1 << std::endl;

    UniquePtr<int> up2 = std::move(up1); // 移动语义
    if (!up1.get()) {
        std::cout << "up1 is now empty." << std::endl;
    }

    std::cout << "Value in up2: " << *up2 << std::endl;

    up2.reset(new int(20)); // 重置为新值
    std::cout << "Value after reset: " << *up2 << std::endl;

    return 0;
}