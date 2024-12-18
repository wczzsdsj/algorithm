#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
// 左旋转字符串
class Solution {
  public:
    string dynamicPassword(string password, int target) {
        reverse(password.begin(), password.begin()+target);
        reverse(password.begin()+target, password.end());
        reverse(password.begin(), password.end());
        return password;
    }
};