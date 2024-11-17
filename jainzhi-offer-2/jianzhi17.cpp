#include<iostream>
#include<vector>
#include<string>

using namespace std;
// 打印从1到最大的n位数
// 大数问题
class Solution_bign_struct
{
private:
struct bign{
    int num[100];
    int len;
};

public:
    bign bignAdd(bign a,bign b,bool& isoverflow,int cnt)
    {
        bign c;
        c.len = 0;
        int addnum = 0;
        for (int i = 0; i < max(a.len, b.len);i++)
        {
            int temp = a.num[i] + b.num[i] + addnum;
            addnum = temp / 10;
            c.num[c.len++] = temp % 10;
        }
        if(addnum)
            c.num[c.len++] = addnum;
        if(c.len>cnt)
            isoverflow = true;
        return c;
    }

    void countNumbers(int cnt)
    {
        bign a,b,c;
        a.len = 1;
        a.num[0] = 0;
        b.len = 1;
        b.num[0] = 1;
        bool isoverflow = false;

        while (!isoverflow){
            c = bignAdd(a,b,isoverflow,cnt);
            // if(c.len==cnt+1)
            if(isoverflow)
                break;
            if (!(c.len==1&&c.num[0]==1))
                cout << ",";
            for (int i = c.len - 1; i >= 0;i--)
            {
                cout << c.num[i];
            }
            a = c;
        }

        return;
    }
};
class Solution_bign
{

public:
    bool bignAdd(vector<int> a, vector<int> b, vector<int>& ans, int cnt)
    {
        // int m = a.size(), n = b.size();
        // int temp = 0;
        // while (a[temp])
        // {
        //     temp++;
        // }
        // int m = temp;
        // temp = 0;
        // while (b[temp])
        // {
        //     temp++;
        // }
        // int n = temp;
        int addnum = 0,len=0;
        for (int i = 0; i < cnt;i++){
            int sumi = a[i] + b[i]+addnum;
            addnum = sumi / 10;
            ans[i]=sumi%10;
            if(addnum&&i==cnt-1)
                return false;
        }
        // temp = 0;
        // while (ans[temp])
        // {
        //     temp++;
        // }
        // if(addnum)
        //     ans[temp]=addnum;
        // if(ans[cnt]==1)
        //     return false;
        return true;
    }

    void countNumbers(int cnt)
    {
        int index = 0;
        vector<int> a(cnt,0),  b(cnt,0), ans(cnt,0);
        a[0] = 0;
        b[0] = 1;
        while (bignAdd(a, b,ans,cnt))
        {
            a = ans;
            int temp = cnt-1;
            while(a[temp]==0){
                temp--;
            }
            for (int i = temp; i >= 0;i--)
            {
                cout << a[i];
            }
            cout << ",";
        }
        return;
    }
};
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
    Solution_bign_struct *obj = new Solution_bign_struct;
    obj->countNumbers(3);

    // Solution_bign *obj = new Solution_bign;
    // obj->countNumbers(2);

    // Solution *obj = new Solution();
    // obj->countNumbers(3);

    // Solution2 *obj = new Solution2();
    // obj->countNumbers(3);
    return 0;
}