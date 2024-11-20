#include<iostream>
#include<vector>
using namespace std;

//奇数在前，偶数在后
//双指针
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int i = 0, j = 0;
        while(j<nums.size()){
            if(nums[j]&1){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }

        return nums;
    }
};

// 函数指针写法，判断逻辑解耦
// isEven放在类外，原因如下：
// 传参不正确的原因在于 isEven 是一个类的成员函数，需要一个对象上下文来调用。
// 在你的原始代码中，exchangeCore 函数接收一个函数指针 bool (*func)(int)，而在 exchange 函数中调用时直接传入了 isEven，这本身是没有问题的，但有几个地方需要注意：
// 1.函数指针的用法：如果 isEven 是类的成员函数，你不能直接将其作为函数指针传递，因为成员函数有一个隐含的 this 指针。你需要使用 std::bind 或者 lambda 表达式。
// 2.lambda 表达式：在我的示例中，我使用了 lambda 表达式来捕获 this 指针并调用 isEven，这是一种常见的做法。
bool isEven(int n)
{
    return n & 1;
}
class Solution2
{
public:

    vector<int> exchangeCore(vector<int> &nums,bool (*func)(int))
    {
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (func(nums[j]))
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }

        return nums;
    }
    vector<int> exchange(vector<int> &nums)
    {
        exchangeCore(nums,isEven);

        return nums;
    }
};
int main(){

    return 0;
}