#include<iostream>
#include<string>
#include<sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 数字转stirng        string s = to_string(cur->val);
// string转数字        int num=atoi(s.c_str());    num=stoi(s);  #include<cstring>

// itoa并不是一个标准的C函数，它是Windows特有的，如果要写跨平台的程序，请用sprintf。是Windows平台下扩展的，标准库中有sprintf，功能比这个更强，用法跟printf类似：
// char str[255];
// sprintf(str, "%x", 100); // 将100转为16进制表示的字符串。

// 二叉树的序列化与反序列化
// 先序遍历v1 val过大会导致char溢出
class Codec
{
public:
    string treestream;
    TreeNode *head;
    int index = 0;
    void serializeCore(TreeNode *cur)
    {
        if(cur==nullptr){
            treestream += " ";
            return;
        }
        treestream += ((cur->val) + '0'); // val过大会导致char溢出
        serializeCore(cur->left);
        serializeCore(cur->right);
    }
    TreeNode *deserializeCore(string data)
    {
        if(index>=data.size())
            cout << "error";
        if (data[index] == ' '){
            index++;
            return nullptr;
        }
        TreeNode *cur = new TreeNode(data[index] - '0');
        if (index == 0)
            head = cur;
        index++;
        cur->left = deserializeCore(data);
        cur->right = deserializeCore(data);
        return cur;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        serializeCore(root);
        return treestream;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(data.size()==0)
            return nullptr;
        deserializeCore(data);
        return head;
    }
};
//先序遍历v2
class Codec
{
public:
    string treestream;
    stringstream ss;
    TreeNode *head;
    int index = 0;
    void serializeCore(TreeNode *cur)
    {
        if (cur == nullptr)
        {
            treestream += "# ";
            return;
        }
        treestream += to_string(cur->val)+' ';
        serializeCore(cur->left);
        serializeCore(cur->right);
    }
    TreeNode *deserializeCore(string data)
    {
        // if (index >= data.size())
        //     cout << "error";
        string stringtemp;
        ss >> stringtemp;
        if (stringtemp == "#")
        {
            return nullptr;
        }
        TreeNode *cur = new TreeNode(stoi(stringtemp));
        if (index == 0){
            head = cur;
            index++;
        }
        cur->left = deserializeCore(data);
        cur->right = deserializeCore(data);
        return cur;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        serializeCore(root);
        return treestream;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return nullptr;
        ss<<data;
        deserializeCore(data);
        return head;
    }
};
int main(){
    TreeNode *root = new TreeNode(1);
    Codec ser, deser;
    string s=ser.serialize(root);
    cout << s <<' '<<ser.treestream<< endl;
    // TreeNode *ans = deser.deserialize();

    // printf("%d", ans->val);
    // string s;
    // s += 1+'0';
    // cout << s;
    return 0;
}