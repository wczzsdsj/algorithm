#include <bits/stdc++.h>
using namespace std;

// 17. 电话号码的字母组合
class Solution {
  public:
    unordered_map<char, string> phoneMap{
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> ans;
    string s;
    void dfs(string digits, int index) {
        if (index == digits.length()) {
            ans.push_back(s);
            return;
        }
        for (auto &val : phoneMap[digits[index]]) {
            s += val;
            dfs(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return ans;
        dfs(digits, 0);
        return ans;
    }
};