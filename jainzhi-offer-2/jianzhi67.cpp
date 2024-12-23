#include<bits/stdc++.h>
using namespace std;

// 把字符串转换成整数
class Solution {
  public:
    int myAtoi(string str) {
        int index = 0;
        int size = str.length();
        bool sub = false;
        while (index < size && (str[index] == ' ')) {
            index++;
        }
        if (str[index] == '+') {
            sub = false;
            index++;
        } else if (str[index] == '-') {
            sub = true;
            index++;
        }

        long long num = 0;
        while (index < size && (str[index] >= '0' && str[index] <= '9')) {
            num = num * 10 + str[index] - '0';
            if (sub == false && num > INT_MAX) {
                num = INT_MAX;
                return num;
            }
            if (sub == true && 0 - num < INT_MIN) {
                num = INT_MIN;
                return num;
            }
            index++;
        }
        if (sub == true)
            num = 0 - num;
        return int(num);
    }
};
