#include <chrono>
#include <iostream>
#include <thread>

// https://cloud.tencent.com/developer/article/2375099
// 也可以增加个变量记录上次访问时间，在consume时前面刷新tokens_数量
class TokenBucket {
  public:
    TokenBucket(int capacity, int rate)
        : capacity_(capacity), rate_(rate), tokens_(capacity) {}

    bool consume(int tokens) {
        if (tokens <= tokens_) {
            tokens_ -= tokens;
            return true;
        } else {
            return false;
        }
    }

    void refill() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            tokens_ = std::min(capacity_, tokens_ + rate_);
        }
    }

  private:
    int capacity_;
    int rate_;
    int tokens_;
};

int main() {
    TokenBucket bucket(10, 2); // 令牌桶容量为10，每秒增加2个令牌

    // 启动令牌桶的自动补充线程
    std::thread refill_thread([&] { bucket.refill(); });

    // 模拟资源访问
    for (int i = 0; i < 20; ++i) {
        if (bucket.consume(1)) {
            std::cout << "Access granted" << std::endl;
        } else {
            std::cout << "Access denied" << std::endl;
        }
        std::this_thread::sleep_for(
            std::chrono::milliseconds(500)); // 模拟资源访问间隔
    }

    // 等待自动补充线程结束
    refill_thread.join();

    return 0;
}