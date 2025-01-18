#include <bits/stdc++.h>
using namespace std;

// 394. 字符串解码
class Solution {
  public:
    string decodeString(string s) {
        int len = s.length();
        stack<char> stk;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if ((c >= '0' && c <= '9') || c == '[' || (c >= 'a' && c <= 'z')) {
                stk.push(c);
            } else if (c == ']') {
                string temp;
                while (stk.top() != '[') {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                // int num=stk.top()-'0';
                // stk.pop();
                int num = 0;
                int i = 0;
                while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
                    num = num + (stk.top() - '0') * pow(10, i);
                    i++;
                    stk.pop();
                }
                for (int i = 0; i < num; i++) {
                    for (int j = temp.length() - 1; j >= 0; j--) {
                        stk.push(temp[j]);
                    }
                }
            }
        }
        string ret;
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// 或者双栈法，类比逆波兰式求解