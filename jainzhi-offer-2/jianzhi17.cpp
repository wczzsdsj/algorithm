#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 打印从1到最大的n位数
// 大数问题
class Solution
{
public:
    void countNumbersCore(int cnt,int index,vector<int> vi,vector<string>& ans){
        string temp;
        if(index>cnt){
            int flag = 0;
            for(auto i:vi){
                if(i==0&&flag==0){
                    continue;
                }else{
                    flag = 1;
                    temp += i+'0';
                }
            }
            if(temp.size())ans.push_back(temp);
            return;
        }
        for (int i=0; i < 10;i++)
        {
            vi.push_back(i);
            countNumbersCore(cnt,index+1,vi,ans);
            vi.pop_back();
        }

    }

    vector<string> countNumbers(int cnt)
    {
        vector<string> ans;
        vector<int> vi;
        countNumbersCore(cnt, 1, vi, ans);
        for (auto str : ans)
        {
            cout << str << ",";
        }
        return ans;
    }
};
//全排列，不重复
class Solution2
{
public:
    void countNumbersCore(int cnt, int index, vector<int> vi, bool* vis)
    {
        if (index > cnt)
        {
            for (auto i : vi)
            {
                cout << i;
            }
            cout << ',';
            return;
        }

        for (int i = 1; i <= cnt; i++)
        {
            if(vis[i]==0){
                vi.push_back(i);
                vis[i] = 1;
                countNumbersCore(cnt, index + 1, vi,vis);
                vi.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<string> countNumbers(int cnt)
    {
        bool vis[cnt];
        vector<string> ans;
        vector<int> vi;
        countNumbersCore(cnt, 1, vi,vis);
        return ans;
    }
};

int main(){

    Solution *obj = new Solution();
    obj->countNumbers(3);

    // Solution2 *obj = new Solution2();
    // obj->countNumbers(3);
    return 0;
}