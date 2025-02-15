#include <iostream>

template <typename T> 
class SharedPtr {
  public:
    // 默认构造函数
    SharedPtr(T *ptr = nullptr) : ptr_(ptr), ref_count_(new size_t(1)) {}

    // 拷贝构造函数
    SharedPtr(const SharedPtr &other)
        : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        ++(*ref_count_); // 增加引用计数
    }

    // 移动构造函数
    SharedPtr(SharedPtr &&other) noexcept
        : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        other.ptr_ = nullptr;
        other.ref_count_ = nullptr;
    }

    // 析构函数
    ~SharedPtr() { release(); }

    // 拷贝赋值运算符
    SharedPtr &operator=(const SharedPtr &other) {
        if (this != &other) {
            release(); // 释放当前资源
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            ++(*ref_count_); // 增加引用计数
        }
        return *this;
    }

    // 移动赋值运算符
    SharedPtr &operator=(SharedPtr &&other) noexcept {
        if (this != &other) {
            release(); // 释放当前资源
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            other.ptr_ = nullptr;
            other.ref_count_ = nullptr;
        }
        return *this;
    }

    // 重载解引用操作符
    T &operator*() const { return *ptr_; }

    // 重载箭头操作符
    T *operator->() const { return ptr_; }

    // 获取引用计数
    size_t use_count() const { return *ref_count_; }

  private:
    T *ptr_;            // 原始指针
    size_t *ref_count_; // 引用计数

    // 释放资源
    void release() {
        if (--(*ref_count_) == 0) {
            delete ptr_;       // 删除原始指针
            delete ref_count_; // 删除引用计数
        }
    }
};

// 示例用法
int main() {
    SharedPtr<int> sp1(new int(10));
    std::cout << "Value: " << *sp1 << ", Count: " << sp1.use_count()
              << std::endl;

    {
        SharedPtr<int> sp2 = sp1; // 拷贝构造
        std::cout << "Value: " << *sp2 << ", Count: " << sp1.use_count()
                  << std::endl;
    } // sp2 超出作用域，引用计数减少

    std::cout << "Count after sp2 out of scope: " << sp1.use_count()
              << std::endl;

    return 0;
}