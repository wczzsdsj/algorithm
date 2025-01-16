#include <bits/stdc++.h>
using namespace std;

// 20. 有效的括号
class Solution {
  public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp;
        mp[']'] = '[';
        mp[')'] = '(';
        mp['}'] = '{';

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty() == 1)
                    return false;
                char c = st.top();
                st.pop();
                if (c != mp[s[i]])
                    return false;
            }
        }
        return st.empty() ? true : false;
    }
};