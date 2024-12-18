#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
// 翻转单词顺序
class Solution {
  public:
    string reverseMessage(string message) {
        if (message == "")
            return "";
        int l = 0, r = message.length() - 1;
        while (l < message.length() && message[l] == ' ') {
            l++;
        }
        while (r >= 0 && message[r] == ' ') {
            r--;
        }
        if (l > r)
            return "";
        reverse(message.begin() + l, message.begin() + r + 1);
        int maxindex = r;
        int minindex = l;
        r = l;
        while (l <= maxindex) {
            while (r <= maxindex && message[r] != ' ') {
                r++;
            }
            reverse(message.begin() + l, message.begin() + r);
            while (r <= maxindex && message[r] == ' ') {
                r++;
            }
            l = r;
        }
        string ans;
        for (int i = minindex; i <= maxindex; i++) {
            if (message[i] == ' ' && i - 1 >= minindex &&
                message[i - 1] == ' ') {
                continue;
            }
            ans += message[i];
        }
        return ans;
    }
};